// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SGameMode.h"
#include "SHordeGameMode.generated.h"


enum class EWaveState : uint8;
class UUserWidget;

/**
 * The base gamemode for Horde and other Wave-Spawning type GameModes. Should be used in conjunction with a SHordeGameState varient in order to
 * send information related to the number of enemies left in a wave/the current state of the wave/etc to clients.
 */
UCLASS()
class COOPGAME_API ASHordeGameMode : public ASGameMode
{
	GENERATED_BODY()
	


public:
    ASHordeGameMode();
    virtual void StartPlay() override;

protected:

    // Wave spawning
    UPROPERTY(EditDefaultsOnly, Category = "GameMode")
    int32 NumberWaves = 1;

    // Preparation time between waves
    UPROPERTY(EditDefaultsOnly, Category = "GameMode")
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

    virtual void OnActorKilled_Implementation(AActor* KilledActor, AActor* KillerActor, AActor* DamageCauser) override;
	
};
