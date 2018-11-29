#include "SWeaponComponent.h"
#include "Net/UnrealNetwork.h"
#include "Blueprint/UserWidget.h"
#include "CoopGame.h"
#include "SWeaponWidget.h"
#include "SWeapon.h"
#include "Components/SkeletalMeshComponent.h"
#include "SCharacter.h"
#include "TimerManager.h"

USWeaponComponent::USWeaponComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
    SetIsReplicated(true);
}

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
	DOREPLIFETIME(USWeaponComponent, bCanFire);
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

	bCanFire = true;
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

		if (Weapon->GetAmmoInClip() <= 0)
		{
			Weapon->Reload();
		}
    }
}

void USWeaponComponent::OnRep_CurrentWeapon()
{
    SetCurrentWeapon(CurrentWeapon);
}

void USWeaponComponent::OnRep_WeaponInventory()
{
	for (ASWeapon* W : WeaponInventory)
	{
		if (!W)
		{
			return;
		}
	}

	if (WeaponWidget)
	{
		WeaponWidget->RefreshWeapons();
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
        UE_LOG(LogTemp, Log, TEXT("Failed: WeaponInventoryEmpty"));
        return;
    }

	ASCharacter* MyCharacter = Cast<ASCharacter>(GetOwner());

	if (MyCharacter)
	{
		MyCharacter->OnWeaponChangeDelegate.Broadcast();
	}

	bCanFire = false;

	FTimerHandle Handle;
	GetWorld()->GetTimerManager().SetTimer(Handle, [&]() {
		if (!CurrentWeapon)
		{
			UE_LOG(LogTemp, Log, TEXT("No Current Weapon, Equipping First"));
			EquipWeapon(WeaponInventory[0]);
		}
		else
		{
			UE_LOG(LogTemp, Log, TEXT("WeaponSwap Success"));
			GetCurrentWeapon()->CancelReload();
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
	}, ChangeWeaponDelay, false);
}

void USWeaponComponent::StartFire()
{
    if (CurrentWeapon && bCanFire)
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

USWeaponWidget* USWeaponComponent::DrawWeaponWidget(APlayerController* OwningController, int32 NumberWeaponSlots)
{
    if (OwningController)
    {
        WeaponWidget = CreateWidget<USWeaponWidget>(OwningController,WeaponsWidgetClass);
    
		if (WeaponWidget)
		{
			WeaponWidget->InitializeWeaponWidget(this, NumberWeaponSlots);
			return WeaponWidget;
		}
    }

	UE_LOG(LogTemp, Error, TEXT("DrawWeaponWidget called without owning controller, this is confusing"));
	return nullptr;
}