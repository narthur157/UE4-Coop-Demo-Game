// Created by YetiTech Studios.
//Extended, modified, rearchitected, and made, you know, usable, by Al Paca
#pragma once

#include "CoreMinimal.h"
#include "GameLiftClientTypes.h"

// AWS includes
#include "aws/gamelift/GameLiftClient.h"
#include "aws/gamelift/model/CreateGameSessionResult.h"
#include "aws/gamelift/model/StartMatchmakingResult.h"
#include "aws/core/auth/AWSCredentialsProvider.h"
#include "aws/gamelift/model/AcceptMatchRequest.h"
//

#include "GameLiftClientApi.generated.h"

UENUM(BlueprintType)
enum class EActivateStatus : uint8
{
	/* Successfully activated. */
	ACTIVATE_Success				UMETA(DisplayName = "Success"),

	/* GameLiftClient was null. Make sure you called CreateGameLiftObject function. */
	ACTIVATE_NoGameLift				UMETA(DisplayName = "Null GameLift"),

	/* Delegate that was suppose to call when outcome is a success was not binded to any function. */
	ACTIVATE_NoSuccessCallback		UMETA(DisplayName = "Success Delegate not bound"),

	/* Delegate that was suppose to call when outcome is a failure was not binded to any function. */
	ACTIVATE_NoFailCallback			UMETA(DisplayName = "Failed Delegate not bound")
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCreateGameSessionSuccess, const FString&, GameSessionID);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCreateGameSessionFailed, const FString&, ErrorMessage);
UCLASS()
class GAMELIFTCLIENTSDK_API UGameLiftCreateGameSession : public UObject
{
	GENERATED_BODY()

	friend class UGameLiftClientObject;

public:
	UPROPERTY(BlueprintAssignable, Category = "GameLift CreateGameSession")
	FOnCreateGameSessionSuccess OnCreateGameSessionSuccess;

	UPROPERTY(BlueprintAssignable, Category = "GameLift CreateGameSession")
	FOnCreateGameSessionFailed OnCreateGameSessionFailed;

private:
	FGameLiftGameSessionConfig SessionConfig;

	static UGameLiftCreateGameSession* CreateGameSession(FGameLiftGameSessionConfig GameSessionProperties);

public:
	UFUNCTION(BlueprintCallable, Category = "GameLift CreateGameSession")
	EActivateStatus Activate();

private:
	void OnCreateGameSession(const Aws::GameLift::GameLiftClient* Client, const Aws::GameLift::Model::CreateGameSessionRequest& Request, const Aws::GameLift::Model::CreateGameSessionOutcome& Outcome, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& Context);
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnDescribeGameSessionStateSuccess, const FString&, SessionID, EGameLiftGameSessionStatus, SessionState);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDescribeGameSessionStateFailed, const FString&, ErrorMessage);
UCLASS()
class GAMELIFTCLIENTSDK_API UGameLiftDescribeGameSession : public UObject
{
	GENERATED_BODY()

	friend class UGameLiftClientObject;

public:

	UPROPERTY(BlueprintAssignable, Category = "GameLift DescribeGameSession")
	FOnDescribeGameSessionStateSuccess OnDescribeGameSessionStateSuccess;
	
	UPROPERTY(BlueprintAssignable, Category = "GameLift DescribeGameSession")
	FOnDescribeGameSessionStateFailed OnDescribeGameSessionStateFailed;

private:
	FString SessionID;

	static UGameLiftDescribeGameSession* DescribeGameSession(FString GameSessionID);

public:
	UFUNCTION(BlueprintCallable, Category = "GameLift DescribeGameSession")
	EActivateStatus Activate();	

private:
	void OnDescribeGameSessionState(const Aws::GameLift::GameLiftClient* Client, const Aws::GameLift::Model::DescribeGameSessionDetailsRequest& Request, const Aws::GameLift::Model::DescribeGameSessionDetailsOutcome& Outcome, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& Context);
	EGameLiftGameSessionStatus GetSessionState(const Aws::GameLift::Model::GameSessionStatus& Status);
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnCreatePlayerSessionSuccess, const FString&, IPAddress, const FString&, Port, const FString&, PlayerSessionID);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCreatePlayerSessionFailed, const FString&, ErrorMessage);
UCLASS()
class GAMELIFTCLIENTSDK_API UGameLiftCreatePlayerSession : public UObject
{
	GENERATED_BODY()

	friend class UGameLiftClientObject;

public:

	UPROPERTY(BlueprintAssignable, Category = "GameLift CreatePlayerSession")
	FOnCreatePlayerSessionSuccess OnCreatePlayerSessionSuccess;

	UPROPERTY(BlueprintAssignable, Category = "GameLift CreatePlayerSession")
	FOnCreatePlayerSessionFailed OnCreatePlayerSessionFailed;

private:
	FString GameSessionID;
	FString PlayerID;

