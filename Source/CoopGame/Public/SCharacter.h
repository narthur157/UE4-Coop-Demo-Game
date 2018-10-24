// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "SCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;
class ASWeapon;

UCLASS()
class COOPGAME_API ASCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ASCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

    void MoveForward(float RelativeSpeed);
    void MoveRight(float RelativeSpeed);

    void BeginCrouch();
    void EndCrouch();

    void BeginZoom();
    void EndZoom();

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
    UCameraComponent* CameraComp = nullptr;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "SpringArmComponent")
    USpringArmComponent* SpringArmComp;

    UPROPERTY(EditDefaultsOnly, Category = "Player")
    float ZoomedFOV;

    UPROPERTY(EditDefaultsOnly, Category = "Player", meta = (ClampMin = 0.0, ClampMax = 100))
    float ZoomInterpSpeed;


    bool bWantsToZoom;

    float DefaultFOV;

    void StartFire();

    void StopFire();

    UPROPERTY(VisibleDefaultsOnly, Category = "Player")
    FName WeaponSocket = "WeaponSocket";

    UPROPERTY(EditDefaultsOnly, Category = "Weapon")
    TArray<TSubclassOf<ASWeapon>> DefaultWeapons;
   
    ASWeapon* CurrentWeapon;

    int32 CurrentWeaponIndex = 0;

    void EquipWeapon(int32 Index);

    //TArray<ASWeapon*> WeaponInventory;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

    virtual FVector GetPawnViewLocation() const override;

    void ChangeWeapon();
	
};
