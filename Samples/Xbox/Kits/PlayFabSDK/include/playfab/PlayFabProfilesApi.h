#pragma once

#ifdef ENABLE_PLAYFABENTITY_API

#include "playfab/PlayFabHttp.h"
#include "playfab/PlayFabProfilesDataModels.h"

namespace PlayFab
{
    /// <summary>
    /// Main interface for PlayFab Sdk, specifically all Profiles APIs
    /// </summary>
    class PlayFabProfilesAPI
    {
    public:
        static size_t Update();
        static void ForgetAllCredentials();


        // ------------ Generated API calls
        static void GetGlobalPolicy(ProfilesModels::GetGlobalPolicyRequest& request, ProcessApiCallback<ProfilesModels::GetGlobalPolicyResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetProfile(ProfilesModels::GetEntityProfileRequest& request, ProcessApiCallback<ProfilesModels::GetEntityProfileResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetProfiles(ProfilesModels::GetEntityProfilesRequest& request, ProcessApiCallback<ProfilesModels::GetEntityProfilesResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void SetGlobalPolicy(ProfilesModels::SetGlobalPolicyRequest& request, ProcessApiCallback<ProfilesModels::SetGlobalPolicyResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void SetProfileLanguage(ProfilesModels::SetProfileLanguageRequest& request, ProcessApiCallback<ProfilesModels::SetProfileLanguageResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void SetProfilePolicy(ProfilesModels::SetEntityProfilePolicyRequest& request, ProcessApiCallback<ProfilesModels::SetEntityProfilePolicyResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);

    private:
        PlayFabProfilesAPI(); // Private constructor, static class should never have an instance
        PlayFabProfilesAPI(const PlayFabProfilesAPI& other); // Private copy-constructor, static class should never have an instance

        // ------------ Generated result handlers
        static void OnGetGlobalPolicyResult(CallRequestContainer& request);
        static void OnGetProfileResult(CallRequestContainer& request);
        static void OnGetProfilesResult(CallRequestContainer& request);
        static void OnSetGlobalPolicyResult(CallRequestContainer& request);
        static void OnSetProfileLanguageResult(CallRequestContainer& request);
        static void OnSetProfilePolicyResult(CallRequestContainer& request);

    };
}

#endif
