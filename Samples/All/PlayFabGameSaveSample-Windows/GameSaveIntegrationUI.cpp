#include "pch.h"
#include "GameSaveIntegrationUI.h"
#include "game.h"

void ShowRemoteConnectDialogForXUserOnSteamDeck(const std::string& url, const std::string& code, uint32_t userIdentifier)
{
    g_gameState.remoteConnectDialog.showDialog = true;
    g_gameState.remoteConnectDialog.url = url;
    g_gameState.remoteConnectDialog.code = code;
    g_gameState.remoteConnectDialog.userIdentifier = userIdentifier;
    
    AddLog("Showing Remote Connect dialog for user: %u", userIdentifier);
}

void RenderRemoteConnectDialogForXUserOnSteamDeck()
{
    if (!g_gameState.remoteConnectDialog.showDialog)
        return;

    // Set dialog size and position
    ImGui::SetNextWindowSize(ImVec2(520, 320), ImGuiCond_Always);
    ImGui::SetNextWindowPos(ImVec2(ImGui::GetIO().DisplaySize.x * 0.5f, ImGui::GetIO().DisplaySize.y * 0.5f), 
                           ImGuiCond_Always, ImVec2(0.5f, 0.5f));

    // Create modal dialog
    if (ImGui::BeginPopupModal("Xbox Remote Connect", &g_gameState.remoteConnectDialog.showDialog, 
                              ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove))
    {
        // Header with user info
        ImGui::Text("Xbox Remote Connect");
        ImGui::SameLine();
        ImGui::TextColored(ImVec4(0.7f, 0.7f, 0.7f, 1.0f), "- User ID: %u", g_gameState.remoteConnectDialog.userIdentifier);
        ImGui::Separator();
        
        ImGui::Spacing();
        
        // Instructions
        ImGui::TextWrapped("To complete the Xbox sign-in process, please visit the URL below and enter the verification code:");
        
        ImGui::Spacing();
        
        // URL Section with better styling
        ImGui::Text("Website URL:");
        ImGui::PushStyleColor(ImGuiCol_FrameBg, ImVec4(0.15f, 0.15f, 0.15f, 1.0f));
        ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0.9f, 0.9f, 0.9f, 1.0f));
        ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2(8, 6));
        
        // Create a wider input field for URL
        ImGui::SetNextItemWidth(-1.0f);
        ImGui::InputText("##url", const_cast<char*>(g_gameState.remoteConnectDialog.url.c_str()), 
                        g_gameState.remoteConnectDialog.url.length(), ImGuiInputTextFlags_ReadOnly);
        
        ImGui::PopStyleVar();
        ImGui::PopStyleColor(2);
        
        ImGui::Spacing();
        
        // Code Section with enhanced styling
        ImGui::Text("Verification Code:");
        
        // Create a centered, prominent code display
        float codeWidth = 200.0f;
        float windowWidth = ImGui::GetWindowContentRegionMax().x;
        ImGui::SetCursorPosX((windowWidth - codeWidth) * 0.5f);
        
        // Styled code box
        ImGui::PushStyleColor(ImGuiCol_FrameBg, ImVec4(0.25f, 0.35f, 0.55f, 1.0f));
        ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(1.0f, 1.0f, 1.0f, 1.0f));
        ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2(15, 12));
        ImGui::PushStyleVar(ImGuiStyleVar_FrameRounding, 4.0f);
        
        ImGui::SetNextItemWidth(codeWidth);
        char codeBuffer[32];
        strncpy_s(codeBuffer, g_gameState.remoteConnectDialog.code.c_str(), sizeof(codeBuffer) - 1);
        ImGui::InputText("##code", codeBuffer, sizeof(codeBuffer), 
                        ImGuiInputTextFlags_ReadOnly | ImGuiInputTextFlags_CharsNoBlank);
        
        ImGui::PopStyleVar(2);
        ImGui::PopStyleColor(2);
        
        ImGui::Spacing();
        
        // Final instruction
        ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0.8f, 0.8f, 0.8f, 1.0f));
        ImGui::TextWrapped("Once you've entered the code on the website, the connection will be established automatically.");
        ImGui::PopStyleColor();
        
        ImGui::Spacing();
        
        // Center the Cancel button
        float buttonWidth = 120.0f;
        ImGui::SetCursorPosX((windowWidth - buttonWidth) * 0.5f);
        
        if (ImGui::Button("Cancel", ImVec2(buttonWidth, 32)))
        {
            AddLog("Remote Connect dialog cancelled by user");
            CloseRemoteConnectDialogForXUserOnSteamDeck();
        }
        
        ImGui::EndPopup();
    }
}

void CloseRemoteConnectDialogForXUserOnSteamDeck()
{
    g_gameState.remoteConnectDialog.showDialog = false;
    g_gameState.remoteConnectDialog.url.clear();
    g_gameState.remoteConnectDialog.code.clear();
    g_gameState.remoteConnectDialog.userIdentifier = 0;
}

