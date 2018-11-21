// Fill out your copyright notice in the Description page of Project Settings.

#include "SAIController.h"
#include "SPlayerState.h"


void ASAIController::BeginPlay()
{
    Super::BeginPlay();

    ASPlayerState* PS = Cast<ASPlayerState>(PlayerState);
    if (PS)
    {
        OnPawnChanged.AddDynamic(PS, &ASPlayerState::SetCurrentPawn);
    }
}


void ASAIController::SetPawn(APawn* InPawn)
{
    Super::SetPawn(InPawn);
    OnPawnChanged.Broadcast(InPawn);
    OnPawnChange();
}