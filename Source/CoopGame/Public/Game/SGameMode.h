// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "SGameMode.generated.h"


class UUserWidget;

/**
 * Base GameState type. Simply recieves events about Actors being killed. Specific GameModes should be derived from here.
 * This class does not, and should not, know any specifics about concrete GameModes.
 */
UCLASS(ABSTRACT)
class COOPGAME_API ASGameMode : public AGameModeBase
{
	GENERATED_BODY()
	
public:
    ASGameMode();
    virtual void StartPlay() override;

    /** To be called when an actor is killed, calls on an SGameState to broadcast to clients that an enemy has died */
    UFUNCTION(BlueprintNativeEvent, Category = "GameMode")
    void OnActorKilled(AActor* KilledActor, AActor* KillerActor, AActor* DamageCauser);
    virtual void OnActorKilled_Implementation(AActor* KilledActor, AActor* KillerActor, AActor* DamageCauser);

protected:


    /** Determines if there are any players alive,  */
    void CheckPlayerState();

    /** Begins the GameOver process, calling on an SGameState to broadcast that the victory condition was met for some team(s) */
    UFUNCTION(BlueprintCallable, Category = "GameMode")
    void GameOver(bool bWasSuccessful);

    /** Restarts PlayerControllers with default pawns */
    void RestartDeadPlayers();

    /** Blueprint Interface for GameOver events */
    UFUNCTION(BlueprintImplementableEvent, Category = "GameMode")
    void OnGameOver(bool bWasSuccessful);


    virtual void InitializeHUDForPlayer_Implementation(APlayerController* NewPlayer) override;
};