void ShowSyncProgressDialog(PFLocalUserHandle localUserHandle, PFGameSaveFilesSyncState syncState, uint64_t currentBytes, uint64_t totalBytes)
{
    g_gameState.syncProgressDialog.showDialog = true;
    g_gameState.syncProgressDialog.localUserHandle = localUserHandle;
    g_gameState.syncProgressDialog.syncState = syncState;
    g_gameState.syncProgressDialog.currentBytes = currentBytes;
    g_gameState.syncProgressDialog.totalBytes = totalBytes;
    g_gameState.syncProgressDialog.isDownloading = (syncState == PFGameSaveFilesSyncState::Downloading);
    
    AddLog("Showing sync progress dialog - %s: %lld/%lld bytes", 
           g_gameState.syncProgressDialog.isDownloading ? "Downloading" : "Uploading", 
           currentBytes, totalBytes);
}

void RenderSyncProgressDialog()
{
    if (!g_gameState.syncProgressDialog.showDialog)
        return;

    // Get the latest sync progress
    PFGameSaveFilesUiProgressGetProgress(g_gameState.localUserHandle, 
        &g_gameState.syncProgressDialog.syncState, 
        &g_gameState.syncProgressDialog.currentBytes,
        &g_gameState.syncProgressDialog.totalBytes
        );

    // Close the dialog when sync is complete
    if (g_gameState.syncProgressDialog.syncState == PFGameSaveFilesSyncState::SyncComplete)
    {
        AddLog("Sync completed successfully, closing progress dialog");
        CloseSyncProgressDialog();
    }

    // Set dialog size and position
    ImGui::SetNextWindowSize(ImVec2(450, 200), ImGuiCond_Always);
    ImGui::SetNextWindowPos(ImVec2(ImGui::GetIO().DisplaySize.x * 0.5f, ImGui::GetIO().DisplaySize.y * 0.5f), 
                           ImGuiCond_Always, ImVec2(0.5f, 0.5f));

    // Create modal dialog
    if (ImGui::BeginPopupModal("Game Save Sync", &g_gameState.syncProgressDialog.showDialog, 
                              ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove))
    {
        // Title based on sync state
        const char* actionText = g_gameState.syncProgressDialog.isDownloading ? "Downloading" : "Uploading";
        ImGui::Text("%s game save data...", actionText);
        ImGui::Separator();
        
        ImGui::Spacing();
        
        // Progress calculation
        float progress = 0.0f;
        if (g_gameState.syncProgressDialog.totalBytes > 0)
        {
            progress = (float)g_gameState.syncProgressDialog.currentBytes / (float)g_gameState.syncProgressDialog.totalBytes;
        }
        
        // Progress bar
        ImGui::Text("Progress:");
        ImGui::ProgressBar(progress, ImVec2(-1.0f, 0.0f), "");
        
        // Progress text
        ImGui::Text("%lld / %lld bytes (%.1f%%)", 
                   g_gameState.syncProgressDialog.currentBytes, 
                   g_gameState.syncProgressDialog.totalBytes,
                   progress * 100.0f);
        
        ImGui::Spacing();
        
        // Status text
        ImGui::TextWrapped("Please wait while we sync your game save data with the cloud.");
        
        ImGui::Spacing();
        
        // Center the Cancel button
        float buttonWidth = 120.0f;
        float windowWidth = ImGui::GetWindowContentRegionMax().x;
        ImGui::SetCursorPosX((windowWidth - buttonWidth) * 0.5f);
        
        if (ImGui::Button("Cancel", ImVec2(buttonWidth, 30)))
        {
            AddLog("Sync progress cancelled by user");
            
            // Call the PlayFab API to cancel the sync operation
            if (g_gameState.syncProgressDialog.localUserHandle != nullptr)
            {
                PFGameSaveFilesSetUiProgressResponse(g_gameState.syncProgressDialog.localUserHandle, PFGameSaveFilesUiProgressUserAction::Cancel);
            }
            
            CloseSyncProgressDialog();
        }
        
        ImGui::EndPopup();
    }
}

void CloseSyncProgressDialog()
{
    g_gameState.syncProgressDialog.showDialog = false;
    g_gameState.syncProgressDialog.localUserHandle = nullptr;
    g_gameState.syncProgressDialog.syncState = PFGameSaveFilesSyncState::NotStarted;
    g_gameState.syncProgressDialog.currentBytes = 0;
    g_gameState.syncProgressDialog.totalBytes = 0;
    g_gameState.syncProgressDialog.isDownloading = false;
}

