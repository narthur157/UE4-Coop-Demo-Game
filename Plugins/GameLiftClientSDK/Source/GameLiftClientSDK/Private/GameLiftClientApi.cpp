// Created by YetiTech Studios.
//Extended, modified, rearchitected, and made, you know, usable, by Al Paca
#include "GameLiftClientApi.h"
#include "GameLiftClientObject.h"
#include "GameLiftClientGlobals.h"
#include "Async.h"

#if WITH_GAMELIFTCLIENTSDK
#include "aws/gamelift/model/DescribeGameSessionDetailsRequest.h"
#include "aws/gamelift/GameLiftClient.h"
#include "aws/core/utils/Outcome.h"
#include "aws/core/auth/AWSCredentialsProvider.h"
#include "aws/gamelift/model/GameProperty.h"
#include "aws/gamelift/model/SearchGameSessionsRequest.h"
#include "aws/gamelift/model/CreatePlayerSessionRequest.h"
#include "aws/gamelift/model/CreateGameSessionRequest.h"
#include "aws/gamelift/model/StartMatchmakingRequest.h"
#include "aws/gamelift/model/StopMatchmakingRequest.h"
#include "aws/gamelift/model/DescribeMatchmakingRequest.h"
#include "aws/gamelift/model/AcceptMatchRequest.h"
#include <aws/core/http/HttpRequest.h>
#endif

UGameLiftCreateGameSession* UGameLiftCreateGameSession::CreateGameSession(FGameLiftGameSessionConfig GameSessionProperties)
{
#if WITH_GAMELIFTCLIENTSDK
	UGameLiftCreateGameSession* Proxy = NewObject<UGameLiftCreateGameSession>();
	Proxy->SessionConfig = GameSessionProperties;
	return Proxy;
#endif
	return nullptr;
}

EActivateStatus UGameLiftCreateGameSession::Activate()
{
#if WITH_GAMELIFTCLIENTSDK
	LOG_NORMAL("Preparing to create game session...");
	std::unique_ptr<Aws::GameLift::GameLiftClient> GameLiftClient(UGameLiftClientObject::Client());
	if (!OnCreateGameSessionSuccess.IsBound())
	{
		LOG_ERROR("No functions were bound to OnCreateGameSessionSuccess multi-cast delegate! Aborting Activate.");
		return EActivateStatus::ACTIVATE_NoSuccessCallback;
	}

	if (!OnCreateGameSessionFailed.IsBound())
	{
		LOG_ERROR("No functions were bound to OnCreateGameSessionFailed multi-cast delegate! Aborting Activate.");
		return EActivateStatus::ACTIVATE_NoFailCallback;
	}

	Aws::GameLift::Model::CreateGameSessionRequest GameSessionRequest;

	GameSessionRequest.SetMaximumPlayerSessionCount(SessionConfig.GetMaxPlayers());

	for (FGameLiftGameSessionServerProperties ServerSetting : SessionConfig.GetGameSessionProperties())
	{
		LOG_NORMAL("********************************************************************");
		Aws::GameLift::Model::GameProperty MapProperty;
		MapProperty.SetKey(TCHAR_TO_UTF8(*ServerSetting.Key));
		MapProperty.SetValue(TCHAR_TO_UTF8(*ServerSetting.Value));
		GameSessionRequest.AddGameProperties(MapProperty);
		LOG_NORMAL(FString::Printf(TEXT("New GameProperty added. Key: (%s) Value: (%s)"), *ServerSetting.Key, *ServerSetting.Value));
	}

	Aws::GameLift::CreateGameSessionResponseReceivedHandler Handler;
	Handler = std::bind(&UGameLiftCreateGameSession::OnCreateGameSession, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4);

	LOG_NORMAL("Starting game session...");
	GameLiftClient->CreateGameSessionAsync(GameSessionRequest, Handler);
	return EActivateStatus::ACTIVATE_Success;
#endif
	return EActivateStatus::ACTIVATE_NoGameLift;
}

