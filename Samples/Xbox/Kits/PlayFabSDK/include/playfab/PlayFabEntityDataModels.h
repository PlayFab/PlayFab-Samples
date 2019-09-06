#pragma once

#ifndef DISABLE_PLAYFABCLIENT_API

#include "playfab/PlayFabBaseModel.h"

namespace PlayFab
{
    namespace EntityModels
    {
        // Entity Enums
        enum EffectType
        {
            EffectTypeAllow,
            EffectTypeDeny
        };

        inline void ToJsonEnum(const EffectType input, web::json::value& output)
        {
            if (input == EffectTypeAllow) output = web::json::value(U("Allow"));
            if (input == EffectTypeDeny) output = web::json::value(U("Deny"));
        }
        inline void FromJsonEnum(const web::json::value& input, EffectType& output)
        {
            if (!input.is_string()) return;
            const utility::string_t& inputStr = input.as_string();
            if (inputStr == U("Allow")) output = EffectTypeAllow;
            if (inputStr == U("Deny")) output = EffectTypeDeny;
        }

        enum EntityTypes
        {
            EntityTypestitle,
            EntityTypesmaster_player_account,
            EntityTypestitle_player_account,
            EntityTypescharacter,
            EntityTypesgroup
        };

        inline void ToJsonEnum(const EntityTypes input, web::json::value& output)
        {
            if (input == EntityTypestitle) output = web::json::value(U("title"));
            if (input == EntityTypesmaster_player_account) output = web::json::value(U("master_player_account"));
            if (input == EntityTypestitle_player_account) output = web::json::value(U("title_player_account"));
            if (input == EntityTypescharacter) output = web::json::value(U("character"));
            if (input == EntityTypesgroup) output = web::json::value(U("group"));
        }
        inline void FromJsonEnum(const web::json::value& input, EntityTypes& output)
        {
            if (!input.is_string()) return;
            const utility::string_t& inputStr = input.as_string();
            if (inputStr == U("title")) output = EntityTypestitle;
            if (inputStr == U("master_player_account")) output = EntityTypesmaster_player_account;
            if (inputStr == U("title_player_account")) output = EntityTypestitle_player_account;
            if (inputStr == U("character")) output = EntityTypescharacter;
            if (inputStr == U("group")) output = EntityTypesgroup;
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
            if (input == OperationTypesCreated) output = web::json::value(U("Created"));
            if (input == OperationTypesUpdated) output = web::json::value(U("Updated"));
            if (input == OperationTypesDeleted) output = web::json::value(U("Deleted"));
            if (input == OperationTypesNone) output = web::json::value(U("None"));
        }
        inline void FromJsonEnum(const web::json::value& input, OperationTypes& output)
        {
            if (!input.is_string()) return;
            const utility::string_t& inputStr = input.as_string();
            if (inputStr == U("Created")) output = OperationTypesCreated;
            if (inputStr == U("Updated")) output = OperationTypesUpdated;
            if (inputStr == U("Deleted")) output = OperationTypesDeleted;
            if (inputStr == U("None")) output = OperationTypesNone;
        }

