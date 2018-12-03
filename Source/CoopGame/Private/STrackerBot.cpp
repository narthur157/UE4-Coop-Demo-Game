#include "STrackerBot.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "NavigationSystem.h"
#include "GameFramework/Character.h"
#include "NavigationPath.h"
#include "SHealthComponent.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "CoopGame.h"
#include "GameFramework/GameState.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/SphereComponent.h"
#include "Sound/SoundCue.h"
#include "Gameplay/GameplayComponents/TeamComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "TimerManager.h"
#include "Game/SGameState.h"
#include "Engine/Engine.h"
#include "Net/UnrealNetwork.h"
#include "DrawDebugHelpers.h"

static int32 DebugTrackerBotNavigation = 0;
FAutoConsoleVariableRef CVARDebugTrackerBotNavigation(
	TEXT("COOP.TrackerBotNavigation"),
	DebugTrackerBotNavigation,
	TEXT("Draws debug objects for tracker bot navigation"),
	ECVF_Cheat);


ASTrackerBot::ASTrackerBot()
{
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.TickInterval = 0.1f;

    MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
    MeshComp->SetCanEverAffectNavigation(false);
    MeshComp->SetSimulatePhysics(true);
    RootComponent = MeshComp;

    HealthComp = CreateDefaultSubobject<USHealthComponent>(TEXT("Health Component"));
    HealthComp->OnHealthChanged.AddDynamic(this, &ASTrackerBot::OnTakeDamage);
    
    TeamComp = CreateDefaultSubobject<UTeamComponent>(TEXT("Team Component"));

    ProximityExplosionRadius = CreateDefaultSubobject<USphereComponent>(TEXT("ProximityRadius"));
    ProximityExplosionRadius->SetupAttachment(RootComponent);
    ProximityExplosionRadius->SetCollisionResponseToAllChannels(ECR_Ignore);
    ProximityExplosionRadius->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
}

void ASTrackerBot::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);

    DOREPLIFETIME(ASTrackerBot, bExploded);
    DOREPLIFETIME(ASTrackerBot, ExplodeTime);
    DOREPLIFETIME(ASTrackerBot, bSelfDestructionAttached);
}

// Called when the game starts or when spawned
void ASTrackerBot::BeginPlay()
{
	Super::BeginPlay();

    ProximityExplosionRadius->OnComponentBeginOverlap.AddDynamic(this, &ASTrackerBot::OnProximityRadiusOverlap);
    ProximityExplosionRadius->SetSphereRadius(ProximityRadius, true);

    if (Role == ROLE_Authority)
    {
        NextPathPoint = GetNextPathPoint();
    }

    if (!MatInstance && MeshComp)
    {
        MatInstance = MeshComp->CreateAndSetMaterialInstanceDynamicFromMaterial(0, MeshComp->GetMaterial(0));
    }
}

FVector ASTrackerBot::GetNextPathPoint()
{
    GetWorldTimerManager().ClearTimer(TimerHandle_RefreshPath);
    GetWorldTimerManager().SetTimer(TimerHandle_RefreshPath, this, &ASTrackerBot::RefreshPath, RefreshInterval, false);

    AActor* BestTarget = nullptr;
    float NearestTargetDistance = FLT_MAX;

    for (FConstPawnIterator It = GetWorld()->GetPawnIterator(); It; ++It)
    {
        APawn* TestPawn = It->Get();
        
		if (!TestPawn || TestPawn == this || UTeamComponent::IsActorFriendly(this, TestPawn))
        {
            continue;
        }


        USHealthComponent* HealthComp = TestPawn->FindComponentByClass<USHealthComponent>();

		if (HealthComp && HealthComp->GetHealth() > 0)
        {
            // Target is still alive, check and store nearest target if this target is closer than the previous nearest
            float Distance = (TestPawn->GetActorLocation() - GetActorLocation()).Size();
            
			if (NearestTargetDistance > Distance)
            {
                BestTarget = TestPawn;
                NearestTargetDistance = Distance;
            }
        }
    }

    if (BestTarget)
    {
        UNavigationPath* NavPath = UNavigationSystemV1::FindPathToActorSynchronously(GetWorld(), GetActorLocation(), BestTarget);

        if (NavPath && NavPath->PathPoints.Num() > 0)
        {
			if (DebugTrackerBotNavigation)
			{
				DrawDebugSphere(GetWorld(), NavPath->PathPoints[1], 100, 12, FColor::Red, true, 5.0f, 0, 1);
			}

            return NavPath->PathPoints[1];
        }
		else
		{
			return BestTarget->GetActorLocation();
		}
    }

	UE_LOG(LogTemp, Error, TEXT("TrackerBot failed to find path"));

    return GetActorLocation();
}

void ASTrackerBot::OnTakeDamage(USHealthComponent * ChangedHealthComp, float Health, float HealthDelta, 
    const UDamageType * DamageType, AController * InstigatedBy, AActor * DamageCauser)
{
    if (Health <= 0)
    {
        SelfDestruct();
    }
}

void ASTrackerBot::SelfDestruct()
{
    if (bExploded) { return; }

    bExploded = true;
    OnRep_Exploded();

    if (Role == ROLE_Authority)
    {
        TArray<AActor*> IgnoredActors = { };
        
		float ActualDamage = ((GetDamageModifier() / 100) * ExplosionDamage) + ExplosionDamage;
		bool bScaleDamageByDistance = bBotAttachesToPlayer;

        UGameplayStatics::ApplyRadialDamage(this, ActualDamage, GetActorLocation(), ExplosionRadius,nullptr, IgnoredActors,this,GetController(), bScaleDamageByDistance);
        // Kill ourselves
        UGameplayStatics::ApplyDamage(this, HealthComp->GetHealth(), GetController(), this, nullptr);
        
        // Give clients a chance to play effects
        SetLifeSpan(4.0);
    }

	MeshComp->SetCollisionResponseToAllChannels(ECR_Ignore);
}

