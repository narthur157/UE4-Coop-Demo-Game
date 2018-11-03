// Fill out your copyright notice in the Description page of Project Settings.

#include "SPlayerController.h"
#include "Engine.h"
#include "Blueprint/UserWidget.h"



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
    if (!MenuRef)
    {
        MenuRef = CreateWidget<UUserWidget>(this, MenuWidgetClass);
        if (MenuRef)
        {
            MenuRef->AddToViewport();
            MenuRef->SetVisibility(ESlateVisibility::Visible);
            GEngine->GameViewport->Viewport->LockMouseToViewport(false);
            bShowMouseCursor = true;
            
        }
    }
    else
    {
        if (MenuRef->IsVisible())
        {
            MenuRef->SetVisibility(ESlateVisibility::Hidden);
            GEngine->GameViewport->Viewport->LockMouseToViewport(true);
            bShowMouseCursor = false;
        }
        else
        {
            MenuRef->SetVisibility(ESlateVisibility::Visible);
            GEngine->GameViewport->Viewport->LockMouseToViewport(false);
            bShowMouseCursor = true;
        }
    }
}