void ShowSyncFailedDialog(PFLocalUserHandle localUserHandle, HRESULT errorCode)
{
    if( g_gameState.syncProgressDialog.showDialog )
    {
        AddLog("Sync failed dialog: Closing progress dialog");
        CloseSyncProgressDialog();
    }

    g_gameState.syncFailedDialog.showDialog = true;
    g_gameState.syncFailedDialog.localUserHandle = localUserHandle;
    g_gameState.syncFailedDialog.errorCode = errorCode;
    
    AddLog("Showing sync failed dialog - Error: 0x%08X", errorCode);
}

void RenderSyncFailedDialog()
{
    if (!g_gameState.syncFailedDialog.showDialog)
        return;

    // Set dialog size and position
    ImGui::SetNextWindowSize(ImVec2(500, 220), ImGuiCond_Always);
    ImGui::SetNextWindowPos(ImVec2(ImGui::GetIO().DisplaySize.x * 0.5f, ImGui::GetIO().DisplaySize.y * 0.5f), 
                           ImGuiCond_Always, ImVec2(0.5f, 0.5f));

    // Create modal dialog
    if (ImGui::BeginPopupModal("Sync Failed", &g_gameState.syncFailedDialog.showDialog, 
                              ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove))
    {
        ImGui::Text("Sync Error");
        ImGui::Separator();
        
        ImGui::Spacing();
        
        // Error message
        ImGui::TextWrapped("We couldn't sync your data with the cloud just now.");
        ImGui::Spacing();
        ImGui::TextWrapped("Try syncing again or use this game offline.");
        
        ImGui::Spacing();
        
        // Error code display
        ImGui::Text("Error Code: 0x%08X", g_gameState.syncFailedDialog.errorCode);
        
        ImGui::Spacing();
        
        // Button layout
        float buttonWidth = 120.0f;
        float spacing = 10.0f;
        float totalWidth = (buttonWidth * 3) + (spacing * 2);
        float windowWidth = ImGui::GetWindowContentRegionMax().x;
        float startX = (windowWidth - totalWidth) * 0.5f;
        
        ImGui::SetCursorPosX(startX);
        
        // Try Again button
        if (ImGui::Button("Try Again", ImVec2(buttonWidth, 30)))
        {
            AddLog("Sync failed dialog: User chose Try Again");
            
            if (g_gameState.syncFailedDialog.localUserHandle != nullptr)
            {
                PFGameSaveFilesSetUiSyncFailedResponse(g_gameState.syncFailedDialog.localUserHandle, PFGameSaveFilesUiSyncFailedUserAction::Retry);
            }
            
            CloseSyncFailedDialog();
        }
        
        ImGui::SameLine(0, spacing);
        
        // Use Offline button
        if (ImGui::Button("Use Offline", ImVec2(buttonWidth, 30)))
        {
            AddLog("Sync failed dialog: User chose Use Offline");
            
            if (g_gameState.syncFailedDialog.localUserHandle != nullptr)
            {
                PFGameSaveFilesSetUiSyncFailedResponse(g_gameState.syncFailedDialog.localUserHandle, PFGameSaveFilesUiSyncFailedUserAction::UseOffline);
            }
            
            CloseSyncFailedDialog();
        }
        
        ImGui::SameLine(0, spacing);
        
        // Cancel button
        if (ImGui::Button("Cancel", ImVec2(buttonWidth, 30)))
        {
            AddLog("Sync failed dialog: User chose Cancel");
            
            if (g_gameState.syncFailedDialog.localUserHandle != nullptr)
            {
                PFGameSaveFilesSetUiSyncFailedResponse(g_gameState.syncFailedDialog.localUserHandle, PFGameSaveFilesUiSyncFailedUserAction::Cancel);
            }
            
            CloseSyncFailedDialog();
        }
        
        ImGui::EndPopup();
    }
}

void CloseSyncFailedDialog()
{
    g_gameState.syncFailedDialog.showDialog = false;
    g_gameState.syncFailedDialog.localUserHandle = nullptr;
    g_gameState.syncFailedDialog.errorCode = S_OK;
}

void ShowActiveDeviceContentionDialog(PFLocalUserHandle localUserHandle, PFGameSaveDescriptor* localGameSave, PFGameSaveDescriptor* remoteGameSave)
{
    if( g_gameState.syncProgressDialog.showDialog )
    {
        AddLog("Active device contention dialog: Closing progress dialog");
        CloseSyncProgressDialog();
    }

    g_gameState.activeDeviceContentionDialog.showDialog = true;
    g_gameState.activeDeviceContentionDialog.localUserHandle = localUserHandle;
    
    // Copy the game save descriptors
    if (localGameSave)
        g_gameState.activeDeviceContentionDialog.localGameSave = *localGameSave;
    if (remoteGameSave)
        g_gameState.activeDeviceContentionDialog.remoteGameSave = *remoteGameSave;
    
    AddLog("Showing active device contention dialog");
}

