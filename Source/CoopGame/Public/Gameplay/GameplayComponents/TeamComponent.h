// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TeamComponent.generated.h"



UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class COOPGAME_API UTeamComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTeamComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

    UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_TeamChanged)
    uint8 TeamID = 255;

    UFUNCTION()
    void OnRep_TeamChanged() {};

public:	
	
    UFUNCTION(BlueprintCallable, Category = "Team")
    uint8 GetTeam() { return TeamID; }

    UFUNCTION(BlueprintCallable, Category = "Team")
    void SetTeam(uint8 NewTeamID);

    UFUNCTION(BlueprintCallable, Category = "Team")
    uint8 GetTeamID();
	
    UFUNCTION(BlueprintCallable, Category = "Team")
    static bool IsActorFriendly(AActor* ActorOne, AActor* ActorTwo);
    //static bool IsPlayerFriendly(AController* ControllerOne, AController* ControllerTwo);
	
};
