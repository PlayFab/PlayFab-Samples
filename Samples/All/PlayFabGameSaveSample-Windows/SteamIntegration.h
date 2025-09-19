#pragma once

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
