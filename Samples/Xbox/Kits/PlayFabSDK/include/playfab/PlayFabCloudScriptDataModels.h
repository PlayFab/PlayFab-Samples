#pragma once

#ifdef ENABLE_PLAYFABENTITY_API

#include "playfab/PlayFabBaseModel.h"

namespace PlayFab
{
    namespace CloudScriptModels
    {
        // CloudScript Enums
        enum CloudScriptRevisionOption
        {
            CloudScriptRevisionOptionLive,
            CloudScriptRevisionOptionLatest,
            CloudScriptRevisionOptionSpecific
        };

        inline void ToJsonEnum(const CloudScriptRevisionOption input, web::json::value& output)
        {
            if (input == CloudScriptRevisionOptionLive) output = web::json::value(L"Live");
            if (input == CloudScriptRevisionOptionLatest) output = web::json::value(L"Latest");
            if (input == CloudScriptRevisionOptionSpecific) output = web::json::value(L"Specific");
        }
        inline void FromJsonEnum(const web::json::value& input, CloudScriptRevisionOption& output)
        {
            if (!input.is_string()) return;
            const utility::string_t& inputStr = input.as_string();
            if (inputStr == L"Live") output = CloudScriptRevisionOptionLive;
            if (inputStr == L"Latest") output = CloudScriptRevisionOptionLatest;
            if (inputStr == L"Specific") output = CloudScriptRevisionOptionSpecific;
        }

        enum EntityTypes
        {
            EntityTypestitle,
            EntityTypesmaster_player_account,
            EntityTypestitle_player_account,
            EntityTypescharacter,
            EntityTypesgroup,
            EntityTypesservice
        };

        inline void ToJsonEnum(const EntityTypes input, web::json::value& output)
        {
            if (input == EntityTypestitle) output = web::json::value(L"title");
            if (input == EntityTypesmaster_player_account) output = web::json::value(L"master_player_account");
            if (input == EntityTypestitle_player_account) output = web::json::value(L"title_player_account");
            if (input == EntityTypescharacter) output = web::json::value(L"character");
            if (input == EntityTypesgroup) output = web::json::value(L"group");
            if (input == EntityTypesservice) output = web::json::value(L"service");
        }
        inline void FromJsonEnum(const web::json::value& input, EntityTypes& output)
        {
            if (!input.is_string()) return;
            const utility::string_t& inputStr = input.as_string();
            if (inputStr == L"title") output = EntityTypestitle;
            if (inputStr == L"master_player_account") output = EntityTypesmaster_player_account;
            if (inputStr == L"title_player_account") output = EntityTypestitle_player_account;
            if (inputStr == L"character") output = EntityTypescharacter;
            if (inputStr == L"group") output = EntityTypesgroup;
            if (inputStr == L"service") output = EntityTypesservice;
        }

        // CloudScript Classes
        struct EntityKey : public PlayFabBaseModel
        {
            std::string Id;
            Boxed<EntityTypes> Type;
            std::string TypeString;

            EntityKey() :
                PlayFabBaseModel(),
                Id(),
                Type(),
                TypeString()
            {}

            EntityKey(const EntityKey& src) :
                PlayFabBaseModel(),
                Id(src.Id),
                Type(src.Type),
                TypeString(src.TypeString)
            {}

