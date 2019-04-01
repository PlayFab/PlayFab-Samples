//--------------------------------------------------------------------------------------
// PlayfabManager.h
//
// Advanced Technology Group (ATG)
// Copyright (C) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.
//--------------------------------------------------------------------------------------

#pragma once

#include "OnlineManager.h"

#include "playfab\PlayFabClientDataModels.h"
#include "playfab\PlayFabAuthenticationDataModels.h"
#include "playfab\PlayFabEventsDataModels.h"
#include "playfab\PlayFabMultiplayerDataModels.h"


namespace BumbleRumble
{

enum class MatchmakingStatus
{
    NotMatching,
    Matching,
    MatchingComplete,
    CancellingMatch,
    MatchingFailed
};

class PlayFabManager : public OnlineManager
{
public:
    PlayFabManager();
    ~PlayFabManager();

    virtual void Initialize() override;
    virtual void SignIn(std::function<void(bool, std::string&)> callback) override;
    virtual void BeginMultiplayer(const std::string &queueName, int timeout) override;
    virtual void Tick() override;

    virtual void UpdateStatistic(const std::string &name, int value, const Json::Value &metadata = Json::Value()) override;
    virtual void SendTelemetry(const std::string &eventName, const Json::Value &payload) override;

    inline MatchmakingStatus MatchStatus() { return m_matchStatus; }
    inline const std::string& MatchError() { return m_matchError; }

    std::vector<std::string> MatchPlayerIds();

    bool IsGameHost();
    std::string& EntityId() { return m_entityKey.Id; }
    std::string& EntityToken() { return m_entityToken; }
    void GetHostNetwork(std::function<void(std::string)> callback);
    void WriteHostNetwork(std::string network);
    void ClearHostNetwork();
    void CancelMatchmaking();

private:
    void RetrieveMatchResults();
    void PollMatchmaking();

    PlayFab::ClientModels::LoginResult  m_loginResult;
    PlayFab::ClientModels::EntityKey  m_entityKey;
    std::string m_entityToken;
    std::string m_playfabId;
    std::vector<PlayFab::MultiplayerModels::EntityKey> m_matchedPlayers;

    bool m_polling;
    DX::StepTimer m_matchTimer;
    std::string m_ticketId;
    std::string m_matchId;
    std::string m_matchQueue;
    std::string m_matchError;
    MatchmakingStatus m_matchStatus;
};

}
