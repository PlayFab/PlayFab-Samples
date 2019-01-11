#include <stdafx.h>

#ifdef ENABLE_PLAYFABADMIN_API

#include <playfab/PlayFabAdminApi.h>
#include <playfab/PlayFabHttp.h>
#include <playfab/PlayFabSettings.h>
#include <playfab/PlayFabError.h>

#pragma warning (disable: 4100) // formal parameters are part of a public interface

namespace PlayFab
{
    using namespace AdminModels;

    size_t PlayFabAdminAPI::Update()
    {
        return PlayFabHttp::Get().Update();
    }

    void PlayFabAdminAPI::ForgetAllCredentials()
    {
        return PlayFabSettings::ForgetAllCredentials();
    }

    // PlayFabAdmin APIs

    void PlayFabAdminAPI::AbortTaskInstance(
        AbortTaskInstanceRequest& request,
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
            "/Admin/AbortTaskInstance",
            headers,
            jsonAsString,
            OnAbortTaskInstanceResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<EmptyResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabAdminAPI::OnAbortTaskInstanceResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
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

    void PlayFabAdminAPI::AddNews(
        AddNewsRequest& request,
        ProcessApiCallback<AddNewsResult> callback,
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
            "/Admin/AddNews",
            headers,
            jsonAsString,
            OnAddNewsResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<AddNewsResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabAdminAPI::OnAddNewsResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        AddNewsResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<AddNewsResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabAdminAPI::AddPlayerTag(
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
            "/Admin/AddPlayerTag",
            headers,
            jsonAsString,
            OnAddPlayerTagResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<AddPlayerTagResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabAdminAPI::OnAddPlayerTagResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
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

    void PlayFabAdminAPI::AddServerBuild(
        AddServerBuildRequest& request,
        ProcessApiCallback<AddServerBuildResult> callback,
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
            "/Admin/AddServerBuild",
            headers,
            jsonAsString,
            OnAddServerBuildResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<AddServerBuildResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabAdminAPI::OnAddServerBuildResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        AddServerBuildResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<AddServerBuildResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabAdminAPI::AddUserVirtualCurrency(
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
            "/Admin/AddUserVirtualCurrency",
            headers,
            jsonAsString,
            OnAddUserVirtualCurrencyResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<ModifyUserVirtualCurrencyResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabAdminAPI::OnAddUserVirtualCurrencyResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
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

    void PlayFabAdminAPI::AddVirtualCurrencyTypes(
        AddVirtualCurrencyTypesRequest& request,
        ProcessApiCallback<BlankResult> callback,
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
            "/Admin/AddVirtualCurrencyTypes",
            headers,
            jsonAsString,
            OnAddVirtualCurrencyTypesResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<BlankResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabAdminAPI::OnAddVirtualCurrencyTypesResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        BlankResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<BlankResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabAdminAPI::BanUsers(
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
            "/Admin/BanUsers",
            headers,
            jsonAsString,
            OnBanUsersResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<BanUsersResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabAdminAPI::OnBanUsersResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
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

    void PlayFabAdminAPI::CheckLimitedEditionItemAvailability(
        CheckLimitedEditionItemAvailabilityRequest& request,
        ProcessApiCallback<CheckLimitedEditionItemAvailabilityResult> callback,
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
            "/Admin/CheckLimitedEditionItemAvailability",
            headers,
            jsonAsString,
            OnCheckLimitedEditionItemAvailabilityResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<CheckLimitedEditionItemAvailabilityResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabAdminAPI::OnCheckLimitedEditionItemAvailabilityResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        CheckLimitedEditionItemAvailabilityResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<CheckLimitedEditionItemAvailabilityResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabAdminAPI::CreateActionsOnPlayersInSegmentTask(
        CreateActionsOnPlayerSegmentTaskRequest& request,
        ProcessApiCallback<CreateTaskResult> callback,
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
            "/Admin/CreateActionsOnPlayersInSegmentTask",
            headers,
            jsonAsString,
            OnCreateActionsOnPlayersInSegmentTaskResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<CreateTaskResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabAdminAPI::OnCreateActionsOnPlayersInSegmentTaskResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        CreateTaskResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<CreateTaskResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabAdminAPI::CreateCloudScriptTask(
        CreateCloudScriptTaskRequest& request,
        ProcessApiCallback<CreateTaskResult> callback,
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
            "/Admin/CreateCloudScriptTask",
            headers,
            jsonAsString,
            OnCreateCloudScriptTaskResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<CreateTaskResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabAdminAPI::OnCreateCloudScriptTaskResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        CreateTaskResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<CreateTaskResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabAdminAPI::CreatePlayerSharedSecret(
        CreatePlayerSharedSecretRequest& request,
        ProcessApiCallback<CreatePlayerSharedSecretResult> callback,
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
            "/Admin/CreatePlayerSharedSecret",
            headers,
            jsonAsString,
            OnCreatePlayerSharedSecretResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<CreatePlayerSharedSecretResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabAdminAPI::OnCreatePlayerSharedSecretResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        CreatePlayerSharedSecretResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<CreatePlayerSharedSecretResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabAdminAPI::CreatePlayerStatisticDefinition(
        CreatePlayerStatisticDefinitionRequest& request,
        ProcessApiCallback<CreatePlayerStatisticDefinitionResult> callback,
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
            "/Admin/CreatePlayerStatisticDefinition",
            headers,
            jsonAsString,
            OnCreatePlayerStatisticDefinitionResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<CreatePlayerStatisticDefinitionResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabAdminAPI::OnCreatePlayerStatisticDefinitionResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        CreatePlayerStatisticDefinitionResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<CreatePlayerStatisticDefinitionResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabAdminAPI::DeleteContent(
        DeleteContentRequest& request,
        ProcessApiCallback<BlankResult> callback,
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
            "/Admin/DeleteContent",
            headers,
            jsonAsString,
            OnDeleteContentResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<BlankResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabAdminAPI::OnDeleteContentResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        BlankResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<BlankResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabAdminAPI::DeleteMasterPlayerAccount(
        DeleteMasterPlayerAccountRequest& request,
        ProcessApiCallback<DeleteMasterPlayerAccountResult> callback,
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
            "/Admin/DeleteMasterPlayerAccount",
            headers,
            jsonAsString,
            OnDeleteMasterPlayerAccountResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<DeleteMasterPlayerAccountResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabAdminAPI::OnDeleteMasterPlayerAccountResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        DeleteMasterPlayerAccountResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<DeleteMasterPlayerAccountResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabAdminAPI::DeletePlayer(
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
            "/Admin/DeletePlayer",
            headers,
            jsonAsString,
            OnDeletePlayerResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<DeletePlayerResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabAdminAPI::OnDeletePlayerResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
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

    void PlayFabAdminAPI::DeletePlayerSharedSecret(
        DeletePlayerSharedSecretRequest& request,
        ProcessApiCallback<DeletePlayerSharedSecretResult> callback,
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
            "/Admin/DeletePlayerSharedSecret",
            headers,
            jsonAsString,
            OnDeletePlayerSharedSecretResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<DeletePlayerSharedSecretResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabAdminAPI::OnDeletePlayerSharedSecretResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        DeletePlayerSharedSecretResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<DeletePlayerSharedSecretResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabAdminAPI::DeleteStore(
        DeleteStoreRequest& request,
        ProcessApiCallback<DeleteStoreResult> callback,
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
            "/Admin/DeleteStore",
            headers,
            jsonAsString,
            OnDeleteStoreResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<DeleteStoreResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabAdminAPI::OnDeleteStoreResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        DeleteStoreResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<DeleteStoreResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabAdminAPI::DeleteTask(
        DeleteTaskRequest& request,
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
            "/Admin/DeleteTask",
            headers,
            jsonAsString,
            OnDeleteTaskResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<EmptyResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabAdminAPI::OnDeleteTaskResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
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

    void PlayFabAdminAPI::DeleteTitle(
        DeleteTitleRequest& request,
        ProcessApiCallback<DeleteTitleResult> callback,
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
            "/Admin/DeleteTitle",
            headers,
            jsonAsString,
            OnDeleteTitleResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<DeleteTitleResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabAdminAPI::OnDeleteTitleResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        DeleteTitleResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<DeleteTitleResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabAdminAPI::ExportMasterPlayerData(
        ExportMasterPlayerDataRequest& request,
        ProcessApiCallback<ExportMasterPlayerDataResult> callback,
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
            "/Admin/ExportMasterPlayerData",
            headers,
            jsonAsString,
            OnExportMasterPlayerDataResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<ExportMasterPlayerDataResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabAdminAPI::OnExportMasterPlayerDataResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        ExportMasterPlayerDataResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<ExportMasterPlayerDataResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabAdminAPI::GetActionsOnPlayersInSegmentTaskInstance(
        GetTaskInstanceRequest& request,
        ProcessApiCallback<GetActionsOnPlayersInSegmentTaskInstanceResult> callback,
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
            "/Admin/GetActionsOnPlayersInSegmentTaskInstance",
            headers,
            jsonAsString,
            OnGetActionsOnPlayersInSegmentTaskInstanceResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetActionsOnPlayersInSegmentTaskInstanceResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabAdminAPI::OnGetActionsOnPlayersInSegmentTaskInstanceResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        GetActionsOnPlayersInSegmentTaskInstanceResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<GetActionsOnPlayersInSegmentTaskInstanceResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabAdminAPI::GetAllSegments(
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
            "/Admin/GetAllSegments",
            headers,
            jsonAsString,
            OnGetAllSegmentsResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetAllSegmentsResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabAdminAPI::OnGetAllSegmentsResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
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

    void PlayFabAdminAPI::GetCatalogItems(
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
            "/Admin/GetCatalogItems",
            headers,
            jsonAsString,
            OnGetCatalogItemsResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetCatalogItemsResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabAdminAPI::OnGetCatalogItemsResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
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

    void PlayFabAdminAPI::GetCloudScriptRevision(
        GetCloudScriptRevisionRequest& request,
        ProcessApiCallback<GetCloudScriptRevisionResult> callback,
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
            "/Admin/GetCloudScriptRevision",
            headers,
            jsonAsString,
            OnGetCloudScriptRevisionResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetCloudScriptRevisionResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabAdminAPI::OnGetCloudScriptRevisionResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        GetCloudScriptRevisionResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<GetCloudScriptRevisionResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabAdminAPI::GetCloudScriptTaskInstance(
        GetTaskInstanceRequest& request,
        ProcessApiCallback<GetCloudScriptTaskInstanceResult> callback,
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
            "/Admin/GetCloudScriptTaskInstance",
            headers,
            jsonAsString,
            OnGetCloudScriptTaskInstanceResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetCloudScriptTaskInstanceResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabAdminAPI::OnGetCloudScriptTaskInstanceResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        GetCloudScriptTaskInstanceResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<GetCloudScriptTaskInstanceResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabAdminAPI::GetCloudScriptVersions(
        GetCloudScriptVersionsRequest& request,
        ProcessApiCallback<GetCloudScriptVersionsResult> callback,
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
            "/Admin/GetCloudScriptVersions",
            headers,
            jsonAsString,
            OnGetCloudScriptVersionsResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetCloudScriptVersionsResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabAdminAPI::OnGetCloudScriptVersionsResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        GetCloudScriptVersionsResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<GetCloudScriptVersionsResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabAdminAPI::GetContentList(
        GetContentListRequest& request,
        ProcessApiCallback<GetContentListResult> callback,
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
            "/Admin/GetContentList",
            headers,
            jsonAsString,
            OnGetContentListResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetContentListResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabAdminAPI::OnGetContentListResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        GetContentListResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<GetContentListResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabAdminAPI::GetContentUploadUrl(
        GetContentUploadUrlRequest& request,
        ProcessApiCallback<GetContentUploadUrlResult> callback,
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
            "/Admin/GetContentUploadUrl",
            headers,
            jsonAsString,
            OnGetContentUploadUrlResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetContentUploadUrlResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabAdminAPI::OnGetContentUploadUrlResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        GetContentUploadUrlResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<GetContentUploadUrlResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabAdminAPI::GetDataReport(
        GetDataReportRequest& request,
        ProcessApiCallback<GetDataReportResult> callback,
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
            "/Admin/GetDataReport",
            headers,
            jsonAsString,
            OnGetDataReportResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetDataReportResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabAdminAPI::OnGetDataReportResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        GetDataReportResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<GetDataReportResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabAdminAPI::GetMatchmakerGameInfo(
        GetMatchmakerGameInfoRequest& request,
        ProcessApiCallback<GetMatchmakerGameInfoResult> callback,
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
            "/Admin/GetMatchmakerGameInfo",
            headers,
            jsonAsString,
            OnGetMatchmakerGameInfoResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetMatchmakerGameInfoResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabAdminAPI::OnGetMatchmakerGameInfoResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        GetMatchmakerGameInfoResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<GetMatchmakerGameInfoResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabAdminAPI::GetMatchmakerGameModes(
        GetMatchmakerGameModesRequest& request,
        ProcessApiCallback<GetMatchmakerGameModesResult> callback,
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
            "/Admin/GetMatchmakerGameModes",
            headers,
            jsonAsString,
            OnGetMatchmakerGameModesResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetMatchmakerGameModesResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabAdminAPI::OnGetMatchmakerGameModesResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        GetMatchmakerGameModesResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<GetMatchmakerGameModesResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabAdminAPI::GetPlayedTitleList(
        GetPlayedTitleListRequest& request,
        ProcessApiCallback<GetPlayedTitleListResult> callback,
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
            "/Admin/GetPlayedTitleList",
            headers,
            jsonAsString,
            OnGetPlayedTitleListResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetPlayedTitleListResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabAdminAPI::OnGetPlayedTitleListResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        GetPlayedTitleListResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<GetPlayedTitleListResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabAdminAPI::GetPlayerIdFromAuthToken(
        GetPlayerIdFromAuthTokenRequest& request,
        ProcessApiCallback<GetPlayerIdFromAuthTokenResult> callback,
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
            "/Admin/GetPlayerIdFromAuthToken",
            headers,
            jsonAsString,
            OnGetPlayerIdFromAuthTokenResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetPlayerIdFromAuthTokenResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabAdminAPI::OnGetPlayerIdFromAuthTokenResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        GetPlayerIdFromAuthTokenResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<GetPlayerIdFromAuthTokenResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabAdminAPI::GetPlayerProfile(
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
            "/Admin/GetPlayerProfile",
            headers,
            jsonAsString,
            OnGetPlayerProfileResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetPlayerProfileResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabAdminAPI::OnGetPlayerProfileResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
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

    void PlayFabAdminAPI::GetPlayerSegments(
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
            "/Admin/GetPlayerSegments",
            headers,
            jsonAsString,
            OnGetPlayerSegmentsResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetPlayerSegmentsResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabAdminAPI::OnGetPlayerSegmentsResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
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

    void PlayFabAdminAPI::GetPlayerSharedSecrets(
        GetPlayerSharedSecretsRequest& request,
        ProcessApiCallback<GetPlayerSharedSecretsResult> callback,
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
            "/Admin/GetPlayerSharedSecrets",
            headers,
            jsonAsString,
            OnGetPlayerSharedSecretsResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetPlayerSharedSecretsResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabAdminAPI::OnGetPlayerSharedSecretsResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        GetPlayerSharedSecretsResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<GetPlayerSharedSecretsResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabAdminAPI::GetPlayersInSegment(
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
            "/Admin/GetPlayersInSegment",
            headers,
            jsonAsString,
            OnGetPlayersInSegmentResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetPlayersInSegmentResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabAdminAPI::OnGetPlayersInSegmentResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
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

    void PlayFabAdminAPI::GetPlayerStatisticDefinitions(
        GetPlayerStatisticDefinitionsRequest& request,
        ProcessApiCallback<GetPlayerStatisticDefinitionsResult> callback,
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
            "/Admin/GetPlayerStatisticDefinitions",
            headers,
            jsonAsString,
            OnGetPlayerStatisticDefinitionsResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetPlayerStatisticDefinitionsResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabAdminAPI::OnGetPlayerStatisticDefinitionsResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        GetPlayerStatisticDefinitionsResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<GetPlayerStatisticDefinitionsResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabAdminAPI::GetPlayerStatisticVersions(
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
            "/Admin/GetPlayerStatisticVersions",
            headers,
            jsonAsString,
            OnGetPlayerStatisticVersionsResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetPlayerStatisticVersionsResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabAdminAPI::OnGetPlayerStatisticVersionsResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
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

    void PlayFabAdminAPI::GetPlayerTags(
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
            "/Admin/GetPlayerTags",
            headers,
            jsonAsString,
            OnGetPlayerTagsResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetPlayerTagsResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabAdminAPI::OnGetPlayerTagsResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
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

    void PlayFabAdminAPI::GetPolicy(
        GetPolicyRequest& request,
        ProcessApiCallback<GetPolicyResponse> callback,
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
            "/Admin/GetPolicy",
            headers,
            jsonAsString,
            OnGetPolicyResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetPolicyResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabAdminAPI::OnGetPolicyResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        GetPolicyResponse outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<GetPolicyResponse> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabAdminAPI::GetPublisherData(
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
            "/Admin/GetPublisherData",
            headers,
            jsonAsString,
            OnGetPublisherDataResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetPublisherDataResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabAdminAPI::OnGetPublisherDataResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
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

    void PlayFabAdminAPI::GetRandomResultTables(
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
            "/Admin/GetRandomResultTables",
            headers,
            jsonAsString,
            OnGetRandomResultTablesResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetRandomResultTablesResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabAdminAPI::OnGetRandomResultTablesResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
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

    void PlayFabAdminAPI::GetServerBuildInfo(
        GetServerBuildInfoRequest& request,
        ProcessApiCallback<GetServerBuildInfoResult> callback,
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
            "/Admin/GetServerBuildInfo",
            headers,
            jsonAsString,
            OnGetServerBuildInfoResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetServerBuildInfoResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabAdminAPI::OnGetServerBuildInfoResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        GetServerBuildInfoResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<GetServerBuildInfoResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabAdminAPI::GetServerBuildUploadUrl(
        GetServerBuildUploadURLRequest& request,
        ProcessApiCallback<GetServerBuildUploadURLResult> callback,
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
            "/Admin/GetServerBuildUploadUrl",
            headers,
            jsonAsString,
            OnGetServerBuildUploadUrlResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetServerBuildUploadURLResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabAdminAPI::OnGetServerBuildUploadUrlResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        GetServerBuildUploadURLResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<GetServerBuildUploadURLResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabAdminAPI::GetStoreItems(
        GetStoreItemsRequest& request,
        ProcessApiCallback<GetStoreItemsResult> callback,
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
            "/Admin/GetStoreItems",
            headers,
            jsonAsString,
            OnGetStoreItemsResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetStoreItemsResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabAdminAPI::OnGetStoreItemsResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        GetStoreItemsResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<GetStoreItemsResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabAdminAPI::GetTaskInstances(
        GetTaskInstancesRequest& request,
        ProcessApiCallback<GetTaskInstancesResult> callback,
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
            "/Admin/GetTaskInstances",
            headers,
            jsonAsString,
            OnGetTaskInstancesResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetTaskInstancesResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabAdminAPI::OnGetTaskInstancesResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        GetTaskInstancesResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<GetTaskInstancesResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabAdminAPI::GetTasks(
        GetTasksRequest& request,
        ProcessApiCallback<GetTasksResult> callback,
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
            "/Admin/GetTasks",
            headers,
            jsonAsString,
            OnGetTasksResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetTasksResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabAdminAPI::OnGetTasksResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        GetTasksResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<GetTasksResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabAdminAPI::GetTitleData(
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
            "/Admin/GetTitleData",
            headers,
            jsonAsString,
            OnGetTitleDataResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetTitleDataResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabAdminAPI::OnGetTitleDataResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
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

    void PlayFabAdminAPI::GetTitleInternalData(
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
            "/Admin/GetTitleInternalData",
            headers,
            jsonAsString,
            OnGetTitleInternalDataResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetTitleDataResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabAdminAPI::OnGetTitleInternalDataResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
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

    void PlayFabAdminAPI::GetUserAccountInfo(
        LookupUserAccountInfoRequest& request,
        ProcessApiCallback<LookupUserAccountInfoResult> callback,
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
            "/Admin/GetUserAccountInfo",
            headers,
            jsonAsString,
            OnGetUserAccountInfoResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<LookupUserAccountInfoResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabAdminAPI::OnGetUserAccountInfoResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        LookupUserAccountInfoResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<LookupUserAccountInfoResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabAdminAPI::GetUserBans(
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
            "/Admin/GetUserBans",
            headers,
            jsonAsString,
            OnGetUserBansResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetUserBansResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabAdminAPI::OnGetUserBansResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
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

    void PlayFabAdminAPI::GetUserData(
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
            "/Admin/GetUserData",
            headers,
            jsonAsString,
            OnGetUserDataResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetUserDataResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabAdminAPI::OnGetUserDataResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
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

    void PlayFabAdminAPI::GetUserInternalData(
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
            "/Admin/GetUserInternalData",
            headers,
            jsonAsString,
            OnGetUserInternalDataResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetUserDataResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabAdminAPI::OnGetUserInternalDataResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
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

    void PlayFabAdminAPI::GetUserInventory(
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
            "/Admin/GetUserInventory",
            headers,
            jsonAsString,
            OnGetUserInventoryResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetUserInventoryResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabAdminAPI::OnGetUserInventoryResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
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

    void PlayFabAdminAPI::GetUserPublisherData(
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
            "/Admin/GetUserPublisherData",
            headers,
            jsonAsString,
            OnGetUserPublisherDataResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetUserDataResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabAdminAPI::OnGetUserPublisherDataResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
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

    void PlayFabAdminAPI::GetUserPublisherInternalData(
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
            "/Admin/GetUserPublisherInternalData",
            headers,
            jsonAsString,
            OnGetUserPublisherInternalDataResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetUserDataResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabAdminAPI::OnGetUserPublisherInternalDataResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
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

    void PlayFabAdminAPI::GetUserPublisherReadOnlyData(
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
            "/Admin/GetUserPublisherReadOnlyData",
            headers,
            jsonAsString,
            OnGetUserPublisherReadOnlyDataResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetUserDataResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabAdminAPI::OnGetUserPublisherReadOnlyDataResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
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

    void PlayFabAdminAPI::GetUserReadOnlyData(
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
            "/Admin/GetUserReadOnlyData",
            headers,
            jsonAsString,
            OnGetUserReadOnlyDataResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetUserDataResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabAdminAPI::OnGetUserReadOnlyDataResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
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

    void PlayFabAdminAPI::GrantItemsToUsers(
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
            "/Admin/GrantItemsToUsers",
            headers,
            jsonAsString,
            OnGrantItemsToUsersResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GrantItemsToUsersResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabAdminAPI::OnGrantItemsToUsersResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
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

    void PlayFabAdminAPI::IncrementLimitedEditionItemAvailability(
        IncrementLimitedEditionItemAvailabilityRequest& request,
        ProcessApiCallback<IncrementLimitedEditionItemAvailabilityResult> callback,
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
            "/Admin/IncrementLimitedEditionItemAvailability",
            headers,
            jsonAsString,
            OnIncrementLimitedEditionItemAvailabilityResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<IncrementLimitedEditionItemAvailabilityResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabAdminAPI::OnIncrementLimitedEditionItemAvailabilityResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        IncrementLimitedEditionItemAvailabilityResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<IncrementLimitedEditionItemAvailabilityResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabAdminAPI::IncrementPlayerStatisticVersion(
        IncrementPlayerStatisticVersionRequest& request,
        ProcessApiCallback<IncrementPlayerStatisticVersionResult> callback,
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
            "/Admin/IncrementPlayerStatisticVersion",
            headers,
            jsonAsString,
            OnIncrementPlayerStatisticVersionResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<IncrementPlayerStatisticVersionResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabAdminAPI::OnIncrementPlayerStatisticVersionResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        IncrementPlayerStatisticVersionResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<IncrementPlayerStatisticVersionResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabAdminAPI::ListServerBuilds(
        ListBuildsRequest& request,
        ProcessApiCallback<ListBuildsResult> callback,
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
            "/Admin/ListServerBuilds",
            headers,
            jsonAsString,
            OnListServerBuildsResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<ListBuildsResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabAdminAPI::OnListServerBuildsResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        ListBuildsResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<ListBuildsResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabAdminAPI::ListVirtualCurrencyTypes(
        ListVirtualCurrencyTypesRequest& request,
        ProcessApiCallback<ListVirtualCurrencyTypesResult> callback,
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
            "/Admin/ListVirtualCurrencyTypes",
            headers,
            jsonAsString,
            OnListVirtualCurrencyTypesResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<ListVirtualCurrencyTypesResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabAdminAPI::OnListVirtualCurrencyTypesResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        ListVirtualCurrencyTypesResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<ListVirtualCurrencyTypesResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabAdminAPI::ModifyMatchmakerGameModes(
        ModifyMatchmakerGameModesRequest& request,
        ProcessApiCallback<ModifyMatchmakerGameModesResult> callback,
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
            "/Admin/ModifyMatchmakerGameModes",
            headers,
            jsonAsString,
            OnModifyMatchmakerGameModesResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<ModifyMatchmakerGameModesResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabAdminAPI::OnModifyMatchmakerGameModesResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        ModifyMatchmakerGameModesResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<ModifyMatchmakerGameModesResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabAdminAPI::ModifyServerBuild(
        ModifyServerBuildRequest& request,
        ProcessApiCallback<ModifyServerBuildResult> callback,
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
            "/Admin/ModifyServerBuild",
            headers,
            jsonAsString,
            OnModifyServerBuildResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<ModifyServerBuildResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabAdminAPI::OnModifyServerBuildResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        ModifyServerBuildResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<ModifyServerBuildResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabAdminAPI::RefundPurchase(
        RefundPurchaseRequest& request,
        ProcessApiCallback<RefundPurchaseResponse> callback,
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
            "/Admin/RefundPurchase",
            headers,
            jsonAsString,
            OnRefundPurchaseResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<RefundPurchaseResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabAdminAPI::OnRefundPurchaseResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        RefundPurchaseResponse outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<RefundPurchaseResponse> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabAdminAPI::RemovePlayerTag(
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
            "/Admin/RemovePlayerTag",
            headers,
            jsonAsString,
            OnRemovePlayerTagResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<RemovePlayerTagResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabAdminAPI::OnRemovePlayerTagResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
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

    void PlayFabAdminAPI::RemoveServerBuild(
        RemoveServerBuildRequest& request,
        ProcessApiCallback<RemoveServerBuildResult> callback,
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
            "/Admin/RemoveServerBuild",
            headers,
            jsonAsString,
            OnRemoveServerBuildResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<RemoveServerBuildResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabAdminAPI::OnRemoveServerBuildResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        RemoveServerBuildResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<RemoveServerBuildResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabAdminAPI::RemoveVirtualCurrencyTypes(
        RemoveVirtualCurrencyTypesRequest& request,
        ProcessApiCallback<BlankResult> callback,
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
            "/Admin/RemoveVirtualCurrencyTypes",
            headers,
            jsonAsString,
            OnRemoveVirtualCurrencyTypesResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<BlankResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabAdminAPI::OnRemoveVirtualCurrencyTypesResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        BlankResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<BlankResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabAdminAPI::ResetCharacterStatistics(
        ResetCharacterStatisticsRequest& request,
        ProcessApiCallback<ResetCharacterStatisticsResult> callback,
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
            "/Admin/ResetCharacterStatistics",
            headers,
            jsonAsString,
            OnResetCharacterStatisticsResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<ResetCharacterStatisticsResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabAdminAPI::OnResetCharacterStatisticsResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        ResetCharacterStatisticsResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<ResetCharacterStatisticsResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabAdminAPI::ResetPassword(
        ResetPasswordRequest& request,
        ProcessApiCallback<ResetPasswordResult> callback,
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
            "/Admin/ResetPassword",
            headers,
            jsonAsString,
            OnResetPasswordResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<ResetPasswordResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabAdminAPI::OnResetPasswordResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        ResetPasswordResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<ResetPasswordResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabAdminAPI::ResetUserStatistics(
        ResetUserStatisticsRequest& request,
        ProcessApiCallback<ResetUserStatisticsResult> callback,
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
            "/Admin/ResetUserStatistics",
            headers,
            jsonAsString,
            OnResetUserStatisticsResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<ResetUserStatisticsResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabAdminAPI::OnResetUserStatisticsResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        ResetUserStatisticsResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<ResetUserStatisticsResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabAdminAPI::ResolvePurchaseDispute(
        ResolvePurchaseDisputeRequest& request,
        ProcessApiCallback<ResolvePurchaseDisputeResponse> callback,
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
            "/Admin/ResolvePurchaseDispute",
            headers,
            jsonAsString,
            OnResolvePurchaseDisputeResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<ResolvePurchaseDisputeResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabAdminAPI::OnResolvePurchaseDisputeResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        ResolvePurchaseDisputeResponse outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<ResolvePurchaseDisputeResponse> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabAdminAPI::RevokeAllBansForUser(
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
            "/Admin/RevokeAllBansForUser",
            headers,
            jsonAsString,
            OnRevokeAllBansForUserResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<RevokeAllBansForUserResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabAdminAPI::OnRevokeAllBansForUserResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
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

    void PlayFabAdminAPI::RevokeBans(
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
            "/Admin/RevokeBans",
            headers,
            jsonAsString,
            OnRevokeBansResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<RevokeBansResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabAdminAPI::OnRevokeBansResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
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

    void PlayFabAdminAPI::RevokeInventoryItem(
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
            "/Admin/RevokeInventoryItem",
            headers,
            jsonAsString,
            OnRevokeInventoryItemResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<RevokeInventoryResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabAdminAPI::OnRevokeInventoryItemResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
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

    void PlayFabAdminAPI::RevokeInventoryItems(
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
            "/Admin/RevokeInventoryItems",
            headers,
            jsonAsString,
            OnRevokeInventoryItemsResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<RevokeInventoryItemsResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabAdminAPI::OnRevokeInventoryItemsResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
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

    void PlayFabAdminAPI::RunTask(
        RunTaskRequest& request,
        ProcessApiCallback<RunTaskResult> callback,
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
            "/Admin/RunTask",
            headers,
            jsonAsString,
            OnRunTaskResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<RunTaskResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabAdminAPI::OnRunTaskResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        RunTaskResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<RunTaskResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabAdminAPI::SendAccountRecoveryEmail(
        SendAccountRecoveryEmailRequest& request,
        ProcessApiCallback<SendAccountRecoveryEmailResult> callback,
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
            "/Admin/SendAccountRecoveryEmail",
            headers,
            jsonAsString,
            OnSendAccountRecoveryEmailResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<SendAccountRecoveryEmailResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabAdminAPI::OnSendAccountRecoveryEmailResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        SendAccountRecoveryEmailResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<SendAccountRecoveryEmailResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabAdminAPI::SetCatalogItems(
        UpdateCatalogItemsRequest& request,
        ProcessApiCallback<UpdateCatalogItemsResult> callback,
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
            "/Admin/SetCatalogItems",
            headers,
            jsonAsString,
            OnSetCatalogItemsResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<UpdateCatalogItemsResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabAdminAPI::OnSetCatalogItemsResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        UpdateCatalogItemsResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<UpdateCatalogItemsResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabAdminAPI::SetPlayerSecret(
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
            "/Admin/SetPlayerSecret",
            headers,
            jsonAsString,
            OnSetPlayerSecretResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<SetPlayerSecretResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabAdminAPI::OnSetPlayerSecretResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
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

    void PlayFabAdminAPI::SetPublishedRevision(
        SetPublishedRevisionRequest& request,
        ProcessApiCallback<SetPublishedRevisionResult> callback,
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
            "/Admin/SetPublishedRevision",
            headers,
            jsonAsString,
            OnSetPublishedRevisionResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<SetPublishedRevisionResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabAdminAPI::OnSetPublishedRevisionResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        SetPublishedRevisionResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<SetPublishedRevisionResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabAdminAPI::SetPublisherData(
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
            "/Admin/SetPublisherData",
            headers,
            jsonAsString,
            OnSetPublisherDataResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<SetPublisherDataResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabAdminAPI::OnSetPublisherDataResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
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

    void PlayFabAdminAPI::SetStoreItems(
        UpdateStoreItemsRequest& request,
        ProcessApiCallback<UpdateStoreItemsResult> callback,
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
            "/Admin/SetStoreItems",
            headers,
            jsonAsString,
            OnSetStoreItemsResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<UpdateStoreItemsResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabAdminAPI::OnSetStoreItemsResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        UpdateStoreItemsResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<UpdateStoreItemsResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabAdminAPI::SetTitleData(
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
            "/Admin/SetTitleData",
            headers,
            jsonAsString,
            OnSetTitleDataResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<SetTitleDataResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabAdminAPI::OnSetTitleDataResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
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

    void PlayFabAdminAPI::SetTitleInternalData(
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
            "/Admin/SetTitleInternalData",
            headers,
            jsonAsString,
            OnSetTitleInternalDataResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<SetTitleDataResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabAdminAPI::OnSetTitleInternalDataResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
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

    void PlayFabAdminAPI::SetupPushNotification(
        SetupPushNotificationRequest& request,
        ProcessApiCallback<SetupPushNotificationResult> callback,
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
            "/Admin/SetupPushNotification",
            headers,
            jsonAsString,
            OnSetupPushNotificationResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<SetupPushNotificationResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabAdminAPI::OnSetupPushNotificationResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        SetupPushNotificationResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<SetupPushNotificationResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabAdminAPI::SubtractUserVirtualCurrency(
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
            "/Admin/SubtractUserVirtualCurrency",
            headers,
            jsonAsString,
            OnSubtractUserVirtualCurrencyResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<ModifyUserVirtualCurrencyResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabAdminAPI::OnSubtractUserVirtualCurrencyResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
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

    void PlayFabAdminAPI::UpdateBans(
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
            "/Admin/UpdateBans",
            headers,
            jsonAsString,
            OnUpdateBansResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<UpdateBansResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabAdminAPI::OnUpdateBansResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
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

    void PlayFabAdminAPI::UpdateCatalogItems(
        UpdateCatalogItemsRequest& request,
        ProcessApiCallback<UpdateCatalogItemsResult> callback,
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
            "/Admin/UpdateCatalogItems",
            headers,
            jsonAsString,
            OnUpdateCatalogItemsResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<UpdateCatalogItemsResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabAdminAPI::OnUpdateCatalogItemsResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        UpdateCatalogItemsResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<UpdateCatalogItemsResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabAdminAPI::UpdateCloudScript(
        UpdateCloudScriptRequest& request,
        ProcessApiCallback<UpdateCloudScriptResult> callback,
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
            "/Admin/UpdateCloudScript",
            headers,
            jsonAsString,
            OnUpdateCloudScriptResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<UpdateCloudScriptResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabAdminAPI::OnUpdateCloudScriptResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        UpdateCloudScriptResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<UpdateCloudScriptResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabAdminAPI::UpdatePlayerSharedSecret(
        UpdatePlayerSharedSecretRequest& request,
        ProcessApiCallback<UpdatePlayerSharedSecretResult> callback,
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
            "/Admin/UpdatePlayerSharedSecret",
            headers,
            jsonAsString,
            OnUpdatePlayerSharedSecretResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<UpdatePlayerSharedSecretResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabAdminAPI::OnUpdatePlayerSharedSecretResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        UpdatePlayerSharedSecretResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<UpdatePlayerSharedSecretResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabAdminAPI::UpdatePlayerStatisticDefinition(
        UpdatePlayerStatisticDefinitionRequest& request,
        ProcessApiCallback<UpdatePlayerStatisticDefinitionResult> callback,
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
            "/Admin/UpdatePlayerStatisticDefinition",
            headers,
            jsonAsString,
            OnUpdatePlayerStatisticDefinitionResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<UpdatePlayerStatisticDefinitionResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabAdminAPI::OnUpdatePlayerStatisticDefinitionResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        UpdatePlayerStatisticDefinitionResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<UpdatePlayerStatisticDefinitionResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabAdminAPI::UpdatePolicy(
        UpdatePolicyRequest& request,
        ProcessApiCallback<UpdatePolicyResponse> callback,
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
            "/Admin/UpdatePolicy",
            headers,
            jsonAsString,
            OnUpdatePolicyResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<UpdatePolicyResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabAdminAPI::OnUpdatePolicyResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        UpdatePolicyResponse outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<UpdatePolicyResponse> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabAdminAPI::UpdateRandomResultTables(
        UpdateRandomResultTablesRequest& request,
        ProcessApiCallback<UpdateRandomResultTablesResult> callback,
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
            "/Admin/UpdateRandomResultTables",
            headers,
            jsonAsString,
            OnUpdateRandomResultTablesResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<UpdateRandomResultTablesResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabAdminAPI::OnUpdateRandomResultTablesResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        UpdateRandomResultTablesResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<UpdateRandomResultTablesResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabAdminAPI::UpdateStoreItems(
        UpdateStoreItemsRequest& request,
        ProcessApiCallback<UpdateStoreItemsResult> callback,
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
            "/Admin/UpdateStoreItems",
            headers,
            jsonAsString,
            OnUpdateStoreItemsResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<UpdateStoreItemsResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabAdminAPI::OnUpdateStoreItemsResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        UpdateStoreItemsResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<UpdateStoreItemsResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabAdminAPI::UpdateTask(
        UpdateTaskRequest& request,
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
            "/Admin/UpdateTask",
            headers,
            jsonAsString,
            OnUpdateTaskResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<EmptyResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabAdminAPI::OnUpdateTaskResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
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

    void PlayFabAdminAPI::UpdateUserData(
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
            "/Admin/UpdateUserData",
            headers,
            jsonAsString,
            OnUpdateUserDataResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<UpdateUserDataResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabAdminAPI::OnUpdateUserDataResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
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

    void PlayFabAdminAPI::UpdateUserInternalData(
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
            "/Admin/UpdateUserInternalData",
            headers,
            jsonAsString,
            OnUpdateUserInternalDataResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<UpdateUserDataResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabAdminAPI::OnUpdateUserInternalDataResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
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

    void PlayFabAdminAPI::UpdateUserPublisherData(
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
            "/Admin/UpdateUserPublisherData",
            headers,
            jsonAsString,
            OnUpdateUserPublisherDataResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<UpdateUserDataResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabAdminAPI::OnUpdateUserPublisherDataResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
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

    void PlayFabAdminAPI::UpdateUserPublisherInternalData(
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
            "/Admin/UpdateUserPublisherInternalData",
            headers,
            jsonAsString,
            OnUpdateUserPublisherInternalDataResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<UpdateUserDataResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabAdminAPI::OnUpdateUserPublisherInternalDataResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
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

    void PlayFabAdminAPI::UpdateUserPublisherReadOnlyData(
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
            "/Admin/UpdateUserPublisherReadOnlyData",
            headers,
            jsonAsString,
            OnUpdateUserPublisherReadOnlyDataResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<UpdateUserDataResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabAdminAPI::OnUpdateUserPublisherReadOnlyDataResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
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

    void PlayFabAdminAPI::UpdateUserReadOnlyData(
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
            "/Admin/UpdateUserReadOnlyData",
            headers,
            jsonAsString,
            OnUpdateUserReadOnlyDataResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<UpdateUserDataResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabAdminAPI::OnUpdateUserReadOnlyDataResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
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

    void PlayFabAdminAPI::UpdateUserTitleDisplayName(
        UpdateUserTitleDisplayNameRequest& request,
        ProcessApiCallback<UpdateUserTitleDisplayNameResult> callback,
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
            "/Admin/UpdateUserTitleDisplayName",
            headers,
            jsonAsString,
            OnUpdateUserTitleDisplayNameResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<UpdateUserTitleDisplayNameResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabAdminAPI::OnUpdateUserTitleDisplayNameResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        UpdateUserTitleDisplayNameResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<UpdateUserTitleDisplayNameResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    bool PlayFabAdminAPI::ValidateResult(PlayFabResultCommon& resultCommon, CallRequestContainer& container)
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
