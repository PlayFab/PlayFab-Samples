#pragma once

#ifdef ENABLE_STEAM_SDK

class SteamIntegration
{
public:
    static bool CheckSteamAvailability();
    static bool CheckIfSteamDeck();
    static void CleanupSteam();
    static HRESULT SignInViaSteam();

    static HRESULT InitializeXUserForSteamDeck();
    static HRESULT SetSandboxForSteamDeck(const std::string& sandbox);
    static void SignOutViaXboxOnSteamDeck();
};

#endif // ENABLE_STEAM_SDK
