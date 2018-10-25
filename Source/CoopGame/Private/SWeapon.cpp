// Fill out your copyright notice in the Description page of Project Settings.

#include "SWeapon.h"
#include "DrawDebugHelpers.h"
#include "Components/SkeletalMeshComponent.h"
#include "Engine/World.h"


// Sets default values
ASWeapon::ASWeapon()
{
    MeshComp = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("MeshComponent"));
    RootComponent = MeshComp;
    SetReplicates(true);

    NetUpdateFrequency = 66.0f;
    MinNetUpdateFrequency = 33.0f;
}

void ASWeapon::ServerFire_Implementation()
{
    Fire();
}

bool ASWeapon::ServerFire_Validate()
{
    return true;
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


