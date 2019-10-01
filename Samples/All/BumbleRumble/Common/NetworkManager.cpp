//--------------------------------------------------------------------------------------
// NetworkManager.cpp
//
// Advanced Technology Group (ATG)
// Copyright (C) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.
//--------------------------------------------------------------------------------------

#include "pch.h"
#include "Managers.h"
#include "Game.h"

#include "PartyImpl.h"
#include "Managers.h"
#include "NetworkMessages.h"
#include "STTOverlayScreen.h"
#include "PlayerState.h"

using namespace BumbleRumble;
using namespace Party;

NetworkManager::NetworkManager() :
    m_state(NetworkManagerState::Initialize),
    m_localEndpoint(nullptr),
    m_network(nullptr),
    m_localUser(nullptr),
    m_localChatControl(nullptr),
    m_cofaInitialized(false),
    m_languageCode("en-US"),
    m_languageName("English (United States)"),
    m_languageProfile("Microsoft Server Speech Text to Speech Voice (en-US, ZiraRUS)")
{
}

NetworkManager::~NetworkManager()
{
    DEBUGLOG("NetworkManager::~NetworkManager()\n");
}

void NetworkManager::SetLanguageCode(const char* lang, const char* name, const char* profile)
{
    m_languageCode = lang;
    m_languageName = name;
    m_languageProfile = profile;
}

void NetworkManager::Initialize()
{
    DEBUGLOG("NetworkManager::Initialize()\n");

    auto& cofa = PartyManager::GetSingleton();
    PartyError err;

    if (m_cofaInitialized == false)
    {
        extern const char* c_pfTitleId;

        // Initialize PlayFab Party
        err = cofa.Initialize(c_pfTitleId);
        if (PARTY_FAILED(err))
        {
            DEBUGLOG("Initialize failed: %hs\n", GetErrorMessage(err));
            return;
        }

        m_cofaInitialized = true;
    }

    if (m_localUser == nullptr)
    {
        PartyString entityId = Managers::Get<PlayFabManager>()->EntityId().c_str();
        PartyString entityToken = Managers::Get<PlayFabManager>()->EntityToken().c_str();

        // Create a local user object
        err = cofa.CreateLocalUser(
            entityId,                                   // User id
            entityToken,                                // User entity token
            &m_localUser                                // OUT local user object
            );

        if (PARTY_FAILED(err))
        {
            DEBUGLOG("CreateLocalUser failed: %hs\n", GetErrorMessage(err));
            return;
        }
    }

    if (m_localChatControl == nullptr)
    {
        PartyLocalDevice* localDevice = nullptr;

        // Retrieve the local device
        err = cofa.GetLocalDevice(&localDevice);

        if (PARTY_FAILED(err))
        {
            DEBUGLOG("GetLocalDevice failed: %hs\n", GetErrorMessage(err));
            return;
        }

        // Create a chat control for the local user on the local device
        err = localDevice->CreateChatControl(
            m_localUser,                                // Local user object
            m_languageCode,                             // Language id
            nullptr,                                    // Async identifier
            &m_localChatControl                         // OUT local chat control
            );

        if (PARTY_FAILED(err))
        {
            DEBUGLOG("CreateChatControl failed: %hs\n", GetErrorMessage(err));
            return;
        }

        // Use automatic settings for the audio input device
        err = m_localChatControl->SetAudioInput(
            PartyAudioDeviceSelectionType::Automatic,    // Selection type
            nullptr,                                    // Device id
            nullptr                                     // Async identifier
            );

        if (PARTY_FAILED(err))
        {
            DEBUGLOG("SetAudioInput failed: %hs\n", GetErrorMessage(err));
            return;
        }

        // Use automatic settings for the audio output device
        err = m_localChatControl->SetAudioOutput(
            PartyAudioDeviceSelectionType::Automatic,    // Selection type
            nullptr,                                    // Device id
            nullptr                                     // Async identifier
            );

        if (PARTY_FAILED(err))
        {
            DEBUGLOG("SetAudioOutput failed: %hs\n", GetErrorMessage(err));
        }

        // Set the language profile to use
        err = m_localChatControl->SetTextToSpeechProfile(
            m_languageProfile,                          // Language profile
            nullptr                                     // Async identifier
            );

        if (PARTY_FAILED(err))
        {
            DEBUGLOG("SetTextToSpeechProfile failed: %hs\n", GetErrorMessage(err));
        }

        // Enable transcriptions always for sample purposes
        err = m_localChatControl->SetTranscriptionRequested(
            true,                                       // Turn on speech-to-text transcription
            nullptr                                     // Async identifier
            );

        if (PARTY_FAILED(err))
        {
            DEBUGLOG("SetTranscriptionRequested failed: %hs\n", GetErrorMessage(err));
        }
    }
}

void NetworkManager::Shutdown()
{
    DEBUGLOG("NetworkManager::Shutdown()\n");

    m_state = NetworkManagerState::Initialize;

    // This cleans up everything allocated in Initialize() and
    // should only be used when done with networking
    PartyManager::GetSingleton().Cleanup();

    m_localChatControl = nullptr;
    m_localEndpoint = nullptr;
    m_network = nullptr;
    m_localUser = nullptr;
    m_cofaInitialized = false;
}

