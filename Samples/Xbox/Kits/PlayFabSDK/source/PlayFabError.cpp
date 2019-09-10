#include "PlayFab/PlayFabError.h"

namespace PlayFab
{
    void PlayFabError::FromJson(web::json::value& input)
    {
        const web::json::value HttpCode_member = input[L"code"];
        if (!HttpCode_member.is_null()) HttpCode = HttpCode_member.as_integer();
        const web::json::value ErrorCode_member = input[L"errorCode"];
        if (!ErrorCode_member.is_null()) ErrorCode = PlayFabErrorCode(ErrorCode_member.as_integer());
        const web::json::value HttpStatus_member = input[L"status"];
        if (!HttpStatus_member.is_null()) HttpStatus = ShortenString(HttpStatus_member.as_string());
        const web::json::value ErrorName_member = input[L"error"];
        if (!ErrorName_member.is_null()) ErrorName = ShortenString(ErrorName_member.as_string());
        const web::json::value ErrorMessage_member = input[L"errorMessage"];
        if (!ErrorMessage_member.is_null()) ErrorMessage = ShortenString(ErrorMessage_member.as_string());
        ErrorDetails = input[L"errorDetails"];
        Data = input[L"data"];
    }

    web::json::value PlayFabError::ToJson() const
    {
        // This is not expected to be used, but implemented for completeness
        web::json::value output;
        output[L"code"] = web::json::value(HttpCode);
        output[L"errorCode"] = web::json::value(ErrorCode);
        output[L"status"] = web::json::value(WidenString(HttpStatus));
        output[L"error"] = web::json::value(WidenString(ErrorName));
        output[L"errorMessage"] = web::json::value(WidenString(ErrorMessage));
        output[L"errorDetails"] = ErrorDetails;
        output[L"data"] = Data;
        return output;
    }

    std::string PlayFabError::GenerateErrorReport() const
    {
        std::string output;
        output.resize(output.size() + 1024);
        output += ErrorMessage;
        if (!ErrorDetails.is_null() && ErrorDetails.is_object())
        {
            auto eachDetailPair = ErrorDetails.as_object();
            for (auto detailIter = eachDetailPair.cbegin(); detailIter != eachDetailPair.cend(); ++detailIter)
            {
                if (!detailIter->second.is_array()) continue;

                output += "\n";
                output += ShortenString(detailIter->first);
                output += ": ";
                auto eachValueArray = detailIter->second.as_array();
                int valueIndex = 0;
                for (auto valueIter = eachValueArray.cbegin(); valueIter != eachValueArray.cend(); ++valueIter)
                {
                    if (!valueIter->is_string()) continue;
                    if (valueIndex != 0) output += ", ";
                    output += ShortenString(valueIter->as_string());
                    valueIndex++;
                }
            }
        }
        return output;
    }
}
