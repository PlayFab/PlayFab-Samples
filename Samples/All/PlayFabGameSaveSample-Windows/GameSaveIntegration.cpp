#include "pch.h"
#include "GameSaveIntegration.h"
#include "GameSaveIntegrationUI.h"
#include "SteamIntegration.h"
#include "Game.h"
#include <windows.h>

void OnPFGameSaveFilesUiProgress(
    _In_ PFLocalUserHandle localUserHandle, 
    _In_ PFGameSaveFilesSyncState syncState, 
    _In_ void* context)
{
    PFGameSaveFilesSyncState state{};
    uint64_t current{};
    uint64_t total{};
    PFGameSaveFilesUiProgressGetProgress(localUserHandle, &syncState, &current, &total);
    
    ShowSyncProgressDialog(localUserHandle, syncState, current, total);
    
    // Close the dialog when sync is complete
    if (syncState == PFGameSaveFilesSyncState::SyncComplete)
    {
        AddLog("Sync completed successfully, closing progress dialog");
        CloseSyncProgressDialog();
    }
}

void OnPFGameSaveFilesUiSyncFailed(
    _In_ PFLocalUserHandle localUserHandle,
    _In_ PFGameSaveFilesSyncState syncState,
    _In_ HRESULT error,
    _In_ void* context)
{
    AddLog("Sync failed with error: 0x%08X", error);
    
    // Close the progress dialog first
    CloseSyncProgressDialog();
    
    // Show the sync failed dialog
    ShowSyncFailedDialog(localUserHandle, error);
}

void OnPFGameSaveFilesUiActiveDeviceContention(
    _In_ PFLocalUserHandle localUserHandle, 
    _In_ PFGameSaveDescriptor* localGameSave, 
    _In_ PFGameSaveDescriptor* remoteGameSave, 
    _In_ void* context)
{
    AddLog("Active device contention detected");
    
    // Show the active device contention dialog
    ShowActiveDeviceContentionDialog(localUserHandle, localGameSave, remoteGameSave);
}

void OnPFGameSaveFilesUiConflict(
    _In_ PFLocalUserHandle localUserHandle,
    _In_ PFGameSaveDescriptor* localGameSave,
    _In_ PFGameSaveDescriptor* remoteGameSave,
    _In_ void* context)
{
    AddLog("Save data conflict detected");
    
    // Show the conflict dialog
    ShowConflictDialog(localUserHandle, localGameSave, remoteGameSave);
}

void OnPFGameSaveFilesUiOutOfStorage(
    _In_ PFLocalUserHandle localUserHandle, 
    _In_ uint64_t requiredBytes, 
    _In_ void* context)
{
    AddLog("Out of storage: Required bytes: %llu", requiredBytes);

    // Show the out of storage dialog
    ShowOutOfStorageDialog(localUserHandle, requiredBytes);
}

// When your title receives an Active Device Changed event, it means the player 
// has become active on another device. The current device is no longer the
// primary active session, but it can continue to make offline progress.
//
// There is no required action on your part—game saves will automatically transition 
// into offline mode on the current device. However, if you’d like to enhance user
// awareness, you may optionally display a message to inform the player of the change.
void OnPFGameSaveFilesActiveDeviceChanged(
    PFLocalUserHandle localUserHandle,
    PFGameSaveDescriptor* activeDevice,
    void* context)
{
    AddLog("Active device changed. The player is now active on another device. This device will continue in offline mode.");    
    AddLog("This event can be ignored as the gamesaves will automatically go offline.");
}

