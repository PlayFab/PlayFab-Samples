#pragma once

#include "LobbyPlayer.h"
#include "playfab\PlayFabMultiplayerDataModels.h"

constexpr auto THUNDERRUMBLE_VERSION = 0x2;

namespace ThunderRumble
{
    enum LobbyState
    {
        WaitingForPlayers,
        Countdown,
        AllocatingServer,
        WaitingForServer,
        InGame
    };

    class BaseRequest
    {
    public:
        BaseRequest(const std::string& strEndpoint)
        {
            m_strEndpoint = strEndpoint;
        }

        virtual Json::Value Serialize() = 0;
        std::string m_strEndpoint;
    };

    // REGISTER PLAYER
    class RegisterPlayerRequest : public BaseRequest
    {
    public:
        RegisterPlayerRequest(const std::string& strPlayFabSessionID) : BaseRequest("registerplayer")
        {
            m_strPlayFabSessionID = strPlayFabSessionID;
        }

        Json::Value Serialize()
        {
            Json::Value requestBody;
            requestBody["playfab_session"] = m_strPlayFabSessionID.c_str();
            return requestBody;
        }

    private:
        std::string m_strPlayFabSessionID;
    };

    class RegisterPlayerResponse
    {
    public:
        RegisterPlayerResponse(Json::Value responseBody)
        {
            const Json::Value jsonSessionID = responseBody["SessionID"];
            m_SessionID = jsonSessionID.asString();
        }

        std::string m_SessionID;
    };

    // BeginMatchmaking
    class BeginMatchmakingRequest : public BaseRequest
    {
    public:
        BeginMatchmakingRequest(const std::string& strServicesSessionID, PlayFab::MultiplayerModels::AzureRegion preferredRegion) : BaseRequest("beginmatchmaking")
        {
            m_strServicesSessionID = strServicesSessionID;
            m_PreferredRegion = preferredRegion;
        }

        Json::Value Serialize()
        {
            Json::Value requestBody;
            requestBody["user_session"] = m_strServicesSessionID.c_str();
            requestBody["preferred_region"] = m_PreferredRegion;
            return requestBody;
        }

    private:
        std::string m_strServicesSessionID;
        PlayFab::MultiplayerModels::AzureRegion m_PreferredRegion;
    };

    class BeginMatchmakingResponse
    {
    public:
        BeginMatchmakingResponse(Json::Value responseBody)
        {

        }
    };

    // PulseMatchmaking
    class PulseMatchmakingRequest : public BaseRequest
    {
    public:
        PulseMatchmakingRequest(const std::string& strServicesSessionID) : BaseRequest("pulsematchmaking")
        {
            m_strServicesSessionID = strServicesSessionID;
        }

        Json::Value Serialize()
        {
            Json::Value requestBody;
            requestBody["user_session"] = m_strServicesSessionID.c_str();
            return requestBody;
        }

    private:
        std::string m_strServicesSessionID;
    };

    class PulseMatchmakingResponse
    {
    public:
        PulseMatchmakingResponse(Json::Value responseBody)
        {
            // time until start
            const Json::Value lobbyInstObj = responseBody["LobbyInstance"];

            const Json::Value lobbyCountdown = lobbyInstObj["TimeUntilMatchStartSeconds"];
            m_TimeUntilMatchStartSeconds = lobbyCountdown.asInt();

            const Json::Value lobbyState = lobbyInstObj["State"];
            m_LobbyState = (LobbyState)lobbyState.asInt();

            const Json::Value serverInst = lobbyInstObj["ServerInstance"];
            if (!serverInst.isNull())
            {
                m_IpAddr = serverInst["IPV4Address"].asString();

                // Find the game port
                const Json::Value arrPorts = serverInst["Ports"];
                for (auto iter = arrPorts.begin(); iter != arrPorts.end(); iter++)
                {
                    Json::Value arrPortIter = (*iter);
                    const Json::Value portName = arrPortIter["Name"];
                    const Json::Value portNum = arrPortIter["Num"];
                    if (portName.asString() == "Game")
                    {
                        m_Port = (uint16_t)portNum.asUInt();
                        break;
                    }
                }
            }

            // local player index
            const Json::Value localPlayerIndexVal = responseBody["LocalPlayerIndex"];
            m_localPlayerIndex = (uint16_t)localPlayerIndexVal.asUInt();

            // members
            const Json::Value arrMembers = lobbyInstObj["Members"];
            for (auto iter = arrMembers.begin(); iter != arrMembers.end(); iter++)
            {
                Json::Value arrMemberIter = (*iter);
                const std::string& displayName = arrMemberIter["DisplayName"].asString();

                byte shipColor = (byte)arrMemberIter["ShipColor"].asUInt();
                byte shipVariant = (byte)arrMemberIter["ShipVariant"].asUInt();
                bool bIsReady = arrMemberIter["IsReady"].asBool();

                wchar_t wcharStr[64] = { 0 };
                MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, displayName.c_str(), (int)strlen(displayName.c_str()), wcharStr, MAX_PATH);

                m_vecMembers.push_back(CLobbyPlayer(std::wstring(wcharStr), shipColor, shipVariant, bIsReady));
            }
        }

