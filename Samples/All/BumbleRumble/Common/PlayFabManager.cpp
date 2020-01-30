//--------------------------------------------------------------------------------------
// PlayfabManager.cpp
//
// Advanced Technology Group (ATG)
// Copyright (C) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.
//--------------------------------------------------------------------------------------

#include "pch.h"

#include "PlayFabManager.h"
#include "Managers.h"
#include "StepTimer.h"

#include "playfab\PlayFabClientApi.h"
#include "playfab\PlayFabApiSettings.h"
#include "playfab\PlayFabSettings.h"
#include "playfab\PlayFabAuthenticationApi.h"
#include "playfab\PlayFabEventsApi.h"
#include "playfab\PlayFabMultiplayerApi.h"
#include "playfab\PlayFabDataApi.h"

using namespace BumbleRumble;
using namespace PlayFab;
using namespace ClientModels;

extern const char* c_pfTitleId;

PlayFabManager::PlayFabManager() :
    m_matchStatus(MatchmakingStatus::NotMatching),
    m_polling(false)
{
}

PlayFabManager::~PlayFabManager()
{
}

void PlayFabManager::Initialize()
{
    PlayFabSettings::staticSettings->titleId = c_pfTitleId;

    m_matchTimer.SetTargetElapsedSeconds(13.0f);
    m_matchTimer.SetFixedTimeStep(true);
}

void PlayFabManager::SignIn(std::function<void(bool, std::string&)> callback)
{
    DEBUGLOG("PlayFabManager::SignIn()\n");

    auto userId = Managers::Get<GameStateManager>()->GetLocalPlayerName();

    LoginWithCustomIDRequest loginRequest;
    loginRequest.CreateAccount = true;
    loginRequest.CustomId = userId;

    GetPlayerCombinedInfoRequestParams reqParams;
    reqParams.GetUserAccountInfo = true;

    loginRequest.InfoRequestParameters = reqParams;

    PlayFabClientAPI::LoginWithCustomID(
        loginRequest,
        [this, callback, userId](const LoginResult& loginResult, void*)
        {
            m_playfabId = loginResult.PlayFabId;

            if (loginResult.EntityToken.notNull() && loginResult.EntityToken->Entity.notNull())
            {
                m_entityKey = loginResult.EntityToken->Entity;
                m_entityToken = loginResult.EntityToken->EntityToken;

                Managers::Get<GameStateManager>()->SetLocalPeerId(m_entityKey.Id);
            }

            ClearHostNetwork();

            std::string displayName;
            
            if (loginResult.InfoResultPayload.notNull() &&
                loginResult.InfoResultPayload->AccountInfo.notNull() &&
                loginResult.InfoResultPayload->AccountInfo->TitleInfo.notNull())
            {
                displayName = loginResult.InfoResultPayload->AccountInfo->TitleInfo->DisplayName;
            }

            if (displayName.empty())
            {
                // Set display name
                UpdateUserTitleDisplayNameRequest updateDisplayNameRequest;

                updateDisplayNameRequest.DisplayName = userId;

                PlayFabClientAPI::UpdateUserTitleDisplayName(
                    updateDisplayNameRequest,
                    [callback](const UpdateUserTitleDisplayNameResult&, void*)
                    {
                        if (callback != nullptr)
                        {
                            std::string message;

                            callback(true, message);
                        }
                    },
                    [callback](const PlayFabError& error, void*)
                    {
                        if (callback != nullptr)
                        {
                            std::string message(error.ErrorMessage);

                            callback(false, message);
                        }
                    });
            }
            else
            {
                // The user already has a display name set, trigger the success callback
                if (callback != nullptr)
                {
                    std::string message;

                    callback(true, message);
                }
            }
        },
        [callback](const PlayFabError& error, void*)
        {
            if (callback != nullptr)
            {
                std::string message(error.ErrorMessage);

                callback(false, message);
            }
        });
}

void PlayFabManager::BeginMultiplayer(const std::string &queueName, int timeout)
{
    DEBUGLOG("PlayFabManager::BeginMultiplayer('%hs', %d)\n", queueName.c_str(), timeout);

    if (m_matchStatus == MatchmakingStatus::Matching)
    {
        DEBUGLOG("BeginMultiplayer called while already matching\n");
        return;
    }

    m_matchStatus = MatchmakingStatus::Matching;

    MultiplayerModels::EntityKey entityKey;

    entityKey.Id = m_entityKey.Id;
    entityKey.Type = m_entityKey.Type;

    MultiplayerModels::MatchmakingPlayer player;

    player.Entity = entityKey;

    MultiplayerModels::CreateMatchmakingTicketRequest ticketRequest;

    ticketRequest.Creator = player;
    ticketRequest.GiveUpAfterSeconds = timeout;
    ticketRequest.QueueName = queueName;

    m_matchQueue = ticketRequest.QueueName;

    PlayFabMultiplayerAPI::CreateMatchmakingTicket(
        ticketRequest,
        [this](const MultiplayerModels::CreateMatchmakingTicketResult& result, void*)
        {
            DEBUGLOG("CreateMatchmakingTicket succeeded: %hs\n", result.TicketId.c_str());
            m_ticketId = result.TicketId;
            m_matchTimer.ResetElapsedTime();
        },
        [this](const PlayFabError& error, void*)
        {
            DEBUGLOG("CreateMatchmakingTicket failed: %hs\n", error.ErrorMessage.c_str());
            m_matchError = error.ErrorMessage;
            m_matchStatus = MatchmakingStatus::MatchingFailed;
        });
}

