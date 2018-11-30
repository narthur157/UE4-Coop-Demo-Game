// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SHealthComponent.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_SixParams(FOnHealthChangedSignature, USHealthComponent*, HealthComp, float, Health, float, HealthDelta, const class UDamageType*, DamageType, class AController*, InstigatedBy, AActor*, DamageCauser);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnKilled, AActor*, KilledActor);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnDealtDamage, AActor*, DamageDealer, AActor*, DamageReciever, AActor*, DamageCauser);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnDamageTaken, AActor*, DamageReciever, AActor*, DamageDealer, AActor*, DamageCauser);

UCLASS( ClassGroup=(COOP), meta=(BlueprintSpawnableComponent) )
class COOPGAME_API USHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	USHealthComponent();

    UPROPERTY(EditDefaultsOnly, Replicated, BlueprintReadOnly, Category = "HealthComponent")
    bool bDamageSelf = true;

    UPROPERTY(BlueprintAssignable, Category = "HealthComponentEvents")
    FOnHealthChangedSignature OnHealthChanged;

    UFUNCTION(BlueprintCallable, Category = "HealthComponent")
    void Heal(float HealAmount);

    UFUNCTION(BlueprintCallable, Category = "HealthComponent")
    float GetHealth() const { return Health; }

    // Interface delegates which fire on major health related events
    // Intended to be more narrow in scope than OnHealthChanged
    UPROPERTY(BlueprintAssignable, Category = "DamageEventDelegates")
    FOnKilled OnKilled;

    UPROPERTY(BlueprintAssignable, Category = "DamageEventDelegates")
    FOnDealtDamage OnDamageDealt;

    UPROPERTY(BlueprintAssignable, Category = "DamageEventDelegates")
    FOnDamageTaken OnDamageTaken;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

    UPROPERTY(ReplicatedUsing=OnRep_Health, BlueprintReadOnly, Category = "HealthComponent")
    float Health;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HealthComponent")
    float MaxHealth = 100.0f;

    UFUNCTION()
    void HandleTakeDamage(AActor* DamagedActor, float Damage, const class UDamageType* DamageType, class AController* InstigatedBy, AActor* DamageCauser);

    UFUNCTION()
    void OnRep_Health(float OldHealth);

    bool bIsDead = false;

    AActor * DetermineDamageInstigatorActor(AController * DamageInstigator, AActor * DamageCauser);
    
};
