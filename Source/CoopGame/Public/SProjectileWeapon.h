#pragma once

#include "CoreMinimal.h"
#include "SWeapon.h"
#include "SProjectileWeapon.generated.h"

class ASProjectile;

USTRUCT()
struct FProjectileWeaponData
{
    GENERATED_BODY()

    UPROPERTY(EditDefaultsOnly, Category = "ProjectileWeaponData")
	TSubclassOf<UDamageType> ProjectileDamageType;

	UPROPERTY(EditDefaultsOnly, Category = "ProjectileWeaponData")
	float ProjectileLifeTime = -1.0f;

	UPROPERTY(EditDefaultsOnly, Category = "ProjectileWeaponData")
	float ProjectileDamage = 0.0f;

	UPROPERTY(EditDefaultsOnly, Category = "ProjectileWeaponData")
	float ProjectileDamageDirectHit = 0.0f;

	UPROPERTY(EditDefaultsOnly, Category = "ProjectileWeaponData")
	float ProjectileRadius = 0.0f;


    bool DoesExpire()
    {
        return ProjectileLifeTime > 0 ? true : false;
    }
};

UCLASS()
class COOPGAME_API ASProjectileWeapon : public ASWeapon
{
	GENERATED_BODY()

public:
	ASProjectileWeapon();

protected:
	UPROPERTY(EditDefaultsOnly, Category = "ProjectileWeapon")
	FVector ProjectileSpawnTranslate;

    UPROPERTY(EditDefaultsOnly, Category = "ProjectileWeapon")
	TSubclassOf<ASProjectile> ProjectileClass;

	UPROPERTY(EditAnywhere, Category = "ProjectileWeapon")
    FProjectileWeaponData ProjectileWeaponConfigData;

    virtual void Fire() override;
};
