// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SProjectile.h"
#include "SProjectile_Bounce.generated.h"

/**
 * 
 */
UCLASS()
class COOPGAME_API ASProjectile_Bounce : public ASProjectile
{
	GENERATED_BODY()
	
public:
    ASProjectile_Bounce();

protected:

    virtual void OnProjectileHit(AActor * SelfActor, AActor * OtherActor, FVector NormalImpulse, const FHitResult & Hit) override;
	
	
};
