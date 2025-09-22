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
    bool steamAvailable{ false };
    bool isSteamDeck{ false };
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
