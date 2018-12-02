// Fill out your copyright notice in the Description page of Project Settings.

#include "SGameState.h"
#include "STeamManager.h"
#include "STeam.h"
#include "Engine/World.h"
#include "Net/UnrealNetwork.h"


ASGameState::ASGameState() 
{

}

void ASGameState::PreInitializeComponents()
{
    Super::PreInitializeComponents();

    TeamManager = GetWorld()->SpawnActor<ASTeamManager>(ASTeamManager::StaticClass());
}

void ASGameState::MulticastGameOver_Implementation(ASTeam* WinningTeam)
{

    OnTeamGameOver.Broadcast(WinningTeam);
}

void ASGameState::MulticastActorKilled_Implementation(AActor* KilledActor, AActor* KillerActor, AActor* DamageCauser)
{
    OnActorKilledGameState.Broadcast(KilledActor, KillerActor, DamageCauser);
}


ASTeamManager* ASGameState::GetTeamManager()
{
    return TeamManager;
}