void SetForceInprocGameSavesRegistry(bool enable)
{
    // This is just for testing, and don't use this in production code.
    // Set or deletes the registry to force PlayFab Game Save to run in-process instead of using out-of-process GRTS
    // 
    // Windows Registry Editor Version 5.00
    // [HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\GamingServices]
    // "ForceUseInprocGameSaves"=dword:00000001
    const wchar_t* keyPath = L"SOFTWARE\\Microsoft\\GamingServices";
    const wchar_t* valueName = L"ForceUseInprocGameSaves";
    
    HKEY hKey;
    LONG result = RegOpenKeyExW(HKEY_LOCAL_MACHINE, keyPath, 0, KEY_SET_VALUE, &hKey);
    
    if (result != ERROR_SUCCESS)
    {
        // Try to create the key if it doesn't exist
        result = RegCreateKeyExW(HKEY_LOCAL_MACHINE, keyPath, 0, nullptr, 
                                REG_OPTION_NON_VOLATILE, KEY_SET_VALUE, nullptr, &hKey, nullptr);
    }
    
    if (result != ERROR_SUCCESS)
    {
        if (enable)
        {
            AddLog("Failed to open/create registry key HKLM\\%ls, error: %ld (try running as administrator)", keyPath, result);
        }
        return;
    }
    
    if (enable)
    {
        DWORD value = 1;
        result = RegSetValueExW(hKey, valueName, 0, REG_DWORD, reinterpret_cast<const BYTE*>(&value), sizeof(value));
        if (result == ERROR_SUCCESS)
        {
            AddLog("Successfully set ForceUseInprocGameSaves registry value to 1");
        }
        else
        {
            AddLog("Failed to set ForceUseInprocGameSaves registry value, error: %ld (try running as administrator)", result);
        }
    }
    else
    {
        result = RegDeleteValueW(hKey, valueName);
        if (result == ERROR_SUCCESS)
        {
            AddLog("Successfully deleted ForceUseInprocGameSaves registry value");
        }
        else if (result == ERROR_FILE_NOT_FOUND)
        {
            AddLog("ForceUseInprocGameSaves registry value does not exist, nothing to delete");
        }
        else
        {
            AddLog("Failed to delete ForceUseInprocGameSaves registry value, error: %ld (try running as administrator)", result);
        }
    }
    
    RegCloseKey(hKey);
}

HRESULT GameSaveIntegration::Initialize()
{
    AddLog("GameSaveIntegration::Initialize");

    g_gameState.steamAvailable = SteamIntegration::CheckSteamAvailability();
    g_gameState.isSteamDeck = SteamIntegration::CheckIfSteamDeck();
    if( g_gameState.isSteamDeck )
    {
        RETURN_IF_FAILED(SteamIntegration::SetSandboxForSteamDeck("XDKS.1"));
    }

    RETURN_IF_FAILED(XGameRuntimeInitialize());
    RETURN_IF_FAILED(PFInitialize(nullptr));
    // Hook libHttpClient tracing to debugger for easier diagnostics
    HCTraceSetClientCallback(MyDebugTrace);
    HCSettingsSetTraceLevel(HCTraceLevel::Information);
    RETURN_IF_FAILED(PFServicesInitialize(nullptr));
    RETURN_IF_FAILED(PFServiceConfigCreateHandle(
        "https://E18D7.playfabapi.com",    // PlayFab API endpoint - obtained in the Game Manager
        "E18D7",                           // PlayFab Title id - obtained in the Game Manager
        &g_gameState.serviceConfigHandle));

    RETURN_IF_FAILED(XTaskQueueCreate(XTaskQueueDispatchMode::ThreadPool, XTaskQueueDispatchMode::ThreadPool, &g_gameState.queue));

    if (g_gameState.isSteamDeck)
    {
        RETURN_IF_FAILED(SteamIntegration::InitializeXUserForSteamDeck());
    }

    return S_OK;
}

