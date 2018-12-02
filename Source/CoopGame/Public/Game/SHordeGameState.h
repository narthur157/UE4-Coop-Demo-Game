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

class ASTeam;

/** Broadcasts that the horde team was set */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHordeTeamChanged, const ASTeam*, HordeTeam);

/** Broadcasts that the player team was set */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPlayerTeamChanged, const ASTeam*, PlayerTeam);

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



    UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_HordeTeam, Category = "TeamStates")
    ASTeam* HordeTeam = nullptr;

    UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_PlayerTeam, Category = "TeamStates")
    ASTeam* PlayerTeam = nullptr;

    UPROPERTY(BlueprintAssignable, Category = "TeamStates")
    FOnHordeTeamChanged OnHordeTeamChanged;

    UPROPERTY(BlueprintAssignable, Category = "TeamStates")
    FOnPlayerTeamChanged OnPlayerTeamChanged;

    UFUNCTION(BlueprintCallable, Category = "WaveState")
    void SetWaveState(EWaveState NewState);

    UFUNCTION(BlueprintCallable, Category = "WaveState")
    void SetCurrentWaveNumber(int32 WaveNumber);

    UFUNCTION(BlueprintCallable, Category = "WaveState")
    void SetNextWaveStartTime(float NewNextWaveStartTime) { NextWaveStartTime = NewNextWaveStartTime; }

    UFUNCTION(BlueprintPure, Category = "WaveState")
    float GetNextWaveStartTime() { return NextWaveStartTime; }

    UFUNCTION(BlueprintPure, Category = "WaveState")
    int32 GetCurrentWaveNumber() { return CurrentWaveNumber; }

    /** Broadcasts when the wave state has changed */
    UPROPERTY(BlueprintAssignable, Category = "WaveState")
    FGameStateWaveChanged OnWaveStateChanged;

    /** Blueprint interface for HordeGameState logic to run when the wave state has been changed */
    UFUNCTION(BlueprintImplementableEvent, Category = "WaveState")
    void WaveStateChanged(EWaveState NewState, EWaveState OldState);

    UFUNCTION()
    void OnRep_HordeTeam();

protected:

    UPROPERTY(Replicated)
    int32 CurrentWaveNumber =  0;

    /** Replicated value that determines when the next wave will spawn as specified by the gamestate */
    UPROPERTY(BlueprintReadOnly, Replicated, Category = "WaveState")
    float NextWaveStartTime = 0.0f;

    /** Enum representing the current state of the wave, see EWaveState definition for value details. */
    UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_WaveStateChanged, Category = "WaveState")
    EWaveState WaveState = EWaveState::None;

    /** Used to broadcast changes in waves to any listening entites on the client. */
    UFUNCTION()
    void OnRep_WaveStateChanged(EWaveState OldState);

    UFUNCTION()
    void OnRep_PlayerTeam();
};

