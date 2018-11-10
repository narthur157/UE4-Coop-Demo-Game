// Fill out your copyright notice in the Description page of Project Settings.

#include "SHordeGameMode.h"
#include "CoopGame.h"
#include "Blueprint/UserWidget.h"
#include "SHealthComponent.h"
#include "SPlayerState.h"
#include "SHordeGameState.h"


ASHordeGameMode::ASHordeGameMode()
{
    GameStateClass = ASHordeGameState::StaticClass();
    PlayerStateClass = ASPlayerState::StaticClass();
    
}

void ASHordeGameMode::StartPlay()
{
    Super::StartPlay();
    PrepareForNextWave();
}


void ASHordeGameMode::StartWave()
{
    SetWaveState(EWaveState::WaitingToComplete);
    CurrentWaveCount++;
    NumberBotsToSpawn = 6 * CurrentWaveCount;
    GetWorldTimerManager().SetTimer(TimerHandle_BotSpawner, this, &ASHordeGameMode::SpawnBotTimerElapsed, 1.0f, true, 0.0f);
}

void ASHordeGameMode::SpawnBotTimerElapsed()
{
    SpawnNewBot();
    NumberBotsToSpawn--;
    if (NumberBotsToSpawn <= 0)
    {
        EndWave();
    }
}

void ASHordeGameMode::EndWave()
{
    GetWorldTimerManager().ClearTimer(TimerHandle_BotSpawner);
}

void ASHordeGameMode::PrepareForNextWave()
{
    RestartDeadPlayers();
    // Game is finished, players win on waves
    if (CurrentWaveCount == NumberWaves && NumberWaves > 0)
    {
        GameOver(true);
        return;
    }

    // Spawn next wave immediately
    if (TimeBetweenWaves == 0)
    {
        StartWave();
    }
    else
    {
        // Spawn the next wave on a delay
        GetWorldTimerManager().SetTimer(TimerHandle_NextWaveStart, this, &ASHordeGameMode::StartWave, TimeBetweenWaves, false);
        ASHordeGameState* GS = GetGameState<ASHordeGameState>();
        if (ensureAlways(GS))
        {
            GS->SetNextWaveStartTime(GetWorld()->TimeSeconds + TimeBetweenWaves);
        }
    }
    SetWaveState(EWaveState::WaitingToStart);

}

// Iterate over all of the pawns, if we find a bot and its still alive then carry on
// This should really be generalized more into a team format somehow? broadcast win/lose conditions based on teamID
void ASHordeGameMode::CheckWaveState()
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
        TRACE("Bots have all died.");
        SetWaveState(EWaveState::WaveComplete);
        PrepareForNextWave();
    }
}

// Changes the state of the wave spawner
void ASHordeGameMode::SetWaveState(EWaveState State)
{
    ASHordeGameState* GS = GetGameState<ASHordeGameState>();
    if (ensureAlways(GS))
    {
        GS->SetWaveState(State);
    }
}

// Called when a player has died, used in order to avoid using tick to check player/wave state
void ASHordeGameMode::OnActorKilled_Implementation(AActor* KilledActor, AActor* KillerActor, AActor* DamageCauser)
{
    // TODO: We only really need to check one or the other based on whether or not the killed actor is a player
    ASGameState* GS = GetGameState<ASGameState>();
    if (KillerActor && KilledActor)
    {
        GS->MulticastActorKilled(KilledActor, KillerActor, DamageCauser);
    }
    CheckPlayerState();
    CheckWaveState();
}
