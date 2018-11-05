// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SWeaponComponent.generated.h"


class ASWeapon;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class COOPGAME_API USWeaponComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	USWeaponComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
    UPROPERTY(VisibleDefaultsOnly, Category = "Player")
        FName WeaponSocket = "WeaponSocket";
    // Server only function
    void SpawnDefaultWeaponInventory();

    UPROPERTY(EditDefaultsOnly, Category = "Weapon")
    TArray<TSubclassOf<ASWeapon>> DefaultWeapons;

    UPROPERTY(Replicated)
     TArray<ASWeapon*> WeaponInventory;

    UPROPERTY(BlueprintReadonly, ReplicatedUsing = OnRep_CurrentWeapon)
     ASWeapon* CurrentWeapon;

    UFUNCTION()
        void OnRep_CurrentWeapon();

    // Server only
    void EquipWeapon(ASWeapon* Weapon);

    UFUNCTION()
        void SetCurrentWeapon(ASWeapon* NewWeapon);

    UFUNCTION(Server, Reliable, WithValidation)
        void ServerEquipWeapon(ASWeapon* Weapon);


    void ChangeWeapon();


    UFUNCTION(BlueprintCallable, Category = "PlayerWeapon")
        void StartFire();

    UFUNCTION(BlueprintCallable, Category = "PlayerWeapon")
        void StopFire();
	
};
