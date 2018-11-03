// Fill out your copyright notice in the Description page of Project Settings.

#include "SGameMode.h"
#include "SHealthComponent.h"
#include "SGameState.h"
#include "CoopGame.h"
#include "SPlayerController.h"
#include "SPlayerState.h"

ASGameMode::ASGameMode()
{
    GameStateClass = ASGameState::StaticClass();
    PlayerStateClass = ASPlayerState::StaticClass();
    ActorKilled.AddDynamic(this, &ASGameMode::OnActorKilled);
}

void ASGameMode::StartPlay()
{
    Super::StartPlay();

    PrepareForNextWave();
}


void ASGameMode::StartWave()
{
    SetWaveState(EWaveState::WaitingToComplete);
    CurrentWaveCount++;
    NumberBotsToSpawn = 2 * CurrentWaveCount;
    GetWorldTimerManager().SetTimer(TimerHandle_BotSpawner, this, &ASGameMode::SpawnBotTimerElapsed, 1.0f, true, 0.0f);
}

void ASGameMode::SpawnBotTimerElapsed()
{
    SpawnNewBot();
    NumberBotsToSpawn--;
    if (NumberBotsToSpawn <= 0)
    {
        EndWave();
    }
}

void ASGameMode::EndWave()
{
    GetWorldTimerManager().ClearTimer(TimerHandle_BotSpawner);
    SetWaveState(EWaveState::WaitingToComplete);
}

void ASGameMode::PrepareForNextWave()
{
    RestartDeadPlayers();
    // Game is finished, players win on waves
    if (CurrentWaveCount == NumberWaves)
    {
        GameOver(true);
        return;
    }
    // Work on spawning the next wave
    GetWorldTimerManager().SetTimer(TimerHandle_NextWaveStart, this, &ASGameMode::StartWave, TimeBetweenWaves, false);
    SetWaveState(EWaveState::WaitingToStart);
    
}

// Iterate over all of the pawns, if we find a bot and its still alive then carry on
// This should really be generalized more into a team format somehow? broadcast win/lose conditions based on teamID
void ASGameMode::CheckWaveState()
{
    if (NumberBotsToSpawn > 0 || GetWorldTimerManager().IsTimerActive(TimerHandle_NextWaveStart))
    {
        return;
    }

    bool bIsAnyBotAlive = false;
    for (FConstPawnIterator It = GetWorld()->GetPawnIterator(); It; ++It)
    {
        // If we are player controlled
        APawn* TestPawn = It->Get();
        if (!TestPawn || TestPawn->IsPlayerControlled())
        {
            continue;
        }
        USHealthComponent* HealthComp = TestPawn->FindComponentByClass<USHealthComponent>();
        if (HealthComp && HealthComp->GetHealth() > 0)
        {
            // Bot is still alive
            bIsAnyBotAlive = true;
            break;
        }
    }
    if (!bIsAnyBotAlive)
    {
        TRACE("Bots have all died");
        SetWaveState(EWaveState::WaveComplete);
        PrepareForNextWave();
    }
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
        TRACE("Bots have all died");
        GameOver(false);
    }

}

// Called when the game has ended
void ASGameMode::GameOver(bool bWasSuccessful)
{
    EndWave();
    SetWaveState(EWaveState::GameOver);
  
    ASGameState* GS = GetGameState<ASGameState>();
    if (ensureAlways(GS))
    {
        GS->MulticastGameOver(bWasSuccessful);
    }
    OnGameOver(bWasSuccessful);
}

// Changes the state of the wave spawner
void ASGameMode::SetWaveState(EWaveState State)
{
    ASGameState* GS = GetGameState<ASGameState>();
    if (ensureAlways(GS))
    {
        GS->SetWaveState(State);
    }
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

// Called when a player has died, used in order to avoid using tick to check player/wave state
void ASGameMode::OnActorKilled_Implementation(AActor* KilledActor, AActor* KillerActor, AController* KillerController)
{
    APawn* KilledPawn = Cast<APawn>(KilledActor);
    // TODO: We only really need to check one or the other based on whether or not the killed actor is a player
    CheckPlayerState();
    CheckWaveState();
}