// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SPowerupActor.generated.h"

class USoundBase;
class UParticleSystem;
class UParticleSystemComponent;
class USceneComponent;
class USPulseGlowComponent;

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

	UFUNCTION()
	void OnRep_PowerupActive();

	UFUNCTION(BlueprintImplementableEvent, Category = "Powerup")
	void OnPowerupStateChanged(bool bNewIsActive);

	UFUNCTION(NetMulticast, WithValidation, Reliable)
	void MulticastSpawnPowerupEffect(AActor* MyActor);

	UFUNCTION(NetMulticast, WithValidation, Reliable)
	void MulticastDespawnPowerupEffect();

	UFUNCTION()
	void OnTickPowerup();


	// Will be attached to actor for duration of powerup if defined
	UPROPERTY(EditDefaultsOnly, Category = "PowerupFX")
	UParticleSystem* PowerupEffect = nullptr;

	// Alternative to defining an attachment point
	UPROPERTY(EditDefaultsOnly, Category = "PowerupFX")
	FVector PowerupEffectSpawnOffset = FVector::ZeroVector;

	UPROPERTY(EditDefaultsOnly, Category = "PowerupFX")
	FColor GlowColor = FColor::White;

	UPROPERTY(EditDefaultsOnly, Category = "PowerupFX")
	USoundBase* PowerupSound;

	// Time between powerup ticks
    UPROPERTY(EditDefaultsOnly, Category = "Powerup")
    float PowerupInterval= 0.0f;

    // Total times this powerup effect is applied
    UPROPERTY(EditDefaultsOnly, Category = "Powerup")
    int32 TotalNumberOfTicks = 0;

	// Actor who received the powerup
	UPROPERTY(BlueprintReadOnly)
	AActor* ActivatedFor = nullptr;

	UPROPERTY(ReplicatedUsing = OnRep_PowerupActive)
	bool bIsPowerupActive = false;

	UParticleSystemComponent* ActivePowerupEffect = nullptr;

	USPulseGlowComponent* ActivePulseComp = nullptr;

    FTimerHandle TimerHandle_PowerupTick;

    int32 TicksProcessed = 0;

public:	

    void ActivatePowerup(AActor* InstigatorActor);

    UFUNCTION(BlueprintImplementableEvent, Category = "Powerup")
    void OnActivated(AActor* InstigatorActor);

    UFUNCTION(BlueprintImplementableEvent, Category = "Powerup")
    void OnPowerupTicked();

    UFUNCTION(BlueprintImplementableEvent, Category = "Powerup")
    void OnExpired();
	
};
