//--------------------------------------------------------------------------------------
// FacebookAuthHelper.h
//
// Advanced Technology Group (ATG)
// Copyright (C) Microsoft Corporation. All rights reserved.
//--------------------------------------------------------------------------------------
#pragma once

// Set this to your Facebook App ID
// See ReadMe.docx for more information
#pragma message( __FILE__  ": TODO set Facebook App ID" )
#define FB_CLIENT_ID L"<put your Facebook App ID here>"

class FacebookAuthHelper
{
public:
    FacebookAuthHelper();

    struct FacebookAuthResult
    {
        FacebookAuthResult()
            : webAuthStatus(Windows::Xbox::UI::WebAuthenticationStatus::Success)
            , errorDetail(0)
        {}

        Windows::Xbox::UI::WebAuthenticationStatus webAuthStatus;
        std::wstring                               accessToken;
        std::wstring                               errorCode;
        std::wstring                               errorDescription;
        unsigned int                               errorDetail;
    };

    concurrency::task<FacebookAuthResult> Authenticate(Windows::Xbox::System::IUser^ user);

private:
    std::wstring GetUrlParam(const std::wstring &key, Windows::Foundation::Uri^ authResponse) const;
};