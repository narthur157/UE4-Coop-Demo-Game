// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SWeapon.h"
#include "SHitscanWeapon.generated.h"

/**
 * 
 */
UCLASS()
class COOPGAME_API ASHitscanWeapon : public ASWeapon
{
	GENERATED_BODY()
	
	
public:

protected:

    UPROPERTY(EditDefaultsOnly, Category = "Weapon")
    TSubclassOf<UDamageType> DamageType;

    UPROPERTY(EditDefaultsOnly, Category = "Weapon")
    float BaseDamage = 20.0f;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Weapon")
    UParticleSystem* DefaultImpactEffect = nullptr;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Weapon")
    UParticleSystem* FleshImpactEffect = nullptr;

    virtual void Fire() override;

    void DrawTracerEffect(const FVector &TraceEndPoint);

    void PlayImpactEffect(const FHitResult& Hit);

public:

};
