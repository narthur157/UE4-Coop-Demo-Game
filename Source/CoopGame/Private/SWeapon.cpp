// Fill out your copyright notice in the Description page of Project Settings.

#include "SWeapon.h"
#include "DrawDebugHelpers.h"
#include "Components/SkeletalMeshComponent.h"
#include "Engine/World.h"
#include "SHealthComponent.h"
#include "UserWidget.h"
#include "SHitIndicatorWidget.h"

ASWeapon::ASWeapon()
{
    MeshComp = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("MeshComponent"));
    RootComponent = MeshComp;
    SetReplicates(true);

    NetUpdateFrequency = 66.0f;
    MinNetUpdateFrequency = 33.0f;
}

void ASWeapon::BeginPlay()
{
	APawn* MyPawn = Cast<APawn>(GetOwner());

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
	}

	USHealthComponent* HitHealth = Cast<USHealthComponent>(HitActor->GetComponentByClass(USHealthComponent::StaticClass()));
	if (HitHealth && GetOwner())
	{
		if (HitIndicatorWidget && !USHealthComponent::IsFriendly(HitActor, GetOwner()))
		{
			HitIndicatorWidget->PlayHitAnimation();
		}
	}
}

void ASWeapon::StartFire()
{

    float FirstDelay = FMath::Max(LastFireTime + TimeBetweenShots - GetWorld()->TimeSeconds, 0.0f);
    GetWorldTimerManager().SetTimer(TimerHandle_TimeBetweenShots, this, &ASWeapon::Fire, TimeBetweenShots, true, FirstDelay);
}

void ASWeapon::StopFire()
{
    GetWorldTimerManager().ClearTimer(TimerHandle_TimeBetweenShots);
}


