#pragma once

#ifdef ENABLE_PLAYFABSERVER_API

#include <playfab/PlayFabCallRequestContainer.h>
#include <playfab/PlayFabHttp.h>
#include <playfab/PlayFabMatchmakerDataModels.h>

namespace PlayFab
{
    /// <summary>
    /// Main interface for PlayFab Sdk, specifically all Matchmaker APIs
    /// </summary>
    class PlayFabMatchmakerAPI
    {
    public:
        static size_t Update();
        static void ForgetAllCredentials();


        // ------------ Generated API calls
        static void AuthUser(MatchmakerModels::AuthUserRequest& request, ProcessApiCallback<MatchmakerModels::AuthUserResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void PlayerJoined(MatchmakerModels::PlayerJoinedRequest& request, ProcessApiCallback<MatchmakerModels::PlayerJoinedResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void PlayerLeft(MatchmakerModels::PlayerLeftRequest& request, ProcessApiCallback<MatchmakerModels::PlayerLeftResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void StartGame(MatchmakerModels::StartGameRequest& request, ProcessApiCallback<MatchmakerModels::StartGameResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UserInfo(MatchmakerModels::UserInfoRequest& request, ProcessApiCallback<MatchmakerModels::UserInfoResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);

    private:
        PlayFabMatchmakerAPI(); // Private constructor, static class should never have an instance
        PlayFabMatchmakerAPI(const PlayFabMatchmakerAPI& other); // Private copy-constructor, static class should never have an instance

        // ------------ Generated result handlers
        static void OnAuthUserResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnPlayerJoinedResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnPlayerLeftResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnStartGameResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnUserInfoResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);

        static bool ValidateResult(PlayFabResultCommon& resultCommon, CallRequestContainer& container);
    };
}

#endif
