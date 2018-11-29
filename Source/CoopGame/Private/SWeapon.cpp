#include "SWeapon.h"
#include "DrawDebugHelpers.h"
#include "Components/SkeletalMeshComponent.h"
#include "Net/UnrealNetwork.h"
#include "SHealthComponent.h"
#include "UserWidget.h"
#include "Gameplay/GameplayComponents/TeamComponent.h"
#include "SHitIndicatorWidget.h"
#include "TimerManager.h"
#include "SCharacter.h"

ASWeapon::ASWeapon()
{
    MeshComp = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("MeshComponent"));
    RootComponent = MeshComp;
    SetReplicates(true);

    NetUpdateFrequency = 66.0f;
    MinNetUpdateFrequency = 33.0f;
}

void ASWeapon::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ASWeapon, bIsReloading);
    DOREPLIFETIME(ASWeapon, AmmoInClip);
}

void ASWeapon::Reload()
{
	if (bIsReloading || AmmoInClip == MaxAmmo)
	{
		return;
	}

	ASCharacter* MyCharacter = Cast<ASCharacter>(GetOwner());
	
	if (MyCharacter)
	{
		MyCharacter->OnReloadDelegate.Broadcast();
	}

	// Start the reload animation client side
	bIsReloading = true;
	ServerReload();
}

void ASWeapon::CancelReload()
{
	bIsReloading = false;
	GetWorldTimerManager().ClearTimer(TimerHandle_ReloadTimer);

	if (Role < ROLE_Authority)
	{
		ServerCancelReload();
	}
}

void ASWeapon::ServerReload_Implementation()
{
	bIsReloading = true;

	GetWorldTimerManager().SetTimer(TimerHandle_ReloadTimer, [&]() {
		AmmoInClip = MaxAmmo;
		bIsReloading = false;
	}, TimeToReload, false);
}

bool ASWeapon::ServerReload_Validate()
{
	return true;
}

void ASWeapon::ServerCancelReload_Implementation()
{
	CancelReload();
}

bool ASWeapon::ServerCancelReload_Validate()
{
	return true;
}

void ASWeapon::BeginPlay()
{
	APawn* MyPawn = Cast<APawn>(GetOwner());

	AmmoInClip = MaxAmmo;

	if (HitIndicatorWidgetClass && MyPawn && MyPawn->IsPlayerControlled())
	{
		HitIndicatorWidget = CreateWidget<USHitIndicatorWidget>(GetWorld(), HitIndicatorWidgetClass);
		HitIndicatorWidget->AddToViewport();
	}
}


void ASWeapon::ServerFire_Implementation()
{
    Fire();
}

bool ASWeapon::ServerFire_Validate()
{
    return true;
}

/**
 * @param HitActor If this actor is on the other team the weapon hit will be broadcast
 * @param bSkipCheck If true, broadcast weapon hit regardless
 */
void ASWeapon::OnHit(AActor* HitActor, bool bSkipCheck)
{
	if (!HitIndicatorWidget || (!HitActor && !bSkipCheck))
	{
		return;
	}

	if (bSkipCheck)
	{
		HitIndicatorWidget->PlayHitAnimation();
		return;
	}

	USHealthComponent* HitHealth = Cast<USHealthComponent>(HitActor->GetComponentByClass(USHealthComponent::StaticClass()));
	if (HitHealth && GetOwner())
	{
		if (HitIndicatorWidget && !UTeamComponent::IsActorFriendly(HitActor, GetOwner()))
		{
			HitIndicatorWidget->PlayHitAnimation();
		}
	}
}

void ASWeapon::StartFire()
{
	if (AmmoInClip <= 0)
	{
		return;
	}

    float FirstDelay = FMath::Max(LastFireTime + TimeBetweenShots - GetWorld()->TimeSeconds, 0.0f);

	GetWorldTimerManager().SetTimer(TimerHandle_TimeBetweenShots, [&]()
	{
		CancelReload();
		Fire();

		// If the weapon is equipped with 0 
		if (AmmoInClip <= 0)
		{
			StopFire();
			Reload();
		}
	}, TimeBetweenShots, true, FirstDelay);
}

void ASWeapon::StopFire()
{
    GetWorldTimerManager().ClearTimer(TimerHandle_TimeBetweenShots);
}
