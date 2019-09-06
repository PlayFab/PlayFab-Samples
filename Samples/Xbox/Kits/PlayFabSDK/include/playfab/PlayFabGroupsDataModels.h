#pragma once

#ifdef ENABLE_PLAYFABENTITY_API

#include "playfab/PlayFabBaseModel.h"

namespace PlayFab
{
    namespace GroupsModels
    {
        // Groups Enums
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

        // Groups Classes
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
                FromJsonUtilO(input[L"Entity"], Entity);
                FromJsonUtilO(input[L"Group"], Group);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Entity; ToJsonUtilO(Entity, each_Entity); output[L"Entity"] = each_Entity;
                web::json::value each_Group; ToJsonUtilO(Group, each_Group); output[L"Group"] = each_Group;
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
                FromJsonUtilO(input[L"Entity"], Entity);
                FromJsonUtilO(input[L"Group"], Group);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Entity; ToJsonUtilO(Entity, each_Entity); output[L"Entity"] = each_Entity;
                web::json::value each_Group; ToJsonUtilO(Group, each_Group); output[L"Group"] = each_Group;
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
                FromJsonUtilO(input[L"Group"], Group);
                FromJsonUtilO(input[L"Members"], Members);
                FromJsonUtilS(input[L"RoleId"], RoleId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Group; ToJsonUtilO(Group, each_Group); output[L"Group"] = each_Group;
                web::json::value each_Members; ToJsonUtilO(Members, each_Members); output[L"Members"] = each_Members;
                web::json::value each_RoleId; ToJsonUtilS(RoleId, each_RoleId); output[L"RoleId"] = each_RoleId;
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
                FromJsonUtilP(input[L"AutoAcceptOutstandingInvite"], AutoAcceptOutstandingInvite);
                FromJsonUtilO(input[L"Entity"], Entity);
                FromJsonUtilO(input[L"Group"], Group);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_AutoAcceptOutstandingInvite; ToJsonUtilP(AutoAcceptOutstandingInvite, each_AutoAcceptOutstandingInvite); output[L"AutoAcceptOutstandingInvite"] = each_AutoAcceptOutstandingInvite;
                web::json::value each_Entity; ToJsonUtilO(Entity, each_Entity); output[L"Entity"] = each_Entity;
                web::json::value each_Group; ToJsonUtilO(Group, each_Group); output[L"Group"] = each_Group;
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
                FromJsonUtilO(input[L"Key"], Key);
                FromJsonUtilO(input[L"Lineage"], Lineage);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Key; ToJsonUtilO(Key, each_Key); output[L"Key"] = each_Key;
                web::json::value each_Lineage; ToJsonUtilO(Lineage, each_Lineage); output[L"Lineage"] = each_Lineage;
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
                FromJsonUtilO(input[L"Entity"], Entity);
                FromJsonUtilT(input[L"Expires"], Expires);
                FromJsonUtilO(input[L"Group"], Group);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Entity; ToJsonUtilO(Entity, each_Entity); output[L"Entity"] = each_Entity;
                web::json::value each_Expires; ToJsonUtilT(Expires, each_Expires); output[L"Expires"] = each_Expires;
                web::json::value each_Group; ToJsonUtilO(Group, each_Group); output[L"Group"] = each_Group;
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
                FromJsonUtilO(input[L"Entity"], Entity);
                FromJsonUtilO(input[L"Group"], Group);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Entity; ToJsonUtilO(Entity, each_Entity); output[L"Entity"] = each_Entity;
                web::json::value each_Group; ToJsonUtilO(Group, each_Group); output[L"Group"] = each_Group;
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
                FromJsonUtilS(input[L"DestinationRoleId"], DestinationRoleId);
                FromJsonUtilO(input[L"Group"], Group);
                FromJsonUtilO(input[L"Members"], Members);
                FromJsonUtilS(input[L"OriginRoleId"], OriginRoleId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_DestinationRoleId; ToJsonUtilS(DestinationRoleId, each_DestinationRoleId); output[L"DestinationRoleId"] = each_DestinationRoleId;
                web::json::value each_Group; ToJsonUtilO(Group, each_Group); output[L"Group"] = each_Group;
                web::json::value each_Members; ToJsonUtilO(Members, each_Members); output[L"Members"] = each_Members;
                web::json::value each_OriginRoleId; ToJsonUtilS(OriginRoleId, each_OriginRoleId); output[L"OriginRoleId"] = each_OriginRoleId;
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
                FromJsonUtilO(input[L"Entity"], Entity);
                FromJsonUtilS(input[L"GroupName"], GroupName);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Entity; ToJsonUtilO(Entity, each_Entity); output[L"Entity"] = each_Entity;
                web::json::value each_GroupName; ToJsonUtilS(GroupName, each_GroupName); output[L"GroupName"] = each_GroupName;
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
                FromJsonUtilS(input[L"AdminRoleId"], AdminRoleId);
                FromJsonUtilT(input[L"Created"], Created);
                FromJsonUtilO(input[L"Group"], Group);
                FromJsonUtilS(input[L"GroupName"], GroupName);
                FromJsonUtilS(input[L"MemberRoleId"], MemberRoleId);
                FromJsonUtilP(input[L"ProfileVersion"], ProfileVersion);
                FromJsonUtilS(input[L"Roles"], Roles);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_AdminRoleId; ToJsonUtilS(AdminRoleId, each_AdminRoleId); output[L"AdminRoleId"] = each_AdminRoleId;
                web::json::value each_Created; ToJsonUtilT(Created, each_Created); output[L"Created"] = each_Created;
                web::json::value each_Group; ToJsonUtilO(Group, each_Group); output[L"Group"] = each_Group;
                web::json::value each_GroupName; ToJsonUtilS(GroupName, each_GroupName); output[L"GroupName"] = each_GroupName;
                web::json::value each_MemberRoleId; ToJsonUtilS(MemberRoleId, each_MemberRoleId); output[L"MemberRoleId"] = each_MemberRoleId;
                web::json::value each_ProfileVersion; ToJsonUtilP(ProfileVersion, each_ProfileVersion); output[L"ProfileVersion"] = each_ProfileVersion;
                web::json::value each_Roles; ToJsonUtilS(Roles, each_Roles); output[L"Roles"] = each_Roles;
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
                FromJsonUtilO(input[L"Group"], Group);
                FromJsonUtilS(input[L"RoleId"], RoleId);
                FromJsonUtilS(input[L"RoleName"], RoleName);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Group; ToJsonUtilO(Group, each_Group); output[L"Group"] = each_Group;
                web::json::value each_RoleId; ToJsonUtilS(RoleId, each_RoleId); output[L"RoleId"] = each_RoleId;
                web::json::value each_RoleName; ToJsonUtilS(RoleName, each_RoleName); output[L"RoleName"] = each_RoleName;
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
                FromJsonUtilP(input[L"ProfileVersion"], ProfileVersion);
                FromJsonUtilS(input[L"RoleId"], RoleId);
                FromJsonUtilS(input[L"RoleName"], RoleName);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_ProfileVersion; ToJsonUtilP(ProfileVersion, each_ProfileVersion); output[L"ProfileVersion"] = each_ProfileVersion;
                web::json::value each_RoleId; ToJsonUtilS(RoleId, each_RoleId); output[L"RoleId"] = each_RoleId;
                web::json::value each_RoleName; ToJsonUtilS(RoleName, each_RoleName); output[L"RoleName"] = each_RoleName;
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
                FromJsonUtilO(input[L"Group"], Group);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Group; ToJsonUtilO(Group, each_Group); output[L"Group"] = each_Group;
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
                FromJsonUtilO(input[L"Group"], Group);
                FromJsonUtilS(input[L"RoleId"], RoleId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Group; ToJsonUtilO(Group, each_Group); output[L"Group"] = each_Group;
                web::json::value each_RoleId; ToJsonUtilS(RoleId, each_RoleId); output[L"RoleId"] = each_RoleId;
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
                FromJsonUtilO(input[L"Members"], Members);
                FromJsonUtilS(input[L"RoleId"], RoleId);
                FromJsonUtilS(input[L"RoleName"], RoleName);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Members; ToJsonUtilO(Members, each_Members); output[L"Members"] = each_Members;
                web::json::value each_RoleId; ToJsonUtilS(RoleId, each_RoleId); output[L"RoleId"] = each_RoleId;
                web::json::value each_RoleName; ToJsonUtilS(RoleName, each_RoleName); output[L"RoleName"] = each_RoleName;
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
                FromJsonUtilO(input[L"Group"], Group);
                FromJsonUtilS(input[L"GroupName"], GroupName);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Group; ToJsonUtilO(Group, each_Group); output[L"Group"] = each_Group;
                web::json::value each_GroupName; ToJsonUtilS(GroupName, each_GroupName); output[L"GroupName"] = each_GroupName;
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
                FromJsonUtilS(input[L"AdminRoleId"], AdminRoleId);
                FromJsonUtilT(input[L"Created"], Created);
                FromJsonUtilO(input[L"Group"], Group);
                FromJsonUtilS(input[L"GroupName"], GroupName);
                FromJsonUtilS(input[L"MemberRoleId"], MemberRoleId);
                FromJsonUtilP(input[L"ProfileVersion"], ProfileVersion);
                FromJsonUtilS(input[L"Roles"], Roles);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_AdminRoleId; ToJsonUtilS(AdminRoleId, each_AdminRoleId); output[L"AdminRoleId"] = each_AdminRoleId;
                web::json::value each_Created; ToJsonUtilT(Created, each_Created); output[L"Created"] = each_Created;
                web::json::value each_Group; ToJsonUtilO(Group, each_Group); output[L"Group"] = each_Group;
                web::json::value each_GroupName; ToJsonUtilS(GroupName, each_GroupName); output[L"GroupName"] = each_GroupName;
                web::json::value each_MemberRoleId; ToJsonUtilS(MemberRoleId, each_MemberRoleId); output[L"MemberRoleId"] = each_MemberRoleId;
                web::json::value each_ProfileVersion; ToJsonUtilP(ProfileVersion, each_ProfileVersion); output[L"ProfileVersion"] = each_ProfileVersion;
                web::json::value each_Roles; ToJsonUtilS(Roles, each_Roles); output[L"Roles"] = each_Roles;
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
                FromJsonUtilO(input[L"Entity"], Entity);
                FromJsonUtilT(input[L"Expires"], Expires);
                FromJsonUtilO(input[L"Group"], Group);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Entity; ToJsonUtilO(Entity, each_Entity); output[L"Entity"] = each_Entity;
                web::json::value each_Expires; ToJsonUtilT(Expires, each_Expires); output[L"Expires"] = each_Expires;
                web::json::value each_Group; ToJsonUtilO(Group, each_Group); output[L"Group"] = each_Group;
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
                FromJsonUtilO(input[L"Entity"], Entity);
                FromJsonUtilO(input[L"Group"], Group);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Entity; ToJsonUtilO(Entity, each_Entity); output[L"Entity"] = each_Entity;
                web::json::value each_Group; ToJsonUtilO(Group, each_Group); output[L"Group"] = each_Group;
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
                FromJsonUtilT(input[L"Expires"], Expires);
                FromJsonUtilO(input[L"Group"], Group);
                FromJsonUtilO(input[L"InvitedByEntity"], InvitedByEntity);
                FromJsonUtilO(input[L"InvitedEntity"], InvitedEntity);
                FromJsonUtilS(input[L"RoleId"], RoleId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Expires; ToJsonUtilT(Expires, each_Expires); output[L"Expires"] = each_Expires;
                web::json::value each_Group; ToJsonUtilO(Group, each_Group); output[L"Group"] = each_Group;
                web::json::value each_InvitedByEntity; ToJsonUtilO(InvitedByEntity, each_InvitedByEntity); output[L"InvitedByEntity"] = each_InvitedByEntity;
                web::json::value each_InvitedEntity; ToJsonUtilO(InvitedEntity, each_InvitedEntity); output[L"InvitedEntity"] = each_InvitedEntity;
                web::json::value each_RoleId; ToJsonUtilS(RoleId, each_RoleId); output[L"RoleId"] = each_RoleId;
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
                FromJsonUtilS(input[L"RoleId"], RoleId);
                FromJsonUtilS(input[L"RoleName"], RoleName);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_RoleId; ToJsonUtilS(RoleId, each_RoleId); output[L"RoleId"] = each_RoleId;
                web::json::value each_RoleName; ToJsonUtilS(RoleName, each_RoleName); output[L"RoleName"] = each_RoleName;
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
                FromJsonUtilO(input[L"Group"], Group);
                FromJsonUtilS(input[L"GroupName"], GroupName);
                FromJsonUtilP(input[L"ProfileVersion"], ProfileVersion);
                FromJsonUtilO(input[L"Roles"], Roles);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Group; ToJsonUtilO(Group, each_Group); output[L"Group"] = each_Group;
                web::json::value each_GroupName; ToJsonUtilS(GroupName, each_GroupName); output[L"GroupName"] = each_GroupName;
                web::json::value each_ProfileVersion; ToJsonUtilP(ProfileVersion, each_ProfileVersion); output[L"ProfileVersion"] = each_ProfileVersion;
                web::json::value each_Roles; ToJsonUtilO(Roles, each_Roles); output[L"Roles"] = each_Roles;
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
                FromJsonUtilP(input[L"AutoAcceptOutstandingApplication"], AutoAcceptOutstandingApplication);
                FromJsonUtilO(input[L"Entity"], Entity);
                FromJsonUtilO(input[L"Group"], Group);
                FromJsonUtilS(input[L"RoleId"], RoleId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_AutoAcceptOutstandingApplication; ToJsonUtilP(AutoAcceptOutstandingApplication, each_AutoAcceptOutstandingApplication); output[L"AutoAcceptOutstandingApplication"] = each_AutoAcceptOutstandingApplication;
                web::json::value each_Entity; ToJsonUtilO(Entity, each_Entity); output[L"Entity"] = each_Entity;
                web::json::value each_Group; ToJsonUtilO(Group, each_Group); output[L"Group"] = each_Group;
                web::json::value each_RoleId; ToJsonUtilS(RoleId, each_RoleId); output[L"RoleId"] = each_RoleId;
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
                FromJsonUtilT(input[L"Expires"], Expires);
                FromJsonUtilO(input[L"Group"], Group);
                FromJsonUtilO(input[L"InvitedByEntity"], InvitedByEntity);
                FromJsonUtilO(input[L"InvitedEntity"], InvitedEntity);
                FromJsonUtilS(input[L"RoleId"], RoleId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Expires; ToJsonUtilT(Expires, each_Expires); output[L"Expires"] = each_Expires;
                web::json::value each_Group; ToJsonUtilO(Group, each_Group); output[L"Group"] = each_Group;
                web::json::value each_InvitedByEntity; ToJsonUtilO(InvitedByEntity, each_InvitedByEntity); output[L"InvitedByEntity"] = each_InvitedByEntity;
                web::json::value each_InvitedEntity; ToJsonUtilO(InvitedEntity, each_InvitedEntity); output[L"InvitedEntity"] = each_InvitedEntity;
                web::json::value each_RoleId; ToJsonUtilS(RoleId, each_RoleId); output[L"RoleId"] = each_RoleId;
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
                FromJsonUtilO(input[L"Entity"], Entity);
                FromJsonUtilO(input[L"Group"], Group);
                FromJsonUtilS(input[L"RoleId"], RoleId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Entity; ToJsonUtilO(Entity, each_Entity); output[L"Entity"] = each_Entity;
                web::json::value each_Group; ToJsonUtilO(Group, each_Group); output[L"Group"] = each_Group;
                web::json::value each_RoleId; ToJsonUtilS(RoleId, each_RoleId); output[L"RoleId"] = each_RoleId;
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
                FromJsonUtilP(input[L"IsMember"], IsMember);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_IsMember; ToJsonUtilP(IsMember, each_IsMember); output[L"IsMember"] = each_IsMember;
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
                FromJsonUtilO(input[L"Group"], Group);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Group; ToJsonUtilO(Group, each_Group); output[L"Group"] = each_Group;
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
                FromJsonUtilO(input[L"Applications"], Applications);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Applications; ToJsonUtilO(Applications, each_Applications); output[L"Applications"] = each_Applications;
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
                FromJsonUtilO(input[L"Group"], Group);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Group; ToJsonUtilO(Group, each_Group); output[L"Group"] = each_Group;
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
                FromJsonUtilO(input[L"BlockedEntities"], BlockedEntities);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_BlockedEntities; ToJsonUtilO(BlockedEntities, each_BlockedEntities); output[L"BlockedEntities"] = each_BlockedEntities;
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
                FromJsonUtilO(input[L"Group"], Group);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Group; ToJsonUtilO(Group, each_Group); output[L"Group"] = each_Group;
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
                FromJsonUtilO(input[L"Invitations"], Invitations);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Invitations; ToJsonUtilO(Invitations, each_Invitations); output[L"Invitations"] = each_Invitations;
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
                FromJsonUtilO(input[L"Group"], Group);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Group; ToJsonUtilO(Group, each_Group); output[L"Group"] = each_Group;
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
                FromJsonUtilO(input[L"Members"], Members);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Members; ToJsonUtilO(Members, each_Members); output[L"Members"] = each_Members;
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
                FromJsonUtilO(input[L"Entity"], Entity);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Entity; ToJsonUtilO(Entity, each_Entity); output[L"Entity"] = each_Entity;
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
                FromJsonUtilO(input[L"Applications"], Applications);
                FromJsonUtilO(input[L"Invitations"], Invitations);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Applications; ToJsonUtilO(Applications, each_Applications); output[L"Applications"] = each_Applications;
                web::json::value each_Invitations; ToJsonUtilO(Invitations, each_Invitations); output[L"Invitations"] = each_Invitations;
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
                FromJsonUtilO(input[L"Entity"], Entity);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Entity; ToJsonUtilO(Entity, each_Entity); output[L"Entity"] = each_Entity;
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
                FromJsonUtilO(input[L"Groups"], Groups);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Groups; ToJsonUtilO(Groups, each_Groups); output[L"Groups"] = each_Groups;
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
                FromJsonUtilO(input[L"Entity"], Entity);
                FromJsonUtilO(input[L"Group"], Group);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Entity; ToJsonUtilO(Entity, each_Entity); output[L"Entity"] = each_Entity;
                web::json::value each_Group; ToJsonUtilO(Group, each_Group); output[L"Group"] = each_Group;
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
                FromJsonUtilO(input[L"Entity"], Entity);
                FromJsonUtilO(input[L"Group"], Group);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Entity; ToJsonUtilO(Entity, each_Entity); output[L"Entity"] = each_Entity;
                web::json::value each_Group; ToJsonUtilO(Group, each_Group); output[L"Group"] = each_Group;
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
                FromJsonUtilO(input[L"Group"], Group);
                FromJsonUtilO(input[L"Members"], Members);
                FromJsonUtilS(input[L"RoleId"], RoleId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Group; ToJsonUtilO(Group, each_Group); output[L"Group"] = each_Group;
                web::json::value each_Members; ToJsonUtilO(Members, each_Members); output[L"Members"] = each_Members;
                web::json::value each_RoleId; ToJsonUtilS(RoleId, each_RoleId); output[L"RoleId"] = each_RoleId;
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
                FromJsonUtilO(input[L"Entity"], Entity);
                FromJsonUtilO(input[L"Group"], Group);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Entity; ToJsonUtilO(Entity, each_Entity); output[L"Entity"] = each_Entity;
                web::json::value each_Group; ToJsonUtilO(Group, each_Group); output[L"Group"] = each_Group;
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
                FromJsonUtilS(input[L"AdminRoleId"], AdminRoleId);
                FromJsonUtilP(input[L"ExpectedProfileVersion"], ExpectedProfileVersion);
                FromJsonUtilO(input[L"Group"], Group);
                FromJsonUtilS(input[L"GroupName"], GroupName);
                FromJsonUtilS(input[L"MemberRoleId"], MemberRoleId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_AdminRoleId; ToJsonUtilS(AdminRoleId, each_AdminRoleId); output[L"AdminRoleId"] = each_AdminRoleId;
                web::json::value each_ExpectedProfileVersion; ToJsonUtilP(ExpectedProfileVersion, each_ExpectedProfileVersion); output[L"ExpectedProfileVersion"] = each_ExpectedProfileVersion;
                web::json::value each_Group; ToJsonUtilO(Group, each_Group); output[L"Group"] = each_Group;
                web::json::value each_GroupName; ToJsonUtilS(GroupName, each_GroupName); output[L"GroupName"] = each_GroupName;
                web::json::value each_MemberRoleId; ToJsonUtilS(MemberRoleId, each_MemberRoleId); output[L"MemberRoleId"] = each_MemberRoleId;
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
                FromJsonUtilS(input[L"OperationReason"], OperationReason);
                FromJsonUtilP(input[L"ProfileVersion"], ProfileVersion);
                FromJsonUtilE(input[L"SetResult"], SetResult);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_OperationReason; ToJsonUtilS(OperationReason, each_OperationReason); output[L"OperationReason"] = each_OperationReason;
                web::json::value each_ProfileVersion; ToJsonUtilP(ProfileVersion, each_ProfileVersion); output[L"ProfileVersion"] = each_ProfileVersion;
                web::json::value each_SetResult; ToJsonUtilE(SetResult, each_SetResult); output[L"SetResult"] = each_SetResult;
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
                FromJsonUtilP(input[L"ExpectedProfileVersion"], ExpectedProfileVersion);
                FromJsonUtilO(input[L"Group"], Group);
                FromJsonUtilS(input[L"RoleId"], RoleId);
                FromJsonUtilS(input[L"RoleName"], RoleName);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_ExpectedProfileVersion; ToJsonUtilP(ExpectedProfileVersion, each_ExpectedProfileVersion); output[L"ExpectedProfileVersion"] = each_ExpectedProfileVersion;
                web::json::value each_Group; ToJsonUtilO(Group, each_Group); output[L"Group"] = each_Group;
                web::json::value each_RoleId; ToJsonUtilS(RoleId, each_RoleId); output[L"RoleId"] = each_RoleId;
                web::json::value each_RoleName; ToJsonUtilS(RoleName, each_RoleName); output[L"RoleName"] = each_RoleName;
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
                FromJsonUtilS(input[L"OperationReason"], OperationReason);
                FromJsonUtilP(input[L"ProfileVersion"], ProfileVersion);
                FromJsonUtilE(input[L"SetResult"], SetResult);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_OperationReason; ToJsonUtilS(OperationReason, each_OperationReason); output[L"OperationReason"] = each_OperationReason;
                web::json::value each_ProfileVersion; ToJsonUtilP(ProfileVersion, each_ProfileVersion); output[L"ProfileVersion"] = each_ProfileVersion;
                web::json::value each_SetResult; ToJsonUtilE(SetResult, each_SetResult); output[L"SetResult"] = each_SetResult;
                return output;
            }
        };

    }
}

#endif