void NetworkManager::CreateAndConnectToNetwork(std::vector<std::string>& playerIds, std::function<void(std::string)> callback)
{
    DEBUGLOG("NetworkManager::CreateAndConnectToNetwork()\n");

    PartyNetworkConfiguration cfg = {};

    // Setup the network to allow 8 single-device players of any device type
    cfg.allowedDeviceTypeCount = 0;
    cfg.allowedDeviceTypes = nullptr;
    cfg.maxDeviceCount = 8;
    cfg.maxDevicesPerUserCount = 1;
    cfg.maxEndpointsPerDeviceCount = 1;
    cfg.maxUserCount = 8;
    cfg.maxUsersPerDeviceCount = 1;

    PartyString uid = nullptr;
    PartyError err = m_localUser->GetEntityId(&uid);

    if (PARTY_FAILED(err))
    {
        DEBUGLOG("GetEntityId failed: %hs\n", GetErrorMessage(err));
        return;
    }

    std::vector<PartyString> additionalIds;

    DEBUGLOG("Additional user ids: \n");
    for (const auto& id : playerIds)
    {
        additionalIds.push_back(id.c_str());
        DEBUGLOG("\t%hs\n", id.c_str());
    }

    PartyNetworkDescriptor networkDescriptor = {};

    // Create a new network descriptor
    err = PartyManager::GetSingleton().CreateNewNetwork(
        m_localUser,                                // Local User
        &cfg,                                       // Network Config
        0,                                          // Region List Count
        nullptr,                                    // Region List
        static_cast<uint32_t>(additionalIds.size()),// Additional UserId Count
        additionalIds.data(),                       // Additional UserId List
        nullptr,                                    // Async Identifier
        &networkDescriptor                          // OUT network descriptor
        );

    if (PARTY_FAILED(err))
    {
        DEBUGLOG("CreateNewNetwork failed: %hs\n", GetErrorMessage(err));
        return;
    }

    // Connect to the new network
    if (InternalConnectToNetwork(networkDescriptor))
    {
        m_state = NetworkManagerState::WaitingForNetwork;
        m_onnetworkcreated = callback;
    }
}

void NetworkManager::ConnectToNetwork(const char* descriptor, std::function<void(void)> callback)
{
    DEBUGLOG("NetworkManager::ConnectToNetwork()\n");

    PartyNetworkDescriptor networkDescriptor = {};

    // Deserialize the remote network's descriptor
    PartyError err = PartyManager::DeserializeNetworkDescriptor(descriptor, &networkDescriptor);

    if (PARTY_FAILED(err))
    {
        DEBUGLOG("ConnectToNetwork failed to deserialize descriptor: %hs\n", GetErrorMessage(err));
        return;
    }

    // Connect to the remote network
    if (InternalConnectToNetwork(networkDescriptor))
    {
        m_state = NetworkManagerState::WaitingForNetwork;
        m_onnetworkconnected = callback;
    }
}

bool NetworkManager::InternalConnectToNetwork(Party::PartyNetworkDescriptor& descriptor)
{
    // This portion of connecting to the network is the same for
    // both creating a new and joining an existing network.

    PartyError err = PartyManager::GetSingleton().ConnectToNetwork(
        &descriptor,                                // Network descriptor
        nullptr,                                    // Async identifier
        &m_network                                  // OUT network
        );

    if (PARTY_FAILED(err))
    {
        DEBUGLOG("ConnectToNetwork failed: %hs\n", GetErrorMessage(err));
        return false;
    }

    // Authenticate the local user on the network so we can participate in it
    err = m_network->AuthenticateLocalUser(
        m_localUser,                                // Local user
        nullptr                                     // Async identifier
        );

    if (PARTY_FAILED(err))
    {
        DEBUGLOG("AuthenticateLocalUser failed: %hs\n", GetErrorMessage(err));
        return false;
    }

    // Connect the local user chat control to the network so we can use VOIP
    err = m_network->ConnectChatControl(
        m_localChatControl,                         // Local chat control
        nullptr                                     // Async identifier
        );

    if (PARTY_FAILED(err))
    {
        DEBUGLOG("ConnectChatControl failed: %hs\n", GetErrorMessage(err));
        return false;
    }

    // Establish a network endoint for game message traffic
    err = m_network->CreateEndpoint(
        m_localUser,                                // Local user
        0,                                          // Property Count
        nullptr,                                    // Property name keys
        nullptr,                                    // Property Values
        nullptr,                                    // Async identifier
        &m_localEndpoint                            // OUT local endpoint
        );

    if (PARTY_FAILED(err))
    {
        DEBUGLOG("Failed to CreateEndpoint: %hs\n", GetErrorMessage(err));
        return false;
    }

    return true;
}

