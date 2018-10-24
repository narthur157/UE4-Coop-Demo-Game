// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SWeapon.h"
#include "SProjectileWeapon.generated.h"

class ASProjectile;

USTRUCT()
struct FProjectileWeaponData
{
    GENERATED_BODY()

    UPROPERTY(EditDefaultsOnly)
    TSubclassOf<UDamageType> ProjectileDamageType;

    UPROPERTY(EditDefaultsOnly)
    float ProjectileLifeTime = -1.0f;

    UPROPERTY(EditDefaultsOnly)
    float ProjectileDamage = 0.0f;

    UPROPERTY(EditDefaultsOnly)
    float ProjectileRadius = 0.0f;

    UPROPERTY(EditDefaultsOnly)
    float LaunchSpeed = 0.0f;

    bool DoesExpire()
    {
        return ProjectileLifeTime > 0 ? true : false;
    }
};

/**
 * 
 */
UCLASS()
class COOPGAME_API ASProjectileWeapon : public ASWeapon
{
	GENERATED_BODY()
	
public:

protected:

    UPROPERTY(EditDefaultsOnly, Category = "Weapon")
    TSubclassOf<ASProjectile> ProjectileClass;

    UPROPERTY(EditAnywhere, Category = "Weapon")
    FProjectileWeaponData ProjectileWeaponConfigData;

    virtual void Fire() override;

};
