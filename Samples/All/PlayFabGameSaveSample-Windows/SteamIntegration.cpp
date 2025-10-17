#include "pch.h"
#include "SteamIntegration.h"
#include "GameSaveIntegrationUI.h"
#include "game.h"

void OnRemoteConnectShow(
    _In_opt_ void* context,
    _In_ uint32_t userIdentifier,
    _In_ XUserPlatformOperation operation,
    _In_z_ char const* url,
    _In_z_ char const* code,
    _In_ size_t qrCodeSize,
    _In_reads_bytes_(qrCodeSize) void const* qrCode
)
{
    ShowRemoteConnectDialogForXUserOnSteamDeck(std::string(url), std::string(code), userIdentifier);
}

void OnRemoteConnectClose(
    _In_opt_ void* context,
    _In_ uint32_t userIdentifier,
    _In_ XUserPlatformOperation operation
)
{
    AddLog("Remote Connect: CLOSE for user: %u", userIdentifier);
    CloseRemoteConnectDialogForXUserOnSteamDeck();
}

void OnSpopPrompt(
    _In_opt_ void* context,
    _In_ uint32_t userIdentifier,
    _In_ XUserPlatformOperation operation,
    _In_z_ char const* modernGamertag,
    _In_opt_z_ char const* modernGamertagSuffix
)
{
    AddLog("SPOP Prompt: User: %u, Operation: %llu, Gamertag: %s%s", 
           userIdentifier, 
           (unsigned long long)operation, 
           modernGamertag ? modernGamertag : "null",
           modernGamertagSuffix ? modernGamertagSuffix : "");
    
    // Show the SPOP prompt dialog for user to choose an action
    ShowSpopPromptDialogForXUserOnSteamDeck(
        userIdentifier, 
        &operation, 
        modernGamertag ? std::string(modernGamertag) : "", 
        modernGamertagSuffix ? std::string(modernGamertagSuffix) : ""
    );
}

bool SteamIntegration::CheckSteamAvailability()
{
    // Try to initialize Steam API
    bool steamAvailable = SteamAPI_Init();
    
    if (steamAvailable)
    {
        AddLog("Steam API initialized successfully");

        if (!SteamUser()->BLoggedOn()) 
        {
            AddLog("Warning: User not logged in to Steam");
        }
    }
    else
    {
        AddLog("Steam API initialization failed or Steam not available - continuing without Steam");
    }

    return steamAvailable;
}

bool SteamIntegration::CheckIfSteamDeck()
{
    if (g_gameState.steamAvailable)
    {
        bool isSteamDeck = SteamUtils()->IsSteamRunningOnSteamDeck();
        if (isSteamDeck)
        {
            AddLog("Running on Steam Deck");
        }
        return isSteamDeck;
    }
    
    return false;
}

HRESULT SteamIntegration::InitializeXUserForSteamDeck()
{
    if (g_gameState.isSteamDeck)
    {
        XUserPlatformRemoteConnectEventHandlers remoteConnect{};
        remoteConnect.context = nullptr;
        remoteConnect.show = &OnRemoteConnectShow;
        remoteConnect.close = &OnRemoteConnectClose;
        RETURN_IF_FAILED(XUserPlatformRemoteConnectSetEventHandlers(nullptr, &remoteConnect));

        RETURN_IF_FAILED(XUserPlatformSpopPromptSetEventHandlers(nullptr, &OnSpopPrompt, nullptr));
    }

    return S_OK;
}

