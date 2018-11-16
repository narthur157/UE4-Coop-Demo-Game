// Fill out your copyright notice in the Description page of Project Settings.

#include "SGameMode.h"
#include "SHealthComponent.h"
#include "SPlayerState.h"
#include "SGameState.h"
#include "STeam.h"
#include "CoopGame.h"


ASGameMode::ASGameMode()
{
    GameStateClass = ASGameState::StaticClass();
    PlayerStateClass = ASPlayerState::StaticClass();
}

void ASGameMode::StartPlay()
{
    Super::StartPlay();
}

// Iterate over all the players, if none are alive then its a loss
void ASGameMode::CheckPlayerState()
{
    bool bIsPlayerAlive = false;
    for (FConstPlayerControllerIterator It = GetWorld()->GetPlayerControllerIterator(); It; It++)
    {
        APawn* PlayerPawn = It->Get()->GetPawn();
        if (PlayerPawn)
        {
            USHealthComponent* HealthComp = PlayerPawn->FindComponentByClass<USHealthComponent>();
            if (ensure(HealthComp) && HealthComp->GetHealth() > 0.0f)
            {
                bIsPlayerAlive = true;
                break;
            }
        }
    }

    if (!bIsPlayerAlive)
    {
        TRACE("All players have died.");
        GameOver(false);
    }
}

// Called when the game has ended
void ASGameMode::GameOver(bool bWasSuccessful)
{
    ASGameState* GS = GetGameState<ASGameState>();
    if (ensureAlways(GS))
    {
        GS->MulticastGameOver(bWasSuccessful);
    }
    OnGameOver(bWasSuccessful);
}

// Respawns dead players
void ASGameMode::RestartDeadPlayers()
{
    for (FConstPlayerControllerIterator It = GetWorld()->GetPlayerControllerIterator(); It; It++)
    {
        APawn* PlayerPawn = It->Get()->GetPawn();
        if (!PlayerPawn)
        {
            RestartPlayer(It->Get());
        }
    }
}

void ASGameMode::InitializeHUDForPlayer_Implementation(APlayerController * NewPlayer)
{
    NewPlayer->ClientSetHUD(HUDClass);
}

// Called when a player has died, used in order to avoid using tick to check player/wave state
void ASGameMode::OnActorKilled_Implementation(AActor* KilledActor, AActor* KillerActor, AActor* DamageCauser)
{
    
}