void NetworkManager::SendGameMessage(const GameNetworkMessage & message)
{
    if (m_localEndpoint && m_state == NetworkManagerState::NetworkConnected)
    {
        auto packet = message.Serialize();

        // Form the data packet into a data buffer structure
        PartyDataBuffer data[] = {
            {
                static_cast<const void*>(packet.data()),
                static_cast<uint32_t>(packet.size())
            },
        };

        PartySendMessageOptions deliveryOptions;

        // ShipInput and ShipData messages don't need to be sent reliably
        // or sequentially, but the rest are needed for gameplay
        switch (message.MessageType())
        {
        case GameMessageType::ShipInput:
        case GameMessageType::ShipData:
            deliveryOptions = PartySendMessageOptions::Default;
            break;

        default:
            deliveryOptions = PartySendMessageOptions::GuaranteedDelivery |
                              PartySendMessageOptions::SequentialDelivery;
        }

        // Send out the message to all other peers
        PartyError err = m_localEndpoint->SendMessage(
            0,                                      // endpoint count; 0 = broadcast
            nullptr,                                // endpoint list
            deliveryOptions,                        // send message options
            nullptr,                                // configuration
            1,                                      // buffer count
            data,                                   // buffer
            nullptr                                 // async identifier
            );

        if (PARTY_FAILED(err))
        {
            DEBUGLOG("Failed to SendMessage: %hs\n", GetErrorMessage(err));
        }
    }
}

void NetworkManager::SendTextMessage(std::string text)
{
    if (m_localChatControl != nullptr)
    {
        DEBUGLOG("Send text message: %hs\n", text.c_str());

        std::vector<Party::PartyChatControl*> targets;

        for (const auto& item : m_chatControls)
        {
            Party::PartyLocalChatControl* local = nullptr;

            item.second->GetLocal(&local);

            if (local == nullptr)
            {
                targets.push_back(item.second);
            }
        }

        PartyError err = m_localChatControl->SendText(
            static_cast<uint32_t>(targets.size()),  // Count of target controls
            targets.data(),                         // Target controls
            text.c_str(),                           // Text to synthesize
            0,                                      // Data buffer size
            nullptr                                 // Data buffer
            );

        if (PARTY_FAILED(err))
        {
            DEBUGLOG("Failed to SendText: %hs\n", GetErrorMessage(err));
        }

        // Toast the text on the screen
        Managers::Get<ScreenManager>()->GetSTTWindow()->AddSTTString(
            DisplayNameFromChatControl(m_localChatControl),
            text.c_str(),
            false
            );

    }
}

void NetworkManager::SendTextAsVoice(std::string text)
{
    if (m_localChatControl != nullptr)
    {
        DEBUGLOG("Requesting transcription of: %hs\n", text.c_str());

        PartyError err = m_localChatControl->SynthesizeTextToSpeech(
            text.c_str(),                           // Text to synthesize
            nullptr                                 // Async identifier
            );

        if (PARTY_FAILED(err))
        {
            DEBUGLOG("Failed to SynthesizeTextToSpeech: %hs\n", GetErrorMessage(err));
        }
    }
}

void NetworkManager::LeaveNetwork(std::function<void(void)> callback)
{
    DEBUGLOG("NetworkManager::LeaveNetwork()\n");

    if (m_state != NetworkManagerState::Leaving && m_network != nullptr)
    {
        m_state = NetworkManagerState::Leaving;
        m_onnetworkdestroyed = callback;

        // First destroy the chat control
        PartyLocalDevice* localDevice = nullptr;

        // Retrieve the local device
        auto err = PartyManager::GetSingleton().GetLocalDevice(&localDevice);

        if (PARTY_FAILED(err))
        {
            DEBUGLOG("GetLocalDevice failed: %hs\n", GetErrorMessage(err));
            m_network->LeaveNetwork(nullptr);
            return;
        }

        err = localDevice->DestroyChatControl(m_localChatControl, nullptr);

        if (PARTY_FAILED(err))
        {
            DEBUGLOG("DestroyChatControl failed: %hs\n", GetErrorMessage(err));
            m_network->LeaveNetwork(nullptr);
        }
    }
    else
    {
        if (callback != nullptr)
        {
            callback();
        }
    }
}

std::string PartyStateChangeResultToReasonString(PartyStateChangeResult result)
{
    switch (result)
    {
    case PartyStateChangeResult::Succeeded: return "Succeeded";
    case PartyStateChangeResult::UnknownError: return "An unknown error occured";
    case PartyStateChangeResult::CanceledByTitle: return "Another title operation canceled this operation";
    case PartyStateChangeResult::InternetConnectivityError: return "The local device has internet connectivity issues which caused the operation to fail";
    case PartyStateChangeResult::PartyServiceError: return "The Party service is unable to create a new network at this time";
    case PartyStateChangeResult::NoServersAvailable: return "There are no available servers in the regions specified by the call to PartyManager::CreateNewNetwork()";
    case PartyStateChangeResult::UserNotAuthorized: return "The PartyLocalUser specified in the call to PartyManager::CreateNewNetwork() is not allowed to create a new network";
    case PartyStateChangeResult::UserCreateNetworkThrottled: return "The PartyLocalUser specified in the call to PartyManager::CreateNewNetwork() has created too many networks and cannot create new networks at this time";
    case PartyStateChangeResult::TitleNotEnabledForParty: return "The title has not been configured properly in the Party portal";
    case PartyStateChangeResult::TitleCreateNetworkThrottled: return "The title has created too many networks";
    case PartyStateChangeResult::NetworkFull: return "The network is full and is not allowing new devices or users to join";
    case PartyStateChangeResult::NetworkNoLongerExists: return "The network no longer exists";
    case PartyStateChangeResult::NetworkNotJoinable: return "The network is not currently allowing new devices or users to join";
    case PartyStateChangeResult::VersionMismatch: return "The network uses a version of the Party library that is incompatible with this library";
    case PartyStateChangeResult::LeaveNetworkCalled: return "The network was gracefully exited by the local device";
    }
    return "Unknown enumeration value";
}

