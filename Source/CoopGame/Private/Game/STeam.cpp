// Fill out your copyright notice in the Description page of Project Settings.

#include "STeam.h"
#include "Net/UnrealNetwork.h"
#include "Gameplay/GameplayComponents/TeamComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/PlayerState.h"
ASTeam::ASTeam()
{
    bReplicates = true;
}


void ASTeam::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);

    DOREPLIFETIME(ASTeam, MemberStates);
}

void ASTeam::SetTeamID(uint8 NewTeamID)
{
    TeamID = NewTeamID;
}

void ASTeam::AddToTeam(AController* Controller)
{
    // Don't run this on clients. Only server functions are able to change teams.
    if (Role < ROLE_Authority) { return; }

    for (int i = 0; i < Members.Num(); i++)
    {
        if (Members[i] == Controller)
        {
            return;
        }
    }

    if (Controller->PlayerState)
    {
        MemberStates.Add(Controller->PlayerState);

    }
    Members.Add(Controller);
}