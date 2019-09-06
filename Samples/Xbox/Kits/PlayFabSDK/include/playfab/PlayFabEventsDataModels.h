#pragma once

#ifdef ENABLE_PLAYFABENTITY_API

#include "playfab/PlayFabBaseModel.h"

namespace PlayFab
{
    namespace EventsModels
    {
        // Events Enums
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

        // Events Classes
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

        struct EventContents : public PlayFabBaseModel
        {
            EntityKey Entity;
            std::string EventNamespace;
            std::string Name;
            std::string OriginalId;
            Boxed<time_t> OriginalTimestamp;
            web::json::value Payload;
            std::string PayloadJSON;

            EventContents() :
                PlayFabBaseModel(),
                Entity(),
                EventNamespace(),
                Name(),
                OriginalId(),
                OriginalTimestamp(),
                Payload(),
                PayloadJSON()
            {}

            EventContents(const EventContents& src) :
                PlayFabBaseModel(),
                Entity(src.Entity),
                EventNamespace(src.EventNamespace),
                Name(src.Name),
                OriginalId(src.OriginalId),
                OriginalTimestamp(src.OriginalTimestamp),
                Payload(src.Payload),
                PayloadJSON(src.PayloadJSON)
            {}

            ~EventContents() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[L"Entity"], Entity);
                FromJsonUtilS(input[L"EventNamespace"], EventNamespace);
                FromJsonUtilS(input[L"Name"], Name);
                FromJsonUtilS(input[L"OriginalId"], OriginalId);
                FromJsonUtilT(input[L"OriginalTimestamp"], OriginalTimestamp);
                Payload = input[L"Payload"];
                FromJsonUtilS(input[L"PayloadJSON"], PayloadJSON);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Entity; ToJsonUtilO(Entity, each_Entity); output[L"Entity"] = each_Entity;
                web::json::value each_EventNamespace; ToJsonUtilS(EventNamespace, each_EventNamespace); output[L"EventNamespace"] = each_EventNamespace;
                web::json::value each_Name; ToJsonUtilS(Name, each_Name); output[L"Name"] = each_Name;
                web::json::value each_OriginalId; ToJsonUtilS(OriginalId, each_OriginalId); output[L"OriginalId"] = each_OriginalId;
                web::json::value each_OriginalTimestamp; ToJsonUtilT(OriginalTimestamp, each_OriginalTimestamp); output[L"OriginalTimestamp"] = each_OriginalTimestamp;
                output[L"Payload"] = Payload;
                web::json::value each_PayloadJSON; ToJsonUtilS(PayloadJSON, each_PayloadJSON); output[L"PayloadJSON"] = each_PayloadJSON;
                return output;
            }
        };

        struct WriteEventsRequest : public PlayFabRequestCommon
        {
            std::list<EventContents> Events;

            WriteEventsRequest() :
                PlayFabRequestCommon(),
                Events()
            {}

            WriteEventsRequest(const WriteEventsRequest& src) :
                PlayFabRequestCommon(),
                Events(src.Events)
            {}

            ~WriteEventsRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[L"Events"], Events);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Events; ToJsonUtilO(Events, each_Events); output[L"Events"] = each_Events;
                return output;
            }
        };

        struct WriteEventsResponse : public PlayFabResultCommon
        {
            std::list<std::string> AssignedEventIds;

            WriteEventsResponse() :
                PlayFabResultCommon(),
                AssignedEventIds()
            {}

            WriteEventsResponse(const WriteEventsResponse& src) :
                PlayFabResultCommon(),
                AssignedEventIds(src.AssignedEventIds)
            {}

            ~WriteEventsResponse() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"AssignedEventIds"], AssignedEventIds);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_AssignedEventIds; ToJsonUtilS(AssignedEventIds, each_AssignedEventIds); output[L"AssignedEventIds"] = each_AssignedEventIds;
                return output;
            }
        };

    }
}

#endif
