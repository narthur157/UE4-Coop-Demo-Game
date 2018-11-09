// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "SGameMode.generated.h"



/**
 * 
 */
UCLASS(Abstract)
class COOPGAME_API ASGameMode : public AGameModeBase
{
	GENERATED_BODY()
	
public:
    ASGameMode();
    virtual void StartPlay() override;

    UFUNCTION(BlueprintNativeEvent, Category = "GameMode")
    void OnActorKilled(AActor* KilledActor, AActor* KillerActor, AActor* DamageCauser);
    virtual void OnActorKilled_Implementation(AActor* KilledActor, AActor* KillerActor, AActor* DamageCauser);

protected:

    // Gamestate handlers 
    void CheckPlayerState();

    UFUNCTION(BlueprintCallable, Category = "GameMode")
    void GameOver(bool bWasSuccessful);

    void RestartDeadPlayers();

    UFUNCTION(BlueprintImplementableEvent, Category = "GameMode")
    void OnGameOver(bool bWasSuccessful);

};
