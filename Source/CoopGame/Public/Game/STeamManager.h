// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Info.h"
#include "STeamManager.generated.h"

class ASTeam;

/**
 * 
 */
UCLASS()
class COOPGAME_API ASTeamManager : public AInfo
{
	GENERATED_BODY()
	

public:
    ASTeamManager();

    /** [ServerOnly] */
    UFUNCTION(BlueprintCallable, Category = "Teams")
    void CreateTeam(uint8 NewTeamID);

    UFUNCTION(BlueprintCallable, Category = "Teams")
    ASTeam* GetTeam(uint8 TeamIndex);

    /** [ServerOnly] */
    UFUNCTION(BlueprintCallable, Category = "Teams")
    void AddPlayerToTeam(AController* NewTeamMember, uint8 TeamToChangeTo);
    UFUNCTION(Server, Reliable, WithValidation, Category = "Teams")
    void ServerAddPlayerToTeam(AController* NewTeamMember, uint8 TeamToChangeTo);
	
protected:

    UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Teams, Category = "Teams")
    TArray<ASTeam*> Teams;

    UFUNCTION(BlueprintCallable, Category = "Teams")
    void OnRep_Teams() {}
	
};
