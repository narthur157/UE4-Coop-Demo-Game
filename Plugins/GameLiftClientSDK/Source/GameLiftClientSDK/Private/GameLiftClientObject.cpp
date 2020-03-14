// Created by YetiTech Studios.
//Extended, modified, rearchitected, and made, you know, usable, by Al Paca
#include "GameLiftClientObject.h"
#include "GameLiftClientApi.h"
#include "GameLiftClientGlobals.h"
#include "GameLiftClientTypes.h"
#include "aws/gamelift/model/AcceptMatchRequest.h"
#include "aws/core/client/ClientConfiguration.h"

Aws::GameLift::GameLiftClient* UGameLiftClientObject::Client()
{
	const FString AccessKey = "AKIAZRW47CYZ4VG3G675";
	const FString Secret = "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";
	const FString Region = "us-east-1";
	const int32 LocalPort = 7777;

#if WITH_GAMELIFTCLIENTSDK
	Aws::Client::ClientConfiguration ClientConfig;
	Aws::Auth::AWSCredentials Credentials;

	ClientConfig.connectTimeoutMs = 10000;
	ClientConfig.requestTimeoutMs = 10000;
	ClientConfig.region = TCHAR_TO_UTF8(*Region);

	Credentials = Aws::Auth::AWSCredentials(TCHAR_TO_UTF8(*AccessKey), TCHAR_TO_UTF8(*Secret));
	return new Aws::GameLift::GameLiftClient(Credentials, ClientConfig);
#endif
}

UGameLiftClientObject* UGameLiftClientObject::CreateGameLiftObject(const FString& AccessKey, const FString& Secret, const FString& Region /*= "us-east-1"*/, bool bUsingGameLiftLocal /*= false*/, int32 LocalPort /*= 9080*/)
{
#if WITH_GAMELIFTCLIENTSDK
	UGameLiftClientObject* Proxy = NewObject<UGameLiftClientObject>();
	Proxy->Internal_InitGameLiftClientSDK(AccessKey, Secret, Region, bUsingGameLiftLocal, LocalPort);
	return Proxy;
#endif
	return nullptr;
}

UGameLiftCreateGameSession* UGameLiftClientObject::CreateGameSession(FGameLiftGameSessionConfig GameSessionProperties)
{
#if WITH_GAMELIFTCLIENTSDK
	UGameLiftCreateGameSession* Proxy = UGameLiftCreateGameSession::CreateGameSession(GameSessionProperties);
	return Proxy;
#endif
	return nullptr;
}

UGameLiftDescribeGameSession* UGameLiftClientObject::DescribeGameSession(FString GameSessionID)
{
#if WITH_GAMELIFTCLIENTSDK
	UGameLiftDescribeGameSession* Proxy = UGameLiftDescribeGameSession::DescribeGameSession(GameSessionID);
	return Proxy;
#endif
	return nullptr;
}

UGameLiftCreatePlayerSession* UGameLiftClientObject::CreatePlayerSession(FString GameSessionID, FString UniquePlayerID)
{
#if WITH_GAMELIFTCLIENTSDK
	UGameLiftCreatePlayerSession* Proxy = UGameLiftCreatePlayerSession::CreatePlayerSession(GameSessionID, UniquePlayerID);
	return Proxy;
#endif
	return nullptr;
}

UGameLiftStartMatchmaking* UGameLiftClientObject::StartMatchmaking(const FGameLiftMatchmakingRequest& Request)
{
#if WITH_GAMELIFTCLIENTSDK
	UGameLiftStartMatchmaking* Proxy = UGameLiftStartMatchmaking::StartMatchmaking(Request);
	return Proxy;
#endif
	return nullptr;
}

UGameLiftStopMatchmaking* UGameLiftClientObject::StopMatchmaking(const FString& TicketId)
{
#if WITH_GAMELIFTCLIENTSDK
	UGameLiftStopMatchmaking* Proxy = UGameLiftStopMatchmaking::StopMatchmaking(TicketId);
	return Proxy;
#endif
	return nullptr;
}

UGameLiftDescribeMatchmaking* UGameLiftClientObject::DescribeMatchmaking(const TArray<FString>& TicketIds)
{
#if WITH_GAMELIFTCLIENTSDK
	UGameLiftDescribeMatchmaking* Proxy = UGameLiftDescribeMatchmaking::DescribeMatchmaking(TicketIds);
	return Proxy;
#endif
	return nullptr;
}

UGameLiftAcceptMatch* UGameLiftClientObject::AcceptMatch(const TArray<FString>& PlayerIds, const FString& TicketId)
{
#if WITH_GAMELIFTCLIENTSDK
	UGameLiftAcceptMatch* Proxy = UGameLiftAcceptMatch::AcceptMatch(Aws::GameLift::Model::AcceptanceType::ACCEPT, PlayerIds, TicketId);
	return Proxy;
#endif
	return nullptr;
}

UGameLiftAcceptMatch* UGameLiftClientObject::RejectMatch(const TArray<FString>& PlayerIds, const FString& TicketId)
{
#if WITH_GAMELIFTCLIENTSDK
	UGameLiftAcceptMatch* Proxy = UGameLiftAcceptMatch::AcceptMatch(Aws::GameLift::Model::AcceptanceType::REJECT, PlayerIds, TicketId);
	return Proxy;
#endif
	return nullptr;
}