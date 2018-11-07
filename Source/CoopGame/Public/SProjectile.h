// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
// TODO: Why wont it let me forward declare the FProjectileWeaponData struct?
#include "SProjectileWeapon.h"
#include "SProjectile.generated.h"

class UProjectileMovementComponent;
class USphereComponent;
class UStaticMeshComponent;
class USoundCue;

UCLASS()
class COOPGAME_API ASProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASProjectile();

protected:
    UPROPERTY(VisibleAnywhere, Category = "Components")
    USphereComponent* CollisionComp = nullptr;

    UPROPERTY(VisibleAnywhere, Category = "Components")
    UProjectileMovementComponent* MovementComp = nullptr;

    UPROPERTY(VisibleAnywhere, Category = "Components")
    UStaticMeshComponent* MeshComp = nullptr;

	UPROPERTY(EditDefaultsOnly, Category = "Weapon")
	float ProjectileSpeed;

    UPROPERTY(EditDefaultsOnly, Category = "Weapon")
    UParticleSystem* ExplosionEffect = nullptr;

    UPROPERTY(EditDefaultsOnly, Category = "Weapon")
    USoundCue* ExplosionSoundEffect = nullptr;

    UFUNCTION(BlueprintCallable, Category = "Weapon")
    virtual void Explode();

    UFUNCTION()
    virtual void OnProjectileHit(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit);

    UPROPERTY(ReplicatedUsing = OnRep_Exploded)
    bool bExploded = false;

    UFUNCTION()
    void OnRep_Exploded();

    FTimerHandle FuseTimerHandle;
    FProjectileWeaponData WeaponData;

    bool bWasInitialized = false;

public:	
    UFUNCTION()
    virtual void OnProjectileExpire();
	
	UFUNCTION()
    virtual void Launch();
	
    virtual void Initialize(const FProjectileWeaponData& Data);
};