HRESULT SteamIntegration::SetSandboxForSteamDeck(const std::string& sandbox)
{
    AddLog("SetSandboxForInprocXGameRuntime: Setting sandbox to '%s'", sandbox.c_str());
    
    // Set Xbox Live Sandbox registry key
    HKEY hKey;
    LONG result = RegCreateKeyExA(
        HKEY_LOCAL_MACHINE,
        "SOFTWARE\\Microsoft\\XboxLive",
        0,
        NULL,
        REG_OPTION_NON_VOLATILE,
        KEY_WRITE,
        NULL,
        &hKey,
        NULL
    );

    if (result != ERROR_SUCCESS)
    {
        AddLog("Failed to create/open Xbox Live registry key. Error: %ld. Make sure the application is running with elevated privileges.", result);
        return HRESULT_FROM_WIN32(result);
    }

    // Set the sandbox value
    LONG setResult = RegSetValueExA(
        hKey,
        "Sandbox",
        0,
        REG_SZ,
        (const BYTE*)sandbox.c_str(),
        (DWORD)(sandbox.length() + 1)
    );
    
    RegCloseKey(hKey);

    if (setResult != ERROR_SUCCESS)
    {
        AddLog("Failed to set Xbox Live Sandbox registry value. Error: %ld", setResult);
        return HRESULT_FROM_WIN32(setResult);
    }

    return S_OK;
}

void SteamIntegration::CleanupSteam()
{
    // Shutdown Steam API if it was initialized
    if (g_gameState.steamAvailable)
    {
        SteamAPI_Shutdown();
        AddLog("Steam API shutdown");
        g_gameState.steamAvailable = false;
    }
}

HRESULT SteamIntegration::SignInViaSteam()
{
    AddLog("SignInViaSteam");

    if (!g_gameState.steamAvailable)
    {
        AddLog("Steam API not available - cannot sign in via Steam");
        return E_FAIL;
    }

    RETURN_IF_FAILED(PFLocalUserCreateHandleWithSteamUser(
        g_gameState.serviceConfigHandle,
        nullptr,
        &g_gameState.localUserHandle));

    return S_OK;
}

void SteamIntegration::SignOutViaXboxOnSteamDeck()
{
    AddLog("SignOutViaXbox: Cleaning up Xbox credentials from Windows Credential Manager");

    // Enumerate and delete Xbox credentials from Windows Credential Manager
    PCREDENTIALA* credentials = nullptr;
    DWORD credentialCount = 0;
    HRESULT hr = S_OK;

    // Enumerate all credentials
    if (CredEnumerateA(nullptr, 0, &credentialCount, &credentials))
    {
        AddLog("Found %d credentials in Windows Credential Manager", credentialCount);
        int deletedCount = 0;

        for (DWORD i = 0; i < credentialCount; i++)
        {
            if (credentials[i]->TargetName != nullptr)
            {
                std::string targetName(credentials[i]->TargetName);

                // Check if the credential target name starts with "Xbl"
                if (targetName.length() >= 3 &&
                    targetName.substr(0, 3) == "Xbl")
                {
                    AddLog("Deleting Xbox credential: %s", targetName.c_str());

                    if (CredDeleteA(credentials[i]->TargetName, credentials[i]->Type, 0))
                    {
                        deletedCount++;
                        AddLog("Successfully deleted credential: %s", targetName.c_str());
                    }
                    else
                    {
                        DWORD error = GetLastError();
                        AddLog("Failed to delete credential %s, error: %d", targetName.c_str(), error);
                        // Continue with other credentials even if one fails
                    }
                }
            }
        }

        AddLog("Deleted %d Xbox credentials from Windows Credential Manager", deletedCount);

        // Free the credential array
        CredFree(credentials);
    }
    else
    {
        DWORD error = GetLastError();
        AddLog("Failed to enumerate credentials from Windows Credential Manager, error: %d", error);
        hr = HRESULT_FROM_WIN32(error);
    }

    // Clean up Xbox user handle if it exists
    if (g_gameState.xuser != nullptr)
    {
        XUserCloseHandle(g_gameState.xuser);
        g_gameState.xuser = nullptr;
        AddLog("Xbox user handle closed");
    }

    // Clean up local user handle if it exists
    if (g_gameState.localUserHandle != nullptr)
    {
        PFLocalUserCloseHandle(g_gameState.localUserHandle);
        g_gameState.localUserHandle = nullptr;
        AddLog("PlayFab local user handle closed");
    }

    g_gameState.userSignedIn = false;
}
