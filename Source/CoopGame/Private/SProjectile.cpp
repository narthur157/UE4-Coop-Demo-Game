// Fill out your copyright notice in the Description page of Project Settings.

#include "SProjectile.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/ProjectileMovementComponent.h"


// Sets default values
ASProjectile::ASProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
   
    CollisionComp = CreateDefaultSubobject<USphereComponent>(TEXT("CollisionComponent"));
    SetRootComponent(CollisionComp);


    MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
    MeshComp->SetNotifyRigidBodyCollision(true);
    MeshComp->SetVisibility(true);
    MeshComp->SetupAttachment(CollisionComp);

    MovementComp = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Projectile Movement Component"));
    MovementComp->bAutoActivate = true;
    MovementComp->SetUpdatedComponent(RootComponent);
    MovementComp->bShouldBounce = true;
    MovementComp->Bounciness = 0.6f;

 

}

void ASProjectile::Launch(float LaunchSpeed)
{
    MovementComp->SetVelocityInLocalSpace(FVector::ForwardVector * LaunchSpeed);
    MovementComp->Activate();
    FTimerHandle FuseTimerHandle;
    GetWorld()->GetTimerManager().SetTimer(FuseTimerHandle, this, &ASProjectile::OnFuseExpire, FuseDuration, false);
    OnActorHit.AddDynamic(this, &ASProjectile::OnProjectileHit);
}

void ASProjectile::OnFuseExpire()
{
    Explode();
}

void ASProjectile::OnProjectileHit(AActor * SelfActor, AActor * OtherActor, FVector NormalImpulse, const FHitResult & Hit)
{
    if (bExplodeOnContact && Cast<APawn>(OtherActor) && Cast<APawn>(OtherActor) != Instigator)
    {
        Explode();
    }
}

void ASProjectile::Explode()
{
    if (ExplosionEffect)
    {
        UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ExplosionEffect, GetActorLocation(), FVector::ZeroVector.Rotation());
    }
    
    UGameplayStatics::ApplyRadialDamage(GetWorld(), Damage, GetActorLocation(), DamageRadius, DamageType, IgnoredActors);
    Destroy();
}