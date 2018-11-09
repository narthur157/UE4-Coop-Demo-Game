#include "SCharacter.h"
#include "Camera/CameraComponent.h"
#include "SWeapon.h"
#include "Engine/World.h"
#include "GameFramework/PawnMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/CapsuleComponent.h"
#include "SHealthComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "UnrealNetwork.h"
#include "SWeaponComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "UnrealNames.h"
#include "GameFramework/PlayerState.h"

ASCharacter::ASCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

    SpringArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
    SpringArmComp->SetupAttachment(RootComponent);
    SpringArmComp->bUsePawnControlRotation = true;

    HealthComp = CreateDefaultSubobject<USHealthComponent>(TEXT("HealthComponent"));
    WeaponComp = CreateDefaultSubobject<USWeaponComponent>(TEXT("WeaponComponent"));

	SetReplicates(true);

    CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
    CameraComp->SetupAttachment(SpringArmComp);

    GetMovementComponent()->GetNavAgentPropertiesRef().bCanCrouch = true;

    ZoomedFOV = 65.0;
    ZoomInterpSpeed = 20.0f;
}

void ASCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    PlayerInputComponent->BindAxis("MoveForward", this, &ASCharacter::MoveForward);
    PlayerInputComponent->BindAxis("MoveRight", this, &ASCharacter::MoveRight);
    PlayerInputComponent->BindAxis("LookUp", this, &ASCharacter::AddControllerPitchInput);
    PlayerInputComponent->BindAxis("Turn", this, &ASCharacter::AddControllerYawInput);

    PlayerInputComponent->BindAction("Sprint", IE_Pressed, this, &ASCharacter::BeginSprint);
    PlayerInputComponent->BindAction("Sprint", IE_Released, this, &ASCharacter::EndSprint);
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

    DOREPLIFETIME(ASCharacter, bDied);
	DOREPLIFETIME_CONDITION(ASCharacter, bWantsToZoom, COND_SkipOwner);
}

void ASCharacter::BeginPlay()
{
	Super::BeginPlay();
    DefaultFOV = CameraComp->FieldOfView;
    HealthComp->OnHealthChanged.AddDynamic(this, &ASCharacter::OnHealthChanged);
}

void ASCharacter::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    float TargetFOV = bWantsToZoom ? ZoomedFOV : DefaultFOV;
    float NewFOV = FMath::FInterpTo(CameraComp->FieldOfView, TargetFOV, DeltaTime, ZoomInterpSpeed);

	if (Role == ROLE_AutonomousProxy)
	{
		ServerSetZoom(bWantsToZoom);
	}

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

// TODO: Server functions so this works in multiplayer
void ASCharacter::BeginSprint()
{
   // bWantsToSprint = true;
    //GetCharacterMovement()->MaxWalkSpeed += SprintSpeed;

}

void ASCharacter::EndSprint()
{
    //bWantsToSprint = false;
    //GetCharacterMovement()->MaxWalkSpeed -= SprintSpeed;
}

uint8 ASCharacter::GetTeamID()
{
    return HealthComp->TeamNum;
}

void ASCharacter::StartFire()
{
    if (WeaponComp)
    {
        WeaponComp->StartFire();
    }
}

void ASCharacter::StopFire()
{
    if (WeaponComp)
    {
        WeaponComp->StopFire();
    }
}

FVector ASCharacter::GetPawnViewLocation() const
{
	return CameraComp ? CameraComp->GetComponentLocation() : Super::GetPawnViewLocation();
}

void ASCharacter::ChangeWeapon()
{
    if (WeaponComp)
    {
        WeaponComp->ChangeWeapon();
    }
}

void ASCharacter::DisableInput(APlayerController* PlayerController)
{
	Super::DisableInput(PlayerController);

	StopFire();
}

void ASCharacter::OnHealthChanged(USHealthComponent * ChangedHealthComp, float Health, float HealthDelta, const UDamageType * DamageType, AController * InstigatedBy, AActor * DamageCauser)
{
    if (Health <= 0.0f && !bDied)
    {
        bDied = true;
        StopFire();

        // Die
        GetMovementComponent()->StopMovementImmediately();
		
		APlayerController* PC = Cast<APlayerController>(GetController());

		if (PC)
		{
			PC->PlayerState->bIsSpectator = true;
			PC->ChangeState(NAME_Spectating);
			PC->ClientGotoState(NAME_Spectating);
		}

        GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
        DetachFromControllerPendingDestroy();
		PrimaryActorTick.bCanEverTick = false;
        SetLifeSpan(10.0f);
    }
}

void ASCharacter::ServerSetZoom_Implementation(bool bZoom)
{
	bWantsToZoom = bZoom;
}

bool ASCharacter::ServerSetZoom_Validate(bool bZoom)
{
	return true;
}

