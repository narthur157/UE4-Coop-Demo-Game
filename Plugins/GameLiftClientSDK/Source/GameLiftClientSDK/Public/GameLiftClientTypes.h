// Created by YetiTech Studios.

#pragma once

#include "aws/gamelift/model/MatchmakingTicket.h"
#include "GameLiftClientTypes.generated.h"

UENUM(BlueprintType)
enum class EGameLiftGameSessionStatus : uint8
{
	STATUS_Activating		UMETA(DisplayName = "Activating"),
	STATUS_Active			UMETA(DisplayName = "Active"),
	STATUS_Error			UMETA(DisplayName = "Error"),
	STATUS_NotSet			UMETA(DisplayName = "Not Set"),
	STATUS_Terminating		UMETA(DisplayName = "Terminating"),
	STATUS_Terminated		UMETA(DisplayName = "Terminated"),
	STATUS_NoStatus			UMETA(Hidden)
};

UENUM(BlueprintType)
enum class EGameLiftMatchmakingTicketStatus : uint8
{
	QUEUED				UMETA(DisplayName = "Queued"),
	SEARCHING			UMETA(DisplayName = "Searching"),
	REQUIRES_ACCEPTANCE UMETA(DisplayName = "Requires Acceptance"),
	PLACING				UMETA(DisplayName = "Placing"),
	COMPLETED			UMETA(DisplayName = "Completed"),
	FAILED				UMETA(DisplayName = "Failed"),
	CANCELLED			UMETA(DisplayName = "Cancelled"),
	TIMED_OUT			UMETA(DisplayName = "Timed Out")
};

USTRUCT(Blueprintable, BlueprintType)
struct FGameLiftGameSessionServerProperties
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite)
	FString Key;

	UPROPERTY(BlueprintReadWrite)
	FString Value;
};

USTRUCT(BlueprintType)
struct FGameLiftGameSessionConfig
{
	GENERATED_USTRUCT_BODY()

private:

	/* Maximum number of players that can be connected simultaneously to the game session. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	int32 MaxPlayers;

	/* 
	 * Unique identifier for an alias associated with the fleet to create a game session in.
	 * You can switch gameplay and players to a new fleet without changing your game client or other game components. 
	 * For example, for games in production, using an alias allows you to seamlessly redirect your player base to a new game server update.
	 * @See http://docs.aws.amazon.com/gamelift/latest/developerguide/aliases-creating.html
	 * @See http://docs.aws.amazon.com/gamelift/latest/apireference/API_CreateAlias.html
	 * */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	FString AliasID;

	/* Set of developer-defined properties for a game session, formatted as a set of type:value pairs. 
	 * These properties are included in the GameSession object, which is passed to the game server with a request to start a new game session */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	TArray<FGameLiftGameSessionServerProperties> GameSessionProperties;

public:

	void SetMaxPlayers(int32 NewMaxPlayers)
	{
		MaxPlayers = NewMaxPlayers;
	}

	void SetAliasID(FString NewAliasID)
	{
		AliasID = NewAliasID;
	}

	void SetGameSessionProperties(TArray<FGameLiftGameSessionServerProperties> NewProperties)
	{
		GameSessionProperties = NewProperties;
	}

	FORCEINLINE int32 GetMaxPlayers() const { return MaxPlayers; }
	FORCEINLINE FString GetAliasID() const { return AliasID; }
	FORCEINLINE FString GetGameLiftLocalFleetID() const { return "fleet-1a2b3c4d-5e6f-7a8b-9c0d-1e2f3a4b5c6d"; }
	FORCEINLINE TArray<FGameLiftGameSessionServerProperties> GetGameSessionProperties() const { return GameSessionProperties; }

	FGameLiftGameSessionConfig()
	{
		MaxPlayers = 0;
		AliasID = "";
	}	
};

USTRUCT(BlueprintType)
struct FGameLiftGameSessionDesiredPlayerSessions
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadWrite)
	FString PlayerData;

	UPROPERTY(BlueprintReadWrite)
	FString PlayerId;
};

USTRUCT(BlueprintType)
struct FGameLiftPlayerLatency
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadWrite)
	int32 LatencyMilliseconds;

	UPROPERTY(BlueprintReadWrite)
	FString PlayerId;

	UPROPERTY(BlueprintReadWrite)
	FString RegionId;
};

USTRUCT(BlueprintType)
struct FGameLiftPlayer
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadWrite)
	int32 LatencyMilliseconds;

	UPROPERTY(BlueprintReadWrite)
	int32 Elo;

	UPROPERTY(BlueprintReadWrite)
	FString PlayerId;
};

USTRUCT(BlueprintType)
struct FGameLiftMatchmakingRequest
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadWrite)
	FString ConfigurationName;

	UPROPERTY(BlueprintReadWrite)
	TArray<FGameLiftPlayer> Players;

	UPROPERTY(BlueprintReadWrite)
	FString TicketId;
};

USTRUCT(BlueprintType)
struct FGameLiftMatchedPlayerSession
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadWrite)
	FString PlayerId;

	UPROPERTY(BlueprintReadWrite)
	FString PlayerSessionId;
};

USTRUCT(BlueprintType)
struct FGameLiftGameSessionConnectionInfo
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadWrite)
	FString GameSessionArn;

	UPROPERTY(BlueprintReadWrite)
	FString IpAddress;

	UPROPERTY(BlueprintReadWrite)
	TArray<FGameLiftMatchedPlayerSession> MatchedPlayerSessions;

	UPROPERTY(BlueprintReadWrite)
	int32 Port;
};

USTRUCT(BlueprintType)
struct FGameLiftMatchmakingResponseTicket
{
	GENERATED_USTRUCT_BODY()

	FGameLiftMatchmakingResponseTicket() { }
	FGameLiftMatchmakingResponseTicket(const Aws::GameLift::Model::MatchmakingTicket& Ticket);

	UPROPERTY(BlueprintReadWrite)
	FString ConfigurationName;

	UPROPERTY(BlueprintReadWrite)
	float EndTime = 0.0f;

	UPROPERTY(BlueprintReadWrite)
	int32 EstimatedWaitTime = 0;

	UPROPERTY(BlueprintReadWrite)
	FGameLiftGameSessionConnectionInfo GameSessionConnectionInfo;

	UPROPERTY(BlueprintReadWrite)
	TArray<FGameLiftPlayer> Players;

	UPROPERTY(BlueprintReadWrite)
	EGameLiftMatchmakingTicketStatus Status;

	UPROPERTY(BlueprintReadWrite)
	FString StatusMessage;

	UPROPERTY(BlueprintReadWrite)
	FString StatusReason;

	UPROPERTY(BlueprintReadWrite)
	FString TicketId;
};