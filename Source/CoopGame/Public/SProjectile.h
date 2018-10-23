// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SProjectile.generated.h"

class UProjectileMovementComponent;

UCLASS()
class COOPGAME_API ASProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

    UPROPERTY(VisibleAnywhere, Category = "Components")
    UProjectileMovementComponent* MovementComp = nullptr;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

    virtual void Launch(float LaunchSpeed);
	
};
