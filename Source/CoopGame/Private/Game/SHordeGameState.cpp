// Fill out your copyright notice in the Description page of Project Settings.

#include "SHordeGameState.h"
#include "Net/UnrealNetwork.h"
#include "CoopGame.h"


void ASHordeGameState::OnRep_WaveStateChanged(EWaveState OldState)
{
    WaveStateChanged(WaveState, OldState);
    OnWaveStateChanged.Broadcast(OldState, WaveState);
}

void ASHordeGameState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);

    DOREPLIFETIME(ASHordeGameState, WaveState);
    DOREPLIFETIME(ASHordeGameState, NumEnemiesAlive);
    DOREPLIFETIME(ASHordeGameState, NextWaveStartTime);
}

void ASHordeGameState::SetWaveState(EWaveState NewState)
{
    if (Role == ROLE_Authority)
    {
        EWaveState OldState = WaveState;
        WaveState = NewState;
        OnRep_WaveStateChanged(OldState);
    }
}

void ASHordeGameState::OnRep_NumEnemiesChanged()
{
    TRACE("NumberEnemiesChanged");
    OnNumEnemiesChanged.Broadcast(NumEnemiesAlive);
}