	static UGameLiftCreatePlayerSession* CreatePlayerSession(FString GameSessionID, FString UniquePlayerID);

public:
	UFUNCTION(BlueprintCallable, Category = "GameLift CreatePlayerSession")
	EActivateStatus Activate();

private:
	void OnCreatePlayerSession(const Aws::GameLift::GameLiftClient* Client, const Aws::GameLift::Model::CreatePlayerSessionRequest& Request, const Aws::GameLift::Model::CreatePlayerSessionOutcome& Outcome, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& Context);
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnStartMatchmakingSuccess, const FGameLiftMatchmakingResponseTicket&, ResponseTicket);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnStartMatchmakingFailed, const FString&, ErrorMessage);
UCLASS()
class GAMELIFTCLIENTSDK_API UGameLiftStartMatchmaking : public UObject
{
	GENERATED_BODY()

	friend class UGameLiftClientObject;

public:

	UPROPERTY(BlueprintAssignable, Category = "GameLift StartMatchmaking")
	FOnStartMatchmakingSuccess OnStartMatchmakingSuccess;

	UPROPERTY(BlueprintAssignable, Category = "GameLift StartMatchmaking")
	FOnStartMatchmakingFailed OnStartMatchmakingFailed;

private:
	FGameLiftMatchmakingRequest MatchmakingRequest;

	static UGameLiftStartMatchmaking* StartMatchmaking(const FGameLiftMatchmakingRequest& Request);

public:
	UFUNCTION(BlueprintCallable, Category = "GameLift StartMatchmaking")
	EActivateStatus Activate();

private:
	void OnStartMatchmaking(const Aws::GameLift::GameLiftClient* Client, const Aws::GameLift::Model::StartMatchmakingRequest& Request, const Aws::GameLift::Model::StartMatchmakingOutcome& Outcome, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& Context);
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnStopMatchmakingSuccess);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnStopMatchmakingFailed, const FString&, ErrorMessage);
UCLASS()
class GAMELIFTCLIENTSDK_API UGameLiftStopMatchmaking : public UObject
{
	GENERATED_BODY()

	friend class UGameLiftClientObject;

public:

	UPROPERTY(BlueprintAssignable, Category = "GameLift StopMatchmaking")
	FOnStopMatchmakingSuccess OnStopMatchmakingSuccess;

	UPROPERTY(BlueprintAssignable, Category = "GameLift StopMatchmaking")
	FOnStopMatchmakingFailed OnStopMatchmakingFailed;

private:
	FString TicketId;

	static UGameLiftStopMatchmaking* StopMatchmaking(const FString& TicketId);

public:
	UFUNCTION(BlueprintCallable, Category = "GameLift StopMatchmaking")
	EActivateStatus Activate();

private:
	void OnStopMatchmaking(const Aws::GameLift::GameLiftClient* Client, const Aws::GameLift::Model::StopMatchmakingRequest& Request, const Aws::GameLift::Model::StopMatchmakingOutcome& Outcome, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& Context);
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDescribeMatchmakingSuccess, const TArray<FGameLiftMatchmakingResponseTicket>&, Tickets);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDescribeMatchmakingFailed, const FString&, ErrorMessage);
UCLASS()
class GAMELIFTCLIENTSDK_API UGameLiftDescribeMatchmaking : public UObject
{
	GENERATED_BODY()

	friend class UGameLiftClientObject;

public:

	UPROPERTY(BlueprintAssignable, Category = "GameLift DescribeMatchmaking")
	FOnDescribeMatchmakingSuccess OnDescribeMatchmakingSuccess;

	UPROPERTY(BlueprintAssignable, Category = "GameLift DescribeMatchmaking")
	FOnDescribeMatchmakingFailed OnDescribeMatchmakingFailed;

private:
	TArray<FString> TicketIds;

	static UGameLiftDescribeMatchmaking* DescribeMatchmaking(const TArray<FString>& TicketIds);

public:
	UFUNCTION(BlueprintCallable, Category = "GameLift DescribeMatchmaking")
	EActivateStatus Activate();

private:
	void OnDescribeMatchmaking(const Aws::GameLift::GameLiftClient* Client, const Aws::GameLift::Model::DescribeMatchmakingRequest& Request, const Aws::GameLift::Model::DescribeMatchmakingOutcome& Outcome, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& Context);
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnAcceptMatchSuccess);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAcceptMatchFailed, const FString&, ErrorMessage);
UCLASS()
class GAMELIFTCLIENTSDK_API UGameLiftAcceptMatch : public UObject
{
	GENERATED_BODY()

	friend class UGameLiftClientObject;

public:

	UPROPERTY(BlueprintAssignable, Category = "GameLift AcceptMatch")
	FOnAcceptMatchSuccess OnAcceptMatchSuccess;

	UPROPERTY(BlueprintAssignable, Category = "GameLift AcceptMatch")
	FOnAcceptMatchFailed OnAcceptMatchFailed;

private:
	Aws::GameLift::Model::AcceptanceType AcceptanceType;
	TArray<FString> PlayerIds;
	FString TicketId;

	static UGameLiftAcceptMatch* AcceptMatch(const Aws::GameLift::Model::AcceptanceType& AcceptanceType, const TArray<FString>& PlayerIds, const FString& TicketId);

public:
	UFUNCTION(BlueprintCallable, Category = "GameLift AcceptMatch")
	EActivateStatus Activate();

private:
	void OnAcceptMatch(const Aws::GameLift::GameLiftClient* Client, const Aws::GameLift::Model::AcceptMatchRequest& Request, const Aws::GameLift::Model::AcceptMatchOutcome& Outcome, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& Context);
};