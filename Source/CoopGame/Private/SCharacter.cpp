// Fill out your copyright notice in the Description page of Project Settings.

#include "SCharacter.h"
#include "Camera/CameraComponent.h"
#include "SWeapon.h"
#include "Engine/World.h"
#include "GameFramework/PawnMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/CapsuleComponent.h"
#include "SHealthComponent.h"
#include "UnrealNetwork.h"


// Sets default values
ASCharacter::ASCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


    SpringArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
    SpringArmComp->SetupAttachment(RootComponent);
    SpringArmComp->bUsePawnControlRotation = true;

    HealthComp = CreateDefaultSubobject<USHealthComponent>(TEXT("HealthComponent"));

    CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
    CameraComp->SetupAttachment(SpringArmComp);

    GetMovementComponent()->GetNavAgentPropertiesRef().bCanCrouch = true;

    ZoomedFOV = 65.0;
    ZoomInterpSpeed = 20.0f;
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

    PlayerInputComponent->BindAction("WeaponSwap", IE_Pressed, this, &ASCharacter::ChangeWeapon);

}

void ASCharacter::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);

    DOREPLIFETIME(ASCharacter, CurrentWeapon);
    DOREPLIFETIME(ASCharacter, WeaponInventory);
    DOREPLIFETIME(ASCharacter, bDied);
}

// Called when the game starts or when spawned
void ASCharacter::BeginPlay()
{
	Super::BeginPlay();
    DefaultFOV = CameraComp->FieldOfView;

    HealthComp->OnHealthChanged.AddDynamic(this, &ASCharacter::OnHealthChanged);

    SpawnDefaultWeaponInventory();
}

// Called every frame
void ASCharacter::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    float TargetFOV = bWantsToZoom ? ZoomedFOV : DefaultFOV;
    float NewFOV = FMath::FInterpTo(CameraComp->FieldOfView, TargetFOV, DeltaTime, ZoomInterpSpeed);

    CameraComp->SetFieldOfView(NewFOV);
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
    if (CurrentWeapon)
    {
        CurrentWeapon->StartFire();

    }
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

void ASCharacter::SpawnDefaultWeaponInventory()
{
    // We want the server to own these actors
    if (Role < ROLE_Authority)
    {
        return;
    }
    else
    {
        FActorSpawnParameters SpawnParams;
        SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
        SpawnParams.Owner = this;

        for (int i = 0; i < DefaultWeapons.Num(); i++)
        {
            ASWeapon* NewWeapon = GetWorld()->SpawnActor<ASWeapon>(DefaultWeapons[i], SpawnParams);
            WeaponInventory.Add(NewWeapon);
            NewWeapon->SetActorHiddenInGame(true);
        }

        if (WeaponInventory.Num() > 0)
        {
            EquipWeapon(WeaponInventory[0]);
        }
    }
}

// Only want to setcurrentweapon on the server
void ASCharacter::EquipWeapon(ASWeapon* Weapon)
{
    // Only run on server
    if (Role < ROLE_Authority)
    {
        ServerEquipWeapon(Weapon);
        return;
    }
    
    if (CurrentWeapon)
    {
        CurrentWeapon->SetActorHiddenInGame(true);
    }
    SetCurrentWeapon(Weapon);
}

// Changes weapon
void ASCharacter::SetCurrentWeapon(ASWeapon* Weapon)
{
    if (Weapon)
    {
        Weapon->SetActorHiddenInGame(false);
        CurrentWeapon = Weapon;
        CurrentWeapon->AttachToComponent(GetMesh(), FAttachmentTransformRules::SnapToTargetNotIncludingScale, WeaponSocket);
    }
}


void ASCharacter::OnRep_CurrentWeapon()
{
    SetCurrentWeapon(CurrentWeapon);
}

void ASCharacter::ServerEquipWeapon_Implementation(ASWeapon* Weapon)
{
    EquipWeapon(Weapon);
}

bool ASCharacter::ServerEquipWeapon_Validate(ASWeapon* Weapon)
{
    return true;
}


void ASCharacter::ChangeWeapon()
{
    if (WeaponInventory.Num() == 0)
    {
        UE_LOG(LogTemp, Warning, TEXT("Failed: WeaponInventoryEmpty"));
        return;
    }

    if (!CurrentWeapon)
    {
        UE_LOG(LogTemp, Warning, TEXT("No Current Weapon, Equipping First"));
        EquipWeapon(WeaponInventory[0]);
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("WeaponSwap Success"));
        int32 CurrentWeaponIndex = WeaponInventory.Find(CurrentWeapon);
        if (CurrentWeaponIndex == WeaponInventory.Num() - 1)
        {
            EquipWeapon(WeaponInventory[0]);
        }
        else if(CurrentWeaponIndex != INDEX_NONE)
        {
            CurrentWeaponIndex++;
            EquipWeapon(WeaponInventory[CurrentWeaponIndex]);
        }
    }
}


void ASCharacter::OnHealthChanged(USHealthComponent * ChangedHealthComp, float Health, float HealthDelta, const UDamageType * DamageType, AController * InstigatedBy, AActor * DamageCauser)
{
    if (Health <= 0.0f && !bDied)
    {
        bDied = true;
        // Die

        GetMovementComponent()->StopMovementImmediately();
        GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
        DetachFromControllerPendingDestroy();
        SetLifeSpan(10.0f);

    }
}

