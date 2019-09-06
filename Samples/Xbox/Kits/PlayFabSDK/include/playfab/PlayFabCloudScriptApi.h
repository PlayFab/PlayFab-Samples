#pragma once

#ifdef ENABLE_PLAYFABENTITY_API

#include "playfab/PlayFabHttp.h"
#include "playfab/PlayFabCloudScriptDataModels.h"

namespace PlayFab
{
    /// <summary>
    /// Main interface for PlayFab Sdk, specifically all CloudScript APIs
    /// </summary>
    class PlayFabCloudScriptAPI
    {
    public:
        static size_t Update();
        static void ForgetAllCredentials();


        // ------------ Generated API calls
        static void ExecuteEntityCloudScript(CloudScriptModels::ExecuteEntityCloudScriptRequest& request, ProcessApiCallback<CloudScriptModels::ExecuteCloudScriptResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);

    private:
        PlayFabCloudScriptAPI(); // Private constructor, static class should never have an instance
        PlayFabCloudScriptAPI(const PlayFabCloudScriptAPI& other); // Private copy-constructor, static class should never have an instance

        // ------------ Generated result handlers
        static void OnExecuteEntityCloudScriptResult(CallRequestContainer& request);

    };
}

#endif
