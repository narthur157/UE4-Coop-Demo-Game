// Fill out your copyright notice in the Description page of Project Settings.

#include "SPlayerState.h"
#include "SHealthComponent.h"
#include "GameFramework/Pawn.h"
#include "Net/UnrealNetwork.h"


void ASPlayerState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);

    DOREPLIFETIME(ASPlayerState, CurrentPawn)
    DOREPLIFETIME(ASPlayerState, Team);

}

void ASPlayerState::SetCurrentPawn(APawn * NewCurrentPawn)
{
    if (Role < ROLE_Authority) { return; }

    // God the playerstate should really not care about whether or not the pawn it is attached to
    // is using a health component


    OnRep_CurrentPawn();
}

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

void ASPlayerState::OnRep_Team()
{
    OnTeamChanged.Broadcast(this, Team);
}