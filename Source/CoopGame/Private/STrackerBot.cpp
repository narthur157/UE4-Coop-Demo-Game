// Fill out your copyright notice in the Description page of Project Settings.

#include "STrackerBot.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "AI/Navigation/NavigationSystem.h"
#include "GameFramework/Character.h"
#include "AI/Navigation/NavigationPath.h"
#include "SHealthComponent.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "CoopGame.h"
#include "GameFramework/GameState.h"
#include "Components/SphereComponent.h"
#include "Sound/SoundCue.h"
#include "Particles/ParticleSystemComponent.h"
#include "Net/UnrealNetwork.h"


ASTrackerBot::ASTrackerBot()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
    MeshComp->SetCanEverAffectNavigation(false);
    MeshComp->SetSimulatePhysics(true);
    RootComponent = MeshComp;

    HealthComp = CreateDefaultSubobject<USHealthComponent>(TEXT("Health Component"));
    HealthComp->OnHealthChanged.AddDynamic(this, &ASTrackerBot::OnTakeDamage);
    
    ProximityExplosionRadius = CreateDefaultSubobject<USphereComponent>(TEXT("ProximityRadius"));
    ProximityExplosionRadius->SetupAttachment(RootComponent);
    ProximityExplosionRadius->SetCollisionResponseToAllChannels(ECR_Ignore);
    ProximityExplosionRadius->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
    //.

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
    AActor* BestTarget = nullptr;
    float NearestTargetDistance = FLT_MAX;

    for (FConstPawnIterator It = GetWorld()->GetPawnIterator(); It; ++It)
    {
        APawn* TestPawn = It->Get();
        if (!TestPawn || TestPawn == this || USHealthComponent::IsFriendly(TestPawn, this))
        {
            continue;
        }
        USHealthComponent* HealthComp = TestPawn->FindComponentByClass<USHealthComponent>();
        if (HealthComp && HealthComp->GetHealth() > 0)
        {
            // Bot is still alive, check and store nearest target if this target is closer than the previous nearest
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
        UNavigationPath* NavPath = UNavigationSystem::FindPathToActorSynchronously(this, GetActorLocation(), BestTarget);

        GetWorldTimerManager().ClearTimer(TimerHandle_RefreshPath);
        GetWorldTimerManager().SetTimer(TimerHandle_RefreshPath, this, &ASTrackerBot::RefreshPath, 5.0f, false);

        if (NavPath && NavPath->PathPoints.Num() > 1)
        {
            // Next point
            return NavPath->PathPoints[1];
        }
    }

    return GetActorLocation();
}

void ASTrackerBot::OnTakeDamage(USHealthComponent * ChangedHealthComp, float Health, float HealthDelta, 
    const UDamageType * DamageType, AController * InstigatedBy, AActor * DamageCauser)
{
    if (Health <= 0)
    {
        SelfDestruct();
    }
    if (MatInstance->IsValidLowLevel())
    {
        MatInstance->SetScalarParameterValue("LastTimeDamageTaken", GetWorld()->TimeSeconds);
    }
}


void ASTrackerBot::SelfDestruct()
{
    if (bExploded) { return; }

    bExploded = true;
    OnRep_Exploded();

    if (Role == ROLE_Authority)
    {
        TArray<AActor*> IgnoredActors = { this };
        float ActualDamage = ((GetDamageModifier() / 100) * ExplosionDamage) + ExplosionDamage;
        UGameplayStatics::ApplyRadialDamage(this, ActualDamage, GetActorLocation(), ExplosionRadius, nullptr, IgnoredActors, this, GetInstigatorController(), true);
        // Give clients a chance to play effects
        SetLifeSpan(4.0);
    }
}

// Called every frame
void ASTrackerBot::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
    if (!bSelfDestructionAttached && !bExploded && Role == ROLE_Authority)
    {
        MoveTowardsTarget();
    }
}

void ASTrackerBot::MoveTowardsTarget()
{
    float DistanceToTarget = (GetActorLocation() - NextPathPoint).Size();

    if (DistanceToTarget <= RequiredDistanceToTarget)
    {
        NextPathPoint = GetNextPathPoint();
    }
    else
    {
        // Need to move towards the current NextPathPoint
        FVector ForceDirection = NextPathPoint - GetActorLocation();
        ForceDirection.Normalize();
        ForceDirection *= MovementForce;
        MeshComp->AddForce(ForceDirection, NAME_None, bUseVelocityChange);
    }
}

void ASTrackerBot::OnProximityRadiusOverlap(UPrimitiveComponent * OverlappedComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{

    APawn* OtherActorPawn = Cast<APawn>(OtherActor);
    // If the other actor 
    if (OtherActorPawn && OtherActorPawn != this && !USHealthComponent::IsFriendly(OtherActorPawn, this))
    {
        if (Role == ROLE_Authority)
        {
            USkeletalMeshComponent* OtherMesh = OtherActorPawn->FindComponentByClass<USkeletalMeshComponent>();

            if (OtherMesh)
            {
                bool ActorHasTrackerBot = false;
                TArray<AActor*> AttachedActors;
                OtherActorPawn->GetAttachedActors(AttachedActors);
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
                }
            }
            
            GetWorldTimerManager().SetTimer(SelfDestructCountdownTimer, this, &ASTrackerBot::SelfDestruct, SelfDestructTime, false);
            ExplodeTime = GetWorld()->TimeSeconds + SelfDestructTime;
            OnRep_ExplodeTime();
        }
        if (!bTriggered)
        {
            UGameplayStatics::SpawnSoundAttached(TriggeredSound, RootComponent);
            bTriggered = true;
        }
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