        // Entity Classes
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
                FromJsonUtilS(input[U("Id")], Id);
                FromJsonUtilE(input[U("Type")], Type);
                FromJsonUtilS(input[U("TypeString")], TypeString);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Id; ToJsonUtilS(Id, each_Id); output[U("Id")] = each_Id;
                web::json::value each_Type; ToJsonUtilE(Type, each_Type); output[U("Type")] = each_Type;
                web::json::value each_TypeString; ToJsonUtilS(TypeString, each_TypeString); output[U("TypeString")] = each_TypeString;
                return output;
            }
        };

        struct AbortFileUploadsRequest : public PlayFabRequestCommon
        {
            EntityKey Entity;
            std::list<std::string> FileNames;
            Boxed<Int32> ProfileVersion;

            AbortFileUploadsRequest() :
                PlayFabRequestCommon(),
                Entity(),
                FileNames(),
                ProfileVersion()
            {}

            AbortFileUploadsRequest(const AbortFileUploadsRequest& src) :
                PlayFabRequestCommon(),
                Entity(src.Entity),
                FileNames(src.FileNames),
                ProfileVersion(src.ProfileVersion)
            {}

            ~AbortFileUploadsRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[U("Entity")], Entity);
                FromJsonUtilS(input[U("FileNames")], FileNames);
                FromJsonUtilP(input[U("ProfileVersion")], ProfileVersion);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Entity; ToJsonUtilO(Entity, each_Entity); output[U("Entity")] = each_Entity;
                web::json::value each_FileNames; ToJsonUtilS(FileNames, each_FileNames); output[U("FileNames")] = each_FileNames;
                web::json::value each_ProfileVersion; ToJsonUtilP(ProfileVersion, each_ProfileVersion); output[U("ProfileVersion")] = each_ProfileVersion;
                return output;
            }
        };

        struct AbortFileUploadsResponse : public PlayFabResultCommon
        {
            Boxed<EntityKey> Entity;
            Int32 ProfileVersion;

            AbortFileUploadsResponse() :
                PlayFabResultCommon(),
                Entity(),
                ProfileVersion()
            {}

            AbortFileUploadsResponse(const AbortFileUploadsResponse& src) :
                PlayFabResultCommon(),
                Entity(src.Entity),
                ProfileVersion(src.ProfileVersion)
            {}

            ~AbortFileUploadsResponse() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[U("Entity")], Entity);
                FromJsonUtilP(input[U("ProfileVersion")], ProfileVersion);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Entity; ToJsonUtilO(Entity, each_Entity); output[U("Entity")] = each_Entity;
                web::json::value each_ProfileVersion; ToJsonUtilP(ProfileVersion, each_ProfileVersion); output[U("ProfileVersion")] = each_ProfileVersion;
                return output;
            }
        };

        struct AcceptGroupApplicationRequest : public PlayFabRequestCommon
        {
            EntityKey Entity;
            EntityKey Group;

            AcceptGroupApplicationRequest() :
                PlayFabRequestCommon(),
                Entity(),
                Group()
            {}

            AcceptGroupApplicationRequest(const AcceptGroupApplicationRequest& src) :
                PlayFabRequestCommon(),
                Entity(src.Entity),
                Group(src.Group)
            {}

            ~AcceptGroupApplicationRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[U("Entity")], Entity);
                FromJsonUtilO(input[U("Group")], Group);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Entity; ToJsonUtilO(Entity, each_Entity); output[U("Entity")] = each_Entity;
                web::json::value each_Group; ToJsonUtilO(Group, each_Group); output[U("Group")] = each_Group;
                return output;
            }
        };

        struct AcceptGroupInvitationRequest : public PlayFabRequestCommon
        {
            Boxed<EntityKey> Entity;
            EntityKey Group;

            AcceptGroupInvitationRequest() :
                PlayFabRequestCommon(),
                Entity(),
                Group()
            {}

            AcceptGroupInvitationRequest(const AcceptGroupInvitationRequest& src) :
                PlayFabRequestCommon(),
                Entity(src.Entity),
                Group(src.Group)
            {}

            ~AcceptGroupInvitationRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[U("Entity")], Entity);
                FromJsonUtilO(input[U("Group")], Group);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Entity; ToJsonUtilO(Entity, each_Entity); output[U("Entity")] = each_Entity;
                web::json::value each_Group; ToJsonUtilO(Group, each_Group); output[U("Group")] = each_Group;
                return output;
            }
        };

        struct AddMembersRequest : public PlayFabRequestCommon
        {
            EntityKey Group;
            std::list<EntityKey> Members;
            std::string RoleId;

            AddMembersRequest() :
                PlayFabRequestCommon(),
                Group(),
                Members(),
                RoleId()
            {}

            AddMembersRequest(const AddMembersRequest& src) :
                PlayFabRequestCommon(),
                Group(src.Group),
                Members(src.Members),
                RoleId(src.RoleId)
            {}

            ~AddMembersRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[U("Group")], Group);
                FromJsonUtilO(input[U("Members")], Members);
                FromJsonUtilS(input[U("RoleId")], RoleId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Group; ToJsonUtilO(Group, each_Group); output[U("Group")] = each_Group;
                web::json::value each_Members; ToJsonUtilO(Members, each_Members); output[U("Members")] = each_Members;
                web::json::value each_RoleId; ToJsonUtilS(RoleId, each_RoleId); output[U("RoleId")] = each_RoleId;
                return output;
            }
        };

        struct ApplyToGroupRequest : public PlayFabRequestCommon
        {
            Boxed<bool> AutoAcceptOutstandingInvite;
            Boxed<EntityKey> Entity;
            EntityKey Group;

            ApplyToGroupRequest() :
                PlayFabRequestCommon(),
                AutoAcceptOutstandingInvite(),
                Entity(),
                Group()
            {}

            ApplyToGroupRequest(const ApplyToGroupRequest& src) :
                PlayFabRequestCommon(),
                AutoAcceptOutstandingInvite(src.AutoAcceptOutstandingInvite),
                Entity(src.Entity),
                Group(src.Group)
            {}

            ~ApplyToGroupRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilP(input[U("AutoAcceptOutstandingInvite")], AutoAcceptOutstandingInvite);
                FromJsonUtilO(input[U("Entity")], Entity);
                FromJsonUtilO(input[U("Group")], Group);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_AutoAcceptOutstandingInvite; ToJsonUtilP(AutoAcceptOutstandingInvite, each_AutoAcceptOutstandingInvite); output[U("AutoAcceptOutstandingInvite")] = each_AutoAcceptOutstandingInvite;
                web::json::value each_Entity; ToJsonUtilO(Entity, each_Entity); output[U("Entity")] = each_Entity;
                web::json::value each_Group; ToJsonUtilO(Group, each_Group); output[U("Group")] = each_Group;
                return output;
            }
        };

        struct EntityWithLineage : public PlayFabBaseModel
        {
            Boxed<EntityKey> Key;
            std::map<std::string, EntityKey> Lineage;

            EntityWithLineage() :
                PlayFabBaseModel(),
                Key(),
                Lineage()
            {}

            EntityWithLineage(const EntityWithLineage& src) :
                PlayFabBaseModel(),
                Key(src.Key),
                Lineage(src.Lineage)
            {}

            ~EntityWithLineage() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[U("Key")], Key);
                FromJsonUtilO(input[U("Lineage")], Lineage);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Key; ToJsonUtilO(Key, each_Key); output[U("Key")] = each_Key;
                web::json::value each_Lineage; ToJsonUtilO(Lineage, each_Lineage); output[U("Lineage")] = each_Lineage;
                return output;
            }
        };

        struct ApplyToGroupResponse : public PlayFabResultCommon
        {
            Boxed<EntityWithLineage> Entity;
            time_t Expires;
            Boxed<EntityKey> Group;

            ApplyToGroupResponse() :
                PlayFabResultCommon(),
                Entity(),
                Expires(),
                Group()
            {}

            ApplyToGroupResponse(const ApplyToGroupResponse& src) :
                PlayFabResultCommon(),
                Entity(src.Entity),
                Expires(src.Expires),
                Group(src.Group)
            {}

            ~ApplyToGroupResponse() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[U("Entity")], Entity);
                FromJsonUtilT(input[U("Expires")], Expires);
                FromJsonUtilO(input[U("Group")], Group);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Entity; ToJsonUtilO(Entity, each_Entity); output[U("Entity")] = each_Entity;
                web::json::value each_Expires; ToJsonUtilT(Expires, each_Expires); output[U("Expires")] = each_Expires;
                web::json::value each_Group; ToJsonUtilO(Group, each_Group); output[U("Group")] = each_Group;
                return output;
            }
        };

        struct BlockEntityRequest : public PlayFabRequestCommon
        {
            EntityKey Entity;
            EntityKey Group;

            BlockEntityRequest() :
                PlayFabRequestCommon(),
                Entity(),
                Group()
            {}

            BlockEntityRequest(const BlockEntityRequest& src) :
                PlayFabRequestCommon(),
                Entity(src.Entity),
                Group(src.Group)
            {}

            ~BlockEntityRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[U("Entity")], Entity);
                FromJsonUtilO(input[U("Group")], Group);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Entity; ToJsonUtilO(Entity, each_Entity); output[U("Entity")] = each_Entity;
                web::json::value each_Group; ToJsonUtilO(Group, each_Group); output[U("Group")] = each_Group;
                return output;
            }
        };

        struct ChangeMemberRoleRequest : public PlayFabRequestCommon
        {
            std::string DestinationRoleId;
            EntityKey Group;
            std::list<EntityKey> Members;
            std::string OriginRoleId;

            ChangeMemberRoleRequest() :
                PlayFabRequestCommon(),
                DestinationRoleId(),
                Group(),
                Members(),
                OriginRoleId()
            {}

            ChangeMemberRoleRequest(const ChangeMemberRoleRequest& src) :
                PlayFabRequestCommon(),
                DestinationRoleId(src.DestinationRoleId),
                Group(src.Group),
                Members(src.Members),
                OriginRoleId(src.OriginRoleId)
            {}

            ~ChangeMemberRoleRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("DestinationRoleId")], DestinationRoleId);
                FromJsonUtilO(input[U("Group")], Group);
                FromJsonUtilO(input[U("Members")], Members);
                FromJsonUtilS(input[U("OriginRoleId")], OriginRoleId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_DestinationRoleId; ToJsonUtilS(DestinationRoleId, each_DestinationRoleId); output[U("DestinationRoleId")] = each_DestinationRoleId;
                web::json::value each_Group; ToJsonUtilO(Group, each_Group); output[U("Group")] = each_Group;
                web::json::value each_Members; ToJsonUtilO(Members, each_Members); output[U("Members")] = each_Members;
                web::json::value each_OriginRoleId; ToJsonUtilS(OriginRoleId, each_OriginRoleId); output[U("OriginRoleId")] = each_OriginRoleId;
                return output;
            }
        };

        struct CreateGroupRequest : public PlayFabRequestCommon
        {
            Boxed<EntityKey> Entity;
            std::string GroupName;

            CreateGroupRequest() :
                PlayFabRequestCommon(),
                Entity(),
                GroupName()
            {}

            CreateGroupRequest(const CreateGroupRequest& src) :
                PlayFabRequestCommon(),
                Entity(src.Entity),
                GroupName(src.GroupName)
            {}

            ~CreateGroupRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[U("Entity")], Entity);
                FromJsonUtilS(input[U("GroupName")], GroupName);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Entity; ToJsonUtilO(Entity, each_Entity); output[U("Entity")] = each_Entity;
                web::json::value each_GroupName; ToJsonUtilS(GroupName, each_GroupName); output[U("GroupName")] = each_GroupName;
                return output;
            }
        };

        struct CreateGroupResponse : public PlayFabResultCommon
        {
            std::string AdminRoleId;
            time_t Created;
            EntityKey Group;
            std::string GroupName;
            std::string MemberRoleId;
            Int32 ProfileVersion;
            std::map<std::string, std::string> Roles;

            CreateGroupResponse() :
                PlayFabResultCommon(),
                AdminRoleId(),
                Created(),
                Group(),
                GroupName(),
                MemberRoleId(),
                ProfileVersion(),
                Roles()
            {}

            CreateGroupResponse(const CreateGroupResponse& src) :
                PlayFabResultCommon(),
                AdminRoleId(src.AdminRoleId),
                Created(src.Created),
                Group(src.Group),
                GroupName(src.GroupName),
                MemberRoleId(src.MemberRoleId),
                ProfileVersion(src.ProfileVersion),
                Roles(src.Roles)
            {}

            ~CreateGroupResponse() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("AdminRoleId")], AdminRoleId);
                FromJsonUtilT(input[U("Created")], Created);
                FromJsonUtilO(input[U("Group")], Group);
                FromJsonUtilS(input[U("GroupName")], GroupName);
                FromJsonUtilS(input[U("MemberRoleId")], MemberRoleId);
                FromJsonUtilP(input[U("ProfileVersion")], ProfileVersion);
                FromJsonUtilS(input[U("Roles")], Roles);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_AdminRoleId; ToJsonUtilS(AdminRoleId, each_AdminRoleId); output[U("AdminRoleId")] = each_AdminRoleId;
                web::json::value each_Created; ToJsonUtilT(Created, each_Created); output[U("Created")] = each_Created;
                web::json::value each_Group; ToJsonUtilO(Group, each_Group); output[U("Group")] = each_Group;
                web::json::value each_GroupName; ToJsonUtilS(GroupName, each_GroupName); output[U("GroupName")] = each_GroupName;
                web::json::value each_MemberRoleId; ToJsonUtilS(MemberRoleId, each_MemberRoleId); output[U("MemberRoleId")] = each_MemberRoleId;
                web::json::value each_ProfileVersion; ToJsonUtilP(ProfileVersion, each_ProfileVersion); output[U("ProfileVersion")] = each_ProfileVersion;
                web::json::value each_Roles; ToJsonUtilS(Roles, each_Roles); output[U("Roles")] = each_Roles;
                return output;
            }
        };

        struct CreateGroupRoleRequest : public PlayFabRequestCommon
        {
            EntityKey Group;
            std::string RoleId;
            std::string RoleName;

            CreateGroupRoleRequest() :
                PlayFabRequestCommon(),
                Group(),
                RoleId(),
                RoleName()
            {}

            CreateGroupRoleRequest(const CreateGroupRoleRequest& src) :
                PlayFabRequestCommon(),
                Group(src.Group),
                RoleId(src.RoleId),
                RoleName(src.RoleName)
            {}

            ~CreateGroupRoleRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[U("Group")], Group);
                FromJsonUtilS(input[U("RoleId")], RoleId);
                FromJsonUtilS(input[U("RoleName")], RoleName);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Group; ToJsonUtilO(Group, each_Group); output[U("Group")] = each_Group;
                web::json::value each_RoleId; ToJsonUtilS(RoleId, each_RoleId); output[U("RoleId")] = each_RoleId;
                web::json::value each_RoleName; ToJsonUtilS(RoleName, each_RoleName); output[U("RoleName")] = each_RoleName;
                return output;
            }
        };

        struct CreateGroupRoleResponse : public PlayFabResultCommon
        {
            Int32 ProfileVersion;
            std::string RoleId;
            std::string RoleName;

            CreateGroupRoleResponse() :
                PlayFabResultCommon(),
                ProfileVersion(),
                RoleId(),
                RoleName()
            {}

            CreateGroupRoleResponse(const CreateGroupRoleResponse& src) :
                PlayFabResultCommon(),
                ProfileVersion(src.ProfileVersion),
                RoleId(src.RoleId),
                RoleName(src.RoleName)
            {}

            ~CreateGroupRoleResponse() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilP(input[U("ProfileVersion")], ProfileVersion);
                FromJsonUtilS(input[U("RoleId")], RoleId);
                FromJsonUtilS(input[U("RoleName")], RoleName);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_ProfileVersion; ToJsonUtilP(ProfileVersion, each_ProfileVersion); output[U("ProfileVersion")] = each_ProfileVersion;
                web::json::value each_RoleId; ToJsonUtilS(RoleId, each_RoleId); output[U("RoleId")] = each_RoleId;
                web::json::value each_RoleName; ToJsonUtilS(RoleName, each_RoleName); output[U("RoleName")] = each_RoleName;
                return output;
            }
        };

        struct DeleteFilesRequest : public PlayFabRequestCommon
        {
            EntityKey Entity;
            std::list<std::string> FileNames;
            Boxed<Int32> ProfileVersion;

            DeleteFilesRequest() :
                PlayFabRequestCommon(),
                Entity(),
                FileNames(),
                ProfileVersion()
            {}

            DeleteFilesRequest(const DeleteFilesRequest& src) :
                PlayFabRequestCommon(),
                Entity(src.Entity),
                FileNames(src.FileNames),
                ProfileVersion(src.ProfileVersion)
            {}

            ~DeleteFilesRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[U("Entity")], Entity);
                FromJsonUtilS(input[U("FileNames")], FileNames);
                FromJsonUtilP(input[U("ProfileVersion")], ProfileVersion);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Entity; ToJsonUtilO(Entity, each_Entity); output[U("Entity")] = each_Entity;
                web::json::value each_FileNames; ToJsonUtilS(FileNames, each_FileNames); output[U("FileNames")] = each_FileNames;
                web::json::value each_ProfileVersion; ToJsonUtilP(ProfileVersion, each_ProfileVersion); output[U("ProfileVersion")] = each_ProfileVersion;
                return output;
            }
        };

        struct DeleteFilesResponse : public PlayFabResultCommon
        {
            Boxed<EntityKey> Entity;
            Int32 ProfileVersion;

            DeleteFilesResponse() :
                PlayFabResultCommon(),
                Entity(),
                ProfileVersion()
            {}

            DeleteFilesResponse(const DeleteFilesResponse& src) :
                PlayFabResultCommon(),
                Entity(src.Entity),
                ProfileVersion(src.ProfileVersion)
            {}

            ~DeleteFilesResponse() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[U("Entity")], Entity);
                FromJsonUtilP(input[U("ProfileVersion")], ProfileVersion);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Entity; ToJsonUtilO(Entity, each_Entity); output[U("Entity")] = each_Entity;
                web::json::value each_ProfileVersion; ToJsonUtilP(ProfileVersion, each_ProfileVersion); output[U("ProfileVersion")] = each_ProfileVersion;
                return output;
            }
        };

        struct DeleteGroupRequest : public PlayFabRequestCommon
        {
            EntityKey Group;

            DeleteGroupRequest() :
                PlayFabRequestCommon(),
                Group()
            {}

            DeleteGroupRequest(const DeleteGroupRequest& src) :
                PlayFabRequestCommon(),
                Group(src.Group)
            {}

            ~DeleteGroupRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[U("Group")], Group);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Group; ToJsonUtilO(Group, each_Group); output[U("Group")] = each_Group;
                return output;
            }
        };

        struct DeleteRoleRequest : public PlayFabRequestCommon
        {
            EntityKey Group;
            std::string RoleId;

            DeleteRoleRequest() :
                PlayFabRequestCommon(),
                Group(),
                RoleId()
            {}

            DeleteRoleRequest(const DeleteRoleRequest& src) :
                PlayFabRequestCommon(),
                Group(src.Group),
                RoleId(src.RoleId)
            {}

            ~DeleteRoleRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[U("Group")], Group);
                FromJsonUtilS(input[U("RoleId")], RoleId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Group; ToJsonUtilO(Group, each_Group); output[U("Group")] = each_Group;
                web::json::value each_RoleId; ToJsonUtilS(RoleId, each_RoleId); output[U("RoleId")] = each_RoleId;
                return output;
            }
        };

        struct EmptyResult : public PlayFabResultCommon
        {

            EmptyResult() :
                PlayFabResultCommon()
            {}

            EmptyResult(const EmptyResult&) :
                PlayFabResultCommon()
            {}

            ~EmptyResult() { }

            void FromJson(web::json::value&) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

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
                DataObject = input[U("DataObject")];
                FromJsonUtilS(input[U("EscapedDataObject")], EscapedDataObject);
                FromJsonUtilS(input[U("ObjectName")], ObjectName);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                output[U("DataObject")] = DataObject;
                web::json::value each_EscapedDataObject; ToJsonUtilS(EscapedDataObject, each_EscapedDataObject); output[U("EscapedDataObject")] = each_EscapedDataObject;
                web::json::value each_ObjectName; ToJsonUtilS(ObjectName, each_ObjectName); output[U("ObjectName")] = each_ObjectName;
                return output;
            }
        };

        struct EntityMemberRole : public PlayFabBaseModel
        {
            std::list<EntityWithLineage> Members;
            std::string RoleId;
            std::string RoleName;

            EntityMemberRole() :
                PlayFabBaseModel(),
                Members(),
                RoleId(),
                RoleName()
            {}

            EntityMemberRole(const EntityMemberRole& src) :
                PlayFabBaseModel(),
                Members(src.Members),
                RoleId(src.RoleId),
                RoleName(src.RoleName)
            {}

            ~EntityMemberRole() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[U("Members")], Members);
                FromJsonUtilS(input[U("RoleId")], RoleId);
                FromJsonUtilS(input[U("RoleName")], RoleName);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Members; ToJsonUtilO(Members, each_Members); output[U("Members")] = each_Members;
                web::json::value each_RoleId; ToJsonUtilS(RoleId, each_RoleId); output[U("RoleId")] = each_RoleId;
                web::json::value each_RoleName; ToJsonUtilS(RoleName, each_RoleName); output[U("RoleName")] = each_RoleName;
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
                FromJsonUtilS(input[U("Action")], Action);
                FromJsonUtilS(input[U("Comment")], Comment);
                Condition = input[U("Condition")];
                FromJsonEnum(input[U("Effect")], Effect);
                Principal = input[U("Principal")];
                FromJsonUtilS(input[U("Resource")], Resource);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Action; ToJsonUtilS(Action, each_Action); output[U("Action")] = each_Action;
                web::json::value each_Comment; ToJsonUtilS(Comment, each_Comment); output[U("Comment")] = each_Comment;
                output[U("Condition")] = Condition;
                web::json::value each_Effect; ToJsonEnum(Effect, each_Effect); output[U("Effect")] = each_Effect;
                output[U("Principal")] = Principal;
                web::json::value each_Resource; ToJsonUtilS(Resource, each_Resource); output[U("Resource")] = each_Resource;
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
                FromJsonUtilS(input[U("Checksum")], Checksum);
                FromJsonUtilS(input[U("FileName")], FileName);
                FromJsonUtilT(input[U("LastModified")], LastModified);
                FromJsonUtilP(input[U("Size")], Size);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Checksum; ToJsonUtilS(Checksum, each_Checksum); output[U("Checksum")] = each_Checksum;
                web::json::value each_FileName; ToJsonUtilS(FileName, each_FileName); output[U("FileName")] = each_FileName;
                web::json::value each_LastModified; ToJsonUtilT(LastModified, each_LastModified); output[U("LastModified")] = each_LastModified;
                web::json::value each_Size; ToJsonUtilP(Size, each_Size); output[U("Size")] = each_Size;
                return output;
            }
        };

        struct EntityProfileBody : public PlayFabBaseModel
        {
            Boxed<EntityKey> Entity;
            std::string EntityChain;
            std::map<std::string, EntityProfileFileMetadata> Files;
            std::map<std::string, EntityDataObject> Objects;
            std::list<EntityPermissionStatement> Permissions;
            Int32 VersionNumber;

            EntityProfileBody() :
                PlayFabBaseModel(),
                Entity(),
                EntityChain(),
                Files(),
                Objects(),
                Permissions(),
                VersionNumber()
            {}

            EntityProfileBody(const EntityProfileBody& src) :
                PlayFabBaseModel(),
                Entity(src.Entity),
                EntityChain(src.EntityChain),
                Files(src.Files),
                Objects(src.Objects),
                Permissions(src.Permissions),
                VersionNumber(src.VersionNumber)
            {}

            ~EntityProfileBody() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[U("Entity")], Entity);
                FromJsonUtilS(input[U("EntityChain")], EntityChain);
                FromJsonUtilO(input[U("Files")], Files);
                FromJsonUtilO(input[U("Objects")], Objects);
                FromJsonUtilO(input[U("Permissions")], Permissions);
                FromJsonUtilP(input[U("VersionNumber")], VersionNumber);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Entity; ToJsonUtilO(Entity, each_Entity); output[U("Entity")] = each_Entity;
                web::json::value each_EntityChain; ToJsonUtilS(EntityChain, each_EntityChain); output[U("EntityChain")] = each_EntityChain;
                web::json::value each_Files; ToJsonUtilO(Files, each_Files); output[U("Files")] = each_Files;
                web::json::value each_Objects; ToJsonUtilO(Objects, each_Objects); output[U("Objects")] = each_Objects;
                web::json::value each_Permissions; ToJsonUtilO(Permissions, each_Permissions); output[U("Permissions")] = each_Permissions;
                web::json::value each_VersionNumber; ToJsonUtilP(VersionNumber, each_VersionNumber); output[U("VersionNumber")] = each_VersionNumber;
                return output;
            }
        };

        struct FinalizeFileUploadsRequest : public PlayFabRequestCommon
        {
            EntityKey Entity;
            std::list<std::string> FileNames;

            FinalizeFileUploadsRequest() :
                PlayFabRequestCommon(),
                Entity(),
                FileNames()
            {}

            FinalizeFileUploadsRequest(const FinalizeFileUploadsRequest& src) :
                PlayFabRequestCommon(),
                Entity(src.Entity),
                FileNames(src.FileNames)
            {}

            ~FinalizeFileUploadsRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[U("Entity")], Entity);
                FromJsonUtilS(input[U("FileNames")], FileNames);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Entity; ToJsonUtilO(Entity, each_Entity); output[U("Entity")] = each_Entity;
                web::json::value each_FileNames; ToJsonUtilS(FileNames, each_FileNames); output[U("FileNames")] = each_FileNames;
                return output;
            }
        };

        struct GetFileMetadata : public PlayFabBaseModel
        {
            std::string Checksum;
            std::string DownloadUrl;
            std::string FileName;
            time_t LastModified;
            Int32 Size;

            GetFileMetadata() :
                PlayFabBaseModel(),
                Checksum(),
                DownloadUrl(),
                FileName(),
                LastModified(),
                Size()
            {}

            GetFileMetadata(const GetFileMetadata& src) :
                PlayFabBaseModel(),
                Checksum(src.Checksum),
                DownloadUrl(src.DownloadUrl),
                FileName(src.FileName),
                LastModified(src.LastModified),
                Size(src.Size)
            {}

            ~GetFileMetadata() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("Checksum")], Checksum);
                FromJsonUtilS(input[U("DownloadUrl")], DownloadUrl);
                FromJsonUtilS(input[U("FileName")], FileName);
                FromJsonUtilT(input[U("LastModified")], LastModified);
                FromJsonUtilP(input[U("Size")], Size);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Checksum; ToJsonUtilS(Checksum, each_Checksum); output[U("Checksum")] = each_Checksum;
                web::json::value each_DownloadUrl; ToJsonUtilS(DownloadUrl, each_DownloadUrl); output[U("DownloadUrl")] = each_DownloadUrl;
                web::json::value each_FileName; ToJsonUtilS(FileName, each_FileName); output[U("FileName")] = each_FileName;
                web::json::value each_LastModified; ToJsonUtilT(LastModified, each_LastModified); output[U("LastModified")] = each_LastModified;
                web::json::value each_Size; ToJsonUtilP(Size, each_Size); output[U("Size")] = each_Size;
                return output;
            }
        };

        struct FinalizeFileUploadsResponse : public PlayFabResultCommon
        {
            Boxed<EntityKey> Entity;
            std::map<std::string, GetFileMetadata> Metadata;
            Int32 ProfileVersion;

            FinalizeFileUploadsResponse() :
                PlayFabResultCommon(),
                Entity(),
                Metadata(),
                ProfileVersion()
            {}

            FinalizeFileUploadsResponse(const FinalizeFileUploadsResponse& src) :
                PlayFabResultCommon(),
                Entity(src.Entity),
                Metadata(src.Metadata),
                ProfileVersion(src.ProfileVersion)
            {}

            ~FinalizeFileUploadsResponse() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[U("Entity")], Entity);
                FromJsonUtilO(input[U("Metadata")], Metadata);
                FromJsonUtilP(input[U("ProfileVersion")], ProfileVersion);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Entity; ToJsonUtilO(Entity, each_Entity); output[U("Entity")] = each_Entity;
                web::json::value each_Metadata; ToJsonUtilO(Metadata, each_Metadata); output[U("Metadata")] = each_Metadata;
                web::json::value each_ProfileVersion; ToJsonUtilP(ProfileVersion, each_ProfileVersion); output[U("ProfileVersion")] = each_ProfileVersion;
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
                FromJsonUtilP(input[U("DataAsObject")], DataAsObject);
                FromJsonUtilO(input[U("Entity")], Entity);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_DataAsObject; ToJsonUtilP(DataAsObject, each_DataAsObject); output[U("DataAsObject")] = each_DataAsObject;
                web::json::value each_Entity; ToJsonUtilO(Entity, each_Entity); output[U("Entity")] = each_Entity;
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
                FromJsonUtilO(input[U("Profile")], Profile);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Profile; ToJsonUtilO(Profile, each_Profile); output[U("Profile")] = each_Profile;
                return output;
            }
        };

        struct GetEntityTokenRequest : public PlayFabRequestCommon
        {
            Boxed<EntityKey> Entity;

            GetEntityTokenRequest() :
                PlayFabRequestCommon(),
                Entity()
            {}

            GetEntityTokenRequest(const GetEntityTokenRequest& src) :
                PlayFabRequestCommon(),
                Entity(src.Entity)
            {}

            ~GetEntityTokenRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[U("Entity")], Entity);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Entity; ToJsonUtilO(Entity, each_Entity); output[U("Entity")] = each_Entity;
                return output;
            }
        };

        struct GetEntityTokenResponse : public PlayFabResultCommon
        {
            Boxed<EntityKey> Entity;
            std::string EntityToken;
            Boxed<time_t> TokenExpiration;

            GetEntityTokenResponse() :
                PlayFabResultCommon(),
                Entity(),
                EntityToken(),
                TokenExpiration()
            {}

            GetEntityTokenResponse(const GetEntityTokenResponse& src) :
                PlayFabResultCommon(),
                Entity(src.Entity),
                EntityToken(src.EntityToken),
                TokenExpiration(src.TokenExpiration)
            {}

            ~GetEntityTokenResponse() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[U("Entity")], Entity);
                FromJsonUtilS(input[U("EntityToken")], EntityToken);
                FromJsonUtilT(input[U("TokenExpiration")], TokenExpiration);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Entity; ToJsonUtilO(Entity, each_Entity); output[U("Entity")] = each_Entity;
                web::json::value each_EntityToken; ToJsonUtilS(EntityToken, each_EntityToken); output[U("EntityToken")] = each_EntityToken;
                web::json::value each_TokenExpiration; ToJsonUtilT(TokenExpiration, each_TokenExpiration); output[U("TokenExpiration")] = each_TokenExpiration;
                return output;
            }
        };

        struct GetFilesRequest : public PlayFabRequestCommon
        {
            EntityKey Entity;

            GetFilesRequest() :
                PlayFabRequestCommon(),
                Entity()
            {}

            GetFilesRequest(const GetFilesRequest& src) :
                PlayFabRequestCommon(),
                Entity(src.Entity)
            {}

            ~GetFilesRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[U("Entity")], Entity);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Entity; ToJsonUtilO(Entity, each_Entity); output[U("Entity")] = each_Entity;
                return output;
            }
        };

        struct GetFilesResponse : public PlayFabResultCommon
        {
            Boxed<EntityKey> Entity;
            std::map<std::string, GetFileMetadata> Metadata;
            Int32 ProfileVersion;

            GetFilesResponse() :
                PlayFabResultCommon(),
                Entity(),
                Metadata(),
                ProfileVersion()
            {}

            GetFilesResponse(const GetFilesResponse& src) :
                PlayFabResultCommon(),
                Entity(src.Entity),
                Metadata(src.Metadata),
                ProfileVersion(src.ProfileVersion)
            {}

            ~GetFilesResponse() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[U("Entity")], Entity);
                FromJsonUtilO(input[U("Metadata")], Metadata);
                FromJsonUtilP(input[U("ProfileVersion")], ProfileVersion);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Entity; ToJsonUtilO(Entity, each_Entity); output[U("Entity")] = each_Entity;
                web::json::value each_Metadata; ToJsonUtilO(Metadata, each_Metadata); output[U("Metadata")] = each_Metadata;
                web::json::value each_ProfileVersion; ToJsonUtilP(ProfileVersion, each_ProfileVersion); output[U("ProfileVersion")] = each_ProfileVersion;
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
                FromJsonUtilO(input[U("Permissions")], Permissions);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Permissions; ToJsonUtilO(Permissions, each_Permissions); output[U("Permissions")] = each_Permissions;
                return output;
            }
        };

        struct GetGroupRequest : public PlayFabRequestCommon
        {
            Boxed<EntityKey> Group;
            std::string GroupName;

            GetGroupRequest() :
                PlayFabRequestCommon(),
                Group(),
                GroupName()
            {}

            GetGroupRequest(const GetGroupRequest& src) :
                PlayFabRequestCommon(),
                Group(src.Group),
                GroupName(src.GroupName)
            {}

            ~GetGroupRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[U("Group")], Group);
                FromJsonUtilS(input[U("GroupName")], GroupName);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Group; ToJsonUtilO(Group, each_Group); output[U("Group")] = each_Group;
                web::json::value each_GroupName; ToJsonUtilS(GroupName, each_GroupName); output[U("GroupName")] = each_GroupName;
                return output;
            }
        };

        struct GetGroupResponse : public PlayFabResultCommon
        {
            std::string AdminRoleId;
            time_t Created;
            EntityKey Group;
            std::string GroupName;
            std::string MemberRoleId;
            Int32 ProfileVersion;
            std::map<std::string, std::string> Roles;

            GetGroupResponse() :
                PlayFabResultCommon(),
                AdminRoleId(),
                Created(),
                Group(),
                GroupName(),
                MemberRoleId(),
                ProfileVersion(),
                Roles()
            {}

            GetGroupResponse(const GetGroupResponse& src) :
                PlayFabResultCommon(),
                AdminRoleId(src.AdminRoleId),
                Created(src.Created),
                Group(src.Group),
                GroupName(src.GroupName),
                MemberRoleId(src.MemberRoleId),
                ProfileVersion(src.ProfileVersion),
                Roles(src.Roles)
            {}

            ~GetGroupResponse() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("AdminRoleId")], AdminRoleId);
                FromJsonUtilT(input[U("Created")], Created);
                FromJsonUtilO(input[U("Group")], Group);
                FromJsonUtilS(input[U("GroupName")], GroupName);
                FromJsonUtilS(input[U("MemberRoleId")], MemberRoleId);
                FromJsonUtilP(input[U("ProfileVersion")], ProfileVersion);
                FromJsonUtilS(input[U("Roles")], Roles);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_AdminRoleId; ToJsonUtilS(AdminRoleId, each_AdminRoleId); output[U("AdminRoleId")] = each_AdminRoleId;
                web::json::value each_Created; ToJsonUtilT(Created, each_Created); output[U("Created")] = each_Created;
                web::json::value each_Group; ToJsonUtilO(Group, each_Group); output[U("Group")] = each_Group;
                web::json::value each_GroupName; ToJsonUtilS(GroupName, each_GroupName); output[U("GroupName")] = each_GroupName;
                web::json::value each_MemberRoleId; ToJsonUtilS(MemberRoleId, each_MemberRoleId); output[U("MemberRoleId")] = each_MemberRoleId;
                web::json::value each_ProfileVersion; ToJsonUtilP(ProfileVersion, each_ProfileVersion); output[U("ProfileVersion")] = each_ProfileVersion;
                web::json::value each_Roles; ToJsonUtilS(Roles, each_Roles); output[U("Roles")] = each_Roles;
                return output;
            }
        };

        struct GetObjectsRequest : public PlayFabRequestCommon
        {
            EntityKey Entity;
            Boxed<bool> EscapeObject;

            GetObjectsRequest() :
                PlayFabRequestCommon(),
                Entity(),
                EscapeObject()
            {}

            GetObjectsRequest(const GetObjectsRequest& src) :
                PlayFabRequestCommon(),
                Entity(src.Entity),
                EscapeObject(src.EscapeObject)
            {}

            ~GetObjectsRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[U("Entity")], Entity);
                FromJsonUtilP(input[U("EscapeObject")], EscapeObject);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Entity; ToJsonUtilO(Entity, each_Entity); output[U("Entity")] = each_Entity;
                web::json::value each_EscapeObject; ToJsonUtilP(EscapeObject, each_EscapeObject); output[U("EscapeObject")] = each_EscapeObject;
                return output;
            }
        };

        struct ObjectResult : public PlayFabResultCommon
        {
            web::json::value DataObject;
            std::string EscapedDataObject;
            std::string ObjectName;

            ObjectResult() :
                PlayFabResultCommon(),
                DataObject(),
                EscapedDataObject(),
                ObjectName()
            {}

            ObjectResult(const ObjectResult& src) :
                PlayFabResultCommon(),
                DataObject(src.DataObject),
                EscapedDataObject(src.EscapedDataObject),
                ObjectName(src.ObjectName)
            {}

            ~ObjectResult() { }

            void FromJson(web::json::value& input) override
            {
                DataObject = input[U("DataObject")];
                FromJsonUtilS(input[U("EscapedDataObject")], EscapedDataObject);
                FromJsonUtilS(input[U("ObjectName")], ObjectName);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                output[U("DataObject")] = DataObject;
                web::json::value each_EscapedDataObject; ToJsonUtilS(EscapedDataObject, each_EscapedDataObject); output[U("EscapedDataObject")] = each_EscapedDataObject;
                web::json::value each_ObjectName; ToJsonUtilS(ObjectName, each_ObjectName); output[U("ObjectName")] = each_ObjectName;
                return output;
            }
        };

        struct GetObjectsResponse : public PlayFabResultCommon
        {
            Boxed<EntityKey> Entity;
            std::map<std::string, ObjectResult> Objects;
            Int32 ProfileVersion;

            GetObjectsResponse() :
                PlayFabResultCommon(),
                Entity(),
                Objects(),
                ProfileVersion()
            {}

            GetObjectsResponse(const GetObjectsResponse& src) :
                PlayFabResultCommon(),
                Entity(src.Entity),
                Objects(src.Objects),
                ProfileVersion(src.ProfileVersion)
            {}

            ~GetObjectsResponse() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[U("Entity")], Entity);
                FromJsonUtilO(input[U("Objects")], Objects);
                FromJsonUtilP(input[U("ProfileVersion")], ProfileVersion);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Entity; ToJsonUtilO(Entity, each_Entity); output[U("Entity")] = each_Entity;
                web::json::value each_Objects; ToJsonUtilO(Objects, each_Objects); output[U("Objects")] = each_Objects;
                web::json::value each_ProfileVersion; ToJsonUtilP(ProfileVersion, each_ProfileVersion); output[U("ProfileVersion")] = each_ProfileVersion;
                return output;
            }
        };

        struct GroupApplication : public PlayFabBaseModel
        {
            Boxed<EntityWithLineage> Entity;
            time_t Expires;
            Boxed<EntityKey> Group;

            GroupApplication() :
                PlayFabBaseModel(),
                Entity(),
                Expires(),
                Group()
            {}

            GroupApplication(const GroupApplication& src) :
                PlayFabBaseModel(),
                Entity(src.Entity),
                Expires(src.Expires),
                Group(src.Group)
            {}

            ~GroupApplication() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[U("Entity")], Entity);
                FromJsonUtilT(input[U("Expires")], Expires);
                FromJsonUtilO(input[U("Group")], Group);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Entity; ToJsonUtilO(Entity, each_Entity); output[U("Entity")] = each_Entity;
                web::json::value each_Expires; ToJsonUtilT(Expires, each_Expires); output[U("Expires")] = each_Expires;
                web::json::value each_Group; ToJsonUtilO(Group, each_Group); output[U("Group")] = each_Group;
                return output;
            }
        };

        struct GroupBlock : public PlayFabBaseModel
        {
            Boxed<EntityWithLineage> Entity;
            EntityKey Group;

            GroupBlock() :
                PlayFabBaseModel(),
                Entity(),
                Group()
            {}

            GroupBlock(const GroupBlock& src) :
                PlayFabBaseModel(),
                Entity(src.Entity),
                Group(src.Group)
            {}

            ~GroupBlock() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[U("Entity")], Entity);
                FromJsonUtilO(input[U("Group")], Group);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Entity; ToJsonUtilO(Entity, each_Entity); output[U("Entity")] = each_Entity;
                web::json::value each_Group; ToJsonUtilO(Group, each_Group); output[U("Group")] = each_Group;
                return output;
            }
        };

        struct GroupInvitation : public PlayFabBaseModel
        {
            time_t Expires;
            Boxed<EntityKey> Group;
            Boxed<EntityWithLineage> InvitedByEntity;
            Boxed<EntityWithLineage> InvitedEntity;
            std::string RoleId;

            GroupInvitation() :
                PlayFabBaseModel(),
                Expires(),
                Group(),
                InvitedByEntity(),
                InvitedEntity(),
                RoleId()
            {}

            GroupInvitation(const GroupInvitation& src) :
                PlayFabBaseModel(),
                Expires(src.Expires),
                Group(src.Group),
                InvitedByEntity(src.InvitedByEntity),
                InvitedEntity(src.InvitedEntity),
                RoleId(src.RoleId)
            {}

            ~GroupInvitation() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilT(input[U("Expires")], Expires);
                FromJsonUtilO(input[U("Group")], Group);
                FromJsonUtilO(input[U("InvitedByEntity")], InvitedByEntity);
                FromJsonUtilO(input[U("InvitedEntity")], InvitedEntity);
                FromJsonUtilS(input[U("RoleId")], RoleId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Expires; ToJsonUtilT(Expires, each_Expires); output[U("Expires")] = each_Expires;
                web::json::value each_Group; ToJsonUtilO(Group, each_Group); output[U("Group")] = each_Group;
                web::json::value each_InvitedByEntity; ToJsonUtilO(InvitedByEntity, each_InvitedByEntity); output[U("InvitedByEntity")] = each_InvitedByEntity;
                web::json::value each_InvitedEntity; ToJsonUtilO(InvitedEntity, each_InvitedEntity); output[U("InvitedEntity")] = each_InvitedEntity;
                web::json::value each_RoleId; ToJsonUtilS(RoleId, each_RoleId); output[U("RoleId")] = each_RoleId;
                return output;
            }
        };

        struct GroupRole : public PlayFabBaseModel
        {
            std::string RoleId;
            std::string RoleName;

            GroupRole() :
                PlayFabBaseModel(),
                RoleId(),
                RoleName()
            {}

            GroupRole(const GroupRole& src) :
                PlayFabBaseModel(),
                RoleId(src.RoleId),
                RoleName(src.RoleName)
            {}

            ~GroupRole() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("RoleId")], RoleId);
                FromJsonUtilS(input[U("RoleName")], RoleName);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_RoleId; ToJsonUtilS(RoleId, each_RoleId); output[U("RoleId")] = each_RoleId;
                web::json::value each_RoleName; ToJsonUtilS(RoleName, each_RoleName); output[U("RoleName")] = each_RoleName;
                return output;
            }
        };

        struct GroupWithRoles : public PlayFabBaseModel
        {
            Boxed<EntityKey> Group;
            std::string GroupName;
            Int32 ProfileVersion;
            std::list<GroupRole> Roles;

            GroupWithRoles() :
                PlayFabBaseModel(),
                Group(),
                GroupName(),
                ProfileVersion(),
                Roles()
            {}

            GroupWithRoles(const GroupWithRoles& src) :
                PlayFabBaseModel(),
                Group(src.Group),
                GroupName(src.GroupName),
                ProfileVersion(src.ProfileVersion),
                Roles(src.Roles)
            {}

            ~GroupWithRoles() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[U("Group")], Group);
                FromJsonUtilS(input[U("GroupName")], GroupName);
                FromJsonUtilP(input[U("ProfileVersion")], ProfileVersion);
                FromJsonUtilO(input[U("Roles")], Roles);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Group; ToJsonUtilO(Group, each_Group); output[U("Group")] = each_Group;
                web::json::value each_GroupName; ToJsonUtilS(GroupName, each_GroupName); output[U("GroupName")] = each_GroupName;
                web::json::value each_ProfileVersion; ToJsonUtilP(ProfileVersion, each_ProfileVersion); output[U("ProfileVersion")] = each_ProfileVersion;
                web::json::value each_Roles; ToJsonUtilO(Roles, each_Roles); output[U("Roles")] = each_Roles;
                return output;
            }
        };

        struct InitiateFileUploadMetadata : public PlayFabBaseModel
        {
            std::string FileName;
            std::string UploadUrl;

            InitiateFileUploadMetadata() :
                PlayFabBaseModel(),
                FileName(),
                UploadUrl()
            {}

            InitiateFileUploadMetadata(const InitiateFileUploadMetadata& src) :
                PlayFabBaseModel(),
                FileName(src.FileName),
                UploadUrl(src.UploadUrl)
            {}

            ~InitiateFileUploadMetadata() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("FileName")], FileName);
                FromJsonUtilS(input[U("UploadUrl")], UploadUrl);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_FileName; ToJsonUtilS(FileName, each_FileName); output[U("FileName")] = each_FileName;
                web::json::value each_UploadUrl; ToJsonUtilS(UploadUrl, each_UploadUrl); output[U("UploadUrl")] = each_UploadUrl;
                return output;
            }
        };

        struct InitiateFileUploadsRequest : public PlayFabRequestCommon
        {
            EntityKey Entity;
            std::list<std::string> FileNames;
            Boxed<Int32> ProfileVersion;

            InitiateFileUploadsRequest() :
                PlayFabRequestCommon(),
                Entity(),
                FileNames(),
                ProfileVersion()
            {}

            InitiateFileUploadsRequest(const InitiateFileUploadsRequest& src) :
                PlayFabRequestCommon(),
                Entity(src.Entity),
                FileNames(src.FileNames),
                ProfileVersion(src.ProfileVersion)
            {}

            ~InitiateFileUploadsRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[U("Entity")], Entity);
                FromJsonUtilS(input[U("FileNames")], FileNames);
                FromJsonUtilP(input[U("ProfileVersion")], ProfileVersion);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Entity; ToJsonUtilO(Entity, each_Entity); output[U("Entity")] = each_Entity;
                web::json::value each_FileNames; ToJsonUtilS(FileNames, each_FileNames); output[U("FileNames")] = each_FileNames;
                web::json::value each_ProfileVersion; ToJsonUtilP(ProfileVersion, each_ProfileVersion); output[U("ProfileVersion")] = each_ProfileVersion;
                return output;
            }
        };

        struct InitiateFileUploadsResponse : public PlayFabResultCommon
        {
            Boxed<EntityKey> Entity;
            Int32 ProfileVersion;
            std::list<InitiateFileUploadMetadata> UploadDetails;

            InitiateFileUploadsResponse() :
                PlayFabResultCommon(),
                Entity(),
                ProfileVersion(),
                UploadDetails()
            {}

            InitiateFileUploadsResponse(const InitiateFileUploadsResponse& src) :
                PlayFabResultCommon(),
                Entity(src.Entity),
                ProfileVersion(src.ProfileVersion),
                UploadDetails(src.UploadDetails)
            {}

            ~InitiateFileUploadsResponse() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[U("Entity")], Entity);
                FromJsonUtilP(input[U("ProfileVersion")], ProfileVersion);
                FromJsonUtilO(input[U("UploadDetails")], UploadDetails);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Entity; ToJsonUtilO(Entity, each_Entity); output[U("Entity")] = each_Entity;
                web::json::value each_ProfileVersion; ToJsonUtilP(ProfileVersion, each_ProfileVersion); output[U("ProfileVersion")] = each_ProfileVersion;
                web::json::value each_UploadDetails; ToJsonUtilO(UploadDetails, each_UploadDetails); output[U("UploadDetails")] = each_UploadDetails;
                return output;
            }
        };

        struct InviteToGroupRequest : public PlayFabRequestCommon
        {
            Boxed<bool> AutoAcceptOutstandingApplication;
            EntityKey Entity;
            EntityKey Group;
            std::string RoleId;

            InviteToGroupRequest() :
                PlayFabRequestCommon(),
                AutoAcceptOutstandingApplication(),
                Entity(),
                Group(),
                RoleId()
            {}

            InviteToGroupRequest(const InviteToGroupRequest& src) :
                PlayFabRequestCommon(),
                AutoAcceptOutstandingApplication(src.AutoAcceptOutstandingApplication),
                Entity(src.Entity),
                Group(src.Group),
                RoleId(src.RoleId)
            {}

            ~InviteToGroupRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilP(input[U("AutoAcceptOutstandingApplication")], AutoAcceptOutstandingApplication);
                FromJsonUtilO(input[U("Entity")], Entity);
                FromJsonUtilO(input[U("Group")], Group);
                FromJsonUtilS(input[U("RoleId")], RoleId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_AutoAcceptOutstandingApplication; ToJsonUtilP(AutoAcceptOutstandingApplication, each_AutoAcceptOutstandingApplication); output[U("AutoAcceptOutstandingApplication")] = each_AutoAcceptOutstandingApplication;
                web::json::value each_Entity; ToJsonUtilO(Entity, each_Entity); output[U("Entity")] = each_Entity;
                web::json::value each_Group; ToJsonUtilO(Group, each_Group); output[U("Group")] = each_Group;
                web::json::value each_RoleId; ToJsonUtilS(RoleId, each_RoleId); output[U("RoleId")] = each_RoleId;
                return output;
            }
        };

        struct InviteToGroupResponse : public PlayFabResultCommon
        {
            time_t Expires;
            Boxed<EntityKey> Group;
            Boxed<EntityWithLineage> InvitedByEntity;
            Boxed<EntityWithLineage> InvitedEntity;
            std::string RoleId;

            InviteToGroupResponse() :
                PlayFabResultCommon(),
                Expires(),
                Group(),
                InvitedByEntity(),
                InvitedEntity(),
                RoleId()
            {}

            InviteToGroupResponse(const InviteToGroupResponse& src) :
                PlayFabResultCommon(),
                Expires(src.Expires),
                Group(src.Group),
                InvitedByEntity(src.InvitedByEntity),
                InvitedEntity(src.InvitedEntity),
                RoleId(src.RoleId)
            {}

            ~InviteToGroupResponse() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilT(input[U("Expires")], Expires);
                FromJsonUtilO(input[U("Group")], Group);
                FromJsonUtilO(input[U("InvitedByEntity")], InvitedByEntity);
                FromJsonUtilO(input[U("InvitedEntity")], InvitedEntity);
                FromJsonUtilS(input[U("RoleId")], RoleId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Expires; ToJsonUtilT(Expires, each_Expires); output[U("Expires")] = each_Expires;
                web::json::value each_Group; ToJsonUtilO(Group, each_Group); output[U("Group")] = each_Group;
                web::json::value each_InvitedByEntity; ToJsonUtilO(InvitedByEntity, each_InvitedByEntity); output[U("InvitedByEntity")] = each_InvitedByEntity;
                web::json::value each_InvitedEntity; ToJsonUtilO(InvitedEntity, each_InvitedEntity); output[U("InvitedEntity")] = each_InvitedEntity;
                web::json::value each_RoleId; ToJsonUtilS(RoleId, each_RoleId); output[U("RoleId")] = each_RoleId;
                return output;
            }
        };

        struct IsMemberRequest : public PlayFabRequestCommon
        {
            EntityKey Entity;
            EntityKey Group;
            std::string RoleId;

            IsMemberRequest() :
                PlayFabRequestCommon(),
                Entity(),
                Group(),
                RoleId()
            {}

            IsMemberRequest(const IsMemberRequest& src) :
                PlayFabRequestCommon(),
                Entity(src.Entity),
                Group(src.Group),
                RoleId(src.RoleId)
            {}

            ~IsMemberRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[U("Entity")], Entity);
                FromJsonUtilO(input[U("Group")], Group);
                FromJsonUtilS(input[U("RoleId")], RoleId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Entity; ToJsonUtilO(Entity, each_Entity); output[U("Entity")] = each_Entity;
                web::json::value each_Group; ToJsonUtilO(Group, each_Group); output[U("Group")] = each_Group;
                web::json::value each_RoleId; ToJsonUtilS(RoleId, each_RoleId); output[U("RoleId")] = each_RoleId;
                return output;
            }
        };

        struct IsMemberResponse : public PlayFabResultCommon
        {
            bool IsMember;

            IsMemberResponse() :
                PlayFabResultCommon(),
                IsMember()
            {}

            IsMemberResponse(const IsMemberResponse& src) :
                PlayFabResultCommon(),
                IsMember(src.IsMember)
            {}

            ~IsMemberResponse() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilP(input[U("IsMember")], IsMember);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_IsMember; ToJsonUtilP(IsMember, each_IsMember); output[U("IsMember")] = each_IsMember;
                return output;
            }
        };

        struct ListGroupApplicationsRequest : public PlayFabRequestCommon
        {
            EntityKey Group;

            ListGroupApplicationsRequest() :
                PlayFabRequestCommon(),
                Group()
            {}

            ListGroupApplicationsRequest(const ListGroupApplicationsRequest& src) :
                PlayFabRequestCommon(),
                Group(src.Group)
            {}

            ~ListGroupApplicationsRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[U("Group")], Group);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Group; ToJsonUtilO(Group, each_Group); output[U("Group")] = each_Group;
                return output;
            }
        };

        struct ListGroupApplicationsResponse : public PlayFabResultCommon
        {
            std::list<GroupApplication> Applications;

            ListGroupApplicationsResponse() :
                PlayFabResultCommon(),
                Applications()
            {}

            ListGroupApplicationsResponse(const ListGroupApplicationsResponse& src) :
                PlayFabResultCommon(),
                Applications(src.Applications)
            {}

            ~ListGroupApplicationsResponse() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[U("Applications")], Applications);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Applications; ToJsonUtilO(Applications, each_Applications); output[U("Applications")] = each_Applications;
                return output;
            }
        };

        struct ListGroupBlocksRequest : public PlayFabRequestCommon
        {
            EntityKey Group;

            ListGroupBlocksRequest() :
                PlayFabRequestCommon(),
                Group()
            {}

            ListGroupBlocksRequest(const ListGroupBlocksRequest& src) :
                PlayFabRequestCommon(),
                Group(src.Group)
            {}

            ~ListGroupBlocksRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[U("Group")], Group);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Group; ToJsonUtilO(Group, each_Group); output[U("Group")] = each_Group;
                return output;
            }
        };

        struct ListGroupBlocksResponse : public PlayFabResultCommon
        {
            std::list<GroupBlock> BlockedEntities;

            ListGroupBlocksResponse() :
                PlayFabResultCommon(),
                BlockedEntities()
            {}

            ListGroupBlocksResponse(const ListGroupBlocksResponse& src) :
                PlayFabResultCommon(),
                BlockedEntities(src.BlockedEntities)
            {}

            ~ListGroupBlocksResponse() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[U("BlockedEntities")], BlockedEntities);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_BlockedEntities; ToJsonUtilO(BlockedEntities, each_BlockedEntities); output[U("BlockedEntities")] = each_BlockedEntities;
                return output;
            }
        };

        struct ListGroupInvitationsRequest : public PlayFabRequestCommon
        {
            EntityKey Group;

            ListGroupInvitationsRequest() :
                PlayFabRequestCommon(),
                Group()
            {}

            ListGroupInvitationsRequest(const ListGroupInvitationsRequest& src) :
                PlayFabRequestCommon(),
                Group(src.Group)
            {}

            ~ListGroupInvitationsRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[U("Group")], Group);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Group; ToJsonUtilO(Group, each_Group); output[U("Group")] = each_Group;
                return output;
            }
        };

        struct ListGroupInvitationsResponse : public PlayFabResultCommon
        {
            std::list<GroupInvitation> Invitations;

            ListGroupInvitationsResponse() :
                PlayFabResultCommon(),
                Invitations()
            {}

            ListGroupInvitationsResponse(const ListGroupInvitationsResponse& src) :
                PlayFabResultCommon(),
                Invitations(src.Invitations)
            {}

            ~ListGroupInvitationsResponse() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[U("Invitations")], Invitations);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Invitations; ToJsonUtilO(Invitations, each_Invitations); output[U("Invitations")] = each_Invitations;
                return output;
            }
        };

        struct ListGroupMembersRequest : public PlayFabRequestCommon
        {
            EntityKey Group;

            ListGroupMembersRequest() :
                PlayFabRequestCommon(),
                Group()
            {}

            ListGroupMembersRequest(const ListGroupMembersRequest& src) :
                PlayFabRequestCommon(),
                Group(src.Group)
            {}

            ~ListGroupMembersRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[U("Group")], Group);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Group; ToJsonUtilO(Group, each_Group); output[U("Group")] = each_Group;
                return output;
            }
        };

        struct ListGroupMembersResponse : public PlayFabResultCommon
        {
            std::list<EntityMemberRole> Members;

            ListGroupMembersResponse() :
                PlayFabResultCommon(),
                Members()
            {}

            ListGroupMembersResponse(const ListGroupMembersResponse& src) :
                PlayFabResultCommon(),
                Members(src.Members)
            {}

            ~ListGroupMembersResponse() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[U("Members")], Members);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Members; ToJsonUtilO(Members, each_Members); output[U("Members")] = each_Members;
                return output;
            }
        };

        struct ListMembershipOpportunitiesRequest : public PlayFabRequestCommon
        {
            Boxed<EntityKey> Entity;

            ListMembershipOpportunitiesRequest() :
                PlayFabRequestCommon(),
                Entity()
            {}

            ListMembershipOpportunitiesRequest(const ListMembershipOpportunitiesRequest& src) :
                PlayFabRequestCommon(),
                Entity(src.Entity)
            {}

            ~ListMembershipOpportunitiesRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[U("Entity")], Entity);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Entity; ToJsonUtilO(Entity, each_Entity); output[U("Entity")] = each_Entity;
                return output;
            }
        };

        struct ListMembershipOpportunitiesResponse : public PlayFabResultCommon
        {
            std::list<GroupApplication> Applications;
            std::list<GroupInvitation> Invitations;

            ListMembershipOpportunitiesResponse() :
                PlayFabResultCommon(),
                Applications(),
                Invitations()
            {}

            ListMembershipOpportunitiesResponse(const ListMembershipOpportunitiesResponse& src) :
                PlayFabResultCommon(),
                Applications(src.Applications),
                Invitations(src.Invitations)
            {}

            ~ListMembershipOpportunitiesResponse() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[U("Applications")], Applications);
                FromJsonUtilO(input[U("Invitations")], Invitations);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Applications; ToJsonUtilO(Applications, each_Applications); output[U("Applications")] = each_Applications;
                web::json::value each_Invitations; ToJsonUtilO(Invitations, each_Invitations); output[U("Invitations")] = each_Invitations;
                return output;
            }
        };

        struct ListMembershipRequest : public PlayFabRequestCommon
        {
            Boxed<EntityKey> Entity;

            ListMembershipRequest() :
                PlayFabRequestCommon(),
                Entity()
            {}

            ListMembershipRequest(const ListMembershipRequest& src) :
                PlayFabRequestCommon(),
                Entity(src.Entity)
            {}

            ~ListMembershipRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[U("Entity")], Entity);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Entity; ToJsonUtilO(Entity, each_Entity); output[U("Entity")] = each_Entity;
                return output;
            }
        };

        struct ListMembershipResponse : public PlayFabResultCommon
        {
            std::list<GroupWithRoles> Groups;

            ListMembershipResponse() :
                PlayFabResultCommon(),
                Groups()
            {}

            ListMembershipResponse(const ListMembershipResponse& src) :
                PlayFabResultCommon(),
                Groups(src.Groups)
            {}

            ~ListMembershipResponse() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[U("Groups")], Groups);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Groups; ToJsonUtilO(Groups, each_Groups); output[U("Groups")] = each_Groups;
                return output;
            }
        };

        struct RemoveGroupApplicationRequest : public PlayFabRequestCommon
        {
            EntityKey Entity;
            EntityKey Group;

            RemoveGroupApplicationRequest() :
                PlayFabRequestCommon(),
                Entity(),
                Group()
            {}

            RemoveGroupApplicationRequest(const RemoveGroupApplicationRequest& src) :
                PlayFabRequestCommon(),
                Entity(src.Entity),
                Group(src.Group)
            {}

            ~RemoveGroupApplicationRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[U("Entity")], Entity);
                FromJsonUtilO(input[U("Group")], Group);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Entity; ToJsonUtilO(Entity, each_Entity); output[U("Entity")] = each_Entity;
                web::json::value each_Group; ToJsonUtilO(Group, each_Group); output[U("Group")] = each_Group;
                return output;
            }
        };

        struct RemoveGroupInvitationRequest : public PlayFabRequestCommon
        {
            EntityKey Entity;
            EntityKey Group;

            RemoveGroupInvitationRequest() :
                PlayFabRequestCommon(),
                Entity(),
                Group()
            {}

            RemoveGroupInvitationRequest(const RemoveGroupInvitationRequest& src) :
                PlayFabRequestCommon(),
                Entity(src.Entity),
                Group(src.Group)
            {}

            ~RemoveGroupInvitationRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[U("Entity")], Entity);
                FromJsonUtilO(input[U("Group")], Group);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Entity; ToJsonUtilO(Entity, each_Entity); output[U("Entity")] = each_Entity;
                web::json::value each_Group; ToJsonUtilO(Group, each_Group); output[U("Group")] = each_Group;
                return output;
            }
        };

        struct RemoveMembersRequest : public PlayFabRequestCommon
        {
            EntityKey Group;
            std::list<EntityKey> Members;
            std::string RoleId;

            RemoveMembersRequest() :
                PlayFabRequestCommon(),
                Group(),
                Members(),
                RoleId()
            {}

            RemoveMembersRequest(const RemoveMembersRequest& src) :
                PlayFabRequestCommon(),
                Group(src.Group),
                Members(src.Members),
                RoleId(src.RoleId)
            {}

            ~RemoveMembersRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[U("Group")], Group);
                FromJsonUtilO(input[U("Members")], Members);
                FromJsonUtilS(input[U("RoleId")], RoleId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Group; ToJsonUtilO(Group, each_Group); output[U("Group")] = each_Group;
                web::json::value each_Members; ToJsonUtilO(Members, each_Members); output[U("Members")] = each_Members;
                web::json::value each_RoleId; ToJsonUtilS(RoleId, each_RoleId); output[U("RoleId")] = each_RoleId;
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
                FromJsonUtilO(input[U("Entity")], Entity);
                FromJsonUtilO(input[U("Statements")], Statements);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Entity; ToJsonUtilO(Entity, each_Entity); output[U("Entity")] = each_Entity;
                web::json::value each_Statements; ToJsonUtilO(Statements, each_Statements); output[U("Statements")] = each_Statements;
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
                FromJsonUtilO(input[U("Permissions")], Permissions);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Permissions; ToJsonUtilO(Permissions, each_Permissions); output[U("Permissions")] = each_Permissions;
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
                FromJsonUtilO(input[U("Permissions")], Permissions);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Permissions; ToJsonUtilO(Permissions, each_Permissions); output[U("Permissions")] = each_Permissions;
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

        struct SetObject : public PlayFabBaseModel
        {
            web::json::value DataObject;
            Boxed<bool> DeleteObject;
            std::string EscapedDataObject;
            std::string ObjectName;

            SetObject() :
                PlayFabBaseModel(),
                DataObject(),
                DeleteObject(),
                EscapedDataObject(),
                ObjectName()
            {}

            SetObject(const SetObject& src) :
                PlayFabBaseModel(),
                DataObject(src.DataObject),
                DeleteObject(src.DeleteObject),
                EscapedDataObject(src.EscapedDataObject),
                ObjectName(src.ObjectName)
            {}

            ~SetObject() { }

            void FromJson(web::json::value& input) override
            {
                DataObject = input[U("DataObject")];
                FromJsonUtilP(input[U("DeleteObject")], DeleteObject);
                FromJsonUtilS(input[U("EscapedDataObject")], EscapedDataObject);
                FromJsonUtilS(input[U("ObjectName")], ObjectName);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                output[U("DataObject")] = DataObject;
                web::json::value each_DeleteObject; ToJsonUtilP(DeleteObject, each_DeleteObject); output[U("DeleteObject")] = each_DeleteObject;
                web::json::value each_EscapedDataObject; ToJsonUtilS(EscapedDataObject, each_EscapedDataObject); output[U("EscapedDataObject")] = each_EscapedDataObject;
                web::json::value each_ObjectName; ToJsonUtilS(ObjectName, each_ObjectName); output[U("ObjectName")] = each_ObjectName;
                return output;
            }
        };

        struct SetObjectInfo : public PlayFabBaseModel
        {
            std::string ObjectName;
            std::string OperationReason;
            Boxed<OperationTypes> SetResult;

            SetObjectInfo() :
                PlayFabBaseModel(),
                ObjectName(),
                OperationReason(),
                SetResult()
            {}

            SetObjectInfo(const SetObjectInfo& src) :
                PlayFabBaseModel(),
                ObjectName(src.ObjectName),
                OperationReason(src.OperationReason),
                SetResult(src.SetResult)
            {}

            ~SetObjectInfo() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("ObjectName")], ObjectName);
                FromJsonUtilS(input[U("OperationReason")], OperationReason);
                FromJsonUtilE(input[U("SetResult")], SetResult);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_ObjectName; ToJsonUtilS(ObjectName, each_ObjectName); output[U("ObjectName")] = each_ObjectName;
                web::json::value each_OperationReason; ToJsonUtilS(OperationReason, each_OperationReason); output[U("OperationReason")] = each_OperationReason;
                web::json::value each_SetResult; ToJsonUtilE(SetResult, each_SetResult); output[U("SetResult")] = each_SetResult;
                return output;
            }
        };

        struct SetObjectsRequest : public PlayFabRequestCommon
        {
            EntityKey Entity;
            Boxed<Int32> ExpectedProfileVersion;
            std::list<SetObject> Objects;

            SetObjectsRequest() :
                PlayFabRequestCommon(),
                Entity(),
                ExpectedProfileVersion(),
                Objects()
            {}

            SetObjectsRequest(const SetObjectsRequest& src) :
                PlayFabRequestCommon(),
                Entity(src.Entity),
                ExpectedProfileVersion(src.ExpectedProfileVersion),
                Objects(src.Objects)
            {}

            ~SetObjectsRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[U("Entity")], Entity);
                FromJsonUtilP(input[U("ExpectedProfileVersion")], ExpectedProfileVersion);
                FromJsonUtilO(input[U("Objects")], Objects);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Entity; ToJsonUtilO(Entity, each_Entity); output[U("Entity")] = each_Entity;
                web::json::value each_ExpectedProfileVersion; ToJsonUtilP(ExpectedProfileVersion, each_ExpectedProfileVersion); output[U("ExpectedProfileVersion")] = each_ExpectedProfileVersion;
                web::json::value each_Objects; ToJsonUtilO(Objects, each_Objects); output[U("Objects")] = each_Objects;
                return output;
            }
        };

        struct SetObjectsResponse : public PlayFabResultCommon
        {
            Int32 ProfileVersion;
            std::list<SetObjectInfo> SetResults;

            SetObjectsResponse() :
                PlayFabResultCommon(),
                ProfileVersion(),
                SetResults()
            {}

            SetObjectsResponse(const SetObjectsResponse& src) :
                PlayFabResultCommon(),
                ProfileVersion(src.ProfileVersion),
                SetResults(src.SetResults)
            {}

            ~SetObjectsResponse() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilP(input[U("ProfileVersion")], ProfileVersion);
                FromJsonUtilO(input[U("SetResults")], SetResults);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_ProfileVersion; ToJsonUtilP(ProfileVersion, each_ProfileVersion); output[U("ProfileVersion")] = each_ProfileVersion;
                web::json::value each_SetResults; ToJsonUtilO(SetResults, each_SetResults); output[U("SetResults")] = each_SetResults;
                return output;
            }
        };

        struct UnblockEntityRequest : public PlayFabRequestCommon
        {
            EntityKey Entity;
            EntityKey Group;

            UnblockEntityRequest() :
                PlayFabRequestCommon(),
                Entity(),
                Group()
            {}

            UnblockEntityRequest(const UnblockEntityRequest& src) :
                PlayFabRequestCommon(),
                Entity(src.Entity),
                Group(src.Group)
            {}

            ~UnblockEntityRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[U("Entity")], Entity);
                FromJsonUtilO(input[U("Group")], Group);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Entity; ToJsonUtilO(Entity, each_Entity); output[U("Entity")] = each_Entity;
                web::json::value each_Group; ToJsonUtilO(Group, each_Group); output[U("Group")] = each_Group;
                return output;
            }
        };

        struct UpdateGroupRequest : public PlayFabRequestCommon
        {
            std::string AdminRoleId;
            Boxed<Int32> ExpectedProfileVersion;
            EntityKey Group;
            std::string GroupName;
            std::string MemberRoleId;

            UpdateGroupRequest() :
                PlayFabRequestCommon(),
                AdminRoleId(),
                ExpectedProfileVersion(),
                Group(),
                GroupName(),
                MemberRoleId()
            {}

            UpdateGroupRequest(const UpdateGroupRequest& src) :
                PlayFabRequestCommon(),
                AdminRoleId(src.AdminRoleId),
                ExpectedProfileVersion(src.ExpectedProfileVersion),
                Group(src.Group),
                GroupName(src.GroupName),
                MemberRoleId(src.MemberRoleId)
            {}

            ~UpdateGroupRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("AdminRoleId")], AdminRoleId);
                FromJsonUtilP(input[U("ExpectedProfileVersion")], ExpectedProfileVersion);
                FromJsonUtilO(input[U("Group")], Group);
                FromJsonUtilS(input[U("GroupName")], GroupName);
                FromJsonUtilS(input[U("MemberRoleId")], MemberRoleId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_AdminRoleId; ToJsonUtilS(AdminRoleId, each_AdminRoleId); output[U("AdminRoleId")] = each_AdminRoleId;
                web::json::value each_ExpectedProfileVersion; ToJsonUtilP(ExpectedProfileVersion, each_ExpectedProfileVersion); output[U("ExpectedProfileVersion")] = each_ExpectedProfileVersion;
                web::json::value each_Group; ToJsonUtilO(Group, each_Group); output[U("Group")] = each_Group;
                web::json::value each_GroupName; ToJsonUtilS(GroupName, each_GroupName); output[U("GroupName")] = each_GroupName;
                web::json::value each_MemberRoleId; ToJsonUtilS(MemberRoleId, each_MemberRoleId); output[U("MemberRoleId")] = each_MemberRoleId;
                return output;
            }
        };

        struct UpdateGroupResponse : public PlayFabResultCommon
        {
            std::string OperationReason;
            Int32 ProfileVersion;
            Boxed<OperationTypes> SetResult;

            UpdateGroupResponse() :
                PlayFabResultCommon(),
                OperationReason(),
                ProfileVersion(),
                SetResult()
            {}

            UpdateGroupResponse(const UpdateGroupResponse& src) :
                PlayFabResultCommon(),
                OperationReason(src.OperationReason),
                ProfileVersion(src.ProfileVersion),
                SetResult(src.SetResult)
            {}

            ~UpdateGroupResponse() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("OperationReason")], OperationReason);
                FromJsonUtilP(input[U("ProfileVersion")], ProfileVersion);
                FromJsonUtilE(input[U("SetResult")], SetResult);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_OperationReason; ToJsonUtilS(OperationReason, each_OperationReason); output[U("OperationReason")] = each_OperationReason;
                web::json::value each_ProfileVersion; ToJsonUtilP(ProfileVersion, each_ProfileVersion); output[U("ProfileVersion")] = each_ProfileVersion;
                web::json::value each_SetResult; ToJsonUtilE(SetResult, each_SetResult); output[U("SetResult")] = each_SetResult;
                return output;
            }
        };

        struct UpdateGroupRoleRequest : public PlayFabRequestCommon
        {
            Boxed<Int32> ExpectedProfileVersion;
            EntityKey Group;
            std::string RoleId;
            std::string RoleName;

            UpdateGroupRoleRequest() :
                PlayFabRequestCommon(),
                ExpectedProfileVersion(),
                Group(),
                RoleId(),
                RoleName()
            {}

            UpdateGroupRoleRequest(const UpdateGroupRoleRequest& src) :
                PlayFabRequestCommon(),
                ExpectedProfileVersion(src.ExpectedProfileVersion),
                Group(src.Group),
                RoleId(src.RoleId),
                RoleName(src.RoleName)
            {}

            ~UpdateGroupRoleRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilP(input[U("ExpectedProfileVersion")], ExpectedProfileVersion);
                FromJsonUtilO(input[U("Group")], Group);
                FromJsonUtilS(input[U("RoleId")], RoleId);
                FromJsonUtilS(input[U("RoleName")], RoleName);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_ExpectedProfileVersion; ToJsonUtilP(ExpectedProfileVersion, each_ExpectedProfileVersion); output[U("ExpectedProfileVersion")] = each_ExpectedProfileVersion;
                web::json::value each_Group; ToJsonUtilO(Group, each_Group); output[U("Group")] = each_Group;
                web::json::value each_RoleId; ToJsonUtilS(RoleId, each_RoleId); output[U("RoleId")] = each_RoleId;
                web::json::value each_RoleName; ToJsonUtilS(RoleName, each_RoleName); output[U("RoleName")] = each_RoleName;
                return output;
            }
        };

        struct UpdateGroupRoleResponse : public PlayFabResultCommon
        {
            std::string OperationReason;
            Int32 ProfileVersion;
            Boxed<OperationTypes> SetResult;

            UpdateGroupRoleResponse() :
                PlayFabResultCommon(),
                OperationReason(),
                ProfileVersion(),
                SetResult()
            {}

            UpdateGroupRoleResponse(const UpdateGroupRoleResponse& src) :
                PlayFabResultCommon(),
                OperationReason(src.OperationReason),
                ProfileVersion(src.ProfileVersion),
                SetResult(src.SetResult)
            {}

            ~UpdateGroupRoleResponse() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("OperationReason")], OperationReason);
                FromJsonUtilP(input[U("ProfileVersion")], ProfileVersion);
                FromJsonUtilE(input[U("SetResult")], SetResult);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_OperationReason; ToJsonUtilS(OperationReason, each_OperationReason); output[U("OperationReason")] = each_OperationReason;
                web::json::value each_ProfileVersion; ToJsonUtilP(ProfileVersion, each_ProfileVersion); output[U("ProfileVersion")] = each_ProfileVersion;
                web::json::value each_SetResult; ToJsonUtilE(SetResult, each_SetResult); output[U("SetResult")] = each_SetResult;
                return output;
            }
        };

    }
}

#endif
