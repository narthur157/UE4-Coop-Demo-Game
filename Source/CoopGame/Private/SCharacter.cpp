// Fill out your copyright notice in the Description page of Project Settings.

#include "SCharacter.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/PawnMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"



// Sets default values
ASCharacter::ASCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


    SpringArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
    SpringArmComp->SetupAttachment(RootComponent);
    SpringArmComp->bUsePawnControlRotation = true;

    CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
    CameraComp->SetupAttachment(SpringArmComp);

    GetMovementComponent()->GetNavAgentPropertiesRef().bCanCrouch = true;

    
}

// Called when the game starts or when spawned
void ASCharacter::BeginPlay()
{
	Super::BeginPlay();

	
}

void ASCharacter::MoveForward(float RelativeSpeed)
{
    AddMovementInput(GetActorForwardVector() * RelativeSpeed);
}

void ASCharacter::MoveRight(float RelativeSpeed)
{
    AddMovementInput(GetActorRightVector() * RelativeSpeed);
}

void ASCharacter::BeginCrouch()
{
    Crouch();
}

void ASCharacter::EndCrouch()
{
    UnCrouch();
}

// Called every frame
void ASCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ASCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

    PlayerInputComponent->BindAxis("MoveForward", this, &ASCharacter::MoveForward);
    PlayerInputComponent->BindAxis("MoveRight", this, &ASCharacter::MoveRight);
    PlayerInputComponent->BindAxis("LookUp", this, &ASCharacter::AddControllerPitchInput);
    PlayerInputComponent->BindAxis("Turn", this, &ASCharacter::AddControllerYawInput);

    PlayerInputComponent->BindAction("Crouch", IE_Pressed, this, &ASCharacter::BeginCrouch);
    PlayerInputComponent->BindAction("Crouch", IE_Released, this, &ASCharacter::EndCrouch);
    PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ASCharacter::Jump);


}

FVector ASCharacter::GetPawnViewLocation() const
{
    if (CameraComp)
    {
        return CameraComp->GetComponentLocation();
    }
    return Super::GetPawnViewLocation();
}

