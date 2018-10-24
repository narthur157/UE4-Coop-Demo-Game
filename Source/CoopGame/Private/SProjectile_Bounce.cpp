// Fill out your copyright notice in the Description page of Project Settings.

#include "SProjectile_Bounce.h"
#include "GameFramework/ProjectileMovementComponent.h"


ASProjectile_Bounce::ASProjectile_Bounce()
    : ASProjectile()
{
    MovementComp->bShouldBounce = true;
    MovementComp->Bounciness = 0.6;
}

void ASProjectile_Bounce::OnProjectileHit(AActor * SelfActor, AActor * OtherActor, FVector NormalImpulse, const FHitResult & Hit)
{
    if (Cast<APawn>(OtherActor))
    {
        Explode();
    }
}