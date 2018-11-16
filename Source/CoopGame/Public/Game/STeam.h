// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "STeam.generated.h"

class APlayerState;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTeamUpdated, const ASTeam*, ChangedTeam);


/**
 * 
 */
UCLASS()
class COOPGAME_API ASTeam : public AActor
{

    GENERATED_BODY()

public:
    ASTeam();

    UFUNCTION(BlueprintCallable, Category = "Team")
    void SetTeamID(uint8 NewTeamID);
   
    UFUNCTION(BlueprintCallable, Category = "Team")
    uint8 GetTeamID() { return TeamID; }

    UFUNCTION(BlueprintCallable, Category = "Team")
    void AddToTeam(AController* Controller);

    UFUNCTION(BlueprintCallable, Category = "Team")
    TArray<APlayerState*> GetMemberStates() { return MemberStates; }

protected:

    uint8 TeamID;

    /** Used so we can access team members on server. This will be null on clients */
    TArray<AController*> Members;

    /** Used so we can access team members on clients */
    UPROPERTY(ReplicatedUsing=OnRep_MemberStates)
    TArray<APlayerState*> MemberStates;

    UFUNCTION()
    void OnRep_MemberStates() {};


};
