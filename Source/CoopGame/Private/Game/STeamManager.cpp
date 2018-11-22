// Fill out your copyright notice in the Description page of Project Settings.

#include "STeamManager.h"
#include "Net/UnrealNetwork.h"
#include "Engine/World.h"
#include "STeam.h"



ASTeamManager::ASTeamManager()
{
    SetReplicates(true);
    bAlwaysRelevant = true;

}

void ASTeamManager::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);

    DOREPLIFETIME(ASTeamManager, Teams);
}

void ASTeamManager::CreateTeam(uint8 TeamID)
{
    if (Role < ROLE_Authority) { return; }

    for (ASTeam* Team : Teams)
    {
        if (Team->GetTeamID() == TeamID)
        {
            return;
        }
    }

    ASTeam* NewTeam = GetWorld()->SpawnActor<ASTeam>(ASTeam::StaticClass());
    NewTeam->SetTeamID(TeamID);
    Teams.Add(NewTeam);
}

void ASTeamManager::AddPlayerToTeam(AController* Player, uint8 TeamToAddTo)
{
    if (Role < ROLE_Authority)
    {
        ServerAddPlayerToTeam(Player, TeamToAddTo);
        return;
    }

    // Get the team whoose ID matches the TeamToAddTo
    for (ASTeam* Team : Teams)
    {
        if (Team->GetTeamID() == TeamToAddTo)
        {
            Team->AddToTeam(Player);
        }
        break;
    }
}

void ASTeamManager::ServerAddPlayerToTeam_Implementation(AController* Player, uint8 TeamToAddTo)
{
    AddPlayerToTeam(Player, TeamToAddTo);
}

bool ASTeamManager::ServerAddPlayerToTeam_Validate(AController* Player, uint8 TeamToAddTo)
{
    return true;
}

ASTeam* ASTeamManager::GetTeam(uint8 TeamIndex)
{
    for (ASTeam* Team : Teams)
    {
        if (Team->GetTeamID() == TeamIndex)
        {
            return Team;
        }
    }
    return nullptr;
}