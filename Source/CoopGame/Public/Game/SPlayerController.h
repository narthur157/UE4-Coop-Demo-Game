#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "SPlayerController.generated.h"

class UUserWidget;
class ASTeam;


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPlayerPawnChanged, APawn*, NewPawn);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPlayerReadyForWaves, AController*, Controller);

UCLASS()
class COOPGAME_API ASPlayerController : public APlayerController
{
	GENERATED_BODY()
	
protected:

    UFUNCTION(BlueprintCallable, Category = "MenuOps")
    void ToggleMenu();

    UPROPERTY(BlueprintAssignable, Category = "PawnData")
    FOnPlayerPawnChanged OnPawnChanged;

	UPROPERTY(BlueprintAssignable, Category = "PawnData")
	FOnPlayerReadyForWaves OnPlayerReady;

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

	UFUNCTION(BlueprintCallable)
	void SetMouseSensitivity();

    UFUNCTION(BlueprintCallable, Category = "GameOver")
    void RecieveGameOver(ASTeam* WinningTeam);
	
    UFUNCTION(BlueprintImplementableEvent, Category = "GameOver")
    void OnRecieveGameOver(ASTeam* WinningTeam);

	UFUNCTION()
	void OnReadyForWaves();

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerOnReadyForWaves();

    void SetPawn(APawn* InPawn) override;

protected:
   
};

