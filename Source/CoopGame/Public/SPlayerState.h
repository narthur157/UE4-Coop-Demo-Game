// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "SPlayerState.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnCurrentPawnChanged, ASPlayerState*, PlayerState, APawn*, NewCurrentPawn);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnTeamChanged, ASPlayerState*, ChangedPlayer, ASTeam*, NewTeam);


/** Stat change events */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnPlayerNumberDeathsChanged, ASPlayerState*, ChangedPlayer, int32, NewNumberOfDeaths);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnPlayerScoreChanged, ASPlayerState*, ChangedPlayer, float, NewScore);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnPlayerDamageChanged, ASPlayerState*, ChangedPlayer, float, NewDamage);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnPlayerDamageTakenChanged, ASPlayerState*, ChangedPlayer, float, NewDamageTaken);


class ASTeam;

/**
 * 
 */
UCLASS()
class COOPGAME_API ASPlayerState : public APlayerState
{
    GENERATED_BODY()


public:
   
    UFUNCTION(BlueprintCallable, Category = "Team")
    ASTeam* GetTeam() { return Team; }

    /** [Server Only] */
    UFUNCTION(BlueprintCallable, Category = "Player")
    void SetCurrentPawn(APawn* CurrentPawn);


    UPROPERTY(BlueprintAssignable, Category = "Player")
    FOnCurrentPawnChanged OnCurrentPawnChanged;

    UPROPERTY(BlueprintAssignable, Category = "Player")
    FOnTeamChanged OnTeamChanged;

    /** Stat Modifiers */
    UFUNCTION(BlueprintCallable, Category = "Score")
    void AddScore(float ScoreDelta);

    UFUNCTION(BlueprintCallable, Category = "Score")
    void AddDeaths(int32 DeathsDelta);

    UFUNCTION(BlueprintCallable, Category = "Score")
    void AddDamage(float DamageDelta);

    UFUNCTION(BlueprintCallable, Category = "Score")
    void AddDamageTaken(float DamageTakenDelta);

    /** Player Stats Delegates */
    UPROPERTY(BlueprintAssignable, Category = "PlayerStats")
    FOnPlayerScoreChanged OnScoreChanged;
    UPROPERTY(BlueprintAssignable, Category = "PlayerStats")
    FOnPlayerNumberDeathsChanged OnNumberDeathsChanged;
    UPROPERTY(BlueprintAssignable, Category = "PlayerStats")
    FOnPlayerDamageChanged OnDamageChanged;
    UPROPERTY(BlueprintAssignable, Category = "PlayerStats")
    FOnPlayerDamageTakenChanged OnDamageTakenChanged;

protected:

    UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Team, Category = "Team")
    ASTeam* Team = nullptr;
    UFUNCTION()
    void OnRep_Team();

    UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_CurrentPawn, Category = "Player")
    APawn* CurrentPawn = nullptr;
    UFUNCTION()
    void OnRep_CurrentPawn();

    /** Player Stats */
    UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Deaths, Category = "PlayerStats")
    int32 Deaths = 0;
    UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_DamageDone, Category = "PlayerStats")
    float DamageDone = 0.0f;
    UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_DamageTaken, Category = "PlayerStats")
    float DamageTaken = 0.0f;
    /** Player Stats OnRep */
    void OnRep_Score();
    UFUNCTION()
    void OnRep_Deaths();
    UFUNCTION()
    void OnRep_DamageDone();
    UFUNCTION()
    void OnRep_DamageTaken();

    /** Event Reciever functions */
    void OnCurrentPawnDamageDone(AActor* DamageInstigatorActor, AActor* DamagedActor, AActor* DamageCauser, float Damage);

    void OnCurrentPawnDamageTaken(AActor* DamageReciever, AActor DamageDealer, AActor* DamageCauser, float Damage);
};