HRESULT GameSaveIntegration::InitializeGameSaves(_In_ bool setUiCallbacks, _In_ bool forceInproc)
{
    PFGameSaveInitArgs gsargs{};
    
    // Set or delete the ForceUseInprocGameSaves registry key based on forceInproc parameter
    // This is just for testing, and don't use this in production code.
    SetForceInprocGameSavesRegistry(forceInproc);
    
    // Define where the root for your game saves on for platforms that require it such as Steam Deck.
    // On other platforms such as Windows and Xbox, the path is provided to you and this path is ignored.
    // In this sample, we will use %USERPROFILE%\AppData\Local\GameSaveSample
    char localAppDataPath[MAX_PATH];
    std::string savePath;
    HRESULT hr = SHGetFolderPathA(nullptr, CSIDL_LOCAL_APPDATA, nullptr, SHGFP_TYPE_CURRENT, localAppDataPath);
    if (FAILED(hr))
    {
        savePath = "C:\\temp\\GameSaveSample";
    }
    else
    {
        savePath = std::string(localAppDataPath) + "\\GameSaveSample";
        // Create the directory if it doesn't exist
        CreateDirectoryA(savePath.c_str(), nullptr);
    }
    
    gsargs.saveFolder = savePath.c_str();
    RETURN_IF_FAILED(PFGameSaveFilesInitialize(&gsargs));

    if (setUiCallbacks)
    {
        PFGameSaveUICallbacks callbacks{};
        callbacks.progressCallback = OnPFGameSaveFilesUiProgress;
        callbacks.syncFailedCallback = OnPFGameSaveFilesUiSyncFailed;
        callbacks.activeDeviceContentionCallback = OnPFGameSaveFilesUiActiveDeviceContention;
        callbacks.conflictCallback = OnPFGameSaveFilesUiConflict;
        callbacks.outOfStorageCallback = OnPFGameSaveFilesUiOutOfStorage;
        RETURN_IF_FAILED(PFGameSaveFilesSetUiCallbacks(&callbacks));
    }

    RETURN_IF_FAILED(PFGameSaveFilesSetActiveDeviceChangedCallback(nullptr, OnPFGameSaveFilesActiveDeviceChanged, nullptr));

    g_gameState.gameSavesInitialized = true;
    return S_OK;
}

void GameSaveIntegration::CleanupSteam()
{
    SteamIntegration::CleanupSteam();
}

HRESULT GameSaveIntegration::SignInViaSteam()
{
    SteamIntegration::SignInViaSteam();
    return S_OK;
}

HRESULT GameSaveIntegration::SignInViaXbox()
{
    if (g_gameState.userSignInPending)
    {
        AddLog("Sign-in already pending");
        return S_OK;
    }

    AddLog("SignInViaXbox");

    auto async = std::make_unique<XAsyncBlock>();
    async->context = nullptr;
    async->queue = nullptr;
    async->callback = [](_Inout_ struct XAsyncBlock* async)
    {
        std::unique_ptr<XAsyncBlock> asyncBlockPtr{ async }; // take ownership of XAsyncBlock
        g_gameState.userSignInPending = false;
        HRESULT hr = XAsyncGetStatus(async, false);
        if (SUCCEEDED(hr))
        {
            hr = XUserAddResult(async, &g_gameState.xuser);

            if (SUCCEEDED(hr))
            {
                hr = PFLocalUserCreateHandleWithXboxUser(
                    g_gameState.serviceConfigHandle,
                    g_gameState.xuser,
                    nullptr,
                    &g_gameState.localUserHandle);
            }
        }

        if( SUCCEEDED(hr) )
        {
            g_gameState.userSignedIn = true;
            g_gameState.userSignedInViaXbox = true;
        }
        else
        {
            AddLog("XUserAddAsync failed (HRESULT: 0x%08X)", hr);
        }
    };

    g_gameState.userSignInPending = true;
    HRESULT hr = XUserAddAsync(XUserAddOptions::AddDefaultUserAllowingUI, async.get());
    if( FAILED(hr) )
    {
        g_gameState.userSignInPending = false;
        AddLog("XUserAddAsync failed (HRESULT: 0x%08X)", hr);
        return hr;
    }
    async.release(); // at this point, the callback will be called so release the unique ptr

    return S_OK;
}

