#include <stdafx.h>

#ifndef DISABLE_PLAYFABCLIENT_API

#include <playfab/PlayFabClientApi.h>
#include <playfab/PlayFabHttp.h>
#include <playfab/PlayFabSettings.h>
#include <playfab/PlayFabError.h>

#pragma warning (disable: 4100) // formal parameters are part of a public interface

namespace PlayFab
{
    using namespace ClientModels;

    size_t PlayFabClientAPI::Update()
    {
        return PlayFabHttp::Get().Update();
    }

    void PlayFabClientAPI::ForgetAllCredentials()
    {
        return PlayFabSettings::ForgetAllCredentials();
    }

    // PlayFabClient APIs

    void PlayFabClientAPI::AcceptTrade(
        AcceptTradeRequest& request,
        ProcessApiCallback<AcceptTradeResponse> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();

        Json::FastWriter writer;
        std::string jsonAsString = writer.write(requestJson);

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-Authorization", PlayFabSettings::clientSessionTicket);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Client/AcceptTrade",
            headers,
            jsonAsString,
            OnAcceptTradeResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<AcceptTradeResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabClientAPI::OnAcceptTradeResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        AcceptTradeResponse outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<AcceptTradeResponse> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabClientAPI::AddFriend(
        AddFriendRequest& request,
        ProcessApiCallback<AddFriendResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();

        Json::FastWriter writer;
        std::string jsonAsString = writer.write(requestJson);

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-Authorization", PlayFabSettings::clientSessionTicket);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Client/AddFriend",
            headers,
            jsonAsString,
            OnAddFriendResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<AddFriendResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabClientAPI::OnAddFriendResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        AddFriendResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<AddFriendResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabClientAPI::AddGenericID(
        AddGenericIDRequest& request,
        ProcessApiCallback<AddGenericIDResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();

        Json::FastWriter writer;
        std::string jsonAsString = writer.write(requestJson);

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-Authorization", PlayFabSettings::clientSessionTicket);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Client/AddGenericID",
            headers,
            jsonAsString,
            OnAddGenericIDResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<AddGenericIDResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabClientAPI::OnAddGenericIDResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        AddGenericIDResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<AddGenericIDResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabClientAPI::AddOrUpdateContactEmail(
        AddOrUpdateContactEmailRequest& request,
        ProcessApiCallback<AddOrUpdateContactEmailResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();

        Json::FastWriter writer;
        std::string jsonAsString = writer.write(requestJson);

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-Authorization", PlayFabSettings::clientSessionTicket);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Client/AddOrUpdateContactEmail",
            headers,
            jsonAsString,
            OnAddOrUpdateContactEmailResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<AddOrUpdateContactEmailResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabClientAPI::OnAddOrUpdateContactEmailResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        AddOrUpdateContactEmailResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<AddOrUpdateContactEmailResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabClientAPI::AddSharedGroupMembers(
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
        headers.emplace("X-Authorization", PlayFabSettings::clientSessionTicket);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Client/AddSharedGroupMembers",
            headers,
            jsonAsString,
            OnAddSharedGroupMembersResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<AddSharedGroupMembersResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabClientAPI::OnAddSharedGroupMembersResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
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

    void PlayFabClientAPI::AddUsernamePassword(
        AddUsernamePasswordRequest& request,
        ProcessApiCallback<AddUsernamePasswordResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();

        Json::FastWriter writer;
        std::string jsonAsString = writer.write(requestJson);

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-Authorization", PlayFabSettings::clientSessionTicket);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Client/AddUsernamePassword",
            headers,
            jsonAsString,
            OnAddUsernamePasswordResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<AddUsernamePasswordResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabClientAPI::OnAddUsernamePasswordResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        AddUsernamePasswordResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<AddUsernamePasswordResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabClientAPI::AddUserVirtualCurrency(
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
        headers.emplace("X-Authorization", PlayFabSettings::clientSessionTicket);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Client/AddUserVirtualCurrency",
            headers,
            jsonAsString,
            OnAddUserVirtualCurrencyResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<ModifyUserVirtualCurrencyResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabClientAPI::OnAddUserVirtualCurrencyResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
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

    void PlayFabClientAPI::AndroidDevicePushNotificationRegistration(
        AndroidDevicePushNotificationRegistrationRequest& request,
        ProcessApiCallback<AndroidDevicePushNotificationRegistrationResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();

        Json::FastWriter writer;
        std::string jsonAsString = writer.write(requestJson);

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-Authorization", PlayFabSettings::clientSessionTicket);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Client/AndroidDevicePushNotificationRegistration",
            headers,
            jsonAsString,
            OnAndroidDevicePushNotificationRegistrationResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<AndroidDevicePushNotificationRegistrationResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabClientAPI::OnAndroidDevicePushNotificationRegistrationResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        AndroidDevicePushNotificationRegistrationResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<AndroidDevicePushNotificationRegistrationResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabClientAPI::AttributeInstall(
        AttributeInstallRequest& request,
        ProcessApiCallback<AttributeInstallResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();

        Json::FastWriter writer;
        std::string jsonAsString = writer.write(requestJson);

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-Authorization", PlayFabSettings::clientSessionTicket);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Client/AttributeInstall",
            headers,
            jsonAsString,
            OnAttributeInstallResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<AttributeInstallResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabClientAPI::OnAttributeInstallResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        AttributeInstallResult outResult;
        if (ValidateResult(outResult, container))
        {
            PlayFabSettings::advertisingIdType += "_Successful";

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<AttributeInstallResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabClientAPI::CancelTrade(
        CancelTradeRequest& request,
        ProcessApiCallback<CancelTradeResponse> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();

        Json::FastWriter writer;
        std::string jsonAsString = writer.write(requestJson);

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-Authorization", PlayFabSettings::clientSessionTicket);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Client/CancelTrade",
            headers,
            jsonAsString,
            OnCancelTradeResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<CancelTradeResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabClientAPI::OnCancelTradeResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        CancelTradeResponse outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<CancelTradeResponse> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabClientAPI::ConfirmPurchase(
        ConfirmPurchaseRequest& request,
        ProcessApiCallback<ConfirmPurchaseResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();

        Json::FastWriter writer;
        std::string jsonAsString = writer.write(requestJson);

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-Authorization", PlayFabSettings::clientSessionTicket);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Client/ConfirmPurchase",
            headers,
            jsonAsString,
            OnConfirmPurchaseResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<ConfirmPurchaseResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabClientAPI::OnConfirmPurchaseResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        ConfirmPurchaseResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<ConfirmPurchaseResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabClientAPI::ConsumeItem(
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
        headers.emplace("X-Authorization", PlayFabSettings::clientSessionTicket);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Client/ConsumeItem",
            headers,
            jsonAsString,
            OnConsumeItemResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<ConsumeItemResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabClientAPI::OnConsumeItemResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
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

    void PlayFabClientAPI::ConsumeXboxEntitlements(
        ConsumeXboxEntitlementsRequest& request,
        ProcessApiCallback<ConsumeXboxEntitlementsResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();

        Json::FastWriter writer;
        std::string jsonAsString = writer.write(requestJson);

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-Authorization", PlayFabSettings::clientSessionTicket);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Client/ConsumeXboxEntitlements",
            headers,
            jsonAsString,
            OnConsumeXboxEntitlementsResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<ConsumeXboxEntitlementsResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabClientAPI::OnConsumeXboxEntitlementsResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        ConsumeXboxEntitlementsResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<ConsumeXboxEntitlementsResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabClientAPI::CreateSharedGroup(
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
        headers.emplace("X-Authorization", PlayFabSettings::clientSessionTicket);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Client/CreateSharedGroup",
            headers,
            jsonAsString,
            OnCreateSharedGroupResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<CreateSharedGroupResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabClientAPI::OnCreateSharedGroupResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
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

    void PlayFabClientAPI::ExecuteCloudScript(
        ExecuteCloudScriptRequest& request,
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
        headers.emplace("X-Authorization", PlayFabSettings::clientSessionTicket);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Client/ExecuteCloudScript",
            headers,
            jsonAsString,
            OnExecuteCloudScriptResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<ExecuteCloudScriptResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabClientAPI::OnExecuteCloudScriptResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
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

    void PlayFabClientAPI::GetAccountInfo(
        GetAccountInfoRequest& request,
        ProcessApiCallback<GetAccountInfoResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();

        Json::FastWriter writer;
        std::string jsonAsString = writer.write(requestJson);

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-Authorization", PlayFabSettings::clientSessionTicket);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Client/GetAccountInfo",
            headers,
            jsonAsString,
            OnGetAccountInfoResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetAccountInfoResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabClientAPI::OnGetAccountInfoResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        GetAccountInfoResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<GetAccountInfoResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabClientAPI::GetAllUsersCharacters(
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
        headers.emplace("X-Authorization", PlayFabSettings::clientSessionTicket);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Client/GetAllUsersCharacters",
            headers,
            jsonAsString,
            OnGetAllUsersCharactersResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<ListUsersCharactersResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabClientAPI::OnGetAllUsersCharactersResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
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

    void PlayFabClientAPI::GetCatalogItems(
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
        headers.emplace("X-Authorization", PlayFabSettings::clientSessionTicket);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Client/GetCatalogItems",
            headers,
            jsonAsString,
            OnGetCatalogItemsResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetCatalogItemsResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabClientAPI::OnGetCatalogItemsResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
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

    void PlayFabClientAPI::GetCharacterData(
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
        headers.emplace("X-Authorization", PlayFabSettings::clientSessionTicket);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Client/GetCharacterData",
            headers,
            jsonAsString,
            OnGetCharacterDataResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetCharacterDataResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabClientAPI::OnGetCharacterDataResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
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

    void PlayFabClientAPI::GetCharacterInventory(
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
        headers.emplace("X-Authorization", PlayFabSettings::clientSessionTicket);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Client/GetCharacterInventory",
            headers,
            jsonAsString,
            OnGetCharacterInventoryResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetCharacterInventoryResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabClientAPI::OnGetCharacterInventoryResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
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

    void PlayFabClientAPI::GetCharacterLeaderboard(
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
        headers.emplace("X-Authorization", PlayFabSettings::clientSessionTicket);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Client/GetCharacterLeaderboard",
            headers,
            jsonAsString,
            OnGetCharacterLeaderboardResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetCharacterLeaderboardResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabClientAPI::OnGetCharacterLeaderboardResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
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

    void PlayFabClientAPI::GetCharacterReadOnlyData(
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
        headers.emplace("X-Authorization", PlayFabSettings::clientSessionTicket);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Client/GetCharacterReadOnlyData",
            headers,
            jsonAsString,
            OnGetCharacterReadOnlyDataResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetCharacterDataResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabClientAPI::OnGetCharacterReadOnlyDataResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
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

    void PlayFabClientAPI::GetCharacterStatistics(
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
        headers.emplace("X-Authorization", PlayFabSettings::clientSessionTicket);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Client/GetCharacterStatistics",
            headers,
            jsonAsString,
            OnGetCharacterStatisticsResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetCharacterStatisticsResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabClientAPI::OnGetCharacterStatisticsResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
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

    void PlayFabClientAPI::GetContentDownloadUrl(
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
        headers.emplace("X-Authorization", PlayFabSettings::clientSessionTicket);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Client/GetContentDownloadUrl",
            headers,
            jsonAsString,
            OnGetContentDownloadUrlResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetContentDownloadUrlResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabClientAPI::OnGetContentDownloadUrlResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
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

    void PlayFabClientAPI::GetCurrentGames(
        CurrentGamesRequest& request,
        ProcessApiCallback<CurrentGamesResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();

        Json::FastWriter writer;
        std::string jsonAsString = writer.write(requestJson);

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-Authorization", PlayFabSettings::clientSessionTicket);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Client/GetCurrentGames",
            headers,
            jsonAsString,
            OnGetCurrentGamesResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<CurrentGamesResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabClientAPI::OnGetCurrentGamesResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        CurrentGamesResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<CurrentGamesResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabClientAPI::GetFriendLeaderboard(
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
        headers.emplace("X-Authorization", PlayFabSettings::clientSessionTicket);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Client/GetFriendLeaderboard",
            headers,
            jsonAsString,
            OnGetFriendLeaderboardResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetLeaderboardResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabClientAPI::OnGetFriendLeaderboardResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
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

    void PlayFabClientAPI::GetFriendLeaderboardAroundPlayer(
        GetFriendLeaderboardAroundPlayerRequest& request,
        ProcessApiCallback<GetFriendLeaderboardAroundPlayerResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();

        Json::FastWriter writer;
        std::string jsonAsString = writer.write(requestJson);

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-Authorization", PlayFabSettings::clientSessionTicket);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Client/GetFriendLeaderboardAroundPlayer",
            headers,
            jsonAsString,
            OnGetFriendLeaderboardAroundPlayerResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetFriendLeaderboardAroundPlayerResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabClientAPI::OnGetFriendLeaderboardAroundPlayerResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        GetFriendLeaderboardAroundPlayerResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<GetFriendLeaderboardAroundPlayerResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabClientAPI::GetFriendsList(
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
        headers.emplace("X-Authorization", PlayFabSettings::clientSessionTicket);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Client/GetFriendsList",
            headers,
            jsonAsString,
            OnGetFriendsListResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetFriendsListResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabClientAPI::OnGetFriendsListResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
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

    void PlayFabClientAPI::GetGameServerRegions(
        GameServerRegionsRequest& request,
        ProcessApiCallback<GameServerRegionsResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();

        Json::FastWriter writer;
        std::string jsonAsString = writer.write(requestJson);

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-Authorization", PlayFabSettings::clientSessionTicket);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Client/GetGameServerRegions",
            headers,
            jsonAsString,
            OnGetGameServerRegionsResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GameServerRegionsResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabClientAPI::OnGetGameServerRegionsResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        GameServerRegionsResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<GameServerRegionsResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabClientAPI::GetLeaderboard(
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
        headers.emplace("X-Authorization", PlayFabSettings::clientSessionTicket);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Client/GetLeaderboard",
            headers,
            jsonAsString,
            OnGetLeaderboardResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetLeaderboardResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabClientAPI::OnGetLeaderboardResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
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

    void PlayFabClientAPI::GetLeaderboardAroundCharacter(
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
        headers.emplace("X-Authorization", PlayFabSettings::clientSessionTicket);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Client/GetLeaderboardAroundCharacter",
            headers,
            jsonAsString,
            OnGetLeaderboardAroundCharacterResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetLeaderboardAroundCharacterResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabClientAPI::OnGetLeaderboardAroundCharacterResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
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

    void PlayFabClientAPI::GetLeaderboardAroundPlayer(
        GetLeaderboardAroundPlayerRequest& request,
        ProcessApiCallback<GetLeaderboardAroundPlayerResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();

        Json::FastWriter writer;
        std::string jsonAsString = writer.write(requestJson);

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-Authorization", PlayFabSettings::clientSessionTicket);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Client/GetLeaderboardAroundPlayer",
            headers,
            jsonAsString,
            OnGetLeaderboardAroundPlayerResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetLeaderboardAroundPlayerResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabClientAPI::OnGetLeaderboardAroundPlayerResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        GetLeaderboardAroundPlayerResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<GetLeaderboardAroundPlayerResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabClientAPI::GetLeaderboardForUserCharacters(
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
        headers.emplace("X-Authorization", PlayFabSettings::clientSessionTicket);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Client/GetLeaderboardForUserCharacters",
            headers,
            jsonAsString,
            OnGetLeaderboardForUserCharactersResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetLeaderboardForUsersCharactersResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabClientAPI::OnGetLeaderboardForUserCharactersResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
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

    void PlayFabClientAPI::GetPaymentToken(
        GetPaymentTokenRequest& request,
        ProcessApiCallback<GetPaymentTokenResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();

        Json::FastWriter writer;
        std::string jsonAsString = writer.write(requestJson);

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-Authorization", PlayFabSettings::clientSessionTicket);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Client/GetPaymentToken",
            headers,
            jsonAsString,
            OnGetPaymentTokenResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetPaymentTokenResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabClientAPI::OnGetPaymentTokenResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        GetPaymentTokenResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<GetPaymentTokenResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabClientAPI::GetPhotonAuthenticationToken(
        GetPhotonAuthenticationTokenRequest& request,
        ProcessApiCallback<GetPhotonAuthenticationTokenResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();

        Json::FastWriter writer;
        std::string jsonAsString = writer.write(requestJson);

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-Authorization", PlayFabSettings::clientSessionTicket);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Client/GetPhotonAuthenticationToken",
            headers,
            jsonAsString,
            OnGetPhotonAuthenticationTokenResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetPhotonAuthenticationTokenResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabClientAPI::OnGetPhotonAuthenticationTokenResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        GetPhotonAuthenticationTokenResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<GetPhotonAuthenticationTokenResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabClientAPI::GetPlayerCombinedInfo(
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
        headers.emplace("X-Authorization", PlayFabSettings::clientSessionTicket);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Client/GetPlayerCombinedInfo",
            headers,
            jsonAsString,
            OnGetPlayerCombinedInfoResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetPlayerCombinedInfoResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabClientAPI::OnGetPlayerCombinedInfoResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
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

    void PlayFabClientAPI::GetPlayerProfile(
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
        headers.emplace("X-Authorization", PlayFabSettings::clientSessionTicket);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Client/GetPlayerProfile",
            headers,
            jsonAsString,
            OnGetPlayerProfileResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetPlayerProfileResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabClientAPI::OnGetPlayerProfileResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
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

    void PlayFabClientAPI::GetPlayerSegments(
        GetPlayerSegmentsRequest& request,
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
        headers.emplace("X-Authorization", PlayFabSettings::clientSessionTicket);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Client/GetPlayerSegments",
            headers,
            jsonAsString,
            OnGetPlayerSegmentsResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetPlayerSegmentsResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabClientAPI::OnGetPlayerSegmentsResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
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

    void PlayFabClientAPI::GetPlayerStatistics(
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
        headers.emplace("X-Authorization", PlayFabSettings::clientSessionTicket);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Client/GetPlayerStatistics",
            headers,
            jsonAsString,
            OnGetPlayerStatisticsResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetPlayerStatisticsResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabClientAPI::OnGetPlayerStatisticsResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
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

    void PlayFabClientAPI::GetPlayerStatisticVersions(
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
        headers.emplace("X-Authorization", PlayFabSettings::clientSessionTicket);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Client/GetPlayerStatisticVersions",
            headers,
            jsonAsString,
            OnGetPlayerStatisticVersionsResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetPlayerStatisticVersionsResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabClientAPI::OnGetPlayerStatisticVersionsResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
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

    void PlayFabClientAPI::GetPlayerTags(
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
        headers.emplace("X-Authorization", PlayFabSettings::clientSessionTicket);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Client/GetPlayerTags",
            headers,
            jsonAsString,
            OnGetPlayerTagsResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetPlayerTagsResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabClientAPI::OnGetPlayerTagsResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
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

    void PlayFabClientAPI::GetPlayerTrades(
        GetPlayerTradesRequest& request,
        ProcessApiCallback<GetPlayerTradesResponse> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();

        Json::FastWriter writer;
        std::string jsonAsString = writer.write(requestJson);

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-Authorization", PlayFabSettings::clientSessionTicket);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Client/GetPlayerTrades",
            headers,
            jsonAsString,
            OnGetPlayerTradesResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetPlayerTradesResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabClientAPI::OnGetPlayerTradesResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        GetPlayerTradesResponse outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<GetPlayerTradesResponse> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabClientAPI::GetPlayFabIDsFromFacebookIDs(
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
        headers.emplace("X-Authorization", PlayFabSettings::clientSessionTicket);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Client/GetPlayFabIDsFromFacebookIDs",
            headers,
            jsonAsString,
            OnGetPlayFabIDsFromFacebookIDsResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetPlayFabIDsFromFacebookIDsResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabClientAPI::OnGetPlayFabIDsFromFacebookIDsResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
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

    void PlayFabClientAPI::GetPlayFabIDsFromFacebookInstantGamesIds(
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
        headers.emplace("X-Authorization", PlayFabSettings::clientSessionTicket);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Client/GetPlayFabIDsFromFacebookInstantGamesIds",
            headers,
            jsonAsString,
            OnGetPlayFabIDsFromFacebookInstantGamesIdsResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetPlayFabIDsFromFacebookInstantGamesIdsResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabClientAPI::OnGetPlayFabIDsFromFacebookInstantGamesIdsResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
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

    void PlayFabClientAPI::GetPlayFabIDsFromGameCenterIDs(
        GetPlayFabIDsFromGameCenterIDsRequest& request,
        ProcessApiCallback<GetPlayFabIDsFromGameCenterIDsResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();

        Json::FastWriter writer;
        std::string jsonAsString = writer.write(requestJson);

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-Authorization", PlayFabSettings::clientSessionTicket);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Client/GetPlayFabIDsFromGameCenterIDs",
            headers,
            jsonAsString,
            OnGetPlayFabIDsFromGameCenterIDsResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetPlayFabIDsFromGameCenterIDsResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabClientAPI::OnGetPlayFabIDsFromGameCenterIDsResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        GetPlayFabIDsFromGameCenterIDsResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<GetPlayFabIDsFromGameCenterIDsResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabClientAPI::GetPlayFabIDsFromGenericIDs(
        GetPlayFabIDsFromGenericIDsRequest& request,
        ProcessApiCallback<GetPlayFabIDsFromGenericIDsResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();

        Json::FastWriter writer;
        std::string jsonAsString = writer.write(requestJson);

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-Authorization", PlayFabSettings::clientSessionTicket);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Client/GetPlayFabIDsFromGenericIDs",
            headers,
            jsonAsString,
            OnGetPlayFabIDsFromGenericIDsResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetPlayFabIDsFromGenericIDsResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabClientAPI::OnGetPlayFabIDsFromGenericIDsResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        GetPlayFabIDsFromGenericIDsResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<GetPlayFabIDsFromGenericIDsResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabClientAPI::GetPlayFabIDsFromGoogleIDs(
        GetPlayFabIDsFromGoogleIDsRequest& request,
        ProcessApiCallback<GetPlayFabIDsFromGoogleIDsResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();

        Json::FastWriter writer;
        std::string jsonAsString = writer.write(requestJson);

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-Authorization", PlayFabSettings::clientSessionTicket);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Client/GetPlayFabIDsFromGoogleIDs",
            headers,
            jsonAsString,
            OnGetPlayFabIDsFromGoogleIDsResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetPlayFabIDsFromGoogleIDsResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabClientAPI::OnGetPlayFabIDsFromGoogleIDsResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        GetPlayFabIDsFromGoogleIDsResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<GetPlayFabIDsFromGoogleIDsResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabClientAPI::GetPlayFabIDsFromKongregateIDs(
        GetPlayFabIDsFromKongregateIDsRequest& request,
        ProcessApiCallback<GetPlayFabIDsFromKongregateIDsResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();

        Json::FastWriter writer;
        std::string jsonAsString = writer.write(requestJson);

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-Authorization", PlayFabSettings::clientSessionTicket);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Client/GetPlayFabIDsFromKongregateIDs",
            headers,
            jsonAsString,
            OnGetPlayFabIDsFromKongregateIDsResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetPlayFabIDsFromKongregateIDsResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabClientAPI::OnGetPlayFabIDsFromKongregateIDsResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        GetPlayFabIDsFromKongregateIDsResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<GetPlayFabIDsFromKongregateIDsResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabClientAPI::GetPlayFabIDsFromNintendoSwitchDeviceIds(
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
        headers.emplace("X-Authorization", PlayFabSettings::clientSessionTicket);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Client/GetPlayFabIDsFromNintendoSwitchDeviceIds",
            headers,
            jsonAsString,
            OnGetPlayFabIDsFromNintendoSwitchDeviceIdsResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetPlayFabIDsFromNintendoSwitchDeviceIdsResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabClientAPI::OnGetPlayFabIDsFromNintendoSwitchDeviceIdsResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
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

    void PlayFabClientAPI::GetPlayFabIDsFromSteamIDs(
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
        headers.emplace("X-Authorization", PlayFabSettings::clientSessionTicket);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Client/GetPlayFabIDsFromSteamIDs",
            headers,
            jsonAsString,
            OnGetPlayFabIDsFromSteamIDsResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetPlayFabIDsFromSteamIDsResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabClientAPI::OnGetPlayFabIDsFromSteamIDsResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
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

    void PlayFabClientAPI::GetPlayFabIDsFromTwitchIDs(
        GetPlayFabIDsFromTwitchIDsRequest& request,
        ProcessApiCallback<GetPlayFabIDsFromTwitchIDsResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();

        Json::FastWriter writer;
        std::string jsonAsString = writer.write(requestJson);

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-Authorization", PlayFabSettings::clientSessionTicket);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Client/GetPlayFabIDsFromTwitchIDs",
            headers,
            jsonAsString,
            OnGetPlayFabIDsFromTwitchIDsResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetPlayFabIDsFromTwitchIDsResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabClientAPI::OnGetPlayFabIDsFromTwitchIDsResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        GetPlayFabIDsFromTwitchIDsResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<GetPlayFabIDsFromTwitchIDsResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabClientAPI::GetPlayFabIDsFromXboxLiveIDs(
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
        headers.emplace("X-Authorization", PlayFabSettings::clientSessionTicket);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Client/GetPlayFabIDsFromXboxLiveIDs",
            headers,
            jsonAsString,
            OnGetPlayFabIDsFromXboxLiveIDsResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetPlayFabIDsFromXboxLiveIDsResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabClientAPI::OnGetPlayFabIDsFromXboxLiveIDsResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
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

    void PlayFabClientAPI::GetPublisherData(
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
        headers.emplace("X-Authorization", PlayFabSettings::clientSessionTicket);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Client/GetPublisherData",
            headers,
            jsonAsString,
            OnGetPublisherDataResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetPublisherDataResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabClientAPI::OnGetPublisherDataResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
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

    void PlayFabClientAPI::GetPurchase(
        GetPurchaseRequest& request,
        ProcessApiCallback<GetPurchaseResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();

        Json::FastWriter writer;
        std::string jsonAsString = writer.write(requestJson);

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-Authorization", PlayFabSettings::clientSessionTicket);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Client/GetPurchase",
            headers,
            jsonAsString,
            OnGetPurchaseResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetPurchaseResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabClientAPI::OnGetPurchaseResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        GetPurchaseResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<GetPurchaseResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabClientAPI::GetSharedGroupData(
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
        headers.emplace("X-Authorization", PlayFabSettings::clientSessionTicket);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Client/GetSharedGroupData",
            headers,
            jsonAsString,
            OnGetSharedGroupDataResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetSharedGroupDataResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabClientAPI::OnGetSharedGroupDataResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
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

    void PlayFabClientAPI::GetStoreItems(
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
        headers.emplace("X-Authorization", PlayFabSettings::clientSessionTicket);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Client/GetStoreItems",
            headers,
            jsonAsString,
            OnGetStoreItemsResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetStoreItemsResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabClientAPI::OnGetStoreItemsResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
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

    void PlayFabClientAPI::GetTime(
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
        headers.emplace("X-Authorization", PlayFabSettings::clientSessionTicket);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Client/GetTime",
            headers,
            jsonAsString,
            OnGetTimeResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetTimeResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabClientAPI::OnGetTimeResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
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

    void PlayFabClientAPI::GetTitleData(
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
        headers.emplace("X-Authorization", PlayFabSettings::clientSessionTicket);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Client/GetTitleData",
            headers,
            jsonAsString,
            OnGetTitleDataResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetTitleDataResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabClientAPI::OnGetTitleDataResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
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

    void PlayFabClientAPI::GetTitleNews(
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
        headers.emplace("X-Authorization", PlayFabSettings::clientSessionTicket);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Client/GetTitleNews",
            headers,
            jsonAsString,
            OnGetTitleNewsResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetTitleNewsResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabClientAPI::OnGetTitleNewsResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
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

    void PlayFabClientAPI::GetTitlePublicKey(
        GetTitlePublicKeyRequest& request,
        ProcessApiCallback<GetTitlePublicKeyResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();

        Json::FastWriter writer;
        std::string jsonAsString = writer.write(requestJson);

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("", "");

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Client/GetTitlePublicKey",
            headers,
            jsonAsString,
            OnGetTitlePublicKeyResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetTitlePublicKeyResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabClientAPI::OnGetTitlePublicKeyResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        GetTitlePublicKeyResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<GetTitlePublicKeyResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabClientAPI::GetTradeStatus(
        GetTradeStatusRequest& request,
        ProcessApiCallback<GetTradeStatusResponse> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();

        Json::FastWriter writer;
        std::string jsonAsString = writer.write(requestJson);

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-Authorization", PlayFabSettings::clientSessionTicket);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Client/GetTradeStatus",
            headers,
            jsonAsString,
            OnGetTradeStatusResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetTradeStatusResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabClientAPI::OnGetTradeStatusResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        GetTradeStatusResponse outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<GetTradeStatusResponse> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabClientAPI::GetUserData(
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
        headers.emplace("X-Authorization", PlayFabSettings::clientSessionTicket);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Client/GetUserData",
            headers,
            jsonAsString,
            OnGetUserDataResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetUserDataResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabClientAPI::OnGetUserDataResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
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

    void PlayFabClientAPI::GetUserInventory(
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
        headers.emplace("X-Authorization", PlayFabSettings::clientSessionTicket);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Client/GetUserInventory",
            headers,
            jsonAsString,
            OnGetUserInventoryResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetUserInventoryResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabClientAPI::OnGetUserInventoryResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
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

    void PlayFabClientAPI::GetUserPublisherData(
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
        headers.emplace("X-Authorization", PlayFabSettings::clientSessionTicket);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Client/GetUserPublisherData",
            headers,
            jsonAsString,
            OnGetUserPublisherDataResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetUserDataResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabClientAPI::OnGetUserPublisherDataResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
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

    void PlayFabClientAPI::GetUserPublisherReadOnlyData(
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
        headers.emplace("X-Authorization", PlayFabSettings::clientSessionTicket);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Client/GetUserPublisherReadOnlyData",
            headers,
            jsonAsString,
            OnGetUserPublisherReadOnlyDataResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetUserDataResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabClientAPI::OnGetUserPublisherReadOnlyDataResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
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

    void PlayFabClientAPI::GetUserReadOnlyData(
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
        headers.emplace("X-Authorization", PlayFabSettings::clientSessionTicket);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Client/GetUserReadOnlyData",
            headers,
            jsonAsString,
            OnGetUserReadOnlyDataResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetUserDataResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabClientAPI::OnGetUserReadOnlyDataResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
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

    void PlayFabClientAPI::GetWindowsHelloChallenge(
        GetWindowsHelloChallengeRequest& request,
        ProcessApiCallback<GetWindowsHelloChallengeResponse> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();

        Json::FastWriter writer;
        std::string jsonAsString = writer.write(requestJson);

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("", "");

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Client/GetWindowsHelloChallenge",
            headers,
            jsonAsString,
            OnGetWindowsHelloChallengeResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetWindowsHelloChallengeResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabClientAPI::OnGetWindowsHelloChallengeResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        GetWindowsHelloChallengeResponse outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<GetWindowsHelloChallengeResponse> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabClientAPI::GrantCharacterToUser(
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
        headers.emplace("X-Authorization", PlayFabSettings::clientSessionTicket);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Client/GrantCharacterToUser",
            headers,
            jsonAsString,
            OnGrantCharacterToUserResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GrantCharacterToUserResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabClientAPI::OnGrantCharacterToUserResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
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

    void PlayFabClientAPI::LinkAndroidDeviceID(
        LinkAndroidDeviceIDRequest& request,
        ProcessApiCallback<LinkAndroidDeviceIDResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();

        Json::FastWriter writer;
        std::string jsonAsString = writer.write(requestJson);

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-Authorization", PlayFabSettings::clientSessionTicket);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Client/LinkAndroidDeviceID",
            headers,
            jsonAsString,
            OnLinkAndroidDeviceIDResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<LinkAndroidDeviceIDResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabClientAPI::OnLinkAndroidDeviceIDResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        LinkAndroidDeviceIDResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<LinkAndroidDeviceIDResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabClientAPI::LinkCustomID(
        LinkCustomIDRequest& request,
        ProcessApiCallback<LinkCustomIDResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();

        Json::FastWriter writer;
        std::string jsonAsString = writer.write(requestJson);

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-Authorization", PlayFabSettings::clientSessionTicket);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Client/LinkCustomID",
            headers,
            jsonAsString,
            OnLinkCustomIDResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<LinkCustomIDResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabClientAPI::OnLinkCustomIDResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        LinkCustomIDResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<LinkCustomIDResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabClientAPI::LinkFacebookAccount(
        LinkFacebookAccountRequest& request,
        ProcessApiCallback<LinkFacebookAccountResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();

        Json::FastWriter writer;
        std::string jsonAsString = writer.write(requestJson);

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-Authorization", PlayFabSettings::clientSessionTicket);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Client/LinkFacebookAccount",
            headers,
            jsonAsString,
            OnLinkFacebookAccountResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<LinkFacebookAccountResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabClientAPI::OnLinkFacebookAccountResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        LinkFacebookAccountResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<LinkFacebookAccountResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabClientAPI::LinkFacebookInstantGamesId(
        LinkFacebookInstantGamesIdRequest& request,
        ProcessApiCallback<LinkFacebookInstantGamesIdResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();

        Json::FastWriter writer;
        std::string jsonAsString = writer.write(requestJson);

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-Authorization", PlayFabSettings::clientSessionTicket);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Client/LinkFacebookInstantGamesId",
            headers,
            jsonAsString,
            OnLinkFacebookInstantGamesIdResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<LinkFacebookInstantGamesIdResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabClientAPI::OnLinkFacebookInstantGamesIdResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        LinkFacebookInstantGamesIdResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<LinkFacebookInstantGamesIdResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabClientAPI::LinkGameCenterAccount(
        LinkGameCenterAccountRequest& request,
        ProcessApiCallback<LinkGameCenterAccountResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();

        Json::FastWriter writer;
        std::string jsonAsString = writer.write(requestJson);

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-Authorization", PlayFabSettings::clientSessionTicket);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Client/LinkGameCenterAccount",
            headers,
            jsonAsString,
            OnLinkGameCenterAccountResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<LinkGameCenterAccountResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabClientAPI::OnLinkGameCenterAccountResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        LinkGameCenterAccountResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<LinkGameCenterAccountResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabClientAPI::LinkGoogleAccount(
        LinkGoogleAccountRequest& request,
        ProcessApiCallback<LinkGoogleAccountResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();

        Json::FastWriter writer;
        std::string jsonAsString = writer.write(requestJson);

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-Authorization", PlayFabSettings::clientSessionTicket);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Client/LinkGoogleAccount",
            headers,
            jsonAsString,
            OnLinkGoogleAccountResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<LinkGoogleAccountResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabClientAPI::OnLinkGoogleAccountResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        LinkGoogleAccountResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<LinkGoogleAccountResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabClientAPI::LinkIOSDeviceID(
        LinkIOSDeviceIDRequest& request,
        ProcessApiCallback<LinkIOSDeviceIDResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();

        Json::FastWriter writer;
        std::string jsonAsString = writer.write(requestJson);

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-Authorization", PlayFabSettings::clientSessionTicket);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Client/LinkIOSDeviceID",
            headers,
            jsonAsString,
            OnLinkIOSDeviceIDResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<LinkIOSDeviceIDResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabClientAPI::OnLinkIOSDeviceIDResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        LinkIOSDeviceIDResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<LinkIOSDeviceIDResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabClientAPI::LinkKongregate(
        LinkKongregateAccountRequest& request,
        ProcessApiCallback<LinkKongregateAccountResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();

        Json::FastWriter writer;
        std::string jsonAsString = writer.write(requestJson);

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-Authorization", PlayFabSettings::clientSessionTicket);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Client/LinkKongregate",
            headers,
            jsonAsString,
            OnLinkKongregateResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<LinkKongregateAccountResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabClientAPI::OnLinkKongregateResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        LinkKongregateAccountResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<LinkKongregateAccountResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabClientAPI::LinkNintendoSwitchDeviceId(
        LinkNintendoSwitchDeviceIdRequest& request,
        ProcessApiCallback<LinkNintendoSwitchDeviceIdResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();

        Json::FastWriter writer;
        std::string jsonAsString = writer.write(requestJson);

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-Authorization", PlayFabSettings::clientSessionTicket);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Client/LinkNintendoSwitchDeviceId",
            headers,
            jsonAsString,
            OnLinkNintendoSwitchDeviceIdResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<LinkNintendoSwitchDeviceIdResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabClientAPI::OnLinkNintendoSwitchDeviceIdResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        LinkNintendoSwitchDeviceIdResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<LinkNintendoSwitchDeviceIdResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabClientAPI::LinkOpenIdConnect(
        LinkOpenIdConnectRequest& request,
        ProcessApiCallback<EmptyResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();

        Json::FastWriter writer;
        std::string jsonAsString = writer.write(requestJson);

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-Authorization", PlayFabSettings::clientSessionTicket);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Client/LinkOpenIdConnect",
            headers,
            jsonAsString,
            OnLinkOpenIdConnectResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<EmptyResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabClientAPI::OnLinkOpenIdConnectResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        EmptyResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<EmptyResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabClientAPI::LinkSteamAccount(
        LinkSteamAccountRequest& request,
        ProcessApiCallback<LinkSteamAccountResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();

        Json::FastWriter writer;
        std::string jsonAsString = writer.write(requestJson);

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-Authorization", PlayFabSettings::clientSessionTicket);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Client/LinkSteamAccount",
            headers,
            jsonAsString,
            OnLinkSteamAccountResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<LinkSteamAccountResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabClientAPI::OnLinkSteamAccountResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        LinkSteamAccountResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<LinkSteamAccountResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabClientAPI::LinkTwitch(
        LinkTwitchAccountRequest& request,
        ProcessApiCallback<LinkTwitchAccountResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();

        Json::FastWriter writer;
        std::string jsonAsString = writer.write(requestJson);

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-Authorization", PlayFabSettings::clientSessionTicket);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Client/LinkTwitch",
            headers,
            jsonAsString,
            OnLinkTwitchResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<LinkTwitchAccountResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabClientAPI::OnLinkTwitchResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        LinkTwitchAccountResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<LinkTwitchAccountResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabClientAPI::LinkWindowsHello(
        LinkWindowsHelloAccountRequest& request,
        ProcessApiCallback<LinkWindowsHelloAccountResponse> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();

        Json::FastWriter writer;
        std::string jsonAsString = writer.write(requestJson);

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-Authorization", PlayFabSettings::clientSessionTicket);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Client/LinkWindowsHello",
            headers,
            jsonAsString,
            OnLinkWindowsHelloResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<LinkWindowsHelloAccountResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabClientAPI::OnLinkWindowsHelloResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        LinkWindowsHelloAccountResponse outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<LinkWindowsHelloAccountResponse> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabClientAPI::LinkXboxAccount(
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
        headers.emplace("X-Authorization", PlayFabSettings::clientSessionTicket);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Client/LinkXboxAccount",
            headers,
            jsonAsString,
            OnLinkXboxAccountResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<LinkXboxAccountResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabClientAPI::OnLinkXboxAccountResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
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

    void PlayFabClientAPI::LoginWithAndroidDeviceID(
        LoginWithAndroidDeviceIDRequest& request,
        ProcessApiCallback<LoginResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {
        if (PlayFabSettings::titleId.length() > 0)
        {
            request.TitleId = PlayFabSettings::titleId;
        }

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();

        Json::FastWriter writer;
        std::string jsonAsString = writer.write(requestJson);

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("", "");

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Client/LoginWithAndroidDeviceID",
            headers,
            jsonAsString,
            OnLoginWithAndroidDeviceIDResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<LoginResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabClientAPI::OnLoginWithAndroidDeviceIDResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        LoginResult outResult;
        if (ValidateResult(outResult, container))
        {
            if (outResult.SessionTicket.length() > 0)
            {
                PlayFabSettings::clientSessionTicket = outResult.SessionTicket;
                if (outResult.EntityToken.notNull()) PlayFabSettings::entityToken = outResult.EntityToken->EntityToken;
                MultiStepClientLogin(outResult.SettingsForUser->NeedsAttribution);
            }

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<LoginResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabClientAPI::LoginWithCustomID(
        LoginWithCustomIDRequest& request,
        ProcessApiCallback<LoginResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {
        if (PlayFabSettings::titleId.length() > 0)
        {
            request.TitleId = PlayFabSettings::titleId;
        }

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();

        Json::FastWriter writer;
        std::string jsonAsString = writer.write(requestJson);

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("", "");

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Client/LoginWithCustomID",
            headers,
            jsonAsString,
            OnLoginWithCustomIDResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<LoginResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabClientAPI::OnLoginWithCustomIDResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        LoginResult outResult;
        if (ValidateResult(outResult, container))
        {
            if (outResult.SessionTicket.length() > 0)
            {
                PlayFabSettings::clientSessionTicket = outResult.SessionTicket;
                if (outResult.EntityToken.notNull()) PlayFabSettings::entityToken = outResult.EntityToken->EntityToken;
                MultiStepClientLogin(outResult.SettingsForUser->NeedsAttribution);
            }

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<LoginResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabClientAPI::LoginWithEmailAddress(
        LoginWithEmailAddressRequest& request,
        ProcessApiCallback<LoginResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {
        if (PlayFabSettings::titleId.length() > 0)
        {
            request.TitleId = PlayFabSettings::titleId;
        }

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();

        Json::FastWriter writer;
        std::string jsonAsString = writer.write(requestJson);

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("", "");

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Client/LoginWithEmailAddress",
            headers,
            jsonAsString,
            OnLoginWithEmailAddressResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<LoginResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabClientAPI::OnLoginWithEmailAddressResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        LoginResult outResult;
        if (ValidateResult(outResult, container))
        {
            if (outResult.SessionTicket.length() > 0)
            {
                PlayFabSettings::clientSessionTicket = outResult.SessionTicket;
                if (outResult.EntityToken.notNull()) PlayFabSettings::entityToken = outResult.EntityToken->EntityToken;
                MultiStepClientLogin(outResult.SettingsForUser->NeedsAttribution);
            }

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<LoginResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabClientAPI::LoginWithFacebook(
        LoginWithFacebookRequest& request,
        ProcessApiCallback<LoginResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {
        if (PlayFabSettings::titleId.length() > 0)
        {
            request.TitleId = PlayFabSettings::titleId;
        }

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();

        Json::FastWriter writer;
        std::string jsonAsString = writer.write(requestJson);

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("", "");

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Client/LoginWithFacebook",
            headers,
            jsonAsString,
            OnLoginWithFacebookResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<LoginResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabClientAPI::OnLoginWithFacebookResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        LoginResult outResult;
        if (ValidateResult(outResult, container))
        {
            if (outResult.SessionTicket.length() > 0)
            {
                PlayFabSettings::clientSessionTicket = outResult.SessionTicket;
                if (outResult.EntityToken.notNull()) PlayFabSettings::entityToken = outResult.EntityToken->EntityToken;
                MultiStepClientLogin(outResult.SettingsForUser->NeedsAttribution);
            }

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<LoginResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabClientAPI::LoginWithFacebookInstantGamesId(
        LoginWithFacebookInstantGamesIdRequest& request,
        ProcessApiCallback<LoginResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {
        if (PlayFabSettings::titleId.length() > 0)
        {
            request.TitleId = PlayFabSettings::titleId;
        }

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();

        Json::FastWriter writer;
        std::string jsonAsString = writer.write(requestJson);

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("", "");

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Client/LoginWithFacebookInstantGamesId",
            headers,
            jsonAsString,
            OnLoginWithFacebookInstantGamesIdResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<LoginResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabClientAPI::OnLoginWithFacebookInstantGamesIdResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        LoginResult outResult;
        if (ValidateResult(outResult, container))
        {
            if (outResult.SessionTicket.length() > 0)
            {
                PlayFabSettings::clientSessionTicket = outResult.SessionTicket;
                if (outResult.EntityToken.notNull()) PlayFabSettings::entityToken = outResult.EntityToken->EntityToken;
                MultiStepClientLogin(outResult.SettingsForUser->NeedsAttribution);
            }

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<LoginResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabClientAPI::LoginWithGameCenter(
        LoginWithGameCenterRequest& request,
        ProcessApiCallback<LoginResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {
        if (PlayFabSettings::titleId.length() > 0)
        {
            request.TitleId = PlayFabSettings::titleId;
        }

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();

        Json::FastWriter writer;
        std::string jsonAsString = writer.write(requestJson);

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("", "");

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Client/LoginWithGameCenter",
            headers,
            jsonAsString,
            OnLoginWithGameCenterResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<LoginResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabClientAPI::OnLoginWithGameCenterResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        LoginResult outResult;
        if (ValidateResult(outResult, container))
        {
            if (outResult.SessionTicket.length() > 0)
            {
                PlayFabSettings::clientSessionTicket = outResult.SessionTicket;
                if (outResult.EntityToken.notNull()) PlayFabSettings::entityToken = outResult.EntityToken->EntityToken;
                MultiStepClientLogin(outResult.SettingsForUser->NeedsAttribution);
            }

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<LoginResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabClientAPI::LoginWithGoogleAccount(
        LoginWithGoogleAccountRequest& request,
        ProcessApiCallback<LoginResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {
        if (PlayFabSettings::titleId.length() > 0)
        {
            request.TitleId = PlayFabSettings::titleId;
        }

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();

        Json::FastWriter writer;
        std::string jsonAsString = writer.write(requestJson);

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("", "");

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Client/LoginWithGoogleAccount",
            headers,
            jsonAsString,
            OnLoginWithGoogleAccountResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<LoginResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabClientAPI::OnLoginWithGoogleAccountResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        LoginResult outResult;
        if (ValidateResult(outResult, container))
        {
            if (outResult.SessionTicket.length() > 0)
            {
                PlayFabSettings::clientSessionTicket = outResult.SessionTicket;
                if (outResult.EntityToken.notNull()) PlayFabSettings::entityToken = outResult.EntityToken->EntityToken;
                MultiStepClientLogin(outResult.SettingsForUser->NeedsAttribution);
            }

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<LoginResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabClientAPI::LoginWithIOSDeviceID(
        LoginWithIOSDeviceIDRequest& request,
        ProcessApiCallback<LoginResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {
        if (PlayFabSettings::titleId.length() > 0)
        {
            request.TitleId = PlayFabSettings::titleId;
        }

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();

        Json::FastWriter writer;
        std::string jsonAsString = writer.write(requestJson);

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("", "");

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Client/LoginWithIOSDeviceID",
            headers,
            jsonAsString,
            OnLoginWithIOSDeviceIDResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<LoginResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabClientAPI::OnLoginWithIOSDeviceIDResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        LoginResult outResult;
        if (ValidateResult(outResult, container))
        {
            if (outResult.SessionTicket.length() > 0)
            {
                PlayFabSettings::clientSessionTicket = outResult.SessionTicket;
                if (outResult.EntityToken.notNull()) PlayFabSettings::entityToken = outResult.EntityToken->EntityToken;
                MultiStepClientLogin(outResult.SettingsForUser->NeedsAttribution);
            }

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<LoginResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabClientAPI::LoginWithKongregate(
        LoginWithKongregateRequest& request,
        ProcessApiCallback<LoginResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {
        if (PlayFabSettings::titleId.length() > 0)
        {
            request.TitleId = PlayFabSettings::titleId;
        }

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();

        Json::FastWriter writer;
        std::string jsonAsString = writer.write(requestJson);

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("", "");

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Client/LoginWithKongregate",
            headers,
            jsonAsString,
            OnLoginWithKongregateResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<LoginResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabClientAPI::OnLoginWithKongregateResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        LoginResult outResult;
        if (ValidateResult(outResult, container))
        {
            if (outResult.SessionTicket.length() > 0)
            {
                PlayFabSettings::clientSessionTicket = outResult.SessionTicket;
                if (outResult.EntityToken.notNull()) PlayFabSettings::entityToken = outResult.EntityToken->EntityToken;
                MultiStepClientLogin(outResult.SettingsForUser->NeedsAttribution);
            }

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<LoginResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabClientAPI::LoginWithNintendoSwitchDeviceId(
        LoginWithNintendoSwitchDeviceIdRequest& request,
        ProcessApiCallback<LoginResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {
        if (PlayFabSettings::titleId.length() > 0)
        {
            request.TitleId = PlayFabSettings::titleId;
        }

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();

        Json::FastWriter writer;
        std::string jsonAsString = writer.write(requestJson);

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("", "");

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Client/LoginWithNintendoSwitchDeviceId",
            headers,
            jsonAsString,
            OnLoginWithNintendoSwitchDeviceIdResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<LoginResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabClientAPI::OnLoginWithNintendoSwitchDeviceIdResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        LoginResult outResult;
        if (ValidateResult(outResult, container))
        {
            if (outResult.SessionTicket.length() > 0)
            {
                PlayFabSettings::clientSessionTicket = outResult.SessionTicket;
                if (outResult.EntityToken.notNull()) PlayFabSettings::entityToken = outResult.EntityToken->EntityToken;
                MultiStepClientLogin(outResult.SettingsForUser->NeedsAttribution);
            }

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<LoginResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabClientAPI::LoginWithOpenIdConnect(
        LoginWithOpenIdConnectRequest& request,
        ProcessApiCallback<LoginResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {
        if (PlayFabSettings::titleId.length() > 0)
        {
            request.TitleId = PlayFabSettings::titleId;
        }

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();

        Json::FastWriter writer;
        std::string jsonAsString = writer.write(requestJson);

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("", "");

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Client/LoginWithOpenIdConnect",
            headers,
            jsonAsString,
            OnLoginWithOpenIdConnectResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<LoginResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabClientAPI::OnLoginWithOpenIdConnectResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        LoginResult outResult;
        if (ValidateResult(outResult, container))
        {
            if (outResult.SessionTicket.length() > 0)
            {
                PlayFabSettings::clientSessionTicket = outResult.SessionTicket;
                if (outResult.EntityToken.notNull()) PlayFabSettings::entityToken = outResult.EntityToken->EntityToken;
                MultiStepClientLogin(outResult.SettingsForUser->NeedsAttribution);
            }

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<LoginResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabClientAPI::LoginWithPlayFab(
        LoginWithPlayFabRequest& request,
        ProcessApiCallback<LoginResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {
        if (PlayFabSettings::titleId.length() > 0)
        {
            request.TitleId = PlayFabSettings::titleId;
        }

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();

        Json::FastWriter writer;
        std::string jsonAsString = writer.write(requestJson);

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("", "");

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Client/LoginWithPlayFab",
            headers,
            jsonAsString,
            OnLoginWithPlayFabResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<LoginResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabClientAPI::OnLoginWithPlayFabResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        LoginResult outResult;
        if (ValidateResult(outResult, container))
        {
            if (outResult.SessionTicket.length() > 0)
            {
                PlayFabSettings::clientSessionTicket = outResult.SessionTicket;
                if (outResult.EntityToken.notNull()) PlayFabSettings::entityToken = outResult.EntityToken->EntityToken;
                MultiStepClientLogin(outResult.SettingsForUser->NeedsAttribution);
            }

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<LoginResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabClientAPI::LoginWithSteam(
        LoginWithSteamRequest& request,
        ProcessApiCallback<LoginResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {
        if (PlayFabSettings::titleId.length() > 0)
        {
            request.TitleId = PlayFabSettings::titleId;
        }

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();

        Json::FastWriter writer;
        std::string jsonAsString = writer.write(requestJson);

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("", "");

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Client/LoginWithSteam",
            headers,
            jsonAsString,
            OnLoginWithSteamResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<LoginResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabClientAPI::OnLoginWithSteamResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        LoginResult outResult;
        if (ValidateResult(outResult, container))
        {
            if (outResult.SessionTicket.length() > 0)
            {
                PlayFabSettings::clientSessionTicket = outResult.SessionTicket;
                if (outResult.EntityToken.notNull()) PlayFabSettings::entityToken = outResult.EntityToken->EntityToken;
                MultiStepClientLogin(outResult.SettingsForUser->NeedsAttribution);
            }

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<LoginResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabClientAPI::LoginWithTwitch(
        LoginWithTwitchRequest& request,
        ProcessApiCallback<LoginResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {
        if (PlayFabSettings::titleId.length() > 0)
        {
            request.TitleId = PlayFabSettings::titleId;
        }

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();

        Json::FastWriter writer;
        std::string jsonAsString = writer.write(requestJson);

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("", "");

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Client/LoginWithTwitch",
            headers,
            jsonAsString,
            OnLoginWithTwitchResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<LoginResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabClientAPI::OnLoginWithTwitchResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        LoginResult outResult;
        if (ValidateResult(outResult, container))
        {
            if (outResult.SessionTicket.length() > 0)
            {
                PlayFabSettings::clientSessionTicket = outResult.SessionTicket;
                if (outResult.EntityToken.notNull()) PlayFabSettings::entityToken = outResult.EntityToken->EntityToken;
                MultiStepClientLogin(outResult.SettingsForUser->NeedsAttribution);
            }

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<LoginResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabClientAPI::LoginWithWindowsHello(
        LoginWithWindowsHelloRequest& request,
        ProcessApiCallback<LoginResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {
        if (PlayFabSettings::titleId.length() > 0)
        {
            request.TitleId = PlayFabSettings::titleId;
        }

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();

        Json::FastWriter writer;
        std::string jsonAsString = writer.write(requestJson);

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("", "");

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Client/LoginWithWindowsHello",
            headers,
            jsonAsString,
            OnLoginWithWindowsHelloResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<LoginResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabClientAPI::OnLoginWithWindowsHelloResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        LoginResult outResult;
        if (ValidateResult(outResult, container))
        {
            if (outResult.SessionTicket.length() > 0)
            {
                PlayFabSettings::clientSessionTicket = outResult.SessionTicket;
                if (outResult.EntityToken.notNull()) PlayFabSettings::entityToken = outResult.EntityToken->EntityToken;
                MultiStepClientLogin(outResult.SettingsForUser->NeedsAttribution);
            }

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<LoginResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabClientAPI::LoginWithXbox(
        LoginWithXboxRequest& request,
        ProcessApiCallback<LoginResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {
        if (PlayFabSettings::titleId.length() > 0)
        {
            request.TitleId = PlayFabSettings::titleId;
        }

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();

        Json::FastWriter writer;
        std::string jsonAsString = writer.write(requestJson);

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("", "");

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Client/LoginWithXbox",
            headers,
            jsonAsString,
            OnLoginWithXboxResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<LoginResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabClientAPI::OnLoginWithXboxResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        LoginResult outResult;
        if (ValidateResult(outResult, container))
        {
            if (outResult.SessionTicket.length() > 0)
            {
                PlayFabSettings::clientSessionTicket = outResult.SessionTicket;
                if (outResult.EntityToken.notNull()) PlayFabSettings::entityToken = outResult.EntityToken->EntityToken;
                MultiStepClientLogin(outResult.SettingsForUser->NeedsAttribution);
            }

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<LoginResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabClientAPI::Matchmake(
        MatchmakeRequest& request,
        ProcessApiCallback<MatchmakeResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();

        Json::FastWriter writer;
        std::string jsonAsString = writer.write(requestJson);

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-Authorization", PlayFabSettings::clientSessionTicket);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Client/Matchmake",
            headers,
            jsonAsString,
            OnMatchmakeResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<MatchmakeResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabClientAPI::OnMatchmakeResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        MatchmakeResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<MatchmakeResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabClientAPI::OpenTrade(
        OpenTradeRequest& request,
        ProcessApiCallback<OpenTradeResponse> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();

        Json::FastWriter writer;
        std::string jsonAsString = writer.write(requestJson);

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-Authorization", PlayFabSettings::clientSessionTicket);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Client/OpenTrade",
            headers,
            jsonAsString,
            OnOpenTradeResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<OpenTradeResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabClientAPI::OnOpenTradeResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        OpenTradeResponse outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<OpenTradeResponse> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabClientAPI::PayForPurchase(
        PayForPurchaseRequest& request,
        ProcessApiCallback<PayForPurchaseResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();

        Json::FastWriter writer;
        std::string jsonAsString = writer.write(requestJson);

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-Authorization", PlayFabSettings::clientSessionTicket);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Client/PayForPurchase",
            headers,
            jsonAsString,
            OnPayForPurchaseResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<PayForPurchaseResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabClientAPI::OnPayForPurchaseResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        PayForPurchaseResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<PayForPurchaseResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabClientAPI::PurchaseItem(
        PurchaseItemRequest& request,
        ProcessApiCallback<PurchaseItemResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();

        Json::FastWriter writer;
        std::string jsonAsString = writer.write(requestJson);

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-Authorization", PlayFabSettings::clientSessionTicket);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Client/PurchaseItem",
            headers,
            jsonAsString,
            OnPurchaseItemResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<PurchaseItemResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabClientAPI::OnPurchaseItemResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        PurchaseItemResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<PurchaseItemResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabClientAPI::RedeemCoupon(
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
        headers.emplace("X-Authorization", PlayFabSettings::clientSessionTicket);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Client/RedeemCoupon",
            headers,
            jsonAsString,
            OnRedeemCouponResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<RedeemCouponResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabClientAPI::OnRedeemCouponResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
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

    void PlayFabClientAPI::RegisterForIOSPushNotification(
        RegisterForIOSPushNotificationRequest& request,
        ProcessApiCallback<RegisterForIOSPushNotificationResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();

        Json::FastWriter writer;
        std::string jsonAsString = writer.write(requestJson);

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-Authorization", PlayFabSettings::clientSessionTicket);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Client/RegisterForIOSPushNotification",
            headers,
            jsonAsString,
            OnRegisterForIOSPushNotificationResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<RegisterForIOSPushNotificationResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabClientAPI::OnRegisterForIOSPushNotificationResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        RegisterForIOSPushNotificationResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<RegisterForIOSPushNotificationResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabClientAPI::RegisterPlayFabUser(
        RegisterPlayFabUserRequest& request,
        ProcessApiCallback<RegisterPlayFabUserResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {
        if (PlayFabSettings::titleId.length() > 0)
        {
            request.TitleId = PlayFabSettings::titleId;
        }

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();

        Json::FastWriter writer;
        std::string jsonAsString = writer.write(requestJson);

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("", "");

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Client/RegisterPlayFabUser",
            headers,
            jsonAsString,
            OnRegisterPlayFabUserResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<RegisterPlayFabUserResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabClientAPI::OnRegisterPlayFabUserResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        RegisterPlayFabUserResult outResult;
        if (ValidateResult(outResult, container))
        {
            if (outResult.SessionTicket.length() > 0)
            {
                PlayFabSettings::clientSessionTicket = outResult.SessionTicket;
                MultiStepClientLogin(outResult.SettingsForUser->NeedsAttribution);
            }

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<RegisterPlayFabUserResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabClientAPI::RegisterWithWindowsHello(
        RegisterWithWindowsHelloRequest& request,
        ProcessApiCallback<LoginResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {
        if (PlayFabSettings::titleId.length() > 0)
        {
            request.TitleId = PlayFabSettings::titleId;
        }

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();

        Json::FastWriter writer;
        std::string jsonAsString = writer.write(requestJson);

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("", "");

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Client/RegisterWithWindowsHello",
            headers,
            jsonAsString,
            OnRegisterWithWindowsHelloResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<LoginResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabClientAPI::OnRegisterWithWindowsHelloResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        LoginResult outResult;
        if (ValidateResult(outResult, container))
        {
            if (outResult.SessionTicket.length() > 0)
            {
                PlayFabSettings::clientSessionTicket = outResult.SessionTicket;
                if (outResult.EntityToken.notNull()) PlayFabSettings::entityToken = outResult.EntityToken->EntityToken;
                MultiStepClientLogin(outResult.SettingsForUser->NeedsAttribution);
            }

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<LoginResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabClientAPI::RemoveContactEmail(
        RemoveContactEmailRequest& request,
        ProcessApiCallback<RemoveContactEmailResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();

        Json::FastWriter writer;
        std::string jsonAsString = writer.write(requestJson);

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-Authorization", PlayFabSettings::clientSessionTicket);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Client/RemoveContactEmail",
            headers,
            jsonAsString,
            OnRemoveContactEmailResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<RemoveContactEmailResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabClientAPI::OnRemoveContactEmailResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        RemoveContactEmailResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<RemoveContactEmailResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabClientAPI::RemoveFriend(
        RemoveFriendRequest& request,
        ProcessApiCallback<RemoveFriendResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();

        Json::FastWriter writer;
        std::string jsonAsString = writer.write(requestJson);

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-Authorization", PlayFabSettings::clientSessionTicket);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Client/RemoveFriend",
            headers,
            jsonAsString,
            OnRemoveFriendResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<RemoveFriendResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabClientAPI::OnRemoveFriendResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        RemoveFriendResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<RemoveFriendResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabClientAPI::RemoveGenericID(
        RemoveGenericIDRequest& request,
        ProcessApiCallback<RemoveGenericIDResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();

        Json::FastWriter writer;
        std::string jsonAsString = writer.write(requestJson);

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-Authorization", PlayFabSettings::clientSessionTicket);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Client/RemoveGenericID",
            headers,
            jsonAsString,
            OnRemoveGenericIDResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<RemoveGenericIDResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabClientAPI::OnRemoveGenericIDResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        RemoveGenericIDResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<RemoveGenericIDResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabClientAPI::RemoveSharedGroupMembers(
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
        headers.emplace("X-Authorization", PlayFabSettings::clientSessionTicket);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Client/RemoveSharedGroupMembers",
            headers,
            jsonAsString,
            OnRemoveSharedGroupMembersResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<RemoveSharedGroupMembersResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabClientAPI::OnRemoveSharedGroupMembersResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
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

    void PlayFabClientAPI::ReportDeviceInfo(
        DeviceInfoRequest& request,
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
        headers.emplace("X-Authorization", PlayFabSettings::clientSessionTicket);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Client/ReportDeviceInfo",
            headers,
            jsonAsString,
            OnReportDeviceInfoResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<EmptyResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabClientAPI::OnReportDeviceInfoResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
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

    void PlayFabClientAPI::ReportPlayer(
        ReportPlayerClientRequest& request,
        ProcessApiCallback<ReportPlayerClientResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();

        Json::FastWriter writer;
        std::string jsonAsString = writer.write(requestJson);

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-Authorization", PlayFabSettings::clientSessionTicket);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Client/ReportPlayer",
            headers,
            jsonAsString,
            OnReportPlayerResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<ReportPlayerClientResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabClientAPI::OnReportPlayerResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        ReportPlayerClientResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<ReportPlayerClientResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabClientAPI::RestoreIOSPurchases(
        RestoreIOSPurchasesRequest& request,
        ProcessApiCallback<RestoreIOSPurchasesResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();

        Json::FastWriter writer;
        std::string jsonAsString = writer.write(requestJson);

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-Authorization", PlayFabSettings::clientSessionTicket);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Client/RestoreIOSPurchases",
            headers,
            jsonAsString,
            OnRestoreIOSPurchasesResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<RestoreIOSPurchasesResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabClientAPI::OnRestoreIOSPurchasesResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        RestoreIOSPurchasesResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<RestoreIOSPurchasesResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabClientAPI::SendAccountRecoveryEmail(
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
        headers.emplace("", "");

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Client/SendAccountRecoveryEmail",
            headers,
            jsonAsString,
            OnSendAccountRecoveryEmailResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<SendAccountRecoveryEmailResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabClientAPI::OnSendAccountRecoveryEmailResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
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

    void PlayFabClientAPI::SetFriendTags(
        SetFriendTagsRequest& request,
        ProcessApiCallback<SetFriendTagsResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();

        Json::FastWriter writer;
        std::string jsonAsString = writer.write(requestJson);

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-Authorization", PlayFabSettings::clientSessionTicket);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Client/SetFriendTags",
            headers,
            jsonAsString,
            OnSetFriendTagsResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<SetFriendTagsResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabClientAPI::OnSetFriendTagsResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        SetFriendTagsResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<SetFriendTagsResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabClientAPI::SetPlayerSecret(
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
        headers.emplace("X-Authorization", PlayFabSettings::clientSessionTicket);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Client/SetPlayerSecret",
            headers,
            jsonAsString,
            OnSetPlayerSecretResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<SetPlayerSecretResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabClientAPI::OnSetPlayerSecretResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
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

    void PlayFabClientAPI::StartGame(
        StartGameRequest& request,
        ProcessApiCallback<StartGameResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();

        Json::FastWriter writer;
        std::string jsonAsString = writer.write(requestJson);

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-Authorization", PlayFabSettings::clientSessionTicket);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Client/StartGame",
            headers,
            jsonAsString,
            OnStartGameResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<StartGameResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabClientAPI::OnStartGameResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        StartGameResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<StartGameResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabClientAPI::StartPurchase(
        StartPurchaseRequest& request,
        ProcessApiCallback<StartPurchaseResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();

        Json::FastWriter writer;
        std::string jsonAsString = writer.write(requestJson);

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-Authorization", PlayFabSettings::clientSessionTicket);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Client/StartPurchase",
            headers,
            jsonAsString,
            OnStartPurchaseResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<StartPurchaseResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabClientAPI::OnStartPurchaseResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        StartPurchaseResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<StartPurchaseResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabClientAPI::SubtractUserVirtualCurrency(
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
        headers.emplace("X-Authorization", PlayFabSettings::clientSessionTicket);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Client/SubtractUserVirtualCurrency",
            headers,
            jsonAsString,
            OnSubtractUserVirtualCurrencyResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<ModifyUserVirtualCurrencyResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabClientAPI::OnSubtractUserVirtualCurrencyResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
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

    void PlayFabClientAPI::UnlinkAndroidDeviceID(
        UnlinkAndroidDeviceIDRequest& request,
        ProcessApiCallback<UnlinkAndroidDeviceIDResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();

        Json::FastWriter writer;
        std::string jsonAsString = writer.write(requestJson);

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-Authorization", PlayFabSettings::clientSessionTicket);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Client/UnlinkAndroidDeviceID",
            headers,
            jsonAsString,
            OnUnlinkAndroidDeviceIDResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<UnlinkAndroidDeviceIDResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabClientAPI::OnUnlinkAndroidDeviceIDResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        UnlinkAndroidDeviceIDResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<UnlinkAndroidDeviceIDResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabClientAPI::UnlinkCustomID(
        UnlinkCustomIDRequest& request,
        ProcessApiCallback<UnlinkCustomIDResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();

        Json::FastWriter writer;
        std::string jsonAsString = writer.write(requestJson);

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-Authorization", PlayFabSettings::clientSessionTicket);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Client/UnlinkCustomID",
            headers,
            jsonAsString,
            OnUnlinkCustomIDResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<UnlinkCustomIDResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabClientAPI::OnUnlinkCustomIDResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        UnlinkCustomIDResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<UnlinkCustomIDResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabClientAPI::UnlinkFacebookAccount(
        UnlinkFacebookAccountRequest& request,
        ProcessApiCallback<UnlinkFacebookAccountResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();

        Json::FastWriter writer;
        std::string jsonAsString = writer.write(requestJson);

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-Authorization", PlayFabSettings::clientSessionTicket);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Client/UnlinkFacebookAccount",
            headers,
            jsonAsString,
            OnUnlinkFacebookAccountResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<UnlinkFacebookAccountResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabClientAPI::OnUnlinkFacebookAccountResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        UnlinkFacebookAccountResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<UnlinkFacebookAccountResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabClientAPI::UnlinkFacebookInstantGamesId(
        UnlinkFacebookInstantGamesIdRequest& request,
        ProcessApiCallback<UnlinkFacebookInstantGamesIdResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();

        Json::FastWriter writer;
        std::string jsonAsString = writer.write(requestJson);

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-Authorization", PlayFabSettings::clientSessionTicket);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Client/UnlinkFacebookInstantGamesId",
            headers,
            jsonAsString,
            OnUnlinkFacebookInstantGamesIdResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<UnlinkFacebookInstantGamesIdResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabClientAPI::OnUnlinkFacebookInstantGamesIdResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        UnlinkFacebookInstantGamesIdResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<UnlinkFacebookInstantGamesIdResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabClientAPI::UnlinkGameCenterAccount(
        UnlinkGameCenterAccountRequest& request,
        ProcessApiCallback<UnlinkGameCenterAccountResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();

        Json::FastWriter writer;
        std::string jsonAsString = writer.write(requestJson);

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-Authorization", PlayFabSettings::clientSessionTicket);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Client/UnlinkGameCenterAccount",
            headers,
            jsonAsString,
            OnUnlinkGameCenterAccountResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<UnlinkGameCenterAccountResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabClientAPI::OnUnlinkGameCenterAccountResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        UnlinkGameCenterAccountResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<UnlinkGameCenterAccountResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabClientAPI::UnlinkGoogleAccount(
        UnlinkGoogleAccountRequest& request,
        ProcessApiCallback<UnlinkGoogleAccountResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();

        Json::FastWriter writer;
        std::string jsonAsString = writer.write(requestJson);

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-Authorization", PlayFabSettings::clientSessionTicket);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Client/UnlinkGoogleAccount",
            headers,
            jsonAsString,
            OnUnlinkGoogleAccountResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<UnlinkGoogleAccountResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabClientAPI::OnUnlinkGoogleAccountResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        UnlinkGoogleAccountResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<UnlinkGoogleAccountResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabClientAPI::UnlinkIOSDeviceID(
        UnlinkIOSDeviceIDRequest& request,
        ProcessApiCallback<UnlinkIOSDeviceIDResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();

        Json::FastWriter writer;
        std::string jsonAsString = writer.write(requestJson);

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-Authorization", PlayFabSettings::clientSessionTicket);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Client/UnlinkIOSDeviceID",
            headers,
            jsonAsString,
            OnUnlinkIOSDeviceIDResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<UnlinkIOSDeviceIDResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabClientAPI::OnUnlinkIOSDeviceIDResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        UnlinkIOSDeviceIDResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<UnlinkIOSDeviceIDResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabClientAPI::UnlinkKongregate(
        UnlinkKongregateAccountRequest& request,
        ProcessApiCallback<UnlinkKongregateAccountResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();

        Json::FastWriter writer;
        std::string jsonAsString = writer.write(requestJson);

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-Authorization", PlayFabSettings::clientSessionTicket);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Client/UnlinkKongregate",
            headers,
            jsonAsString,
            OnUnlinkKongregateResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<UnlinkKongregateAccountResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabClientAPI::OnUnlinkKongregateResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        UnlinkKongregateAccountResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<UnlinkKongregateAccountResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabClientAPI::UnlinkNintendoSwitchDeviceId(
        UnlinkNintendoSwitchDeviceIdRequest& request,
        ProcessApiCallback<UnlinkNintendoSwitchDeviceIdResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();

        Json::FastWriter writer;
        std::string jsonAsString = writer.write(requestJson);

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-Authorization", PlayFabSettings::clientSessionTicket);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Client/UnlinkNintendoSwitchDeviceId",
            headers,
            jsonAsString,
            OnUnlinkNintendoSwitchDeviceIdResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<UnlinkNintendoSwitchDeviceIdResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabClientAPI::OnUnlinkNintendoSwitchDeviceIdResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        UnlinkNintendoSwitchDeviceIdResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<UnlinkNintendoSwitchDeviceIdResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabClientAPI::UnlinkOpenIdConnect(
        UninkOpenIdConnectRequest& request,
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
        headers.emplace("X-Authorization", PlayFabSettings::clientSessionTicket);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Client/UnlinkOpenIdConnect",
            headers,
            jsonAsString,
            OnUnlinkOpenIdConnectResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<EmptyResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabClientAPI::OnUnlinkOpenIdConnectResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
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

    void PlayFabClientAPI::UnlinkSteamAccount(
        UnlinkSteamAccountRequest& request,
        ProcessApiCallback<UnlinkSteamAccountResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();

        Json::FastWriter writer;
        std::string jsonAsString = writer.write(requestJson);

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-Authorization", PlayFabSettings::clientSessionTicket);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Client/UnlinkSteamAccount",
            headers,
            jsonAsString,
            OnUnlinkSteamAccountResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<UnlinkSteamAccountResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabClientAPI::OnUnlinkSteamAccountResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        UnlinkSteamAccountResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<UnlinkSteamAccountResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabClientAPI::UnlinkTwitch(
        UnlinkTwitchAccountRequest& request,
        ProcessApiCallback<UnlinkTwitchAccountResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();

        Json::FastWriter writer;
        std::string jsonAsString = writer.write(requestJson);

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-Authorization", PlayFabSettings::clientSessionTicket);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Client/UnlinkTwitch",
            headers,
            jsonAsString,
            OnUnlinkTwitchResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<UnlinkTwitchAccountResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabClientAPI::OnUnlinkTwitchResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        UnlinkTwitchAccountResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<UnlinkTwitchAccountResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabClientAPI::UnlinkWindowsHello(
        UnlinkWindowsHelloAccountRequest& request,
        ProcessApiCallback<UnlinkWindowsHelloAccountResponse> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();

        Json::FastWriter writer;
        std::string jsonAsString = writer.write(requestJson);

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-Authorization", PlayFabSettings::clientSessionTicket);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Client/UnlinkWindowsHello",
            headers,
            jsonAsString,
            OnUnlinkWindowsHelloResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<UnlinkWindowsHelloAccountResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabClientAPI::OnUnlinkWindowsHelloResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        UnlinkWindowsHelloAccountResponse outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<UnlinkWindowsHelloAccountResponse> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabClientAPI::UnlinkXboxAccount(
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
        headers.emplace("X-Authorization", PlayFabSettings::clientSessionTicket);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Client/UnlinkXboxAccount",
            headers,
            jsonAsString,
            OnUnlinkXboxAccountResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<UnlinkXboxAccountResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabClientAPI::OnUnlinkXboxAccountResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
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

    void PlayFabClientAPI::UnlockContainerInstance(
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
        headers.emplace("X-Authorization", PlayFabSettings::clientSessionTicket);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Client/UnlockContainerInstance",
            headers,
            jsonAsString,
            OnUnlockContainerInstanceResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<UnlockContainerItemResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabClientAPI::OnUnlockContainerInstanceResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
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

    void PlayFabClientAPI::UnlockContainerItem(
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
        headers.emplace("X-Authorization", PlayFabSettings::clientSessionTicket);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Client/UnlockContainerItem",
            headers,
            jsonAsString,
            OnUnlockContainerItemResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<UnlockContainerItemResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabClientAPI::OnUnlockContainerItemResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
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

    void PlayFabClientAPI::UpdateAvatarUrl(
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
        headers.emplace("X-Authorization", PlayFabSettings::clientSessionTicket);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Client/UpdateAvatarUrl",
            headers,
            jsonAsString,
            OnUpdateAvatarUrlResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<EmptyResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabClientAPI::OnUpdateAvatarUrlResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
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

    void PlayFabClientAPI::UpdateCharacterData(
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
        headers.emplace("X-Authorization", PlayFabSettings::clientSessionTicket);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Client/UpdateCharacterData",
            headers,
            jsonAsString,
            OnUpdateCharacterDataResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<UpdateCharacterDataResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabClientAPI::OnUpdateCharacterDataResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
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

    void PlayFabClientAPI::UpdateCharacterStatistics(
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
        headers.emplace("X-Authorization", PlayFabSettings::clientSessionTicket);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Client/UpdateCharacterStatistics",
            headers,
            jsonAsString,
            OnUpdateCharacterStatisticsResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<UpdateCharacterStatisticsResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabClientAPI::OnUpdateCharacterStatisticsResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
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

    void PlayFabClientAPI::UpdatePlayerStatistics(
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
        headers.emplace("X-Authorization", PlayFabSettings::clientSessionTicket);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Client/UpdatePlayerStatistics",
            headers,
            jsonAsString,
            OnUpdatePlayerStatisticsResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<UpdatePlayerStatisticsResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabClientAPI::OnUpdatePlayerStatisticsResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
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

    void PlayFabClientAPI::UpdateSharedGroupData(
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
        headers.emplace("X-Authorization", PlayFabSettings::clientSessionTicket);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Client/UpdateSharedGroupData",
            headers,
            jsonAsString,
            OnUpdateSharedGroupDataResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<UpdateSharedGroupDataResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabClientAPI::OnUpdateSharedGroupDataResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
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

    void PlayFabClientAPI::UpdateUserData(
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
        headers.emplace("X-Authorization", PlayFabSettings::clientSessionTicket);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Client/UpdateUserData",
            headers,
            jsonAsString,
            OnUpdateUserDataResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<UpdateUserDataResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabClientAPI::OnUpdateUserDataResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
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

    void PlayFabClientAPI::UpdateUserPublisherData(
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
        headers.emplace("X-Authorization", PlayFabSettings::clientSessionTicket);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Client/UpdateUserPublisherData",
            headers,
            jsonAsString,
            OnUpdateUserPublisherDataResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<UpdateUserDataResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabClientAPI::OnUpdateUserPublisherDataResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
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

    void PlayFabClientAPI::UpdateUserTitleDisplayName(
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
        headers.emplace("X-Authorization", PlayFabSettings::clientSessionTicket);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Client/UpdateUserTitleDisplayName",
            headers,
            jsonAsString,
            OnUpdateUserTitleDisplayNameResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<UpdateUserTitleDisplayNameResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabClientAPI::OnUpdateUserTitleDisplayNameResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
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

    void PlayFabClientAPI::ValidateAmazonIAPReceipt(
        ValidateAmazonReceiptRequest& request,
        ProcessApiCallback<ValidateAmazonReceiptResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();

        Json::FastWriter writer;
        std::string jsonAsString = writer.write(requestJson);

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-Authorization", PlayFabSettings::clientSessionTicket);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Client/ValidateAmazonIAPReceipt",
            headers,
            jsonAsString,
            OnValidateAmazonIAPReceiptResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<ValidateAmazonReceiptResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabClientAPI::OnValidateAmazonIAPReceiptResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        ValidateAmazonReceiptResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<ValidateAmazonReceiptResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabClientAPI::ValidateGooglePlayPurchase(
        ValidateGooglePlayPurchaseRequest& request,
        ProcessApiCallback<ValidateGooglePlayPurchaseResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();

        Json::FastWriter writer;
        std::string jsonAsString = writer.write(requestJson);

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-Authorization", PlayFabSettings::clientSessionTicket);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Client/ValidateGooglePlayPurchase",
            headers,
            jsonAsString,
            OnValidateGooglePlayPurchaseResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<ValidateGooglePlayPurchaseResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabClientAPI::OnValidateGooglePlayPurchaseResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        ValidateGooglePlayPurchaseResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<ValidateGooglePlayPurchaseResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabClientAPI::ValidateIOSReceipt(
        ValidateIOSReceiptRequest& request,
        ProcessApiCallback<ValidateIOSReceiptResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();

        Json::FastWriter writer;
        std::string jsonAsString = writer.write(requestJson);

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-Authorization", PlayFabSettings::clientSessionTicket);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Client/ValidateIOSReceipt",
            headers,
            jsonAsString,
            OnValidateIOSReceiptResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<ValidateIOSReceiptResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabClientAPI::OnValidateIOSReceiptResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        ValidateIOSReceiptResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<ValidateIOSReceiptResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabClientAPI::ValidateWindowsStoreReceipt(
        ValidateWindowsReceiptRequest& request,
        ProcessApiCallback<ValidateWindowsReceiptResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();

        Json::FastWriter writer;
        std::string jsonAsString = writer.write(requestJson);

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-Authorization", PlayFabSettings::clientSessionTicket);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Client/ValidateWindowsStoreReceipt",
            headers,
            jsonAsString,
            OnValidateWindowsStoreReceiptResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<ValidateWindowsReceiptResult>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabClientAPI::OnValidateWindowsStoreReceiptResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        ValidateWindowsReceiptResult outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<ValidateWindowsReceiptResult> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabClientAPI::WriteCharacterEvent(
        WriteClientCharacterEventRequest& request,
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
        headers.emplace("X-Authorization", PlayFabSettings::clientSessionTicket);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Client/WriteCharacterEvent",
            headers,
            jsonAsString,
            OnWriteCharacterEventResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<WriteEventResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabClientAPI::OnWriteCharacterEventResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
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

    void PlayFabClientAPI::WritePlayerEvent(
        WriteClientPlayerEventRequest& request,
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
        headers.emplace("X-Authorization", PlayFabSettings::clientSessionTicket);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Client/WritePlayerEvent",
            headers,
            jsonAsString,
            OnWritePlayerEventResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<WriteEventResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabClientAPI::OnWritePlayerEventResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
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

    void PlayFabClientAPI::WriteTitleEvent(
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
        headers.emplace("X-Authorization", PlayFabSettings::clientSessionTicket);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Client/WriteTitleEvent",
            headers,
            jsonAsString,
            OnWriteTitleEventResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<WriteEventResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabClientAPI::OnWriteTitleEventResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
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

    // Private PlayFabClientAPI specific
    bool PlayFabClientAPI::IsClientLoggedIn()
    {
        return !PlayFabSettings::clientSessionTicket.empty();
    }

    void PlayFabClientAPI::MultiStepClientLogin(bool needsAttribution)
    {
        if (needsAttribution && !PlayFabSettings::disableAdvertising && PlayFabSettings::advertisingIdType.length() > 0 && PlayFabSettings::advertisingIdValue.length() > 0)
        {
            AttributeInstallRequest request;
            if (PlayFabSettings::advertisingIdType == PlayFabSettings::AD_TYPE_IDFA)
                request.Idfa = PlayFabSettings::advertisingIdValue;
            else if (PlayFabSettings::advertisingIdType == PlayFabSettings::AD_TYPE_ANDROID_ID)
                request.Adid = PlayFabSettings::advertisingIdValue;
            else
                return;
            AttributeInstall(request, nullptr, nullptr);
        }
    }

    bool PlayFabClientAPI::ValidateResult(PlayFabResultCommon& resultCommon, CallRequestContainer& container)
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
