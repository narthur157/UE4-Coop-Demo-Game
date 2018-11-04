// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SGameEventWidget.generated.h"

/**
 * 
 */
UCLASS()
class COOPGAME_API USGameEventWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:

    UFUNCTION(BlueprintImplementableEvent, Category = "GameEventWidget")
    void OnActorKilled(const FString& KillerName, const FString& KilledName);

    UFUNCTION(BlueprintImplementableEvent, Category = "GameEventWidget")
    void RequestDisplayMainEvent(const FText& StringToDisplay);

};