HRESULT GameSaveIntegration::SignOutViaXbox()
{
    if (g_gameState.isSteamDeck && g_gameState.userSignedIn)
    {
        SteamIntegration::SignOutViaXboxOnSteamDeck();
    }
   
    return S_OK;
}

HRESULT GameSaveIntegration::AddUserToPFGameSave()
{
    if (!g_gameState.gameSavesInitialized)
    {
        bool setUiCallbacks = g_gameState.isSteamDeck || g_gameState.setUiCallbacks;
        RETURN_IF_FAILED(InitializeGameSaves(setUiCallbacks, g_gameState.forceInproc));
    }

    if (g_gameState.userAddedToGameSavePending)
    {
        return S_OK; // already pending
    }

    AddLog("AddUserToPFGameSave");

    auto async = std::make_unique<XAsyncBlock>();
    async->context = nullptr;
    async->queue = g_gameState.queue; 
    async->callback = [](_Inout_ struct XAsyncBlock* async)
    {
        std::unique_ptr<XAsyncBlock> asyncBlockPtr{ async }; // take ownership of XAsyncBlock
        g_gameState.userAddedToGameSavePending = false;
        HRESULT hr = XAsyncGetStatus(async, false);
        if (SUCCEEDED(hr))
        {
            g_gameState.userAddedToGameSave = true;

            // Get save folder for user
            char saveFolder[MAX_PATH] = { 0 };
            hr = PFGameSaveFilesGetFolder(g_gameState.localUserHandle, MAX_PATH, saveFolder, nullptr);
            g_gameState.saveFolder = saveFolder;

            hr = PFGameSaveFilesGetRemainingQuota(g_gameState.localUserHandle, &g_gameState.remainingQuota);
        }
        else
        {
            AddLog("PFGameSaveFilesAddUserWithUiAsync failed (HRESULT: 0x%08X)", hr);
        }
    };

    g_gameState.userAddedToGameSavePending = true;
    HRESULT hr = PFGameSaveFilesAddUserWithUiAsync(g_gameState.localUserHandle, PFGameSaveFilesAddUserOptions::None, async.get());
    if (FAILED(hr))
    {
        g_gameState.userAddedToGameSavePending = false;
        AddLog("PFGameSaveFilesAddUserWithUiAsync failed (HRESULT: 0x%08X)", hr);
        return hr;
    }
    async.release(); // at this point, the callback will be called so release the unique ptr

    return S_OK;
}

HRESULT GameSaveIntegration::CleanupPFGameSave()
{
    AddLog("CleanupPFGameSave");

    XAsyncBlock async{};
    RETURN_IF_FAILED(PFGameSaveFilesUninitializeAsync(&async));
    RETURN_IF_FAILED(XAsyncGetStatus(&async, true));

    g_gameState.gameSavesInitialized = false;
    return S_OK;
}

void GameSaveIntegration::SaveGame()
{
    AddLog("SaveGame");

    std::string fileName = "savegame.dat";
    std::string path = g_gameState.saveFolder + "\\" + fileName;
    
    // Create a buffer filled with random data
    const size_t fileSize = 1024 * 1024 * 10; // 10MB
    std::vector<uint8_t> buffer(fileSize);
    
    // Fill buffer with random data  
    for (size_t i = 0; i < fileSize; ++i)
    {
        buffer[i] = rand() % 256; // Use rand() for simplicity
    }
    
    // Print the first 4 bytes
    AddLog("SaveGame: First 4 bytes: 0x%02X 0x%02X 0x%02X 0x%02X", 
           buffer[0], buffer[1], buffer[2], buffer[3]);
    
    // Write the binary data to file
    std::ofstream file(path, std::ios::binary);
    if (file.is_open())
    {
        file.write(reinterpret_cast<const char*>(buffer.data()), fileSize);
        file.close();
        AddLog("SaveGame: Successfully created %s with %zu bytes of random data", path.c_str(), fileSize);
    }
    else
    {
        AddLog("SaveGame: Failed to create file %s", path.c_str());
    }
}

