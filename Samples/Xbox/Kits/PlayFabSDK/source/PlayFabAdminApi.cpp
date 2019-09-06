
#ifdef ENABLE_PLAYFABADMIN_API

#include "playfab/PlayFabAdminApi.h"
#include "playfab/PlayFabHttp.h"
#include "playfab/PlayFabSettings.h"

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
        ProcessApiCallback<EmptyResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Admin/AbortTaskInstance", L"X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnAbortTaskInstanceResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<EmptyResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnAbortTaskInstanceResult(CallRequestContainer& request)
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

    void PlayFabAdminAPI::AddNews(
        AddNewsRequest& request,
        ProcessApiCallback<AddNewsResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Admin/AddNews", L"X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnAddNewsResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<AddNewsResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnAddNewsResult(CallRequestContainer& request)
    {
        AddNewsResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<AddNewsResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::AddPlayerTag(
        AddPlayerTagRequest& request,
        ProcessApiCallback<AddPlayerTagResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Admin/AddPlayerTag", L"X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnAddPlayerTagResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<AddPlayerTagResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnAddPlayerTagResult(CallRequestContainer& request)
    {
        AddPlayerTagResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<AddPlayerTagResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::AddServerBuild(
        AddServerBuildRequest& request,
        ProcessApiCallback<AddServerBuildResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Admin/AddServerBuild", L"X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnAddServerBuildResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<AddServerBuildResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnAddServerBuildResult(CallRequestContainer& request)
    {
        AddServerBuildResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<AddServerBuildResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::AddUserVirtualCurrency(
        AddUserVirtualCurrencyRequest& request,
        ProcessApiCallback<ModifyUserVirtualCurrencyResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Admin/AddUserVirtualCurrency", L"X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnAddUserVirtualCurrencyResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<ModifyUserVirtualCurrencyResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnAddUserVirtualCurrencyResult(CallRequestContainer& request)
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

    void PlayFabAdminAPI::AddVirtualCurrencyTypes(
        AddVirtualCurrencyTypesRequest& request,
        ProcessApiCallback<BlankResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Admin/AddVirtualCurrencyTypes", L"X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnAddVirtualCurrencyTypesResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<BlankResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnAddVirtualCurrencyTypesResult(CallRequestContainer& request)
    {
        BlankResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<BlankResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::BanUsers(
        BanUsersRequest& request,
        ProcessApiCallback<BanUsersResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Admin/BanUsers", L"X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnBanUsersResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<BanUsersResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnBanUsersResult(CallRequestContainer& request)
    {
        BanUsersResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<BanUsersResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::CheckLimitedEditionItemAvailability(
        CheckLimitedEditionItemAvailabilityRequest& request,
        ProcessApiCallback<CheckLimitedEditionItemAvailabilityResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Admin/CheckLimitedEditionItemAvailability", L"X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnCheckLimitedEditionItemAvailabilityResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<CheckLimitedEditionItemAvailabilityResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnCheckLimitedEditionItemAvailabilityResult(CallRequestContainer& request)
    {
        CheckLimitedEditionItemAvailabilityResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<CheckLimitedEditionItemAvailabilityResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::CreateActionsOnPlayersInSegmentTask(
        CreateActionsOnPlayerSegmentTaskRequest& request,
        ProcessApiCallback<CreateTaskResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Admin/CreateActionsOnPlayersInSegmentTask", L"X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnCreateActionsOnPlayersInSegmentTaskResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<CreateTaskResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnCreateActionsOnPlayersInSegmentTaskResult(CallRequestContainer& request)
    {
        CreateTaskResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<CreateTaskResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::CreateCloudScriptTask(
        CreateCloudScriptTaskRequest& request,
        ProcessApiCallback<CreateTaskResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Admin/CreateCloudScriptTask", L"X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnCreateCloudScriptTaskResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<CreateTaskResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnCreateCloudScriptTaskResult(CallRequestContainer& request)
    {
        CreateTaskResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<CreateTaskResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::CreatePlayerSharedSecret(
        CreatePlayerSharedSecretRequest& request,
        ProcessApiCallback<CreatePlayerSharedSecretResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Admin/CreatePlayerSharedSecret", L"X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnCreatePlayerSharedSecretResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<CreatePlayerSharedSecretResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnCreatePlayerSharedSecretResult(CallRequestContainer& request)
    {
        CreatePlayerSharedSecretResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<CreatePlayerSharedSecretResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::CreatePlayerStatisticDefinition(
        CreatePlayerStatisticDefinitionRequest& request,
        ProcessApiCallback<CreatePlayerStatisticDefinitionResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Admin/CreatePlayerStatisticDefinition", L"X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnCreatePlayerStatisticDefinitionResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<CreatePlayerStatisticDefinitionResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnCreatePlayerStatisticDefinitionResult(CallRequestContainer& request)
    {
        CreatePlayerStatisticDefinitionResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<CreatePlayerStatisticDefinitionResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::DeleteContent(
        DeleteContentRequest& request,
        ProcessApiCallback<BlankResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Admin/DeleteContent", L"X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnDeleteContentResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<BlankResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnDeleteContentResult(CallRequestContainer& request)
    {
        BlankResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<BlankResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::DeleteMasterPlayerAccount(
        DeleteMasterPlayerAccountRequest& request,
        ProcessApiCallback<DeleteMasterPlayerAccountResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Admin/DeleteMasterPlayerAccount", L"X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnDeleteMasterPlayerAccountResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<DeleteMasterPlayerAccountResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnDeleteMasterPlayerAccountResult(CallRequestContainer& request)
    {
        DeleteMasterPlayerAccountResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<DeleteMasterPlayerAccountResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::DeletePlayer(
        DeletePlayerRequest& request,
        ProcessApiCallback<DeletePlayerResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Admin/DeletePlayer", L"X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnDeletePlayerResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<DeletePlayerResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnDeletePlayerResult(CallRequestContainer& request)
    {
        DeletePlayerResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<DeletePlayerResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::DeletePlayerSharedSecret(
        DeletePlayerSharedSecretRequest& request,
        ProcessApiCallback<DeletePlayerSharedSecretResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Admin/DeletePlayerSharedSecret", L"X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnDeletePlayerSharedSecretResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<DeletePlayerSharedSecretResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnDeletePlayerSharedSecretResult(CallRequestContainer& request)
    {
        DeletePlayerSharedSecretResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<DeletePlayerSharedSecretResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::DeleteStore(
        DeleteStoreRequest& request,
        ProcessApiCallback<DeleteStoreResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Admin/DeleteStore", L"X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnDeleteStoreResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<DeleteStoreResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnDeleteStoreResult(CallRequestContainer& request)
    {
        DeleteStoreResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<DeleteStoreResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::DeleteTask(
        DeleteTaskRequest& request,
        ProcessApiCallback<EmptyResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Admin/DeleteTask", L"X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnDeleteTaskResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<EmptyResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnDeleteTaskResult(CallRequestContainer& request)
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

    void PlayFabAdminAPI::DeleteTitle(
        DeleteTitleRequest& request,
        ProcessApiCallback<DeleteTitleResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Admin/DeleteTitle", L"X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnDeleteTitleResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<DeleteTitleResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnDeleteTitleResult(CallRequestContainer& request)
    {
        DeleteTitleResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<DeleteTitleResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::ExportMasterPlayerData(
        ExportMasterPlayerDataRequest& request,
        ProcessApiCallback<ExportMasterPlayerDataResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Admin/ExportMasterPlayerData", L"X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnExportMasterPlayerDataResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<ExportMasterPlayerDataResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnExportMasterPlayerDataResult(CallRequestContainer& request)
    {
        ExportMasterPlayerDataResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<ExportMasterPlayerDataResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::GetActionsOnPlayersInSegmentTaskInstance(
        GetTaskInstanceRequest& request,
        ProcessApiCallback<GetActionsOnPlayersInSegmentTaskInstanceResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Admin/GetActionsOnPlayersInSegmentTaskInstance", L"X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnGetActionsOnPlayersInSegmentTaskInstanceResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetActionsOnPlayersInSegmentTaskInstanceResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnGetActionsOnPlayersInSegmentTaskInstanceResult(CallRequestContainer& request)
    {
        GetActionsOnPlayersInSegmentTaskInstanceResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<GetActionsOnPlayersInSegmentTaskInstanceResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::GetAllSegments(
        GetAllSegmentsRequest& request,
        ProcessApiCallback<GetAllSegmentsResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Admin/GetAllSegments", L"X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnGetAllSegmentsResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetAllSegmentsResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnGetAllSegmentsResult(CallRequestContainer& request)
    {
        GetAllSegmentsResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<GetAllSegmentsResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::GetCatalogItems(
        GetCatalogItemsRequest& request,
        ProcessApiCallback<GetCatalogItemsResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Admin/GetCatalogItems", L"X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnGetCatalogItemsResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetCatalogItemsResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnGetCatalogItemsResult(CallRequestContainer& request)
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

    void PlayFabAdminAPI::GetCloudScriptRevision(
        GetCloudScriptRevisionRequest& request,
        ProcessApiCallback<GetCloudScriptRevisionResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Admin/GetCloudScriptRevision", L"X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnGetCloudScriptRevisionResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetCloudScriptRevisionResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnGetCloudScriptRevisionResult(CallRequestContainer& request)
    {
        GetCloudScriptRevisionResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<GetCloudScriptRevisionResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::GetCloudScriptTaskInstance(
        GetTaskInstanceRequest& request,
        ProcessApiCallback<GetCloudScriptTaskInstanceResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Admin/GetCloudScriptTaskInstance", L"X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnGetCloudScriptTaskInstanceResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetCloudScriptTaskInstanceResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnGetCloudScriptTaskInstanceResult(CallRequestContainer& request)
    {
        GetCloudScriptTaskInstanceResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<GetCloudScriptTaskInstanceResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::GetCloudScriptVersions(
        GetCloudScriptVersionsRequest& request,
        ProcessApiCallback<GetCloudScriptVersionsResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Admin/GetCloudScriptVersions", L"X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnGetCloudScriptVersionsResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetCloudScriptVersionsResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnGetCloudScriptVersionsResult(CallRequestContainer& request)
    {
        GetCloudScriptVersionsResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<GetCloudScriptVersionsResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::GetContentList(
        GetContentListRequest& request,
        ProcessApiCallback<GetContentListResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Admin/GetContentList", L"X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnGetContentListResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetContentListResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnGetContentListResult(CallRequestContainer& request)
    {
        GetContentListResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<GetContentListResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::GetContentUploadUrl(
        GetContentUploadUrlRequest& request,
        ProcessApiCallback<GetContentUploadUrlResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Admin/GetContentUploadUrl", L"X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnGetContentUploadUrlResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetContentUploadUrlResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnGetContentUploadUrlResult(CallRequestContainer& request)
    {
        GetContentUploadUrlResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<GetContentUploadUrlResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::GetDataReport(
        GetDataReportRequest& request,
        ProcessApiCallback<GetDataReportResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Admin/GetDataReport", L"X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnGetDataReportResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetDataReportResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnGetDataReportResult(CallRequestContainer& request)
    {
        GetDataReportResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<GetDataReportResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::GetMatchmakerGameInfo(
        GetMatchmakerGameInfoRequest& request,
        ProcessApiCallback<GetMatchmakerGameInfoResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Admin/GetMatchmakerGameInfo", L"X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnGetMatchmakerGameInfoResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetMatchmakerGameInfoResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnGetMatchmakerGameInfoResult(CallRequestContainer& request)
    {
        GetMatchmakerGameInfoResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<GetMatchmakerGameInfoResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::GetMatchmakerGameModes(
        GetMatchmakerGameModesRequest& request,
        ProcessApiCallback<GetMatchmakerGameModesResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Admin/GetMatchmakerGameModes", L"X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnGetMatchmakerGameModesResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetMatchmakerGameModesResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnGetMatchmakerGameModesResult(CallRequestContainer& request)
    {
        GetMatchmakerGameModesResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<GetMatchmakerGameModesResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::GetPlayedTitleList(
        GetPlayedTitleListRequest& request,
        ProcessApiCallback<GetPlayedTitleListResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Admin/GetPlayedTitleList", L"X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnGetPlayedTitleListResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetPlayedTitleListResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnGetPlayedTitleListResult(CallRequestContainer& request)
    {
        GetPlayedTitleListResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<GetPlayedTitleListResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::GetPlayerIdFromAuthToken(
        GetPlayerIdFromAuthTokenRequest& request,
        ProcessApiCallback<GetPlayerIdFromAuthTokenResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Admin/GetPlayerIdFromAuthToken", L"X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnGetPlayerIdFromAuthTokenResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetPlayerIdFromAuthTokenResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnGetPlayerIdFromAuthTokenResult(CallRequestContainer& request)
    {
        GetPlayerIdFromAuthTokenResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<GetPlayerIdFromAuthTokenResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::GetPlayerProfile(
        GetPlayerProfileRequest& request,
        ProcessApiCallback<GetPlayerProfileResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Admin/GetPlayerProfile", L"X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnGetPlayerProfileResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetPlayerProfileResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnGetPlayerProfileResult(CallRequestContainer& request)
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

    void PlayFabAdminAPI::GetPlayerSegments(
        GetPlayersSegmentsRequest& request,
        ProcessApiCallback<GetPlayerSegmentsResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Admin/GetPlayerSegments", L"X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnGetPlayerSegmentsResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetPlayerSegmentsResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnGetPlayerSegmentsResult(CallRequestContainer& request)
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

    void PlayFabAdminAPI::GetPlayerSharedSecrets(
        GetPlayerSharedSecretsRequest& request,
        ProcessApiCallback<GetPlayerSharedSecretsResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Admin/GetPlayerSharedSecrets", L"X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnGetPlayerSharedSecretsResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetPlayerSharedSecretsResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnGetPlayerSharedSecretsResult(CallRequestContainer& request)
    {
        GetPlayerSharedSecretsResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<GetPlayerSharedSecretsResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::GetPlayersInSegment(
        GetPlayersInSegmentRequest& request,
        ProcessApiCallback<GetPlayersInSegmentResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Admin/GetPlayersInSegment", L"X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnGetPlayersInSegmentResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetPlayersInSegmentResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnGetPlayersInSegmentResult(CallRequestContainer& request)
    {
        GetPlayersInSegmentResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<GetPlayersInSegmentResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::GetPlayerStatisticDefinitions(
        GetPlayerStatisticDefinitionsRequest& request,
        ProcessApiCallback<GetPlayerStatisticDefinitionsResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Admin/GetPlayerStatisticDefinitions", L"X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnGetPlayerStatisticDefinitionsResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetPlayerStatisticDefinitionsResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnGetPlayerStatisticDefinitionsResult(CallRequestContainer& request)
    {
        GetPlayerStatisticDefinitionsResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<GetPlayerStatisticDefinitionsResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::GetPlayerStatisticVersions(
        GetPlayerStatisticVersionsRequest& request,
        ProcessApiCallback<GetPlayerStatisticVersionsResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Admin/GetPlayerStatisticVersions", L"X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnGetPlayerStatisticVersionsResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetPlayerStatisticVersionsResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnGetPlayerStatisticVersionsResult(CallRequestContainer& request)
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

    void PlayFabAdminAPI::GetPlayerTags(
        GetPlayerTagsRequest& request,
        ProcessApiCallback<GetPlayerTagsResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Admin/GetPlayerTags", L"X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnGetPlayerTagsResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetPlayerTagsResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnGetPlayerTagsResult(CallRequestContainer& request)
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

    void PlayFabAdminAPI::GetPolicy(
        GetPolicyRequest& request,
        ProcessApiCallback<GetPolicyResponse> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Admin/GetPolicy", L"X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnGetPolicyResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetPolicyResponse>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnGetPolicyResult(CallRequestContainer& request)
    {
        GetPolicyResponse outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<GetPolicyResponse> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::GetPublisherData(
        GetPublisherDataRequest& request,
        ProcessApiCallback<GetPublisherDataResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Admin/GetPublisherData", L"X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnGetPublisherDataResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetPublisherDataResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnGetPublisherDataResult(CallRequestContainer& request)
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

    void PlayFabAdminAPI::GetRandomResultTables(
        GetRandomResultTablesRequest& request,
        ProcessApiCallback<GetRandomResultTablesResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Admin/GetRandomResultTables", L"X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnGetRandomResultTablesResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetRandomResultTablesResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnGetRandomResultTablesResult(CallRequestContainer& request)
    {
        GetRandomResultTablesResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<GetRandomResultTablesResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::GetServerBuildInfo(
        GetServerBuildInfoRequest& request,
        ProcessApiCallback<GetServerBuildInfoResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Admin/GetServerBuildInfo", L"X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnGetServerBuildInfoResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetServerBuildInfoResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnGetServerBuildInfoResult(CallRequestContainer& request)
    {
        GetServerBuildInfoResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<GetServerBuildInfoResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::GetServerBuildUploadUrl(
        GetServerBuildUploadURLRequest& request,
        ProcessApiCallback<GetServerBuildUploadURLResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Admin/GetServerBuildUploadUrl", L"X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnGetServerBuildUploadUrlResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetServerBuildUploadURLResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnGetServerBuildUploadUrlResult(CallRequestContainer& request)
    {
        GetServerBuildUploadURLResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<GetServerBuildUploadURLResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::GetStoreItems(
        GetStoreItemsRequest& request,
        ProcessApiCallback<GetStoreItemsResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Admin/GetStoreItems", L"X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnGetStoreItemsResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetStoreItemsResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnGetStoreItemsResult(CallRequestContainer& request)
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

    void PlayFabAdminAPI::GetTaskInstances(
        GetTaskInstancesRequest& request,
        ProcessApiCallback<GetTaskInstancesResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Admin/GetTaskInstances", L"X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnGetTaskInstancesResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetTaskInstancesResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnGetTaskInstancesResult(CallRequestContainer& request)
    {
        GetTaskInstancesResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<GetTaskInstancesResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::GetTasks(
        GetTasksRequest& request,
        ProcessApiCallback<GetTasksResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Admin/GetTasks", L"X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnGetTasksResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetTasksResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnGetTasksResult(CallRequestContainer& request)
    {
        GetTasksResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<GetTasksResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::GetTitleData(
        GetTitleDataRequest& request,
        ProcessApiCallback<GetTitleDataResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Admin/GetTitleData", L"X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnGetTitleDataResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetTitleDataResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnGetTitleDataResult(CallRequestContainer& request)
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

    void PlayFabAdminAPI::GetTitleInternalData(
        GetTitleDataRequest& request,
        ProcessApiCallback<GetTitleDataResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Admin/GetTitleInternalData", L"X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnGetTitleInternalDataResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetTitleDataResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnGetTitleInternalDataResult(CallRequestContainer& request)
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

    void PlayFabAdminAPI::GetUserAccountInfo(
        LookupUserAccountInfoRequest& request,
        ProcessApiCallback<LookupUserAccountInfoResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Admin/GetUserAccountInfo", L"X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnGetUserAccountInfoResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<LookupUserAccountInfoResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnGetUserAccountInfoResult(CallRequestContainer& request)
    {
        LookupUserAccountInfoResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<LookupUserAccountInfoResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::GetUserBans(
        GetUserBansRequest& request,
        ProcessApiCallback<GetUserBansResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Admin/GetUserBans", L"X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnGetUserBansResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetUserBansResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnGetUserBansResult(CallRequestContainer& request)
    {
        GetUserBansResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<GetUserBansResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::GetUserData(
        GetUserDataRequest& request,
        ProcessApiCallback<GetUserDataResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Admin/GetUserData", L"X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnGetUserDataResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetUserDataResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnGetUserDataResult(CallRequestContainer& request)
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

    void PlayFabAdminAPI::GetUserInternalData(
        GetUserDataRequest& request,
        ProcessApiCallback<GetUserDataResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Admin/GetUserInternalData", L"X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnGetUserInternalDataResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetUserDataResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnGetUserInternalDataResult(CallRequestContainer& request)
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

    void PlayFabAdminAPI::GetUserInventory(
        GetUserInventoryRequest& request,
        ProcessApiCallback<GetUserInventoryResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Admin/GetUserInventory", L"X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnGetUserInventoryResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetUserInventoryResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnGetUserInventoryResult(CallRequestContainer& request)
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

    void PlayFabAdminAPI::GetUserPublisherData(
        GetUserDataRequest& request,
        ProcessApiCallback<GetUserDataResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Admin/GetUserPublisherData", L"X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnGetUserPublisherDataResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetUserDataResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnGetUserPublisherDataResult(CallRequestContainer& request)
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

    void PlayFabAdminAPI::GetUserPublisherInternalData(
        GetUserDataRequest& request,
        ProcessApiCallback<GetUserDataResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Admin/GetUserPublisherInternalData", L"X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnGetUserPublisherInternalDataResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetUserDataResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnGetUserPublisherInternalDataResult(CallRequestContainer& request)
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

    void PlayFabAdminAPI::GetUserPublisherReadOnlyData(
        GetUserDataRequest& request,
        ProcessApiCallback<GetUserDataResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Admin/GetUserPublisherReadOnlyData", L"X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnGetUserPublisherReadOnlyDataResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetUserDataResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnGetUserPublisherReadOnlyDataResult(CallRequestContainer& request)
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

    void PlayFabAdminAPI::GetUserReadOnlyData(
        GetUserDataRequest& request,
        ProcessApiCallback<GetUserDataResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Admin/GetUserReadOnlyData", L"X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnGetUserReadOnlyDataResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetUserDataResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnGetUserReadOnlyDataResult(CallRequestContainer& request)
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

    void PlayFabAdminAPI::GrantItemsToUsers(
        GrantItemsToUsersRequest& request,
        ProcessApiCallback<GrantItemsToUsersResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Admin/GrantItemsToUsers", L"X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnGrantItemsToUsersResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GrantItemsToUsersResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnGrantItemsToUsersResult(CallRequestContainer& request)
    {
        GrantItemsToUsersResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<GrantItemsToUsersResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::IncrementLimitedEditionItemAvailability(
        IncrementLimitedEditionItemAvailabilityRequest& request,
        ProcessApiCallback<IncrementLimitedEditionItemAvailabilityResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Admin/IncrementLimitedEditionItemAvailability", L"X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnIncrementLimitedEditionItemAvailabilityResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<IncrementLimitedEditionItemAvailabilityResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnIncrementLimitedEditionItemAvailabilityResult(CallRequestContainer& request)
    {
        IncrementLimitedEditionItemAvailabilityResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<IncrementLimitedEditionItemAvailabilityResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::IncrementPlayerStatisticVersion(
        IncrementPlayerStatisticVersionRequest& request,
        ProcessApiCallback<IncrementPlayerStatisticVersionResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Admin/IncrementPlayerStatisticVersion", L"X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnIncrementPlayerStatisticVersionResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<IncrementPlayerStatisticVersionResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnIncrementPlayerStatisticVersionResult(CallRequestContainer& request)
    {
        IncrementPlayerStatisticVersionResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<IncrementPlayerStatisticVersionResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::ListServerBuilds(
        ListBuildsRequest& request,
        ProcessApiCallback<ListBuildsResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Admin/ListServerBuilds", L"X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnListServerBuildsResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<ListBuildsResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnListServerBuildsResult(CallRequestContainer& request)
    {
        ListBuildsResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<ListBuildsResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::ListVirtualCurrencyTypes(
        ListVirtualCurrencyTypesRequest& request,
        ProcessApiCallback<ListVirtualCurrencyTypesResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Admin/ListVirtualCurrencyTypes", L"X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnListVirtualCurrencyTypesResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<ListVirtualCurrencyTypesResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnListVirtualCurrencyTypesResult(CallRequestContainer& request)
    {
        ListVirtualCurrencyTypesResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<ListVirtualCurrencyTypesResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::ModifyMatchmakerGameModes(
        ModifyMatchmakerGameModesRequest& request,
        ProcessApiCallback<ModifyMatchmakerGameModesResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Admin/ModifyMatchmakerGameModes", L"X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnModifyMatchmakerGameModesResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<ModifyMatchmakerGameModesResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnModifyMatchmakerGameModesResult(CallRequestContainer& request)
    {
        ModifyMatchmakerGameModesResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<ModifyMatchmakerGameModesResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::ModifyServerBuild(
        ModifyServerBuildRequest& request,
        ProcessApiCallback<ModifyServerBuildResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Admin/ModifyServerBuild", L"X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnModifyServerBuildResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<ModifyServerBuildResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnModifyServerBuildResult(CallRequestContainer& request)
    {
        ModifyServerBuildResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<ModifyServerBuildResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::RefundPurchase(
        RefundPurchaseRequest& request,
        ProcessApiCallback<RefundPurchaseResponse> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Admin/RefundPurchase", L"X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnRefundPurchaseResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<RefundPurchaseResponse>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnRefundPurchaseResult(CallRequestContainer& request)
    {
        RefundPurchaseResponse outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<RefundPurchaseResponse> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::RemovePlayerTag(
        RemovePlayerTagRequest& request,
        ProcessApiCallback<RemovePlayerTagResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Admin/RemovePlayerTag", L"X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnRemovePlayerTagResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<RemovePlayerTagResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnRemovePlayerTagResult(CallRequestContainer& request)
    {
        RemovePlayerTagResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<RemovePlayerTagResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::RemoveServerBuild(
        RemoveServerBuildRequest& request,
        ProcessApiCallback<RemoveServerBuildResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Admin/RemoveServerBuild", L"X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnRemoveServerBuildResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<RemoveServerBuildResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnRemoveServerBuildResult(CallRequestContainer& request)
    {
        RemoveServerBuildResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<RemoveServerBuildResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::RemoveVirtualCurrencyTypes(
        RemoveVirtualCurrencyTypesRequest& request,
        ProcessApiCallback<BlankResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Admin/RemoveVirtualCurrencyTypes", L"X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnRemoveVirtualCurrencyTypesResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<BlankResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnRemoveVirtualCurrencyTypesResult(CallRequestContainer& request)
    {
        BlankResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<BlankResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::ResetCharacterStatistics(
        ResetCharacterStatisticsRequest& request,
        ProcessApiCallback<ResetCharacterStatisticsResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Admin/ResetCharacterStatistics", L"X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnResetCharacterStatisticsResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<ResetCharacterStatisticsResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnResetCharacterStatisticsResult(CallRequestContainer& request)
    {
        ResetCharacterStatisticsResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<ResetCharacterStatisticsResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::ResetPassword(
        ResetPasswordRequest& request,
        ProcessApiCallback<ResetPasswordResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Admin/ResetPassword", L"X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnResetPasswordResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<ResetPasswordResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnResetPasswordResult(CallRequestContainer& request)
    {
        ResetPasswordResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<ResetPasswordResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::ResetUserStatistics(
        ResetUserStatisticsRequest& request,
        ProcessApiCallback<ResetUserStatisticsResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Admin/ResetUserStatistics", L"X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnResetUserStatisticsResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<ResetUserStatisticsResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnResetUserStatisticsResult(CallRequestContainer& request)
    {
        ResetUserStatisticsResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<ResetUserStatisticsResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::ResolvePurchaseDispute(
        ResolvePurchaseDisputeRequest& request,
        ProcessApiCallback<ResolvePurchaseDisputeResponse> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Admin/ResolvePurchaseDispute", L"X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnResolvePurchaseDisputeResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<ResolvePurchaseDisputeResponse>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnResolvePurchaseDisputeResult(CallRequestContainer& request)
    {
        ResolvePurchaseDisputeResponse outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<ResolvePurchaseDisputeResponse> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::RevokeAllBansForUser(
        RevokeAllBansForUserRequest& request,
        ProcessApiCallback<RevokeAllBansForUserResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Admin/RevokeAllBansForUser", L"X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnRevokeAllBansForUserResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<RevokeAllBansForUserResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnRevokeAllBansForUserResult(CallRequestContainer& request)
    {
        RevokeAllBansForUserResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<RevokeAllBansForUserResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::RevokeBans(
        RevokeBansRequest& request,
        ProcessApiCallback<RevokeBansResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Admin/RevokeBans", L"X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnRevokeBansResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<RevokeBansResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnRevokeBansResult(CallRequestContainer& request)
    {
        RevokeBansResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<RevokeBansResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::RevokeInventoryItem(
        RevokeInventoryItemRequest& request,
        ProcessApiCallback<RevokeInventoryResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Admin/RevokeInventoryItem", L"X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnRevokeInventoryItemResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<RevokeInventoryResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnRevokeInventoryItemResult(CallRequestContainer& request)
    {
        RevokeInventoryResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<RevokeInventoryResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::RevokeInventoryItems(
        RevokeInventoryItemsRequest& request,
        ProcessApiCallback<RevokeInventoryItemsResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Admin/RevokeInventoryItems", L"X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnRevokeInventoryItemsResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<RevokeInventoryItemsResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnRevokeInventoryItemsResult(CallRequestContainer& request)
    {
        RevokeInventoryItemsResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<RevokeInventoryItemsResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::RunTask(
        RunTaskRequest& request,
        ProcessApiCallback<RunTaskResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Admin/RunTask", L"X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnRunTaskResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<RunTaskResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnRunTaskResult(CallRequestContainer& request)
    {
        RunTaskResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<RunTaskResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::SendAccountRecoveryEmail(
        SendAccountRecoveryEmailRequest& request,
        ProcessApiCallback<SendAccountRecoveryEmailResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Admin/SendAccountRecoveryEmail", L"X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnSendAccountRecoveryEmailResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<SendAccountRecoveryEmailResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnSendAccountRecoveryEmailResult(CallRequestContainer& request)
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

    void PlayFabAdminAPI::SetCatalogItems(
        UpdateCatalogItemsRequest& request,
        ProcessApiCallback<UpdateCatalogItemsResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Admin/SetCatalogItems", L"X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnSetCatalogItemsResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<UpdateCatalogItemsResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnSetCatalogItemsResult(CallRequestContainer& request)
    {
        UpdateCatalogItemsResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<UpdateCatalogItemsResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::SetPlayerSecret(
        SetPlayerSecretRequest& request,
        ProcessApiCallback<SetPlayerSecretResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Admin/SetPlayerSecret", L"X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnSetPlayerSecretResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<SetPlayerSecretResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnSetPlayerSecretResult(CallRequestContainer& request)
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

    void PlayFabAdminAPI::SetPublishedRevision(
        SetPublishedRevisionRequest& request,
        ProcessApiCallback<SetPublishedRevisionResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Admin/SetPublishedRevision", L"X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnSetPublishedRevisionResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<SetPublishedRevisionResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnSetPublishedRevisionResult(CallRequestContainer& request)
    {
        SetPublishedRevisionResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<SetPublishedRevisionResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::SetPublisherData(
        SetPublisherDataRequest& request,
        ProcessApiCallback<SetPublisherDataResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Admin/SetPublisherData", L"X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnSetPublisherDataResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<SetPublisherDataResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnSetPublisherDataResult(CallRequestContainer& request)
    {
        SetPublisherDataResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<SetPublisherDataResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::SetStoreItems(
        UpdateStoreItemsRequest& request,
        ProcessApiCallback<UpdateStoreItemsResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Admin/SetStoreItems", L"X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnSetStoreItemsResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<UpdateStoreItemsResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnSetStoreItemsResult(CallRequestContainer& request)
    {
        UpdateStoreItemsResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<UpdateStoreItemsResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::SetTitleData(
        SetTitleDataRequest& request,
        ProcessApiCallback<SetTitleDataResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Admin/SetTitleData", L"X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnSetTitleDataResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<SetTitleDataResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnSetTitleDataResult(CallRequestContainer& request)
    {
        SetTitleDataResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<SetTitleDataResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::SetTitleInternalData(
        SetTitleDataRequest& request,
        ProcessApiCallback<SetTitleDataResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Admin/SetTitleInternalData", L"X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnSetTitleInternalDataResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<SetTitleDataResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnSetTitleInternalDataResult(CallRequestContainer& request)
    {
        SetTitleDataResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<SetTitleDataResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::SetupPushNotification(
        SetupPushNotificationRequest& request,
        ProcessApiCallback<SetupPushNotificationResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Admin/SetupPushNotification", L"X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnSetupPushNotificationResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<SetupPushNotificationResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnSetupPushNotificationResult(CallRequestContainer& request)
    {
        SetupPushNotificationResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<SetupPushNotificationResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::SubtractUserVirtualCurrency(
        SubtractUserVirtualCurrencyRequest& request,
        ProcessApiCallback<ModifyUserVirtualCurrencyResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Admin/SubtractUserVirtualCurrency", L"X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnSubtractUserVirtualCurrencyResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<ModifyUserVirtualCurrencyResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnSubtractUserVirtualCurrencyResult(CallRequestContainer& request)
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

    void PlayFabAdminAPI::UpdateBans(
        UpdateBansRequest& request,
        ProcessApiCallback<UpdateBansResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Admin/UpdateBans", L"X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnUpdateBansResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<UpdateBansResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnUpdateBansResult(CallRequestContainer& request)
    {
        UpdateBansResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<UpdateBansResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::UpdateCatalogItems(
        UpdateCatalogItemsRequest& request,
        ProcessApiCallback<UpdateCatalogItemsResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Admin/UpdateCatalogItems", L"X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnUpdateCatalogItemsResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<UpdateCatalogItemsResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnUpdateCatalogItemsResult(CallRequestContainer& request)
    {
        UpdateCatalogItemsResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<UpdateCatalogItemsResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::UpdateCloudScript(
        UpdateCloudScriptRequest& request,
        ProcessApiCallback<UpdateCloudScriptResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Admin/UpdateCloudScript", L"X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnUpdateCloudScriptResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<UpdateCloudScriptResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnUpdateCloudScriptResult(CallRequestContainer& request)
    {
        UpdateCloudScriptResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<UpdateCloudScriptResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::UpdatePlayerSharedSecret(
        UpdatePlayerSharedSecretRequest& request,
        ProcessApiCallback<UpdatePlayerSharedSecretResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Admin/UpdatePlayerSharedSecret", L"X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnUpdatePlayerSharedSecretResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<UpdatePlayerSharedSecretResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnUpdatePlayerSharedSecretResult(CallRequestContainer& request)
    {
        UpdatePlayerSharedSecretResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<UpdatePlayerSharedSecretResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::UpdatePlayerStatisticDefinition(
        UpdatePlayerStatisticDefinitionRequest& request,
        ProcessApiCallback<UpdatePlayerStatisticDefinitionResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Admin/UpdatePlayerStatisticDefinition", L"X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnUpdatePlayerStatisticDefinitionResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<UpdatePlayerStatisticDefinitionResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnUpdatePlayerStatisticDefinitionResult(CallRequestContainer& request)
    {
        UpdatePlayerStatisticDefinitionResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<UpdatePlayerStatisticDefinitionResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::UpdatePolicy(
        UpdatePolicyRequest& request,
        ProcessApiCallback<UpdatePolicyResponse> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Admin/UpdatePolicy", L"X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnUpdatePolicyResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<UpdatePolicyResponse>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnUpdatePolicyResult(CallRequestContainer& request)
    {
        UpdatePolicyResponse outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<UpdatePolicyResponse> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::UpdateRandomResultTables(
        UpdateRandomResultTablesRequest& request,
        ProcessApiCallback<UpdateRandomResultTablesResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Admin/UpdateRandomResultTables", L"X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnUpdateRandomResultTablesResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<UpdateRandomResultTablesResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnUpdateRandomResultTablesResult(CallRequestContainer& request)
    {
        UpdateRandomResultTablesResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<UpdateRandomResultTablesResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::UpdateStoreItems(
        UpdateStoreItemsRequest& request,
        ProcessApiCallback<UpdateStoreItemsResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Admin/UpdateStoreItems", L"X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnUpdateStoreItemsResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<UpdateStoreItemsResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnUpdateStoreItemsResult(CallRequestContainer& request)
    {
        UpdateStoreItemsResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<UpdateStoreItemsResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabAdminAPI::UpdateTask(
        UpdateTaskRequest& request,
        ProcessApiCallback<EmptyResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Admin/UpdateTask", L"X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnUpdateTaskResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<EmptyResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnUpdateTaskResult(CallRequestContainer& request)
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

    void PlayFabAdminAPI::UpdateUserData(
        UpdateUserDataRequest& request,
        ProcessApiCallback<UpdateUserDataResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Admin/UpdateUserData", L"X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnUpdateUserDataResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<UpdateUserDataResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnUpdateUserDataResult(CallRequestContainer& request)
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

    void PlayFabAdminAPI::UpdateUserInternalData(
        UpdateUserInternalDataRequest& request,
        ProcessApiCallback<UpdateUserDataResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Admin/UpdateUserInternalData", L"X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnUpdateUserInternalDataResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<UpdateUserDataResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnUpdateUserInternalDataResult(CallRequestContainer& request)
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

    void PlayFabAdminAPI::UpdateUserPublisherData(
        UpdateUserDataRequest& request,
        ProcessApiCallback<UpdateUserDataResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Admin/UpdateUserPublisherData", L"X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnUpdateUserPublisherDataResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<UpdateUserDataResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnUpdateUserPublisherDataResult(CallRequestContainer& request)
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

    void PlayFabAdminAPI::UpdateUserPublisherInternalData(
        UpdateUserInternalDataRequest& request,
        ProcessApiCallback<UpdateUserDataResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Admin/UpdateUserPublisherInternalData", L"X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnUpdateUserPublisherInternalDataResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<UpdateUserDataResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnUpdateUserPublisherInternalDataResult(CallRequestContainer& request)
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

    void PlayFabAdminAPI::UpdateUserPublisherReadOnlyData(
        UpdateUserDataRequest& request,
        ProcessApiCallback<UpdateUserDataResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Admin/UpdateUserPublisherReadOnlyData", L"X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnUpdateUserPublisherReadOnlyDataResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<UpdateUserDataResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnUpdateUserPublisherReadOnlyDataResult(CallRequestContainer& request)
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

    void PlayFabAdminAPI::UpdateUserReadOnlyData(
        UpdateUserDataRequest& request,
        ProcessApiCallback<UpdateUserDataResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Admin/UpdateUserReadOnlyData", L"X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnUpdateUserReadOnlyDataResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<UpdateUserDataResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnUpdateUserReadOnlyDataResult(CallRequestContainer& request)
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

    void PlayFabAdminAPI::UpdateUserTitleDisplayName(
        UpdateUserTitleDisplayNameRequest& request,
        ProcessApiCallback<UpdateUserTitleDisplayNameResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Admin/UpdateUserTitleDisplayName", L"X-SecretKey", PlayFabSettings::developerSecretKey, requestJson, OnUpdateUserTitleDisplayNameResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<UpdateUserTitleDisplayNameResult>(callback)), errorCallback, customData);
    }

    void PlayFabAdminAPI::OnUpdateUserTitleDisplayNameResult(CallRequestContainer& request)
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
}

#endif
