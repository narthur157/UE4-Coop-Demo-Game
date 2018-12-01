#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SWeapon.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnWeaponHit, AActor*, HitActor);

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

    UPROPERTY(BlueprintAssignable, Category = "Weapon")
    FOnWeaponHit OnWeaponHit;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Weapon")
    float TimeToReload = 1.5f;

    UPROPERTY(Replicated, BlueprintReadOnly, Category = "Weapon")
    bool bIsReloading;

    UFUNCTION(BlueprintCallable, Category = "Weapon")
    EAmmoType GetAmmoType() { return AmmoType; }

    UFUNCTION(BlueprintCallable, Category = "Weapon")
    UTexture2D* GetWeaponIcon() { return WeaponIcon; }

    UFUNCTION(BlueprintCallable, Category = "Weapon")
    float GetAmmoInClip() { return AmmoInClip; }

    virtual void BeginPlay() override;
    virtual void Reload();
    virtual void CancelReload();
    virtual void OnHit(AActor* HitActor, bool bSkipCheck = false);

    UFUNCTION(BlueprintCallable, Category = "Weapon")
    virtual void StartFire();

    UFUNCTION(BlueprintCallable, Category = "Weapon")
    virtual void StopFire();

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

    UPROPERTY(EditDefaultsOnly, Category = "Weapon")
    EAmmoType AmmoType = EAmmoType::NONE;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Weapon")
	uint8 MaxAmmo = 20;

    UPROPERTY(Replicated)
    uint8 AmmoInClip = MaxAmmo;

	USHitIndicatorWidget* HitIndicatorWidget = nullptr;

	UPROPERTY(EditDefaultsOnly, Category = "Weapon")
	TSubclassOf<USHitIndicatorWidget> HitIndicatorWidgetClass;

    // Instance variables
    FTimerHandle TimerHandle_TimeBetweenShots;

    float LastFireTime = -9999999;

	FTimerHandle TimerHandle_ReloadTimer;

    // Functionality
	virtual void Fire() {};

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerReload();

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerCancelReload();

    UFUNCTION(Server, Reliable, WithValidation)
    void ServerFire();

};
