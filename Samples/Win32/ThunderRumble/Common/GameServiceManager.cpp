#include "pch.h"

#include "GameServiceManager.h"

#include "Game.h"
#include "GameServiceHTTPRequest.h"
#include "GameServiceManagerTypes.h"
#include "Managers.h"


using namespace ThunderRumble;

GameServiceManager::GameServiceManager()
{

}


GameServiceManager::~GameServiceManager()
{

}

void GameServiceManager::Tick()
{

}

Concurrency::task<bool> GameServiceManager::RegisterPlayer(const std::string& playfabPlayerSessionTicket)
{
    RegisterPlayerRequest requestBody(playfabPlayerSessionTicket);

    ServiceHTTPRequest<RegisterPlayerRequest> httpRequest(requestBody);

    auto requestTask = httpRequest.Send();
    return requestTask.then([=](Concurrency::task<Json::Value> responseTask)
    {
        try
        {
            Json::Value response = responseTask.get();
            RegisterPlayerResponse resp(response);
            m_sessionID = resp.m_SessionID;
            return concurrency::task_from_result(true);
        }
        catch (...)
        {
            return concurrency::task_from_result(false);
        }
    });
}

Concurrency::task<bool> GameServiceManager::BeginMatchmaking()
{
    BeginMatchmakingRequest requestBody(m_sessionID, m_PreferredRegion);

    ServiceHTTPRequest<BeginMatchmakingRequest> httpRequest(requestBody);

    auto requestTask = httpRequest.Send();
    return requestTask.then([=](Concurrency::task<Json::Value> responseTask)
    {
        Json::Value response = responseTask.get();
        try
        {
            BeginMatchmakingResponse resp(responseTask.get());
            return concurrency::task_from_result(true);
        }
        catch (...)
        {
            return concurrency::task_from_result(false);
        }
    });
}

Concurrency::task<bool> GameServiceManager::PulseMatchmaking()
{
    PulseMatchmakingRequest requestBody(m_sessionID);

    ServiceHTTPRequest<PulseMatchmakingRequest> httpRequest(requestBody);

    auto requestTask = httpRequest.Send();
    return requestTask.then([=](Concurrency::task<Json::Value> responseTask)
    {
        Json::Value response = responseTask.get();
        try
        {
            PulseMatchmakingResponse resp(responseTask.get());

            if (resp.m_LobbyState == LobbyState::WaitingForPlayers)
            {
                if (Managers::Get<GameStateManager>()->GetState() != GameState::WaitingToStart)
                {
                    Managers::Get<GameStateManager>()->GotoLobby();
                }
            }
            else if (resp.m_LobbyState == LobbyState::AllocatingServer)
            {
                if (Managers::Get<GameStateManager>()->GetState() != GameState::AllocatingServer)
                {
                    Managers::Get<GameStateManager>()->GotoAllocatingServer();
                }
            }
            else if (resp.m_LobbyState == LobbyState::Countdown)
            {
                Managers::Get<GameStateManager>()->GotoCountdownStage(resp.m_TimeUntilMatchStartSeconds);
            }
            else if (resp.m_LobbyState == LobbyState::InGame)
            {
                auto state = Managers::Get<GameStateManager>()->GetState();
                if (state != GameState::ConnectingToServer && state != GameState::Playing)
                {
                    wchar_t wcharStr[64] = { 0 };
                    MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, resp.m_IpAddr.c_str(), (int)strlen(resp.m_IpAddr.c_str()), wcharStr, MAX_PATH);
                    Managers::Get<GameStateManager>()->ConnectToServer(wcharStr, resp.m_Port);
                }
            }

            auto gameStateMgr = Managers::Get<GameStateManager>();
            gameStateMgr->SetLobbyPlayers(resp.m_localPlayerIndex, resp.m_vecMembers);

            return true;
        }
        catch (...)
        {
            return false;
        }
    });
}

Concurrency::task<GetAvailableRegionsResponse> GameServiceManager::GetAvailableRegions()
{
    GetAvailableRegionsRequest requestBody(m_sessionID);

    ServiceHTTPRequest<GetAvailableRegionsRequest> httpRequest(requestBody);

    auto requestTask = httpRequest.Send();
    return requestTask.then([=](Concurrency::task<Json::Value> responseTask)
    {
        try
        {
            GetAvailableRegionsResponse resp(responseTask.get());


            return resp;
        }
        catch (...)
        {
            return GetAvailableRegionsResponse();
        }
    });
}

Concurrency::task<bool> ThunderRumble::GameServiceManager::SetShipColor(byte shipColor)
{
    SetShipColorRequest requestBody(m_sessionID, shipColor);
    ServiceHTTPRequest<SetShipColorRequest> httpRequest(requestBody);
    auto requestTask = httpRequest.Send();

    return requestTask.then([=](Concurrency::task<Json::Value> responseTask)
    {
        try
        {
            return true;
        }
        catch (...)
        {
            return false;
        }
    });
}

Concurrency::task<bool> ThunderRumble::GameServiceManager::SetShipVariant(byte shipVariant)
{
    SetShipVariantRequest requestBody(m_sessionID, shipVariant);
    ServiceHTTPRequest<SetShipVariantRequest> httpRequest(requestBody);
    auto requestTask = httpRequest.Send();

    return requestTask.then([=](Concurrency::task<Json::Value> responseTask)
    {
        try
        {
            return true;
        }
        catch (...)
        {
            return false;
        }
    });
}

Concurrency::task<bool> ThunderRumble::GameServiceManager::SetReadyState(bool bReady)
{
    SetReadyStateRequest requestBody(m_sessionID, bReady);
    ServiceHTTPRequest<SetReadyStateRequest> httpRequest(requestBody);
    auto requestTask = httpRequest.Send();

    return requestTask.then([=](Concurrency::task<Json::Value> responseTask)
    {
        try
        {
            return true;
        }
        catch (...)
        {
            return false;
        }
    });
}

Concurrency::task<GetLobbyInformationResponse> ThunderRumble::GameServiceManager::GetLobbyInformation(const std::string& /*strLobbyID*/)
{
    return concurrency::task_from_result<GetLobbyInformationResponse>(GetLobbyInformationResponse());
}