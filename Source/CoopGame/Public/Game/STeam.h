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
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FActorJoined, const ASTeam*, Team, const AActor*, Actor);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FActorLeft, const ASTeam*, Team, const AActor*, Actor);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FTeamScoreChanged, const ASTeam*, Team, float, NewScore);

/**
 * 
 */
UCLASS()
class COOPGAME_API ASTeam : public AActor
{

    GENERATED_BODY()

public:
    ASTeam();

    /** Team Events */

    /** Broadcasted when an actor joins the team */
    UPROPERTY(BlueprintAssignable, Category = "Team")
    FActorJoined OnActorJoined;

    /** Broadcasted when an actor leaves the team */
    UPROPERTY(BlueprintAssignable, Category = "Team")
    FActorLeft OnActorLeft;

    /** Broadcasted when a player joins the team */
    UPROPERTY(BlueprintAssignable, Category = "Team")
    FMemberJoined OnMemberJoined;

    /** Broadcasted when a team recieves a TeamID */
    UPROPERTY(BlueprintAssignable, Category = "Team")
    FTeamUpdated OnTeamUpdated;

    /** Broadcasted when a team's score changes */
    UPROPERTY(BlueprintAssignable, Category = "Team")
    FTeamScoreChanged OnTeamScoreChanged;


    /** Getters/Setters */

    UFUNCTION(BlueprintCallable, Category = "TeamStats")
    void AddScore(float ScoreDelta);

    UFUNCTION(BlueprintCallable, Category = "TeamStats")
    float GetScore();

    /** Changes a team ID */
    UFUNCTION(BlueprintCallable, Category = "Team")
    void SetTeamID(uint8 NewTeamID);
   
    /** Retrieves a team's ID */
    UFUNCTION(BlueprintCallable, Category = "Team")
    uint8 GetTeamID() { return TeamID; }


    /** Team Join/Leave operations */

    /** Adds a controller to a team, also attempts to add a the playerstate associated with the team */
    UFUNCTION(BlueprintCallable, Category = "Team")
    void AddToTeam(AController* Controller);

    /** Adds an actor to the team */
    UFUNCTION(BlueprintCallable, Category = "Team")
    void AddActorToTeam(AActor * Actor);

    /** Removes an actor from the team */
    UFUNCTION(BlueprintCallable, Category = "Team")
    void RemoveActorFromTeam(AActor * Actor);

    /** Completely clear out a team, useful for a reset */
    UFUNCTION(BlueprintCallable, Category = "Team")
    void ClearTeam();

    //////////////////////////////////
    // Querying

    /** Get the member's playerstates */
    UFUNCTION(BlueprintCallable, Category = "Team")
    TArray<APlayerState*> GetMemberStates() { return MemberStates; }

    /** Get all the actors which belong to this team */
    UFUNCTION(BlueprintCallable, Category = "Team")
    TArray<AActor*> GetMemberActors() { return MemberActors; }

    /** Get all the actors which belong to this team, with the specified class */
    UFUNCTION(BlueprintCallable, Category = "Team")
    TArray<AActor*> GetActorsOfClass(TSubclassOf<AActor> ActorClass);

    /** GetActorsOfClass but with multiple classes specified, save runtime by passing a set instead of a TArray */
    UFUNCTION(BlueprintCallable, Category = "Team")
    TArray<AActor*> GetActorsOfClassMultiple(const TArray<TSubclassOf<AActor>> &Types);

    /** Get all the actors which belong to this team, with the specified interface */
    UFUNCTION(BlueprintCallable, Category = "Team")
    TArray<AActor*> GetActorsWithInterface(TSubclassOf<UInterface> Interface);

    /** Get all the actors which belong to this team, with the specified tag */
    UFUNCTION(BlueprintCallable, Category = "Team")
    TArray<AActor*> GetActorsWithTag(FName Tag);

protected:

    UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_TeamScore, Category = "TeamStats")
    float TeamScore = 0.0f;

    UPROPERTY(BlueprintReadOnly, Replicated, Category = "Team")
    uint8 TeamID;

    /** Used so we can access team members on server. This will be null on clients */
    TArray<AController*> Members;

    /** Used so we can access team members on clients */
    UPROPERTY(ReplicatedUsing=OnRep_MemberStates)
    TArray<APlayerState*> MemberStates;

    UPROPERTY(ReplicatedUsing = OnRep_MemberActors)
    TArray<AActor*> MemberActors;

    UFUNCTION()
    void OnRep_TeamScore();

    UFUNCTION()
    void OnRep_MemberActors() {}

    UFUNCTION()
    void OnRep_MemberStates() {}

    // Cannot get around multicasting here, simply replicatiing the arrays is not enough as
    // it would be a pain to determine whether or not an actor left or joined based solely on an onrep
    UFUNCTION(NetMulticast, Reliable, WithValidation)
    void PlayerJoinedTeam(APlayerState* Player);

    UFUNCTION(NetMulticast, Reliable, WithValidation)
    void ActorJoinedTeam(AActor* Actor);

    UFUNCTION(NetMulticast, Reliable, WithValidation)
    void ActorLeftTeam(AActor* Actor);

    
};
