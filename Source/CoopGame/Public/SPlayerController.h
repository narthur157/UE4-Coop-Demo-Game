// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "SPlayerController.generated.h"

class UUserWidget;



/**
 * 
 */
UCLASS()
class COOPGAME_API ASPlayerController : public APlayerController
{
	GENERATED_BODY()
	
protected:

    UFUNCTION(BlueprintCallable, Category = "MenuOps")
    void ToggleMenu();

    UUserWidget* MenuRef = nullptr;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Widget")
    TSubclassOf<UUserWidget> MenuWidgetClass = nullptr;

      
public:

    virtual void SetupInputComponent() override;

	
};
