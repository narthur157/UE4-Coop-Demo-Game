// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SPowerupActor.generated.h"


UCLASS()
class COOPGAME_API ASPowerupActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASPowerupActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

    // Time between powerup ticks
    UPROPERTY(EditDefaultsOnly, Category = "Powerup")
    float PowerupInterval= 0.0f;

    // Total times this powerup effect is applied
    UPROPERTY(EditDefaultsOnly, Category = "Powerup")
    int32 TotalNumberOfTicks = 0;

    FTimerHandle TimerHandle_PowerupTick;

    int32 TicksProcessed = 0;

    UFUNCTION()
    void OnTickPowerup();


public:	

    void ActivatePowerup();

    UFUNCTION(BlueprintImplementableEvent, Category = "Powerup")
    void OnActivated();

    UFUNCTION(BlueprintImplementableEvent, Category = "Powerup")
    void OnPowerupTicked();

    UFUNCTION(BlueprintImplementableEvent, Category = "Powerup")
    void OnExpired();
	
};
