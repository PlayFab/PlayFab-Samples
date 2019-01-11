#pragma once

#include <playfab/PlayFabHttp.h>

namespace PlayFab
{
    /// <summary>
    /// All settings and global variables for PlayFab
    /// </summary>
    class PlayFabSettings
    {
    public:
        static const std::string sdkVersion;
        static const std::string buildIdentifier;
        static const std::string versionString;
        static const std::string verticalName;

        static const std::map<std::string, std::string> requestGetParams;

        static bool useDevelopmentEnvironment;
        static std::string developmentEnvironmentURL;
        static std::string productionEnvironmentURL;
        static std::string titleId; // You must set this value for PlayFabSdk to work properly (Found in the Game Manager for your title, at the PlayFab Website)
        static ErrorCallback globalErrorHandler;

        // Control whether all callbacks are threaded or whether the user manually controlls callback timing from their main-thread
        static bool threadedCallbacks;

        static std::string entityToken; // This is set by entity GetEntityToken method, and is required by all other Entity API methods
#if defined(ENABLE_PLAYFABSERVER_API) || defined(ENABLE_PLAYFABADMIN_API)
        static std::string developerSecretKey; // You must set this value for PlayFabSdk to work properly (Found in the Game Manager for your title, at the PlayFab Website)
#endif
#ifndef DISABLE_PLAYFABCLIENT_API
        static std::string clientSessionTicket; // This is set by any Client Login method, and is required for all other Client API methods
        static std::string advertisingIdType; // Set this to the appropriate AD_TYPE_X constant below
        static std::string advertisingIdValue; // Set this to corresponding device value

        // DisableAdvertising is provided for completeness, but changing it is not suggested
        // Disabling this may prevent your advertising-related PlayFab marketplace partners from working correctly
        static bool disableAdvertising;
        static const std::string AD_TYPE_IDFA;
        static const std::string AD_TYPE_ANDROID_ID;

        static void ForgetAllCredentials();
#endif
    private:
        PlayFabSettings(); // Private constructor, static class should never have an instance
        PlayFabSettings(const PlayFabSettings& other); // Private copy-constructor, static class should never have an instance

        friend PlayFabHttp;
        static std::string GetUrl(const std::string& urlPath, const std::map<std::string, std::string>& getParams);
    };
}
