#pragma once

#ifndef DISABLE_PLAYFABENTITY_API

#include <playfab/PlayFabBaseModel.h>

// Intellisense-only includes
#ifndef _WIN32
#include <jsoncpp/json/value.h>
#endif
#ifdef _WIN32
#include <json/value.h>
#endif

namespace PlayFab
{
    namespace LocalizationModels
    {
        // Localization Enums
        // Localization Classes
        struct GetLanguageListRequest : public PlayFabRequestCommon
        {

            GetLanguageListRequest() :
                PlayFabRequestCommon()
            {}

            GetLanguageListRequest(const GetLanguageListRequest&) :
                PlayFabRequestCommon()
            {}

            ~GetLanguageListRequest() = default;

            void FromJson(Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                return output;
            }
        };

        struct GetLanguageListResponse : public PlayFabResultCommon
        {
            std::list<std::string> LanguageList;

            GetLanguageListResponse() :
                PlayFabResultCommon(),
                LanguageList()
            {}

            GetLanguageListResponse(const GetLanguageListResponse& src) :
                PlayFabResultCommon(),
                LanguageList(src.LanguageList)
            {}

            ~GetLanguageListResponse() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["LanguageList"], LanguageList);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_LanguageList; ToJsonUtilS(LanguageList, each_LanguageList); output["LanguageList"] = each_LanguageList;
                return output;
            }
        };

    }
}

#endif
