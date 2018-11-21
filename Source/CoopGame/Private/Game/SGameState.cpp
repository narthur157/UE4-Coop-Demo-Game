// Fill out your copyright notice in the Description page of Project Settings.

#include "SGameState.h"
#include "SPlayerController.h"
#include "SPlayerState.h"
#include "CoopGame.h"
#include "Gameplay/GameplayComponents/TeamComponent.h"
#include "STeam.h"
#include "Net/UnrealNetwork.h"



void ASGameState::MulticastGameOver_Implementation(bool bWasSuccessful)
{
    TRACE("GameState GameOver");
    OnGameOver.Broadcast(bWasSuccessful);
}

void ASGameState::MulticastActorKilled_Implementation(AActor* KilledActor, AActor* KillerActor, AActor* DamageCauser)
{
    OnActorKilledGameState.Broadcast(KilledActor, KillerActor, DamageCauser);
}

void ASGameState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);

    DOREPLIFETIME(ASGameState, Teams);

}

void ASGameState::CreateTeam(uint8 TeamID)
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

void ASGameState::AddPlayerToTeam(AController* Player, uint8 TeamToAddTo)
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

void ASGameState::ServerAddPlayerToTeam_Implementation(AController* Player, uint8 TeamToAddTo)
{
    AddPlayerToTeam(Player, TeamToAddTo);
}

bool ASGameState::ServerAddPlayerToTeam_Validate(AController* Player, uint8 TeamToAddTo)
{
    return true;
}

ASTeam* ASGameState::GetTeam(uint8 TeamIndex)
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