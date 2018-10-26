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
#include "Components/SphereComponent.h"

// Sets default values
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
    ProximityExplosionRadius->SetSphereRadius(ProximityRadius);
    ProximityExplosionRadius->SetupAttachment(RootComponent);
    ProximityExplosionRadius->SetCollisionResponseToAllChannels(ECR_Ignore);
    ProximityExplosionRadius->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);


}

// Called when the game starts or when spawned
void ASTrackerBot::BeginPlay()
{
	Super::BeginPlay();

    FVector NextPathPoint = GetNextPathPoint();

	
}

FVector ASTrackerBot::GetNextPathPoint()
{
    // HAck
    ACharacter* PlayerPawn = UGameplayStatics::GetPlayerCharacter(this, 0);
    if (!PlayerPawn)
    {
        return FVector::ZeroVector;
    }

    UNavigationPath* NavPath = UNavigationSystem::FindPathToActorSynchronously(this, GetActorLocation(), PlayerPawn);

    if (NavPath->PathPoints.Num() > 1)
    {
        // Next poinnt
        return NavPath->PathPoints[1];
    }

    return GetActorLocation();
}

void ASTrackerBot::OnTakeDamage(USHealthComponent * ChangedHealthComp, float Health, float HealthDelta, 
    const UDamageType * DamageType, AController * InstigatedBy, AActor * DamageCauser)
{
    //BOOM!!!!

    UE_LOG(LogTemp, Log, TEXT("Bot %s, Health: %f"), *GetName(), Health);
    if (Health <= 0)
    {
        SelfDestruct();
    }

    if (!MatInstance)
    {
        MatInstance = MeshComp->CreateAndSetMaterialInstanceDynamicFromMaterial(0, MeshComp->GetMaterial(0));
    }
    if (MatInstance)
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
    UE_LOG(LogTemp, Warning, TEXT("Exploding!!!"));
    UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ExplosionEffect, GetActorLocation());
    TArray<AActor*> IgnoredActors = { this };
    UGameplayStatics::ApplyRadialDamage(this, ExplosionDamage, GetActorLocation(), ExplosionRadius, nullptr, IgnoredActors, this, GetInstigatorController(), true);
    DrawDebugSphere(GetWorld(), GetActorLocation(), ExplosionRadius, 12, FColor::Red, false, 2.0f, 0, 1.0f);

    bExploded = true;
    Destroy();
}

// Called every frame
void ASTrackerBot::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
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

        DrawDebugDirectionalArrow(GetWorld(), GetActorLocation(), GetActorLocation() + ForceDirection, 32, FColor::Yellow, false, 0.0f, 0, 1.0f);
    }
    DrawDebugSphere(GetWorld(), NextPathPoint, 20, 12, FColor::Yellow, false, 4.0, 1.0);
}

void ASTrackerBot::NotifyActorBeginOverlap(AActor * OtherActor)
{
    if (OtherActor && Cast<APawn>(OtherActor))
    {
        SelfDestruct();
    }
}

