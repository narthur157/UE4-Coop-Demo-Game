// Fill out your copyright notice in the Description page of Project Settings.

#include "STrackerBot.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "AI/Navigation/NavigationSystem.h"
#include "GameFramework/Character.h"
#include "AI/Navigation/NavigationPath.h"
#include "DrawDebugHelpers.h"
#include "SHealthComponent.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "CoopGame.h"
#include "Components/SphereComponent.h"
#include "Sound/SoundCue.h"
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

}

void ASTrackerBot::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);

    DOREPLIFETIME(ASTrackerBot, ExplodeTime);
    DOREPLIFETIME(ASTrackerBot, bSelfDestructionAttached);

}

// Called when the game starts or when spawned
void ASTrackerBot::BeginPlay()
{
	Super::BeginPlay();

    if (Role == ROLE_Authority)
    {
        FVector NextPathPoint = GetNextPathPoint();
    }
    ProximityExplosionRadius->OnComponentBeginOverlap.AddDynamic(this, &ASTrackerBot::OnProximityRadiusOverlap);
    ProximityExplosionRadius->SetSphereRadius(ProximityRadius, true);
   
}

FVector ASTrackerBot::GetNextPathPoint()
{
    // HAck
    ACharacter* PlayerPawn = UGameplayStatics::GetPlayerCharacter(this, 0);
    if (!PlayerPawn)
    {
        return GetActorLocation();
    }

    UNavigationPath* NavPath = UNavigationSystem::FindPathToActorSynchronously(this, GetActorLocation(), PlayerPawn);

    if (NavPath && NavPath->PathPoints.Num() > 1)
    {
        // Next point
        return NavPath->PathPoints[1];
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
    if (!MatInstance && MeshComp)
    {
        MatInstance = MeshComp->CreateAndSetMaterialInstanceDynamicFromMaterial(0, MeshComp->GetMaterial(0));
    }
    if (MatInstance->IsValidLowLevel())
    {
        MatInstance->SetScalarParameterValue("LastTimeDamageTaken", GetWorld()->TimeSeconds);
    }
}


void ASTrackerBot::SelfDestruct()
{
    if (bExploded)
    {
        return;
    }

    bExploded = true;
    UGameplayStatics::PlaySoundAtLocation(this, ExplodeSound, GetActorLocation());
    UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ExplosionEffect, GetActorLocation());
    GetWorldTimerManager().ClearTimer(SelfDestructCountdownTimer);
    GetWorldTimerManager().ClearTimer(SelfDestructionTickTimer);

    MeshComp->SetVisibility(false);
    MeshComp->SetSimulatePhysics(false);
    MeshComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);

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

        DrawDebugString(GetWorld(), GetActorLocation(), "Target Reached");
    }
    else
    {
        FVector ForceDirection = NextPathPoint - GetActorLocation();
        ForceDirection.Normalize();
        ForceDirection *= MovementForce;

        // Keep moving on
        MeshComp->AddForce(ForceDirection, NAME_None, bUseVelocityChange);
    }
    DrawDebugSphere(GetWorld(), NextPathPoint, 20, 12, FColor::Yellow, false, 4.0, 1.0);
}

void ASTrackerBot::OnProximityRadiusOverlap(UPrimitiveComponent * OverlappedComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
    if (OtherComp != OtherActor->GetRootComponent())
    {
        return;
    }
    APawn* OtherActorPawn = Cast<APawn>(OtherActor);
    if (OtherActorPawn && !bSelfDestructionAttached && !bExploded)
    {
        if (Role == ROLE_Authority)
        {
            USkeletalMeshComponent* OtherMesh = OtherActorPawn->FindComponentByClass<USkeletalMeshComponent>();
            if (OtherMesh)
            {
                // TODO: Add function on actor (maybe even an interface) to add other actors like this one to sockets 
                // As of right now multiple trigger bots can attach to the back slod and that's bad
                bSelfDestructionAttached = true;
                OnRep_TrackerBotAttached();
                AttachToComponent(OtherMesh, FAttachmentTransformRules::SnapToTargetNotIncludingScale, "Back");
            }
            ExplodeTime = GetWorld()->TimeSeconds + SelfDestructTime;
            OnRep_ExplodeTime();
        }
        
        UGameplayStatics::SpawnSoundAttached(TriggeredSound, RootComponent);
    }
}

void ASTrackerBot::SelfDestructTick()
{
    UGameplayStatics::SpawnSoundAttached(SelfDestructTickSound, RootComponent);
    float TimeRemainingUntilDestruction = GetWorldTimerManager().GetTimerRemaining(SelfDestructCountdownTimer);
    GetWorldTimerManager().SetTimer(SelfDestructionTickTimer, this, &ASTrackerBot::SelfDestructTick, TimeRemainingUntilDestruction/4, false);

}

void ASTrackerBot::OnRep_ExplodeTime()
{
    GetWorldTimerManager().SetTimer(SelfDestructCountdownTimer, this, &ASTrackerBot::SelfDestruct, ExplodeTime - GetWorld()->TimeSeconds, false);
    GetWorldTimerManager().SetTimer(SelfDestructionTickTimer, this, &ASTrackerBot::SelfDestructTick, (ExplodeTime - GetWorld()->TimeSeconds) / 4, false);
}

void ASTrackerBot::OnRep_TrackerBotAttached()
{
    MeshComp->SetSimulatePhysics(false);
    MeshComp->SetCollisionResponseToAllChannels(ECR_Ignore);
    MeshComp->SetCollisionResponseToChannel(COLLISION_PROJECTILE, ECR_Block);
    MeshComp->SetCollisionResponseToChannel(COLLISION_WEAPON, ECR_Block);
}

