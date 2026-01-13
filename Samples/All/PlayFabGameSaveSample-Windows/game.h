// Copyright (C) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License. See LICENSE in the project root for license information.

#pragma once

#include "GameSaveIntegrationUI.h"

// Global game state structure
struct GameState
{
    std::vector<std::string> logMessages;
    PFServiceConfigHandle serviceConfigHandle{ nullptr };
    XUserHandle xuser{ nullptr };
    PFLocalUserHandle localUserHandle{ nullptr };
#ifdef ENABLE_STEAM_SDK
    bool steamAvailable{ false };
    bool isSteamDeck{ false };
#endif
    bool gameSavesInitialized{ false };
    bool userSignedIn{ false };
    bool userSignedInViaXbox{ false };
    bool userAddedToGameSavePending{ false };
    bool userAddedToGameSave{ false };
    bool uploadInProgress{ false };
    bool userSignInPending{ false };
    std::string saveFolder;
    int64_t remainingQuota{ 0 };
    XTaskQueueHandle queue{ nullptr };
    
    // Advanced options UI state
    bool showAdvancedOptions{ false };
    bool forceInproc{ false };
    bool setUiCallbacks{ false };
    
    // Dialog states
    RemoteConnectDialogState remoteConnectDialog;
    SpopPromptDialogState spopPromptDialog;
    SyncProgressDialogState syncProgressDialog;
    SyncFailedDialogState syncFailedDialog;
    ActiveDeviceContentionDialogState activeDeviceContentionDialog;
    ConflictDialogState conflictDialog;
    OutOfStorageDialogState outOfStorageDialog;
    ActiveDeviceChangedDialogState activeDeviceChangedDialog;
    CloudDataConfirmationDialogState cloudDataConfirmationDialog;
};

extern GameState g_gameState;

// Global function to add log messages
void AddLog(const std::string& message);
void AddLog(const char* format, ...);

// Debug trace callback used to forward libHttpClient traces to the debugger
void MyDebugTrace(
    _In_z_ const char* areaName,
    _In_ HCTraceLevel level,
    _In_ uint64_t threadId,
    _In_ uint64_t timestamp,
    _In_z_ const char* message);
