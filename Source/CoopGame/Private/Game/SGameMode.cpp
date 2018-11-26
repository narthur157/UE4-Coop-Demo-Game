// Fill out your copyright notice in the Description page of Project Settings.

#include "SGameMode.h"
#include "SHealthComponent.h"
#include "Engine/World.h"

#include "STeamManager.h"
#include "TeamComponent.h"
#include "STeam.h"
#include "SGameState.h"
#include "SPlayerState.h"

ASGameMode::ASGameMode()
{
    GameStateClass = ASGameState::StaticClass();
    PlayerStateClass = ASPlayerState::StaticClass();
}

void ASGameMode::StartPlay()
{
    Super::StartPlay();

    OnStartPlay();
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
    ASGameState* GS = GetGameState<ASGameState>();
    // Broadcast that an actor has died
    if (GS && KillerActor && KilledActor)
    {
        GS->MulticastActorKilled(KilledActor, KillerActor, DamageCauser);
    }

    // Remove the killed actor from the team it is on
    UTeamComponent* TeamComp = KilledActor->FindComponentByClass<UTeamComponent>();
    if (TeamComp)
    {
        ASTeam* ActorTeam = GS->GetTeamManager()->GetTeam(TeamComp->GetTeamID());
        if (ActorTeam)
        {
            ActorTeam->RemoveActorFromTeam(KilledActor);
        }
    }
}


void ASGameMode::RestartPlayerAtPlayerStart(AController* NewPlayer, AActor* StartSpot)
{
    Super::RestartPlayerAtPlayerStart(NewPlayer, StartSpot);

    OnASDRestartPlayerAtPlayerStart(NewPlayer, StartSpot);
}

void ASGameMode::InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage)
{
    Super::InitGame(MapName, Options, ErrorMessage);

    OnInitGame(MapName, Options);
}