void UGameLiftCreateGameSession::OnCreateGameSession(const Aws::GameLift::GameLiftClient* Client, const Aws::GameLift::Model::CreateGameSessionRequest& Request, const Aws::GameLift::Model::CreateGameSessionOutcome& Outcome, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& Context)
{
#if WITH_GAMELIFTCLIENTSDK
	AsyncTask(ENamedThreads::GameThread, [=]()
	{
		if (Outcome.IsSuccess())
		{
			LOG_NORMAL("Received OnCreateGameSession with Success outcome.");
			const FString GameSessionID = FString(Outcome.GetResult().GetGameSession().GetGameSessionId().c_str());
			OnCreateGameSessionSuccess.Broadcast(GameSessionID);
		}
		else
		{
			const FString MyErrorMessage = FString(Outcome.GetError().GetMessage().c_str());
			LOG_ERROR("Received OnCreateGameSession with failed outcome. Error: " + MyErrorMessage);
			OnCreateGameSessionFailed.Broadcast(MyErrorMessage);
		}
	});
#endif
}

UGameLiftDescribeGameSession* UGameLiftDescribeGameSession::DescribeGameSession(FString GameSessionID)
{
#if WITH_GAMELIFTCLIENTSDK
	UGameLiftDescribeGameSession* Proxy = NewObject<UGameLiftDescribeGameSession>();
	Proxy->SessionID = GameSessionID;
	return Proxy;
#endif
	return nullptr;
}

EActivateStatus UGameLiftDescribeGameSession::Activate()
{
#if WITH_GAMELIFTCLIENTSDK
	LOG_NORMAL("Preparing to describe game session...");
	std::unique_ptr<Aws::GameLift::GameLiftClient> GameLiftClient(UGameLiftClientObject::Client());
	if (!OnDescribeGameSessionStateSuccess.IsBound())
	{
		LOG_ERROR("No functions were bound to OnDescribeGameSessionStateSuccess multi-cast delegate! Aborting Activate.");
		return EActivateStatus::ACTIVATE_NoSuccessCallback;
	}

	if (!OnDescribeGameSessionStateFailed.IsBound())
	{
		LOG_ERROR("No functions were bound to OnDescribeGameSessionStateFailed multi-cast delegate! Aborting Activate.");
		return EActivateStatus::ACTIVATE_NoFailCallback;
	}

	Aws::GameLift::Model::DescribeGameSessionDetailsRequest Request;
	Request.SetGameSessionId(TCHAR_TO_UTF8(*SessionID));

	Aws::GameLift::DescribeGameSessionDetailsResponseReceivedHandler Handler;
	Handler = std::bind(&UGameLiftDescribeGameSession::OnDescribeGameSessionState, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4);

	LOG_NORMAL("Requesting to describe game session with ID: " + SessionID);
	GameLiftClient->DescribeGameSessionDetailsAsync(Request, Handler);
	return EActivateStatus::ACTIVATE_Success;
#endif
	return EActivateStatus::ACTIVATE_NoGameLift;
}

void UGameLiftDescribeGameSession::OnDescribeGameSessionState(const Aws::GameLift::GameLiftClient* Client, const Aws::GameLift::Model::DescribeGameSessionDetailsRequest& Request, const Aws::GameLift::Model::DescribeGameSessionDetailsOutcome& Outcome, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& Context)
{
#if WITH_GAMELIFTCLIENTSDK
	AsyncTask(ENamedThreads::GameThread, [=]()
	{
		if (Outcome.IsSuccess())
		{
			LOG_NORMAL("Received OnDescribeGameSessionState with Success outcome.");
			const FString MySessionID = FString(Outcome.GetResult().GetGameSessionDetails().data()->GetGameSession().GetGameSessionId().c_str());
			EGameLiftGameSessionStatus MySessionStatus = GetSessionState(Outcome.GetResult().GetGameSessionDetails().data()->GetGameSession().GetStatus());
			OnDescribeGameSessionStateSuccess.Broadcast(MySessionID, MySessionStatus);
		}
		else
		{
			const FString MyErrorMessage = FString(Outcome.GetError().GetMessage().c_str());
			LOG_ERROR("Received OnDescribeGameSessionState with failed outcome. Error: " + MyErrorMessage);
			OnDescribeGameSessionStateFailed.Broadcast(MyErrorMessage);
		}
	});
#endif
}