        LobbyState m_LobbyState;
        std::string m_IpAddr;
        uint16_t m_Port;
        int m_TimeUntilMatchStartSeconds;
        std::vector<CLobbyPlayer> m_vecMembers;
        uint16_t m_localPlayerIndex;
    };

    // GetAvailableRegions
    class GetAvailableRegionsRequest : public BaseRequest
    {
    public:
        GetAvailableRegionsRequest(const std::string& strServicesSessionID) : BaseRequest("getavailableregions")
        {
            m_strServicesSessionID = strServicesSessionID;
        }

        Json::Value Serialize()
        {
            Json::Value requestBody;
            requestBody["user_session"] = m_strServicesSessionID.c_str();
            return requestBody;
        }

    private:
        std::string m_strServicesSessionID;
    };

    class GetAvailableRegionsResponse
    {
    public:
        GetAvailableRegionsResponse()
        {

        }

        GetAvailableRegionsResponse(Json::Value responseBody)
        {
            const Json::Value arrRegions = responseBody;
            for (auto iter = arrRegions.begin(); iter != arrRegions.end(); iter++)
            {
                const Json::Value regionVal = *iter;
                PlayFab::MultiplayerModels::AzureRegion azureRegion = (PlayFab::MultiplayerModels::AzureRegion)(uint32_t)regionVal.asUInt();
                m_vecRegions.push_back(azureRegion);
            }
        }

        std::vector<PlayFab::MultiplayerModels::AzureRegion> m_vecRegions;
    };

    // SetShipColor (no response, fire and forget)
    class SetShipColorRequest : public BaseRequest
    {
    public:
        SetShipColorRequest(const std::string& strServicesSessionID, byte shipColor) : BaseRequest("setshipcolor")
        {
            m_strServicesSessionID = strServicesSessionID;
            m_ShipColor = shipColor;
        }

        Json::Value Serialize()
        {
            Json::Value requestBody;
            requestBody["user_session"] = m_strServicesSessionID.c_str();
            requestBody["ship_color"] = m_ShipColor;
            return requestBody;
        }

    private:
        std::string m_strServicesSessionID;
        byte m_ShipColor;
    };

    // SetShipVariant (no response, fire and forget)
    class SetShipVariantRequest : public BaseRequest
    {
    public:
        SetShipVariantRequest(const std::string& strServicesSessionID, byte shipVariant) : BaseRequest("setshipvariant")
        {
            m_strServicesSessionID = strServicesSessionID;
            m_ShipVariant = shipVariant;
        }

        Json::Value Serialize()
        {
            Json::Value requestBody;
            requestBody["user_session"] = m_strServicesSessionID.c_str();
            requestBody["ship_variant"] = m_ShipVariant;
            return requestBody;
        }

    private:
        std::string m_strServicesSessionID;
        byte m_ShipVariant;
    };

    // SetReadyState (no response, fire and forget)
    class SetReadyStateRequest : public BaseRequest
    {
    public:
        SetReadyStateRequest(const std::string& strServicesSessionID, bool bReady) : BaseRequest("setreadystate")
        {
            m_strServicesSessionID = strServicesSessionID;
            m_bReady = bReady;
        }

        Json::Value Serialize()
        {
            Json::Value requestBody;
            requestBody["user_session"] = m_strServicesSessionID.c_str();
            requestBody["is_ready"] = m_bReady;
            return requestBody;
        }

    private:
        std::string m_strServicesSessionID;
        bool m_bReady;
    };

    // GetLobbyInformation
    class GetLobbyInformationRequest : public BaseRequest
    {
    public:
        GetLobbyInformationRequest(const std::string& strLobbyID) : BaseRequest("getlobbyinformation")
        {
            m_strLobbyID = strLobbyID;
        }

        Json::Value Serialize()
        {
            Json::Value requestBody;
            requestBody["lobby_id"] = m_strLobbyID.c_str();
            return requestBody;
        }

    private:
        std::string m_strLobbyID;
    };

    class GetLobbyInformationResponse
    {
    public:
        GetLobbyInformationResponse()
        {

        }

        GetLobbyInformationResponse(Json::Value responseBody)
        {
            // members
            const Json::Value arrMembers = responseBody["Members"];
            m_numMembers = (int)arrMembers.size();
        }

        int m_numMembers;
    };
}