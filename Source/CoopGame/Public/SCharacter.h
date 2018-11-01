// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "DamageDealer.h"
#include "SCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;
class ASWeapon;
class UHealthComponent;

UCLASS()
class COOPGAME_API ASCharacter : public ACharacter, public IDamageDealer
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ASCharacter();

protected:
    // Called when the game starts or when spawned
	virtual void BeginPlay() override;

    UPROPERTY(Replicated, BlueprintReadOnly, Category = "Player")
    bool bWantsToSprint = false;

    float SprintSpeed = 200.0f;

    void MoveForward(float RelativeSpeed);
    void MoveRight(float RelativeSpeed);

    void BeginCrouch();
    void EndCrouch();

    void BeginZoom();
    void EndZoom();

    void BeginSprint();
    void EndSprint();

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
    UCameraComponent* CameraComp = nullptr;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "SpringArmComponent")
    USpringArmComponent* SpringArmComp;

    UPROPERTY(EditDefaultsOnly, Category = "Player")
    float ZoomedFOV;

    UPROPERTY(EditDefaultsOnly, Category = "Player", meta = (ClampMin = 0.0, ClampMax = 100))
    float ZoomInterpSpeed;

    float DefaultFOV;

    UPROPERTY(VisibleDefaultsOnly, Category = "Player")
    FName WeaponSocket = "WeaponSocket";

    UPROPERTY(EditDefaultsOnly, Category = "Weapon")
    TArray<TSubclassOf<ASWeapon>> DefaultWeapons;
   
    UPROPERTY(Replicated)
    TArray<ASWeapon*> WeaponInventory;

    UPROPERTY(ReplicatedUsing=OnRep_CurrentWeapon)
    ASWeapon* CurrentWeapon;

    UFUNCTION()
    void OnRep_CurrentWeapon();

    // Server only
    void EquipWeapon(ASWeapon* Weapon);

    UFUNCTION()
    void SetCurrentWeapon(ASWeapon* NewWeapon);

    UFUNCTION(Server, Reliable, WithValidation)
    void ServerEquipWeapon(ASWeapon* Weapon);

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly,  Category = "Health")
    USHealthComponent* HealthComp = nullptr;

    UFUNCTION()
    void OnHealthChanged(USHealthComponent* ChangedHealthComp, float Health, float HealthDelta, const class UDamageType* DamageType, class AController* InstigatedBy, AActor* DamageCauser);

    UPROPERTY(Replicated, BlueprintReadOnly, Category = "Player")
    bool bDied = false;

    // Server only function
    void SpawnDefaultWeaponInventory();

    UPROPERTY(BlueprintReadWrite, Category = "Power")
    float DamageModifier = 1.0f;


public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "PlayerWeapon")
	bool bWantsToZoom;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

    virtual FVector GetPawnViewLocation() const override;

    void ChangeWeapon();
	
    // IDamageDealer
    virtual float GetDamageModifier() override { return DamageModifier; }

    UFUNCTION(BlueprintCallable, Category = "PlayerWeapon")
        void StartFire();

    UFUNCTION(BlueprintCallable, Category = "PlayerWeapon")
        void StopFire();
};