void PlayFabManager::PollMatchmaking()
{
    DEBUGLOG("PlayFabManager::PollMatchmaking()\n");

    if (m_matchStatus != MatchmakingStatus::Matching &&
        m_matchStatus != MatchmakingStatus::CancellingMatch)
    {
        DEBUGLOG("PollMatchmaking called when not matchmaking\n");
        return;
    }

    if (m_polling)
    {
        DEBUGLOG("Already polling...\n");
        return;
    }

    if (m_ticketId.empty() || m_matchQueue.empty())
    {
        DEBUGLOG("No ticket id or match queue to poll\n");
        return;
    }

    m_polling = true;

    MultiplayerModels::GetMatchmakingTicketRequest matchRequest;

    matchRequest.TicketId = m_ticketId;
    matchRequest.QueueName = m_matchQueue;

    PlayFabMultiplayerAPI::GetMatchmakingTicket(
        matchRequest,
        [this](const MultiplayerModels::GetMatchmakingTicketResult& result, void*)
        {
            // Check if the match was canceled
            if (!result.CancellationReasonString.empty())
            {
                m_matchError = "Canceled by " + result.CancellationReasonString;
                m_matchStatus = MatchmakingStatus::MatchingFailed;
            }
            else
            {
                // See if we have a match
                if (!result.MatchId.empty())
                {
                    m_matchId = result.MatchId;
                    RetrieveMatchResults();
                }
            }

            m_polling = false;
            DEBUGLOG("GetMatchmakingTicket Status: %hs\n", result.Status.c_str());
        },
        [this](const PlayFabError& error, void*)
        {
            DEBUGLOG("GetMatchmakingTicket failed: %hs\n", error.ErrorMessage.c_str());
            m_matchError = error.ErrorMessage;
            m_matchStatus = MatchmakingStatus::MatchingFailed;
            m_polling = false;
        });
}

void PlayFabManager::RetrieveMatchResults()
{
    DEBUGLOG("PlayFabManager::RetrieveMatchResults()\n");

    if (m_matchStatus != MatchmakingStatus::Matching || m_matchId.empty())
    {
        DEBUGLOG("RetrieveMatchResults called when no results available\n");
        return;
    }

    MultiplayerModels::GetMatchRequest matchRequest;

    matchRequest.MatchId = m_matchId;
    matchRequest.QueueName = m_matchQueue;

    PlayFabMultiplayerAPI::GetMatch(
        matchRequest,
        [this](const MultiplayerModels::GetMatchResult& result, void*)
        {
            DEBUGLOG("GetMatch succeeded\n");
            m_matchedPlayers.clear();

            for (const auto &member : result.Members)
            {
                m_matchedPlayers.push_back(member.Entity);
            }

            m_matchStatus = MatchmakingStatus::MatchingComplete;
        },
        [this](const PlayFabError& error, void*)
        {
            DEBUGLOG("GetMatch failed: %hs\n", error.ErrorMessage.c_str());
            m_matchError = error.ErrorMessage;
            m_matchStatus = MatchmakingStatus::MatchingFailed;
        });
}

void PlayFabManager::CancelMatchmaking()
{
    DEBUGLOG("PlayFabManager::CancelMatchmaking()\n");

    if (m_matchStatus == MatchmakingStatus::CancellingMatch)
    {
        DEBUGLOG("CancelMatchmaking called while already cancelling\n");
        return;
    }

    if (m_matchStatus != MatchmakingStatus::Matching)
    {
        DEBUGLOG("CancelMatchmaking called when not matchmaking\n");
        return;
    }

    m_matchStatus = MatchmakingStatus::CancellingMatch;

    MultiplayerModels::CancelMatchmakingTicketRequest cancelRequest;

    cancelRequest.TicketId = m_ticketId;
    cancelRequest.QueueName = m_matchQueue;

    PlayFabMultiplayerAPI::CancelMatchmakingTicket(
        cancelRequest,
        [this](const MultiplayerModels::CancelMatchmakingTicketResult&, void*)
        {
            DEBUGLOG("CancelMatchmakingTicket complete\n");
        },
        [this](const PlayFabError& error, void*)
        {
            DEBUGLOG("CancelMatchmakingTicket failed: %hs\n", error.ErrorMessage.c_str());
            m_matchError = error.ErrorMessage;
            m_matchStatus = MatchmakingStatus::MatchingFailed;
        });
}

bool PlayFabManager::IsGameHost()
{
    if (m_matchedPlayers.size() > 0)
    {
        if (m_matchedPlayers.at(0).Id == m_entityKey.Id)
        {
            return true;
        }
    }

    return false;
}

