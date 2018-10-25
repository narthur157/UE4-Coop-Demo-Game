// Fill out your copyright notice in the Description page of Project Settings.

#include "SProjectile.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "SProjectileWeapon.h"


// Sets default values
ASProjectile::ASProjectile()
{

    CollisionComp = CreateDefaultSubobject<USphereComponent>(TEXT("CollisionComponent"));
    SetRootComponent(CollisionComp);

    MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
    MeshComp->SetNotifyRigidBodyCollision(true);
    MeshComp->SetVisibility(true);
    MeshComp->SetupAttachment(CollisionComp);


    MovementComp = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Projectile Movement Component"));
    MovementComp->bAutoActivate = true;
    MovementComp->SetUpdatedComponent(CollisionComp);

    SetReplicates(true);
    SetReplicateMovement(true);
}

void ASProjectile::Initialize(const FProjectileWeaponData & Data)
{
    WeaponData = Data;
    bWasInitialized = true;
}

void ASProjectile::Launch()
{
    if (!bWasInitialized)
    {
        UE_LOG(LogTemp, Warning, TEXT("Projectile fired despite not being Initialized. Please Initialze projectile. Undefined behavior incoming."))
    }
    UE_LOG(LogTemp, Warning, TEXT("Projectile spawned: %s"), *GetActorLocation().ToString())
    // Fire projectile
    MovementComp->SetVelocityInLocalSpace(FVector::ForwardVector * WeaponData.LaunchSpeed);
    MovementComp->Activate();

    // Register projectile to recieve hit events
    OnActorHit.AddDynamic(this, &ASProjectile::OnProjectileHit);

    // if the weapon has designated this projectile to expire, set a timer to do so
    if (WeaponData.DoesExpire())
    {
        FTimerHandle FuseTimerHandle;
        GetWorld()->GetTimerManager().SetTimer(FuseTimerHandle, this, &ASProjectile::OnProjectileExpire, WeaponData.ProjectileLifeTime, false);
    }
}

void ASProjectile::OnProjectileExpire()
{
    Explode();
}

void ASProjectile::OnProjectileHit(AActor * SelfActor, AActor * OtherActor, FVector NormalImpulse, const FHitResult & Hit)
{
    Explode();
}

void ASProjectile::Explode()
{
    if (ExplosionEffect)
    {
        UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ExplosionEffect, GetActorLocation(), FVector::ZeroVector.Rotation());
    }
    // TODO: Find a way to remove this, calculate ignored actors in projectileweapondata?
    TArray<AActor*> IgnoredActors = { this, GetOwner(), Instigator };
    UGameplayStatics::ApplyRadialDamage(GetWorld(), WeaponData.ProjectileDamage, GetActorLocation(), WeaponData.ProjectileRadius, WeaponData.ProjectileDamageType, IgnoredActors, Instigator,Instigator->GetController(),true);
    Destroy();
}