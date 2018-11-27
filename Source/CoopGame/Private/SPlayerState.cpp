// Fill out your copyright notice in the Description page of Project Settings.

#include "SPlayerState.h"
#include "Net/UnrealNetwork.h"


void ASPlayerState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);

    DOREPLIFETIME(ASPlayerState, CurrentPawn)
    DOREPLIFETIME(ASPlayerState, Team);

}
void ASPlayerState::AddScore(float ScoreDelta)
{
    Score += ScoreDelta;
}

void ASPlayerState::SetCurrentPawn(APawn * NewCurrentPawn)
{
    if (Role < ROLE_Authority) { return; }

    CurrentPawn = NewCurrentPawn;
    OnRep_CurrentPawn();
}

void ASPlayerState::OnRep_CurrentPawn()
{
    OnCurrentPawnChanged.Broadcast(this, CurrentPawn);
}

void ASPlayerState::OnRep_Team()
{
    OnTeamChanged.Broadcast(this, Team);
}