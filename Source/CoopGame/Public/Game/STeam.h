// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CoopGame.h"
#include "STeam.generated.h"

class APlayerState;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTeamUpdated, const ASTeam*, ChangedTeam);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FMemberJoined, const ASTeam*, Team, const APlayerState*, NewMember);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FMemberLeft, const ASTeam*, Team, const APlayerState*, OldMember);


/**
 * 
 */
UCLASS()
class COOPGAME_API ASTeam : public AActor
{

    GENERATED_BODY()

public:
    ASTeam();

    UPROPERTY(BlueprintAssignable, Category = "Team")
    FMemberJoined OnMemberJoined;

    UPROPERTY(BlueprintAssignable, Category = "Team")
    FTeamUpdated OnTeamUpdated;

    UFUNCTION(BlueprintCallable, Category = "Team")
    void SetTeamID(uint8 NewTeamID);
   
    UFUNCTION(BlueprintCallable, Category = "Team")
    uint8 GetTeamID() { return TeamID; }

    UFUNCTION(BlueprintCallable, Category = "Team")
    void AddToTeam(AController* Controller);

    UFUNCTION(BlueprintCallable, Category = "Team")
    TArray<APlayerState*> GetMemberStates() { return MemberStates; }

protected:

    UPROPERTY(Replicated)
    uint8 TeamID;

    /** Used so we can access team members on server. This will be null on clients */
    TArray<AController*> Members;

    /** Used so we can access team members on clients */
    UPROPERTY(ReplicatedUsing=OnRep_MemberStates)
    TArray<APlayerState*> MemberStates;

    UFUNCTION()
        void OnRep_MemberStates() {}
     
    UFUNCTION(NetMulticast, Reliable, WithValidation)
    void PlayerJoinedTeam(APlayerState* Player);

};
