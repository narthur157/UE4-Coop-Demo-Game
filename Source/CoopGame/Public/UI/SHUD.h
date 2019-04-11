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

    /** Clears current PawnWidget, sets @NewPawnnWidget as the currently displayed widget */
    UFUNCTION(BlueprintCallable, Category = "SHUD")
    void SetPawnWidget(UUserWidget* NewPawnWidget);

    /** Removes the current PawnWidget from the viewport and prepares it for garbage collection */
    UFUNCTION(BlueprintCallable, Category = "SHUD")
    void RemovePawnWidget();
	
protected:

    /** The HUD that the current possessed Pawn wishes to display */
    UPROPERTY(BlueprintReadWrite, Category = "SHUD")
        UUserWidget* PawnWidget = nullptr;

    /** The HUD that the current GameMode wishes to display */
    UPROPERTY(BlueprintReadWrite, Category = "SHUD")
        UUserWidget* GameWidget = nullptr;
};
