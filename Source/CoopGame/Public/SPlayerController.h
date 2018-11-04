// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "SPlayerController.generated.h"

class UUserWidget;
class USGameEventWidget;

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

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Widget")
    TSubclassOf<UUserWidget> MenuWidgetClass = nullptr;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Widget")
    TSubclassOf<USGameEventWidget> GameEventWidgetClass = nullptr;

    USGameEventWidget* GameEventWidget = nullptr;
      
    UUserWidget* MenuWidget = nullptr;

public:
    virtual void BeginPlay() override;
    ASPlayerController();
    virtual void SetupInputComponent() override;

    UFUNCTION(BlueprintCallable, Category = "GameOver")
    void RecieveGameOver(bool bWasSuccessful);
	
    UFUNCTION(BlueprintImplementableEvent, Category = "GameOver")
    void OnRecieveGameOver(bool bWasSuccessful);
};