void RenderActiveDeviceContentionDialog()
{
    if (!g_gameState.activeDeviceContentionDialog.showDialog)
        return;

    // Set dialog size and position
    ImGui::SetNextWindowSize(ImVec2(580, 200), ImGuiCond_Always);
    ImGui::SetNextWindowPos(ImVec2(ImGui::GetIO().DisplaySize.x * 0.5f, ImGui::GetIO().DisplaySize.y * 0.5f), 
                           ImGuiCond_Always, ImVec2(0.5f, 0.5f));

    // Create modal dialog
    if (ImGui::BeginPopupModal("Active Device Contention", &g_gameState.activeDeviceContentionDialog.showDialog, 
                              ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove))
    {
        ImGui::Text("Device Sync Conflict");
        ImGui::Separator();
        
        ImGui::Spacing();
        
        // Main message
        ImGui::TextWrapped("You may have unsynced progress on a previous device.");
        ImGui::Spacing();
        ImGui::TextWrapped("Please return to the game on that device to continue your latest progress there.");
        ImGui::TextWrapped("Otherwise continue playing from your last synced cloud data on this device.");
        
        // Remote game save info (if available)
        if (g_gameState.activeDeviceContentionDialog.remoteGameSave.deviceFriendlyName[0] != '\0')
        {
            ImGui::Spacing();
            ImGui::Text("Last played on:");
            ImGui::BulletText("Device: %s", g_gameState.activeDeviceContentionDialog.remoteGameSave.deviceFriendlyName);
            ImGui::BulletText("Size: %llu bytes", g_gameState.activeDeviceContentionDialog.remoteGameSave.totalBytes);
            // Note: time would need to be converted to a readable format
        }
        
        ImGui::Spacing();
        
        // Button layout - horizontal with different sizes
        float longButtonWidth = 240.0f;  // For "Continue from Last Cloud Data" - increased width
        float shortButtonWidth = 70.0f;  // For "Retry" and "Cancel"
        float spacing = 8.0f;
        float totalWidth = longButtonWidth + (shortButtonWidth * 2) + (spacing * 2);
        float windowWidth = ImGui::GetWindowContentRegionMax().x;
        float startX = (windowWidth - totalWidth) * 0.5f;
        
        ImGui::SetCursorPosX(startX);
        
        // Continue from last cloud data button
        if (ImGui::Button("Continue from Last Cloud Data", ImVec2(longButtonWidth, 30)))
        {
            AddLog("Active device contention dialog: User chose continue with last cloud data");
            
            // Show confirmation dialog instead of directly calling PlayFab API
            ShowCloudDataConfirmationDialog(g_gameState.activeDeviceContentionDialog.localUserHandle, 
                &g_gameState.activeDeviceContentionDialog.remoteGameSave);
            
            CloseActiveDeviceContentionDialog();
        }
        
        ImGui::SameLine(0, spacing);
        
        // Retry button
        if (ImGui::Button("Retry", ImVec2(shortButtonWidth, 30)))
        {
            AddLog("Active device contention dialog: User chose Retry");
            
            if (g_gameState.activeDeviceContentionDialog.localUserHandle != nullptr)
            {
                PFGameSaveFilesSetUiActiveDeviceContentionResponse(g_gameState.activeDeviceContentionDialog.localUserHandle, 
                    PFGameSaveFilesUiActiveDeviceContentionUserAction::Retry);
            }
            
            CloseActiveDeviceContentionDialog();
        }
        
        ImGui::SameLine(0, spacing);
        
        // Cancel button
        if (ImGui::Button("Cancel", ImVec2(shortButtonWidth, 30)))
        {
            AddLog("Active device contention dialog: User chose Cancel");
            
            if (g_gameState.activeDeviceContentionDialog.localUserHandle != nullptr)
            {
                PFGameSaveFilesSetUiActiveDeviceContentionResponse(g_gameState.activeDeviceContentionDialog.localUserHandle, 
                    PFGameSaveFilesUiActiveDeviceContentionUserAction::Cancel);
            }
            
            CloseActiveDeviceContentionDialog();
        }
        
        ImGui::EndPopup();
    }
}

void CloseActiveDeviceContentionDialog()
{
    g_gameState.activeDeviceContentionDialog.showDialog = false;
    g_gameState.activeDeviceContentionDialog.localUserHandle = nullptr;
    memset(&g_gameState.activeDeviceContentionDialog.localGameSave, 0, sizeof(PFGameSaveDescriptor));
    memset(&g_gameState.activeDeviceContentionDialog.remoteGameSave, 0, sizeof(PFGameSaveDescriptor));
}

void ShowConflictDialog(PFLocalUserHandle localUserHandle, PFGameSaveDescriptor* localGameSave, PFGameSaveDescriptor* remoteGameSave)
{
    if (g_gameState.syncProgressDialog.showDialog)
    {
        AddLog("Conflict dialog: Closing progress dialog");
        CloseSyncProgressDialog();
    }

    g_gameState.conflictDialog.showDialog = true;
    g_gameState.conflictDialog.localUserHandle = localUserHandle;
    
    // Copy the game save descriptors
    if (localGameSave)
        g_gameState.conflictDialog.localGameSave = *localGameSave;
    if (remoteGameSave)
        g_gameState.conflictDialog.remoteGameSave = *remoteGameSave;
    
    AddLog("Showing conflict dialog");
}

