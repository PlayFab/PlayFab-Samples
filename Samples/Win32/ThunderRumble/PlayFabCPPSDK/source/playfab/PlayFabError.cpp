#include <stdafx.h>

#include <playfab/PlayFabError.h>

namespace PlayFab
{
    void PlayFabError::FromJson(Json::Value& input)
    {
        const Json::Value HttpCode_member = input["code"];
        if (HttpCode_member != Json::Value::null) HttpCode = HttpCode_member.asInt();
        const Json::Value ErrorCode_member = input["errorCode"];
        if (ErrorCode_member != Json::Value::null) ErrorCode = PlayFabErrorCode(ErrorCode_member.asInt());
        const Json::Value HttpStatus_member = input["status"];
        if (HttpStatus_member != Json::Value::null) HttpStatus = HttpStatus_member.asString();
        const Json::Value ErrorName_member = input["error"];
        if (ErrorName_member != Json::Value::null) ErrorName = ErrorName_member.asString();
        const Json::Value ErrorMessage_member = input["errorMessage"];
        if (ErrorMessage_member != Json::Value::null) ErrorMessage = ErrorMessage_member.asString();
        ErrorDetails = input["errorDetails"];
        Data = input["data"];
    }

    Json::Value PlayFabError::ToJson() const
    {
        // This is not expected to be used, but implemented for completeness
        Json::Value output;
        output["code"] = Json::Value(HttpCode);
        output["errorCode"] = Json::Value(ErrorCode);
        output["status"] = Json::Value(HttpStatus);
        output["error"] = Json::Value(ErrorName);
        output["errorMessage"] = Json::Value(ErrorMessage);
        output["errorDetails"] = ErrorDetails;
        output["data"] = Data;
        return output;
    }

    std::string PlayFabError::GenerateErrorReport() const
    {
        std::string output;
        output.reserve(1024);
        output += ErrorMessage;
        if (ErrorDetails != Json::Value::null && ErrorDetails.isObject())
        {
            for (auto detailIter = ErrorDetails.begin(); detailIter != ErrorDetails.end(); ++detailIter)
            {
                if (!detailIter->isArray()) continue;

                output += "\n";
                output += detailIter.key().asString();
                output += ": ";
                int valueIndex = 0;
                for (auto valueIter = detailIter->begin(); valueIter != detailIter->end(); ++valueIter)
                {
                    if (!valueIter->isString()) continue;
                    if (valueIndex != 0) output += ", ";
                    output += valueIter->asString();
                    valueIndex++;
                }
            }
        }
        return output;
    }
}
