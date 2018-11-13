// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SGameState.h"
#include "SHordeGameState.generated.h"

/** Represents the current state of the wave */
UENUM(BlueprintType)
enum class EWaveState : uint8
{
    None, /** Setup stage, no valid state has been set yet */
    WaitingToStart, /** Intramural state, usually wating for the specified time between waves to elapse */
    WaitingToComplete, /** Wavemobs are spawning or have been spawned, waiting for a wave end case to happen */
    WaveComplete /** A Success case has happened, the wave was completed and has the possibility to loop around to WaitingToStart */
};

/** Broadcasts when a enemy has died in the wave */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGameStateNumEnemiesChanged, int32, NumEnemiesAlive);

/** Broadcasts when the wave state has changed */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FGameStateWaveChanged, EWaveState, OldState, EWaveState, NewWaveState);

/**
 * SHordeGameState - Replicated values and events which clients must be aware of. Intentionally very tightly coupled to 
 * SHordeGameMode. Should not be used with other types of GameModes, rather a new GameState derived from SGameState should be created.
 */
UCLASS()
class COOPGAME_API ASHordeGameState : public ASGameState
{
	GENERATED_BODY()
	
	
public:

    UPROPERTY(BlueprintReadWrite, ReplicatedUsing = OnRep_NumEnemiesChanged, Category = "WaveState")
        int32 NumEnemiesAlive = 0;

    UFUNCTION(BlueprintCallable, Category = "WaveState")
        void SetWaveState(EWaveState NewState);

    UFUNCTION(BlueprintCallable, Category = "WaveState")
        void SetNextWaveStartTime(float NewNextWaveStartTime) { NextWaveStartTime = NewNextWaveStartTime; }

    UFUNCTION(BlueprintPure, Category = "WaveState")
        float GetNextWaveStartTime() { return NextWaveStartTime; }

    /** Broadcasts when the wave state has changed */
    UPROPERTY(BlueprintAssignable, Category = "WaveState")
        FGameStateWaveChanged OnWaveStateChanged;

    /** Broadcasts when a enemy has died in the wave */
    UPROPERTY(BlueprintAssignable, Category = "WaveState")
        FGameStateNumEnemiesChanged OnNumEnemiesChanged;

    /** Blueprint interface for HordeGameState logic to run when the wave state has been changed */
    UFUNCTION(BlueprintImplementableEvent, Category = "WaveState")
        void WaveStateChanged(EWaveState NewState, EWaveState OldState);

   
protected:

    /** Replicated value that determines when the next wave will spawn as specified by the gamestate */
    UPROPERTY(BlueprintReadOnly, Replicated, Category = "WaveState")
        float NextWaveStartTime = 0.0f;

    /** Used to broadcast changes in the number of enemies to any listening entites on the client. */
    UFUNCTION(BlueprintCallable, Category = "WaveState")
        void OnRep_NumEnemiesChanged();

    /** Enum representing the current state of the wave, see EWaveState definition for value details. */
    UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_WaveStateChanged, Category = "WaveState")
        EWaveState WaveState = EWaveState::None;

    /** Used to broadcast changes in waves to any listening entites on the client. */
    UFUNCTION()
    void OnRep_WaveStateChanged(EWaveState OldState);
};