EGameLiftGameSessionStatus UGameLiftDescribeGameSession::GetSessionState(const Aws::GameLift::Model::GameSessionStatus& Status)
{
#if WITH_GAMELIFTCLIENTSDK
	switch (Status)
	{
		case Aws::GameLift::Model::GameSessionStatus::ACTIVATING:
			return EGameLiftGameSessionStatus::STATUS_Activating;
		case Aws::GameLift::Model::GameSessionStatus::ACTIVE:
			return EGameLiftGameSessionStatus::STATUS_Active;
		case Aws::GameLift::Model::GameSessionStatus::ERROR_:
			return EGameLiftGameSessionStatus::STATUS_Error;
		case Aws::GameLift::Model::GameSessionStatus::NOT_SET:
			return EGameLiftGameSessionStatus::STATUS_NotSet;
		case Aws::GameLift::Model::GameSessionStatus::TERMINATED:
			return EGameLiftGameSessionStatus::STATUS_Terminated;
		case Aws::GameLift::Model::GameSessionStatus::TERMINATING:
			return EGameLiftGameSessionStatus::STATUS_Terminating;
		default:
			break;
	}
	checkNoEntry(); // This code block should never reach!
#endif
	return EGameLiftGameSessionStatus::STATUS_NoStatus; // Just a dummy return
}

UGameLiftCreatePlayerSession* UGameLiftCreatePlayerSession::CreatePlayerSession(FString GameSessionID, FString UniquePlayerID)
{
#if WITH_GAMELIFTCLIENTSDK
	UGameLiftCreatePlayerSession* Proxy = NewObject<UGameLiftCreatePlayerSession>();
	Proxy->GameSessionID = GameSessionID;
	Proxy->PlayerID = UniquePlayerID;
	return Proxy;
#endif
	return nullptr;
}

EActivateStatus UGameLiftCreatePlayerSession::Activate()
{
#if WITH_GAMELIFTCLIENTSDK
	LOG_NORMAL("Preparing to create player session...");
	std::unique_ptr<Aws::GameLift::GameLiftClient> GameLiftClient(UGameLiftClientObject::Client());
	if (!OnCreatePlayerSessionSuccess.IsBound())
	{
		LOG_ERROR("No functions were bound to OnCreatePlayerSessionSuccess multi-cast delegate! Aborting Activate.");
		return EActivateStatus::ACTIVATE_NoSuccessCallback;
	}

	if (!OnCreatePlayerSessionFailed.IsBound())
	{
		LOG_ERROR("No functions were bound to OnCreatePlayerSessionFailed multi-cast delegate! Aborting Activate.");
		return EActivateStatus::ACTIVATE_NoFailCallback;
	}

	Aws::GameLift::Model::CreatePlayerSessionRequest Request;
	LOG_NORMAL("Setting game session ID: " + GameSessionID);
	Request.SetGameSessionId(TCHAR_TO_UTF8(*GameSessionID));
	LOG_NORMAL("Setting player ID: " + PlayerID);
	Request.SetPlayerId(TCHAR_TO_UTF8(*PlayerID));

	Aws::GameLift::CreatePlayerSessionResponseReceivedHandler Handler;
	Handler = std::bind(&UGameLiftCreatePlayerSession::OnCreatePlayerSession, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4);

	LOG_NORMAL("Creating new player session...");
	GameLiftClient->CreatePlayerSessionAsync(Request, Handler);
	return EActivateStatus::ACTIVATE_Success;
#endif
	return EActivateStatus::ACTIVATE_NoGameLift;
}

void UGameLiftCreatePlayerSession::OnCreatePlayerSession(const Aws::GameLift::GameLiftClient* Client, const Aws::GameLift::Model::CreatePlayerSessionRequest& Request, const Aws::GameLift::Model::CreatePlayerSessionOutcome& Outcome, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& Context)
{
#if WITH_GAMELIFTCLIENTSDK
	AsyncTask(ENamedThreads::GameThread, [=]()
	{
		if (Outcome.IsSuccess())
		{
			LOG_NORMAL("Received OnCreatePlayerSession with Success outcome.");
			const FString ServerIpAddress = FString(Outcome.GetResult().GetPlayerSession().GetIpAddress().c_str());
			const FString ServerPort = FString::FromInt(Outcome.GetResult().GetPlayerSession().GetPort());
			const FString MyPlayerSessionID = FString(Outcome.GetResult().GetPlayerSession().GetPlayerSessionId().c_str());
			OnCreatePlayerSessionSuccess.Broadcast(ServerIpAddress, ServerPort, MyPlayerSessionID);
		}
		else
		{
			const FString MyErrorMessage = FString(Outcome.GetError().GetMessage().c_str());
			LOG_ERROR("Received OnCreatePlayerSession with failed outcome. Error: " + MyErrorMessage);
			OnCreatePlayerSessionFailed.Broadcast(MyErrorMessage);
		}
	});
#endif
}

