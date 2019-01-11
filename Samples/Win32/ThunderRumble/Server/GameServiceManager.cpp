#include "pch.h"

#include "GameServiceManager.h"
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
    return concurrency::task_from_result<bool>(false);
}

Concurrency::task<bool> GameServiceManager::BeginMatchmaking()
{
    return concurrency::task_from_result<bool>(false);
}

Concurrency::task<bool> GameServiceManager::PulseMatchmaking()
{
    return concurrency::task_from_result<bool>(false);
}

Concurrency::task<GetAvailableRegionsResponse> GameServiceManager::GetAvailableRegions()
{
    return Concurrency::task_from_result<GetAvailableRegionsResponse>(GetAvailableRegionsResponse());
}

Concurrency::task<bool> ThunderRumble::GameServiceManager::SetShipColor(byte shipColor)
{
    return concurrency::task_from_result<bool>(false);
}

Concurrency::task<bool> ThunderRumble::GameServiceManager::SetShipVariant(byte shipVariant)
{
    return concurrency::task_from_result<bool>(false);
}

Concurrency::task<bool> ThunderRumble::GameServiceManager::SetReadyState(bool bReady)
{
    return concurrency::task_from_result<bool>(false);
}

Concurrency::task<GetLobbyInformationResponse> ThunderRumble::GameServiceManager::GetLobbyInformation(const std::string& strLobbyID)
{
    GetLobbyInformationRequest requestBody(strLobbyID);

    ServiceHTTPRequest<GetLobbyInformationRequest> httpRequest(requestBody);

    auto requestTask = httpRequest.Send();
    return requestTask.then([=](Concurrency::task<Json::Value> responseTask)
    {
        try
        {
            GetLobbyInformationResponse resp(responseTask.get());
            return resp;
        }
        catch (...)
        {
            return GetLobbyInformationResponse();
        }
    });
}