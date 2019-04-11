// Fill out your copyright notice in the Description page of Project Settings.

#include "SHUD.h"
#include "Blueprint/UserWidget.h"



void ASHUD::SetPawnWidget(UUserWidget* NewPawnWidget)
{
    RemovePawnWidget();
    if (NewPawnWidget)
    {
        PawnWidget = NewPawnWidget;
        PawnWidget->AddToViewport();
    }
}

void ASHUD::RemovePawnWidget()
{
    if (PawnWidget)
    {
        PawnWidget->RemoveFromParent();
        PawnWidget = nullptr;
    }
}