// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "SGameMode.generated.h"

/**
 * 
 */
UCLASS()
class COOPGAME_API ASGameMode : public AGameModeBase
{
	GENERATED_BODY()
	
public:
    ASGameMode();
    virtual void Tick(float Deltatime) override;
    virtual void StartPlay() override;


	
protected:


    int32 WaveCount = 0;

    int32 NumberBotsToSpawn = 0;

    UPROPERTY(EditDefaultsOnly, Category = "GameMode")
    float TimeBetweenWaves = 0.0f;

    FTimerHandle TimerHandle_BotSpawner;
    FTimerHandle TimerHandle_NextWaveStart;


    UFUNCTION(BlueprintImplementableEvent, Category = "GameMode")
    void SpawnNewBot();
	
    void SpawnBotTimerElapsed();

    void StartWave();

    void EndWave();

    void PrepareForNextWave();

    void CheckWaveState();
    void CheckPlayerState();

    void GameOver();
};
