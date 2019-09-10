
#ifndef DISABLE_PLAYFABCLIENT_API

#include "playfab/PlayFabClientApi.h"
#include "playfab/PlayFabHttp.h"
#include "playfab/PlayFabSettings.h"

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

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Client/AcceptTrade", L"X-Authorization", PlayFabSettings::clientSessionTicket, requestJson, OnAcceptTradeResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<AcceptTradeResponse>(callback)), errorCallback, customData);
    }

    void PlayFabClientAPI::OnAcceptTradeResult(CallRequestContainer& request)
    {
        AcceptTradeResponse outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<AcceptTradeResponse> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabClientAPI::AddFriend(
        AddFriendRequest& request,
        ProcessApiCallback<AddFriendResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Client/AddFriend", L"X-Authorization", PlayFabSettings::clientSessionTicket, requestJson, OnAddFriendResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<AddFriendResult>(callback)), errorCallback, customData);
    }

    void PlayFabClientAPI::OnAddFriendResult(CallRequestContainer& request)
    {
        AddFriendResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<AddFriendResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabClientAPI::AddGenericID(
        AddGenericIDRequest& request,
        ProcessApiCallback<AddGenericIDResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Client/AddGenericID", L"X-Authorization", PlayFabSettings::clientSessionTicket, requestJson, OnAddGenericIDResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<AddGenericIDResult>(callback)), errorCallback, customData);
    }

    void PlayFabClientAPI::OnAddGenericIDResult(CallRequestContainer& request)
    {
        AddGenericIDResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<AddGenericIDResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabClientAPI::AddOrUpdateContactEmail(
        AddOrUpdateContactEmailRequest& request,
        ProcessApiCallback<AddOrUpdateContactEmailResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Client/AddOrUpdateContactEmail", L"X-Authorization", PlayFabSettings::clientSessionTicket, requestJson, OnAddOrUpdateContactEmailResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<AddOrUpdateContactEmailResult>(callback)), errorCallback, customData);
    }

    void PlayFabClientAPI::OnAddOrUpdateContactEmailResult(CallRequestContainer& request)
    {
        AddOrUpdateContactEmailResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<AddOrUpdateContactEmailResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabClientAPI::AddSharedGroupMembers(
        AddSharedGroupMembersRequest& request,
        ProcessApiCallback<AddSharedGroupMembersResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Client/AddSharedGroupMembers", L"X-Authorization", PlayFabSettings::clientSessionTicket, requestJson, OnAddSharedGroupMembersResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<AddSharedGroupMembersResult>(callback)), errorCallback, customData);
    }

    void PlayFabClientAPI::OnAddSharedGroupMembersResult(CallRequestContainer& request)
    {
        AddSharedGroupMembersResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<AddSharedGroupMembersResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabClientAPI::AddUsernamePassword(
        AddUsernamePasswordRequest& request,
        ProcessApiCallback<AddUsernamePasswordResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Client/AddUsernamePassword", L"X-Authorization", PlayFabSettings::clientSessionTicket, requestJson, OnAddUsernamePasswordResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<AddUsernamePasswordResult>(callback)), errorCallback, customData);
    }

    void PlayFabClientAPI::OnAddUsernamePasswordResult(CallRequestContainer& request)
    {
        AddUsernamePasswordResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<AddUsernamePasswordResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabClientAPI::AddUserVirtualCurrency(
        AddUserVirtualCurrencyRequest& request,
        ProcessApiCallback<ModifyUserVirtualCurrencyResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Client/AddUserVirtualCurrency", L"X-Authorization", PlayFabSettings::clientSessionTicket, requestJson, OnAddUserVirtualCurrencyResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<ModifyUserVirtualCurrencyResult>(callback)), errorCallback, customData);
    }

    void PlayFabClientAPI::OnAddUserVirtualCurrencyResult(CallRequestContainer& request)
    {
        ModifyUserVirtualCurrencyResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<ModifyUserVirtualCurrencyResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabClientAPI::AndroidDevicePushNotificationRegistration(
        AndroidDevicePushNotificationRegistrationRequest& request,
        ProcessApiCallback<AndroidDevicePushNotificationRegistrationResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Client/AndroidDevicePushNotificationRegistration", L"X-Authorization", PlayFabSettings::clientSessionTicket, requestJson, OnAndroidDevicePushNotificationRegistrationResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<AndroidDevicePushNotificationRegistrationResult>(callback)), errorCallback, customData);
    }

    void PlayFabClientAPI::OnAndroidDevicePushNotificationRegistrationResult(CallRequestContainer& request)
    {
        AndroidDevicePushNotificationRegistrationResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<AndroidDevicePushNotificationRegistrationResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabClientAPI::AttributeInstall(
        AttributeInstallRequest& request,
        ProcessApiCallback<AttributeInstallResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Client/AttributeInstall", L"X-Authorization", PlayFabSettings::clientSessionTicket, requestJson, OnAttributeInstallResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<AttributeInstallResult>(callback)), errorCallback, customData);
    }

    void PlayFabClientAPI::OnAttributeInstallResult(CallRequestContainer& request)
    {
        AttributeInstallResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;
        PlayFabSettings::advertisingIdType += L"_Successful";

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<AttributeInstallResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabClientAPI::CancelTrade(
        CancelTradeRequest& request,
        ProcessApiCallback<CancelTradeResponse> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Client/CancelTrade", L"X-Authorization", PlayFabSettings::clientSessionTicket, requestJson, OnCancelTradeResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<CancelTradeResponse>(callback)), errorCallback, customData);
    }

    void PlayFabClientAPI::OnCancelTradeResult(CallRequestContainer& request)
    {
        CancelTradeResponse outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<CancelTradeResponse> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabClientAPI::ConfirmPurchase(
        ConfirmPurchaseRequest& request,
        ProcessApiCallback<ConfirmPurchaseResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Client/ConfirmPurchase", L"X-Authorization", PlayFabSettings::clientSessionTicket, requestJson, OnConfirmPurchaseResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<ConfirmPurchaseResult>(callback)), errorCallback, customData);
    }

    void PlayFabClientAPI::OnConfirmPurchaseResult(CallRequestContainer& request)
    {
        ConfirmPurchaseResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<ConfirmPurchaseResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabClientAPI::ConsumeItem(
        ConsumeItemRequest& request,
        ProcessApiCallback<ConsumeItemResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Client/ConsumeItem", L"X-Authorization", PlayFabSettings::clientSessionTicket, requestJson, OnConsumeItemResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<ConsumeItemResult>(callback)), errorCallback, customData);
    }

    void PlayFabClientAPI::OnConsumeItemResult(CallRequestContainer& request)
    {
        ConsumeItemResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<ConsumeItemResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabClientAPI::ConsumeXboxEntitlements(
        ConsumeXboxEntitlementsRequest& request,
        ProcessApiCallback<ConsumeXboxEntitlementsResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Client/ConsumeXboxEntitlements", L"X-Authorization", PlayFabSettings::clientSessionTicket, requestJson, OnConsumeXboxEntitlementsResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<ConsumeXboxEntitlementsResult>(callback)), errorCallback, customData);
    }

    void PlayFabClientAPI::OnConsumeXboxEntitlementsResult(CallRequestContainer& request)
    {
        ConsumeXboxEntitlementsResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<ConsumeXboxEntitlementsResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabClientAPI::CreateSharedGroup(
        CreateSharedGroupRequest& request,
        ProcessApiCallback<CreateSharedGroupResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Client/CreateSharedGroup", L"X-Authorization", PlayFabSettings::clientSessionTicket, requestJson, OnCreateSharedGroupResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<CreateSharedGroupResult>(callback)), errorCallback, customData);
    }

    void PlayFabClientAPI::OnCreateSharedGroupResult(CallRequestContainer& request)
    {
        CreateSharedGroupResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<CreateSharedGroupResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabClientAPI::ExecuteCloudScript(
        ExecuteCloudScriptRequest& request,
        ProcessApiCallback<ExecuteCloudScriptResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Client/ExecuteCloudScript", L"X-Authorization", PlayFabSettings::clientSessionTicket, requestJson, OnExecuteCloudScriptResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<ExecuteCloudScriptResult>(callback)), errorCallback, customData);
    }

    void PlayFabClientAPI::OnExecuteCloudScriptResult(CallRequestContainer& request)
    {
        ExecuteCloudScriptResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<ExecuteCloudScriptResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabClientAPI::GetAccountInfo(
        GetAccountInfoRequest& request,
        ProcessApiCallback<GetAccountInfoResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Client/GetAccountInfo", L"X-Authorization", PlayFabSettings::clientSessionTicket, requestJson, OnGetAccountInfoResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetAccountInfoResult>(callback)), errorCallback, customData);
    }

    void PlayFabClientAPI::OnGetAccountInfoResult(CallRequestContainer& request)
    {
        GetAccountInfoResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<GetAccountInfoResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabClientAPI::GetAllUsersCharacters(
        ListUsersCharactersRequest& request,
        ProcessApiCallback<ListUsersCharactersResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Client/GetAllUsersCharacters", L"X-Authorization", PlayFabSettings::clientSessionTicket, requestJson, OnGetAllUsersCharactersResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<ListUsersCharactersResult>(callback)), errorCallback, customData);
    }

    void PlayFabClientAPI::OnGetAllUsersCharactersResult(CallRequestContainer& request)
    {
        ListUsersCharactersResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<ListUsersCharactersResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabClientAPI::GetCatalogItems(
        GetCatalogItemsRequest& request,
        ProcessApiCallback<GetCatalogItemsResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Client/GetCatalogItems", L"X-Authorization", PlayFabSettings::clientSessionTicket, requestJson, OnGetCatalogItemsResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetCatalogItemsResult>(callback)), errorCallback, customData);
    }

    void PlayFabClientAPI::OnGetCatalogItemsResult(CallRequestContainer& request)
    {
        GetCatalogItemsResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<GetCatalogItemsResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabClientAPI::GetCharacterData(
        GetCharacterDataRequest& request,
        ProcessApiCallback<GetCharacterDataResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Client/GetCharacterData", L"X-Authorization", PlayFabSettings::clientSessionTicket, requestJson, OnGetCharacterDataResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetCharacterDataResult>(callback)), errorCallback, customData);
    }

    void PlayFabClientAPI::OnGetCharacterDataResult(CallRequestContainer& request)
    {
        GetCharacterDataResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<GetCharacterDataResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabClientAPI::GetCharacterInventory(
        GetCharacterInventoryRequest& request,
        ProcessApiCallback<GetCharacterInventoryResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Client/GetCharacterInventory", L"X-Authorization", PlayFabSettings::clientSessionTicket, requestJson, OnGetCharacterInventoryResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetCharacterInventoryResult>(callback)), errorCallback, customData);
    }

    void PlayFabClientAPI::OnGetCharacterInventoryResult(CallRequestContainer& request)
    {
        GetCharacterInventoryResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<GetCharacterInventoryResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabClientAPI::GetCharacterLeaderboard(
        GetCharacterLeaderboardRequest& request,
        ProcessApiCallback<GetCharacterLeaderboardResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Client/GetCharacterLeaderboard", L"X-Authorization", PlayFabSettings::clientSessionTicket, requestJson, OnGetCharacterLeaderboardResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetCharacterLeaderboardResult>(callback)), errorCallback, customData);
    }

    void PlayFabClientAPI::OnGetCharacterLeaderboardResult(CallRequestContainer& request)
    {
        GetCharacterLeaderboardResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<GetCharacterLeaderboardResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabClientAPI::GetCharacterReadOnlyData(
        GetCharacterDataRequest& request,
        ProcessApiCallback<GetCharacterDataResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Client/GetCharacterReadOnlyData", L"X-Authorization", PlayFabSettings::clientSessionTicket, requestJson, OnGetCharacterReadOnlyDataResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetCharacterDataResult>(callback)), errorCallback, customData);
    }

    void PlayFabClientAPI::OnGetCharacterReadOnlyDataResult(CallRequestContainer& request)
    {
        GetCharacterDataResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<GetCharacterDataResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabClientAPI::GetCharacterStatistics(
        GetCharacterStatisticsRequest& request,
        ProcessApiCallback<GetCharacterStatisticsResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Client/GetCharacterStatistics", L"X-Authorization", PlayFabSettings::clientSessionTicket, requestJson, OnGetCharacterStatisticsResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetCharacterStatisticsResult>(callback)), errorCallback, customData);
    }

    void PlayFabClientAPI::OnGetCharacterStatisticsResult(CallRequestContainer& request)
    {
        GetCharacterStatisticsResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<GetCharacterStatisticsResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabClientAPI::GetContentDownloadUrl(
        GetContentDownloadUrlRequest& request,
        ProcessApiCallback<GetContentDownloadUrlResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Client/GetContentDownloadUrl", L"X-Authorization", PlayFabSettings::clientSessionTicket, requestJson, OnGetContentDownloadUrlResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetContentDownloadUrlResult>(callback)), errorCallback, customData);
    }

    void PlayFabClientAPI::OnGetContentDownloadUrlResult(CallRequestContainer& request)
    {
        GetContentDownloadUrlResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<GetContentDownloadUrlResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabClientAPI::GetCurrentGames(
        CurrentGamesRequest& request,
        ProcessApiCallback<CurrentGamesResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Client/GetCurrentGames", L"X-Authorization", PlayFabSettings::clientSessionTicket, requestJson, OnGetCurrentGamesResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<CurrentGamesResult>(callback)), errorCallback, customData);
    }

    void PlayFabClientAPI::OnGetCurrentGamesResult(CallRequestContainer& request)
    {
        CurrentGamesResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<CurrentGamesResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabClientAPI::GetFriendLeaderboard(
        GetFriendLeaderboardRequest& request,
        ProcessApiCallback<GetLeaderboardResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Client/GetFriendLeaderboard", L"X-Authorization", PlayFabSettings::clientSessionTicket, requestJson, OnGetFriendLeaderboardResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetLeaderboardResult>(callback)), errorCallback, customData);
    }

    void PlayFabClientAPI::OnGetFriendLeaderboardResult(CallRequestContainer& request)
    {
        GetLeaderboardResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<GetLeaderboardResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabClientAPI::GetFriendLeaderboardAroundPlayer(
        GetFriendLeaderboardAroundPlayerRequest& request,
        ProcessApiCallback<GetFriendLeaderboardAroundPlayerResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Client/GetFriendLeaderboardAroundPlayer", L"X-Authorization", PlayFabSettings::clientSessionTicket, requestJson, OnGetFriendLeaderboardAroundPlayerResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetFriendLeaderboardAroundPlayerResult>(callback)), errorCallback, customData);
    }

    void PlayFabClientAPI::OnGetFriendLeaderboardAroundPlayerResult(CallRequestContainer& request)
    {
        GetFriendLeaderboardAroundPlayerResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<GetFriendLeaderboardAroundPlayerResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabClientAPI::GetFriendsList(
        GetFriendsListRequest& request,
        ProcessApiCallback<GetFriendsListResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Client/GetFriendsList", L"X-Authorization", PlayFabSettings::clientSessionTicket, requestJson, OnGetFriendsListResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetFriendsListResult>(callback)), errorCallback, customData);
    }

    void PlayFabClientAPI::OnGetFriendsListResult(CallRequestContainer& request)
    {
        GetFriendsListResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<GetFriendsListResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabClientAPI::GetGameServerRegions(
        GameServerRegionsRequest& request,
        ProcessApiCallback<GameServerRegionsResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Client/GetGameServerRegions", L"X-Authorization", PlayFabSettings::clientSessionTicket, requestJson, OnGetGameServerRegionsResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GameServerRegionsResult>(callback)), errorCallback, customData);
    }

    void PlayFabClientAPI::OnGetGameServerRegionsResult(CallRequestContainer& request)
    {
        GameServerRegionsResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<GameServerRegionsResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabClientAPI::GetLeaderboard(
        GetLeaderboardRequest& request,
        ProcessApiCallback<GetLeaderboardResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Client/GetLeaderboard", L"X-Authorization", PlayFabSettings::clientSessionTicket, requestJson, OnGetLeaderboardResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetLeaderboardResult>(callback)), errorCallback, customData);
    }

    void PlayFabClientAPI::OnGetLeaderboardResult(CallRequestContainer& request)
    {
        GetLeaderboardResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<GetLeaderboardResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabClientAPI::GetLeaderboardAroundCharacter(
        GetLeaderboardAroundCharacterRequest& request,
        ProcessApiCallback<GetLeaderboardAroundCharacterResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Client/GetLeaderboardAroundCharacter", L"X-Authorization", PlayFabSettings::clientSessionTicket, requestJson, OnGetLeaderboardAroundCharacterResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetLeaderboardAroundCharacterResult>(callback)), errorCallback, customData);
    }

    void PlayFabClientAPI::OnGetLeaderboardAroundCharacterResult(CallRequestContainer& request)
    {
        GetLeaderboardAroundCharacterResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<GetLeaderboardAroundCharacterResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabClientAPI::GetLeaderboardAroundPlayer(
        GetLeaderboardAroundPlayerRequest& request,
        ProcessApiCallback<GetLeaderboardAroundPlayerResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Client/GetLeaderboardAroundPlayer", L"X-Authorization", PlayFabSettings::clientSessionTicket, requestJson, OnGetLeaderboardAroundPlayerResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetLeaderboardAroundPlayerResult>(callback)), errorCallback, customData);
    }

    void PlayFabClientAPI::OnGetLeaderboardAroundPlayerResult(CallRequestContainer& request)
    {
        GetLeaderboardAroundPlayerResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<GetLeaderboardAroundPlayerResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabClientAPI::GetLeaderboardForUserCharacters(
        GetLeaderboardForUsersCharactersRequest& request,
        ProcessApiCallback<GetLeaderboardForUsersCharactersResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Client/GetLeaderboardForUserCharacters", L"X-Authorization", PlayFabSettings::clientSessionTicket, requestJson, OnGetLeaderboardForUserCharactersResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetLeaderboardForUsersCharactersResult>(callback)), errorCallback, customData);
    }

    void PlayFabClientAPI::OnGetLeaderboardForUserCharactersResult(CallRequestContainer& request)
    {
        GetLeaderboardForUsersCharactersResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<GetLeaderboardForUsersCharactersResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabClientAPI::GetPaymentToken(
        GetPaymentTokenRequest& request,
        ProcessApiCallback<GetPaymentTokenResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Client/GetPaymentToken", L"X-Authorization", PlayFabSettings::clientSessionTicket, requestJson, OnGetPaymentTokenResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetPaymentTokenResult>(callback)), errorCallback, customData);
    }

    void PlayFabClientAPI::OnGetPaymentTokenResult(CallRequestContainer& request)
    {
        GetPaymentTokenResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<GetPaymentTokenResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabClientAPI::GetPhotonAuthenticationToken(
        GetPhotonAuthenticationTokenRequest& request,
        ProcessApiCallback<GetPhotonAuthenticationTokenResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Client/GetPhotonAuthenticationToken", L"X-Authorization", PlayFabSettings::clientSessionTicket, requestJson, OnGetPhotonAuthenticationTokenResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetPhotonAuthenticationTokenResult>(callback)), errorCallback, customData);
    }

    void PlayFabClientAPI::OnGetPhotonAuthenticationTokenResult(CallRequestContainer& request)
    {
        GetPhotonAuthenticationTokenResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<GetPhotonAuthenticationTokenResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabClientAPI::GetPlayerCombinedInfo(
        GetPlayerCombinedInfoRequest& request,
        ProcessApiCallback<GetPlayerCombinedInfoResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Client/GetPlayerCombinedInfo", L"X-Authorization", PlayFabSettings::clientSessionTicket, requestJson, OnGetPlayerCombinedInfoResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetPlayerCombinedInfoResult>(callback)), errorCallback, customData);
    }

    void PlayFabClientAPI::OnGetPlayerCombinedInfoResult(CallRequestContainer& request)
    {
        GetPlayerCombinedInfoResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<GetPlayerCombinedInfoResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabClientAPI::GetPlayerProfile(
        GetPlayerProfileRequest& request,
        ProcessApiCallback<GetPlayerProfileResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Client/GetPlayerProfile", L"X-Authorization", PlayFabSettings::clientSessionTicket, requestJson, OnGetPlayerProfileResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetPlayerProfileResult>(callback)), errorCallback, customData);
    }

    void PlayFabClientAPI::OnGetPlayerProfileResult(CallRequestContainer& request)
    {
        GetPlayerProfileResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<GetPlayerProfileResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabClientAPI::GetPlayerSegments(
        GetPlayerSegmentsRequest& request,
        ProcessApiCallback<GetPlayerSegmentsResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Client/GetPlayerSegments", L"X-Authorization", PlayFabSettings::clientSessionTicket, requestJson, OnGetPlayerSegmentsResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetPlayerSegmentsResult>(callback)), errorCallback, customData);
    }

    void PlayFabClientAPI::OnGetPlayerSegmentsResult(CallRequestContainer& request)
    {
        GetPlayerSegmentsResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<GetPlayerSegmentsResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabClientAPI::GetPlayerStatistics(
        GetPlayerStatisticsRequest& request,
        ProcessApiCallback<GetPlayerStatisticsResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Client/GetPlayerStatistics", L"X-Authorization", PlayFabSettings::clientSessionTicket, requestJson, OnGetPlayerStatisticsResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetPlayerStatisticsResult>(callback)), errorCallback, customData);
    }

    void PlayFabClientAPI::OnGetPlayerStatisticsResult(CallRequestContainer& request)
    {
        GetPlayerStatisticsResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<GetPlayerStatisticsResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabClientAPI::GetPlayerStatisticVersions(
        GetPlayerStatisticVersionsRequest& request,
        ProcessApiCallback<GetPlayerStatisticVersionsResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Client/GetPlayerStatisticVersions", L"X-Authorization", PlayFabSettings::clientSessionTicket, requestJson, OnGetPlayerStatisticVersionsResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetPlayerStatisticVersionsResult>(callback)), errorCallback, customData);
    }

    void PlayFabClientAPI::OnGetPlayerStatisticVersionsResult(CallRequestContainer& request)
    {
        GetPlayerStatisticVersionsResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<GetPlayerStatisticVersionsResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabClientAPI::GetPlayerTags(
        GetPlayerTagsRequest& request,
        ProcessApiCallback<GetPlayerTagsResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Client/GetPlayerTags", L"X-Authorization", PlayFabSettings::clientSessionTicket, requestJson, OnGetPlayerTagsResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetPlayerTagsResult>(callback)), errorCallback, customData);
    }

    void PlayFabClientAPI::OnGetPlayerTagsResult(CallRequestContainer& request)
    {
        GetPlayerTagsResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<GetPlayerTagsResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabClientAPI::GetPlayerTrades(
        GetPlayerTradesRequest& request,
        ProcessApiCallback<GetPlayerTradesResponse> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Client/GetPlayerTrades", L"X-Authorization", PlayFabSettings::clientSessionTicket, requestJson, OnGetPlayerTradesResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetPlayerTradesResponse>(callback)), errorCallback, customData);
    }

    void PlayFabClientAPI::OnGetPlayerTradesResult(CallRequestContainer& request)
    {
        GetPlayerTradesResponse outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<GetPlayerTradesResponse> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabClientAPI::GetPlayFabIDsFromFacebookIDs(
        GetPlayFabIDsFromFacebookIDsRequest& request,
        ProcessApiCallback<GetPlayFabIDsFromFacebookIDsResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Client/GetPlayFabIDsFromFacebookIDs", L"X-Authorization", PlayFabSettings::clientSessionTicket, requestJson, OnGetPlayFabIDsFromFacebookIDsResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetPlayFabIDsFromFacebookIDsResult>(callback)), errorCallback, customData);
    }

    void PlayFabClientAPI::OnGetPlayFabIDsFromFacebookIDsResult(CallRequestContainer& request)
    {
        GetPlayFabIDsFromFacebookIDsResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<GetPlayFabIDsFromFacebookIDsResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabClientAPI::GetPlayFabIDsFromFacebookInstantGamesIds(
        GetPlayFabIDsFromFacebookInstantGamesIdsRequest& request,
        ProcessApiCallback<GetPlayFabIDsFromFacebookInstantGamesIdsResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Client/GetPlayFabIDsFromFacebookInstantGamesIds", L"X-Authorization", PlayFabSettings::clientSessionTicket, requestJson, OnGetPlayFabIDsFromFacebookInstantGamesIdsResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetPlayFabIDsFromFacebookInstantGamesIdsResult>(callback)), errorCallback, customData);
    }

    void PlayFabClientAPI::OnGetPlayFabIDsFromFacebookInstantGamesIdsResult(CallRequestContainer& request)
    {
        GetPlayFabIDsFromFacebookInstantGamesIdsResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<GetPlayFabIDsFromFacebookInstantGamesIdsResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabClientAPI::GetPlayFabIDsFromGameCenterIDs(
        GetPlayFabIDsFromGameCenterIDsRequest& request,
        ProcessApiCallback<GetPlayFabIDsFromGameCenterIDsResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Client/GetPlayFabIDsFromGameCenterIDs", L"X-Authorization", PlayFabSettings::clientSessionTicket, requestJson, OnGetPlayFabIDsFromGameCenterIDsResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetPlayFabIDsFromGameCenterIDsResult>(callback)), errorCallback, customData);
    }

    void PlayFabClientAPI::OnGetPlayFabIDsFromGameCenterIDsResult(CallRequestContainer& request)
    {
        GetPlayFabIDsFromGameCenterIDsResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<GetPlayFabIDsFromGameCenterIDsResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabClientAPI::GetPlayFabIDsFromGenericIDs(
        GetPlayFabIDsFromGenericIDsRequest& request,
        ProcessApiCallback<GetPlayFabIDsFromGenericIDsResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Client/GetPlayFabIDsFromGenericIDs", L"X-Authorization", PlayFabSettings::clientSessionTicket, requestJson, OnGetPlayFabIDsFromGenericIDsResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetPlayFabIDsFromGenericIDsResult>(callback)), errorCallback, customData);
    }

    void PlayFabClientAPI::OnGetPlayFabIDsFromGenericIDsResult(CallRequestContainer& request)
    {
        GetPlayFabIDsFromGenericIDsResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<GetPlayFabIDsFromGenericIDsResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabClientAPI::GetPlayFabIDsFromGoogleIDs(
        GetPlayFabIDsFromGoogleIDsRequest& request,
        ProcessApiCallback<GetPlayFabIDsFromGoogleIDsResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Client/GetPlayFabIDsFromGoogleIDs", L"X-Authorization", PlayFabSettings::clientSessionTicket, requestJson, OnGetPlayFabIDsFromGoogleIDsResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetPlayFabIDsFromGoogleIDsResult>(callback)), errorCallback, customData);
    }

    void PlayFabClientAPI::OnGetPlayFabIDsFromGoogleIDsResult(CallRequestContainer& request)
    {
        GetPlayFabIDsFromGoogleIDsResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<GetPlayFabIDsFromGoogleIDsResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabClientAPI::GetPlayFabIDsFromKongregateIDs(
        GetPlayFabIDsFromKongregateIDsRequest& request,
        ProcessApiCallback<GetPlayFabIDsFromKongregateIDsResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Client/GetPlayFabIDsFromKongregateIDs", L"X-Authorization", PlayFabSettings::clientSessionTicket, requestJson, OnGetPlayFabIDsFromKongregateIDsResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetPlayFabIDsFromKongregateIDsResult>(callback)), errorCallback, customData);
    }

    void PlayFabClientAPI::OnGetPlayFabIDsFromKongregateIDsResult(CallRequestContainer& request)
    {
        GetPlayFabIDsFromKongregateIDsResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<GetPlayFabIDsFromKongregateIDsResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabClientAPI::GetPlayFabIDsFromNintendoSwitchDeviceIds(
        GetPlayFabIDsFromNintendoSwitchDeviceIdsRequest& request,
        ProcessApiCallback<GetPlayFabIDsFromNintendoSwitchDeviceIdsResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Client/GetPlayFabIDsFromNintendoSwitchDeviceIds", L"X-Authorization", PlayFabSettings::clientSessionTicket, requestJson, OnGetPlayFabIDsFromNintendoSwitchDeviceIdsResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetPlayFabIDsFromNintendoSwitchDeviceIdsResult>(callback)), errorCallback, customData);
    }

    void PlayFabClientAPI::OnGetPlayFabIDsFromNintendoSwitchDeviceIdsResult(CallRequestContainer& request)
    {
        GetPlayFabIDsFromNintendoSwitchDeviceIdsResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<GetPlayFabIDsFromNintendoSwitchDeviceIdsResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabClientAPI::GetPlayFabIDsFromSteamIDs(
        GetPlayFabIDsFromSteamIDsRequest& request,
        ProcessApiCallback<GetPlayFabIDsFromSteamIDsResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Client/GetPlayFabIDsFromSteamIDs", L"X-Authorization", PlayFabSettings::clientSessionTicket, requestJson, OnGetPlayFabIDsFromSteamIDsResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetPlayFabIDsFromSteamIDsResult>(callback)), errorCallback, customData);
    }

    void PlayFabClientAPI::OnGetPlayFabIDsFromSteamIDsResult(CallRequestContainer& request)
    {
        GetPlayFabIDsFromSteamIDsResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<GetPlayFabIDsFromSteamIDsResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabClientAPI::GetPlayFabIDsFromTwitchIDs(
        GetPlayFabIDsFromTwitchIDsRequest& request,
        ProcessApiCallback<GetPlayFabIDsFromTwitchIDsResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Client/GetPlayFabIDsFromTwitchIDs", L"X-Authorization", PlayFabSettings::clientSessionTicket, requestJson, OnGetPlayFabIDsFromTwitchIDsResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetPlayFabIDsFromTwitchIDsResult>(callback)), errorCallback, customData);
    }

    void PlayFabClientAPI::OnGetPlayFabIDsFromTwitchIDsResult(CallRequestContainer& request)
    {
        GetPlayFabIDsFromTwitchIDsResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<GetPlayFabIDsFromTwitchIDsResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabClientAPI::GetPublisherData(
        GetPublisherDataRequest& request,
        ProcessApiCallback<GetPublisherDataResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Client/GetPublisherData", L"X-Authorization", PlayFabSettings::clientSessionTicket, requestJson, OnGetPublisherDataResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetPublisherDataResult>(callback)), errorCallback, customData);
    }

    void PlayFabClientAPI::OnGetPublisherDataResult(CallRequestContainer& request)
    {
        GetPublisherDataResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<GetPublisherDataResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabClientAPI::GetPurchase(
        GetPurchaseRequest& request,
        ProcessApiCallback<GetPurchaseResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Client/GetPurchase", L"X-Authorization", PlayFabSettings::clientSessionTicket, requestJson, OnGetPurchaseResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetPurchaseResult>(callback)), errorCallback, customData);
    }

    void PlayFabClientAPI::OnGetPurchaseResult(CallRequestContainer& request)
    {
        GetPurchaseResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<GetPurchaseResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabClientAPI::GetSharedGroupData(
        GetSharedGroupDataRequest& request,
        ProcessApiCallback<GetSharedGroupDataResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Client/GetSharedGroupData", L"X-Authorization", PlayFabSettings::clientSessionTicket, requestJson, OnGetSharedGroupDataResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetSharedGroupDataResult>(callback)), errorCallback, customData);
    }

    void PlayFabClientAPI::OnGetSharedGroupDataResult(CallRequestContainer& request)
    {
        GetSharedGroupDataResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<GetSharedGroupDataResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabClientAPI::GetStoreItems(
        GetStoreItemsRequest& request,
        ProcessApiCallback<GetStoreItemsResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Client/GetStoreItems", L"X-Authorization", PlayFabSettings::clientSessionTicket, requestJson, OnGetStoreItemsResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetStoreItemsResult>(callback)), errorCallback, customData);
    }

    void PlayFabClientAPI::OnGetStoreItemsResult(CallRequestContainer& request)
    {
        GetStoreItemsResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<GetStoreItemsResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabClientAPI::GetTime(
        GetTimeRequest& request,
        ProcessApiCallback<GetTimeResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Client/GetTime", L"X-Authorization", PlayFabSettings::clientSessionTicket, requestJson, OnGetTimeResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetTimeResult>(callback)), errorCallback, customData);
    }

    void PlayFabClientAPI::OnGetTimeResult(CallRequestContainer& request)
    {
        GetTimeResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<GetTimeResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabClientAPI::GetTitleData(
        GetTitleDataRequest& request,
        ProcessApiCallback<GetTitleDataResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Client/GetTitleData", L"X-Authorization", PlayFabSettings::clientSessionTicket, requestJson, OnGetTitleDataResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetTitleDataResult>(callback)), errorCallback, customData);
    }

    void PlayFabClientAPI::OnGetTitleDataResult(CallRequestContainer& request)
    {
        GetTitleDataResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<GetTitleDataResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabClientAPI::GetTitleNews(
        GetTitleNewsRequest& request,
        ProcessApiCallback<GetTitleNewsResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Client/GetTitleNews", L"X-Authorization", PlayFabSettings::clientSessionTicket, requestJson, OnGetTitleNewsResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetTitleNewsResult>(callback)), errorCallback, customData);
    }

    void PlayFabClientAPI::OnGetTitleNewsResult(CallRequestContainer& request)
    {
        GetTitleNewsResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<GetTitleNewsResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabClientAPI::GetTitlePublicKey(
        GetTitlePublicKeyRequest& request,
        ProcessApiCallback<GetTitlePublicKeyResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Client/GetTitlePublicKey", L"", L"", requestJson, OnGetTitlePublicKeyResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetTitlePublicKeyResult>(callback)), errorCallback, customData);
    }

    void PlayFabClientAPI::OnGetTitlePublicKeyResult(CallRequestContainer& request)
    {
        GetTitlePublicKeyResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<GetTitlePublicKeyResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabClientAPI::GetTradeStatus(
        GetTradeStatusRequest& request,
        ProcessApiCallback<GetTradeStatusResponse> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Client/GetTradeStatus", L"X-Authorization", PlayFabSettings::clientSessionTicket, requestJson, OnGetTradeStatusResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetTradeStatusResponse>(callback)), errorCallback, customData);
    }

    void PlayFabClientAPI::OnGetTradeStatusResult(CallRequestContainer& request)
    {
        GetTradeStatusResponse outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<GetTradeStatusResponse> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabClientAPI::GetUserData(
        GetUserDataRequest& request,
        ProcessApiCallback<GetUserDataResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Client/GetUserData", L"X-Authorization", PlayFabSettings::clientSessionTicket, requestJson, OnGetUserDataResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetUserDataResult>(callback)), errorCallback, customData);
    }

    void PlayFabClientAPI::OnGetUserDataResult(CallRequestContainer& request)
    {
        GetUserDataResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<GetUserDataResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabClientAPI::GetUserInventory(
        GetUserInventoryRequest& request,
        ProcessApiCallback<GetUserInventoryResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Client/GetUserInventory", L"X-Authorization", PlayFabSettings::clientSessionTicket, requestJson, OnGetUserInventoryResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetUserInventoryResult>(callback)), errorCallback, customData);
    }

    void PlayFabClientAPI::OnGetUserInventoryResult(CallRequestContainer& request)
    {
        GetUserInventoryResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<GetUserInventoryResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabClientAPI::GetUserPublisherData(
        GetUserDataRequest& request,
        ProcessApiCallback<GetUserDataResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Client/GetUserPublisherData", L"X-Authorization", PlayFabSettings::clientSessionTicket, requestJson, OnGetUserPublisherDataResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetUserDataResult>(callback)), errorCallback, customData);
    }

    void PlayFabClientAPI::OnGetUserPublisherDataResult(CallRequestContainer& request)
    {
        GetUserDataResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<GetUserDataResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabClientAPI::GetUserPublisherReadOnlyData(
        GetUserDataRequest& request,
        ProcessApiCallback<GetUserDataResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Client/GetUserPublisherReadOnlyData", L"X-Authorization", PlayFabSettings::clientSessionTicket, requestJson, OnGetUserPublisherReadOnlyDataResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetUserDataResult>(callback)), errorCallback, customData);
    }

    void PlayFabClientAPI::OnGetUserPublisherReadOnlyDataResult(CallRequestContainer& request)
    {
        GetUserDataResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<GetUserDataResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabClientAPI::GetUserReadOnlyData(
        GetUserDataRequest& request,
        ProcessApiCallback<GetUserDataResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Client/GetUserReadOnlyData", L"X-Authorization", PlayFabSettings::clientSessionTicket, requestJson, OnGetUserReadOnlyDataResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetUserDataResult>(callback)), errorCallback, customData);
    }

    void PlayFabClientAPI::OnGetUserReadOnlyDataResult(CallRequestContainer& request)
    {
        GetUserDataResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<GetUserDataResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabClientAPI::GetWindowsHelloChallenge(
        GetWindowsHelloChallengeRequest& request,
        ProcessApiCallback<GetWindowsHelloChallengeResponse> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Client/GetWindowsHelloChallenge", L"", L"", requestJson, OnGetWindowsHelloChallengeResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetWindowsHelloChallengeResponse>(callback)), errorCallback, customData);
    }

    void PlayFabClientAPI::OnGetWindowsHelloChallengeResult(CallRequestContainer& request)
    {
        GetWindowsHelloChallengeResponse outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<GetWindowsHelloChallengeResponse> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabClientAPI::GrantCharacterToUser(
        GrantCharacterToUserRequest& request,
        ProcessApiCallback<GrantCharacterToUserResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Client/GrantCharacterToUser", L"X-Authorization", PlayFabSettings::clientSessionTicket, requestJson, OnGrantCharacterToUserResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GrantCharacterToUserResult>(callback)), errorCallback, customData);
    }

    void PlayFabClientAPI::OnGrantCharacterToUserResult(CallRequestContainer& request)
    {
        GrantCharacterToUserResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<GrantCharacterToUserResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabClientAPI::LinkAndroidDeviceID(
        LinkAndroidDeviceIDRequest& request,
        ProcessApiCallback<LinkAndroidDeviceIDResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Client/LinkAndroidDeviceID", L"X-Authorization", PlayFabSettings::clientSessionTicket, requestJson, OnLinkAndroidDeviceIDResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<LinkAndroidDeviceIDResult>(callback)), errorCallback, customData);
    }

    void PlayFabClientAPI::OnLinkAndroidDeviceIDResult(CallRequestContainer& request)
    {
        LinkAndroidDeviceIDResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<LinkAndroidDeviceIDResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabClientAPI::LinkCustomID(
        LinkCustomIDRequest& request,
        ProcessApiCallback<LinkCustomIDResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Client/LinkCustomID", L"X-Authorization", PlayFabSettings::clientSessionTicket, requestJson, OnLinkCustomIDResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<LinkCustomIDResult>(callback)), errorCallback, customData);
    }

    void PlayFabClientAPI::OnLinkCustomIDResult(CallRequestContainer& request)
    {
        LinkCustomIDResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<LinkCustomIDResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabClientAPI::LinkFacebookAccount(
        LinkFacebookAccountRequest& request,
        ProcessApiCallback<LinkFacebookAccountResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Client/LinkFacebookAccount", L"X-Authorization", PlayFabSettings::clientSessionTicket, requestJson, OnLinkFacebookAccountResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<LinkFacebookAccountResult>(callback)), errorCallback, customData);
    }

    void PlayFabClientAPI::OnLinkFacebookAccountResult(CallRequestContainer& request)
    {
        LinkFacebookAccountResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<LinkFacebookAccountResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabClientAPI::LinkFacebookInstantGamesId(
        LinkFacebookInstantGamesIdRequest& request,
        ProcessApiCallback<LinkFacebookInstantGamesIdResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Client/LinkFacebookInstantGamesId", L"X-Authorization", PlayFabSettings::clientSessionTicket, requestJson, OnLinkFacebookInstantGamesIdResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<LinkFacebookInstantGamesIdResult>(callback)), errorCallback, customData);
    }

    void PlayFabClientAPI::OnLinkFacebookInstantGamesIdResult(CallRequestContainer& request)
    {
        LinkFacebookInstantGamesIdResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<LinkFacebookInstantGamesIdResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabClientAPI::LinkGameCenterAccount(
        LinkGameCenterAccountRequest& request,
        ProcessApiCallback<LinkGameCenterAccountResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Client/LinkGameCenterAccount", L"X-Authorization", PlayFabSettings::clientSessionTicket, requestJson, OnLinkGameCenterAccountResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<LinkGameCenterAccountResult>(callback)), errorCallback, customData);
    }

    void PlayFabClientAPI::OnLinkGameCenterAccountResult(CallRequestContainer& request)
    {
        LinkGameCenterAccountResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<LinkGameCenterAccountResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabClientAPI::LinkGoogleAccount(
        LinkGoogleAccountRequest& request,
        ProcessApiCallback<LinkGoogleAccountResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Client/LinkGoogleAccount", L"X-Authorization", PlayFabSettings::clientSessionTicket, requestJson, OnLinkGoogleAccountResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<LinkGoogleAccountResult>(callback)), errorCallback, customData);
    }

    void PlayFabClientAPI::OnLinkGoogleAccountResult(CallRequestContainer& request)
    {
        LinkGoogleAccountResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<LinkGoogleAccountResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabClientAPI::LinkIOSDeviceID(
        LinkIOSDeviceIDRequest& request,
        ProcessApiCallback<LinkIOSDeviceIDResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Client/LinkIOSDeviceID", L"X-Authorization", PlayFabSettings::clientSessionTicket, requestJson, OnLinkIOSDeviceIDResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<LinkIOSDeviceIDResult>(callback)), errorCallback, customData);
    }

    void PlayFabClientAPI::OnLinkIOSDeviceIDResult(CallRequestContainer& request)
    {
        LinkIOSDeviceIDResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<LinkIOSDeviceIDResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabClientAPI::LinkKongregate(
        LinkKongregateAccountRequest& request,
        ProcessApiCallback<LinkKongregateAccountResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Client/LinkKongregate", L"X-Authorization", PlayFabSettings::clientSessionTicket, requestJson, OnLinkKongregateResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<LinkKongregateAccountResult>(callback)), errorCallback, customData);
    }

    void PlayFabClientAPI::OnLinkKongregateResult(CallRequestContainer& request)
    {
        LinkKongregateAccountResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<LinkKongregateAccountResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabClientAPI::LinkNintendoSwitchDeviceId(
        LinkNintendoSwitchDeviceIdRequest& request,
        ProcessApiCallback<LinkNintendoSwitchDeviceIdResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Client/LinkNintendoSwitchDeviceId", L"X-Authorization", PlayFabSettings::clientSessionTicket, requestJson, OnLinkNintendoSwitchDeviceIdResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<LinkNintendoSwitchDeviceIdResult>(callback)), errorCallback, customData);
    }

    void PlayFabClientAPI::OnLinkNintendoSwitchDeviceIdResult(CallRequestContainer& request)
    {
        LinkNintendoSwitchDeviceIdResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<LinkNintendoSwitchDeviceIdResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabClientAPI::LinkSteamAccount(
        LinkSteamAccountRequest& request,
        ProcessApiCallback<LinkSteamAccountResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Client/LinkSteamAccount", L"X-Authorization", PlayFabSettings::clientSessionTicket, requestJson, OnLinkSteamAccountResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<LinkSteamAccountResult>(callback)), errorCallback, customData);
    }

    void PlayFabClientAPI::OnLinkSteamAccountResult(CallRequestContainer& request)
    {
        LinkSteamAccountResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<LinkSteamAccountResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabClientAPI::LinkTwitch(
        LinkTwitchAccountRequest& request,
        ProcessApiCallback<LinkTwitchAccountResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Client/LinkTwitch", L"X-Authorization", PlayFabSettings::clientSessionTicket, requestJson, OnLinkTwitchResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<LinkTwitchAccountResult>(callback)), errorCallback, customData);
    }

    void PlayFabClientAPI::OnLinkTwitchResult(CallRequestContainer& request)
    {
        LinkTwitchAccountResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<LinkTwitchAccountResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabClientAPI::LinkWindowsHello(
        LinkWindowsHelloAccountRequest& request,
        ProcessApiCallback<LinkWindowsHelloAccountResponse> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Client/LinkWindowsHello", L"X-Authorization", PlayFabSettings::clientSessionTicket, requestJson, OnLinkWindowsHelloResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<LinkWindowsHelloAccountResponse>(callback)), errorCallback, customData);
    }

    void PlayFabClientAPI::OnLinkWindowsHelloResult(CallRequestContainer& request)
    {
        LinkWindowsHelloAccountResponse outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<LinkWindowsHelloAccountResponse> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabClientAPI::LinkXboxAccount(
        LinkXboxAccountRequest& request,
        ProcessApiCallback<LinkXboxAccountResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Client/LinkXboxAccount", L"X-Authorization", PlayFabSettings::clientSessionTicket, requestJson, OnLinkXboxAccountResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<LinkXboxAccountResult>(callback)), errorCallback, customData);
    }

    void PlayFabClientAPI::OnLinkXboxAccountResult(CallRequestContainer& request)
    {
        LinkXboxAccountResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<LinkXboxAccountResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabClientAPI::LoginWithAndroidDeviceID(
        LoginWithAndroidDeviceIDRequest& request,
        ProcessApiCallback<LoginResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {
        if (PlayFabSettings::titleId.length() > 0) request.TitleId = ShortenString(PlayFabSettings::titleId);

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Client/LoginWithAndroidDeviceID", L"", L"", requestJson, OnLoginWithAndroidDeviceIDResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<LoginResult>(callback)), errorCallback, customData);
    }

    void PlayFabClientAPI::OnLoginWithAndroidDeviceIDResult(CallRequestContainer& request)
    {
        LoginResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;
        if (outResult.SessionTicket.length() > 0)
        {
            PlayFabSettings::clientSessionTicket = WidenString(outResult.SessionTicket);
            if (outResult.EntityToken.notNull()) PlayFabSettings::entityToken = WidenString(outResult.EntityToken->EntityToken);
            MultiStepClientLogin(outResult.SettingsForUser->NeedsAttribution);
        }

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<LoginResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabClientAPI::LoginWithCustomID(
        LoginWithCustomIDRequest& request,
        ProcessApiCallback<LoginResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {
        if (PlayFabSettings::titleId.length() > 0) request.TitleId = ShortenString(PlayFabSettings::titleId);

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Client/LoginWithCustomID", L"", L"", requestJson, OnLoginWithCustomIDResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<LoginResult>(callback)), errorCallback, customData);
    }

    void PlayFabClientAPI::OnLoginWithCustomIDResult(CallRequestContainer& request)
    {
        LoginResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;
        if (outResult.SessionTicket.length() > 0)
        {
            PlayFabSettings::clientSessionTicket = WidenString(outResult.SessionTicket);
            if (outResult.EntityToken.notNull()) PlayFabSettings::entityToken = WidenString(outResult.EntityToken->EntityToken);
            MultiStepClientLogin(outResult.SettingsForUser->NeedsAttribution);
        }

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<LoginResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabClientAPI::LoginWithEmailAddress(
        LoginWithEmailAddressRequest& request,
        ProcessApiCallback<LoginResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {
        if (PlayFabSettings::titleId.length() > 0) request.TitleId = ShortenString(PlayFabSettings::titleId);

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Client/LoginWithEmailAddress", L"", L"", requestJson, OnLoginWithEmailAddressResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<LoginResult>(callback)), errorCallback, customData);
    }

    void PlayFabClientAPI::OnLoginWithEmailAddressResult(CallRequestContainer& request)
    {
        LoginResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;
        if (outResult.SessionTicket.length() > 0)
        {
            PlayFabSettings::clientSessionTicket = WidenString(outResult.SessionTicket);
            if (outResult.EntityToken.notNull()) PlayFabSettings::entityToken = WidenString(outResult.EntityToken->EntityToken);
            MultiStepClientLogin(outResult.SettingsForUser->NeedsAttribution);
        }

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<LoginResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabClientAPI::LoginWithFacebook(
        LoginWithFacebookRequest& request,
        ProcessApiCallback<LoginResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {
        if (PlayFabSettings::titleId.length() > 0) request.TitleId = ShortenString(PlayFabSettings::titleId);

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Client/LoginWithFacebook", L"", L"", requestJson, OnLoginWithFacebookResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<LoginResult>(callback)), errorCallback, customData);
    }

    void PlayFabClientAPI::OnLoginWithFacebookResult(CallRequestContainer& request)
    {
        LoginResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;
        if (outResult.SessionTicket.length() > 0)
        {
            PlayFabSettings::clientSessionTicket = WidenString(outResult.SessionTicket);
            if (outResult.EntityToken.notNull()) PlayFabSettings::entityToken = WidenString(outResult.EntityToken->EntityToken);
            MultiStepClientLogin(outResult.SettingsForUser->NeedsAttribution);
        }

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<LoginResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabClientAPI::LoginWithFacebookInstantGamesId(
        LoginWithFacebookInstantGamesIdRequest& request,
        ProcessApiCallback<LoginResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {
        if (PlayFabSettings::titleId.length() > 0) request.TitleId = ShortenString(PlayFabSettings::titleId);

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Client/LoginWithFacebookInstantGamesId", L"", L"", requestJson, OnLoginWithFacebookInstantGamesIdResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<LoginResult>(callback)), errorCallback, customData);
    }

    void PlayFabClientAPI::OnLoginWithFacebookInstantGamesIdResult(CallRequestContainer& request)
    {
        LoginResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;
        if (outResult.SessionTicket.length() > 0)
        {
            PlayFabSettings::clientSessionTicket = WidenString(outResult.SessionTicket);
            if (outResult.EntityToken.notNull()) PlayFabSettings::entityToken = WidenString(outResult.EntityToken->EntityToken);
            MultiStepClientLogin(outResult.SettingsForUser->NeedsAttribution);
        }

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<LoginResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabClientAPI::LoginWithGameCenter(
        LoginWithGameCenterRequest& request,
        ProcessApiCallback<LoginResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {
        if (PlayFabSettings::titleId.length() > 0) request.TitleId = ShortenString(PlayFabSettings::titleId);

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Client/LoginWithGameCenter", L"", L"", requestJson, OnLoginWithGameCenterResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<LoginResult>(callback)), errorCallback, customData);
    }

    void PlayFabClientAPI::OnLoginWithGameCenterResult(CallRequestContainer& request)
    {
        LoginResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;
        if (outResult.SessionTicket.length() > 0)
        {
            PlayFabSettings::clientSessionTicket = WidenString(outResult.SessionTicket);
            if (outResult.EntityToken.notNull()) PlayFabSettings::entityToken = WidenString(outResult.EntityToken->EntityToken);
            MultiStepClientLogin(outResult.SettingsForUser->NeedsAttribution);
        }

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<LoginResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabClientAPI::LoginWithGoogleAccount(
        LoginWithGoogleAccountRequest& request,
        ProcessApiCallback<LoginResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {
        if (PlayFabSettings::titleId.length() > 0) request.TitleId = ShortenString(PlayFabSettings::titleId);

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Client/LoginWithGoogleAccount", L"", L"", requestJson, OnLoginWithGoogleAccountResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<LoginResult>(callback)), errorCallback, customData);
    }

    void PlayFabClientAPI::OnLoginWithGoogleAccountResult(CallRequestContainer& request)
    {
        LoginResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;
        if (outResult.SessionTicket.length() > 0)
        {
            PlayFabSettings::clientSessionTicket = WidenString(outResult.SessionTicket);
            if (outResult.EntityToken.notNull()) PlayFabSettings::entityToken = WidenString(outResult.EntityToken->EntityToken);
            MultiStepClientLogin(outResult.SettingsForUser->NeedsAttribution);
        }

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<LoginResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabClientAPI::LoginWithIOSDeviceID(
        LoginWithIOSDeviceIDRequest& request,
        ProcessApiCallback<LoginResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {
        if (PlayFabSettings::titleId.length() > 0) request.TitleId = ShortenString(PlayFabSettings::titleId);

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Client/LoginWithIOSDeviceID", L"", L"", requestJson, OnLoginWithIOSDeviceIDResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<LoginResult>(callback)), errorCallback, customData);
    }

    void PlayFabClientAPI::OnLoginWithIOSDeviceIDResult(CallRequestContainer& request)
    {
        LoginResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;
        if (outResult.SessionTicket.length() > 0)
        {
            PlayFabSettings::clientSessionTicket = WidenString(outResult.SessionTicket);
            if (outResult.EntityToken.notNull()) PlayFabSettings::entityToken = WidenString(outResult.EntityToken->EntityToken);
            MultiStepClientLogin(outResult.SettingsForUser->NeedsAttribution);
        }

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<LoginResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabClientAPI::LoginWithKongregate(
        LoginWithKongregateRequest& request,
        ProcessApiCallback<LoginResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {
        if (PlayFabSettings::titleId.length() > 0) request.TitleId = ShortenString(PlayFabSettings::titleId);

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Client/LoginWithKongregate", L"", L"", requestJson, OnLoginWithKongregateResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<LoginResult>(callback)), errorCallback, customData);
    }

    void PlayFabClientAPI::OnLoginWithKongregateResult(CallRequestContainer& request)
    {
        LoginResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;
        if (outResult.SessionTicket.length() > 0)
        {
            PlayFabSettings::clientSessionTicket = WidenString(outResult.SessionTicket);
            if (outResult.EntityToken.notNull()) PlayFabSettings::entityToken = WidenString(outResult.EntityToken->EntityToken);
            MultiStepClientLogin(outResult.SettingsForUser->NeedsAttribution);
        }

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<LoginResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabClientAPI::LoginWithNintendoSwitchDeviceId(
        LoginWithNintendoSwitchDeviceIdRequest& request,
        ProcessApiCallback<LoginResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {
        if (PlayFabSettings::titleId.length() > 0) request.TitleId = ShortenString(PlayFabSettings::titleId);

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Client/LoginWithNintendoSwitchDeviceId", L"", L"", requestJson, OnLoginWithNintendoSwitchDeviceIdResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<LoginResult>(callback)), errorCallback, customData);
    }

    void PlayFabClientAPI::OnLoginWithNintendoSwitchDeviceIdResult(CallRequestContainer& request)
    {
        LoginResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;
        if (outResult.SessionTicket.length() > 0)
        {
            PlayFabSettings::clientSessionTicket = WidenString(outResult.SessionTicket);
            if (outResult.EntityToken.notNull()) PlayFabSettings::entityToken = WidenString(outResult.EntityToken->EntityToken);
            MultiStepClientLogin(outResult.SettingsForUser->NeedsAttribution);
        }

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<LoginResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabClientAPI::LoginWithPlayFab(
        LoginWithPlayFabRequest& request,
        ProcessApiCallback<LoginResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {
        if (PlayFabSettings::titleId.length() > 0) request.TitleId = ShortenString(PlayFabSettings::titleId);

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Client/LoginWithPlayFab", L"", L"", requestJson, OnLoginWithPlayFabResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<LoginResult>(callback)), errorCallback, customData);
    }

    void PlayFabClientAPI::OnLoginWithPlayFabResult(CallRequestContainer& request)
    {
        LoginResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;
        if (outResult.SessionTicket.length() > 0)
        {
            PlayFabSettings::clientSessionTicket = WidenString(outResult.SessionTicket);
            if (outResult.EntityToken.notNull()) PlayFabSettings::entityToken = WidenString(outResult.EntityToken->EntityToken);
            MultiStepClientLogin(outResult.SettingsForUser->NeedsAttribution);
        }

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<LoginResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabClientAPI::LoginWithSteam(
        LoginWithSteamRequest& request,
        ProcessApiCallback<LoginResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {
        if (PlayFabSettings::titleId.length() > 0) request.TitleId = ShortenString(PlayFabSettings::titleId);

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Client/LoginWithSteam", L"", L"", requestJson, OnLoginWithSteamResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<LoginResult>(callback)), errorCallback, customData);
    }

    void PlayFabClientAPI::OnLoginWithSteamResult(CallRequestContainer& request)
    {
        LoginResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;
        if (outResult.SessionTicket.length() > 0)
        {
            PlayFabSettings::clientSessionTicket = WidenString(outResult.SessionTicket);
            if (outResult.EntityToken.notNull()) PlayFabSettings::entityToken = WidenString(outResult.EntityToken->EntityToken);
            MultiStepClientLogin(outResult.SettingsForUser->NeedsAttribution);
        }

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<LoginResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabClientAPI::LoginWithTwitch(
        LoginWithTwitchRequest& request,
        ProcessApiCallback<LoginResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {
        if (PlayFabSettings::titleId.length() > 0) request.TitleId = ShortenString(PlayFabSettings::titleId);

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Client/LoginWithTwitch", L"", L"", requestJson, OnLoginWithTwitchResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<LoginResult>(callback)), errorCallback, customData);
    }

    void PlayFabClientAPI::OnLoginWithTwitchResult(CallRequestContainer& request)
    {
        LoginResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;
        if (outResult.SessionTicket.length() > 0)
        {
            PlayFabSettings::clientSessionTicket = WidenString(outResult.SessionTicket);
            if (outResult.EntityToken.notNull()) PlayFabSettings::entityToken = WidenString(outResult.EntityToken->EntityToken);
            MultiStepClientLogin(outResult.SettingsForUser->NeedsAttribution);
        }

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<LoginResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabClientAPI::LoginWithWindowsHello(
        LoginWithWindowsHelloRequest& request,
        ProcessApiCallback<LoginResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {
        if (PlayFabSettings::titleId.length() > 0) request.TitleId = ShortenString(PlayFabSettings::titleId);

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Client/LoginWithWindowsHello", L"", L"", requestJson, OnLoginWithWindowsHelloResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<LoginResult>(callback)), errorCallback, customData);
    }

    void PlayFabClientAPI::OnLoginWithWindowsHelloResult(CallRequestContainer& request)
    {
        LoginResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;
        if (outResult.SessionTicket.length() > 0)
        {
            PlayFabSettings::clientSessionTicket = WidenString(outResult.SessionTicket);
            if (outResult.EntityToken.notNull()) PlayFabSettings::entityToken = WidenString(outResult.EntityToken->EntityToken);
            MultiStepClientLogin(outResult.SettingsForUser->NeedsAttribution);
        }

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<LoginResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabClientAPI::LoginWithXbox(
        LoginWithXboxRequest& request,
        ProcessApiCallback<LoginResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {
        if (PlayFabSettings::titleId.length() > 0) request.TitleId = ShortenString(PlayFabSettings::titleId);

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Client/LoginWithXbox", L"", L"", requestJson, OnLoginWithXboxResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<LoginResult>(callback)), errorCallback, customData);
    }

    void PlayFabClientAPI::OnLoginWithXboxResult(CallRequestContainer& request)
    {
        LoginResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;
        if (outResult.SessionTicket.length() > 0)
        {
            PlayFabSettings::clientSessionTicket = WidenString(outResult.SessionTicket);
            if (outResult.EntityToken.notNull()) PlayFabSettings::entityToken = WidenString(outResult.EntityToken->EntityToken);
            MultiStepClientLogin(outResult.SettingsForUser->NeedsAttribution);
        }

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<LoginResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabClientAPI::Matchmake(
        MatchmakeRequest& request,
        ProcessApiCallback<MatchmakeResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Client/Matchmake", L"X-Authorization", PlayFabSettings::clientSessionTicket, requestJson, OnMatchmakeResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<MatchmakeResult>(callback)), errorCallback, customData);
    }

    void PlayFabClientAPI::OnMatchmakeResult(CallRequestContainer& request)
    {
        MatchmakeResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<MatchmakeResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabClientAPI::OpenTrade(
        OpenTradeRequest& request,
        ProcessApiCallback<OpenTradeResponse> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Client/OpenTrade", L"X-Authorization", PlayFabSettings::clientSessionTicket, requestJson, OnOpenTradeResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<OpenTradeResponse>(callback)), errorCallback, customData);
    }

    void PlayFabClientAPI::OnOpenTradeResult(CallRequestContainer& request)
    {
        OpenTradeResponse outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<OpenTradeResponse> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabClientAPI::PayForPurchase(
        PayForPurchaseRequest& request,
        ProcessApiCallback<PayForPurchaseResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Client/PayForPurchase", L"X-Authorization", PlayFabSettings::clientSessionTicket, requestJson, OnPayForPurchaseResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<PayForPurchaseResult>(callback)), errorCallback, customData);
    }

    void PlayFabClientAPI::OnPayForPurchaseResult(CallRequestContainer& request)
    {
        PayForPurchaseResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<PayForPurchaseResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabClientAPI::PurchaseItem(
        PurchaseItemRequest& request,
        ProcessApiCallback<PurchaseItemResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Client/PurchaseItem", L"X-Authorization", PlayFabSettings::clientSessionTicket, requestJson, OnPurchaseItemResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<PurchaseItemResult>(callback)), errorCallback, customData);
    }

    void PlayFabClientAPI::OnPurchaseItemResult(CallRequestContainer& request)
    {
        PurchaseItemResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<PurchaseItemResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabClientAPI::RedeemCoupon(
        RedeemCouponRequest& request,
        ProcessApiCallback<RedeemCouponResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Client/RedeemCoupon", L"X-Authorization", PlayFabSettings::clientSessionTicket, requestJson, OnRedeemCouponResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<RedeemCouponResult>(callback)), errorCallback, customData);
    }

    void PlayFabClientAPI::OnRedeemCouponResult(CallRequestContainer& request)
    {
        RedeemCouponResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<RedeemCouponResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabClientAPI::RegisterForIOSPushNotification(
        RegisterForIOSPushNotificationRequest& request,
        ProcessApiCallback<RegisterForIOSPushNotificationResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Client/RegisterForIOSPushNotification", L"X-Authorization", PlayFabSettings::clientSessionTicket, requestJson, OnRegisterForIOSPushNotificationResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<RegisterForIOSPushNotificationResult>(callback)), errorCallback, customData);
    }

    void PlayFabClientAPI::OnRegisterForIOSPushNotificationResult(CallRequestContainer& request)
    {
        RegisterForIOSPushNotificationResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<RegisterForIOSPushNotificationResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabClientAPI::RegisterPlayFabUser(
        RegisterPlayFabUserRequest& request,
        ProcessApiCallback<RegisterPlayFabUserResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {
        if (PlayFabSettings::titleId.length() > 0) request.TitleId = ShortenString(PlayFabSettings::titleId);

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Client/RegisterPlayFabUser", L"", L"", requestJson, OnRegisterPlayFabUserResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<RegisterPlayFabUserResult>(callback)), errorCallback, customData);
    }

    void PlayFabClientAPI::OnRegisterPlayFabUserResult(CallRequestContainer& request)
    {
        RegisterPlayFabUserResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;
        if (outResult.SessionTicket.length() > 0)
        {
            PlayFabSettings::clientSessionTicket = WidenString(outResult.SessionTicket);
            MultiStepClientLogin(outResult.SettingsForUser->NeedsAttribution);
        }

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<RegisterPlayFabUserResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabClientAPI::RegisterWithWindowsHello(
        RegisterWithWindowsHelloRequest& request,
        ProcessApiCallback<LoginResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {
        if (PlayFabSettings::titleId.length() > 0) request.TitleId = ShortenString(PlayFabSettings::titleId);

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Client/RegisterWithWindowsHello", L"", L"", requestJson, OnRegisterWithWindowsHelloResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<LoginResult>(callback)), errorCallback, customData);
    }

    void PlayFabClientAPI::OnRegisterWithWindowsHelloResult(CallRequestContainer& request)
    {
        LoginResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;
        if (outResult.SessionTicket.length() > 0)
        {
            PlayFabSettings::clientSessionTicket = WidenString(outResult.SessionTicket);
            if (outResult.EntityToken.notNull()) PlayFabSettings::entityToken = WidenString(outResult.EntityToken->EntityToken);
            MultiStepClientLogin(outResult.SettingsForUser->NeedsAttribution);
        }

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<LoginResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabClientAPI::RemoveContactEmail(
        RemoveContactEmailRequest& request,
        ProcessApiCallback<RemoveContactEmailResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Client/RemoveContactEmail", L"X-Authorization", PlayFabSettings::clientSessionTicket, requestJson, OnRemoveContactEmailResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<RemoveContactEmailResult>(callback)), errorCallback, customData);
    }

    void PlayFabClientAPI::OnRemoveContactEmailResult(CallRequestContainer& request)
    {
        RemoveContactEmailResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<RemoveContactEmailResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabClientAPI::RemoveFriend(
        RemoveFriendRequest& request,
        ProcessApiCallback<RemoveFriendResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Client/RemoveFriend", L"X-Authorization", PlayFabSettings::clientSessionTicket, requestJson, OnRemoveFriendResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<RemoveFriendResult>(callback)), errorCallback, customData);
    }

    void PlayFabClientAPI::OnRemoveFriendResult(CallRequestContainer& request)
    {
        RemoveFriendResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<RemoveFriendResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabClientAPI::RemoveGenericID(
        RemoveGenericIDRequest& request,
        ProcessApiCallback<RemoveGenericIDResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Client/RemoveGenericID", L"X-Authorization", PlayFabSettings::clientSessionTicket, requestJson, OnRemoveGenericIDResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<RemoveGenericIDResult>(callback)), errorCallback, customData);
    }

    void PlayFabClientAPI::OnRemoveGenericIDResult(CallRequestContainer& request)
    {
        RemoveGenericIDResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<RemoveGenericIDResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabClientAPI::RemoveSharedGroupMembers(
        RemoveSharedGroupMembersRequest& request,
        ProcessApiCallback<RemoveSharedGroupMembersResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Client/RemoveSharedGroupMembers", L"X-Authorization", PlayFabSettings::clientSessionTicket, requestJson, OnRemoveSharedGroupMembersResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<RemoveSharedGroupMembersResult>(callback)), errorCallback, customData);
    }

    void PlayFabClientAPI::OnRemoveSharedGroupMembersResult(CallRequestContainer& request)
    {
        RemoveSharedGroupMembersResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<RemoveSharedGroupMembersResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabClientAPI::ReportDeviceInfo(
        DeviceInfoRequest& request,
        ProcessApiCallback<EmptyResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Client/ReportDeviceInfo", L"X-Authorization", PlayFabSettings::clientSessionTicket, requestJson, OnReportDeviceInfoResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<EmptyResult>(callback)), errorCallback, customData);
    }

    void PlayFabClientAPI::OnReportDeviceInfoResult(CallRequestContainer& request)
    {
        EmptyResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<EmptyResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabClientAPI::ReportPlayer(
        ReportPlayerClientRequest& request,
        ProcessApiCallback<ReportPlayerClientResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Client/ReportPlayer", L"X-Authorization", PlayFabSettings::clientSessionTicket, requestJson, OnReportPlayerResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<ReportPlayerClientResult>(callback)), errorCallback, customData);
    }

    void PlayFabClientAPI::OnReportPlayerResult(CallRequestContainer& request)
    {
        ReportPlayerClientResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<ReportPlayerClientResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabClientAPI::RestoreIOSPurchases(
        RestoreIOSPurchasesRequest& request,
        ProcessApiCallback<RestoreIOSPurchasesResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Client/RestoreIOSPurchases", L"X-Authorization", PlayFabSettings::clientSessionTicket, requestJson, OnRestoreIOSPurchasesResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<RestoreIOSPurchasesResult>(callback)), errorCallback, customData);
    }

    void PlayFabClientAPI::OnRestoreIOSPurchasesResult(CallRequestContainer& request)
    {
        RestoreIOSPurchasesResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<RestoreIOSPurchasesResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabClientAPI::SendAccountRecoveryEmail(
        SendAccountRecoveryEmailRequest& request,
        ProcessApiCallback<SendAccountRecoveryEmailResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Client/SendAccountRecoveryEmail", L"", L"", requestJson, OnSendAccountRecoveryEmailResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<SendAccountRecoveryEmailResult>(callback)), errorCallback, customData);
    }

    void PlayFabClientAPI::OnSendAccountRecoveryEmailResult(CallRequestContainer& request)
    {
        SendAccountRecoveryEmailResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<SendAccountRecoveryEmailResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabClientAPI::SetFriendTags(
        SetFriendTagsRequest& request,
        ProcessApiCallback<SetFriendTagsResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Client/SetFriendTags", L"X-Authorization", PlayFabSettings::clientSessionTicket, requestJson, OnSetFriendTagsResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<SetFriendTagsResult>(callback)), errorCallback, customData);
    }

    void PlayFabClientAPI::OnSetFriendTagsResult(CallRequestContainer& request)
    {
        SetFriendTagsResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<SetFriendTagsResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabClientAPI::SetPlayerSecret(
        SetPlayerSecretRequest& request,
        ProcessApiCallback<SetPlayerSecretResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Client/SetPlayerSecret", L"X-Authorization", PlayFabSettings::clientSessionTicket, requestJson, OnSetPlayerSecretResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<SetPlayerSecretResult>(callback)), errorCallback, customData);
    }

    void PlayFabClientAPI::OnSetPlayerSecretResult(CallRequestContainer& request)
    {
        SetPlayerSecretResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<SetPlayerSecretResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabClientAPI::StartGame(
        StartGameRequest& request,
        ProcessApiCallback<StartGameResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Client/StartGame", L"X-Authorization", PlayFabSettings::clientSessionTicket, requestJson, OnStartGameResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<StartGameResult>(callback)), errorCallback, customData);
    }

    void PlayFabClientAPI::OnStartGameResult(CallRequestContainer& request)
    {
        StartGameResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<StartGameResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabClientAPI::StartPurchase(
        StartPurchaseRequest& request,
        ProcessApiCallback<StartPurchaseResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Client/StartPurchase", L"X-Authorization", PlayFabSettings::clientSessionTicket, requestJson, OnStartPurchaseResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<StartPurchaseResult>(callback)), errorCallback, customData);
    }

    void PlayFabClientAPI::OnStartPurchaseResult(CallRequestContainer& request)
    {
        StartPurchaseResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<StartPurchaseResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabClientAPI::SubtractUserVirtualCurrency(
        SubtractUserVirtualCurrencyRequest& request,
        ProcessApiCallback<ModifyUserVirtualCurrencyResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Client/SubtractUserVirtualCurrency", L"X-Authorization", PlayFabSettings::clientSessionTicket, requestJson, OnSubtractUserVirtualCurrencyResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<ModifyUserVirtualCurrencyResult>(callback)), errorCallback, customData);
    }

    void PlayFabClientAPI::OnSubtractUserVirtualCurrencyResult(CallRequestContainer& request)
    {
        ModifyUserVirtualCurrencyResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<ModifyUserVirtualCurrencyResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabClientAPI::UnlinkAndroidDeviceID(
        UnlinkAndroidDeviceIDRequest& request,
        ProcessApiCallback<UnlinkAndroidDeviceIDResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Client/UnlinkAndroidDeviceID", L"X-Authorization", PlayFabSettings::clientSessionTicket, requestJson, OnUnlinkAndroidDeviceIDResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<UnlinkAndroidDeviceIDResult>(callback)), errorCallback, customData);
    }

    void PlayFabClientAPI::OnUnlinkAndroidDeviceIDResult(CallRequestContainer& request)
    {
        UnlinkAndroidDeviceIDResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<UnlinkAndroidDeviceIDResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabClientAPI::UnlinkCustomID(
        UnlinkCustomIDRequest& request,
        ProcessApiCallback<UnlinkCustomIDResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Client/UnlinkCustomID", L"X-Authorization", PlayFabSettings::clientSessionTicket, requestJson, OnUnlinkCustomIDResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<UnlinkCustomIDResult>(callback)), errorCallback, customData);
    }

    void PlayFabClientAPI::OnUnlinkCustomIDResult(CallRequestContainer& request)
    {
        UnlinkCustomIDResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<UnlinkCustomIDResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabClientAPI::UnlinkFacebookAccount(
        UnlinkFacebookAccountRequest& request,
        ProcessApiCallback<UnlinkFacebookAccountResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Client/UnlinkFacebookAccount", L"X-Authorization", PlayFabSettings::clientSessionTicket, requestJson, OnUnlinkFacebookAccountResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<UnlinkFacebookAccountResult>(callback)), errorCallback, customData);
    }

    void PlayFabClientAPI::OnUnlinkFacebookAccountResult(CallRequestContainer& request)
    {
        UnlinkFacebookAccountResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<UnlinkFacebookAccountResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabClientAPI::UnlinkFacebookInstantGamesId(
        UnlinkFacebookInstantGamesIdRequest& request,
        ProcessApiCallback<UnlinkFacebookInstantGamesIdResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Client/UnlinkFacebookInstantGamesId", L"X-Authorization", PlayFabSettings::clientSessionTicket, requestJson, OnUnlinkFacebookInstantGamesIdResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<UnlinkFacebookInstantGamesIdResult>(callback)), errorCallback, customData);
    }

    void PlayFabClientAPI::OnUnlinkFacebookInstantGamesIdResult(CallRequestContainer& request)
    {
        UnlinkFacebookInstantGamesIdResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<UnlinkFacebookInstantGamesIdResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabClientAPI::UnlinkGameCenterAccount(
        UnlinkGameCenterAccountRequest& request,
        ProcessApiCallback<UnlinkGameCenterAccountResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Client/UnlinkGameCenterAccount", L"X-Authorization", PlayFabSettings::clientSessionTicket, requestJson, OnUnlinkGameCenterAccountResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<UnlinkGameCenterAccountResult>(callback)), errorCallback, customData);
    }

    void PlayFabClientAPI::OnUnlinkGameCenterAccountResult(CallRequestContainer& request)
    {
        UnlinkGameCenterAccountResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<UnlinkGameCenterAccountResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabClientAPI::UnlinkGoogleAccount(
        UnlinkGoogleAccountRequest& request,
        ProcessApiCallback<UnlinkGoogleAccountResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Client/UnlinkGoogleAccount", L"X-Authorization", PlayFabSettings::clientSessionTicket, requestJson, OnUnlinkGoogleAccountResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<UnlinkGoogleAccountResult>(callback)), errorCallback, customData);
    }

    void PlayFabClientAPI::OnUnlinkGoogleAccountResult(CallRequestContainer& request)
    {
        UnlinkGoogleAccountResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<UnlinkGoogleAccountResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabClientAPI::UnlinkIOSDeviceID(
        UnlinkIOSDeviceIDRequest& request,
        ProcessApiCallback<UnlinkIOSDeviceIDResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Client/UnlinkIOSDeviceID", L"X-Authorization", PlayFabSettings::clientSessionTicket, requestJson, OnUnlinkIOSDeviceIDResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<UnlinkIOSDeviceIDResult>(callback)), errorCallback, customData);
    }

    void PlayFabClientAPI::OnUnlinkIOSDeviceIDResult(CallRequestContainer& request)
    {
        UnlinkIOSDeviceIDResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<UnlinkIOSDeviceIDResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabClientAPI::UnlinkKongregate(
        UnlinkKongregateAccountRequest& request,
        ProcessApiCallback<UnlinkKongregateAccountResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Client/UnlinkKongregate", L"X-Authorization", PlayFabSettings::clientSessionTicket, requestJson, OnUnlinkKongregateResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<UnlinkKongregateAccountResult>(callback)), errorCallback, customData);
    }

    void PlayFabClientAPI::OnUnlinkKongregateResult(CallRequestContainer& request)
    {
        UnlinkKongregateAccountResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<UnlinkKongregateAccountResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabClientAPI::UnlinkNintendoSwitchDeviceId(
        UnlinkNintendoSwitchDeviceIdRequest& request,
        ProcessApiCallback<UnlinkNintendoSwitchDeviceIdResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Client/UnlinkNintendoSwitchDeviceId", L"X-Authorization", PlayFabSettings::clientSessionTicket, requestJson, OnUnlinkNintendoSwitchDeviceIdResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<UnlinkNintendoSwitchDeviceIdResult>(callback)), errorCallback, customData);
    }

    void PlayFabClientAPI::OnUnlinkNintendoSwitchDeviceIdResult(CallRequestContainer& request)
    {
        UnlinkNintendoSwitchDeviceIdResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<UnlinkNintendoSwitchDeviceIdResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabClientAPI::UnlinkSteamAccount(
        UnlinkSteamAccountRequest& request,
        ProcessApiCallback<UnlinkSteamAccountResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Client/UnlinkSteamAccount", L"X-Authorization", PlayFabSettings::clientSessionTicket, requestJson, OnUnlinkSteamAccountResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<UnlinkSteamAccountResult>(callback)), errorCallback, customData);
    }

    void PlayFabClientAPI::OnUnlinkSteamAccountResult(CallRequestContainer& request)
    {
        UnlinkSteamAccountResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<UnlinkSteamAccountResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabClientAPI::UnlinkTwitch(
        UnlinkTwitchAccountRequest& request,
        ProcessApiCallback<UnlinkTwitchAccountResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Client/UnlinkTwitch", L"X-Authorization", PlayFabSettings::clientSessionTicket, requestJson, OnUnlinkTwitchResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<UnlinkTwitchAccountResult>(callback)), errorCallback, customData);
    }

    void PlayFabClientAPI::OnUnlinkTwitchResult(CallRequestContainer& request)
    {
        UnlinkTwitchAccountResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<UnlinkTwitchAccountResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabClientAPI::UnlinkWindowsHello(
        UnlinkWindowsHelloAccountRequest& request,
        ProcessApiCallback<UnlinkWindowsHelloAccountResponse> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Client/UnlinkWindowsHello", L"X-Authorization", PlayFabSettings::clientSessionTicket, requestJson, OnUnlinkWindowsHelloResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<UnlinkWindowsHelloAccountResponse>(callback)), errorCallback, customData);
    }

    void PlayFabClientAPI::OnUnlinkWindowsHelloResult(CallRequestContainer& request)
    {
        UnlinkWindowsHelloAccountResponse outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<UnlinkWindowsHelloAccountResponse> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabClientAPI::UnlinkXboxAccount(
        UnlinkXboxAccountRequest& request,
        ProcessApiCallback<UnlinkXboxAccountResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Client/UnlinkXboxAccount", L"X-Authorization", PlayFabSettings::clientSessionTicket, requestJson, OnUnlinkXboxAccountResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<UnlinkXboxAccountResult>(callback)), errorCallback, customData);
    }

    void PlayFabClientAPI::OnUnlinkXboxAccountResult(CallRequestContainer& request)
    {
        UnlinkXboxAccountResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<UnlinkXboxAccountResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabClientAPI::UnlockContainerInstance(
        UnlockContainerInstanceRequest& request,
        ProcessApiCallback<UnlockContainerItemResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Client/UnlockContainerInstance", L"X-Authorization", PlayFabSettings::clientSessionTicket, requestJson, OnUnlockContainerInstanceResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<UnlockContainerItemResult>(callback)), errorCallback, customData);
    }

    void PlayFabClientAPI::OnUnlockContainerInstanceResult(CallRequestContainer& request)
    {
        UnlockContainerItemResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<UnlockContainerItemResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabClientAPI::UnlockContainerItem(
        UnlockContainerItemRequest& request,
        ProcessApiCallback<UnlockContainerItemResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Client/UnlockContainerItem", L"X-Authorization", PlayFabSettings::clientSessionTicket, requestJson, OnUnlockContainerItemResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<UnlockContainerItemResult>(callback)), errorCallback, customData);
    }

    void PlayFabClientAPI::OnUnlockContainerItemResult(CallRequestContainer& request)
    {
        UnlockContainerItemResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<UnlockContainerItemResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabClientAPI::UpdateAvatarUrl(
        UpdateAvatarUrlRequest& request,
        ProcessApiCallback<EmptyResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Client/UpdateAvatarUrl", L"X-Authorization", PlayFabSettings::clientSessionTicket, requestJson, OnUpdateAvatarUrlResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<EmptyResult>(callback)), errorCallback, customData);
    }

    void PlayFabClientAPI::OnUpdateAvatarUrlResult(CallRequestContainer& request)
    {
        EmptyResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<EmptyResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabClientAPI::UpdateCharacterData(
        UpdateCharacterDataRequest& request,
        ProcessApiCallback<UpdateCharacterDataResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Client/UpdateCharacterData", L"X-Authorization", PlayFabSettings::clientSessionTicket, requestJson, OnUpdateCharacterDataResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<UpdateCharacterDataResult>(callback)), errorCallback, customData);
    }

    void PlayFabClientAPI::OnUpdateCharacterDataResult(CallRequestContainer& request)
    {
        UpdateCharacterDataResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<UpdateCharacterDataResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabClientAPI::UpdateCharacterStatistics(
        UpdateCharacterStatisticsRequest& request,
        ProcessApiCallback<UpdateCharacterStatisticsResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Client/UpdateCharacterStatistics", L"X-Authorization", PlayFabSettings::clientSessionTicket, requestJson, OnUpdateCharacterStatisticsResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<UpdateCharacterStatisticsResult>(callback)), errorCallback, customData);
    }

    void PlayFabClientAPI::OnUpdateCharacterStatisticsResult(CallRequestContainer& request)
    {
        UpdateCharacterStatisticsResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<UpdateCharacterStatisticsResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabClientAPI::UpdatePlayerStatistics(
        UpdatePlayerStatisticsRequest& request,
        ProcessApiCallback<UpdatePlayerStatisticsResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Client/UpdatePlayerStatistics", L"X-Authorization", PlayFabSettings::clientSessionTicket, requestJson, OnUpdatePlayerStatisticsResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<UpdatePlayerStatisticsResult>(callback)), errorCallback, customData);
    }

    void PlayFabClientAPI::OnUpdatePlayerStatisticsResult(CallRequestContainer& request)
    {
        UpdatePlayerStatisticsResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<UpdatePlayerStatisticsResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabClientAPI::UpdateSharedGroupData(
        UpdateSharedGroupDataRequest& request,
        ProcessApiCallback<UpdateSharedGroupDataResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Client/UpdateSharedGroupData", L"X-Authorization", PlayFabSettings::clientSessionTicket, requestJson, OnUpdateSharedGroupDataResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<UpdateSharedGroupDataResult>(callback)), errorCallback, customData);
    }

    void PlayFabClientAPI::OnUpdateSharedGroupDataResult(CallRequestContainer& request)
    {
        UpdateSharedGroupDataResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<UpdateSharedGroupDataResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabClientAPI::UpdateUserData(
        UpdateUserDataRequest& request,
        ProcessApiCallback<UpdateUserDataResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Client/UpdateUserData", L"X-Authorization", PlayFabSettings::clientSessionTicket, requestJson, OnUpdateUserDataResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<UpdateUserDataResult>(callback)), errorCallback, customData);
    }

    void PlayFabClientAPI::OnUpdateUserDataResult(CallRequestContainer& request)
    {
        UpdateUserDataResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<UpdateUserDataResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabClientAPI::UpdateUserPublisherData(
        UpdateUserDataRequest& request,
        ProcessApiCallback<UpdateUserDataResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Client/UpdateUserPublisherData", L"X-Authorization", PlayFabSettings::clientSessionTicket, requestJson, OnUpdateUserPublisherDataResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<UpdateUserDataResult>(callback)), errorCallback, customData);
    }

    void PlayFabClientAPI::OnUpdateUserPublisherDataResult(CallRequestContainer& request)
    {
        UpdateUserDataResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<UpdateUserDataResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabClientAPI::UpdateUserTitleDisplayName(
        UpdateUserTitleDisplayNameRequest& request,
        ProcessApiCallback<UpdateUserTitleDisplayNameResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Client/UpdateUserTitleDisplayName", L"X-Authorization", PlayFabSettings::clientSessionTicket, requestJson, OnUpdateUserTitleDisplayNameResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<UpdateUserTitleDisplayNameResult>(callback)), errorCallback, customData);
    }

    void PlayFabClientAPI::OnUpdateUserTitleDisplayNameResult(CallRequestContainer& request)
    {
        UpdateUserTitleDisplayNameResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<UpdateUserTitleDisplayNameResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabClientAPI::ValidateAmazonIAPReceipt(
        ValidateAmazonReceiptRequest& request,
        ProcessApiCallback<ValidateAmazonReceiptResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Client/ValidateAmazonIAPReceipt", L"X-Authorization", PlayFabSettings::clientSessionTicket, requestJson, OnValidateAmazonIAPReceiptResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<ValidateAmazonReceiptResult>(callback)), errorCallback, customData);
    }

    void PlayFabClientAPI::OnValidateAmazonIAPReceiptResult(CallRequestContainer& request)
    {
        ValidateAmazonReceiptResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<ValidateAmazonReceiptResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabClientAPI::ValidateGooglePlayPurchase(
        ValidateGooglePlayPurchaseRequest& request,
        ProcessApiCallback<ValidateGooglePlayPurchaseResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Client/ValidateGooglePlayPurchase", L"X-Authorization", PlayFabSettings::clientSessionTicket, requestJson, OnValidateGooglePlayPurchaseResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<ValidateGooglePlayPurchaseResult>(callback)), errorCallback, customData);
    }

    void PlayFabClientAPI::OnValidateGooglePlayPurchaseResult(CallRequestContainer& request)
    {
        ValidateGooglePlayPurchaseResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<ValidateGooglePlayPurchaseResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabClientAPI::ValidateIOSReceipt(
        ValidateIOSReceiptRequest& request,
        ProcessApiCallback<ValidateIOSReceiptResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Client/ValidateIOSReceipt", L"X-Authorization", PlayFabSettings::clientSessionTicket, requestJson, OnValidateIOSReceiptResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<ValidateIOSReceiptResult>(callback)), errorCallback, customData);
    }

    void PlayFabClientAPI::OnValidateIOSReceiptResult(CallRequestContainer& request)
    {
        ValidateIOSReceiptResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<ValidateIOSReceiptResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabClientAPI::ValidateWindowsStoreReceipt(
        ValidateWindowsReceiptRequest& request,
        ProcessApiCallback<ValidateWindowsReceiptResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Client/ValidateWindowsStoreReceipt", L"X-Authorization", PlayFabSettings::clientSessionTicket, requestJson, OnValidateWindowsStoreReceiptResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<ValidateWindowsReceiptResult>(callback)), errorCallback, customData);
    }

    void PlayFabClientAPI::OnValidateWindowsStoreReceiptResult(CallRequestContainer& request)
    {
        ValidateWindowsReceiptResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<ValidateWindowsReceiptResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabClientAPI::WriteCharacterEvent(
        WriteClientCharacterEventRequest& request,
        ProcessApiCallback<WriteEventResponse> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Client/WriteCharacterEvent", L"X-Authorization", PlayFabSettings::clientSessionTicket, requestJson, OnWriteCharacterEventResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<WriteEventResponse>(callback)), errorCallback, customData);
    }

    void PlayFabClientAPI::OnWriteCharacterEventResult(CallRequestContainer& request)
    {
        WriteEventResponse outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<WriteEventResponse> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabClientAPI::WritePlayerEvent(
        WriteClientPlayerEventRequest& request,
        ProcessApiCallback<WriteEventResponse> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Client/WritePlayerEvent", L"X-Authorization", PlayFabSettings::clientSessionTicket, requestJson, OnWritePlayerEventResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<WriteEventResponse>(callback)), errorCallback, customData);
    }

    void PlayFabClientAPI::OnWritePlayerEventResult(CallRequestContainer& request)
    {
        WriteEventResponse outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<WriteEventResponse> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabClientAPI::WriteTitleEvent(
        WriteTitleEventRequest& request,
        ProcessApiCallback<WriteEventResponse> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Client/WriteTitleEvent", L"X-Authorization", PlayFabSettings::clientSessionTicket, requestJson, OnWriteTitleEventResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<WriteEventResponse>(callback)), errorCallback, customData);
    }

    void PlayFabClientAPI::OnWriteTitleEventResult(CallRequestContainer& request)
    {
        WriteEventResponse outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<WriteEventResponse> *>(internalPtr));
            callback(outResult, request.customData);
        }
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
                request.Idfa = ShortenString(PlayFabSettings::advertisingIdValue);
            else if (PlayFabSettings::advertisingIdType == PlayFabSettings::AD_TYPE_ANDROID_ID)
                request.Adid = ShortenString(PlayFabSettings::advertisingIdValue);
            else
                return;
            AttributeInstall(request, nullptr, nullptr);
        }
    }
}

#endif
