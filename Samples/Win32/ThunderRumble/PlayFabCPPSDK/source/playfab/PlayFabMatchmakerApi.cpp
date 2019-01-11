#include <stdafx.h>

#ifdef ENABLE_PLAYFABSERVER_API

#include <playfab/PlayFabMatchmakerApi.h>
#include <playfab/PlayFabHttp.h>
#include <playfab/PlayFabSettings.h>
#include <playfab/PlayFabError.h>

#pragma warning (disable: 4100) // formal parameters are part of a public interface

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

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();

        Json::FastWriter writer;
        std::string jsonAsString = writer.write(requestJson);

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-SecretKey", PlayFabSettings::developerSecretKey);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Matchmaker/AuthUser",
            headers,
            jsonAsString,
            OnAuthUserResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<AuthUserResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabMatchmakerAPI::OnAuthUserResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        AuthUserResponse outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<AuthUserResponse> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabMatchmakerAPI::PlayerJoined(
        PlayerJoinedRequest& request,
        ProcessApiCallback<PlayerJoinedResponse> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();

        Json::FastWriter writer;
        std::string jsonAsString = writer.write(requestJson);

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-SecretKey", PlayFabSettings::developerSecretKey);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Matchmaker/PlayerJoined",
            headers,
            jsonAsString,
            OnPlayerJoinedResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<PlayerJoinedResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabMatchmakerAPI::OnPlayerJoinedResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        PlayerJoinedResponse outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<PlayerJoinedResponse> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabMatchmakerAPI::PlayerLeft(
        PlayerLeftRequest& request,
        ProcessApiCallback<PlayerLeftResponse> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();

        Json::FastWriter writer;
        std::string jsonAsString = writer.write(requestJson);

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-SecretKey", PlayFabSettings::developerSecretKey);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Matchmaker/PlayerLeft",
            headers,
            jsonAsString,
            OnPlayerLeftResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<PlayerLeftResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabMatchmakerAPI::OnPlayerLeftResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        PlayerLeftResponse outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<PlayerLeftResponse> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabMatchmakerAPI::StartGame(
        StartGameRequest& request,
        ProcessApiCallback<StartGameResponse> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();

        Json::FastWriter writer;
        std::string jsonAsString = writer.write(requestJson);

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-SecretKey", PlayFabSettings::developerSecretKey);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Matchmaker/StartGame",
            headers,
            jsonAsString,
            OnStartGameResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<StartGameResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabMatchmakerAPI::OnStartGameResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        StartGameResponse outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<StartGameResponse> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabMatchmakerAPI::UserInfo(
        UserInfoRequest& request,
        ProcessApiCallback<UserInfoResponse> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();

        Json::FastWriter writer;
        std::string jsonAsString = writer.write(requestJson);

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-SecretKey", PlayFabSettings::developerSecretKey);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Matchmaker/UserInfo",
            headers,
            jsonAsString,
            OnUserInfoResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<UserInfoResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabMatchmakerAPI::OnUserInfoResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        UserInfoResponse outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<UserInfoResponse> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    bool PlayFabMatchmakerAPI::ValidateResult(PlayFabResultCommon& resultCommon, CallRequestContainer& container)
    {
        if (container.errorWrapper.HttpCode == 200)
        {
            resultCommon.FromJson(container.errorWrapper.Data);
            resultCommon.Request = container.errorWrapper.Request;
            return true;
        }
        else // Process the error case
        {
            if (PlayFabSettings::globalErrorHandler != nullptr)
                PlayFabSettings::globalErrorHandler(container.errorWrapper, container.GetCustomData());
            if (container.errorCallback != nullptr)
                container.errorCallback(container.errorWrapper, container.GetCustomData());
            return false;
        }
    }
}

#endif
