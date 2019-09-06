#pragma once

#include "playfab/PlayFabHttp.h"

namespace PlayFab
{
    /// <summary>
    /// All settings and global variables for PlayFab
    /// </summary>
    class PlayFabSettings
    {
    public:
        static const utility::string_t sdkVersion;
        static const utility::string_t buildIdentifier;
        static const utility::string_t versionString;

        static bool useDevelopmentEnvironment;
        static utility::string_t developmentEnvironmentURL;
        static utility::string_t productionEnvironmentURL;
        static utility::string_t titleId; // You must set this value for PlayFabSdk to work properly (Found in the Game Manager for your title, at the PlayFab Website)
        static ErrorCallback globalErrorHandler;

        // Control whether all callbacks are threaded or whether the user manually controlls callback timing from their main-thread
        static bool threadedCallbacks;

        static utility::string_t entityToken; // This is set by entity GetEntityToken method, and is required by all other Entity API methods
#if defined(ENABLE_PLAYFABSERVER_API) || defined(ENABLE_PLAYFABADMIN_API)
        static utility::string_t developerSecretKey; // You must set this value for PlayFabSdk to work properly (Found in the Game Manager for your title, at the PlayFab Website)
#endif
#ifndef DISABLE_PLAYFABCLIENT_API
        static utility::string_t clientSessionTicket; // This is set by any Client Login method, and is required for all other Client API methods
        static utility::string_t advertisingIdType; // Set this to the appropriate AD_TYPE_X constant below
        static utility::string_t advertisingIdValue; // Set this to corresponding device value

        // DisableAdvertising is provided for completeness, but changing it is not suggested
        // Disabling this may prevent your advertising-related PlayFab marketplace partners from working correctly
        static bool disableAdvertising;
        static const utility::string_t AD_TYPE_IDFA;
        static const utility::string_t AD_TYPE_ANDROID_ID;

        static void ForgetAllCredentials();
#endif
    private:
        PlayFabSettings(); // Private constructor, static class should never have an instance
        PlayFabSettings(const PlayFabSettings& other); // Private copy-constructor, static class should never have an instance

        friend PlayFabHttp;
        static utility::string_t GetUrl(const utility::string_t& urlPath);

        static utility::string_t serverURL;
    };
}
