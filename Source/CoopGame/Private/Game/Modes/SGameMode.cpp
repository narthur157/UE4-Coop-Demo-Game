// Fill out your copyright notice in the Description page of Project Settings.

#include "SGameMode.h"
#include "SHealthComponent.h"
#include "Engine/World.h"

#include "STeamManager.h"
#include "TeamComponent.h"
#include "STeam.h"
#include "SGameState.h"
#include "SPlayerState.h"
#include "GameLiftServerSDK.h"

ASGameMode::ASGameMode()
{
    GameStateClass = ASGameState::StaticClass();
    PlayerStateClass = ASPlayerState::StaticClass();

#if WITH_GAMELIFT

	//Getting the module first.
	FGameLiftServerSDKModule* gameLiftSdkModule = &FModuleManager::LoadModuleChecked<FGameLiftServerSDKModule>(FName("GameLiftServerSDK"));

	//InitSDK establishes a local connection with GameLift's agent to enable communication.
	gameLiftSdkModule->InitSDK();

	//Respond to new game session activation request. GameLift sends activation request 
	//to the game server along with a game session object containing game properties 
	//and other settings. Once the game server is ready to receive player connections, 
	//invoke GameLiftServerAPI.ActivateGameSession()
	auto onGameSession = [=](Aws::GameLift::Server::Model::GameSession gameSession)
	{
		gameLiftSdkModule->ActivateGameSession();
	};

	FProcessParameters* params = new FProcessParameters();
	params->OnStartGameSession.BindLambda(onGameSession);

	//OnProcessTerminate callback. GameLift invokes this before shutting down the instance 
	//that is hosting this game server to give it time to gracefully shut down on its own. 
	//In this example, we simply tell GameLift we are indeed going to shut down.
	params->OnTerminate.BindLambda([=]() {gameLiftSdkModule->ProcessEnding(); });

	//HealthCheck callback. GameLift invokes this callback about every 60 seconds. By default, 
	//GameLift API automatically responds 'true'. A game can optionally perform checks on 
	//dependencies and such and report status based on this info. If no response is received  
	//within 60 seconds, health status is recorded as 'false'. 
	//In this example, we're always healthy!
	params->OnHealthCheck.BindLambda([]() {return true; });

	//Here, the game server tells GameLift what port it is listening on for incoming player 
	//connections. In this example, the port is hardcoded for simplicity. Since active game
	//that are on the same instance must have unique ports, you may want to assign port values
	//from a range, such as:
	//const int32 port = FURL::UrlConfig.DefaultPort;
	//params->port;
	params->port = 7777;

	//Here, the game server tells GameLift what set of files to upload when the game session 
	//ends. GameLift uploads everything specified here for the developers to fetch later.
	TArray<FString> logfiles;
	logfiles.Add(TEXT("aLogFile.txt"));
	params->logParameters = logfiles;

	//Call ProcessReady to tell GameLift this game server is ready to receive game sessions!
	gameLiftSdkModule->ProcessReady(*params);
#endif

}

void ASGameMode::StartPlay()
{
    Super::StartPlay();

    OnStartPlay();
}

// Called when the game has ended
void ASGameMode::GameOver(ASTeam* WinningTeam)
{
    ASGameState* GS = GetGameState<ASGameState>();
    if (ensureAlways(GS))
    {
        GS->MulticastGameOver(WinningTeam);
    }
    OnGameOver(WinningTeam);
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

