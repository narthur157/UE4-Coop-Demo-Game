// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Info.h"
#include "STeamManager.generated.h"

class ASTeam;

/**
 * Primary worker class for teams. Contains information about the playerstates and actors assigned to each team.
 */
UCLASS()
class COOPGAME_API ASTeamManager : public AInfo
{
	GENERATED_BODY()
	

public:
    ASTeamManager();

    /** [ServerOnly] Creates the a team with the specified ID, does nothing if that team already exists */
    UFUNCTION(BlueprintCallable, Category = "Teams")
    void CreateTeam(uint8 NewTeamID);

    /** Returns the teams at the specified index, or null if that team doesnt exist */
    UFUNCTION(BlueprintCallable, Category = "Teams")
    ASTeam* GetTeam(uint8 TeamIndex);

    /** [ServerOnly] Adds a controller to the team at the specified index, does nothing if the ID does not exist */
    UFUNCTION(BlueprintCallable, Category = "Teams")
    void AddPlayerToTeam(AController* NewTeamMember, uint8 TeamToChangeTo);

    /** [ServerOnly] Adds an actor to the specified team, does nothing if the ID does not exist */
    UFUNCTION(BlueprintCallable, Category = "Teams")
    void AddActorToTeam(AActor * Actor, uint8 TeamToAddTo);

protected:

    /** All the teams currently in the game */
    UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Teams, Category = "Teams")
    TArray<ASTeam*> Teams;

    UFUNCTION(BlueprintCallable, Category = "Teams")
    void OnRep_Teams() {}
	
};
