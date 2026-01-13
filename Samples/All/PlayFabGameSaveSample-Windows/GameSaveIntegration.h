#pragma once

class GameSaveIntegration
{
public:
    static HRESULT Initialize();
    static HRESULT InitializeGameSaves(_In_ bool setUiCallbacks, _In_ bool forceInproc = false);
    static HRESULT CleanupPFGameSave();
#ifdef ENABLE_STEAM_SDK
    static void CleanupSteam();

    static HRESULT SignInViaSteam();
#endif
    static HRESULT SignInViaXbox();
    static HRESULT SignOutViaXbox();

    static HRESULT AddUserToPFGameSave();
    static void SaveGame();
    static void LoadGame();
    static void DeleteSave();
    static HRESULT UploadSaveToCloud(bool keepDeviceActive);
};
