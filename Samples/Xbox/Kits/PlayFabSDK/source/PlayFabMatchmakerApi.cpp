
#ifdef ENABLE_PLAYFABSERVER_API

#include "playfab/PlayFabMatchmakerApi.h"
#include "playfab/PlayFabHttp.h"
#include "playfab/PlayFabSettings.h"

namespace PlayFab
{
    using namespace MatchmakerModels;

    size_t PlayFabMatchmakerAPI::Update()
    {
        return PlayFabHttp::Get().Update();
    }

    void PlayFabMatchmakerAPI::ForgetAllCredentials()
    {
        return PlayFabSettings::ForgetAllCredentials();
    }

    // PlayFabMatchmaker APIs

    void PlayFabMatchmakerAPI::AuthUser(
        AuthUserRequest& request,
        ProcessApiCallback<AuthUserResponse> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Matchmaker/AuthUser", L"X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnAuthUserResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<AuthUserResponse>(callback)), errorCallback, customData);
    }

    void PlayFabMatchmakerAPI::OnAuthUserResult(CallRequestContainer& request)
    {
        AuthUserResponse outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<AuthUserResponse> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabMatchmakerAPI::PlayerJoined(
        PlayerJoinedRequest& request,
        ProcessApiCallback<PlayerJoinedResponse> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Matchmaker/PlayerJoined", L"X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnPlayerJoinedResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<PlayerJoinedResponse>(callback)), errorCallback, customData);
    }

    void PlayFabMatchmakerAPI::OnPlayerJoinedResult(CallRequestContainer& request)
    {
        PlayerJoinedResponse outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<PlayerJoinedResponse> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabMatchmakerAPI::PlayerLeft(
        PlayerLeftRequest& request,
        ProcessApiCallback<PlayerLeftResponse> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Matchmaker/PlayerLeft", L"X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnPlayerLeftResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<PlayerLeftResponse>(callback)), errorCallback, customData);
    }

    void PlayFabMatchmakerAPI::OnPlayerLeftResult(CallRequestContainer& request)
    {
        PlayerLeftResponse outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<PlayerLeftResponse> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabMatchmakerAPI::StartGame(
        StartGameRequest& request,
        ProcessApiCallback<StartGameResponse> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Matchmaker/StartGame", L"X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnStartGameResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<StartGameResponse>(callback)), errorCallback, customData);
    }

    void PlayFabMatchmakerAPI::OnStartGameResult(CallRequestContainer& request)
    {
        StartGameResponse outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<StartGameResponse> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabMatchmakerAPI::UserInfo(
        UserInfoRequest& request,
        ProcessApiCallback<UserInfoResponse> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Matchmaker/UserInfo", L"X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnUserInfoResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<UserInfoResponse>(callback)), errorCallback, customData);
    }

    void PlayFabMatchmakerAPI::OnUserInfoResult(CallRequestContainer& request)
    {
        UserInfoResponse outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<UserInfoResponse> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }
}

#endif
