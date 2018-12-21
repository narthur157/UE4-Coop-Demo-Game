// Fill out your copyright notice in the Description page of Project Settings.

#include "SHordeGameState.h"
#include "Net/UnrealNetwork.h"
#include "STeamManager.h"
#include "Engine/Engine.h"
#include "CoopGame.h"



void ASHordeGameState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);

    DOREPLIFETIME(ASHordeGameState, NewAffix);
    DOREPLIFETIME(ASHordeGameState, CurrentlyAppliedAffixes);
    DOREPLIFETIME(ASHordeGameState, PlayerTeam);
    DOREPLIFETIME(ASHordeGameState, HordeTeam);
    DOREPLIFETIME(ASHordeGameState, CurrentWaveNumber);
    DOREPLIFETIME(ASHordeGameState, WaveState);
    DOREPLIFETIME(ASHordeGameState, NextWaveStartTime);
}

void ASHordeGameState::OnRep_WaveStateChanged(EWaveState OldState)
{
    WaveStateChanged(WaveState, OldState);
    OnWaveStateChanged.Broadcast(OldState, WaveState);
}

void ASHordeGameState::OnRep_HordeTeam()
{
    TRACE("RepHordeTeam");
    OnHordeTeamChanged.Broadcast(HordeTeam);
}

void ASHordeGameState::OnRep_PlayerTeam()
{
    TRACE("RepPlayerTeam");
    OnPlayerTeamChanged.Broadcast(PlayerTeam);
}

void ASHordeGameState::OnRep_NewAffix()
{
    OnNewAffix.Broadcast(NewAffix);
}

void ASHordeGameState::MulticastAffixAdded_Implementation(ASAffix* AffixAdded)
{
    OnNewAffix.Broadcast(AffixAdded);
}

void ASHordeGameState::AddAffix(ASAffix* AffixToAdd)
{
    if (!HasAuthority()) { return; }

    CurrentlyAppliedAffixes.Add(AffixToAdd);
    NewAffix = AffixToAdd;
    // To allow for listen servers to play events related to a new affix spawning
    OnRep_NewAffix();
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

void ASHordeGameState::SetCurrentWaveNumber(int32 WaveNumber)
{
    if (HasAuthority())
    {
        CurrentWaveNumber = WaveNumber;
    }
}