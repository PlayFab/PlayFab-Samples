#pragma once

#include "OnlineManager.h"

#include <json/value.h>
#include <playfab/PlayFabClientDataModels.h>

namespace ThunderRumble
{

    class PlayFabManager : public OnlineManager
    {
    public:
        PlayFabManager();
        ~PlayFabManager();

        virtual void Initialize() override;
        virtual void SignIn(std::function<void(bool, std::wstring&)> callback) override;
        virtual void BeginMultiplayer(std::function<void(bool, std::wstring&)> callback) override;
        virtual void Tick() override;

        const PlayFab::ClientModels::LoginResult& GetLoginResult() const { return m_loginResult; }

        virtual void UpdateStatistic(const std::wstring &name, int value, const Json::Value &metadata = Json::Value()) override;
        virtual void SendTelemetry(const std::wstring &eventName, const Json::Value &payload) override;

    private:
        PlayFab::ClientModels::LoginResult  m_loginResult;
        PlayFab::ClientModels::EntityKey  m_entityKey;

        //PlayFab::EventsModels::WriteEventsRequest m_eventsRequest;
    };

}
