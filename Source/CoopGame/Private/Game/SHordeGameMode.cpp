// Fill out your copyright notice in the Description page of Project Settings.

#include "SHordeGameMode.h"
#include "CoopGame.h"
#include "Blueprint/UserWidget.h"
#include "SHealthComponent.h"
#include "SPlayerState.h"
#include "STeamManager.h"
#include "Engine/Engine.h"
#include "Engine/World.h"
#include "STeam.h"
#include "Gameplay/SAffix.h"
#include "TimerManager.h"
#include "SHordeGameState.h"


ASHordeGameMode::ASHordeGameMode()
{
    GameStateClass = ASHordeGameState::StaticClass();
    PlayerStateClass = ASPlayerState::StaticClass();
    
}

void ASHordeGameMode::StartPlay()
{
    Super::StartPlay();

    ASHordeGameState* GS = GetGameState<ASHordeGameState>();
    if (!GS) { return; }

    GS->GetTeamManager()->CreateTeam(PlayerTeamNumber);
    GS->PlayerTeam = GS->GetTeamManager()->GetTeam(PlayerTeamNumber);
    GS->GetTeamManager()->CreateTeam(HordeTeamNumber);
    GS->HordeTeam = GS->GetTeamManager()->GetTeam(HordeTeamNumber);
    GS->OnRep_HordeTeam();
    
    PrepareForNextWave();
}


void ASHordeGameMode::StartWave()
{

    // Update the current wave count
    ASHordeGameState* GS = GetGameState<ASHordeGameState>();
    if (!GS) { return; }
    CurrentWaveCount++;
    GS->SetCurrentWaveNumber(CurrentWaveCount);

    SetWaveState(EWaveState::WaitingToComplete);
    NumberBotsToSpawn = NumberBotsPerWave * CurrentWaveCount;
    GetWorldTimerManager().SetTimer(TimerHandle_BotSpawner, this, &ASHordeGameMode::SpawnBotTimerElapsed, 1.0f, true, 0.0f);
}

void ASHordeGameMode::SpawnBotTimerElapsed()
{
    SpawnNewBot();
    NumberBotsToSpawn--;
    if (NumberBotsToSpawn <= 0)
    {
        ApplyWaveAffixes();
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

    SpawnRandomAffix();

    // Game is finished, players win on waves
    ASHordeGameState* GS = GetGameState<ASHordeGameState>();
    if (CurrentWaveCount == NumberWaves && NumberWaves > 0)
    {
        GameOver(GS->PlayerTeam);
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

    ASHordeGameState* GS = GetGameState<ASHordeGameState>();
    if (!GS)
    {
        return;
    }
    ASTeam* HordeTeam = GS->GetTeamManager()->GetTeam(HordeTeamNumber);
    if (!HordeTeam)
    {
        return;
    }

    // Perhaps in the future its best to have an interface for mobs that can be wave mobs.
    TArray<AActor*> WaveMobsAlive = HordeTeam->GetActorsWithTag("WaveMob");
    if (WaveMobsAlive.Num() <= 0)
    {
        HordeTeam->ClearTeam();

        PrepareForNextWave();
        return;
    }
}

void ASHordeGameMode::CheckPlayerState()
{
    ASHordeGameState* GS = GetGameState<ASHordeGameState>();
    if (!GS) { return; }

    TArray<AActor*> PlayerTeamActors = GS->PlayerTeam->GetActorsWithTag("WaveRelevant");
    if (PlayerTeamActors.Num() == 0)
    {
        GS->MulticastGameOver(GS->HordeTeam);
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
    Super::OnActorKilled_Implementation(KilledActor, KillerActor, DamageCauser);
   
    CheckWaveState();
    CheckPlayerState();
}


void ASHordeGameMode::ApplyWaveAffixes()
{
    ASHordeGameState* GS = GetGameState<ASHordeGameState>();
    if (!GS || AllPossibleWaveAffixes.Num() <= 0)
    {
        return;
    }
 
    ASTeam* HordeTeam = GS->HordeTeam;
    TArray<AActor*> HordeTeamPawns = GS->HordeTeam->GetActorsWithTag("WaveMob");
    
    for (AActor* HordeWaveActor : HordeTeamPawns)
    {
        if (HordeWaveActor)
        {
            ApplyWaveAffixesToActor(HordeWaveActor);
        }
    }
}

void ASHordeGameMode::ApplyWaveAffixesToActor(AActor* Actor)
{
    if (!Actor) { return; }

    for (ASAffix* Affix : SpawnedAffixes)
    {
        Affix->ApplyToActor(Actor);
    }
}

ASAffix* ASHordeGameMode::SpawnRandomAffix()
{
    if (AllPossibleWaveAffixes.Num() <= 0) { return nullptr; }
    ASHordeGameState* GS = GetGameState<ASHordeGameState>();
    if (!GS) { return nullptr; }


    TSubclassOf<ASAffix> Chosen = AllPossibleWaveAffixes[FMath::RandRange(0, AllPossibleWaveAffixes.Num() - 1)];
    ASAffix* Affix = GetWorld()->SpawnActor<ASAffix>(Chosen);
    SpawnedAffixes.Add(Affix);
    AllPossibleWaveAffixes.Remove(Chosen);

    GS->AddAffix(Affix);
    

    return Affix;
}