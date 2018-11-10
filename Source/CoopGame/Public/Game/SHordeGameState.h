// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SGameState.h"
#include "SHordeGameState.generated.h"

UENUM(BlueprintType)
enum class EWaveState : uint8
{
    None,
    WaitingToStart,
    WaitingToComplete,
    WaveComplete,
    GameOver

};

/** Broadcasts when the game has ended */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGameStateNumEnemiesChanged, int32, NumEnemiesAlive);

/** Broadcasts when the wave state has changed */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FGameStateWaveChanged, EWaveState, OldState, EWaveState, NewWaveState);

/**
 * 
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

    UPROPERTY(BlueprintAssignable, Category = "WaveState")
        FGameStateWaveChanged OnWaveStateChanged;

    UPROPERTY(BlueprintAssignable, Category = "WaveState")
        FGameStateNumEnemiesChanged OnNumEnemiesChanged;

    UFUNCTION(BlueprintImplementableEvent, Category = "WaveState")
        void WaveStateChanged(EWaveState NewState, EWaveState OldState);

   
protected:

    UPROPERTY(BlueprintReadOnly, Replicated, Category = "WaveState")
        float NextWaveStartTime = 0.0f;

    UFUNCTION(BlueprintCallable, Category = "WaveState")
        void OnRep_NumEnemiesChanged();

    UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_WaveStateChanged, Category = "WaveState")
        EWaveState WaveState = EWaveState::None;

    UFUNCTION()
        void OnRep_WaveStateChanged(EWaveState OldState);
};

