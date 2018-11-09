// Fill out your copyright notice in the Description page of Project Settings.

#include "SGameState.h"
#include "SPlayerController.h"
#include "CoopGame.h"
#include "Net/UnrealNetwork.h"


void ASGameState::OnRep_WaveStateChanged(EWaveState OldState)
{
    WaveStateChanged(WaveState, OldState);
    OnWaveStateChanged.Broadcast(OldState, WaveState);
}

void ASGameState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);

    DOREPLIFETIME(ASGameState, WaveState);
    DOREPLIFETIME(ASGameState, NumEnemiesAlive);
    DOREPLIFETIME(ASGameState, NextWaveStartTime);
}

void ASGameState::SetWaveState(EWaveState NewState)
{
    if (Role == ROLE_Authority)
    {
        EWaveState OldState = WaveState;
        WaveState = NewState;
        OnRep_WaveStateChanged(OldState);
    }
}

void ASGameState::MulticastGameOver_Implementation(bool bWasSuccessful)
{
    TRACE("GameState GameOver");
    OnGameOver.Broadcast(bWasSuccessful);
}

void ASGameState::MulticastActorKilled_Implementation(AActor* KilledActor, AActor* KillerActor, AActor* DamageCauser)
{
    OnActorKilledGameState.Broadcast(KilledActor, KillerActor, DamageCauser);
}

void ASGameState::OnRep_NumEnemiesChanged()
{
    TRACE("NumberEnemiesChanged");
    OnNumEnemiesChanged.Broadcast(NumEnemiesAlive);
}