void RenderConflictDialog()
{
    if (!g_gameState.conflictDialog.showDialog)
        return;

    // Set dialog size and position
    ImGui::SetNextWindowSize(ImVec2(700, 270), ImGuiCond_Always);
    ImGui::SetNextWindowPos(ImVec2(ImGui::GetIO().DisplaySize.x * 0.5f, ImGui::GetIO().DisplaySize.y * 0.5f), 
                           ImGuiCond_Always, ImVec2(0.5f, 0.5f));

    // Create modal dialog
    if (ImGui::BeginPopupModal("Save Data Conflict", &g_gameState.conflictDialog.showDialog, 
                              ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove))
    {
        ImGui::Text("Save Data Conflict");
        ImGui::Separator();
        
        ImGui::Spacing();
        
        // Main message
        ImGui::Text("Which one do you want to use?");
        ImGui::TextWrapped("The save data we have on the cloud network is different than the data on this device.");
        
        ImGui::Spacing();
        ImGui::Separator();
        ImGui::Spacing();
        
        // Create two columns for save data comparison
        if (ImGui::BeginTable("SaveDataComparison", 2, ImGuiTableFlags_Borders | ImGuiTableFlags_SizingStretchSame))
        {
            ImGui::TableSetupColumn("This Device", ImGuiTableColumnFlags_WidthStretch);
            ImGui::TableSetupColumn("Cloud Data", ImGuiTableColumnFlags_WidthStretch);
            ImGui::TableHeadersRow();
            
            ImGui::TableNextRow();
            
            // Local save column
            ImGui::TableNextColumn();
            ImGui::Text("This Device Save");
            if (g_gameState.conflictDialog.localGameSave.deviceFriendlyName[0] != '\0')
            {
                ImGui::BulletText("Device: %s", g_gameState.conflictDialog.localGameSave.deviceFriendlyName);
            }
            ImGui::BulletText("Size: %llu bytes", g_gameState.conflictDialog.localGameSave.totalBytes);
            
            // Convert time_t to readable format (simplified)
            char timeStr[64];
            struct tm timeInfo;
            if (localtime_s(&timeInfo, &g_gameState.conflictDialog.localGameSave.time) == 0)
            {
                strftime(timeStr, sizeof(timeStr), "%Y-%m-%d %H:%M:%S", &timeInfo);
                ImGui::BulletText("Modified: %s", timeStr);
            }
            
            // Remote save column
            ImGui::TableNextColumn();
            ImGui::Text("Cloud Save");
            if (g_gameState.conflictDialog.remoteGameSave.deviceFriendlyName[0] != '\0')
            {
                ImGui::BulletText("Device: %s", g_gameState.conflictDialog.remoteGameSave.deviceFriendlyName);
            }
            ImGui::BulletText("Size: %llu bytes", g_gameState.conflictDialog.remoteGameSave.totalBytes);
            
            // Convert time_t to readable format (simplified)
            if (localtime_s(&timeInfo, &g_gameState.conflictDialog.remoteGameSave.time) == 0)
            {
                strftime(timeStr, sizeof(timeStr), "%Y-%m-%d %H:%M:%S", &timeInfo);
                ImGui::BulletText("Modified: %s", timeStr);
            }
            
            ImGui::EndTable();
        }
        
        ImGui::Spacing();
        ImGui::Separator();
        ImGui::Spacing();
        
        // Button layout
        float buttonWidth = 150.0f;
        float spacing = 15.0f;
        float totalWidth = (buttonWidth * 3) + (spacing * 2);
        float windowWidth = ImGui::GetWindowContentRegionMax().x;
        float startX = (windowWidth - totalWidth) * 0.5f;
        
        ImGui::SetCursorPosX(startX);
        
        // This Device button
        if (ImGui::Button("Use This Device", ImVec2(buttonWidth, 30)))
        {
            AddLog("Conflict dialog: User chose This Device");
            
            if (g_gameState.conflictDialog.localUserHandle != nullptr)
            {
                PFGameSaveFilesSetUiConflictResponse(g_gameState.conflictDialog.localUserHandle, 
                    PFGameSaveFilesUiConflictUserAction::TakeLocal);
            }
            
            CloseConflictDialog();
        }
        
        ImGui::SameLine(0, spacing);
        
        // Cloud Data button
        if (ImGui::Button("Use Cloud Data", ImVec2(buttonWidth, 30)))
        {
            AddLog("Conflict dialog: User chose Cloud Data");
            
            if (g_gameState.conflictDialog.localUserHandle != nullptr)
            {
                PFGameSaveFilesSetUiConflictResponse(g_gameState.conflictDialog.localUserHandle, 
                    PFGameSaveFilesUiConflictUserAction::TakeRemote);
            }
            
            CloseConflictDialog();
        }
        
        ImGui::SameLine(0, spacing);
        
        // Cancel button
        if (ImGui::Button("Cancel", ImVec2(buttonWidth, 30)))
        {
            AddLog("Conflict dialog: User chose Cancel");
            
            if (g_gameState.conflictDialog.localUserHandle != nullptr)
            {
                PFGameSaveFilesSetUiConflictResponse(g_gameState.conflictDialog.localUserHandle, 
                    PFGameSaveFilesUiConflictUserAction::Cancel);
            }
            
            CloseConflictDialog();
        }
        
        ImGui::EndPopup();
    }
}

