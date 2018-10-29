// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "SGameState.generated.h"

UENUM(BlueprintType)
enum class EWaveState : uint8
{
    WaitingToStart,
    PreparingNextWave, 
    WaitingToComplete,
    WaveComplete,
    GameOver

};


/**
 * 
 */
UCLASS()
class COOPGAME_API ASGameState : public AGameStateBase
{
	GENERATED_BODY()
	
public:
    UFUNCTION(BlueprintCallable, Category = "WaveState")
    void SetWaveState(EWaveState NewState);

protected:
    UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_WaveStateChanged, Category = "WaveState")
        EWaveState WaveState = EWaveState::WaitingToStart;

    UFUNCTION()
    void OnRep_WaveStateChanged(EWaveState OldState);
	
    UFUNCTION(BlueprintImplementableEvent, Category = "WaveState")
    void WaveStateChanged(EWaveState NewState, EWaveState OldState);
};
