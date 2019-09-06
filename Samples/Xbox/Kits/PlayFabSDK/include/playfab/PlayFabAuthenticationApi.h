#pragma once

#ifdef ENABLE_PLAYFABENTITY_API

#include "playfab/PlayFabHttp.h"
#include "playfab/PlayFabAuthenticationDataModels.h"

namespace PlayFab
{
    /// <summary>
    /// Main interface for PlayFab Sdk, specifically all Authentication APIs
    /// </summary>
    class PlayFabAuthenticationAPI
    {
    public:
        static size_t Update();
        static void ForgetAllCredentials();


        // ------------ Generated API calls
        static void GetEntityToken(AuthenticationModels::GetEntityTokenRequest& request, ProcessApiCallback<AuthenticationModels::GetEntityTokenResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);

    private:
        PlayFabAuthenticationAPI(); // Private constructor, static class should never have an instance
        PlayFabAuthenticationAPI(const PlayFabAuthenticationAPI& other); // Private copy-constructor, static class should never have an instance

        // ------------ Generated result handlers
        static void OnGetEntityTokenResult(CallRequestContainer& request);

    };
}

#endif