void CloseConflictDialog()
{
    g_gameState.conflictDialog.showDialog = false;
    g_gameState.conflictDialog.localUserHandle = nullptr;
    memset(&g_gameState.conflictDialog.localGameSave, 0, sizeof(PFGameSaveDescriptor));
    memset(&g_gameState.conflictDialog.remoteGameSave, 0, sizeof(PFGameSaveDescriptor));
}

// Out of Storage Dialog Functions
void ShowOutOfStorageDialog(PFLocalUserHandle localUserHandle, uint64_t requiredBytes)
{
    if (g_gameState.syncProgressDialog.showDialog)
    {
        AddLog("Out of storage dialog: Closing progress dialog");
        CloseSyncProgressDialog();
    }

    g_gameState.outOfStorageDialog.showDialog = true;
    g_gameState.outOfStorageDialog.localUserHandle = localUserHandle;
    g_gameState.outOfStorageDialog.requiredBytes = requiredBytes;
    
    AddLog("Showing Out of Storage dialog - Required bytes: %llu", requiredBytes);
}

void RenderOutOfStorageDialog()
{
    if (!g_gameState.outOfStorageDialog.showDialog)
        return;

    // Set dialog size and position
    ImGui::SetNextWindowSize(ImVec2(480, 220), ImGuiCond_Always);
    ImGui::SetNextWindowPos(ImVec2(ImGui::GetIO().DisplaySize.x * 0.5f, ImGui::GetIO().DisplaySize.y * 0.5f), 
                           ImGuiCond_Always, ImVec2(0.5f, 0.5f));

    if (ImGui::BeginPopupModal("Not Enough Storage", nullptr, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove))
    {
        ImGui::Text("Not Enough Storage");
        ImGui::Separator();
        
        ImGui::Spacing();
        
        ImGui::TextWrapped("We could not save your progress because your device is out of storage.");
        ImGui::TextWrapped("Please free up space and try again.");
        ImGui::Spacing();
        
        // Format required bytes in a human-readable way
        double displayBytes = static_cast<double>(g_gameState.outOfStorageDialog.requiredBytes);
        const char* unit = "bytes";
        
        if (displayBytes >= 1024.0)
        {
            displayBytes /= 1024.0;
            unit = "KB";
            
            if (displayBytes >= 1024.0)
            {
                displayBytes /= 1024.0;
                unit = "MB";
                
                if (displayBytes >= 1024.0)
                {
                    displayBytes /= 1024.0;
                    unit = "GB";
                }
            }
        }
        
        // Display required space if available
        if (g_gameState.outOfStorageDialog.requiredBytes > 0)
        {
            ImGui::Text("Space needed: %.2f %s", displayBytes, unit);
        }
        
        ImGui::Spacing();
        ImGui::Separator();
        ImGui::Spacing();

        // Center the buttons
        float buttonWidth = 100.0f;
        float spacing = 10.0f;
        float totalWidth = (buttonWidth * 2) + spacing;
        float windowWidth = ImGui::GetWindowContentRegionMax().x;
        float startX = (windowWidth - totalWidth) * 0.5f;
        
        ImGui::SetCursorPosX(startX);

        if (ImGui::Button("Try Again", ImVec2(buttonWidth, 30)))
        {
            AddLog("User chose: Try Again for out of storage");
            if (g_gameState.outOfStorageDialog.localUserHandle)
            {
                HRESULT hr = PFGameSaveFilesSetUiOutOfStorageResponse(
                    g_gameState.outOfStorageDialog.localUserHandle, 
                    PFGameSaveFilesUiOutOfStorageUserAction::Retry
                );
                if (FAILED(hr))
                {
                    AddLog("Failed to set out of storage response (Retry): 0x%08X", hr);
                }
            }
            CloseOutOfStorageDialog();
        }

        ImGui::SameLine(0, spacing);

        if (ImGui::Button("Cancel", ImVec2(buttonWidth, 30)))
        {
            AddLog("User chose: Cancel for out of storage");
            if (g_gameState.outOfStorageDialog.localUserHandle)
            {
                HRESULT hr = PFGameSaveFilesSetUiOutOfStorageResponse(
                    g_gameState.outOfStorageDialog.localUserHandle, 
                    PFGameSaveFilesUiOutOfStorageUserAction::Cancel
                );
                if (FAILED(hr))
                {
                    AddLog("Failed to set out of storage response (Cancel): 0x%08X", hr);
                }
            }
            CloseOutOfStorageDialog();
        }

        ImGui::EndPopup();
    }
}

