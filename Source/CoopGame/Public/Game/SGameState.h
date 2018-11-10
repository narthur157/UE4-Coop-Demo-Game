// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "SGameState.generated.h"

UENUM(BlueprintType)
enum class EWaveState : uint8
{
    None,
    WaitingToStart,
    WaitingToComplete,
    WaveComplete,
    GameOver

};

/** Broadcasts when an actor has been killed */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FGameStateActorKilled, AActor*, KilledActor, AActor*, KillerActor, AActor*, DamageCauser);

/** Broadcasts when the game has ended */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGameStateGameOver, bool, bWasSuccessful);

/** Broadcasts when the game has ended */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGameStateNumEnemiesChanged, int32, NumEnemiesAlive);

/** Broadcasts when the wave state has changed */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FGameStateWaveChanged, EWaveState, OldState,  EWaveState, NewWaveState);

/**
 * 
 */
UCLASS()
class COOPGAME_API ASGameState : public AGameStateBase
{
	GENERATED_BODY()
	
public:

    UPROPERTY(BlueprintReadOnly, Replicated, Category = "WaveState")
    float NextWaveStartTime = 0.0f;

    UPROPERTY(BlueprintReadWrite, ReplicatedUsing = OnRep_NumEnemiesChanged, Category = "WaveState")
    int32 NumEnemiesAlive = 0;

    UFUNCTION(BlueprintCallable, Category = "WaveState")
    void SetWaveState(EWaveState NewState);

    UFUNCTION(NetMulticast, Reliable)
    void MulticastGameOver(bool bWasSuccessful);

    UFUNCTION(NetMulticast, Reliable)
    void MulticastActorKilled(AActor* KilledActor, AActor* KillerActor, AActor* DamageCauser);

    UPROPERTY(BlueprintAssignable, Category = "GameEvent")
    FGameStateActorKilled OnActorKilledGameState;

    UPROPERTY(BlueprintAssignable, Category = "GameEvent")
    FGameStateGameOver OnGameOver;

    UPROPERTY(BlueprintAssignable, Category = "WaveState")
    FGameStateWaveChanged OnWaveStateChanged;

    UPROPERTY(BlueprintAssignable, Category = "GameObjective")
    FGameStateNumEnemiesChanged OnNumEnemiesChanged;

    UFUNCTION(BlueprintCallable, Category = "WaveState")
    void OnRep_NumEnemiesChanged();

protected:
    UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_WaveStateChanged, Category = "WaveState")
    EWaveState WaveState = EWaveState::None;

    UFUNCTION()
    void OnRep_WaveStateChanged(EWaveState OldState);
	
    UFUNCTION(BlueprintImplementableEvent, Category = "WaveState")
    void WaveStateChanged(EWaveState NewState, EWaveState OldState);

   
};