#pragma once

#ifdef ENABLE_PLAYFABENTITY_API

#include "playfab/PlayFabBaseModel.h"

namespace PlayFab
{
    namespace ProfilesModels
    {
        // Profiles Enums
        enum EffectType
        {
            EffectTypeAllow,
            EffectTypeDeny
        };

        inline void ToJsonEnum(const EffectType input, web::json::value& output)
        {
            if (input == EffectTypeAllow) output = web::json::value(L"Allow");
            if (input == EffectTypeDeny) output = web::json::value(L"Deny");
        }
        inline void FromJsonEnum(const web::json::value& input, EffectType& output)
        {
            if (!input.is_string()) return;
            const utility::string_t& inputStr = input.as_string();
            if (inputStr == L"Allow") output = EffectTypeAllow;
            if (inputStr == L"Deny") output = EffectTypeDeny;
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

        enum OperationTypes
        {
            OperationTypesCreated,
            OperationTypesUpdated,
            OperationTypesDeleted,
            OperationTypesNone
        };

        inline void ToJsonEnum(const OperationTypes input, web::json::value& output)
        {
            if (input == OperationTypesCreated) output = web::json::value(L"Created");
            if (input == OperationTypesUpdated) output = web::json::value(L"Updated");
            if (input == OperationTypesDeleted) output = web::json::value(L"Deleted");
            if (input == OperationTypesNone) output = web::json::value(L"None");
        }
        inline void FromJsonEnum(const web::json::value& input, OperationTypes& output)
        {
            if (!input.is_string()) return;
            const utility::string_t& inputStr = input.as_string();
            if (inputStr == L"Created") output = OperationTypesCreated;
            if (inputStr == L"Updated") output = OperationTypesUpdated;
            if (inputStr == L"Deleted") output = OperationTypesDeleted;
            if (inputStr == L"None") output = OperationTypesNone;
        }

        // Profiles Classes
        struct EntityDataObject : public PlayFabBaseModel
        {
            web::json::value DataObject;
            std::string EscapedDataObject;
            std::string ObjectName;

            EntityDataObject() :
                PlayFabBaseModel(),
                DataObject(),
                EscapedDataObject(),
                ObjectName()
            {}

            EntityDataObject(const EntityDataObject& src) :
                PlayFabBaseModel(),
                DataObject(src.DataObject),
                EscapedDataObject(src.EscapedDataObject),
                ObjectName(src.ObjectName)
            {}

            ~EntityDataObject() { }

            void FromJson(web::json::value& input) override
            {
                DataObject = input[L"DataObject"];
                FromJsonUtilS(input[L"EscapedDataObject"], EscapedDataObject);
                FromJsonUtilS(input[L"ObjectName"], ObjectName);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                output[L"DataObject"] = DataObject;
                web::json::value each_EscapedDataObject; ToJsonUtilS(EscapedDataObject, each_EscapedDataObject); output[L"EscapedDataObject"] = each_EscapedDataObject;
                web::json::value each_ObjectName; ToJsonUtilS(ObjectName, each_ObjectName); output[L"ObjectName"] = each_ObjectName;
                return output;
            }
        };

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

        struct EntityPermissionStatement : public PlayFabBaseModel
        {
            std::string Action;
            std::string Comment;
            web::json::value Condition;
            EffectType Effect;
            web::json::value Principal;
            std::string Resource;

            EntityPermissionStatement() :
                PlayFabBaseModel(),
                Action(),
                Comment(),
                Condition(),
                Effect(),
                Principal(),
                Resource()
            {}

            EntityPermissionStatement(const EntityPermissionStatement& src) :
                PlayFabBaseModel(),
                Action(src.Action),
                Comment(src.Comment),
                Condition(src.Condition),
                Effect(src.Effect),
                Principal(src.Principal),
                Resource(src.Resource)
            {}

            ~EntityPermissionStatement() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"Action"], Action);
                FromJsonUtilS(input[L"Comment"], Comment);
                Condition = input[L"Condition"];
                FromJsonEnum(input[L"Effect"], Effect);
                Principal = input[L"Principal"];
                FromJsonUtilS(input[L"Resource"], Resource);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Action; ToJsonUtilS(Action, each_Action); output[L"Action"] = each_Action;
                web::json::value each_Comment; ToJsonUtilS(Comment, each_Comment); output[L"Comment"] = each_Comment;
                output[L"Condition"] = Condition;
                web::json::value each_Effect; ToJsonEnum(Effect, each_Effect); output[L"Effect"] = each_Effect;
                output[L"Principal"] = Principal;
                web::json::value each_Resource; ToJsonUtilS(Resource, each_Resource); output[L"Resource"] = each_Resource;
                return output;
            }
        };

        struct EntityProfileFileMetadata : public PlayFabBaseModel
        {
            std::string Checksum;
            std::string FileName;
            time_t LastModified;
            Int32 Size;

            EntityProfileFileMetadata() :
                PlayFabBaseModel(),
                Checksum(),
                FileName(),
                LastModified(),
                Size()
            {}

            EntityProfileFileMetadata(const EntityProfileFileMetadata& src) :
                PlayFabBaseModel(),
                Checksum(src.Checksum),
                FileName(src.FileName),
                LastModified(src.LastModified),
                Size(src.Size)
            {}

            ~EntityProfileFileMetadata() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[L"Checksum"], Checksum);
                FromJsonUtilS(input[L"FileName"], FileName);
                FromJsonUtilT(input[L"LastModified"], LastModified);
                FromJsonUtilP(input[L"Size"], Size);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Checksum; ToJsonUtilS(Checksum, each_Checksum); output[L"Checksum"] = each_Checksum;
                web::json::value each_FileName; ToJsonUtilS(FileName, each_FileName); output[L"FileName"] = each_FileName;
                web::json::value each_LastModified; ToJsonUtilT(LastModified, each_LastModified); output[L"LastModified"] = each_LastModified;
                web::json::value each_Size; ToJsonUtilP(Size, each_Size); output[L"Size"] = each_Size;
                return output;
            }
        };

        struct EntityProfileBody : public PlayFabBaseModel
        {
            Boxed<EntityKey> Entity;
            std::string EntityChain;
            std::map<std::string, EntityProfileFileMetadata> Files;
            std::string Language;
            std::map<std::string, EntityDataObject> Objects;
            std::list<EntityPermissionStatement> Permissions;
            Int32 VersionNumber;

            EntityProfileBody() :
                PlayFabBaseModel(),
                Entity(),
                EntityChain(),
                Files(),
                Language(),
                Objects(),
                Permissions(),
                VersionNumber()
            {}

            EntityProfileBody(const EntityProfileBody& src) :
                PlayFabBaseModel(),
                Entity(src.Entity),
                EntityChain(src.EntityChain),
                Files(src.Files),
                Language(src.Language),
                Objects(src.Objects),
                Permissions(src.Permissions),
                VersionNumber(src.VersionNumber)
            {}

            ~EntityProfileBody() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[L"Entity"], Entity);
                FromJsonUtilS(input[L"EntityChain"], EntityChain);
                FromJsonUtilO(input[L"Files"], Files);
                FromJsonUtilS(input[L"Language"], Language);
                FromJsonUtilO(input[L"Objects"], Objects);
                FromJsonUtilO(input[L"Permissions"], Permissions);
                FromJsonUtilP(input[L"VersionNumber"], VersionNumber);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Entity; ToJsonUtilO(Entity, each_Entity); output[L"Entity"] = each_Entity;
                web::json::value each_EntityChain; ToJsonUtilS(EntityChain, each_EntityChain); output[L"EntityChain"] = each_EntityChain;
                web::json::value each_Files; ToJsonUtilO(Files, each_Files); output[L"Files"] = each_Files;
                web::json::value each_Language; ToJsonUtilS(Language, each_Language); output[L"Language"] = each_Language;
                web::json::value each_Objects; ToJsonUtilO(Objects, each_Objects); output[L"Objects"] = each_Objects;
                web::json::value each_Permissions; ToJsonUtilO(Permissions, each_Permissions); output[L"Permissions"] = each_Permissions;
                web::json::value each_VersionNumber; ToJsonUtilP(VersionNumber, each_VersionNumber); output[L"VersionNumber"] = each_VersionNumber;
                return output;
            }
        };

        struct GetEntityProfileRequest : public PlayFabRequestCommon
        {
            Boxed<bool> DataAsObject;
            EntityKey Entity;

            GetEntityProfileRequest() :
                PlayFabRequestCommon(),
                DataAsObject(),
                Entity()
            {}

            GetEntityProfileRequest(const GetEntityProfileRequest& src) :
                PlayFabRequestCommon(),
                DataAsObject(src.DataAsObject),
                Entity(src.Entity)
            {}

            ~GetEntityProfileRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilP(input[L"DataAsObject"], DataAsObject);
                FromJsonUtilO(input[L"Entity"], Entity);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_DataAsObject; ToJsonUtilP(DataAsObject, each_DataAsObject); output[L"DataAsObject"] = each_DataAsObject;
                web::json::value each_Entity; ToJsonUtilO(Entity, each_Entity); output[L"Entity"] = each_Entity;
                return output;
            }
        };

        struct GetEntityProfileResponse : public PlayFabResultCommon
        {
            Boxed<EntityProfileBody> Profile;

            GetEntityProfileResponse() :
                PlayFabResultCommon(),
                Profile()
            {}

            GetEntityProfileResponse(const GetEntityProfileResponse& src) :
                PlayFabResultCommon(),
                Profile(src.Profile)
            {}

            ~GetEntityProfileResponse() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[L"Profile"], Profile);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Profile; ToJsonUtilO(Profile, each_Profile); output[L"Profile"] = each_Profile;
                return output;
            }
        };

        struct GetEntityProfilesRequest : public PlayFabRequestCommon
        {
            Boxed<bool> DataAsObject;
            std::list<EntityKey> Entities;

            GetEntityProfilesRequest() :
                PlayFabRequestCommon(),
                DataAsObject(),
                Entities()
            {}

            GetEntityProfilesRequest(const GetEntityProfilesRequest& src) :
                PlayFabRequestCommon(),
                DataAsObject(src.DataAsObject),
                Entities(src.Entities)
            {}

            ~GetEntityProfilesRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilP(input[L"DataAsObject"], DataAsObject);
                FromJsonUtilO(input[L"Entities"], Entities);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_DataAsObject; ToJsonUtilP(DataAsObject, each_DataAsObject); output[L"DataAsObject"] = each_DataAsObject;
                web::json::value each_Entities; ToJsonUtilO(Entities, each_Entities); output[L"Entities"] = each_Entities;
                return output;
            }
        };

        struct GetEntityProfilesResponse : public PlayFabResultCommon
        {
            std::list<EntityProfileBody> Profiles;

            GetEntityProfilesResponse() :
                PlayFabResultCommon(),
                Profiles()
            {}

            GetEntityProfilesResponse(const GetEntityProfilesResponse& src) :
                PlayFabResultCommon(),
                Profiles(src.Profiles)
            {}

            ~GetEntityProfilesResponse() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[L"Profiles"], Profiles);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Profiles; ToJsonUtilO(Profiles, each_Profiles); output[L"Profiles"] = each_Profiles;
                return output;
            }
        };

        struct GetGlobalPolicyRequest : public PlayFabRequestCommon
        {

            GetGlobalPolicyRequest() :
                PlayFabRequestCommon()
            {}

            GetGlobalPolicyRequest(const GetGlobalPolicyRequest&) :
                PlayFabRequestCommon()
            {}

            ~GetGlobalPolicyRequest() { }

            void FromJson(web::json::value&) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct GetGlobalPolicyResponse : public PlayFabResultCommon
        {
            std::list<EntityPermissionStatement> Permissions;

            GetGlobalPolicyResponse() :
                PlayFabResultCommon(),
                Permissions()
            {}

            GetGlobalPolicyResponse(const GetGlobalPolicyResponse& src) :
                PlayFabResultCommon(),
                Permissions(src.Permissions)
            {}

            ~GetGlobalPolicyResponse() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[L"Permissions"], Permissions);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Permissions; ToJsonUtilO(Permissions, each_Permissions); output[L"Permissions"] = each_Permissions;
                return output;
            }
        };

        struct SetEntityProfilePolicyRequest : public PlayFabRequestCommon
        {
            EntityKey Entity;
            std::list<EntityPermissionStatement> Statements;

            SetEntityProfilePolicyRequest() :
                PlayFabRequestCommon(),
                Entity(),
                Statements()
            {}

            SetEntityProfilePolicyRequest(const SetEntityProfilePolicyRequest& src) :
                PlayFabRequestCommon(),
                Entity(src.Entity),
                Statements(src.Statements)
            {}

            ~SetEntityProfilePolicyRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[L"Entity"], Entity);
                FromJsonUtilO(input[L"Statements"], Statements);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Entity; ToJsonUtilO(Entity, each_Entity); output[L"Entity"] = each_Entity;
                web::json::value each_Statements; ToJsonUtilO(Statements, each_Statements); output[L"Statements"] = each_Statements;
                return output;
            }
        };

        struct SetEntityProfilePolicyResponse : public PlayFabResultCommon
        {
            std::list<EntityPermissionStatement> Permissions;

            SetEntityProfilePolicyResponse() :
                PlayFabResultCommon(),
                Permissions()
            {}

            SetEntityProfilePolicyResponse(const SetEntityProfilePolicyResponse& src) :
                PlayFabResultCommon(),
                Permissions(src.Permissions)
            {}

            ~SetEntityProfilePolicyResponse() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[L"Permissions"], Permissions);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Permissions; ToJsonUtilO(Permissions, each_Permissions); output[L"Permissions"] = each_Permissions;
                return output;
            }
        };

        struct SetGlobalPolicyRequest : public PlayFabRequestCommon
        {
            std::list<EntityPermissionStatement> Permissions;

            SetGlobalPolicyRequest() :
                PlayFabRequestCommon(),
                Permissions()
            {}

            SetGlobalPolicyRequest(const SetGlobalPolicyRequest& src) :
                PlayFabRequestCommon(),
                Permissions(src.Permissions)
            {}

            ~SetGlobalPolicyRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[L"Permissions"], Permissions);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Permissions; ToJsonUtilO(Permissions, each_Permissions); output[L"Permissions"] = each_Permissions;
                return output;
            }
        };

        struct SetGlobalPolicyResponse : public PlayFabResultCommon
        {

            SetGlobalPolicyResponse() :
                PlayFabResultCommon()
            {}

            SetGlobalPolicyResponse(const SetGlobalPolicyResponse&) :
                PlayFabResultCommon()
            {}

            ~SetGlobalPolicyResponse() { }

            void FromJson(web::json::value&) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct SetProfileLanguageRequest : public PlayFabRequestCommon
        {
            Boxed<EntityKey> Entity;
            Int32 ExpectedVersion;
            std::string Language;

            SetProfileLanguageRequest() :
                PlayFabRequestCommon(),
                Entity(),
                ExpectedVersion(),
                Language()
            {}

            SetProfileLanguageRequest(const SetProfileLanguageRequest& src) :
                PlayFabRequestCommon(),
                Entity(src.Entity),
                ExpectedVersion(src.ExpectedVersion),
                Language(src.Language)
            {}

            ~SetProfileLanguageRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[L"Entity"], Entity);
                FromJsonUtilP(input[L"ExpectedVersion"], ExpectedVersion);
                FromJsonUtilS(input[L"Language"], Language);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Entity; ToJsonUtilO(Entity, each_Entity); output[L"Entity"] = each_Entity;
                web::json::value each_ExpectedVersion; ToJsonUtilP(ExpectedVersion, each_ExpectedVersion); output[L"ExpectedVersion"] = each_ExpectedVersion;
                web::json::value each_Language; ToJsonUtilS(Language, each_Language); output[L"Language"] = each_Language;
                return output;
            }
        };

        struct SetProfileLanguageResponse : public PlayFabResultCommon
        {
            Boxed<OperationTypes> OperationResult;
            Boxed<Int32> VersionNumber;

            SetProfileLanguageResponse() :
                PlayFabResultCommon(),
                OperationResult(),
                VersionNumber()
            {}

            SetProfileLanguageResponse(const SetProfileLanguageResponse& src) :
                PlayFabResultCommon(),
                OperationResult(src.OperationResult),
                VersionNumber(src.VersionNumber)
            {}

            ~SetProfileLanguageResponse() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilE(input[L"OperationResult"], OperationResult);
                FromJsonUtilP(input[L"VersionNumber"], VersionNumber);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_OperationResult; ToJsonUtilE(OperationResult, each_OperationResult); output[L"OperationResult"] = each_OperationResult;
                web::json::value each_VersionNumber; ToJsonUtilP(VersionNumber, each_VersionNumber); output[L"VersionNumber"] = each_VersionNumber;
                return output;
            }
        };

    }
}

#endif
