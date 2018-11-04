// Fill out your copyright notice in the Description page of Project Settings.

#include "SPlayerController.h"
#include "Engine.h"
#include "SGameState.h"
#include "Blueprint/UserWidget.h"
#include "SGameEventWidget.h"

ASPlayerController::ASPlayerController()
    : APlayerController()
{
  
}


void ASPlayerController::BeginPlay()
{
    Super::BeginPlay();

    if (GameEventWidgetClass && IsLocalController())
    {
        GameEventWidget = CreateWidget<USGameEventWidget>(this, GameEventWidgetClass);
        GameEventWidget->AddToViewport();
  
        ASGameState* GS = GetWorld()->GetGameState<ASGameState>();
        if (ensureAlways(GS) && GameEventWidget)
        {
            GS->OnActorKilledGameState.AddDynamic(GameEventWidget, &USGameEventWidget::OnActorKilled);
        }
    }
}

void ASPlayerController::SetupInputComponent()
{
    Super::SetupInputComponent();

    ensure(InputComponent);

    InputComponent->BindAction("ToggleMenu", IE_Pressed, this, &ASPlayerController::ToggleMenu);

}

void ASPlayerController::RecieveGameOver(bool bWasSuccessful)
{
    OnRecieveGameOver(bWasSuccessful);
}

void ASPlayerController::ToggleMenu()
{
    if (!MenuWidget)
    {
        MenuWidget = CreateWidget<UUserWidget>(this, MenuWidgetClass);
        if (MenuWidget)
        {
            MenuWidget->AddToViewport();
            MenuWidget->SetVisibility(ESlateVisibility::Visible);
            GEngine->GameViewport->Viewport->LockMouseToViewport(false);
            bShowMouseCursor = true;
            
        }
    }
    else
    {
        if (MenuWidget->IsVisible())
        {
            MenuWidget->SetVisibility(ESlateVisibility::Hidden);
            GEngine->GameViewport->Viewport->LockMouseToViewport(true);
            bShowMouseCursor = false;
        }
        else
        {
            MenuWidget->SetVisibility(ESlateVisibility::Visible);
            GEngine->GameViewport->Viewport->LockMouseToViewport(false);
            bShowMouseCursor = true;
        }
    }
}

