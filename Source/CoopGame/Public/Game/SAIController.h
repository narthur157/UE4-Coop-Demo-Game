// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "SAIController.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAIPawnChanged, APawn*, NewPawn);

/**
 * 
 */
UCLASS()
class COOPGAME_API ASAIController : public AAIController
{
	GENERATED_BODY()
	
	
protected:

    UPROPERTY(BlueprintAssignable, Category = "PawnData")
    FOnAIPawnChanged OnPawnChanged;

    UFUNCTION(BlueprintImplementableEvent, Category = "AController")
    void OnPawnChange();

public:
    virtual void BeginPlay() override;
    void SetPawn(APawn* InPawn) override;
};
