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

protected:
	/**
	 * 3rd person Projectiles generally should not be spawned from the actual muzzle, rather
	 * the camera, as this represents where the character is really aiming
	 * This creates a jarring effect visually, so the easiest solution is a distracting
	 * muzzle flash, in addition to spawning the projectile a bit ahead of the camera
	 * TODO: Hide the projectile until it is past this distance instead of spawning it there
	 */
	UPROPERTY(EditDefaultsOnly, Category = "ProjectileWeapon")
	float ProjectileSpawnOffset = 250.0f;

    UPROPERTY(EditDefaultsOnly, Category = "ProjectileWeapon")
	TSubclassOf<ASProjectile> ProjectileClass;

	UPROPERTY(EditAnywhere, Category = "ProjectileWeapon")
    FProjectileWeaponData ProjectileWeaponConfigData;

    UFUNCTION(BlueprintCallable, Category = "ProjectileWeapon")
    void SpawnProjectile(TSubclassOf<ASProjectile> Projectile, bool bAttemptPrediction, TArray<AActor*> IgnoredActors);

};
