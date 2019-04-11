// Fill out your copyright notice in the Description page of Project Settings.

#include "SAIController.h"
#include "SPlayerState.h"
#include "Runtime/AIModule/Classes/BrainComponent.h"


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

void ASAIController::PauseLogic(const FString& Reason)
{
    BrainComponent->PauseLogic(Reason);
}

void ASAIController::ResumeLogic(const FString& Reason)
{
    BrainComponent->ResumeLogic(Reason);
}

void ASAIController::ClearFocusForPriority(int32 InPriority)
{
    ClearFocus(InPriority);
}

void ASAIController::ClearFocusForPriorityType(FFocusType Type)
{
    ClearFocus((uint8)Type);
}

AActor* ASAIController::GetFocusActorForPriority(int32 InPriority)
{
    return FocusInformation.Priorities.IsValidIndex(InPriority) ? FocusInformation.Priorities[InPriority].Actor.Get() : nullptr;
}

FVector ASAIController::GetFocalPointForPriority(int32 InPriority)
{
    FVector FocalPoint = FAISystem::InvalidLocation;
    if (FocusInformation.Priorities.IsValidIndex(InPriority))
    {
        if (FocusInformation.Priorities[InPriority].Actor.Get())
        {
            FocalPoint = FocusInformation.Priorities[InPriority].Actor.Get()->GetActorLocation();
        }
        else
        {
            FocalPoint = FocusInformation.Priorities[InPriority].Position;
        }
    }
    return FocalPoint;
    
}


FVector ASAIController::GetFocalPointForPriorityType(FFocusType Type)
{
    if (Type == FFocusType::Max)
    {
        return GetFocalPoint();
    }
    else
    {
        return GetFocalPointForPriority((uint8)Type);
    }
}

AActor* ASAIController::GetFocusActorForFocusType(FFocusType Type)
{
    if (Type == FFocusType::Max)
    {
        return GetFocusActor();
    }
    else
    {
        return GetFocusActorForPriority((uint8)Type);
    }
}

int32 ASAIController::SetFocalPointForPriority(int32 InPriority, FVector Point)
{
    SetFocalPoint(Point, InPriority);
    return InPriority;
}


int32 ASAIController::SetFocusActorForPriority(int32 InPriority, AActor* Actor)
{
    SetFocus(Actor, InPriority);
    return InPriority;
}

int32 ASAIController::SetFocalPointForPriorityType(FFocusType Type, FVector Point)
{
    int32 FocusIndex = -1;
    if (Type == FFocusType::Max)
    {
        SetFocalPoint(Point, FocusInformation.Priorities.Num());
        FocusIndex = FocusInformation.Priorities.Num();
    }
    else
    {
        SetFocalPoint(Point, (uint8)Type);
        FocusIndex = (uint8)Type;
    }
    return FocusIndex;
    
}

int32 ASAIController::SetFocusActorForPriorityType(FFocusType Type, AActor* Actor)
{

    int32 FocusIndex = -1;
    if (Type == FFocusType::Max)
    {
        SetFocus(Actor, FocusInformation.Priorities.Num());
        FocusIndex = FocusInformation.Priorities.Num();
    }
    else
    {
        SetFocus(Actor, (uint8)Type);
        FocusIndex = (uint8)Type;
    }
    return FocusIndex;
}

void ASAIController::SetCurrentTarget(AActor* NewTarget)
{
    SetFocusActorForPriorityType(FFocusType::Target, NewTarget);
}

AActor* ASAIController::GetCurrentTarget()
{
    AActor* Target = nullptr;
    if (FocusInformation.Priorities.IsValidIndex((uint8)FFocusType::Target))
    {
        Target = FocusInformation.Priorities[(uint8)FFocusType::Target].Actor.Get();
    }

    return Target;
}

