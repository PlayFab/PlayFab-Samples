#pragma once

class GameSaveIntegration
{
public:
    static HRESULT Initialize();
    static HRESULT InitializeGameSaves(_In_ bool setUiCallbacks);
    static HRESULT CleanupPFGameSave();
    static void CleanupSteam();

    static HRESULT SignInViaSteam();
    static HRESULT SignInViaXbox();
    static HRESULT SignOutViaXbox();

    static HRESULT AddUserToPFGameSave();
    static void SaveGame();
    static void LoadGame();
    static void DeleteSave();
    static HRESULT UploadSaveToCloud(bool keepDeviceActive);
};
