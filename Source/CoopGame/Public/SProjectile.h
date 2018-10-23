// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"
#include "SProjectile.generated.h"

class UProjectileMovementComponent;
class USphereComponent;
class UDamageType;

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
    TArray< AActor* > IgnoredActors;

    UPROPERTY(EditDefaultsOnly, Category = "Weapon")
    TSubclassOf<UDamageType> DamageType;

    UPROPERTY(EditDefaultsOnly, Category = "Weapon")
    UParticleSystem* ExplosionEffect = nullptr;

    UPROPERTY(EditDefaultsOnly, Category = "Components")
    float FuseDuration = 0.0f;

    UPROPERTY(EditDefaultsOnly, Category = "Components")
    float DamageRadius = 0.0f;

    UPROPERTY(EditDefaultsOnly, Category = "Weapon")
    float Damage = 0.0f;

    UPROPERTY(EditDefaultsOnly, Category = "Weapon")
    bool bExplodeOnContact;

    UFUNCTION(BlueprintCallable, Category = "Weapon")
    void Explode();

    void OnFuseExpire();
    UFUNCTION()
    void OnProjectileHit(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit);


public:	
    virtual void Launch(float LaunchSpeed);
	
};
