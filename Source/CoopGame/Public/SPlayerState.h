// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "SPlayerState.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnCurrentPawnChanged, ASPlayerState*, PlayerState, APawn*, NewCurrentPawn);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnTeamChanged, ASPlayerState*, ChangedPlayer, ASTeam*, NewTeam);

class ASTeam;

/**
 * 
 */
UCLASS()
class COOPGAME_API ASPlayerState : public APlayerState
{
    GENERATED_BODY()


public:
    UFUNCTION(BlueprintCallable, Category = "Score")
    void AddScore(float ScoreDelta);

    UFUNCTION(BlueprintCallable, Category = "Team")
    ASTeam* GetTeam() { return Team; }

    /** [Server Only] */
    UFUNCTION(BlueprintCallable, Category = "Player")
    void SetCurrentPawn(APawn* CurrentPawn);

    UPROPERTY(BlueprintAssignable, Category = "Player")
    FOnCurrentPawnChanged OnCurrentPawnChanged;

    UPROPERTY(BlueprintAssignable, Category = "Player")
    FOnTeamChanged OnTeamChanged;

protected:
    
    UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Team, Category = "Team")
    ASTeam* Team = nullptr;

    UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_CurrentPawn, Category = "Player")
    APawn* CurrentPawn = nullptr;

    UFUNCTION()
    void OnRep_Team();

    UFUNCTION()
    void OnRep_CurrentPawn();
};
