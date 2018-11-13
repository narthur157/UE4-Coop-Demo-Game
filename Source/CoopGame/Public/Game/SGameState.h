// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "SGameState.generated.h"



/** Broadcasts when an actor has been killed */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FGameStateActorKilled, AActor*, KilledActor, AActor*, KillerActor, AActor*, DamageCauser);

/** Broadcasts when the game has ended */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGameStateGameOver, bool, bWasSuccessful);

/**
 * Base GameState type. Simply broadcasts general events such as GameOver/Actor killed to clients. Specific GameStates should be derived from here.
 * This class does not, and should not, know any specifics about concrete GameStates.
 */
UCLASS(ABSTRACT)
class COOPGAME_API ASGameState : public AGameStateBase
{
	GENERATED_BODY()
	
public:

    UFUNCTION(NetMulticast, Reliable)
    void MulticastGameOver(bool bWasSuccessful);

    UFUNCTION(NetMulticast, Reliable)
    void MulticastActorKilled(AActor* KilledActor, AActor* KillerActor, AActor* DamageCauser);

    UPROPERTY(BlueprintAssignable, Category = "GameEvent")
    FGameStateActorKilled OnActorKilledGameState;

    UPROPERTY(BlueprintAssignable, Category = "GameEvent")
    FGameStateGameOver OnGameOver;
   
};
