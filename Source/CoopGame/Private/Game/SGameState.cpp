// Fill out your copyright notice in the Description page of Project Settings.

#include "SGameState.h"
#include "SPlayerController.h"
#include "CoopGame.h"
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


