// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "DamageDealer.h"
#include "ITeamMember.h"
#include "SCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;
class USWeaponComponent;
class UHealthComponent;


UCLASS()
class COOPGAME_API ASCharacter : public ACharacter, public IDamageDealer, public ITeamMember
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ASCharacter();

protected:
    // Called when the game starts or when spawned
	virtual void BeginPlay() override;

    // Movement functions
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
    USpringArmComponent* SpringArmComp = nullptr;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Weapons")
    USWeaponComponent* WeaponComp = nullptr;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Health")
    USHealthComponent* HealthComp = nullptr;

    UPROPERTY(EditDefaultsOnly, Category = "Player")
    float ZoomedFOV;

    UPROPERTY(EditDefaultsOnly, Category = "Player", meta = (ClampMin = 0.0, ClampMax = 100))
    float ZoomInterpSpeed;

    float DefaultFOV;

    UPROPERTY(BlueprintReadWrite, Category = "Power")
    float DamageModifier = 1.0f;

    UFUNCTION()
    void OnHealthChanged(USHealthComponent* ChangedHealthComp, float Health, float HealthDelta, const class UDamageType* DamageType, class AController* InstigatedBy, AActor* DamageCauser);

    UPROPERTY(Replicated, BlueprintReadOnly, Category = "Player")
    bool bDied = false;

	UFUNCTION(Server, Unreliable, WithValidation)
	void ServerSetZoom(bool bZoom);

public:
	UPROPERTY(Replicated, VisibleAnywhere, BlueprintReadWrite, Category = "PlayerWeapon")
	bool bWantsToZoom;

	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

    virtual FVector GetPawnViewLocation() const override;

    /** Implements IDamageDealer */
    virtual float GetDamageModifier() override { return DamageModifier; }

    /** Implements ITeamMember */ 
    virtual uint8 GetTeamID() override;

    /**  Weapon operations, calling these from character for now because we might want to play animations/whatever
     *	 before firing/on changing weapons
	*/
    UFUNCTION(BlueprintCallable, Category = "PlayerWeapon")
    void StartFire();

    UFUNCTION(BlueprintCallable, Category = "PlayerWeapon")
    void StopFire();

    void ChangeWeapon();

	/* Override so that we can stop firing when disabled */
	virtual void DisableInput(APlayerController* PlayerController) override;
};
