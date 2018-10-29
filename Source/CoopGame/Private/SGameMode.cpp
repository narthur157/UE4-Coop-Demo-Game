// Fill out your copyright notice in the Description page of Project Settings.

#include "SGameMode.h"
#include "SHealthComponent.h"

ASGameMode::ASGameMode()
{
    PrimaryActorTick.bCanEverTick = true;
    PrimaryActorTick.TickInterval = 1.0f;

}

void ASGameMode::StartWave()
{
    WaveCount++;
    NumberBotsToSpawn = 2 * WaveCount;
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
}

void ASGameMode::PrepareForNextWave()
{

    GetWorldTimerManager().SetTimer(TimerHandle_NextWaveStart, this, &ASGameMode::StartWave, TimeBetweenWaves, false);

}

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
        PrepareForNextWave();
    }
}

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
        GameOver();
    }

}

void ASGameMode::GameOver()
{
    EndWave();
    UE_LOG(LogTemp, Warning, TEXT("Gameover, Players died."));
}

void ASGameMode::Tick(float Deltatime)
{
    Super::Tick(Deltatime);

    CheckWaveState();
    CheckPlayerState();

}

void ASGameMode::StartPlay()
{
    Super::StartPlay();

    PrepareForNextWave();

}
