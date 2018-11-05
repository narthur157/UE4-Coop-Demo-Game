// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SWeaponComponent.generated.h"

class USWeaponWidget;
class ASWeapon;
class UImage;
enum class EAmmoType : uint8;

USTRUCT(BlueprintType)
struct FWeaponAmmoInventoryItem
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
    EAmmoType AmmoType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
    UTexture2D* AmmoImage;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
    int32 CurrentStackSize = 0;

};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class COOPGAME_API USWeaponComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	USWeaponComponent();

    UFUNCTION(BlueprintCallable, Category = "WeaponData")
    ASWeapon* GetCurrentWeapon() { return CurrentWeapon; }

    UFUNCTION(BlueprintCallable, Category = "WeaponData")
    TArray<ASWeapon*> GetWeaponInventory() { return WeaponInventory; }

    UFUNCTION(BlueprintCallable, Category = "WeaponData")
    TArray<FWeaponAmmoInventoryItem> GetAmmoInventory() { return AmmoInventory; }

    UFUNCTION(BlueprintCallable, Category = "WeaponData")
    float GetAmmoInCurrentWeaponClip() { return CurrentWeapon ? 100.0f : 0.0f; };

    UFUNCTION(BlueprintCallable, Category = "PlayerWeapon")
    void StartFire();

    UFUNCTION(BlueprintCallable, Category = "PlayerWeapon")
    void StopFire();

    void ChangeWeapon();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

    UPROPERTY(VisibleDefaultsOnly, Category = "Player")
    FName WeaponSocket = "WeaponSocket";

    UPROPERTY(EditDefaultsOnly, Category = "Weapon")
    TArray<TSubclassOf<ASWeapon>> DefaultWeapons;

    UPROPERTY(ReplicatedUsing = OnRep_WeaponInventory)
    TArray<ASWeapon*> WeaponInventory;

    UPROPERTY(EditDefaultsOnly, Replicated, Category = "Weapon")
    TArray<FWeaponAmmoInventoryItem> AmmoInventory;

    UPROPERTY(BlueprintReadonly, ReplicatedUsing = OnRep_CurrentWeapon)
     ASWeapon* CurrentWeapon;


    UPROPERTY(EditDefaultsOnly, Category = "Weapon")
    TSubclassOf<USWeaponWidget> WeaponsWidgetClass = nullptr;

    USWeaponWidget* WeaponsWidget = nullptr;

    /** [Server] **/
    void SpawnDefaultWeaponInventory();

    /** [Server] **/
    void EquipWeapon(ASWeapon* Weapon);

    UFUNCTION(Server, Reliable, WithValidation)
    void ServerEquipWeapon(ASWeapon* Weapon);

    UFUNCTION()
    void SetCurrentWeapon(ASWeapon* NewWeapon);

    UFUNCTION()
    void OnRep_CurrentWeapon();

    UFUNCTION()
    void OnRep_WeaponInventory();

};
