
#ifdef ENABLE_PLAYFABENTITY_API

#include "playfab/PlayFabDataApi.h"
#include "playfab/PlayFabHttp.h"
#include "playfab/PlayFabSettings.h"

namespace PlayFab
{
    using namespace DataModels;

    size_t PlayFabDataAPI::Update()
    {
        return PlayFabHttp::Get().Update();
    }

    void PlayFabDataAPI::ForgetAllCredentials()
    {
        return PlayFabSettings::ForgetAllCredentials();
    }

    // PlayFabData APIs

    void PlayFabDataAPI::AbortFileUploads(
        AbortFileUploadsRequest& request,
        ProcessApiCallback<AbortFileUploadsResponse> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/File/AbortFileUploads", L"X-EntityToken", PlayFabSettings::entityToken, requestJson, OnAbortFileUploadsResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<AbortFileUploadsResponse>(callback)), errorCallback, customData);
    }

    void PlayFabDataAPI::OnAbortFileUploadsResult(CallRequestContainer& request)
    {
        AbortFileUploadsResponse outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<AbortFileUploadsResponse> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabDataAPI::DeleteFiles(
        DeleteFilesRequest& request,
        ProcessApiCallback<DeleteFilesResponse> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/File/DeleteFiles", L"X-EntityToken", PlayFabSettings::entityToken, requestJson, OnDeleteFilesResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<DeleteFilesResponse>(callback)), errorCallback, customData);
    }

    void PlayFabDataAPI::OnDeleteFilesResult(CallRequestContainer& request)
    {
        DeleteFilesResponse outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<DeleteFilesResponse> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabDataAPI::FinalizeFileUploads(
        FinalizeFileUploadsRequest& request,
        ProcessApiCallback<FinalizeFileUploadsResponse> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/File/FinalizeFileUploads", L"X-EntityToken", PlayFabSettings::entityToken, requestJson, OnFinalizeFileUploadsResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<FinalizeFileUploadsResponse>(callback)), errorCallback, customData);
    }

    void PlayFabDataAPI::OnFinalizeFileUploadsResult(CallRequestContainer& request)
    {
        FinalizeFileUploadsResponse outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<FinalizeFileUploadsResponse> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabDataAPI::GetFiles(
        GetFilesRequest& request,
        ProcessApiCallback<GetFilesResponse> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/File/GetFiles", L"X-EntityToken", PlayFabSettings::entityToken, requestJson, OnGetFilesResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetFilesResponse>(callback)), errorCallback, customData);
    }

    void PlayFabDataAPI::OnGetFilesResult(CallRequestContainer& request)
    {
        GetFilesResponse outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<GetFilesResponse> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabDataAPI::GetObjects(
        GetObjectsRequest& request,
        ProcessApiCallback<GetObjectsResponse> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Object/GetObjects", L"X-EntityToken", PlayFabSettings::entityToken, requestJson, OnGetObjectsResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetObjectsResponse>(callback)), errorCallback, customData);
    }

    void PlayFabDataAPI::OnGetObjectsResult(CallRequestContainer& request)
    {
        GetObjectsResponse outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<GetObjectsResponse> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabDataAPI::InitiateFileUploads(
        InitiateFileUploadsRequest& request,
        ProcessApiCallback<InitiateFileUploadsResponse> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/File/InitiateFileUploads", L"X-EntityToken", PlayFabSettings::entityToken, requestJson, OnInitiateFileUploadsResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<InitiateFileUploadsResponse>(callback)), errorCallback, customData);
    }

    void PlayFabDataAPI::OnInitiateFileUploadsResult(CallRequestContainer& request)
    {
        InitiateFileUploadsResponse outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<InitiateFileUploadsResponse> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabDataAPI::SetObjects(
        SetObjectsRequest& request,
        ProcessApiCallback<SetObjectsResponse> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Object/SetObjects", L"X-EntityToken", PlayFabSettings::entityToken, requestJson, OnSetObjectsResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<SetObjectsResponse>(callback)), errorCallback, customData);
    }

    void PlayFabDataAPI::OnSetObjectsResult(CallRequestContainer& request)
    {
        SetObjectsResponse outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<SetObjectsResponse> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }
}

#endif
