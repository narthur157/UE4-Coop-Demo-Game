// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "SPlayerState.generated.h"


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
    uint8 GetTeam() { return TeamID; }

protected:
    
    UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_TeamChanged, Category = "Team")
    uint8 TeamID = 255;


    UFUNCTION()
    void OnRep_TeamChanged() {};
};
