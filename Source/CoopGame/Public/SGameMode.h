// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "SGameMode.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnActorKilled, AActor*, KilledActor, AActor*, KillerActor, AController*, KillerController);

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

    UPROPERTY(BlueprintAssignable, Category = "GameMode")
    FOnActorKilled ActorKilled;

    UFUNCTION(BlueprintNativeEvent, Category = "GameMode")
    void OnActorKilled(AActor* KilledActor, AActor* KillerActor, AController* KillerController);
    virtual void OnActorKilled_Implementation(AActor* KilledActor, AActor* KillerActor, AController* KillerController);

protected:

    
    // Gamestate handlers 
    void CheckPlayerState();

    void GameOver(bool bWasSuccessful);

    void RestartDeadPlayers();

    UFUNCTION(BlueprintImplementableEvent, Category = "GameMode")
    void OnGameOver(bool bWasSuccessful);
    
    

};
