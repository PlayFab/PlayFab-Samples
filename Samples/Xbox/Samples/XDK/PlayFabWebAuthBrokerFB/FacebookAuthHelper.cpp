//--------------------------------------------------------------------------------------
// FacebookAuthHelper.cpp
//
// Advanced Technology Group (ATG)
// Copyright (C) Microsoft Corporation. All rights reserved.
//--------------------------------------------------------------------------------------

#include "pch.h"
#include "FacebookAuthHelper.h"

namespace
{
    const wchar_t *c_completedReturnUri = L"https://www.facebook.com/connect/login_success.html";
} // ANONYMOUS namespace

FacebookAuthHelper::FacebookAuthHelper()
{
}

concurrency::task<FacebookAuthHelper::FacebookAuthResult> FacebookAuthHelper::Authenticate(Windows::Xbox::System::IUser ^user)
{
    assert(user != nullptr);
    

    // Construct the Facebook OAUTH request per docs:
    // https://developers.facebook.com/docs/facebook-login/manually-build-a-login-flow

    std::wstring uri(L"https://www.facebook.com/dialog/oauth?client_id=");

    uri += FB_CLIENT_ID;
    uri += L"&display=popup&redirect_uri=";
    uri += Windows::Foundation::Uri::EscapeComponent(ref new Platform::String(c_completedReturnUri))->Data();
    uri += L"&response_type=token&scope=publish_actions&sdk=xboxone";


    concurrency::task_completion_event<FacebookAuthHelper::FacebookAuthResult> tce;

    concurrency::create_task(
        Windows::Xbox::UI::SystemUI::AuthenticateAsync(
            user,
            Windows::Xbox::UI::WebAuthenticationOptions::None,
            ref new Windows::Foundation::Uri(ref new Platform::String(uri.c_str())),
            ref new Windows::Foundation::Uri(ref new Platform::String(c_completedReturnUri))
        )
    ).then([this, tce](concurrency::task<Windows::Xbox::UI::WebAuthenticationResult^> t)
    {
        try
        {
            auto result = t.get();

            FacebookAuthResult authResult;

            // Fill in the webAuthStatus
            authResult.webAuthStatus = result->ResponseStatus;

            std::wstring response = result->ResponseData->Data();
            if (!response.empty())
            {

                // Facebook returns a URI-like value in the auth response
                // but in order for the Uri parser to see the query params
                // a character substitution is needed
                Windows::Foundation::Uri^ responseUri;
                {
                    responseUri = ref new Windows::Foundation::Uri(
                        ref new Platform::String(
                        (response.replace(response.find(L"#"), 1, L"?")).c_str())
                    );
                }

                // Fill in the accessToken
                authResult.accessToken = GetUrlParam(L"access_token", responseUri);

                // Fill in the error code
                authResult.errorCode = GetUrlParam(L"error_code", responseUri);

                // Fill in the error description
                authResult.errorDescription = GetUrlParam(L"error_description", responseUri);
            }

            // Fill in the errorDetail
            authResult.errorDetail = result->ResponseErrorDetail;

            tce.set(authResult);
        }
        catch (Platform::Exception^ Ex)
        {
            FacebookAuthResult authResult;
            authResult.errorCode = L"Exception";
            authResult.errorDescription = Ex->Message->Data();
            authResult.errorDetail= Ex->HResult;
            tce.set(authResult);
        }
    });

    return create_task(tce);
}

std::wstring FacebookAuthHelper::GetUrlParam(const std::wstring & key, Windows::Foundation::Uri ^authResponse) const
{
    if (authResponse != nullptr)
    {
        auto itr = authResponse->QueryParsed->First();
        while (itr->HasCurrent)
        {
            auto cur = itr->Current;
            auto name(cur->Name);
            if (name->Equals(ref new Platform::String(key.c_str())))
            {
                return cur->Value->Data();
            }

            itr->MoveNext();
        }
    }

    return std::wstring();
}
