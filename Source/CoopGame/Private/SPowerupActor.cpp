// Fill out your copyright notice in the Description page of Project Settings.

#include "SPowerupActor.h"


// Sets default values
ASPowerupActor::ASPowerupActor()
{

}

// Called when the game starts or when spawned
void ASPowerupActor::BeginPlay()
{
	Super::BeginPlay();
   
}

void ASPowerupActor::OnTickPowerup()
{
    TicksProcessed++;

    OnPowerupTicked();

    if (TotalNumberOfTicks <= TicksProcessed)
    {
        OnExpired();
        GetWorldTimerManager().ClearTimer(TimerHandle_PowerupTick);
    }
}

void ASPowerupActor::ActivatePowerup()
{
    if (PowerupInterval > 0.0f)
    {
        GetWorldTimerManager().SetTimer(TimerHandle_PowerupTick, this, &ASPowerupActor::OnTickPowerup, PowerupInterval, true, 0.0f);
    }
    else
    {
        OnTickPowerup();
    }
}