void CloseOutOfStorageDialog()
{
    g_gameState.outOfStorageDialog.showDialog = false;
    g_gameState.outOfStorageDialog.localUserHandle = nullptr;
    g_gameState.outOfStorageDialog.requiredBytes = 0;
}

// Cloud Data Confirmation Dialog Functions
void ShowCloudDataConfirmationDialog(PFLocalUserHandle localUserHandle, PFGameSaveDescriptor* remoteGameSave)
{
    g_gameState.cloudDataConfirmationDialog.showDialog = true;
    g_gameState.cloudDataConfirmationDialog.localUserHandle = localUserHandle;
    
    // Copy the remote game save descriptor
    if (remoteGameSave)
        g_gameState.cloudDataConfirmationDialog.remoteGameSave = *remoteGameSave;
    
    AddLog("Showing cloud data confirmation dialog");
}

void RenderCloudDataConfirmationDialog()
{
    if (!g_gameState.cloudDataConfirmationDialog.showDialog)
        return;

    // Set dialog size and position
    ImGui::SetNextWindowSize(ImVec2(520, 220), ImGuiCond_Always);
    ImGui::SetNextWindowPos(ImVec2(ImGui::GetIO().DisplaySize.x * 0.5f, ImGui::GetIO().DisplaySize.y * 0.5f), 
                           ImGuiCond_Always, ImVec2(0.5f, 0.5f));

    // Create modal dialog
    if (ImGui::BeginPopupModal("Confirm Cloud Data", &g_gameState.cloudDataConfirmationDialog.showDialog, 
                              ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove))
    {
        ImGui::Text("Confirm Continue from Cloud Data");
        ImGui::Separator();
        
        ImGui::Spacing();
        
        // Main confirmation message
        ImGui::TextWrapped("Are you sure you want to continue from your last saved cloud data?");
        ImGui::Spacing();
        ImGui::TextWrapped("Your previous game save will remain on your other device and you can continue playing from your last cloud save:");
        
        ImGui::Spacing();
        
        // Remote game save info (if available)
        if (g_gameState.cloudDataConfirmationDialog.remoteGameSave.deviceFriendlyName[0] != '\0')
        {
            ImGui::Text("Last cloud save:");
            ImGui::BulletText("Device: %s", g_gameState.cloudDataConfirmationDialog.remoteGameSave.deviceFriendlyName);
            ImGui::BulletText("Size: %llu bytes", g_gameState.cloudDataConfirmationDialog.remoteGameSave.totalBytes);
            
            // Convert time_t to readable format
            char timeStr[64];
            struct tm timeInfo;
            if (localtime_s(&timeInfo, &g_gameState.cloudDataConfirmationDialog.remoteGameSave.time) == 0)
            {
                strftime(timeStr, sizeof(timeStr), "%Y-%m-%d %H:%M:%S", &timeInfo);
                ImGui::BulletText("Modified: %s", timeStr);
            }
        }
        
        ImGui::Spacing();
        ImGui::Separator();
        ImGui::Spacing();
        
        // Button layout
        float shortButtonWidth = 120.0f;   // For "Go Back"
        float longButtonWidth = 240.0f;    // For "Continue from Last Cloud Data" - same as ActiveDeviceContention dialog
        float spacing = 10.0f;
        float totalWidth = shortButtonWidth + longButtonWidth + spacing;
        float windowWidth = ImGui::GetWindowContentRegionMax().x;
        float startX = (windowWidth - totalWidth) * 0.5f;
        
        ImGui::SetCursorPosX(startX);
        
        // Continue from Last Cloud Data button
        if (ImGui::Button("Continue from Last Cloud Data", ImVec2(longButtonWidth, 30)))
        {
            AddLog("Cloud data confirmation dialog: User confirmed continue with last cloud data");
            
            if (g_gameState.cloudDataConfirmationDialog.localUserHandle != nullptr)
            {
                PFGameSaveFilesSetUiActiveDeviceContentionResponse(g_gameState.cloudDataConfirmationDialog.localUserHandle, 
                    PFGameSaveFilesUiActiveDeviceContentionUserAction::SyncLastSavedData);
            }
            
            CloseCloudDataConfirmationDialog();
        }
        
        ImGui::SameLine(0, spacing);
        
        // Go Back button
        if (ImGui::Button("Go Back", ImVec2(shortButtonWidth, 30)))
        {
            AddLog("Cloud data confirmation dialog: User chose Go Back");
            
            // Close this dialog and show the ActiveDeviceContention dialog again
            CloseCloudDataConfirmationDialog();
            g_gameState.activeDeviceContentionDialog.showDialog = true;
        }
        
        ImGui::EndPopup();
    }
}

