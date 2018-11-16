// Fill out your copyright notice in the Description page of Project Settings.

#include "Gameplay/GameplayComponents/TeamComponent.h"
#include "STeam.h"
#include "Net/UnrealNetwork.h"


// Sets default values for this component's properties
UTeamComponent::UTeamComponent()
{
    SetIsReplicated(true);
}

void UTeamComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    DOREPLIFETIME(UTeamComponent, TeamID);

}


// Called when the game starts
void UTeamComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

void UTeamComponent::SetTeam(uint8 NewTeamID)
{
    if (GetOwnerRole() < ROLE_Authority)
    {
        return;
    }

    TeamID = NewTeamID;
}


uint8 UTeamComponent::GetTeamID()
{
    return TeamID;
}


bool UTeamComponent::IsActorFriendly(AActor* ActorOne, AActor* ActorTwo)
{
    UTeamComponent* TeamCompOne = ActorOne->FindComponentByClass<UTeamComponent>();
    UTeamComponent* TeamCompTwo = ActorTwo->FindComponentByClass<UTeamComponent>();

    if (!TeamCompOne || !TeamCompTwo)
    {
        return false;
    }

    if (TeamCompOne->GetTeam() == TeamCompTwo->GetTeam())
    {
        return true;
    }
    return false;

}