std::string PartyAudioInputStateToString(PartyAudioInputState state)
{
    switch (state)
    {
    case PartyAudioInputState::Initialized: return "Initialized";
    case PartyAudioInputState::NoInput: return "NoInput";
    case PartyAudioInputState::NotFound: return "NotFound";
    case PartyAudioInputState::UnknownError: return "UnknownError";
    case PartyAudioInputState::UnsupportedFormat: return "UnsupportedFormat";
    case PartyAudioInputState::UserConsentDenied: return "UserConsentDenied";
    }
    return "Unknown enumeration value";
}

std::string PartyAudioOutputStateToString(PartyAudioOutputState state)
{
    switch (state)
    {
    case PartyAudioOutputState::Initialized: return "Initialized";
    case PartyAudioOutputState::NoOutput: return "NoOutput";
    case PartyAudioOutputState::NotFound: return "NotFound";
    case PartyAudioOutputState::UnknownError: return "UnknownError";
    case PartyAudioOutputState::UnsupportedFormat: return "UnsupportedFormat";
    }
    return "Unknown enumeration value";
}

std::string PartyAudioDeviceSelectionTypeToString(PartyAudioDeviceSelectionType type)
{
    switch (type)
    {
    case PartyAudioDeviceSelectionType::Automatic: return "Automatic";
    case PartyAudioDeviceSelectionType::Manual: return "Manual";
    case PartyAudioDeviceSelectionType::None: return "None";
    }
    return "Unknown enumeration value";
}

PartyString NetworkManager::GetErrorMessage(PartyError error)
{
    PartyString errString = nullptr;

    PartyError err = PartyManager::GetErrorMessage(error, &errString);
    if (PARTY_FAILED(err))
    {
        DEBUGLOG("Failed to get error message %lu.\n", error);
        return "[ERROR]";
    }

    return errString;
}