UGameLiftStartMatchmaking* UGameLiftStartMatchmaking::StartMatchmaking(const FGameLiftMatchmakingRequest& Request)
{
#if WITH_GAMELIFTCLIENTSDK
	UGameLiftStartMatchmaking* Proxy = NewObject<UGameLiftStartMatchmaking>();
	Proxy->MatchmakingRequest = Request;
	return Proxy;
#endif
	return nullptr;
}

EActivateStatus UGameLiftStartMatchmaking::Activate()
{
#if WITH_GAMELIFTCLIENTSDK
	LOG_NORMAL("Preparing to start matchmaking...");
	std::unique_ptr<Aws::GameLift::GameLiftClient> GameLiftClient(UGameLiftClientObject::Client());
	if (!OnStartMatchmakingSuccess.IsBound())
	{
		LOG_ERROR("No functions were bound to OnStartMatchmakingSuccess multi-cast delegate! Aborting Activate.");
		return EActivateStatus::ACTIVATE_NoSuccessCallback;
	}

	if (!OnStartMatchmakingFailed.IsBound())
	{
		LOG_ERROR("No functions were bound to OnStartMatchmakingFailed multi-cast delegate! Aborting Activate.");
		return EActivateStatus::ACTIVATE_NoFailCallback;
	}

	Aws::GameLift::Model::StartMatchmakingRequest Request;
	Request.SetConfigurationName(TCHAR_TO_UTF8(*MatchmakingRequest.ConfigurationName));
	Request.SetTicketId(TCHAR_TO_UTF8(*FGuid::NewGuid().ToString()));
	for (const FGameLiftPlayer& Player : MatchmakingRequest.Players)
	{
		Aws::GameLift::Model::Player AwsPlayer;
		AwsPlayer.SetPlayerId(TCHAR_TO_UTF8(*Player.PlayerId));
		AwsPlayer.SetTeam("dawn");
		Aws::Map<Aws::String, int> Latency;
		Latency.insert(std::pair<Aws::String, int>(Aws::String("us-east-1"), Player.LatencyMilliseconds));
		AwsPlayer.SetLatencyInMs(Latency);
		Aws::GameLift::Model::AttributeValue EloAttributeValue;
		EloAttributeValue.SetN(Player.Elo);
		AwsPlayer.AddPlayerAttributes("elo", EloAttributeValue);
		Request.AddPlayers(AwsPlayer);
	}

	Aws::GameLift::StartMatchmakingResponseReceivedHandler Handler;
	Handler = std::bind(&UGameLiftStartMatchmaking::OnStartMatchmaking, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4);

	LOG_NORMAL("Starting matchmaking...");
	GameLiftClient->StartMatchmakingAsync(Request, Handler);
	return EActivateStatus::ACTIVATE_Success;
#endif
	return EActivateStatus::ACTIVATE_NoGameLift;
}

void UGameLiftStartMatchmaking::OnStartMatchmaking(const Aws::GameLift::GameLiftClient* Client, const Aws::GameLift::Model::StartMatchmakingRequest& Request, const Aws::GameLift::Model::StartMatchmakingOutcome& Outcome, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& Context)
{
#if WITH_GAMELIFTCLIENTSDK
	AsyncTask(ENamedThreads::GameThread, [=]()
	{
		if (Outcome.IsSuccess())
		{
			const Aws::GameLift::Model::MatchmakingTicket ReceivedTicket = Outcome.GetResult().GetMatchmakingTicket();
			LOG_NORMAL("Received OnStartMatchmaking with Success outcome.");
			FGameLiftMatchmakingResponseTicket Ticket(ReceivedTicket);
			OnStartMatchmakingSuccess.Broadcast(Ticket);
		}
		else
		{
			const FString ErrorMessage = FString(Outcome.GetError().GetMessage().c_str());
			LOG_ERROR("Received OnStartMatchmaking with failed outcome. Error: " + ErrorMessage);
			OnStartMatchmakingFailed.Broadcast(ErrorMessage);
		}
	});
#endif
}