void GameSaveIntegration::LoadGame()
{
    AddLog("LoadGame");

    std::string fileName = "savegame.dat";
    std::string path = g_gameState.saveFolder + "\\" + fileName;
    
    // Check if file exists
    std::ifstream file(path, std::ios::binary);
    if (!file.is_open())
    {
        AddLog("LoadGame: File %s does not exist", path.c_str());
        return;
    }
    
    // Get file size
    file.seekg(0, std::ios::end);
    std::streamsize fileSize = file.tellg();
    file.seekg(0, std::ios::beg);
    
    const size_t expectedSize = 1024 * 1024 * 10; // 10MB

    if (fileSize != expectedSize)
    {
        AddLog("LoadGame: File size mismatch. Expected %zu bytes, but file is %lld bytes", 
               expectedSize, static_cast<long long>(fileSize));
        file.close();
        return;
    }
    
    // Read and print the first 4 bytes
    uint8_t firstFourBytes[4];
    file.read(reinterpret_cast<char*>(firstFourBytes), 4);
    if (file.gcount() == 4)
    {
        AddLog("LoadGame: First 4 bytes: 0x%02X 0x%02X 0x%02X 0x%02X", 
               firstFourBytes[0], firstFourBytes[1], firstFourBytes[2], firstFourBytes[3]);
    }
    else
    {
        AddLog("LoadGame: Failed to read first 4 bytes");
    }
    
    AddLog("LoadGame: File %s exists and is the correct size (%lld bytes)", 
           path.c_str(), static_cast<long long>(fileSize));
    
    file.close();
}

void GameSaveIntegration::DeleteSave()
{
    AddLog("DeleteSave");

    std::string fileName = "savegame.dat";
    std::string path = g_gameState.saveFolder + "\\" + fileName;
    
    // Check if file exists first
    std::ifstream file(path);
    if (!file.is_open())
    {
        AddLog("DeleteSave: File %s does not exist", path.c_str());
        return;
    }
    file.close();
    
    // File exists, attempt to delete it
    if (DeleteFileA(path.c_str()))
    {
        AddLog("DeleteSave: Successfully deleted %s", path.c_str());
    }
    else
    {
        DWORD error = GetLastError();
        AddLog("DeleteSave: Failed to delete %s, error: %d", path.c_str(), error);
    }
}

HRESULT GameSaveIntegration::UploadSaveToCloud(bool keepDeviceActive)
{
    AddLog("UploadSaveToCloud");

    if (g_gameState.uploadInProgress)
    {
        AddLog("Upload already in progress");
        return S_OK;
    }

    auto async = std::make_unique<XAsyncBlock>();
    async->context = nullptr;
    async->queue = nullptr; // uses the default queue
    async->callback = [](_Inout_ struct XAsyncBlock* async)
    {
        std::unique_ptr<XAsyncBlock> asyncBlockPtr{ async }; // take ownership of XAsyncBlock
        g_gameState.uploadInProgress = false;
        HRESULT hr = XAsyncGetStatus(async, false);
        if (FAILED(hr))
        {
            AddLog("PFGameSaveFilesUploadWithUiAsync failed (HRESULT: 0x%08X)", hr);
        }
    };

    PFGameSaveFilesUploadOption uploadOption = (keepDeviceActive) ? PFGameSaveFilesUploadOption::KeepDeviceActive : PFGameSaveFilesUploadOption::ReleaseDeviceAsActive;
    g_gameState.uploadInProgress = true;
    HRESULT hr = PFGameSaveFilesUploadWithUiAsync(g_gameState.localUserHandle, uploadOption, async.get());
    if( FAILED(hr) )
    {
        g_gameState.uploadInProgress = false;
        AddLog("PFGameSaveFilesUploadWithUiAsync failed (HRESULT: 0x%08X)", hr);
        return hr;
    }
    async.release(); // at this point, the callback will be called so release the unique ptr

    return S_OK;
}