std::vector<std::string> PlayFabManager::MatchPlayerIds()
{
    std::vector<std::string> playerIds;

    for (const auto& player : m_matchedPlayers)
    {
        playerIds.push_back(player.Id);
    }

    return playerIds;
}

void PlayFabManager::GetHostNetwork(std::function<void(std::string, std::string)> callback)
{
    DEBUGLOG("PlayFabManager::GetHostNetwork()\n");

    if (m_matchedPlayers.size() == 0)
    {
        if (callback != nullptr)
        {
            std::string empty;
            callback(empty, empty);
        }

        return;
    }

    Json::Value param;

    param["entity"] = m_matchedPlayers.at(0).ToJson();

    ClientModels::ExecuteCloudScriptRequest request;

    request.FunctionName = "get_game_network";
    request.FunctionParameter = param;

    PlayFabClientAPI::ExecuteCloudScript(
        request,
        [callback](const ClientModels::ExecuteCloudScriptResult& result, void*)
        {
            std::string empty;

            if (result.Error.notNull())
            {
                DEBUGLOG("CloudScript error occured: %hs\n", result.Error->Message.c_str());
                if (callback != nullptr)
                {
                    callback(empty, empty);
                }
            }
            else
            {
                if (result.FunctionResult.empty())
                {
                    if (callback != nullptr)
                    {
                        callback(empty, empty);
                    }
                }
                else
                {
                    if (callback != nullptr)
                    {
                        auto network = result.FunctionResult["network"]["Value"].asString();
                        auto invite = result.FunctionResult["invite"]["Value"].asString();

                        DEBUGLOG("GetHostNetwork: %hs, %hs\n", invite.c_str(), network.c_str());
                        callback(invite, network);
                    }
                }
            }
        },
        [callback](const PlayFabError& error, void*)
        {
            DEBUGLOG("ExecuteCloudScript failed: %hs\n", error.ErrorMessage.c_str());
            if (callback != nullptr)
            {
                std::string empty;
                callback(empty, empty);
            }
        });
}

void PlayFabManager::WriteHostNetwork(std::string invite, std::string network)
{
    DEBUGLOG("PlayFabManager::WriteHostNetwork('%hs')\n", network.c_str());

    Json::Value param;

    param["entity"] = m_entityKey.ToJson();
    param["network"] = network;
    param["invite"] = invite;

    ClientModels::ExecuteCloudScriptRequest request;

    request.FunctionName = "set_game_network";
    request.FunctionParameter = param;

    PlayFabClientAPI::ExecuteCloudScript(
        request,
        [](const ClientModels::ExecuteCloudScriptResult& result, void*)
        {
            if (result.Error.notNull())
            {
                DEBUGLOG("CloudScript error occured: %hs\n", result.Error->Message.c_str());
            }
            else
            {
                DEBUGLOG("SetGameNetwork CloudScript succeeded\n");
            }
        },
        [](const PlayFabError& error, void*)
        {
            DEBUGLOG("ExecuteCloudScript failed: %hs\n", error.ErrorMessage.c_str());
        });
}

void PlayFabManager::ClearHostNetwork()
{
    DEBUGLOG("PlayFabManager::ClearHostNetwork()\n");

    Json::Value param;

    param["entity"] = m_entityKey.ToJson();

    ClientModels::ExecuteCloudScriptRequest request;

    request.FunctionName = "clear_game_network";
    request.FunctionParameter = param;

    PlayFabClientAPI::ExecuteCloudScript(
        request,
        [](const ClientModels::ExecuteCloudScriptResult& result, void*)
        {
            if (result.Error.notNull())
            {
                DEBUGLOG("CloudScript error occured: %hs\n", result.Error->Message.c_str());
            }
            else
            {
                DEBUGLOG("ClearGameNetwork CloudScript succeeded\n");
            }
        },
        [](const PlayFabError& error, void*)
        {
            DEBUGLOG("ExecuteCloudScript failed: %hs\n", error.ErrorMessage.c_str());
        });
}

void PlayFabManager::Tick()
{
    PlayFabClientAPI::Update();
    PlayFabMultiplayerAPI::Update();
    PlayFabDataAPI::Update();

    if (m_matchStatus == MatchmakingStatus::Matching ||
        m_matchStatus == MatchmakingStatus::CancellingMatch)
    {
        m_matchTimer.Tick([&]()
        {
            PollMatchmaking();
        });
    }
}

void PlayFabManager::UpdateStatistic(const std::string &name, int value, const Json::Value &metadata)
{
    Json::Value statistic;

    statistic["statistic_name"] = Json::Value(name.c_str());
    statistic["count"] = value;

    if (!metadata.isNull())
    {
        statistic["metadata"] = metadata;
    }

    SendTelemetry("nr_statistic_update", statistic);
}

void PlayFabManager::SendTelemetry(const std::string& /*eventName*/, const Json::Value &payload)
{
    PlayFab::ClientModels::WriteClientPlayerEventRequest request;
    request.EventName = "nr_statistic_update";

    request.Body = payload;

    PlayFab::PlayFabClientAPI::WritePlayerEvent(request, [](const WriteEventResponse& /*response*/, void *) {});
}
