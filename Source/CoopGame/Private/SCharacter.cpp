// Fill out your copyright notice in the Description page of Project Settings.

#include "SCharacter.h"
#include "Camera/CameraComponent.h"
#include "SWeapon.h"
#include "Engine/World.h"
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

    ZoomedFOV = 65.0;
    ZoomInterpSpeed = 20.0f;
}

// Called when the game starts or when spawned
void ASCharacter::BeginPlay()
{
	Super::BeginPlay();
    DefaultFOV = CameraComp->FieldOfView;

    // Spawn a default weapon
    FActorSpawnParameters SpawnParams;
    SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
    CurrentWeapon = GetWorld()->SpawnActor<ASWeapon>(DefaultWeapon, FVector::ZeroVector, FRotator::ZeroRotator, SpawnParams);
    if (CurrentWeapon)
    {
        CurrentWeapon->SetOwner(this);
        CurrentWeapon->AttachToComponent(GetMesh(), FAttachmentTransformRules::SnapToTargetNotIncludingScale, "WeaponSocket");
    }
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

void ASCharacter::BeginZoom()
{
    bWantsToZoom = true;
}

void ASCharacter::EndZoom()
{
    bWantsToZoom = false;
}

void ASCharacter::StartFire()
{
    CurrentWeapon->StartFire();
}

// Called every frame
void ASCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
    
    float TargetFOV = bWantsToZoom ? ZoomedFOV : DefaultFOV;
    float NewFOV = FMath::FInterpTo(CameraComp->FieldOfView, TargetFOV, DeltaTime, ZoomInterpSpeed);

    CameraComp->SetFieldOfView(NewFOV);
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
    PlayerInputComponent->BindAction("Zoom", IE_Pressed, this, &ASCharacter::BeginZoom);
    PlayerInputComponent->BindAction("Zoom", IE_Released, this, &ASCharacter::EndZoom);

    PlayerInputComponent->BindAction("Fire", IE_Pressed, this, &ASCharacter::StartFire);
    PlayerInputComponent->BindAction("Fire", IE_Released, this, &ASCharacter::StopFire);

}

void ASCharacter::StopFire()
{
    if (CurrentWeapon)
    {
        CurrentWeapon->StopFire();
    }
}

FVector ASCharacter::GetPawnViewLocation() const
{
    if (CameraComp)
    {
        return CameraComp->GetComponentLocation();
    }
    return Super::GetPawnViewLocation();
}

