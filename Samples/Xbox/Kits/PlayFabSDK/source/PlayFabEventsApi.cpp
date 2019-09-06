
#ifdef ENABLE_PLAYFABENTITY_API

#include "playfab/PlayFabEventsApi.h"
#include "playfab/PlayFabHttp.h"
#include "playfab/PlayFabSettings.h"

namespace PlayFab
{
    using namespace EventsModels;

    size_t PlayFabEventsAPI::Update()
    {
        return PlayFabHttp::Get().Update();
    }

    void PlayFabEventsAPI::ForgetAllCredentials()
    {
        return PlayFabSettings::ForgetAllCredentials();
    }

    // PlayFabEvents APIs

    void PlayFabEventsAPI::WriteEvents(
        WriteEventsRequest& request,
        ProcessApiCallback<WriteEventsResponse> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Event/WriteEvents", L"X-EntityToken", PlayFabSettings::entityToken, requestJson, OnWriteEventsResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<WriteEventsResponse>(callback)), errorCallback, customData);
    }

    void PlayFabEventsAPI::OnWriteEventsResult(CallRequestContainer& request)
    {
        WriteEventsResponse outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<WriteEventsResponse> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }
}

#endif