void CloseCloudDataConfirmationDialog()
{
    g_gameState.cloudDataConfirmationDialog.showDialog = false;
    g_gameState.cloudDataConfirmationDialog.localUserHandle = nullptr;
    memset(&g_gameState.cloudDataConfirmationDialog.remoteGameSave, 0, sizeof(PFGameSaveDescriptor));
}

void ShowSpopPromptDialogForXUserOnSteamDeck(uint32_t userIdentifier, XUserPlatformOperation* operation, const std::string& modernGamertag, const std::string& modernGamertagSuffix)
{
    g_gameState.spopPromptDialog.showDialog = true;
    g_gameState.spopPromptDialog.userIdentifier = userIdentifier;
    g_gameState.spopPromptDialog.operation = operation ? *operation : nullptr;
    g_gameState.spopPromptDialog.modernGamertag = modernGamertag;
    g_gameState.spopPromptDialog.modernGamertagSuffix = modernGamertagSuffix;
    
    AddLog("Showing SPOP Prompt dialog for user: %u, gamertag: %s%s", userIdentifier, modernGamertag.c_str(), modernGamertagSuffix.c_str());
}

void RenderSpopPromptDialogForXUserOnSteamDeck()
{
    if (!g_gameState.spopPromptDialog.showDialog)
        return;

    // Set dialog size and position
    ImGui::SetNextWindowSize(ImVec2(520, 280), ImGuiCond_Always);
    ImGui::SetNextWindowPos(ImVec2(ImGui::GetIO().DisplaySize.x * 0.5f, ImGui::GetIO().DisplaySize.y * 0.5f), 
                           ImGuiCond_Always, ImVec2(0.5f, 0.5f));

    if (ImGui::BeginPopupModal("Xbox Sign-In Prompt", nullptr, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove))
    {
        ImGui::Text("Xbox User Sign-In Required");
        ImGui::Separator();
        
        ImGui::Spacing();
        
        // Main message
        ImGui::TextWrapped("Your account has been signed in on another device. What do you want to do?");
        
        ImGui::Spacing();
        
        ImGui::Text("User ID: %u", g_gameState.spopPromptDialog.userIdentifier);
        if (!g_gameState.spopPromptDialog.modernGamertag.empty())
        {
            ImGui::Text("Gamertag: %s%s", 
                g_gameState.spopPromptDialog.modernGamertag.c_str(),
                g_gameState.spopPromptDialog.modernGamertagSuffix.c_str());
        }
        
        ImGui::Spacing();
        ImGui::Separator();
        ImGui::Spacing();
        
        ImGui::Text("Please choose an option:");
        
        ImGui::Spacing();
        
        // Button layout
        float buttonWidth = 140.0f;
        float spacing = 10.0f;
        float totalWidth = (buttonWidth * 3) + (spacing * 2);
        float windowWidth = ImGui::GetWindowContentRegionMax().x;
        float startX = (windowWidth - totalWidth) * 0.5f;
        
        ImGui::SetCursorPosX(startX);
        
        if (ImGui::Button("Sign In Here", ImVec2(buttonWidth, 30)))
        {
            AddLog("User chose: Sign In Here");
            XUserPlatformSpopPromptComplete(g_gameState.spopPromptDialog.operation, XUserPlatformSpopOperationResult::SignInHere);
            CloseSpopPromptDialogForXUserOnSteamDeck();
        }
        
        ImGui::SameLine(0, spacing);
        if (ImGui::Button("Switch Account", ImVec2(buttonWidth, 30)))
        {
            AddLog("User chose: Switch Account");
            XUserPlatformSpopPromptComplete(g_gameState.spopPromptDialog.operation, XUserPlatformSpopOperationResult::SwitchAccount);
            CloseSpopPromptDialogForXUserOnSteamDeck();
        }
        
        ImGui::SameLine(0, spacing);
        if (ImGui::Button("Cancel", ImVec2(buttonWidth, 30)))
        {
            AddLog("User chose: Cancel");
            XUserPlatformSpopPromptComplete(g_gameState.spopPromptDialog.operation, XUserPlatformSpopOperationResult::Canceled);
            CloseSpopPromptDialogForXUserOnSteamDeck();
        }
        
        ImGui::EndPopup();
    }
}

void CloseSpopPromptDialogForXUserOnSteamDeck()
{
    g_gameState.spopPromptDialog.showDialog = false;
    g_gameState.spopPromptDialog.userIdentifier = 0;
    g_gameState.spopPromptDialog.operation = nullptr;
    g_gameState.spopPromptDialog.modernGamertag.clear();
    g_gameState.spopPromptDialog.modernGamertagSuffix.clear();
}
