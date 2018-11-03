// Fill out your copyright notice in the Description page of Project Settings.

#include "SGameState.h"
#include "SPlayerController.h"
#include "CoopGame.h"
#include "Net/UnrealNetwork.h"


void ASGameState::OnRep_WaveStateChanged(EWaveState OldState)
{
    WaveStateChanged(WaveState, OldState);
}

void ASGameState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);

    DOREPLIFETIME(ASGameState, WaveState);
}

void ASGameState::SetWaveState(EWaveState NewState)
{
    if (Role == ROLE_Authority)
    {
        EWaveState OldState = WaveState;
        WaveState = NewState;
        OnRep_WaveStateChanged(OldState);
    }
}

void ASGameState::MulticastGameOver_Implementation(bool bWasSuccessful)
{
    for (FConstPlayerControllerIterator It = GetWorld()->GetPlayerControllerIterator(); It; ++It)
    {
        ASPlayerController* PC = Cast<ASPlayerController>(It->Get());
        if (PC && PC->IsLocalController())
        {
            if (PC->GetPawn())
            {
                PC->GetPawn()->DisableInput(PC);
            }
            PC->RecieveGameOver(bWasSuccessful);
        }
    }
}