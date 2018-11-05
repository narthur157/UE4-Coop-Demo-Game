 // Fill out your copyright notice in the Description page of Project Settings.

#include "SWeaponComponent.h"
#include "Engine/World.h"
#include "Net/UnrealNetwork.h"
#include "Blueprint/UserWidget.h"
#include "CoopGame.h"
#include "SWeaponWidget.h"
#include "SWeapon.h"

// Sets default values for this component's properties
USWeaponComponent::USWeaponComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;
    SetIsReplicated(true);
	// ...
}

// Called when the game starts
void USWeaponComponent::BeginPlay()
{
	Super::BeginPlay();

    SpawnDefaultWeaponInventory();
}

void USWeaponComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);

    DOREPLIFETIME(USWeaponComponent, AmmoInventory);
    DOREPLIFETIME(USWeaponComponent, CurrentWeapon);
    DOREPLIFETIME(USWeaponComponent, WeaponInventory);
}

void USWeaponComponent::SpawnDefaultWeaponInventory()
{
    // We want the server to own these actors
    if (GetOwnerRole() < ROLE_Authority)
    {
        return;
    }
    else
    {
        FActorSpawnParameters SpawnParams;
        SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
        SpawnParams.Owner = GetOwner();

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
        
        if (!IsRunningDedicatedServer())
        {
            OnRep_WeaponInventory();
        }
    }   
}

// Only want to setcurrentweapon on the server
void USWeaponComponent::EquipWeapon(ASWeapon* Weapon)
{
    // Only run on server
    if (GetOwnerRole() < ROLE_Authority)
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
void USWeaponComponent::SetCurrentWeapon(ASWeapon* Weapon)
{
    if (Weapon)
    {
        Weapon->SetActorHiddenInGame(false);
        CurrentWeapon = Weapon;

        USkeletalMeshComponent* OwningMesh = GetOwner()->FindComponentByClass<USkeletalMeshComponent>();
        CurrentWeapon->AttachToComponent(OwningMesh, FAttachmentTransformRules::SnapToTargetNotIncludingScale, WeaponSocket);
    }
}

void USWeaponComponent::OnRep_CurrentWeapon()
{
    SetCurrentWeapon(CurrentWeapon);
}

void USWeaponComponent::OnRep_WeaponInventory()
{
    APawn* Owner = Cast<APawn>(GetOwner());
    APlayerController* OwnerController = Cast<APlayerController>(Owner->GetController());
    if (Owner && OwnerController)
    {
        TRACE("WeaponInventoryReplicated: %d / %d", WeaponInventory.Num(), DefaultWeapons.Num());

        if (!WeaponsWidget)
        {
            WeaponsWidget = CreateWidget<USWeaponWidget>(OwnerController, WeaponsWidgetClass);
            WeaponsWidget->InitializeWeaponWidget(this);
            WeaponsWidget->AddToViewport();
        }
        WeaponsWidget->RefreshAmmo();
        WeaponsWidget->RefreshWeapons();
    }
}

void USWeaponComponent::ServerEquipWeapon_Implementation(ASWeapon* Weapon)
{
    EquipWeapon(Weapon);
}

bool USWeaponComponent::ServerEquipWeapon_Validate(ASWeapon* Weapon)
{
    return true;
}

void USWeaponComponent::ChangeWeapon()
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
        StopFire();
        int32 CurrentWeaponIndex = WeaponInventory.Find(CurrentWeapon);
        if (CurrentWeaponIndex == WeaponInventory.Num() - 1)
        {
            EquipWeapon(WeaponInventory[0]);
        }
        else if (CurrentWeaponIndex != INDEX_NONE)
        {
            CurrentWeaponIndex++;
            EquipWeapon(WeaponInventory[CurrentWeaponIndex]);
        }
    }
}

void USWeaponComponent::StartFire()
{
    if (CurrentWeapon)
    {
        CurrentWeapon->StartFire();
    }
}

void USWeaponComponent::StopFire()
{
    if (CurrentWeapon)
    {
        CurrentWeapon->StopFire();
    }
}