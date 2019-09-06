#include "playfab/PlayFabSettings.h"

namespace PlayFab
{
    const utility::string_t PlayFabSettings::sdkVersion = L"1.30.180809";
    const utility::string_t PlayFabSettings::buildIdentifier = L"jbuild_winxboxsdk_sdk-slave2016-3_0";
    const utility::string_t PlayFabSettings::versionString = L"WindowsSDK-1.30.180809";

    bool PlayFabSettings::useDevelopmentEnvironment = false;
    utility::string_t PlayFabSettings::serverURL;
    utility::string_t PlayFabSettings::developmentEnvironmentURL = L".playfabsandbox.com";
    utility::string_t PlayFabSettings::productionEnvironmentURL = L".playfabapi.com";
    utility::string_t PlayFabSettings::titleId; // You must set this value for PlayFabSdk to work properly (Found in the Game Manager for your title, at the PlayFab Website)
    ErrorCallback PlayFabSettings::globalErrorHandler = nullptr;

    // Control whether all callbacks are threaded or whether the user manually controlls callback timing from their main-thread
    bool PlayFabSettings::threadedCallbacks = false;

    utility::string_t PlayFabSettings::entityToken; // This is set by entity GetEntityToken method, and is required by all other Entity API methods
#if defined(ENABLE_PLAYFABSERVER_API) || defined(ENABLE_PLAYFABADMIN_API)
    utility::string_t PlayFabSettings::developerSecretKey; // You must set this value for PlayFabSdk to work properly (Found in the Game Manager for your title, at the PlayFab Website)
#endif

#ifndef DISABLE_PLAYFABCLIENT_API
    utility::string_t PlayFabSettings::clientSessionTicket; // This is set by any Client Login method, and is required for all other Client API methods
    utility::string_t PlayFabSettings::advertisingIdType = L""; // Set this to the appropriate AD_TYPE_X constant below
    utility::string_t PlayFabSettings::advertisingIdValue = L""; // Set this to corresponding device value

    bool PlayFabSettings::disableAdvertising = false;
    const utility::string_t PlayFabSettings::AD_TYPE_IDFA = L"Idfa";
    const utility::string_t PlayFabSettings::AD_TYPE_ANDROID_ID = L"Adid";
#endif

    void PlayFabSettings::ForgetAllCredentials()
    {
        entityToken.clear();
        clientSessionTicket.clear();
    }

    utility::string_t PlayFabSettings::GetUrl(const utility::string_t& urlPath)
    {
        if (serverURL.length() == 0)
            serverURL = U("https://" + titleId + (useDevelopmentEnvironment ? developmentEnvironmentURL : productionEnvironmentURL));
        return serverURL + urlPath;
    }
}