void ASTrackerBot::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

    if (!bSelfDestructionAttached && !bExploded && Role == ROLE_Authority)
    {
        MoveTowardsTarget(DeltaTime);
    }
}

void ASTrackerBot::MoveTowardsTarget(float DeltaTime)
{
    float DistanceToTarget = (GetActorLocation() - NextPathPoint).Size();

    if (DistanceToTarget <= RequiredDistanceToTarget)
    {
        NextPathPoint = GetNextPathPoint();
    }

	FVector ForceDirection = NextPathPoint - GetActorLocation();
	ForceDirection.Normalize();

	float ActualMoveSpeed = GetVelocity().Size();
	FVector MoveDirection = GetVelocity();
	MoveDirection.Normalize();

	float SpeedTowardsTarget = (((ForceDirection + MoveDirection) / 2) * ActualMoveSpeed).Size();

	if (SpeedTowardsTarget <= MaxSpeed)
	{
		ForceDirection *= MovementForce * (DeltaTime * 100);
		MeshComp->AddForce(ForceDirection, NAME_None, bUseVelocityChange);
	}
}

void ASTrackerBot::OnProximityRadiusOverlap(UPrimitiveComponent * OverlappedComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	if (bExploded || bTriggered)
	{
		return;
	}

    APawn* OtherActorPawn = Cast<APawn>(OtherActor);
    if (OtherActorPawn && OtherActorPawn != this && !UTeamComponent::IsActorFriendly(OtherActorPawn, this))
    {
		USHealthComponent* OtherHealth = OtherActor->FindComponentByClass<USHealthComponent>();

        if (Role == ROLE_Authority)
        {
			if (bBotAttachesToPlayer)
			{
				AttachBotToActor(OtherActorPawn);
			}
            
            GetWorldTimerManager().SetTimer(SelfDestructCountdownTimer, this, &ASTrackerBot::SelfDestruct, SelfDestructTime, false);
            ExplodeTime = GetWorld()->TimeSeconds + SelfDestructTime;
            OnRep_ExplodeTime();
        }

        UGameplayStatics::SpawnSoundAttached(TriggeredSound, RootComponent);
        bTriggered = true;
    }
}

void ASTrackerBot::RefreshPath()
{
   NextPathPoint = GetNextPathPoint();
}

void ASTrackerBot::SelfDestructTick()
{
    UGameplayStatics::SpawnSoundAttached(SelfDestructTickSound, RootComponent);
    float TimeRemainingUntilDestruction = ExplodeTime - GetWorld()->TimeSeconds;
    GetWorldTimerManager().SetTimer(SelfDestructionTickTimer, this, &ASTrackerBot::SelfDestructTick, TimeRemainingUntilDestruction/4, false);

}

void ASTrackerBot::OnRep_ExplodeTime()
{
    TRACE("%s started self destruct. Destruct time : %f", *GetName(), ExplodeTime);
    GetWorldTimerManager().SetTimer(SelfDestructionTickTimer, this, &ASTrackerBot::SelfDestructTick, (ExplodeTime - GetWorld()->TimeSeconds) / 4, false);
}

void ASTrackerBot::OnRep_TrackerBotAttached()
{
    MeshComp->SetSimulatePhysics(false);
    MeshComp->SetCollisionResponseToAllChannels(ECR_Ignore);
    MeshComp->SetCollisionResponseToChannel(COLLISION_PROJECTILE, ECR_Block);
    MeshComp->SetCollisionResponseToChannel(COLLISION_WEAPON, ECR_Block);
}

void ASTrackerBot::OnRep_Exploded()
{
    TRACE("%s self destructed, time: %f", *GetName(), GetWorld()->TimeSeconds)
    UGameplayStatics::PlaySoundAtLocation(this, ExplodeSound, GetActorLocation());
    UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ExplosionEffect, GetActorLocation());
    GetWorldTimerManager().ClearTimer(SelfDestructCountdownTimer);
    GetWorldTimerManager().ClearTimer(SelfDestructionTickTimer);

    MeshComp->SetVisibility(false);
    MeshComp->SetSimulatePhysics(false);
    MeshComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

bool ASTrackerBot::AttachBotToActor(APawn* OtherPawn)
{
	USkeletalMeshComponent* OtherMesh = OtherPawn->FindComponentByClass<USkeletalMeshComponent>();

	if (OtherMesh)
	{
		bool ActorHasTrackerBot = false;
		TArray<AActor*> AttachedActors;
		OtherPawn->GetAttachedActors(AttachedActors);
		for (AActor* Actor : AttachedActors)
		{
			if (Actor->IsA<ASTrackerBot>())
			{
				ActorHasTrackerBot = true;
				break;
			}
		}

		if (!ActorHasTrackerBot)
		{
			// TODO: Add function on actor (maybe even an interface) to add other actors like this one to sockets 
			// As of right now multiple trigger bots can attach to the back slod and that's bad
			OnRep_TrackerBotAttached();
			AttachToComponent(OtherMesh, FAttachmentTransformRules::SnapToTargetNotIncludingScale, "Back");
			bSelfDestructionAttached = true;
			return true;
		}
	}

	return false;
}

uint8 ASTrackerBot::GetTeamID()
{
    return TeamComp->GetTeamID();
}

FVector ASTrackerBot::GetSize()
{
    return FVector(MeshComp->Bounds.SphereRadius, MeshComp->Bounds.SphereRadius, MeshComp->Bounds.SphereRadius);
}


