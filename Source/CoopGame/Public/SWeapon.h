// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SWeapon.generated.h"

class UDamageType;
class UParticleSystem;

UCLASS()
class COOPGAME_API ASWeapon : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASWeapon();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    USkeletalMeshComponent* MeshComp = nullptr;

    UPROPERTY(EditDefaultsOnly, Category = "Weapon")
    TSubclassOf<UDamageType> DamageType;

    UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Weapon")
    FName MuzzleSocketName = "MuzzleSocket";

    UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Weapon")
    FName TracerTargetName = "Target";

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Weapon")
    UParticleSystem* MuzzleEffect = nullptr;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Weapon")
    UParticleSystem* ImpactEffect = nullptr;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Weapon")
    UParticleSystem* TracerEffect = nullptr;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

    UFUNCTION(BlueprintCallable, Category = "Weapon")
    virtual void Fire();
	
};
