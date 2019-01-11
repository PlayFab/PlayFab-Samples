#pragma once

#include <ppltasks.h>

#include "OnlineManager.h"
#include "GameServiceManagerTypes.h"

#include <playfab/PlayFabMultiplayerDataModels.h>

namespace ThunderRumble
{
    class GameServiceManager : public Manager
    {
    public:
        GameServiceManager();
        ~GameServiceManager();

        void Tick();
        PlayFab::MultiplayerModels::AzureRegion GetPreferredRegion() const { return m_PreferredRegion; };
        void SetPreferredRegion(PlayFab::MultiplayerModels::AzureRegion preferredRegion) { m_PreferredRegion = preferredRegion; m_bHasDeterminedPreferredRegion = true; };

        bool HasDeterminedPreferredRegion() const { return m_bHasDeterminedPreferredRegion; }

        // Client calls
        Concurrency::task<bool> RegisterPlayer(const std::string& playfabPlayerSessionTicket);
        Concurrency::task<bool> BeginMatchmaking();
        Concurrency::task<bool> PulseMatchmaking();
        Concurrency::task<GetAvailableRegionsResponse> GetAvailableRegions();

        Concurrency::task<bool> SetShipColor(byte shipColor);
        Concurrency::task<bool> SetShipVariant(byte shipVariant);
        Concurrency::task<bool> SetReadyState(bool bReady);

        // Server calls
        Concurrency::task<GetLobbyInformationResponse> GetLobbyInformation(const std::string& strLobbyID);

    private:
        std::string m_sessionID;
        PlayFab::MultiplayerModels::AzureRegion m_PreferredRegion;
        bool m_bHasDeterminedPreferredRegion = false;
    };
}