FGameLiftMatchmakingResponseTicket::FGameLiftMatchmakingResponseTicket(const Aws::GameLift::Model::MatchmakingTicket& Ticket)
{
#if WITH_GAMELIFTCLIENTSDK
	ConfigurationName = FString(Ticket.GetConfigurationName().c_str());
	EndTime = (float)(Ticket.GetEndTime().CurrentTimeMillis());
	EstimatedWaitTime = Ticket.GetEstimatedWaitTime();
	GameSessionConnectionInfo.GameSessionArn = FString(Ticket.GetGameSessionConnectionInfo().GetGameSessionArn().c_str());
	GameSessionConnectionInfo.IpAddress = FString(Ticket.GetGameSessionConnectionInfo().GetIpAddress().c_str());
	GameSessionConnectionInfo.Port = Ticket.GetGameSessionConnectionInfo().GetPort();
	for (const Aws::GameLift::Model::MatchedPlayerSession& PlayerSession : Ticket.GetGameSessionConnectionInfo().GetMatchedPlayerSessions())
	{
		FGameLiftMatchedPlayerSession Session;
		Session.PlayerId = FString(PlayerSession.GetPlayerId().c_str());
		Session.PlayerSessionId = FString(PlayerSession.GetPlayerSessionId().c_str());
		GameSessionConnectionInfo.MatchedPlayerSessions.Emplace(Session);
	}
	for (const Aws::GameLift::Model::Player& AwsPlayer : Ticket.GetPlayers())
	{
		FGameLiftPlayer Player;
		FString Key = "elo";
		Player.Elo = AwsPlayer.GetPlayerAttributes().at(Aws::String(TCHAR_TO_UTF8(*Key))).GetN();
		Player.LatencyMilliseconds = AwsPlayer.GetLatencyInMs().at(Aws::String("us-east-1"));
		Player.PlayerId = FString(AwsPlayer.GetPlayerId().c_str());
		Players.Emplace(Player);
	}
	switch (Ticket.GetStatus())
	{
	case Aws::GameLift::Model::MatchmakingConfigurationStatus::QUEUED: Status = EGameLiftMatchmakingTicketStatus::QUEUED; break;
	case Aws::GameLift::Model::MatchmakingConfigurationStatus::SEARCHING: Status = EGameLiftMatchmakingTicketStatus::SEARCHING; break;
	case Aws::GameLift::Model::MatchmakingConfigurationStatus::REQUIRES_ACCEPTANCE: Status = EGameLiftMatchmakingTicketStatus::REQUIRES_ACCEPTANCE; break;
	case Aws::GameLift::Model::MatchmakingConfigurationStatus::PLACING: Status = EGameLiftMatchmakingTicketStatus::PLACING; break;
	case Aws::GameLift::Model::MatchmakingConfigurationStatus::COMPLETED: Status = EGameLiftMatchmakingTicketStatus::COMPLETED; break;
	case Aws::GameLift::Model::MatchmakingConfigurationStatus::FAILED: Status = EGameLiftMatchmakingTicketStatus::FAILED; break;
	case Aws::GameLift::Model::MatchmakingConfigurationStatus::CANCELLED: Status = EGameLiftMatchmakingTicketStatus::CANCELLED; break;
	case Aws::GameLift::Model::MatchmakingConfigurationStatus::TIMED_OUT: Status = EGameLiftMatchmakingTicketStatus::TIMED_OUT; break;
	}
	StatusMessage = FString(Ticket.GetStatusMessage().c_str());
	StatusReason = FString(Ticket.GetStatusReason().c_str());
	TicketId = FString(Ticket.GetTicketId().c_str());
#endif
}

UGameLiftStopMatchmaking* UGameLiftStopMatchmaking::StopMatchmaking(const FString& TicketId)
{
#if WITH_GAMELIFTCLIENTSDK
	UGameLiftStopMatchmaking* Proxy = NewObject<UGameLiftStopMatchmaking>();
	Proxy->TicketId = TicketId;
	return Proxy;
#endif
	return nullptr;
}

