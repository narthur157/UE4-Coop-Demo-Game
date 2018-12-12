// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "SPlayerController.generated.h"

class UUserWidget;
class ASTeam;


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPlayerPawnChanged, APawn*, NewPawn);

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

    UPROPERTY(BlueprintAssignable, Category = "PawnData")
    FOnPlayerPawnChanged OnPawnChanged;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Widget")
    TSubclassOf<UUserWidget> MenuWidgetClass = nullptr;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Widget")
    TSubclassOf<UUserWidget> GameEventWidgetClass = nullptr;

    UFUNCTION(BlueprintImplementableEvent, Category = "AController")
    void OnPawnChange();

    UPROPERTY(BlueprintReadWrite, Category = "PawnData")
    UUserWidget* PawnWidget = nullptr;

    UUserWidget* GameEventWidget = nullptr;
      
    UUserWidget* MenuWidget = nullptr;


    float CurrentRecoilYawOffset = 0.0f;
    float CurrentRecoilPitchOffset = 0.0f;

    float RecoilResetTime = 0.0f;

public:
    virtual void BeginPlay() override;
    ASPlayerController();
    virtual void SetupInputComponent() override;
    virtual void Tick(float DeltaTime) override;

    UFUNCTION(BlueprintCallable, Category = "GameOver")
    void RecieveGameOver(ASTeam* WinningTeam);
	
    UFUNCTION(BlueprintImplementableEvent, Category = "GameOver")
    void OnRecieveGameOver(ASTeam* WinningTeam);

    void SetPawn(APawn* InPawn) override;

    void AddRecoilInputYaw(float RecoilYawAmount);
    void AddRecoilInputPitch(float RecoilPitchAmount);

protected:
   
};

