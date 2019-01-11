#include "pch.h"

#include "PlayFabManager.h"
#include "Managers.h"

#include <playfab\PlayFabClientApi.h>
#include <playfab\PlayFabSettings.h>

using namespace ThunderRumble;
using namespace PlayFab;
using namespace ClientModels;

PlayFabManager::PlayFabManager()
{
}


PlayFabManager::~PlayFabManager()
{
}

void PlayFabManager::Initialize()
{
    PlayFabSettings::titleId = "<INSERT TITLE ID HERE>";
    PlayFab::PlayFabSettings::threadedCallbacks = true;
}

void PlayFabManager::SignIn(std::function<void(bool, std::wstring&)> callback)
{
    char szMachineName[MAX_COMPUTERNAME_LENGTH + 1];
    DWORD size = sizeof(szMachineName) / sizeof(szMachineName[0]);
    GetComputerNameA(szMachineName, &size);

    LoginWithCustomIDRequest loginRequest;
    loginRequest.CreateAccount = true;
    loginRequest.CustomId = szMachineName;

    PlayFabClientAPI::LoginWithCustomID(
        loginRequest,
        [this, callback, szMachineName](const LoginResult& loginResult, void*)
    {
        if (loginResult.EntityToken.notNull() && loginResult.EntityToken->Entity.notNull())
        {
            m_entityKey = loginResult.EntityToken->Entity;
        }

        // Get the player profile
        GetAccountInfoRequest getProfileRequest;
        getProfileRequest.PlayFabId = loginResult.PlayFabId;

        PlayFabClientAPI::GetAccountInfo(
            getProfileRequest,
            [this, callback, loginResult, szMachineName](const GetAccountInfoResult& getProfileResult, void*)
        {
            const std::string& displayName = getProfileResult.AccountInfo->TitleInfo->DisplayName;
            if (displayName.empty())
            {
                // Set display name
                UpdateUserTitleDisplayNameRequest updateDisplayNameRequest;
                updateDisplayNameRequest.DisplayName = szMachineName;

                PlayFabClientAPI::UpdateUserTitleDisplayName(
                    updateDisplayNameRequest,
                    [this, callback, loginResult](const UpdateUserTitleDisplayNameResult& /*updateDisplayNameResult*/, void*)
                {
                    // Trigger callback when we have successfully updated the players display name
                    m_loginResult = loginResult;

                    if (callback != nullptr)
                    {
                        std::wstring message;

                        callback(true, message);
                    }
                },
                    [callback](const PlayFabError& error, void*)
                {
                    if (callback != nullptr)
                    {
                        std::wstring message;
                        message = std::wstring(error.ErrorMessage.begin(), error.ErrorMessage.end());

                        callback(false, message);
                    }
                });
            }
            else
            {
                // The user already has a display name set, trigger the success callback
                m_loginResult = loginResult;

                if (callback != nullptr)
                {
                    std::wstring message;

                    callback(true, message);
                }
            }
        },
            [callback](const PlayFabError& error, void*)
        {
            if (callback != nullptr)
            {
                std::wstring message;
                message = std::wstring(error.ErrorMessage.begin(), error.ErrorMessage.end());

                callback(false, message);
            }
        });
    },
        [callback](const PlayFabError& error, void*)
    {
        if (callback != nullptr)
        {
            std::wstring message;
            message = std::wstring(error.ErrorMessage.begin(), error.ErrorMessage.end());

            callback(false, message);
        }
    });
}

void PlayFabManager::BeginMultiplayer(std::function<void(bool, std::wstring&)> callback)
{
    if (callback != nullptr)
    {
        std::wstring message;

        callback(true, message);
    }
}

void PlayFabManager::Tick()
{
    // EntityAPI Events dont seem to work with cloud scripts right now...leaving this in for when they do.
    /*if (!m_eventsRequest.Events.empty())
    {
        PlayFab::PlayFabEventsAPI::WriteEvents(m_eventsRequest, [](const PlayFab::EventsModels::WriteEventsResponse &response, void*)
        {
        });
        m_eventsRequest.Events.clear();

    }*/
}

void PlayFabManager::UpdateStatistic(const std::wstring &name, int value, const Json::Value &metadata)
{
    Json::Value statistic;

    statistic["statistic_name"] = Json::Value(name.c_str());
    statistic["count"] = value;

    if (!metadata.isNull())
    {
        statistic["metadata"] = metadata;
    }

    SendTelemetry(L"nr_statistic_update", statistic);
}

void PlayFabManager::SendTelemetry(const std::wstring& /*eventName*/, const Json::Value &payload)
{
    // EntityAPI Events dont seem to work with cloud scripts right now...leaving this in for when they do.
    /*PlayFab::EventsModels::EventContents event;
    event.Entity = *reinterpret_cast<PlayFab::EventsModels::EntityKey*>(&m_entityKey);
    event.EventNamespace = "com.playfab.events.nr";
    event.Name = PlayFab::ShortenString(eventName);

    event.Payload = payload;

    m_eventsRequest.Events.push_back(event);*/

    PlayFab::ClientModels::WriteClientPlayerEventRequest request;
    request.EventName = "nr_statistic_update";

    request.Body = payload;

    PlayFab::PlayFabClientAPI::WritePlayerEvent(request, [](const WriteEventResponse& /*response*/, void *) {});
}
