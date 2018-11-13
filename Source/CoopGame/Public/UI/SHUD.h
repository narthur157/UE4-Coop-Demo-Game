// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "SHUD.generated.h"

class UUserWidget;

/**
 * 
 */
UCLASS()
class COOPGAME_API ASHUD : public AHUD
{
	GENERATED_BODY()

public:

    UFUNCTION(BlueprintCallable, Category = "SHUD")
    void SetPawnWidget(UUserWidget* NewPawnWidget);

    UFUNCTION(BlueprintCallable, Category = "SHUD")
    void RemovePawnWidget();
	
protected:

    UPROPERTY(BlueprintReadWrite, Category = "SHUD")
        UUserWidget* PawnWidget = nullptr;

    UPROPERTY(BlueprintReadWrite, Category = "SHUD")
        UUserWidget* GameWidget = nullptr;
};
