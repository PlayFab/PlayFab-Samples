#include <stdafx.h>

#ifdef ENABLE_PLAYFABSERVER_API

#include <playfab/PlayFabServerApi.h>
#include <playfab/PlayFabHttp.h>
#include <playfab/PlayFabSettings.h>
#include <playfab/PlayFabError.h>

#pragma warning (disable: 4100) // formal parameters are part of a public interface

namespace PlayFab
{
    using namespace ServerModels;

    size_t PlayFabServerAPI::Update()
    {
        return PlayFabHttp::Get().Update();
    }

    void PlayFabServerAPI::ForgetAllCredentials()
    {
        return PlayFabSettings::ForgetAllCredentials();
    }

    // PlayFabServer APIs

    void PlayFabServerAPI::AddCharacterVirtualCurrency(
        AddCharacterVirtualCurrencyRequest& request,
        ProcessApiCallback<ModifyCharacterVirtualCurrencyResult> callback,
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
            "/Server/AddCharacterVirtualCurrency",
            headers,
            jsonAsString,
            OnAddCharacterVirtualCurrencyResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<ModifyCharacterVirtualCurrencyResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabServerAPI::OnAddCharacterVirtualCurrencyResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        ModifyCharacterVirtualCurrencyResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<ModifyCharacterVirtualCurrencyResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabServerAPI::AddFriend(
        AddFriendRequest& request,
        ProcessApiCallback<EmptyResponse> callback,
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
            "/Server/AddFriend",
            headers,
            jsonAsString,
            OnAddFriendResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<EmptyResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabServerAPI::OnAddFriendResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        EmptyResponse outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<EmptyResponse> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabServerAPI::AddPlayerTag(
        AddPlayerTagRequest& request,
        ProcessApiCallback<AddPlayerTagResult> callback,
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
            "/Server/AddPlayerTag",
            headers,
            jsonAsString,
            OnAddPlayerTagResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<AddPlayerTagResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabServerAPI::OnAddPlayerTagResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        AddPlayerTagResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<AddPlayerTagResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabServerAPI::AddSharedGroupMembers(
        AddSharedGroupMembersRequest& request,
        ProcessApiCallback<AddSharedGroupMembersResult> callback,
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
            "/Server/AddSharedGroupMembers",
            headers,
            jsonAsString,
            OnAddSharedGroupMembersResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<AddSharedGroupMembersResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabServerAPI::OnAddSharedGroupMembersResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        AddSharedGroupMembersResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<AddSharedGroupMembersResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabServerAPI::AddUserVirtualCurrency(
        AddUserVirtualCurrencyRequest& request,
        ProcessApiCallback<ModifyUserVirtualCurrencyResult> callback,
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
            "/Server/AddUserVirtualCurrency",
            headers,
            jsonAsString,
            OnAddUserVirtualCurrencyResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<ModifyUserVirtualCurrencyResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabServerAPI::OnAddUserVirtualCurrencyResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        ModifyUserVirtualCurrencyResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<ModifyUserVirtualCurrencyResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabServerAPI::AuthenticateSessionTicket(
        AuthenticateSessionTicketRequest& request,
        ProcessApiCallback<AuthenticateSessionTicketResult> callback,
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
            "/Server/AuthenticateSessionTicket",
            headers,
            jsonAsString,
            OnAuthenticateSessionTicketResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<AuthenticateSessionTicketResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabServerAPI::OnAuthenticateSessionTicketResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        AuthenticateSessionTicketResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<AuthenticateSessionTicketResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabServerAPI::AwardSteamAchievement(
        AwardSteamAchievementRequest& request,
        ProcessApiCallback<AwardSteamAchievementResult> callback,
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
            "/Server/AwardSteamAchievement",
            headers,
            jsonAsString,
            OnAwardSteamAchievementResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<AwardSteamAchievementResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabServerAPI::OnAwardSteamAchievementResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        AwardSteamAchievementResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<AwardSteamAchievementResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabServerAPI::BanUsers(
        BanUsersRequest& request,
        ProcessApiCallback<BanUsersResult> callback,
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
            "/Server/BanUsers",
            headers,
            jsonAsString,
            OnBanUsersResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<BanUsersResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabServerAPI::OnBanUsersResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        BanUsersResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<BanUsersResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabServerAPI::ConsumeItem(
        ConsumeItemRequest& request,
        ProcessApiCallback<ConsumeItemResult> callback,
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
            "/Server/ConsumeItem",
            headers,
            jsonAsString,
            OnConsumeItemResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<ConsumeItemResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabServerAPI::OnConsumeItemResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        ConsumeItemResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<ConsumeItemResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabServerAPI::CreateSharedGroup(
        CreateSharedGroupRequest& request,
        ProcessApiCallback<CreateSharedGroupResult> callback,
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
            "/Server/CreateSharedGroup",
            headers,
            jsonAsString,
            OnCreateSharedGroupResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<CreateSharedGroupResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabServerAPI::OnCreateSharedGroupResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        CreateSharedGroupResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<CreateSharedGroupResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabServerAPI::DeleteCharacterFromUser(
        DeleteCharacterFromUserRequest& request,
        ProcessApiCallback<DeleteCharacterFromUserResult> callback,
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
            "/Server/DeleteCharacterFromUser",
            headers,
            jsonAsString,
            OnDeleteCharacterFromUserResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<DeleteCharacterFromUserResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabServerAPI::OnDeleteCharacterFromUserResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        DeleteCharacterFromUserResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<DeleteCharacterFromUserResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabServerAPI::DeletePlayer(
        DeletePlayerRequest& request,
        ProcessApiCallback<DeletePlayerResult> callback,
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
            "/Server/DeletePlayer",
            headers,
            jsonAsString,
            OnDeletePlayerResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<DeletePlayerResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabServerAPI::OnDeletePlayerResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        DeletePlayerResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<DeletePlayerResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabServerAPI::DeleteSharedGroup(
        DeleteSharedGroupRequest& request,
        ProcessApiCallback<EmptyResponse> callback,
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
            "/Server/DeleteSharedGroup",
            headers,
            jsonAsString,
            OnDeleteSharedGroupResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<EmptyResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabServerAPI::OnDeleteSharedGroupResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        EmptyResponse outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<EmptyResponse> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabServerAPI::DeregisterGame(
        DeregisterGameRequest& request,
        ProcessApiCallback<DeregisterGameResponse> callback,
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
            "/Server/DeregisterGame",
            headers,
            jsonAsString,
            OnDeregisterGameResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<DeregisterGameResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabServerAPI::OnDeregisterGameResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        DeregisterGameResponse outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<DeregisterGameResponse> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabServerAPI::EvaluateRandomResultTable(
        EvaluateRandomResultTableRequest& request,
        ProcessApiCallback<EvaluateRandomResultTableResult> callback,
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
            "/Server/EvaluateRandomResultTable",
            headers,
            jsonAsString,
            OnEvaluateRandomResultTableResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<EvaluateRandomResultTableResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabServerAPI::OnEvaluateRandomResultTableResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        EvaluateRandomResultTableResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<EvaluateRandomResultTableResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabServerAPI::ExecuteCloudScript(
        ExecuteCloudScriptServerRequest& request,
        ProcessApiCallback<ExecuteCloudScriptResult> callback,
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
            "/Server/ExecuteCloudScript",
            headers,
            jsonAsString,
            OnExecuteCloudScriptResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<ExecuteCloudScriptResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabServerAPI::OnExecuteCloudScriptResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        ExecuteCloudScriptResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<ExecuteCloudScriptResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabServerAPI::GetAllSegments(
        GetAllSegmentsRequest& request,
        ProcessApiCallback<GetAllSegmentsResult> callback,
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
            "/Server/GetAllSegments",
            headers,
            jsonAsString,
            OnGetAllSegmentsResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetAllSegmentsResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabServerAPI::OnGetAllSegmentsResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        GetAllSegmentsResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<GetAllSegmentsResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabServerAPI::GetAllUsersCharacters(
        ListUsersCharactersRequest& request,
        ProcessApiCallback<ListUsersCharactersResult> callback,
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
            "/Server/GetAllUsersCharacters",
            headers,
            jsonAsString,
            OnGetAllUsersCharactersResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<ListUsersCharactersResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabServerAPI::OnGetAllUsersCharactersResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        ListUsersCharactersResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<ListUsersCharactersResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabServerAPI::GetCatalogItems(
        GetCatalogItemsRequest& request,
        ProcessApiCallback<GetCatalogItemsResult> callback,
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
            "/Server/GetCatalogItems",
            headers,
            jsonAsString,
            OnGetCatalogItemsResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetCatalogItemsResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabServerAPI::OnGetCatalogItemsResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        GetCatalogItemsResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<GetCatalogItemsResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabServerAPI::GetCharacterData(
        GetCharacterDataRequest& request,
        ProcessApiCallback<GetCharacterDataResult> callback,
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
            "/Server/GetCharacterData",
            headers,
            jsonAsString,
            OnGetCharacterDataResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetCharacterDataResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabServerAPI::OnGetCharacterDataResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        GetCharacterDataResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<GetCharacterDataResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabServerAPI::GetCharacterInternalData(
        GetCharacterDataRequest& request,
        ProcessApiCallback<GetCharacterDataResult> callback,
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
            "/Server/GetCharacterInternalData",
            headers,
            jsonAsString,
            OnGetCharacterInternalDataResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetCharacterDataResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabServerAPI::OnGetCharacterInternalDataResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        GetCharacterDataResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<GetCharacterDataResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabServerAPI::GetCharacterInventory(
        GetCharacterInventoryRequest& request,
        ProcessApiCallback<GetCharacterInventoryResult> callback,
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
            "/Server/GetCharacterInventory",
            headers,
            jsonAsString,
            OnGetCharacterInventoryResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetCharacterInventoryResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabServerAPI::OnGetCharacterInventoryResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        GetCharacterInventoryResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<GetCharacterInventoryResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabServerAPI::GetCharacterLeaderboard(
        GetCharacterLeaderboardRequest& request,
        ProcessApiCallback<GetCharacterLeaderboardResult> callback,
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
            "/Server/GetCharacterLeaderboard",
            headers,
            jsonAsString,
            OnGetCharacterLeaderboardResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetCharacterLeaderboardResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabServerAPI::OnGetCharacterLeaderboardResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        GetCharacterLeaderboardResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<GetCharacterLeaderboardResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabServerAPI::GetCharacterReadOnlyData(
        GetCharacterDataRequest& request,
        ProcessApiCallback<GetCharacterDataResult> callback,
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
            "/Server/GetCharacterReadOnlyData",
            headers,
            jsonAsString,
            OnGetCharacterReadOnlyDataResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetCharacterDataResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabServerAPI::OnGetCharacterReadOnlyDataResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        GetCharacterDataResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<GetCharacterDataResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabServerAPI::GetCharacterStatistics(
        GetCharacterStatisticsRequest& request,
        ProcessApiCallback<GetCharacterStatisticsResult> callback,
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
            "/Server/GetCharacterStatistics",
            headers,
            jsonAsString,
            OnGetCharacterStatisticsResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetCharacterStatisticsResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabServerAPI::OnGetCharacterStatisticsResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        GetCharacterStatisticsResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<GetCharacterStatisticsResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabServerAPI::GetContentDownloadUrl(
        GetContentDownloadUrlRequest& request,
        ProcessApiCallback<GetContentDownloadUrlResult> callback,
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
            "/Server/GetContentDownloadUrl",
            headers,
            jsonAsString,
            OnGetContentDownloadUrlResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetContentDownloadUrlResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabServerAPI::OnGetContentDownloadUrlResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        GetContentDownloadUrlResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<GetContentDownloadUrlResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabServerAPI::GetFriendLeaderboard(
        GetFriendLeaderboardRequest& request,
        ProcessApiCallback<GetLeaderboardResult> callback,
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
            "/Server/GetFriendLeaderboard",
            headers,
            jsonAsString,
            OnGetFriendLeaderboardResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetLeaderboardResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabServerAPI::OnGetFriendLeaderboardResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        GetLeaderboardResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<GetLeaderboardResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabServerAPI::GetFriendsList(
        GetFriendsListRequest& request,
        ProcessApiCallback<GetFriendsListResult> callback,
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
            "/Server/GetFriendsList",
            headers,
            jsonAsString,
            OnGetFriendsListResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetFriendsListResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabServerAPI::OnGetFriendsListResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        GetFriendsListResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<GetFriendsListResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabServerAPI::GetLeaderboard(
        GetLeaderboardRequest& request,
        ProcessApiCallback<GetLeaderboardResult> callback,
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
            "/Server/GetLeaderboard",
            headers,
            jsonAsString,
            OnGetLeaderboardResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetLeaderboardResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabServerAPI::OnGetLeaderboardResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        GetLeaderboardResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<GetLeaderboardResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabServerAPI::GetLeaderboardAroundCharacter(
        GetLeaderboardAroundCharacterRequest& request,
        ProcessApiCallback<GetLeaderboardAroundCharacterResult> callback,
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
            "/Server/GetLeaderboardAroundCharacter",
            headers,
            jsonAsString,
            OnGetLeaderboardAroundCharacterResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetLeaderboardAroundCharacterResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabServerAPI::OnGetLeaderboardAroundCharacterResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        GetLeaderboardAroundCharacterResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<GetLeaderboardAroundCharacterResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabServerAPI::GetLeaderboardAroundUser(
        GetLeaderboardAroundUserRequest& request,
        ProcessApiCallback<GetLeaderboardAroundUserResult> callback,
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
            "/Server/GetLeaderboardAroundUser",
            headers,
            jsonAsString,
            OnGetLeaderboardAroundUserResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetLeaderboardAroundUserResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabServerAPI::OnGetLeaderboardAroundUserResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        GetLeaderboardAroundUserResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<GetLeaderboardAroundUserResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabServerAPI::GetLeaderboardForUserCharacters(
        GetLeaderboardForUsersCharactersRequest& request,
        ProcessApiCallback<GetLeaderboardForUsersCharactersResult> callback,
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
            "/Server/GetLeaderboardForUserCharacters",
            headers,
            jsonAsString,
            OnGetLeaderboardForUserCharactersResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetLeaderboardForUsersCharactersResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabServerAPI::OnGetLeaderboardForUserCharactersResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        GetLeaderboardForUsersCharactersResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<GetLeaderboardForUsersCharactersResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabServerAPI::GetPlayerCombinedInfo(
        GetPlayerCombinedInfoRequest& request,
        ProcessApiCallback<GetPlayerCombinedInfoResult> callback,
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
            "/Server/GetPlayerCombinedInfo",
            headers,
            jsonAsString,
            OnGetPlayerCombinedInfoResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetPlayerCombinedInfoResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabServerAPI::OnGetPlayerCombinedInfoResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        GetPlayerCombinedInfoResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<GetPlayerCombinedInfoResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabServerAPI::GetPlayerProfile(
        GetPlayerProfileRequest& request,
        ProcessApiCallback<GetPlayerProfileResult> callback,
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
            "/Server/GetPlayerProfile",
            headers,
            jsonAsString,
            OnGetPlayerProfileResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetPlayerProfileResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabServerAPI::OnGetPlayerProfileResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        GetPlayerProfileResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<GetPlayerProfileResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabServerAPI::GetPlayerSegments(
        GetPlayersSegmentsRequest& request,
        ProcessApiCallback<GetPlayerSegmentsResult> callback,
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
            "/Server/GetPlayerSegments",
            headers,
            jsonAsString,
            OnGetPlayerSegmentsResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetPlayerSegmentsResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabServerAPI::OnGetPlayerSegmentsResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        GetPlayerSegmentsResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<GetPlayerSegmentsResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabServerAPI::GetPlayersInSegment(
        GetPlayersInSegmentRequest& request,
        ProcessApiCallback<GetPlayersInSegmentResult> callback,
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
            "/Server/GetPlayersInSegment",
            headers,
            jsonAsString,
            OnGetPlayersInSegmentResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetPlayersInSegmentResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabServerAPI::OnGetPlayersInSegmentResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        GetPlayersInSegmentResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<GetPlayersInSegmentResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabServerAPI::GetPlayerStatistics(
        GetPlayerStatisticsRequest& request,
        ProcessApiCallback<GetPlayerStatisticsResult> callback,
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
            "/Server/GetPlayerStatistics",
            headers,
            jsonAsString,
            OnGetPlayerStatisticsResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetPlayerStatisticsResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabServerAPI::OnGetPlayerStatisticsResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        GetPlayerStatisticsResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<GetPlayerStatisticsResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabServerAPI::GetPlayerStatisticVersions(
        GetPlayerStatisticVersionsRequest& request,
        ProcessApiCallback<GetPlayerStatisticVersionsResult> callback,
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
            "/Server/GetPlayerStatisticVersions",
            headers,
            jsonAsString,
            OnGetPlayerStatisticVersionsResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetPlayerStatisticVersionsResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabServerAPI::OnGetPlayerStatisticVersionsResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        GetPlayerStatisticVersionsResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<GetPlayerStatisticVersionsResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabServerAPI::GetPlayerTags(
        GetPlayerTagsRequest& request,
        ProcessApiCallback<GetPlayerTagsResult> callback,
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
            "/Server/GetPlayerTags",
            headers,
            jsonAsString,
            OnGetPlayerTagsResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetPlayerTagsResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabServerAPI::OnGetPlayerTagsResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        GetPlayerTagsResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<GetPlayerTagsResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabServerAPI::GetPlayFabIDsFromFacebookIDs(
        GetPlayFabIDsFromFacebookIDsRequest& request,
        ProcessApiCallback<GetPlayFabIDsFromFacebookIDsResult> callback,
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
            "/Server/GetPlayFabIDsFromFacebookIDs",
            headers,
            jsonAsString,
            OnGetPlayFabIDsFromFacebookIDsResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetPlayFabIDsFromFacebookIDsResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabServerAPI::OnGetPlayFabIDsFromFacebookIDsResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        GetPlayFabIDsFromFacebookIDsResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<GetPlayFabIDsFromFacebookIDsResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabServerAPI::GetPlayFabIDsFromFacebookInstantGamesIds(
        GetPlayFabIDsFromFacebookInstantGamesIdsRequest& request,
        ProcessApiCallback<GetPlayFabIDsFromFacebookInstantGamesIdsResult> callback,
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
            "/Server/GetPlayFabIDsFromFacebookInstantGamesIds",
            headers,
            jsonAsString,
            OnGetPlayFabIDsFromFacebookInstantGamesIdsResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetPlayFabIDsFromFacebookInstantGamesIdsResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabServerAPI::OnGetPlayFabIDsFromFacebookInstantGamesIdsResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        GetPlayFabIDsFromFacebookInstantGamesIdsResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<GetPlayFabIDsFromFacebookInstantGamesIdsResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabServerAPI::GetPlayFabIDsFromNintendoSwitchDeviceIds(
        GetPlayFabIDsFromNintendoSwitchDeviceIdsRequest& request,
        ProcessApiCallback<GetPlayFabIDsFromNintendoSwitchDeviceIdsResult> callback,
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
            "/Server/GetPlayFabIDsFromNintendoSwitchDeviceIds",
            headers,
            jsonAsString,
            OnGetPlayFabIDsFromNintendoSwitchDeviceIdsResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetPlayFabIDsFromNintendoSwitchDeviceIdsResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabServerAPI::OnGetPlayFabIDsFromNintendoSwitchDeviceIdsResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        GetPlayFabIDsFromNintendoSwitchDeviceIdsResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<GetPlayFabIDsFromNintendoSwitchDeviceIdsResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabServerAPI::GetPlayFabIDsFromSteamIDs(
        GetPlayFabIDsFromSteamIDsRequest& request,
        ProcessApiCallback<GetPlayFabIDsFromSteamIDsResult> callback,
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
            "/Server/GetPlayFabIDsFromSteamIDs",
            headers,
            jsonAsString,
            OnGetPlayFabIDsFromSteamIDsResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetPlayFabIDsFromSteamIDsResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabServerAPI::OnGetPlayFabIDsFromSteamIDsResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        GetPlayFabIDsFromSteamIDsResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<GetPlayFabIDsFromSteamIDsResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabServerAPI::GetPlayFabIDsFromXboxLiveIDs(
        GetPlayFabIDsFromXboxLiveIDsRequest& request,
        ProcessApiCallback<GetPlayFabIDsFromXboxLiveIDsResult> callback,
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
            "/Server/GetPlayFabIDsFromXboxLiveIDs",
            headers,
            jsonAsString,
            OnGetPlayFabIDsFromXboxLiveIDsResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetPlayFabIDsFromXboxLiveIDsResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabServerAPI::OnGetPlayFabIDsFromXboxLiveIDsResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        GetPlayFabIDsFromXboxLiveIDsResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<GetPlayFabIDsFromXboxLiveIDsResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabServerAPI::GetPublisherData(
        GetPublisherDataRequest& request,
        ProcessApiCallback<GetPublisherDataResult> callback,
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
            "/Server/GetPublisherData",
            headers,
            jsonAsString,
            OnGetPublisherDataResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetPublisherDataResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabServerAPI::OnGetPublisherDataResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        GetPublisherDataResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<GetPublisherDataResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabServerAPI::GetRandomResultTables(
        GetRandomResultTablesRequest& request,
        ProcessApiCallback<GetRandomResultTablesResult> callback,
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
            "/Server/GetRandomResultTables",
            headers,
            jsonAsString,
            OnGetRandomResultTablesResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetRandomResultTablesResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabServerAPI::OnGetRandomResultTablesResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        GetRandomResultTablesResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<GetRandomResultTablesResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabServerAPI::GetServerCustomIDsFromPlayFabIDs(
        GetServerCustomIDsFromPlayFabIDsRequest& request,
        ProcessApiCallback<GetServerCustomIDsFromPlayFabIDsResult> callback,
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
            "/Server/GetServerCustomIDsFromPlayFabIDs",
            headers,
            jsonAsString,
            OnGetServerCustomIDsFromPlayFabIDsResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetServerCustomIDsFromPlayFabIDsResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabServerAPI::OnGetServerCustomIDsFromPlayFabIDsResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        GetServerCustomIDsFromPlayFabIDsResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<GetServerCustomIDsFromPlayFabIDsResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabServerAPI::GetSharedGroupData(
        GetSharedGroupDataRequest& request,
        ProcessApiCallback<GetSharedGroupDataResult> callback,
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
            "/Server/GetSharedGroupData",
            headers,
            jsonAsString,
            OnGetSharedGroupDataResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetSharedGroupDataResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabServerAPI::OnGetSharedGroupDataResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        GetSharedGroupDataResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<GetSharedGroupDataResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabServerAPI::GetTime(
        GetTimeRequest& request,
        ProcessApiCallback<GetTimeResult> callback,
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
            "/Server/GetTime",
            headers,
            jsonAsString,
            OnGetTimeResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetTimeResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabServerAPI::OnGetTimeResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        GetTimeResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<GetTimeResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabServerAPI::GetTitleData(
        GetTitleDataRequest& request,
        ProcessApiCallback<GetTitleDataResult> callback,
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
            "/Server/GetTitleData",
            headers,
            jsonAsString,
            OnGetTitleDataResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetTitleDataResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabServerAPI::OnGetTitleDataResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        GetTitleDataResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<GetTitleDataResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabServerAPI::GetTitleInternalData(
        GetTitleDataRequest& request,
        ProcessApiCallback<GetTitleDataResult> callback,
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
            "/Server/GetTitleInternalData",
            headers,
            jsonAsString,
            OnGetTitleInternalDataResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetTitleDataResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabServerAPI::OnGetTitleInternalDataResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        GetTitleDataResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<GetTitleDataResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabServerAPI::GetTitleNews(
        GetTitleNewsRequest& request,
        ProcessApiCallback<GetTitleNewsResult> callback,
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
            "/Server/GetTitleNews",
            headers,
            jsonAsString,
            OnGetTitleNewsResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetTitleNewsResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabServerAPI::OnGetTitleNewsResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        GetTitleNewsResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<GetTitleNewsResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabServerAPI::GetUserAccountInfo(
        GetUserAccountInfoRequest& request,
        ProcessApiCallback<GetUserAccountInfoResult> callback,
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
            "/Server/GetUserAccountInfo",
            headers,
            jsonAsString,
            OnGetUserAccountInfoResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetUserAccountInfoResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabServerAPI::OnGetUserAccountInfoResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        GetUserAccountInfoResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<GetUserAccountInfoResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabServerAPI::GetUserBans(
        GetUserBansRequest& request,
        ProcessApiCallback<GetUserBansResult> callback,
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
            "/Server/GetUserBans",
            headers,
            jsonAsString,
            OnGetUserBansResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetUserBansResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabServerAPI::OnGetUserBansResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        GetUserBansResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<GetUserBansResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabServerAPI::GetUserData(
        GetUserDataRequest& request,
        ProcessApiCallback<GetUserDataResult> callback,
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
            "/Server/GetUserData",
            headers,
            jsonAsString,
            OnGetUserDataResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetUserDataResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabServerAPI::OnGetUserDataResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        GetUserDataResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<GetUserDataResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabServerAPI::GetUserInternalData(
        GetUserDataRequest& request,
        ProcessApiCallback<GetUserDataResult> callback,
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
            "/Server/GetUserInternalData",
            headers,
            jsonAsString,
            OnGetUserInternalDataResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetUserDataResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabServerAPI::OnGetUserInternalDataResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        GetUserDataResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<GetUserDataResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabServerAPI::GetUserInventory(
        GetUserInventoryRequest& request,
        ProcessApiCallback<GetUserInventoryResult> callback,
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
            "/Server/GetUserInventory",
            headers,
            jsonAsString,
            OnGetUserInventoryResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetUserInventoryResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabServerAPI::OnGetUserInventoryResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        GetUserInventoryResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<GetUserInventoryResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabServerAPI::GetUserPublisherData(
        GetUserDataRequest& request,
        ProcessApiCallback<GetUserDataResult> callback,
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
            "/Server/GetUserPublisherData",
            headers,
            jsonAsString,
            OnGetUserPublisherDataResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetUserDataResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabServerAPI::OnGetUserPublisherDataResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        GetUserDataResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<GetUserDataResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabServerAPI::GetUserPublisherInternalData(
        GetUserDataRequest& request,
        ProcessApiCallback<GetUserDataResult> callback,
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
            "/Server/GetUserPublisherInternalData",
            headers,
            jsonAsString,
            OnGetUserPublisherInternalDataResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetUserDataResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabServerAPI::OnGetUserPublisherInternalDataResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        GetUserDataResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<GetUserDataResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabServerAPI::GetUserPublisherReadOnlyData(
        GetUserDataRequest& request,
        ProcessApiCallback<GetUserDataResult> callback,
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
            "/Server/GetUserPublisherReadOnlyData",
            headers,
            jsonAsString,
            OnGetUserPublisherReadOnlyDataResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetUserDataResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabServerAPI::OnGetUserPublisherReadOnlyDataResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        GetUserDataResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<GetUserDataResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabServerAPI::GetUserReadOnlyData(
        GetUserDataRequest& request,
        ProcessApiCallback<GetUserDataResult> callback,
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
            "/Server/GetUserReadOnlyData",
            headers,
            jsonAsString,
            OnGetUserReadOnlyDataResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetUserDataResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabServerAPI::OnGetUserReadOnlyDataResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        GetUserDataResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<GetUserDataResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabServerAPI::GrantCharacterToUser(
        GrantCharacterToUserRequest& request,
        ProcessApiCallback<GrantCharacterToUserResult> callback,
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
            "/Server/GrantCharacterToUser",
            headers,
            jsonAsString,
            OnGrantCharacterToUserResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GrantCharacterToUserResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabServerAPI::OnGrantCharacterToUserResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        GrantCharacterToUserResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<GrantCharacterToUserResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabServerAPI::GrantItemsToCharacter(
        GrantItemsToCharacterRequest& request,
        ProcessApiCallback<GrantItemsToCharacterResult> callback,
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
            "/Server/GrantItemsToCharacter",
            headers,
            jsonAsString,
            OnGrantItemsToCharacterResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GrantItemsToCharacterResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabServerAPI::OnGrantItemsToCharacterResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        GrantItemsToCharacterResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<GrantItemsToCharacterResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabServerAPI::GrantItemsToUser(
        GrantItemsToUserRequest& request,
        ProcessApiCallback<GrantItemsToUserResult> callback,
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
            "/Server/GrantItemsToUser",
            headers,
            jsonAsString,
            OnGrantItemsToUserResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GrantItemsToUserResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabServerAPI::OnGrantItemsToUserResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        GrantItemsToUserResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<GrantItemsToUserResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabServerAPI::GrantItemsToUsers(
        GrantItemsToUsersRequest& request,
        ProcessApiCallback<GrantItemsToUsersResult> callback,
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
            "/Server/GrantItemsToUsers",
            headers,
            jsonAsString,
            OnGrantItemsToUsersResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GrantItemsToUsersResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabServerAPI::OnGrantItemsToUsersResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        GrantItemsToUsersResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<GrantItemsToUsersResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabServerAPI::LinkXboxAccount(
        LinkXboxAccountRequest& request,
        ProcessApiCallback<LinkXboxAccountResult> callback,
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
            "/Server/LinkXboxAccount",
            headers,
            jsonAsString,
            OnLinkXboxAccountResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<LinkXboxAccountResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabServerAPI::OnLinkXboxAccountResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        LinkXboxAccountResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<LinkXboxAccountResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabServerAPI::LoginWithServerCustomId(
        LoginWithServerCustomIdRequest& request,
        ProcessApiCallback<ServerLoginResult> callback,
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
            "/Server/LoginWithServerCustomId",
            headers,
            jsonAsString,
            OnLoginWithServerCustomIdResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<ServerLoginResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabServerAPI::OnLoginWithServerCustomIdResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        ServerLoginResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<ServerLoginResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabServerAPI::LoginWithXbox(
        LoginWithXboxRequest& request,
        ProcessApiCallback<ServerLoginResult> callback,
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
            "/Server/LoginWithXbox",
            headers,
            jsonAsString,
            OnLoginWithXboxResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<ServerLoginResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabServerAPI::OnLoginWithXboxResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        ServerLoginResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<ServerLoginResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabServerAPI::ModifyItemUses(
        ModifyItemUsesRequest& request,
        ProcessApiCallback<ModifyItemUsesResult> callback,
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
            "/Server/ModifyItemUses",
            headers,
            jsonAsString,
            OnModifyItemUsesResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<ModifyItemUsesResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabServerAPI::OnModifyItemUsesResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        ModifyItemUsesResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<ModifyItemUsesResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabServerAPI::MoveItemToCharacterFromCharacter(
        MoveItemToCharacterFromCharacterRequest& request,
        ProcessApiCallback<MoveItemToCharacterFromCharacterResult> callback,
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
            "/Server/MoveItemToCharacterFromCharacter",
            headers,
            jsonAsString,
            OnMoveItemToCharacterFromCharacterResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<MoveItemToCharacterFromCharacterResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabServerAPI::OnMoveItemToCharacterFromCharacterResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        MoveItemToCharacterFromCharacterResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<MoveItemToCharacterFromCharacterResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabServerAPI::MoveItemToCharacterFromUser(
        MoveItemToCharacterFromUserRequest& request,
        ProcessApiCallback<MoveItemToCharacterFromUserResult> callback,
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
            "/Server/MoveItemToCharacterFromUser",
            headers,
            jsonAsString,
            OnMoveItemToCharacterFromUserResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<MoveItemToCharacterFromUserResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabServerAPI::OnMoveItemToCharacterFromUserResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        MoveItemToCharacterFromUserResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<MoveItemToCharacterFromUserResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabServerAPI::MoveItemToUserFromCharacter(
        MoveItemToUserFromCharacterRequest& request,
        ProcessApiCallback<MoveItemToUserFromCharacterResult> callback,
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
            "/Server/MoveItemToUserFromCharacter",
            headers,
            jsonAsString,
            OnMoveItemToUserFromCharacterResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<MoveItemToUserFromCharacterResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabServerAPI::OnMoveItemToUserFromCharacterResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        MoveItemToUserFromCharacterResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<MoveItemToUserFromCharacterResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabServerAPI::NotifyMatchmakerPlayerLeft(
        NotifyMatchmakerPlayerLeftRequest& request,
        ProcessApiCallback<NotifyMatchmakerPlayerLeftResult> callback,
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
            "/Server/NotifyMatchmakerPlayerLeft",
            headers,
            jsonAsString,
            OnNotifyMatchmakerPlayerLeftResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<NotifyMatchmakerPlayerLeftResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabServerAPI::OnNotifyMatchmakerPlayerLeftResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        NotifyMatchmakerPlayerLeftResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<NotifyMatchmakerPlayerLeftResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabServerAPI::RedeemCoupon(
        RedeemCouponRequest& request,
        ProcessApiCallback<RedeemCouponResult> callback,
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
            "/Server/RedeemCoupon",
            headers,
            jsonAsString,
            OnRedeemCouponResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<RedeemCouponResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabServerAPI::OnRedeemCouponResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        RedeemCouponResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<RedeemCouponResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabServerAPI::RedeemMatchmakerTicket(
        RedeemMatchmakerTicketRequest& request,
        ProcessApiCallback<RedeemMatchmakerTicketResult> callback,
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
            "/Server/RedeemMatchmakerTicket",
            headers,
            jsonAsString,
            OnRedeemMatchmakerTicketResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<RedeemMatchmakerTicketResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabServerAPI::OnRedeemMatchmakerTicketResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        RedeemMatchmakerTicketResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<RedeemMatchmakerTicketResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabServerAPI::RefreshGameServerInstanceHeartbeat(
        RefreshGameServerInstanceHeartbeatRequest& request,
        ProcessApiCallback<RefreshGameServerInstanceHeartbeatResult> callback,
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
            "/Server/RefreshGameServerInstanceHeartbeat",
            headers,
            jsonAsString,
            OnRefreshGameServerInstanceHeartbeatResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<RefreshGameServerInstanceHeartbeatResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabServerAPI::OnRefreshGameServerInstanceHeartbeatResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        RefreshGameServerInstanceHeartbeatResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<RefreshGameServerInstanceHeartbeatResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabServerAPI::RegisterGame(
        RegisterGameRequest& request,
        ProcessApiCallback<RegisterGameResponse> callback,
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
            "/Server/RegisterGame",
            headers,
            jsonAsString,
            OnRegisterGameResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<RegisterGameResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabServerAPI::OnRegisterGameResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        RegisterGameResponse outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<RegisterGameResponse> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabServerAPI::RemoveFriend(
        RemoveFriendRequest& request,
        ProcessApiCallback<EmptyResponse> callback,
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
            "/Server/RemoveFriend",
            headers,
            jsonAsString,
            OnRemoveFriendResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<EmptyResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabServerAPI::OnRemoveFriendResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        EmptyResponse outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<EmptyResponse> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabServerAPI::RemovePlayerTag(
        RemovePlayerTagRequest& request,
        ProcessApiCallback<RemovePlayerTagResult> callback,
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
            "/Server/RemovePlayerTag",
            headers,
            jsonAsString,
            OnRemovePlayerTagResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<RemovePlayerTagResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabServerAPI::OnRemovePlayerTagResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        RemovePlayerTagResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<RemovePlayerTagResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabServerAPI::RemoveSharedGroupMembers(
        RemoveSharedGroupMembersRequest& request,
        ProcessApiCallback<RemoveSharedGroupMembersResult> callback,
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
            "/Server/RemoveSharedGroupMembers",
            headers,
            jsonAsString,
            OnRemoveSharedGroupMembersResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<RemoveSharedGroupMembersResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabServerAPI::OnRemoveSharedGroupMembersResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        RemoveSharedGroupMembersResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<RemoveSharedGroupMembersResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabServerAPI::ReportPlayer(
        ReportPlayerServerRequest& request,
        ProcessApiCallback<ReportPlayerServerResult> callback,
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
            "/Server/ReportPlayer",
            headers,
            jsonAsString,
            OnReportPlayerResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<ReportPlayerServerResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabServerAPI::OnReportPlayerResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        ReportPlayerServerResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<ReportPlayerServerResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabServerAPI::RevokeAllBansForUser(
        RevokeAllBansForUserRequest& request,
        ProcessApiCallback<RevokeAllBansForUserResult> callback,
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
            "/Server/RevokeAllBansForUser",
            headers,
            jsonAsString,
            OnRevokeAllBansForUserResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<RevokeAllBansForUserResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabServerAPI::OnRevokeAllBansForUserResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        RevokeAllBansForUserResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<RevokeAllBansForUserResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabServerAPI::RevokeBans(
        RevokeBansRequest& request,
        ProcessApiCallback<RevokeBansResult> callback,
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
            "/Server/RevokeBans",
            headers,
            jsonAsString,
            OnRevokeBansResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<RevokeBansResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabServerAPI::OnRevokeBansResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        RevokeBansResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<RevokeBansResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabServerAPI::RevokeInventoryItem(
        RevokeInventoryItemRequest& request,
        ProcessApiCallback<RevokeInventoryResult> callback,
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
            "/Server/RevokeInventoryItem",
            headers,
            jsonAsString,
            OnRevokeInventoryItemResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<RevokeInventoryResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabServerAPI::OnRevokeInventoryItemResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        RevokeInventoryResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<RevokeInventoryResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabServerAPI::RevokeInventoryItems(
        RevokeInventoryItemsRequest& request,
        ProcessApiCallback<RevokeInventoryItemsResult> callback,
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
            "/Server/RevokeInventoryItems",
            headers,
            jsonAsString,
            OnRevokeInventoryItemsResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<RevokeInventoryItemsResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabServerAPI::OnRevokeInventoryItemsResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        RevokeInventoryItemsResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<RevokeInventoryItemsResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabServerAPI::SendCustomAccountRecoveryEmail(
        SendCustomAccountRecoveryEmailRequest& request,
        ProcessApiCallback<SendCustomAccountRecoveryEmailResult> callback,
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
            "/Server/SendCustomAccountRecoveryEmail",
            headers,
            jsonAsString,
            OnSendCustomAccountRecoveryEmailResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<SendCustomAccountRecoveryEmailResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabServerAPI::OnSendCustomAccountRecoveryEmailResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        SendCustomAccountRecoveryEmailResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<SendCustomAccountRecoveryEmailResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabServerAPI::SendEmailFromTemplate(
        SendEmailFromTemplateRequest& request,
        ProcessApiCallback<SendEmailFromTemplateResult> callback,
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
            "/Server/SendEmailFromTemplate",
            headers,
            jsonAsString,
            OnSendEmailFromTemplateResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<SendEmailFromTemplateResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabServerAPI::OnSendEmailFromTemplateResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        SendEmailFromTemplateResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<SendEmailFromTemplateResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabServerAPI::SendPushNotification(
        SendPushNotificationRequest& request,
        ProcessApiCallback<SendPushNotificationResult> callback,
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
            "/Server/SendPushNotification",
            headers,
            jsonAsString,
            OnSendPushNotificationResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<SendPushNotificationResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabServerAPI::OnSendPushNotificationResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        SendPushNotificationResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<SendPushNotificationResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabServerAPI::SetFriendTags(
        SetFriendTagsRequest& request,
        ProcessApiCallback<EmptyResponse> callback,
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
            "/Server/SetFriendTags",
            headers,
            jsonAsString,
            OnSetFriendTagsResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<EmptyResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabServerAPI::OnSetFriendTagsResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        EmptyResponse outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<EmptyResponse> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabServerAPI::SetGameServerInstanceData(
        SetGameServerInstanceDataRequest& request,
        ProcessApiCallback<SetGameServerInstanceDataResult> callback,
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
            "/Server/SetGameServerInstanceData",
            headers,
            jsonAsString,
            OnSetGameServerInstanceDataResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<SetGameServerInstanceDataResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabServerAPI::OnSetGameServerInstanceDataResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        SetGameServerInstanceDataResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<SetGameServerInstanceDataResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabServerAPI::SetGameServerInstanceState(
        SetGameServerInstanceStateRequest& request,
        ProcessApiCallback<SetGameServerInstanceStateResult> callback,
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
            "/Server/SetGameServerInstanceState",
            headers,
            jsonAsString,
            OnSetGameServerInstanceStateResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<SetGameServerInstanceStateResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabServerAPI::OnSetGameServerInstanceStateResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        SetGameServerInstanceStateResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<SetGameServerInstanceStateResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabServerAPI::SetGameServerInstanceTags(
        SetGameServerInstanceTagsRequest& request,
        ProcessApiCallback<SetGameServerInstanceTagsResult> callback,
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
            "/Server/SetGameServerInstanceTags",
            headers,
            jsonAsString,
            OnSetGameServerInstanceTagsResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<SetGameServerInstanceTagsResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabServerAPI::OnSetGameServerInstanceTagsResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        SetGameServerInstanceTagsResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<SetGameServerInstanceTagsResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabServerAPI::SetPlayerSecret(
        SetPlayerSecretRequest& request,
        ProcessApiCallback<SetPlayerSecretResult> callback,
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
            "/Server/SetPlayerSecret",
            headers,
            jsonAsString,
            OnSetPlayerSecretResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<SetPlayerSecretResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabServerAPI::OnSetPlayerSecretResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        SetPlayerSecretResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<SetPlayerSecretResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabServerAPI::SetPublisherData(
        SetPublisherDataRequest& request,
        ProcessApiCallback<SetPublisherDataResult> callback,
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
            "/Server/SetPublisherData",
            headers,
            jsonAsString,
            OnSetPublisherDataResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<SetPublisherDataResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabServerAPI::OnSetPublisherDataResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        SetPublisherDataResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<SetPublisherDataResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabServerAPI::SetTitleData(
        SetTitleDataRequest& request,
        ProcessApiCallback<SetTitleDataResult> callback,
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
            "/Server/SetTitleData",
            headers,
            jsonAsString,
            OnSetTitleDataResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<SetTitleDataResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabServerAPI::OnSetTitleDataResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        SetTitleDataResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<SetTitleDataResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabServerAPI::SetTitleInternalData(
        SetTitleDataRequest& request,
        ProcessApiCallback<SetTitleDataResult> callback,
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
            "/Server/SetTitleInternalData",
            headers,
            jsonAsString,
            OnSetTitleInternalDataResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<SetTitleDataResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabServerAPI::OnSetTitleInternalDataResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        SetTitleDataResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<SetTitleDataResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabServerAPI::SubtractCharacterVirtualCurrency(
        SubtractCharacterVirtualCurrencyRequest& request,
        ProcessApiCallback<ModifyCharacterVirtualCurrencyResult> callback,
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
            "/Server/SubtractCharacterVirtualCurrency",
            headers,
            jsonAsString,
            OnSubtractCharacterVirtualCurrencyResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<ModifyCharacterVirtualCurrencyResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabServerAPI::OnSubtractCharacterVirtualCurrencyResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        ModifyCharacterVirtualCurrencyResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<ModifyCharacterVirtualCurrencyResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabServerAPI::SubtractUserVirtualCurrency(
        SubtractUserVirtualCurrencyRequest& request,
        ProcessApiCallback<ModifyUserVirtualCurrencyResult> callback,
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
            "/Server/SubtractUserVirtualCurrency",
            headers,
            jsonAsString,
            OnSubtractUserVirtualCurrencyResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<ModifyUserVirtualCurrencyResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabServerAPI::OnSubtractUserVirtualCurrencyResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        ModifyUserVirtualCurrencyResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<ModifyUserVirtualCurrencyResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabServerAPI::UnlinkXboxAccount(
        UnlinkXboxAccountRequest& request,
        ProcessApiCallback<UnlinkXboxAccountResult> callback,
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
            "/Server/UnlinkXboxAccount",
            headers,
            jsonAsString,
            OnUnlinkXboxAccountResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<UnlinkXboxAccountResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabServerAPI::OnUnlinkXboxAccountResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        UnlinkXboxAccountResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<UnlinkXboxAccountResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabServerAPI::UnlockContainerInstance(
        UnlockContainerInstanceRequest& request,
        ProcessApiCallback<UnlockContainerItemResult> callback,
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
            "/Server/UnlockContainerInstance",
            headers,
            jsonAsString,
            OnUnlockContainerInstanceResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<UnlockContainerItemResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabServerAPI::OnUnlockContainerInstanceResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        UnlockContainerItemResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<UnlockContainerItemResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabServerAPI::UnlockContainerItem(
        UnlockContainerItemRequest& request,
        ProcessApiCallback<UnlockContainerItemResult> callback,
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
            "/Server/UnlockContainerItem",
            headers,
            jsonAsString,
            OnUnlockContainerItemResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<UnlockContainerItemResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabServerAPI::OnUnlockContainerItemResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        UnlockContainerItemResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<UnlockContainerItemResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabServerAPI::UpdateAvatarUrl(
        UpdateAvatarUrlRequest& request,
        ProcessApiCallback<EmptyResponse> callback,
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
            "/Server/UpdateAvatarUrl",
            headers,
            jsonAsString,
            OnUpdateAvatarUrlResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<EmptyResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabServerAPI::OnUpdateAvatarUrlResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        EmptyResponse outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<EmptyResponse> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabServerAPI::UpdateBans(
        UpdateBansRequest& request,
        ProcessApiCallback<UpdateBansResult> callback,
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
            "/Server/UpdateBans",
            headers,
            jsonAsString,
            OnUpdateBansResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<UpdateBansResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabServerAPI::OnUpdateBansResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        UpdateBansResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<UpdateBansResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabServerAPI::UpdateCharacterData(
        UpdateCharacterDataRequest& request,
        ProcessApiCallback<UpdateCharacterDataResult> callback,
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
            "/Server/UpdateCharacterData",
            headers,
            jsonAsString,
            OnUpdateCharacterDataResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<UpdateCharacterDataResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabServerAPI::OnUpdateCharacterDataResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        UpdateCharacterDataResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<UpdateCharacterDataResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabServerAPI::UpdateCharacterInternalData(
        UpdateCharacterDataRequest& request,
        ProcessApiCallback<UpdateCharacterDataResult> callback,
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
            "/Server/UpdateCharacterInternalData",
            headers,
            jsonAsString,
            OnUpdateCharacterInternalDataResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<UpdateCharacterDataResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabServerAPI::OnUpdateCharacterInternalDataResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        UpdateCharacterDataResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<UpdateCharacterDataResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabServerAPI::UpdateCharacterReadOnlyData(
        UpdateCharacterDataRequest& request,
        ProcessApiCallback<UpdateCharacterDataResult> callback,
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
            "/Server/UpdateCharacterReadOnlyData",
            headers,
            jsonAsString,
            OnUpdateCharacterReadOnlyDataResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<UpdateCharacterDataResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabServerAPI::OnUpdateCharacterReadOnlyDataResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        UpdateCharacterDataResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<UpdateCharacterDataResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabServerAPI::UpdateCharacterStatistics(
        UpdateCharacterStatisticsRequest& request,
        ProcessApiCallback<UpdateCharacterStatisticsResult> callback,
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
            "/Server/UpdateCharacterStatistics",
            headers,
            jsonAsString,
            OnUpdateCharacterStatisticsResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<UpdateCharacterStatisticsResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabServerAPI::OnUpdateCharacterStatisticsResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        UpdateCharacterStatisticsResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<UpdateCharacterStatisticsResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabServerAPI::UpdatePlayerStatistics(
        UpdatePlayerStatisticsRequest& request,
        ProcessApiCallback<UpdatePlayerStatisticsResult> callback,
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
            "/Server/UpdatePlayerStatistics",
            headers,
            jsonAsString,
            OnUpdatePlayerStatisticsResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<UpdatePlayerStatisticsResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabServerAPI::OnUpdatePlayerStatisticsResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        UpdatePlayerStatisticsResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<UpdatePlayerStatisticsResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabServerAPI::UpdateSharedGroupData(
        UpdateSharedGroupDataRequest& request,
        ProcessApiCallback<UpdateSharedGroupDataResult> callback,
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
            "/Server/UpdateSharedGroupData",
            headers,
            jsonAsString,
            OnUpdateSharedGroupDataResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<UpdateSharedGroupDataResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabServerAPI::OnUpdateSharedGroupDataResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        UpdateSharedGroupDataResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<UpdateSharedGroupDataResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabServerAPI::UpdateUserData(
        UpdateUserDataRequest& request,
        ProcessApiCallback<UpdateUserDataResult> callback,
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
            "/Server/UpdateUserData",
            headers,
            jsonAsString,
            OnUpdateUserDataResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<UpdateUserDataResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabServerAPI::OnUpdateUserDataResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        UpdateUserDataResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<UpdateUserDataResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabServerAPI::UpdateUserInternalData(
        UpdateUserInternalDataRequest& request,
        ProcessApiCallback<UpdateUserDataResult> callback,
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
            "/Server/UpdateUserInternalData",
            headers,
            jsonAsString,
            OnUpdateUserInternalDataResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<UpdateUserDataResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabServerAPI::OnUpdateUserInternalDataResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        UpdateUserDataResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<UpdateUserDataResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabServerAPI::UpdateUserInventoryItemCustomData(
        UpdateUserInventoryItemDataRequest& request,
        ProcessApiCallback<EmptyResponse> callback,
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
            "/Server/UpdateUserInventoryItemCustomData",
            headers,
            jsonAsString,
            OnUpdateUserInventoryItemCustomDataResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<EmptyResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabServerAPI::OnUpdateUserInventoryItemCustomDataResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        EmptyResponse outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<EmptyResponse> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabServerAPI::UpdateUserPublisherData(
        UpdateUserDataRequest& request,
        ProcessApiCallback<UpdateUserDataResult> callback,
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
            "/Server/UpdateUserPublisherData",
            headers,
            jsonAsString,
            OnUpdateUserPublisherDataResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<UpdateUserDataResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabServerAPI::OnUpdateUserPublisherDataResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        UpdateUserDataResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<UpdateUserDataResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabServerAPI::UpdateUserPublisherInternalData(
        UpdateUserInternalDataRequest& request,
        ProcessApiCallback<UpdateUserDataResult> callback,
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
            "/Server/UpdateUserPublisherInternalData",
            headers,
            jsonAsString,
            OnUpdateUserPublisherInternalDataResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<UpdateUserDataResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabServerAPI::OnUpdateUserPublisherInternalDataResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        UpdateUserDataResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<UpdateUserDataResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabServerAPI::UpdateUserPublisherReadOnlyData(
        UpdateUserDataRequest& request,
        ProcessApiCallback<UpdateUserDataResult> callback,
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
            "/Server/UpdateUserPublisherReadOnlyData",
            headers,
            jsonAsString,
            OnUpdateUserPublisherReadOnlyDataResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<UpdateUserDataResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabServerAPI::OnUpdateUserPublisherReadOnlyDataResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        UpdateUserDataResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<UpdateUserDataResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabServerAPI::UpdateUserReadOnlyData(
        UpdateUserDataRequest& request,
        ProcessApiCallback<UpdateUserDataResult> callback,
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
            "/Server/UpdateUserReadOnlyData",
            headers,
            jsonAsString,
            OnUpdateUserReadOnlyDataResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<UpdateUserDataResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabServerAPI::OnUpdateUserReadOnlyDataResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        UpdateUserDataResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<UpdateUserDataResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabServerAPI::WriteCharacterEvent(
        WriteServerCharacterEventRequest& request,
        ProcessApiCallback<WriteEventResponse> callback,
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
            "/Server/WriteCharacterEvent",
            headers,
            jsonAsString,
            OnWriteCharacterEventResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<WriteEventResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabServerAPI::OnWriteCharacterEventResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        WriteEventResponse outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<WriteEventResponse> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabServerAPI::WritePlayerEvent(
        WriteServerPlayerEventRequest& request,
        ProcessApiCallback<WriteEventResponse> callback,
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
            "/Server/WritePlayerEvent",
            headers,
            jsonAsString,
            OnWritePlayerEventResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<WriteEventResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabServerAPI::OnWritePlayerEventResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        WriteEventResponse outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<WriteEventResponse> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabServerAPI::WriteTitleEvent(
        WriteTitleEventRequest& request,
        ProcessApiCallback<WriteEventResponse> callback,
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
            "/Server/WriteTitleEvent",
            headers,
            jsonAsString,
            OnWriteTitleEventResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<WriteEventResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabServerAPI::OnWriteTitleEventResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        WriteEventResponse outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<WriteEventResponse> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    bool PlayFabServerAPI::ValidateResult(PlayFabResultCommon& resultCommon, CallRequestContainer& container)
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
