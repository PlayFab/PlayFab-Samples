//--------------------------------------------------------------------------------------
// NetworkManager.h
//
// Advanced Technology Group (ATG)
// Copyright (C) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.
//--------------------------------------------------------------------------------------

#pragma once

#include "Manager.h"
#include "NetworkMessages.h"

namespace BumbleRumble
{

enum class NetworkManagerState
{
    Initialize,
    WaitingForNetwork,
    NetworkConnected,
    Leaving
};

class NetworkManager : public Manager
{
public:
    NetworkManager();
    ~NetworkManager();

    void Initialize();
    void CreateAndConnectToNetwork(std::vector<std::string>& playerIds, std::function<void(std::string)> callback = nullptr);
    void ConnectToNetwork(const char* descriptor, std::function<void(void)> callback = nullptr);
    void SendGameMessage(const GameNetworkMessage& message);
    void SendTextAsVoice(std::string text);
    void SendTextMessage(std::string text);
    void LeaveNetwork(std::function<void(void)> callback = nullptr);
    void Shutdown();

    void DoWork();

    Party::PartyChatControl* GetChatControl(std::string& peer);
    Party::PartyLocalChatControl* GetLocalChatControl() { return m_localChatControl; }

    void SetLanguageCode(const char* lang, const char* name, const char* profile);
    const char* GetLanguageCode() { return m_languageCode; }
    const char* GetLanguageName() { return m_languageName; }

    inline NetworkManagerState State() { return m_state; }

private:
    bool InternalConnectToNetwork(Party::PartyNetworkDescriptor& descriptor);
    std::string DisplayNameFromChatControl(Party::PartyChatControl* control);
    PartyString GetErrorMessage(PartyError error);

    std::function<void(std::string)> m_onnetworkcreated;
    std::function<void(void)> m_onnetworkconnected;
    std::function<void(void)> m_onnetworkdestroyed;
    NetworkManagerState m_state;
    std::map<std::string, Party::PartyChatControl*> m_chatControls;
    Party::PartyLocalUser* m_localUser;
    Party::PartyLocalEndpoint* m_localEndpoint;
    Party::PartyLocalChatControl* m_localChatControl;
    Party::PartyNetwork* m_network;
    PartyString m_languageCode;
    PartyString m_languageProfile;
    PartyString m_languageName;
    bool m_cofaInitialized;
};

}
