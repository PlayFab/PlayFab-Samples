//--------------------------------------------------------------------------------------
// NetworkManager.h
//
// Advanced Technology Group (ATG)
// Copyright (C) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.
//--------------------------------------------------------------------------------------

#pragma once

#include "Party.h"
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
    void CreateAndConnectToNetwork(const char* inviteId, std::function<void(std::string)> onNetworkCreated = nullptr);
    void ConnectToNetwork(const char* inviteId, const char* descriptor, std::function<void(void)> onNetworkConnected = nullptr);
    void SendGameMessage(const GameNetworkMessage& message);
    void SendTextAsVoice(std::string text);
    void SendTextMessage(std::string text);
    void LeaveNetwork(std::function<void(void)> onNetworkDestroyed = nullptr);
    void Shutdown();

    void DoWork();

    Party::PartyChatControl* GetChatControl(std::string& peer);
    Party::PartyLocalChatControl* GetLocalChatControl() { return m_localChatControl; }
    const char* GetLocalUserEntityId() { return m_localEntityId.c_str(); }

    void SetLanguageCode(const char* lang, const char* name);
    const char* GetLanguageCode() { return m_languageCode.c_str(); }
    const char* GetLanguageName() { return m_languageName.c_str(); }

    inline NetworkManagerState State() { return m_state; }
    inline bool IsConnected() const { return m_state == NetworkManagerState::NetworkConnected; }

    inline bool IsCognitiveServicesEnabled() { return m_enableCognitiveServices; }
    void SetCognitiveServicesEnabled(bool bEnabled);

private:
    bool InternalConnectToNetwork(const char* networkId, Party::PartyNetworkDescriptor& descriptor);
    void CreateLocalUser();
    void CreateLocalChatControl();
    std::string DisplayNameFromChatControl(Party::PartyChatControl* control);
    void UpdateTTSProfile();
    void SetTextChatTranslationOptions(bool bTranslateToLocalLanguage);
    void SetVoiceChatTranscriptionOptions(bool bTranscribeSelf, bool bTranscribeOtherChatControlsWithMatchingLanguages, bool bTranscribeOtherChatControlsWithNonMatchingLanguages, bool bTranslateToLocalLanguage);

    std::function<void(std::string)> m_onNetworkCreated;
    std::function<void(void)> m_onNetworkConnected;
    std::function<void(void)> m_onNetworkDestroyed;
    NetworkManagerState m_state;
    std::map<std::string, Party::PartyChatControl*> m_chatControls;
    Party::PartyLocalEndpoint* m_localEndpoint;
    Party::PartyNetwork* m_network;
    Party::PartyLocalUser* m_localUser;
    Party::PartyLocalChatControl* m_localChatControl;
    bool m_partyInitialized;
    bool m_enableCognitiveServices;
    std::string m_languageCode;
    std::string m_languageName;
    std::string m_localEntityId;
    std::string m_localEntityToken;
};

}