            ~EntityKey() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"Id"], Id);
                FromJsonUtilE(input[L"Type"], Type);
                FromJsonUtilS(input[L"TypeString"], TypeString);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Id; ToJsonUtilS(Id, each_Id); output[L"Id"] = each_Id;
                web::json::value each_Type; ToJsonUtilE(Type, each_Type); output[L"Type"] = each_Type;
                web::json::value each_TypeString; ToJsonUtilS(TypeString, each_TypeString); output[L"TypeString"] = each_TypeString;
                return output;
            }
        };

        struct ScriptExecutionError : public PlayFabBaseModel
        {
            std::string Error;
            std::string Message;
            std::string StackTrace;

            ScriptExecutionError() :
                PlayFabBaseModel(),
                Error(),
                Message(),
                StackTrace()
            {}

            ScriptExecutionError(const ScriptExecutionError& src) :
                PlayFabBaseModel(),
                Error(src.Error),
                Message(src.Message),
                StackTrace(src.StackTrace)
            {}

            ~ScriptExecutionError() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"Error"], Error);
                FromJsonUtilS(input[L"Message"], Message);
                FromJsonUtilS(input[L"StackTrace"], StackTrace);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Error; ToJsonUtilS(Error, each_Error); output[L"Error"] = each_Error;
                web::json::value each_Message; ToJsonUtilS(Message, each_Message); output[L"Message"] = each_Message;
                web::json::value each_StackTrace; ToJsonUtilS(StackTrace, each_StackTrace); output[L"StackTrace"] = each_StackTrace;
                return output;
            }
        };

        struct LogStatement : public PlayFabBaseModel
        {
            web::json::value Data;
            std::string Level;
            std::string Message;

            LogStatement() :
                PlayFabBaseModel(),
                Data(),
                Level(),
                Message()
            {}

            LogStatement(const LogStatement& src) :
                PlayFabBaseModel(),
                Data(src.Data),
                Level(src.Level),
                Message(src.Message)
            {}

            ~LogStatement() { }

            void FromJson(web::json::value& input) override
            {
                Data = input[L"Data"];
                FromJsonUtilS(input[L"Level"], Level);
                FromJsonUtilS(input[L"Message"], Message);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                output[L"Data"] = Data;
                web::json::value each_Level; ToJsonUtilS(Level, each_Level); output[L"Level"] = each_Level;
                web::json::value each_Message; ToJsonUtilS(Message, each_Message); output[L"Message"] = each_Message;
                return output;
            }
        };

        struct ExecuteCloudScriptResult : public PlayFabResultCommon
        {
            Int32 APIRequestsIssued;
            Boxed<ScriptExecutionError> Error;
            double ExecutionTimeSeconds;
            std::string FunctionName;
            web::json::value FunctionResult;
            Boxed<bool> FunctionResultTooLarge;
            Int32 HttpRequestsIssued;
            std::list<LogStatement> Logs;
            Boxed<bool> LogsTooLarge;
            Uint32 MemoryConsumedBytes;
            double ProcessorTimeSeconds;
            Int32 Revision;

            ExecuteCloudScriptResult() :
                PlayFabResultCommon(),
                APIRequestsIssued(),
                Error(),
                ExecutionTimeSeconds(),
                FunctionName(),
                FunctionResult(),
                FunctionResultTooLarge(),
                HttpRequestsIssued(),
                Logs(),
                LogsTooLarge(),
                MemoryConsumedBytes(),
                ProcessorTimeSeconds(),
                Revision()
            {}

            ExecuteCloudScriptResult(const ExecuteCloudScriptResult& src) :
                PlayFabResultCommon(),
                APIRequestsIssued(src.APIRequestsIssued),
                Error(src.Error),
                ExecutionTimeSeconds(src.ExecutionTimeSeconds),
                FunctionName(src.FunctionName),
                FunctionResult(src.FunctionResult),
                FunctionResultTooLarge(src.FunctionResultTooLarge),
                HttpRequestsIssued(src.HttpRequestsIssued),
                Logs(src.Logs),
                LogsTooLarge(src.LogsTooLarge),
                MemoryConsumedBytes(src.MemoryConsumedBytes),
                ProcessorTimeSeconds(src.ProcessorTimeSeconds),
                Revision(src.Revision)
            {}

            ~ExecuteCloudScriptResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilP(input[L"APIRequestsIssued"], APIRequestsIssued);
                FromJsonUtilO(input[L"Error"], Error);
                FromJsonUtilP(input[L"ExecutionTimeSeconds"], ExecutionTimeSeconds);
                FromJsonUtilS(input[L"FunctionName"], FunctionName);
                FunctionResult = input[L"FunctionResult"];
                FromJsonUtilP(input[L"FunctionResultTooLarge"], FunctionResultTooLarge);
                FromJsonUtilP(input[L"HttpRequestsIssued"], HttpRequestsIssued);
                FromJsonUtilO(input[L"Logs"], Logs);
                FromJsonUtilP(input[L"LogsTooLarge"], LogsTooLarge);
                FromJsonUtilP(input[L"MemoryConsumedBytes"], MemoryConsumedBytes);
                FromJsonUtilP(input[L"ProcessorTimeSeconds"], ProcessorTimeSeconds);
                FromJsonUtilP(input[L"Revision"], Revision);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_APIRequestsIssued; ToJsonUtilP(APIRequestsIssued, each_APIRequestsIssued); output[L"APIRequestsIssued"] = each_APIRequestsIssued;
                web::json::value each_Error; ToJsonUtilO(Error, each_Error); output[L"Error"] = each_Error;
                web::json::value each_ExecutionTimeSeconds; ToJsonUtilP(ExecutionTimeSeconds, each_ExecutionTimeSeconds); output[L"ExecutionTimeSeconds"] = each_ExecutionTimeSeconds;
                web::json::value each_FunctionName; ToJsonUtilS(FunctionName, each_FunctionName); output[L"FunctionName"] = each_FunctionName;
                output[L"FunctionResult"] = FunctionResult;
                web::json::value each_FunctionResultTooLarge; ToJsonUtilP(FunctionResultTooLarge, each_FunctionResultTooLarge); output[L"FunctionResultTooLarge"] = each_FunctionResultTooLarge;
                web::json::value each_HttpRequestsIssued; ToJsonUtilP(HttpRequestsIssued, each_HttpRequestsIssued); output[L"HttpRequestsIssued"] = each_HttpRequestsIssued;
                web::json::value each_Logs; ToJsonUtilO(Logs, each_Logs); output[L"Logs"] = each_Logs;
                web::json::value each_LogsTooLarge; ToJsonUtilP(LogsTooLarge, each_LogsTooLarge); output[L"LogsTooLarge"] = each_LogsTooLarge;
                web::json::value each_MemoryConsumedBytes; ToJsonUtilP(MemoryConsumedBytes, each_MemoryConsumedBytes); output[L"MemoryConsumedBytes"] = each_MemoryConsumedBytes;
                web::json::value each_ProcessorTimeSeconds; ToJsonUtilP(ProcessorTimeSeconds, each_ProcessorTimeSeconds); output[L"ProcessorTimeSeconds"] = each_ProcessorTimeSeconds;
                web::json::value each_Revision; ToJsonUtilP(Revision, each_Revision); output[L"Revision"] = each_Revision;
                return output;
            }
        };

        struct ExecuteEntityCloudScriptRequest : public PlayFabRequestCommon
        {
            Boxed<EntityKey> Entity;
            std::string FunctionName;
            web::json::value FunctionParameter;
            Boxed<bool> GeneratePlayStreamEvent;
            Boxed<CloudScriptRevisionOption> RevisionSelection;
            Boxed<Int32> SpecificRevision;

            ExecuteEntityCloudScriptRequest() :
                PlayFabRequestCommon(),
                Entity(),
                FunctionName(),
                FunctionParameter(),
                GeneratePlayStreamEvent(),
                RevisionSelection(),
                SpecificRevision()
            {}

            ExecuteEntityCloudScriptRequest(const ExecuteEntityCloudScriptRequest& src) :
                PlayFabRequestCommon(),
                Entity(src.Entity),
                FunctionName(src.FunctionName),
                FunctionParameter(src.FunctionParameter),
                GeneratePlayStreamEvent(src.GeneratePlayStreamEvent),
                RevisionSelection(src.RevisionSelection),
                SpecificRevision(src.SpecificRevision)
            {}

            ~ExecuteEntityCloudScriptRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[L"Entity"], Entity);
                FromJsonUtilS(input[L"FunctionName"], FunctionName);
                FunctionParameter = input[L"FunctionParameter"];
                FromJsonUtilP(input[L"GeneratePlayStreamEvent"], GeneratePlayStreamEvent);
                FromJsonUtilE(input[L"RevisionSelection"], RevisionSelection);
                FromJsonUtilP(input[L"SpecificRevision"], SpecificRevision);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Entity; ToJsonUtilO(Entity, each_Entity); output[L"Entity"] = each_Entity;
                web::json::value each_FunctionName; ToJsonUtilS(FunctionName, each_FunctionName); output[L"FunctionName"] = each_FunctionName;
                output[L"FunctionParameter"] = FunctionParameter;
                web::json::value each_GeneratePlayStreamEvent; ToJsonUtilP(GeneratePlayStreamEvent, each_GeneratePlayStreamEvent); output[L"GeneratePlayStreamEvent"] = each_GeneratePlayStreamEvent;
                web::json::value each_RevisionSelection; ToJsonUtilE(RevisionSelection, each_RevisionSelection); output[L"RevisionSelection"] = each_RevisionSelection;
                web::json::value each_SpecificRevision; ToJsonUtilP(SpecificRevision, each_SpecificRevision); output[L"SpecificRevision"] = each_SpecificRevision;
                return output;
            }
        };

    }
}

#endif
