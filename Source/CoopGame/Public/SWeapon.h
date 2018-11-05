#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SWeapon.generated.h"

class UDamageType;
class UCameraShake;
class UParticleSystem;
class USoundCue;
class UTexture2D;
class UImage;
class USHitIndicatorWidget;

UENUM(BlueprintType)
enum class EAmmoType : uint8
{
    Bullet,
    Grenade, 
    NONE
};

UCLASS()
class COOPGAME_API ASWeapon : public AActor
{
	GENERATED_BODY()
	
public:	
	ASWeapon();

    UFUNCTION(BlueprintCallable, Category = "Weapon")
    EAmmoType GetAmmoType() { return AmmoType; }

    UFUNCTION(BlueprintCallable, Category = "Weapon")
    UTexture2D* GetWeaponIcon() { return WeaponIcon; }

    UFUNCTION(BlueprintCallable, Category = "Weapon")
    float GetAmmoInClip() { return AmmoInClip; }

protected:

    // Weapon Data
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    USkeletalMeshComponent* MeshComp = nullptr;

    UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Weapon")
    FName MuzzleSocketName = "MuzzleSocket";

    UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Weapon")
    FName TracerTargetName = "Target";

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Weapon")
    UParticleSystem* MuzzleEffect = nullptr;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Weapon")
    UParticleSystem* TracerEffect = nullptr;

    UPROPERTY(EditDefaultsOnly, Category = "Weapon")
    USoundCue* FireSound = nullptr;

    UPROPERTY(EditDefaultsOnly, Category = "Weapon")
    UTexture2D* WeaponIcon = nullptr;

    UPROPERTY(EditDefaultsOnly, Category = "Weapon")
    float TimeBetweenShots = 0.5f;

    UPROPERTY(EditDefaultsOnly, Category = "WeaponData")
    EAmmoType AmmoType = EAmmoType::NONE;


    UPROPERTY(EditDefaultsOnly, Replicated, Category = "WeaponData")
    float AmmoInClip = 20.0f;

	USHitIndicatorWidget* HitIndicatorWidget = nullptr;

	UPROPERTY(EditDefaultsOnly, Category = "Weapon")
	TSubclassOf<USHitIndicatorWidget> HitIndicatorWidgetClass;

    // Instance variables
    FTimerHandle TimerHandle_TimeBetweenShots;

    float LastFireTime = -9999999;

    // Functionality
    virtual void Fire() {}

    UFUNCTION(Server, Reliable, WithValidation)
    void ServerFire();

public:	

	virtual void BeginPlay() override;

public:
	virtual void OnHit(AActor* HitActor, bool bSkipCheck = false);

    UFUNCTION(BlueprintCallable, Category = "Weapon")
    virtual void StartFire();

    UFUNCTION(BlueprintCallable, Category = "Weapon")
    virtual void StopFire();	
   
};
