// Fill out your copyright notice in the Description page of Project Settings.

#include "SAffix.h"
#include "TimerManager.h"




ASAffix::ASAffix()
{
    SetReplicates(true);
    bAlwaysRelevant = true;
}

void ASAffix::ApplyToActor(AActor* Actor)
{
    ActorsActivatedFor.Add(Actor);
    OnApplyToActor(Actor);

    if (TickInterval > 0.0f)
    {
        GetWorldTimerManager().SetTimer(TimerHandle_AffixTick, this, &ASAffix::AffixTick, TickInterval, true);
    }
}

void ASAffix::AffixTick()
{
    OnTicked();
}

void ASAffix::Disable()
{
    OnDisabled();

    GetWorldTimerManager().ClearTimer(TimerHandle_AffixTick);

}