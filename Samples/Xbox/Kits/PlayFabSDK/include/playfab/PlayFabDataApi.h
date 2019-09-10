#pragma once

#ifdef ENABLE_PLAYFABENTITY_API

#include "playfab/PlayFabHttp.h"
#include "playfab/PlayFabDataDataModels.h"

namespace PlayFab
{
    /// <summary>
    /// Main interface for PlayFab Sdk, specifically all Data APIs
    /// </summary>
    class PlayFabDataAPI
    {
    public:
        static size_t Update();
        static void ForgetAllCredentials();


        // ------------ Generated API calls
        static void AbortFileUploads(DataModels::AbortFileUploadsRequest& request, ProcessApiCallback<DataModels::AbortFileUploadsResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void DeleteFiles(DataModels::DeleteFilesRequest& request, ProcessApiCallback<DataModels::DeleteFilesResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void FinalizeFileUploads(DataModels::FinalizeFileUploadsRequest& request, ProcessApiCallback<DataModels::FinalizeFileUploadsResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetFiles(DataModels::GetFilesRequest& request, ProcessApiCallback<DataModels::GetFilesResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetObjects(DataModels::GetObjectsRequest& request, ProcessApiCallback<DataModels::GetObjectsResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void InitiateFileUploads(DataModels::InitiateFileUploadsRequest& request, ProcessApiCallback<DataModels::InitiateFileUploadsResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void SetObjects(DataModels::SetObjectsRequest& request, ProcessApiCallback<DataModels::SetObjectsResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);

    private:
        PlayFabDataAPI(); // Private constructor, static class should never have an instance
        PlayFabDataAPI(const PlayFabDataAPI& other); // Private copy-constructor, static class should never have an instance

        // ------------ Generated result handlers
        static void OnAbortFileUploadsResult(CallRequestContainer& request);
        static void OnDeleteFilesResult(CallRequestContainer& request);
        static void OnFinalizeFileUploadsResult(CallRequestContainer& request);
        static void OnGetFilesResult(CallRequestContainer& request);
        static void OnGetObjectsResult(CallRequestContainer& request);
        static void OnInitiateFileUploadsResult(CallRequestContainer& request);
        static void OnSetObjectsResult(CallRequestContainer& request);

    };
}

#endif
