
#ifdef ENABLE_PLAYFABENTITY_API

#include "playfab/PlayFabAuthenticationApi.h"
#include "playfab/PlayFabHttp.h"
#include "playfab/PlayFabSettings.h"

namespace PlayFab
{
    using namespace AuthenticationModels;

    size_t PlayFabAuthenticationAPI::Update()
    {
        return PlayFabHttp::Get().Update();
    }

    void PlayFabAuthenticationAPI::ForgetAllCredentials()
    {
        return PlayFabSettings::ForgetAllCredentials();
    }

    // PlayFabAuthentication APIs

    void PlayFabAuthenticationAPI::GetEntityToken(
        GetEntityTokenRequest& request,
        ProcessApiCallback<GetEntityTokenResponse> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {
        utility::string_t authKey, authValue;
        if (PlayFabSettings::entityToken.length() > 0) {
            authKey = L"X-EntityToken"; authValue = PlayFabSettings::entityToken;
        } else if (PlayFabSettings::clientSessionTicket.length() > 0) {
            authKey = L"X-Authorization"; authValue = PlayFabSettings::clientSessionTicket;
        }
#if defined(ENABLE_PLAYFABSERVER_API) || defined(ENABLE_PLAYFABADMIN_API)
        else if (PlayFabSettings::developerSecretKey.length() > 0) {
            authKey = L"X-SecretKey"; authValue = PlayFabSettings::developerSecretKey;
        }
#endif

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Authentication/GetEntityToken", authKey, authValue, requestJson, OnGetEntityTokenResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetEntityTokenResponse>(callback)), errorCallback, customData);
    }

    void PlayFabAuthenticationAPI::OnGetEntityTokenResult(CallRequestContainer& request)
    {
        GetEntityTokenResponse outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;
        if (outResult.EntityToken.length() > 0) PlayFabSettings::entityToken = WidenString(outResult.EntityToken);

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<GetEntityTokenResponse> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }
}

#endif
