// Fill out your copyright notice in the Description page of Project Settings.

#include "SPlayerState.h"
#include "SHealthComponent.h"
#include "GameFramework/Pawn.h"
#include "TeamComponent.h"
#include "Net/UnrealNetwork.h"

ASPlayerState::ASPlayerState()
{
    TeamComponent = CreateDefaultSubobject<UTeamComponent>(TEXT("Team Component"));
}

void ASPlayerState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);

    DOREPLIFETIME(ASPlayerState, CurrentPawn)
}

void ASPlayerState::SetCurrentPawn(APawn * NewCurrentPawn)
{
    if (Role < ROLE_Authority) { return; }

    CurrentPawn = NewCurrentPawn;
    OnRep_CurrentPawn();
}

/** It sure would be nice if we could just bind to our current pawn here but instead we are bound by the laws of amazinng race conditions and i am far too lazy to set up a delegate in every pawn that is possible to be controlled to alert this playerstate of when we are freed from the constraints of the race condition gods*/
void ASPlayerState::OnCurrentPawnDamageDone(AActor* DamageInstigatorActor, AActor* DamagedActor, AActor* DamageCauser, float Damage)
{
    AddDamage(Damage);
}

void ASPlayerState::OnCurrentPawnDamageTaken(AActor* DamageReciever, AActor DamageDealer, AActor* DamageCauser, float Damage)
{
    AddDamageTaken(Damage);
}

void ASPlayerState::OnRep_CurrentPawn()
{
    OnCurrentPawnChanged.Broadcast(this, CurrentPawn);
}


//////////////////////////////////
/** PlayerStats Modifiers */
void ASPlayerState::AddScore(float ScoreDelta)
{
    Score += ScoreDelta;
    OnRep_Score();
}


void ASPlayerState::AddDeaths(int32 DeathsDelta)
{
    Deaths += DeathsDelta;
    OnRep_Deaths();
}

void ASPlayerState::AddDamage(float DamageDelta)
{
    DamageDone += DamageDelta;
    OnRep_DamageDone();
}

void ASPlayerState::AddDamageTaken(float DamageTakenDelta)
{
    DamageTaken += DamageTakenDelta;
    OnRep_DamageTaken();

}

//////////////////////////////////
/** PlayerStats OnRep */
void ASPlayerState::OnRep_Score()
{
    OnScoreChanged.Broadcast(this, Score);
}

void ASPlayerState::OnRep_Deaths()
{
    OnNumberDeathsChanged.Broadcast(this, Deaths);
}

void ASPlayerState::OnRep_DamageDone()
{
    OnDamageChanged.Broadcast(this, DamageDone);
}

void ASPlayerState::OnRep_DamageTaken()
{
    OnDamageTakenChanged.Broadcast(this, DamageTaken);
}
