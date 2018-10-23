// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SProjectile.generated.h"

class UProjectileMovementComponent;
class USphereComponent;

UCLASS()
class COOPGAME_API ASProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASProjectile();

protected:

    UPROPERTY(VisibleAnywhere, Category = "Components")
    USphereComponent* CollisionComp = nullptr;

    UPROPERTY(VisibleAnywhere, Category = "Components")
    UProjectileMovementComponent* MovementComp = nullptr;

    UPROPERTY(VisibleAnywhere, Category = "Components")
    UStaticMeshComponent* MeshComp = nullptr;

public:	
    virtual void Launch(float LaunchSpeed);
	
};
