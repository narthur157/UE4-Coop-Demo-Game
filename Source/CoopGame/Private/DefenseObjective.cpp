// Fill out your copyright notice in the Description page of Project Settings.

#include "DefenseObjective.h"
#include "Net/UnrealNetwork.h"
#include "Gameplay/GameplayComponents/TeamComponent.h"
#include "SHealthComponent.h"

// Sets default values
ADefenseObjective::ADefenseObjective()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
    SetReplicates(true);
    HealthComp = CreateDefaultSubobject<USHealthComponent>(TEXT("HealthComponent"));
    TeamComp = CreateDefaultSubobject<UTeamComponent>(TEXT("TeamComponnent"));
}

void ADefenseObjective::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    DOREPLIFETIME(ADefenseObjective, bObjectiveDestroyed);
}

// Called when the game starts or when spawned
void ADefenseObjective::BeginPlay()
{
	Super::BeginPlay();
    HealthComp->OnHealthChanged.AddDynamic(this, &ADefenseObjective::OnHealthComponentTakeDamage);
}

uint8 ADefenseObjective::GetTeamID()
{
    return TeamComp->GetTeamID();
}

void ADefenseObjective::OnRep_ObjectiveDestroyed()
{
    OnObjectiveDestroyed();
}