EActivateStatus UGameLiftStopMatchmaking::Activate()
{
#if WITH_GAMELIFTCLIENTSDK
	LOG_NORMAL("Preparing to stop matchmaking...");
	std::unique_ptr<Aws::GameLift::GameLiftClient> GameLiftClient(UGameLiftClientObject::Client());
	if (!OnStopMatchmakingSuccess.IsBound())
	{
		LOG_ERROR("No functions were bound to OnStopMatchmakingSuccess multi-cast delegate! Aborting Activate.");
		return EActivateStatus::ACTIVATE_NoSuccessCallback;
	}

	if (!OnStopMatchmakingFailed.IsBound())
	{
		LOG_ERROR("No functions were bound to OnStopMatchmakingFailed multi-cast delegate! Aborting Activate.");
		return EActivateStatus::ACTIVATE_NoFailCallback;
	}

	Aws::GameLift::Model::StopMatchmakingRequest Request;
	Request.SetTicketId(TCHAR_TO_UTF8(*TicketId));

	Aws::GameLift::StopMatchmakingResponseReceivedHandler Handler;
	Handler = std::bind(&UGameLiftStopMatchmaking::OnStopMatchmaking, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4);

	LOG_NORMAL("Stopping matchmaking...");
	GameLiftClient->StopMatchmakingAsync(Request, Handler);
	return EActivateStatus::ACTIVATE_Success;
#endif
	return EActivateStatus::ACTIVATE_NoGameLift;
}

void UGameLiftStopMatchmaking::OnStopMatchmaking(const Aws::GameLift::GameLiftClient* Client, const Aws::GameLift::Model::StopMatchmakingRequest& Request, const Aws::GameLift::Model::StopMatchmakingOutcome& Outcome, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& Context)
{
#if WITH_GAMELIFTCLIENTSDK
	AsyncTask(ENamedThreads::GameThread, [=]()
	{
		if (Outcome.IsSuccess())
		{
			LOG_NORMAL("Received OnStopMatchmaking with Success outcome.");
			OnStopMatchmakingSuccess.Broadcast();
		}
		else
		{
			const FString ErrorMessage = FString(Outcome.GetError().GetMessage().c_str());
			LOG_ERROR("Received OnStopMatchmaking with failed outcome. Error: " + ErrorMessage);
			OnStopMatchmakingFailed.Broadcast(ErrorMessage);
		}
	});
#endif
}

UGameLiftDescribeMatchmaking* UGameLiftDescribeMatchmaking::DescribeMatchmaking(const TArray<FString>& TicketIds)
{
#if WITH_GAMELIFTCLIENTSDK
	UGameLiftDescribeMatchmaking* Proxy = NewObject<UGameLiftDescribeMatchmaking>();
	Proxy->TicketIds = TicketIds;
	return Proxy;
#endif
	return nullptr;
}

EActivateStatus UGameLiftDescribeMatchmaking::Activate()
{
#if WITH_GAMELIFTCLIENTSDK
	LOG_NORMAL("Preparing to describe matchmaking...");
	std::unique_ptr<Aws::GameLift::GameLiftClient> GameLiftClient(UGameLiftClientObject::Client());
	if (!OnDescribeMatchmakingSuccess.IsBound())
	{
		LOG_ERROR("No functions were bound to OnDescribeMatchmakingSuccess multi-cast delegate! Aborting Activate.");
		return EActivateStatus::ACTIVATE_NoSuccessCallback;
	}

	if (!OnDescribeMatchmakingFailed.IsBound())
	{
		LOG_ERROR("No functions were bound to OnDescribeMatchmakingFailed multi-cast delegate! Aborting Activate.");
		return EActivateStatus::ACTIVATE_NoFailCallback;
	}

	if (TicketIds.Num() > 10)
	{
		FString Message = "GameLiftClient::DescribeMatchmaking() only allows up to 10 ticket ids per request!";
		LOG_ERROR(Message);
		OnDescribeMatchmakingFailed.Broadcast(Message);
		return EActivateStatus::ACTIVATE_NoGameLift; //I didn't want to add another enum entry just for this case, so roll with this return value.
	}

	Aws::GameLift::Model::DescribeMatchmakingRequest Request;
	for (const FString& TicketId : TicketIds)
	{
		Request.AddTicketIds(TCHAR_TO_UTF8(*TicketId));
	}

	Aws::GameLift::DescribeMatchmakingResponseReceivedHandler Handler;
	Handler = std::bind(&UGameLiftDescribeMatchmaking::OnDescribeMatchmaking, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4);

	LOG_NORMAL("Describing matchmaking...");
	GameLiftClient->DescribeMatchmakingAsync(Request, Handler);
	return EActivateStatus::ACTIVATE_Success;
#endif
	return EActivateStatus::ACTIVATE_NoGameLift;
}