void NetworkManager::DoWork()
{
    if (m_state == NetworkManagerState::Initialize)
    {
        return;
    }

    PartyStateChangeArray changes;
    uint32_t count;

    // Start processing messages from the CoFa layer
    PartyError err = PartyManager::GetSingleton().StartProcessingStateChanges(
        &count,
        &changes
        );

    if (PARTY_FAILED(err))
    {
        DEBUGLOG("StartProcessingStateChanges failed: %hs\n", GetErrorMessage(err));
        return;
    }

    for (uint32_t i = 0; i < count; i++)
    {
        auto change = changes[i];

        switch (change->stateChangeType)
        {
            case PartyStateChangeType::CreateNewNetworkCompleted:
            {
                DEBUGLOG("PartyStateChange: PartyStateChangeType::CreateNewNetworkCompleted\n");
                auto result = static_cast<const PartyCreateNewNetworkCompletedStateChange*>(change);
                if (result->result == PartyStateChangeResult::Succeeded)
                {
                    DEBUGLOG("CreateNewNetworkCompleted:  SUCCESS\n");
                }
                else
                {
                    DEBUGLOG("CreateNewNetworkCompleted:  FAIL:  %hs\n", PartyStateChangeResultToReasonString(result->result).c_str());
                    DEBUGLOG("ErrorDetail: %hs\n", GetErrorMessage(result->errorDetail));
                    Managers::Get<GameStateManager>()->ResetGame("Unable to create network");
                }
                break;
            }
            case PartyStateChangeType::ConnectToNetworkCompleted:
            {
                DEBUGLOG("PartyStateChange: PartyStateChangeType::ConnectToNetworkCompleted\n");
                auto result = static_cast<const PartyConnectToNetworkCompletedStateChange*>(change);
                if (result->result == PartyStateChangeResult::Succeeded)
                {
                    DEBUGLOG("ConnectToNetworkCompleted:  SUCCESS\n");
                    m_state = NetworkManagerState::NetworkConnected;
                    // Callback if ConnectToNetwork() was called
                    if (m_onnetworkconnected)
                    {
                        m_onnetworkconnected();
                    }
                    // Callback if CreateAndConnectToNetwork() was called
                    if (m_onnetworkcreated)
                    {
                        char descriptor[c_maxSerializedNetworkDescriptorStringLength + 1] = {};

                        // Serialize our local network descriptor for other peers to use
                        err = PartyManager::SerializeNetworkDescriptor(
                            &result->networkDescriptor,
                            descriptor
                            );

                        if (PARTY_FAILED(err))
                        {
                            DEBUGLOG("Failed to serialize network descriptor: %hs\n", GetErrorMessage(err));
                            m_onnetworkcreated(std::string());
                        }

                        DEBUGLOG("Serialized value: %hs\n", descriptor);
                        // Callback with the descriptor to be shared with connecting clients
                        m_onnetworkcreated(std::string(descriptor));
                    }
                }
                else
                {
                    DEBUGLOG("ConnectToNetworkCompleted:  FAIL:  %hs\n", PartyStateChangeResultToReasonString(result->result).c_str());
                    DEBUGLOG("ErrorDetail: %hs\n", GetErrorMessage(result->errorDetail));
                    Managers::Get<GameStateManager>()->ResetGame("Unable to connect to network");
                }
                break;
            }
            case PartyStateChangeType::CreateEndpointCompleted:
            {
                DEBUGLOG("PartyStateChange: PartyStateChangeType::CreateEndpointCompleted\n");
                auto result = static_cast<const PartyCreateEndpointCompletedStateChange*>(change);
                if (result->result == PartyStateChangeResult::Succeeded)
                {
                    DEBUGLOG("CreateEndpointCompleted:  SUCCESS\n");
                }
                else
                {
                    DEBUGLOG("CreateEndpointCompleted:  FAIL:  %hs\n", PartyStateChangeResultToReasonString(result->result).c_str());
                    DEBUGLOG("ErrorDetail: %hs\n", GetErrorMessage(result->errorDetail));
                    Managers::Get<GameStateManager>()->ResetGame("Unable to establish network endpoint");
                }
                break;
            }
            case PartyStateChangeType::EndpointCreated:
            {
                DEBUGLOG("PartyStateChange: PartyStateChangeType::EndpointCreated\n");
                auto result = static_cast<const PartyEndpointCreatedStateChange*>(change);
                PartyString user = nullptr;

                err = result->endpoint->GetEntityId(&user);

                if (PARTY_FAILED(err) || user == nullptr)
                {
                    DEBUGLOG("Unable to retrieve user id from endpoint: %hs\n", GetErrorMessage(err));
                }
                else
                {
                    DEBUGLOG("Established endpoint with user %hs\n", user);
                    // Send out our info packets to any new connections so
                    // they'll know about us.
                    auto playerState = Managers::Get<GameStateManager>()->GetPlayerState(Managers::Get<PlayFabManager>()->EntityId());
                    auto displayName = playerState->DisplayName;

                    Managers::Get<NetworkManager>()->SendGameMessage(
                        GameNetworkMessage(
                            GameMessageType::PlayerInfo,
                            displayName
                            )
                        );

                    Managers::Get<NetworkManager>()->SendGameMessage(
                        GameNetworkMessage(
                            GameMessageType::PlayerState,
                            playerState->SerializePlayerStateData()
                            )
                        );
                }
                break;
            }
            case PartyStateChangeType::EndpointDestroyed:
            {
                DEBUGLOG("PartyStateChange: PartyStateChangeType::EndpointDestroyed\n");
                auto result = static_cast<const PartyEndpointDestroyedStateChange*>(change);

                DEBUGLOG("Endpoint is %hs\n", result->endpoint == m_localEndpoint ? "local" : "remote");
                DEBUGLOG("Reason: %d\n", result->reason);
                DEBUGLOG("Error Detail: %hs\n", GetErrorMessage(result->errorDetail));

                if (result->endpoint == m_localEndpoint)
                {
                    // Our endpoint was disconnected
                    m_localEndpoint = nullptr;
                }
                else
                {
                    // Another user has disconnected
                    PartyString user = nullptr;
                    err = result->endpoint->GetEntityId(&user);

                    if (PARTY_FAILED(err))
                    {
                        DEBUGLOG("Unable to retrieve user id from endpoint: %hs\n", GetErrorMessage(err));
                        break;
                    }

                    std::string userId(user);
                    Managers::Get<GameStateManager>()->DeactivatePlayer(userId);
                }
                break;
            }
            case PartyStateChangeType::EndpointMessageReceived:
            {
                // This is spammy, but can be useful when debugging
                // DEBUGLOG("PartyStateChange: PartyStateChangeType::EndpointMessageReceived\n");
                auto result = static_cast<const PartyEndpointMessageReceivedStateChange*>(change);
                auto buffer = static_cast<const uint8_t*>(result->messageBuffer);
                auto packet = std::make_shared<GameNetworkMessage>(
                    std::vector<uint8_t>(buffer, buffer + result->messageSize)
                    );

                PartyString sender = nullptr;
                err = result->senderEndpoint->GetEntityId(&sender);

                if (PARTY_SUCCEEDED(err))
                {
                    std::string senderId(sender);

                    // Give the message to the game engine
                    Managers::Get<GameStateManager>()->ProcessGameNetworkMessage(
                        senderId,
                        packet
                        );
                }
                else
                {
                    DEBUGLOG("GetEntityId failed: %hs\n", GetErrorMessage(err));
                }

                break;
            }
            case PartyStateChangeType::AuthenticateLocalUserCompleted:
            {
                DEBUGLOG("PartyStateChange: PartyStateChangeType::AuthenticateLocalUserCompleted\n");
                auto result = static_cast<const PartyAuthenticateLocalUserCompletedStateChange*>(change);
                if (result->result == PartyStateChangeResult::Succeeded)
                {
                    DEBUGLOG("Succeeded\n");
                }
                else
                {
                    DEBUGLOG("Failed: %hs\n", PartyStateChangeResultToReasonString(result->result).c_str());
                    DEBUGLOG("ErrorDetail: %hs\n", GetErrorMessage(result->errorDetail));
                    Managers::Get<GameStateManager>()->ResetGame("Unable to authenticate local user");
                }
                break;
            }
            case PartyStateChangeType::LocalUserRemoved:
            {
                DEBUGLOG("PartyStateChange: PartyStateChangeType::LocalUserRemoved\n");
                if (m_state != NetworkManagerState::Leaving)
                {
                    DEBUGLOG("Unexpected local user removal!\n");
                }
                break;
            }
            case PartyStateChangeType::LeaveNetworkCompleted:
            {
                DEBUGLOG("PartyStateChange: PartyStateChangeType::LeaveNetworkCompleted\n");
                m_state = NetworkManagerState::Initialize;
                if (m_onnetworkdestroyed)
                {
                    m_onnetworkdestroyed();
                }
                break;
            }
            case PartyStateChangeType::NetworkDestroyed:
            {
                DEBUGLOG("PartyStateChange: PartyStateChangeType::NetworkDestroyed\n");
                m_network = nullptr;
                if (m_state != NetworkManagerState::Leaving)
                {
                    DEBUGLOG("Unexpected network destruction!\n");
                    Managers::Get<GameStateManager>()->ResetGame("Unexpected network destruction");
                }
                break;
            }
            case PartyStateChangeType::NetworkConfigurationMadeAvailable:
            {
                DEBUGLOG("PartyStateChange: PartyStateChangeType::NetworkConfigurationMadeAvailable\n");
                break;
            }
            case PartyStateChangeType::RemoteDeviceCreated:
            {
                DEBUGLOG("PartyStateChange: PartyStateChangeType::RemoteDeviceCreated\n");
                break;
            }
            case PartyStateChangeType::RemoteDeviceJoinedNetwork:
            {
                DEBUGLOG("PartyStateChange: PartyStateChangeType::RemoteDeviceJoinedNetwork\n");
                break;
            }
            case PartyStateChangeType::RemoteDeviceDestroyed:
            {
                DEBUGLOG("PartyStateChange: PartyStateChangeType::RemoteDeviceDestroyed\n");
                break;
            }
            case PartyStateChangeType::RemoteDeviceLeftNetwork:
            {
                DEBUGLOG("PartyStateChange: PartyStateChangeType::RemoteDeviceLeftNetwork\n");
                break;
            }
            case PartyStateChangeType::ChatControlJoinedNetwork:
            {
                DEBUGLOG("PartyStateChange: PartyStateChangeType::ChatControlJoinedNetwork\n");
                break;
            }
            case PartyStateChangeType::ChatControlLeftNetwork:
            {
                DEBUGLOG("PartyStateChange: PartyStateChangeType::ChatControlLeftNetwork\n");
                break;
            }
            case PartyStateChangeType::ChatControlDestroyed:
            {
                DEBUGLOG("PartyStateChange: PartyStateChangeType::ChatControlDestroyed\n");
                auto result = static_cast<const PartyChatControlDestroyedStateChange*>(change);
                PartyString sender = nullptr;
                err = result->chatControl->GetEntityId(&sender);

                if (PARTY_FAILED(err))
                {
                    DEBUGLOG("GetEntityId failed: %hs\n", GetErrorMessage(err));
                }
                else
                {
                    DEBUGLOG("Destroyed ChatControl from %hs\n", sender);

                    if (result->chatControl == m_localChatControl)
                    {
                        DEBUGLOG("Local ChatControl destroyed\n");
                        m_localChatControl = nullptr;

                        if (m_state == NetworkManagerState::Leaving)
                        {
                            // Continue the LeaveNetwork process
                            m_network->LeaveNetwork(nullptr);
                        }
                    }
                    else
                    {
                        m_chatControls.erase(sender);
                    }
                }
                break;
            }
            case PartyStateChangeType::ChatControlCreated:
            {
                DEBUGLOG("PartyStateChange: PartyStateChangeType::ChatControlCreated\n");
                auto result = static_cast<const PartyChatControlCreatedStateChange*>(change);
                PartyString sender = nullptr;
                err = result->chatControl->GetEntityId(&sender);

                if (PARTY_FAILED(err))
                {
                    DEBUGLOG("GetEntityId failed: %hs\n", GetErrorMessage(err));
                }
                else
                {
                    DEBUGLOG("Created ChatControl for %hs\n", sender);
                    m_chatControls[sender] = result->chatControl;

                    PartyLocalChatControl* local = nullptr;
                    err = result->chatControl->GetLocal(&local);

                    if (PARTY_FAILED(err))
                    {
                        DEBUGLOG("Failed to get LocalChatControl: %hs\n", GetErrorMessage(err));
                    }
                    else if(local == nullptr)
                    {
                        // Remote ChatControl added, set chat permissions
                        err = m_localChatControl->SetPermissions(
                            result->chatControl,
                            PartyChatPermissionOptions::ReceiveAudio |
                                PartyChatPermissionOptions::ReceiveText |
                                PartyChatPermissionOptions::SendAudio
                            );

                        if (PARTY_FAILED(err))
                        {
                            DEBUGLOG("Failed to SetPermissions on ChatControl: %hs\n", GetErrorMessage(err));
                        }
                    }
                }
                break;
            }
            case PartyStateChangeType::ConnectChatControlCompleted:
            {
                DEBUGLOG("PartyStateChange: PartyStateChangeType::ConnectChatControlCompleted\n");
                auto result = static_cast<const PartyConnectChatControlCompletedStateChange*>(change);
                if (result->result == PartyStateChangeResult::Succeeded)
                {
                    DEBUGLOG("Succeeded\n");
                }
                else
                {
                    DEBUGLOG("Failed: %hs\n", PartyStateChangeResultToReasonString(result->result).c_str());
                    DEBUGLOG("Error detail: %hs\n", GetErrorMessage(result->errorDetail));
                    Managers::Get<ScreenManager>()->ShowError("Voice chat failed");
                }
                break;
            }
            case PartyStateChangeType::CreateChatControlCompleted:
            {
                DEBUGLOG("PartyStateChange: PartyStateChangeType::CreateChatControlCompleted\n");
                auto result = static_cast<const PartyCreateChatControlCompletedStateChange*>(change);
                if (result->result == PartyStateChangeResult::Succeeded)
                {
                    DEBUGLOG("Succeeded\n");
                }
                else
                {
                    DEBUGLOG("Failed: %hs\n", PartyStateChangeResultToReasonString(result->result).c_str());
                    DEBUGLOG("Error detail: %hs\n", GetErrorMessage(result->errorDetail));
                    Managers::Get<ScreenManager>()->ShowError("Voice chat failed");
                }
                break;
            }
            case PartyStateChangeType::LocalChatAudioInputChanged:
            {
                DEBUGLOG("PartyStateChange: PartyStateChangeType::LocalChatAudioInputChanged\n");
                auto result = static_cast<const PartyLocalChatAudioInputChangedStateChange*>(change);
                DEBUGLOG("Audio device: %hs; Selection type: %hs; State: %hs\n",
                    result->audioDeviceIdentifier,
                    PartyAudioDeviceSelectionTypeToString(result->audioDeviceSelectionType).c_str(),
                    PartyAudioInputStateToString(result->state).c_str()
                    );
                if (PARTY_FAILED(result->errorDetail))
                {
                    DEBUGLOG("Error Detail: %hs\n", GetErrorMessage(result->errorDetail));
                }
                break;
            }
            case PartyStateChangeType::SetChatAudioInputCompleted:
            {
                DEBUGLOG("PartyStateChange: PartyStateChangeType::SetChatAudioInputCompleted\n");
                auto result = static_cast<const PartySetChatAudioInputCompletedStateChange*>(change);
                if (result->result == PartyStateChangeResult::Succeeded)
                {
                    DEBUGLOG("Succeeded\n");
                }
                else
                {
                    DEBUGLOG("Failed: %hs\n", PartyStateChangeResultToReasonString(result->result).c_str());
                    Managers::Get<ScreenManager>()->ShowError("Voice chat failed");
                }
                break;
            }
            case PartyStateChangeType::SetChatAudioOutputCompleted:
            {
                DEBUGLOG("PartyStateChange: PartyStateChangeType::SetChatAudioOutputCompleted\n");
                auto result = static_cast<const PartySetChatAudioOutputCompletedStateChange*>(change);
                if (result->result == PartyStateChangeResult::Succeeded)
                {
                    DEBUGLOG("Succeeded\n");
                }
                else
                {
                    DEBUGLOG("Failed: %hs\n", PartyStateChangeResultToReasonString(result->result).c_str());
                    DEBUGLOG("ErrorDetail: %hs\n", GetErrorMessage(result->errorDetail));
                    Managers::Get<ScreenManager>()->ShowError("Voice chat failed");
                }
                break;
            }
            case PartyStateChangeType::LocalChatAudioOutputChanged:
            {
                DEBUGLOG("PartyStateChange: PartyStateChangeType::LocalChatAudioOutputChanged\n");
                auto result = static_cast<const PartyLocalChatAudioOutputChangedStateChange*>(change);
                DEBUGLOG("Audio device: %hs; Selection type: %hs; State: %hs\n",
                    result->audioDeviceIdentifier,
                    PartyAudioDeviceSelectionTypeToString(result->audioDeviceSelectionType).c_str(),
                    PartyAudioOutputStateToString(result->state).c_str()
                    );
                if (PARTY_FAILED(result->errorDetail))
                {
                    DEBUGLOG("Error Detail: %hs\n", GetErrorMessage(result->errorDetail));
                }
                break;
            }
            case PartyStateChangeType::ChatTextReceived:
            {
                DEBUGLOG("PartyStateChange: PartyStateChangeType::ChatTextReceived\n");
                auto result = static_cast<const PartyChatTextReceivedStateChange*>(change);

                // Toast the text on the screen
                Managers::Get<ScreenManager>()->GetSTTWindow()->AddSTTString(
                    DisplayNameFromChatControl(result->senderChatControl),
                    result->chatText,
                    false
                    );

                DEBUGLOG("Chat Text: %hs\n", result->chatText);
                break;
            }
            case PartyStateChangeType::VoiceChatTranscriptionReceived:
            {
                DEBUGLOG("PartyStateChange: PartyStateChangeType::VoiceChatTranscriptionReceived\n");
                auto result = static_cast<const PartyVoiceChatTranscriptionReceivedStateChange*>(change);

                if (PARTY_FAILED(result->errorDetail))
                {
                    DEBUGLOG("Error Detail: %hs\n", GetErrorMessage(result->errorDetail));
                }
                if (result->result != PartyStateChangeResult::Succeeded)
                {
                    DEBUGLOG("Failed: %hs\n", PartyStateChangeResultToReasonString(result->result).c_str());
                }
                else if (result->transcription == nullptr)
                {
                    DEBUGLOG("Transcription is null\n");
                }
                else
                {
                    // Toast the text on the screen
                    Managers::Get<ScreenManager>()->GetSTTWindow()->AddSTTString(
                        DisplayNameFromChatControl(result->senderChatControl),
                        result->transcription,
                        true,
                        result->type == PartyVoiceChatTranscriptionPhraseType::Hypothesis
                        );

                    DEBUGLOG("Chat Transcription: %hs\n", result->transcription);
                }
                break;
            }
            case PartyStateChangeType::SetTranscriptionRequestedCompleted:
            {
                DEBUGLOG("PartyStateChange: PartyStateChangeType::SetTranscriptionRequestedCompleted\n");
                auto result = static_cast<const PartySetTranscriptionRequestedCompletedStateChange*>(change);
                if (PARTY_FAILED(result->errorDetail))
                {
                    DEBUGLOG("Error Detail: %hs\n", GetErrorMessage(result->errorDetail));
                }
                break;
            }
            case PartyStateChangeType::SynthesizeTextToSpeechCompleted:
            {
                DEBUGLOG("PartyStateChangeType::SynthesizeTextToSpeechCompleted\n");
                auto result = static_cast<const PartySynthesizeTextToSpeechCompletedStateChange*>(change);
                if (PARTY_FAILED(result->errorDetail))
                {
                    DEBUGLOG("Error Detail: %hs\n", GetErrorMessage(result->errorDetail));
                }
                if (result->result != PartyStateChangeResult::Succeeded)
                {
                    DEBUGLOG("Failed: %hs\n", PartyStateChangeResultToReasonString(result->result).c_str());
                }
                break;
            }
            case PartyStateChangeType::SetTextToSpeechProfileCompleted:
            {
                DEBUGLOG("PartyStateChangeType::SetTextToSpeechProfileCompleted\n");
                auto result = static_cast<const PartySetTextToSpeechProfileCompletedStateChange*>(change);
                if (PARTY_FAILED(result->errorDetail))
                {
                    DEBUGLOG("Error Detail: %hs\n", GetErrorMessage(result->errorDetail));
                }
                if (result->result != PartyStateChangeResult::Succeeded)
                {
                    DEBUGLOG("Failed: %hs\n", PartyStateChangeResultToReasonString(result->result).c_str());
                }
                break;
            }
            case PartyStateChangeType::RegionsChanged:
            {
                DEBUGLOG("PartyStateChangeType::RegionsChanged\n");
                auto result = static_cast<const PartyRegionsChangedStateChange*>(change);
                if (PARTY_FAILED(result->errorDetail))
                {
                    DEBUGLOG("Error Detail: %hs\n", GetErrorMessage(result->errorDetail));
                }
                if (result->result != PartyStateChangeResult::Succeeded)
                {
                    DEBUGLOG("Failed: %hs\n", PartyStateChangeResultToReasonString(result->result).c_str());
                }
                break;
            }
            default:
                DEBUGLOG("PartyStateChange: %d\n", change->stateChangeType);
                break;
        }
    }

    // Return the processed changes back to CoFa
    err = PartyManager::GetSingleton().FinishProcessingStateChanges(count, changes);

    if (PARTY_FAILED(err))
    {
        DEBUGLOG("FinishProcessingStateChanges failed: %hs\n", GetErrorMessage(err));
    }
}

std::string NetworkManager::DisplayNameFromChatControl(PartyChatControl* control)
{
    std::string sttuser;
    PartyString sender = nullptr;

    auto err = control->GetEntityId(&sender);
    if (PARTY_FAILED(err) || sender == nullptr)
    {
        DEBUGLOG("GetEntityId failed: %hs\n", GetErrorMessage(err));
        sttuser = "[ERROR]";
    }
    else
    {
        std::string senderid(sender);

        // Get the display name of the sender
        auto playerInfo = Managers::Get<GameStateManager>()->GetPlayerState(senderid);

        if (playerInfo != nullptr)
        {
            sttuser = playerInfo->DisplayName;
        }
        else
        {
            sttuser = senderid;
        }
    }

    return sttuser;
}

PartyChatControl* NetworkManager::GetChatControl(std::string& peer)
{
    auto itr = m_chatControls.find(peer);
    if (itr != m_chatControls.end())
    {
        return itr->second;
    }
    return nullptr;
}
