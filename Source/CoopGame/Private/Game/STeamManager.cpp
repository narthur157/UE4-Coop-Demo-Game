// Fill out your copyright notice in the Description page of Project Settings.

#include "STeamManager.h"
#include "Net/UnrealNetwork.h"
#include "Engine/World.h"
#include "STeam.h"
#include "TeamComponent.h"



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

    // Determine if there already exists a team with the specified ID
    for (ASTeam* Team : Teams)
    {
        if (Team->GetTeamID() == TeamID)
        {
            return;
        }
    }

    // Creates the team and adds it to the Team array
    ASTeam* NewTeam = GetWorld()->SpawnActor<ASTeam>(ASTeam::StaticClass());
    NewTeam->SetTeamID(TeamID);
    Teams.Add(NewTeam);
}

void ASTeamManager::AddPlayerToTeam(AController* Player, uint8 TeamToAddTo)
{
    if (Role < ROLE_Authority) { return; }

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


void ASTeamManager::AddActorToTeam(AActor* Actor, uint8 TeamToAddTo)
{
    if (Role < ROLE_Authority) { return; }

    ASTeam* Team = GetTeam(TeamToAddTo);
    UTeamComponent* TeamComponent = Actor->FindComponentByClass<UTeamComponent>();
    if (!Team || !TeamComponent)
    {
        return;
    }

    if (TeamComponent->GetTeam())
    {
        TeamComponent->GetTeam()->RemoveActorFromTeam(Actor);
    }
    
    Team->AddActorToTeam(Actor);
    TeamComponent->SetTeam(Team);

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