void UGameLiftDescribeMatchmaking::OnDescribeMatchmaking(const Aws::GameLift::GameLiftClient* Client, const Aws::GameLift::Model::DescribeMatchmakingRequest& Request, const Aws::GameLift::Model::DescribeMatchmakingOutcome& Outcome, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& Context)
{
#if WITH_GAMELIFTCLIENTSDK
	AsyncTask(ENamedThreads::GameThread, [=]()
	{
		if (Outcome.IsSuccess())
		{
			LOG_NORMAL("Received OnDescribeMatchmaking with Success outcome.");
			TArray<FGameLiftMatchmakingResponseTicket> Tickets;
			for (const Aws::GameLift::Model::MatchmakingTicket& ReceivedTicket : Outcome.GetResult().GetTicketList())
			{
				FGameLiftMatchmakingResponseTicket Ticket(ReceivedTicket);
				Tickets.Emplace(Ticket);
			}
			OnDescribeMatchmakingSuccess.Broadcast(Tickets);
		}
		else
		{
			const FString ErrorMessage = FString(Outcome.GetError().GetMessage().c_str());
			LOG_ERROR("Received OnDescribeMatchmaking with failed outcome. Error: " + ErrorMessage);
			OnDescribeMatchmakingFailed.Broadcast(ErrorMessage);
		}
	});
#endif
}

UGameLiftAcceptMatch* UGameLiftAcceptMatch::AcceptMatch(const Aws::GameLift::Model::AcceptanceType& AcceptanceType, const TArray<FString>& PlayerIds, const FString& TicketId)
{
#if WITH_GAMELIFTCLIENTSDK
	UGameLiftAcceptMatch* Proxy = NewObject<UGameLiftAcceptMatch>();
	Proxy->AcceptanceType = AcceptanceType;
	Proxy->PlayerIds = PlayerIds;
	Proxy->TicketId = TicketId;
	return Proxy;
#endif
	return nullptr;
}

EActivateStatus UGameLiftAcceptMatch::Activate()
{
#if WITH_GAMELIFTCLIENTSDK
	LOG_NORMAL("Preparing to accept/reject match...");
	std::unique_ptr<Aws::GameLift::GameLiftClient> GameLiftClient(UGameLiftClientObject::Client());
	if (!OnAcceptMatchSuccess.IsBound())
	{
		LOG_ERROR("No functions were bound to OnAcceptMatchSuccess multi-cast delegate! Aborting Activate.");
		return EActivateStatus::ACTIVATE_NoSuccessCallback;
	}

	if (!OnAcceptMatchFailed.IsBound())
	{
		LOG_ERROR("No functions were bound to OnAcceptMatchFailed multi-cast delegate! Aborting Activate.");
		return EActivateStatus::ACTIVATE_NoFailCallback;
	}

	Aws::GameLift::Model::AcceptMatchRequest Request;
	Request.SetAcceptanceType(AcceptanceType);
	Request.SetTicketId(TCHAR_TO_UTF8(*TicketId));
	for (const FString& PlayerId : PlayerIds)
	{
		Request.AddPlayerIds(TCHAR_TO_UTF8(*PlayerId));
	}

	Aws::GameLift::AcceptMatchResponseReceivedHandler Handler;
	Handler = std::bind(&UGameLiftAcceptMatch::OnAcceptMatch, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4);

	LOG_NORMAL("Accepting/rejecting match...");
	GameLiftClient->AcceptMatchAsync(Request, Handler);
	return EActivateStatus::ACTIVATE_Success;
#endif
	return EActivateStatus::ACTIVATE_NoGameLift;
}

void UGameLiftAcceptMatch::OnAcceptMatch(const Aws::GameLift::GameLiftClient* Client, const Aws::GameLift::Model::AcceptMatchRequest& Request, const Aws::GameLift::Model::AcceptMatchOutcome& Outcome, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& Context)
{
#if WITH_GAMELIFTCLIENTSDK
	AsyncTask(ENamedThreads::GameThread, [=]()
	{
		if (Outcome.IsSuccess())
		{
			LOG_NORMAL("Received OnAcceptMatch with Success outcome.");
			OnAcceptMatchSuccess.Broadcast();
		}
		else
		{
			const FString ErrorMessage = FString(Outcome.GetError().GetMessage().c_str());
			LOG_ERROR("Received OnAcceptMatch with failed outcome. Error: " + ErrorMessage);
			OnAcceptMatchFailed.Broadcast(ErrorMessage);
		}
	});
#endif
}