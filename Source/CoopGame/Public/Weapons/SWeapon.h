#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SWeapon.generated.h"

/**
Weapon rework goals: 
1.) New weapons should be createable purely in blueprints
2.) 




*/

DECLARE_DELEGATE(FOnWeaponReload);
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

    virtual void BeginPlay() override;

    // primary used to dispay hit markers, should be bound to a delegate somewhere perhaps if it needs to be accessed outside of
    // this class, rather than being public
    virtual void OnHit(AActor* HitActor, bool bSkipCheck = false);


    /** Sound played when weapon is swapped/otherwise becomes active */
    // Should really make a getter/setter for this
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Weapon")
    USoundCue* WeaponActivatedSound = nullptr;

    /** Event Delegates */

	FOnWeaponReload OnReload;

    UPROPERTY(BlueprintAssignable, Category = "Weapon")
    FOnWeaponHit OnWeaponHit;

    /** Getters/Setters */

    UFUNCTION(BlueprintCallable, Category = "Weapon")
    EAmmoType GetAmmoType() { return AmmoType; }

    UFUNCTION(BlueprintCallable, Category = "Weapon")
    UTexture2D* GetWeaponIcon() { return WeaponIcon; }

    UFUNCTION(BlueprintCallable, Category = "Weapon")
    float GetAmmoInClip() { return AmmoInClip; }

    UFUNCTION(BlueprintCallable, Category = "Weapon")
    float GetClipSize() { return ClipSize; }

    /** Current Weapon State Variables */

    UPROPERTY(Replicated, BlueprintReadOnly, Category = "Weapon")
    bool bIsReloading;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Weapon")
    float TimeToReload = 1.5f;

    /** Should be overridden if a particuar weapon requires any special cases to be true in order for it to begin firing */
    UFUNCTION(BlueprintCallable, Category = "Weapon")
    bool CanFire();

    /** Checks to see if AmmoInClip <= AmmoRequiredToFire, returns false if so. Optionally reloads the weapon if there is not enough ammo */
    UFUNCTION(BlueprintCallable, Category = "Weapon")
    bool HasAmmoRequiredToFire(bool bReloadIfFase = false);

    /** Weapon Actions */

    UFUNCTION(BlueprintCallable, Category = "Weapon")
    virtual void Reload();

    UFUNCTION(BlueprintCallable, Category = "Weapon")
    virtual void CancelReload();

    UFUNCTION(BlueprintCallable, Category = "Weapon")
    virtual void StopFire();

    UFUNCTION(BlueprintCallable, Category = "Weapon")
    virtual void StartFire();

protected:

    /** Protected Weapon Actions */

    /** Handles replication of firing, calls OnFire. Rather than overriding this, one should override OnFire */
    virtual void Fire();
    UFUNCTION(Server, Reliable, WithValidation)
     void ServerFire();

    /** Primary override for individual firing behaviors of weapons */
    UFUNCTION(BlueprintImplementableEvent, Category = "Firing")
    void OnFire();

    UFUNCTION(Server, Reliable, WithValidation)
    void ServerReload();

    UFUNCTION(Server, Reliable, WithValidation)
    void ServerCancelReload();


    /** General Weapon Data */
    
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    USkeletalMeshComponent* MeshComp = nullptr;

    /** If the weapon has less than this amount in its clip, HasAmmoRequiredToFire will fail */
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Weapon")
    int32 AmmoRequiredToFire = 1;

    /** The ammo type which this weapon uses */
    UPROPERTY(EditDefaultsOnly, Category = "Weapon")
    EAmmoType AmmoType = EAmmoType::NONE;

    /** The damage type that this weapon causes */
    UPROPERTY(EditDefaultsOnly, Category = "Weapon")
    TSubclassOf<UDamageType> DamageType;

    /** Sound played during reload */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Weapon")
	USoundCue* ReloadSound = nullptr;

    /** Specifies the socket on @MeshComp where things like muzzlle flashes should play */
    UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Weapon")
    FName MuzzleSocketName = "MuzzleSocket";

    /** Effect to be played on fire at @MuzzleSocketName's location */
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Weapon")
    UParticleSystem* MuzzleEffect = nullptr;

    /** The sound a weapon makes when fired */
    UPROPERTY(EditDefaultsOnly, Category = "Weapon")
    USoundCue* FireSound = nullptr;

    /** The image used to represent this weapon */
    UPROPERTY(EditDefaultsOnly, Category = "Weapon")
    UTexture2D* WeaponIcon = nullptr;

    /** The cooldown period between firing events */
    UPROPERTY(EditDefaultsOnly, Category = "Weapon")
	float TimeBetweenShots = 0.5f;

    /** The maximum amount of ammo carried in a clip */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Weapon")
	uint8 ClipSize = 20;

    /** The current amount of ammo in our clip, if this number is less than AmmoRequiredToFire, HasAmmoRequiredToFire will fail */
    UPROPERTY(Replicated)
    uint8 AmmoInClip = ClipSize;

    /** Widget reference displayed when this weapon hits something */
	USHitIndicatorWidget* HitIndicatorWidget = nullptr;
	UPROPERTY(EditDefaultsOnly, Category = "Weapon")
	TSubclassOf<USHitIndicatorWidget> HitIndicatorWidgetClass;

    /** Instance variables */

    /** Timer used repeat firing events (eg when mouse is held down) */
    FTimerHandle TimerHandle_TimeBetweenShots;

    /** The last time this weapon has fired */
    UPROPERTY(BlueprintReadWrite, Category = "Weapon")
    float LastFireTime = -9999999;

    /** The timer tracking how much time is remaining for a successful reload operation */
	FTimerHandle TimerHandle_ReloadTimer;

    

};
