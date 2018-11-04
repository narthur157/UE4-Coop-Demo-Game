// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SWeapon.generated.h"

class UDamageType;
class UCameraShake;
class UParticleSystem;
class USoundCue;
class UImage;

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
	// Sets default values for this actor's properties
	ASWeapon();

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
    TSubclassOf<UCameraShake> FireCamShake;

    UPROPERTY(EditDefaultsOnly, Category = "Weapon")
    USoundCue* FireSound = nullptr;

    UPROPERTY(EditDefaultsOnly, Category = "Weapon")
    UImage* WeaponIcon = nullptr;

    UPROPERTY(EditDefaultsOnly, Category = "Weapon")
    float TimeBetweenShots = 0.0f;

    UPROPERTY(EditDefaultsOnly, Category = "WeaponData")
    EAmmoType AmmoType = EAmmoType::NONE;

    // Instance variables
    FTimerHandle TimerHandle_TimeBetweenShots;

    float LastFireTime = -9999999;

    // Functionality
    virtual void Fire() {}

    UFUNCTION(Server, Reliable, WithValidation)
    void ServerFire();

 


public:	

    UFUNCTION(BlueprintCallable, Category = "Weapon")
    virtual void StartFire();

    UFUNCTION(BlueprintCallable, Category = "Weapon")
    virtual void StopFire();	
   
};
