// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "SGameMode.generated.h"

enum class EWaveState : uint8;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnActorKilled, AActor*, KilledActor, AActor*, KillerActor, AController*, KillerController);

/**
 * Base wave gamemode, win condition = WaveCount == NumberWaves, lose condition = players dead
 */
UCLASS()
class COOPGAME_API ASGameMode : public AGameModeBase
{
	GENERATED_BODY()
	
public:
    ASGameMode();
    virtual void StartPlay() override;

    UPROPERTY(BlueprintAssignable, Category = "GameMode")
    FOnActorKilled ActorKilled;

	
protected:

    // Wave spawning
    UPROPERTY(EditDefaultsOnly, Category = "WaveMode")
    int32 NumberWaves = 1;

    // Preparation time between waves
    UPROPERTY(EditDefaultsOnly, Category = "WaveMode")
    float TimeBetweenWaves = 0.0f;

    int32 CurrentWaveCount = 0;

    // Integer used to control how many bots we are spawning in the current wave
    int32 NumberBotsToSpawn = 0;

    FTimerHandle TimerHandle_BotSpawner;
    FTimerHandle TimerHandle_NextWaveStart;

    // Spawns a bot using the blueprint override
    UFUNCTION(BlueprintImplementableEvent, Category = "GameMode")
    void SpawnNewBot();

    void SpawnBotTimerElapsed();

    void StartWave();

    void EndWave();

    void PrepareForNextWave();

    void SetWaveState(EWaveState State);

    void CheckWaveState();

    // Gamestate handlers 
    void CheckPlayerState();

    void GameOver(bool bWasSuccessful);

    void RestartDeadPlayers();

    UFUNCTION(BlueprintImplementableEvent, Category = "GameMode")
    void OnGameOver(bool bWasSuccessful);
    
    UFUNCTION(BlueprintNativeEvent, Category = "GameMode")
    void OnActorKilled(AActor* KilledActor, AActor* KillerActor, AController* KillerController);

};
