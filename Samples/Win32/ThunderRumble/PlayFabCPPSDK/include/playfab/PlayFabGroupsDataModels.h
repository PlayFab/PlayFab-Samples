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
    namespace GroupsModels
    {
        // Groups Enums
        enum OperationTypes
        {
            OperationTypesCreated,
            OperationTypesUpdated,
            OperationTypesDeleted,
            OperationTypesNone
        };

        inline void ToJsonEnum(const OperationTypes input, Json::Value& output)
        {
            if (input == OperationTypesCreated) output = Json::Value("Created");
            if (input == OperationTypesUpdated) output = Json::Value("Updated");
            if (input == OperationTypesDeleted) output = Json::Value("Deleted");
            if (input == OperationTypesNone) output = Json::Value("None");
        }
        inline void FromJsonEnum(const Json::Value& input, OperationTypes& output)
        {
            if (!input.isString()) return;
            const std::string& inputStr = input.asString();
            if (inputStr == "Created") output = OperationTypesCreated;
            if (inputStr == "Updated") output = OperationTypesUpdated;
            if (inputStr == "Deleted") output = OperationTypesDeleted;
            if (inputStr == "None") output = OperationTypesNone;
        }

        // Groups Classes
        struct EntityKey : public PlayFabBaseModel
        {
            std::string Id;
            std::string Type;

            EntityKey() :
                PlayFabBaseModel(),
                Id(),
                Type()
            {}

            EntityKey(const EntityKey& src) :
                PlayFabBaseModel(),
                Id(src.Id),
                Type(src.Type)
            {}

            ~EntityKey() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["Id"], Id);
                FromJsonUtilS(input["Type"], Type);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Id; ToJsonUtilS(Id, each_Id); output["Id"] = each_Id;
                Json::Value each_Type; ToJsonUtilS(Type, each_Type); output["Type"] = each_Type;
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

            ~AcceptGroupApplicationRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Entity"], Entity);
                FromJsonUtilO(input["Group"], Group);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                Json::Value each_Group; ToJsonUtilO(Group, each_Group); output["Group"] = each_Group;
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

            ~AcceptGroupInvitationRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Entity"], Entity);
                FromJsonUtilO(input["Group"], Group);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                Json::Value each_Group; ToJsonUtilO(Group, each_Group); output["Group"] = each_Group;
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

            ~AddMembersRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Group"], Group);
                FromJsonUtilO(input["Members"], Members);
                FromJsonUtilS(input["RoleId"], RoleId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Group; ToJsonUtilO(Group, each_Group); output["Group"] = each_Group;
                Json::Value each_Members; ToJsonUtilO(Members, each_Members); output["Members"] = each_Members;
                Json::Value each_RoleId; ToJsonUtilS(RoleId, each_RoleId); output["RoleId"] = each_RoleId;
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

            ~ApplyToGroupRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilP(input["AutoAcceptOutstandingInvite"], AutoAcceptOutstandingInvite);
                FromJsonUtilO(input["Entity"], Entity);
                FromJsonUtilO(input["Group"], Group);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_AutoAcceptOutstandingInvite; ToJsonUtilP(AutoAcceptOutstandingInvite, each_AutoAcceptOutstandingInvite); output["AutoAcceptOutstandingInvite"] = each_AutoAcceptOutstandingInvite;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                Json::Value each_Group; ToJsonUtilO(Group, each_Group); output["Group"] = each_Group;
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

            ~EntityWithLineage() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Key"], Key);
                FromJsonUtilO(input["Lineage"], Lineage);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Key; ToJsonUtilO(Key, each_Key); output["Key"] = each_Key;
                Json::Value each_Lineage; ToJsonUtilO(Lineage, each_Lineage); output["Lineage"] = each_Lineage;
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

            ~ApplyToGroupResponse() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Entity"], Entity);
                FromJsonUtilT(input["Expires"], Expires);
                FromJsonUtilO(input["Group"], Group);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                Json::Value each_Expires; ToJsonUtilT(Expires, each_Expires); output["Expires"] = each_Expires;
                Json::Value each_Group; ToJsonUtilO(Group, each_Group); output["Group"] = each_Group;
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

            ~BlockEntityRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Entity"], Entity);
                FromJsonUtilO(input["Group"], Group);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                Json::Value each_Group; ToJsonUtilO(Group, each_Group); output["Group"] = each_Group;
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

            ~ChangeMemberRoleRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["DestinationRoleId"], DestinationRoleId);
                FromJsonUtilO(input["Group"], Group);
                FromJsonUtilO(input["Members"], Members);
                FromJsonUtilS(input["OriginRoleId"], OriginRoleId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_DestinationRoleId; ToJsonUtilS(DestinationRoleId, each_DestinationRoleId); output["DestinationRoleId"] = each_DestinationRoleId;
                Json::Value each_Group; ToJsonUtilO(Group, each_Group); output["Group"] = each_Group;
                Json::Value each_Members; ToJsonUtilO(Members, each_Members); output["Members"] = each_Members;
                Json::Value each_OriginRoleId; ToJsonUtilS(OriginRoleId, each_OriginRoleId); output["OriginRoleId"] = each_OriginRoleId;
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

            ~CreateGroupRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Entity"], Entity);
                FromJsonUtilS(input["GroupName"], GroupName);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                Json::Value each_GroupName; ToJsonUtilS(GroupName, each_GroupName); output["GroupName"] = each_GroupName;
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

            ~CreateGroupResponse() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["AdminRoleId"], AdminRoleId);
                FromJsonUtilT(input["Created"], Created);
                FromJsonUtilO(input["Group"], Group);
                FromJsonUtilS(input["GroupName"], GroupName);
                FromJsonUtilS(input["MemberRoleId"], MemberRoleId);
                FromJsonUtilP(input["ProfileVersion"], ProfileVersion);
                FromJsonUtilS(input["Roles"], Roles);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_AdminRoleId; ToJsonUtilS(AdminRoleId, each_AdminRoleId); output["AdminRoleId"] = each_AdminRoleId;
                Json::Value each_Created; ToJsonUtilT(Created, each_Created); output["Created"] = each_Created;
                Json::Value each_Group; ToJsonUtilO(Group, each_Group); output["Group"] = each_Group;
                Json::Value each_GroupName; ToJsonUtilS(GroupName, each_GroupName); output["GroupName"] = each_GroupName;
                Json::Value each_MemberRoleId; ToJsonUtilS(MemberRoleId, each_MemberRoleId); output["MemberRoleId"] = each_MemberRoleId;
                Json::Value each_ProfileVersion; ToJsonUtilP(ProfileVersion, each_ProfileVersion); output["ProfileVersion"] = each_ProfileVersion;
                Json::Value each_Roles; ToJsonUtilS(Roles, each_Roles); output["Roles"] = each_Roles;
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

            ~CreateGroupRoleRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Group"], Group);
                FromJsonUtilS(input["RoleId"], RoleId);
                FromJsonUtilS(input["RoleName"], RoleName);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Group; ToJsonUtilO(Group, each_Group); output["Group"] = each_Group;
                Json::Value each_RoleId; ToJsonUtilS(RoleId, each_RoleId); output["RoleId"] = each_RoleId;
                Json::Value each_RoleName; ToJsonUtilS(RoleName, each_RoleName); output["RoleName"] = each_RoleName;
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

            ~CreateGroupRoleResponse() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilP(input["ProfileVersion"], ProfileVersion);
                FromJsonUtilS(input["RoleId"], RoleId);
                FromJsonUtilS(input["RoleName"], RoleName);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_ProfileVersion; ToJsonUtilP(ProfileVersion, each_ProfileVersion); output["ProfileVersion"] = each_ProfileVersion;
                Json::Value each_RoleId; ToJsonUtilS(RoleId, each_RoleId); output["RoleId"] = each_RoleId;
                Json::Value each_RoleName; ToJsonUtilS(RoleName, each_RoleName); output["RoleName"] = each_RoleName;
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

            ~DeleteGroupRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Group"], Group);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Group; ToJsonUtilO(Group, each_Group); output["Group"] = each_Group;
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

            ~DeleteRoleRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Group"], Group);
                FromJsonUtilS(input["RoleId"], RoleId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Group; ToJsonUtilO(Group, each_Group); output["Group"] = each_Group;
                Json::Value each_RoleId; ToJsonUtilS(RoleId, each_RoleId); output["RoleId"] = each_RoleId;
                return output;
            }
        };

        struct EmptyResponse : public PlayFabResultCommon
        {

            EmptyResponse() :
                PlayFabResultCommon()
            {}

            EmptyResponse(const EmptyResponse&) :
                PlayFabResultCommon()
            {}

            ~EmptyResponse() = default;

            void FromJson(Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
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

            ~EntityMemberRole() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Members"], Members);
                FromJsonUtilS(input["RoleId"], RoleId);
                FromJsonUtilS(input["RoleName"], RoleName);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Members; ToJsonUtilO(Members, each_Members); output["Members"] = each_Members;
                Json::Value each_RoleId; ToJsonUtilS(RoleId, each_RoleId); output["RoleId"] = each_RoleId;
                Json::Value each_RoleName; ToJsonUtilS(RoleName, each_RoleName); output["RoleName"] = each_RoleName;
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

            ~GetGroupRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Group"], Group);
                FromJsonUtilS(input["GroupName"], GroupName);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Group; ToJsonUtilO(Group, each_Group); output["Group"] = each_Group;
                Json::Value each_GroupName; ToJsonUtilS(GroupName, each_GroupName); output["GroupName"] = each_GroupName;
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

            ~GetGroupResponse() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["AdminRoleId"], AdminRoleId);
                FromJsonUtilT(input["Created"], Created);
                FromJsonUtilO(input["Group"], Group);
                FromJsonUtilS(input["GroupName"], GroupName);
                FromJsonUtilS(input["MemberRoleId"], MemberRoleId);
                FromJsonUtilP(input["ProfileVersion"], ProfileVersion);
                FromJsonUtilS(input["Roles"], Roles);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_AdminRoleId; ToJsonUtilS(AdminRoleId, each_AdminRoleId); output["AdminRoleId"] = each_AdminRoleId;
                Json::Value each_Created; ToJsonUtilT(Created, each_Created); output["Created"] = each_Created;
                Json::Value each_Group; ToJsonUtilO(Group, each_Group); output["Group"] = each_Group;
                Json::Value each_GroupName; ToJsonUtilS(GroupName, each_GroupName); output["GroupName"] = each_GroupName;
                Json::Value each_MemberRoleId; ToJsonUtilS(MemberRoleId, each_MemberRoleId); output["MemberRoleId"] = each_MemberRoleId;
                Json::Value each_ProfileVersion; ToJsonUtilP(ProfileVersion, each_ProfileVersion); output["ProfileVersion"] = each_ProfileVersion;
                Json::Value each_Roles; ToJsonUtilS(Roles, each_Roles); output["Roles"] = each_Roles;
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

            ~GroupApplication() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Entity"], Entity);
                FromJsonUtilT(input["Expires"], Expires);
                FromJsonUtilO(input["Group"], Group);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                Json::Value each_Expires; ToJsonUtilT(Expires, each_Expires); output["Expires"] = each_Expires;
                Json::Value each_Group; ToJsonUtilO(Group, each_Group); output["Group"] = each_Group;
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

            ~GroupBlock() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Entity"], Entity);
                FromJsonUtilO(input["Group"], Group);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                Json::Value each_Group; ToJsonUtilO(Group, each_Group); output["Group"] = each_Group;
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

            ~GroupInvitation() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilT(input["Expires"], Expires);
                FromJsonUtilO(input["Group"], Group);
                FromJsonUtilO(input["InvitedByEntity"], InvitedByEntity);
                FromJsonUtilO(input["InvitedEntity"], InvitedEntity);
                FromJsonUtilS(input["RoleId"], RoleId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Expires; ToJsonUtilT(Expires, each_Expires); output["Expires"] = each_Expires;
                Json::Value each_Group; ToJsonUtilO(Group, each_Group); output["Group"] = each_Group;
                Json::Value each_InvitedByEntity; ToJsonUtilO(InvitedByEntity, each_InvitedByEntity); output["InvitedByEntity"] = each_InvitedByEntity;
                Json::Value each_InvitedEntity; ToJsonUtilO(InvitedEntity, each_InvitedEntity); output["InvitedEntity"] = each_InvitedEntity;
                Json::Value each_RoleId; ToJsonUtilS(RoleId, each_RoleId); output["RoleId"] = each_RoleId;
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

            ~GroupRole() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["RoleId"], RoleId);
                FromJsonUtilS(input["RoleName"], RoleName);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_RoleId; ToJsonUtilS(RoleId, each_RoleId); output["RoleId"] = each_RoleId;
                Json::Value each_RoleName; ToJsonUtilS(RoleName, each_RoleName); output["RoleName"] = each_RoleName;
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

            ~GroupWithRoles() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Group"], Group);
                FromJsonUtilS(input["GroupName"], GroupName);
                FromJsonUtilP(input["ProfileVersion"], ProfileVersion);
                FromJsonUtilO(input["Roles"], Roles);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Group; ToJsonUtilO(Group, each_Group); output["Group"] = each_Group;
                Json::Value each_GroupName; ToJsonUtilS(GroupName, each_GroupName); output["GroupName"] = each_GroupName;
                Json::Value each_ProfileVersion; ToJsonUtilP(ProfileVersion, each_ProfileVersion); output["ProfileVersion"] = each_ProfileVersion;
                Json::Value each_Roles; ToJsonUtilO(Roles, each_Roles); output["Roles"] = each_Roles;
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

            ~InviteToGroupRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilP(input["AutoAcceptOutstandingApplication"], AutoAcceptOutstandingApplication);
                FromJsonUtilO(input["Entity"], Entity);
                FromJsonUtilO(input["Group"], Group);
                FromJsonUtilS(input["RoleId"], RoleId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_AutoAcceptOutstandingApplication; ToJsonUtilP(AutoAcceptOutstandingApplication, each_AutoAcceptOutstandingApplication); output["AutoAcceptOutstandingApplication"] = each_AutoAcceptOutstandingApplication;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                Json::Value each_Group; ToJsonUtilO(Group, each_Group); output["Group"] = each_Group;
                Json::Value each_RoleId; ToJsonUtilS(RoleId, each_RoleId); output["RoleId"] = each_RoleId;
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

            ~InviteToGroupResponse() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilT(input["Expires"], Expires);
                FromJsonUtilO(input["Group"], Group);
                FromJsonUtilO(input["InvitedByEntity"], InvitedByEntity);
                FromJsonUtilO(input["InvitedEntity"], InvitedEntity);
                FromJsonUtilS(input["RoleId"], RoleId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Expires; ToJsonUtilT(Expires, each_Expires); output["Expires"] = each_Expires;
                Json::Value each_Group; ToJsonUtilO(Group, each_Group); output["Group"] = each_Group;
                Json::Value each_InvitedByEntity; ToJsonUtilO(InvitedByEntity, each_InvitedByEntity); output["InvitedByEntity"] = each_InvitedByEntity;
                Json::Value each_InvitedEntity; ToJsonUtilO(InvitedEntity, each_InvitedEntity); output["InvitedEntity"] = each_InvitedEntity;
                Json::Value each_RoleId; ToJsonUtilS(RoleId, each_RoleId); output["RoleId"] = each_RoleId;
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

            ~IsMemberRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Entity"], Entity);
                FromJsonUtilO(input["Group"], Group);
                FromJsonUtilS(input["RoleId"], RoleId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                Json::Value each_Group; ToJsonUtilO(Group, each_Group); output["Group"] = each_Group;
                Json::Value each_RoleId; ToJsonUtilS(RoleId, each_RoleId); output["RoleId"] = each_RoleId;
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

            ~IsMemberResponse() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilP(input["IsMember"], IsMember);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_IsMember; ToJsonUtilP(IsMember, each_IsMember); output["IsMember"] = each_IsMember;
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

            ~ListGroupApplicationsRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Group"], Group);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Group; ToJsonUtilO(Group, each_Group); output["Group"] = each_Group;
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

            ~ListGroupApplicationsResponse() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Applications"], Applications);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Applications; ToJsonUtilO(Applications, each_Applications); output["Applications"] = each_Applications;
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

            ~ListGroupBlocksRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Group"], Group);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Group; ToJsonUtilO(Group, each_Group); output["Group"] = each_Group;
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

            ~ListGroupBlocksResponse() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["BlockedEntities"], BlockedEntities);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_BlockedEntities; ToJsonUtilO(BlockedEntities, each_BlockedEntities); output["BlockedEntities"] = each_BlockedEntities;
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

            ~ListGroupInvitationsRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Group"], Group);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Group; ToJsonUtilO(Group, each_Group); output["Group"] = each_Group;
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

            ~ListGroupInvitationsResponse() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Invitations"], Invitations);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Invitations; ToJsonUtilO(Invitations, each_Invitations); output["Invitations"] = each_Invitations;
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

            ~ListGroupMembersRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Group"], Group);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Group; ToJsonUtilO(Group, each_Group); output["Group"] = each_Group;
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

            ~ListGroupMembersResponse() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Members"], Members);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Members; ToJsonUtilO(Members, each_Members); output["Members"] = each_Members;
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

            ~ListMembershipOpportunitiesRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Entity"], Entity);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
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

            ~ListMembershipOpportunitiesResponse() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Applications"], Applications);
                FromJsonUtilO(input["Invitations"], Invitations);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Applications; ToJsonUtilO(Applications, each_Applications); output["Applications"] = each_Applications;
                Json::Value each_Invitations; ToJsonUtilO(Invitations, each_Invitations); output["Invitations"] = each_Invitations;
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

            ~ListMembershipRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Entity"], Entity);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
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

            ~ListMembershipResponse() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Groups"], Groups);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Groups; ToJsonUtilO(Groups, each_Groups); output["Groups"] = each_Groups;
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

            ~RemoveGroupApplicationRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Entity"], Entity);
                FromJsonUtilO(input["Group"], Group);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                Json::Value each_Group; ToJsonUtilO(Group, each_Group); output["Group"] = each_Group;
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

            ~RemoveGroupInvitationRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Entity"], Entity);
                FromJsonUtilO(input["Group"], Group);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                Json::Value each_Group; ToJsonUtilO(Group, each_Group); output["Group"] = each_Group;
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

            ~RemoveMembersRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Group"], Group);
                FromJsonUtilO(input["Members"], Members);
                FromJsonUtilS(input["RoleId"], RoleId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Group; ToJsonUtilO(Group, each_Group); output["Group"] = each_Group;
                Json::Value each_Members; ToJsonUtilO(Members, each_Members); output["Members"] = each_Members;
                Json::Value each_RoleId; ToJsonUtilS(RoleId, each_RoleId); output["RoleId"] = each_RoleId;
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

            ~UnblockEntityRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Entity"], Entity);
                FromJsonUtilO(input["Group"], Group);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                Json::Value each_Group; ToJsonUtilO(Group, each_Group); output["Group"] = each_Group;
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

            ~UpdateGroupRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["AdminRoleId"], AdminRoleId);
                FromJsonUtilP(input["ExpectedProfileVersion"], ExpectedProfileVersion);
                FromJsonUtilO(input["Group"], Group);
                FromJsonUtilS(input["GroupName"], GroupName);
                FromJsonUtilS(input["MemberRoleId"], MemberRoleId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_AdminRoleId; ToJsonUtilS(AdminRoleId, each_AdminRoleId); output["AdminRoleId"] = each_AdminRoleId;
                Json::Value each_ExpectedProfileVersion; ToJsonUtilP(ExpectedProfileVersion, each_ExpectedProfileVersion); output["ExpectedProfileVersion"] = each_ExpectedProfileVersion;
                Json::Value each_Group; ToJsonUtilO(Group, each_Group); output["Group"] = each_Group;
                Json::Value each_GroupName; ToJsonUtilS(GroupName, each_GroupName); output["GroupName"] = each_GroupName;
                Json::Value each_MemberRoleId; ToJsonUtilS(MemberRoleId, each_MemberRoleId); output["MemberRoleId"] = each_MemberRoleId;
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

            ~UpdateGroupResponse() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["OperationReason"], OperationReason);
                FromJsonUtilP(input["ProfileVersion"], ProfileVersion);
                FromJsonUtilE(input["SetResult"], SetResult);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_OperationReason; ToJsonUtilS(OperationReason, each_OperationReason); output["OperationReason"] = each_OperationReason;
                Json::Value each_ProfileVersion; ToJsonUtilP(ProfileVersion, each_ProfileVersion); output["ProfileVersion"] = each_ProfileVersion;
                Json::Value each_SetResult; ToJsonUtilE(SetResult, each_SetResult); output["SetResult"] = each_SetResult;
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

            ~UpdateGroupRoleRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilP(input["ExpectedProfileVersion"], ExpectedProfileVersion);
                FromJsonUtilO(input["Group"], Group);
                FromJsonUtilS(input["RoleId"], RoleId);
                FromJsonUtilS(input["RoleName"], RoleName);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_ExpectedProfileVersion; ToJsonUtilP(ExpectedProfileVersion, each_ExpectedProfileVersion); output["ExpectedProfileVersion"] = each_ExpectedProfileVersion;
                Json::Value each_Group; ToJsonUtilO(Group, each_Group); output["Group"] = each_Group;
                Json::Value each_RoleId; ToJsonUtilS(RoleId, each_RoleId); output["RoleId"] = each_RoleId;
                Json::Value each_RoleName; ToJsonUtilS(RoleName, each_RoleName); output["RoleName"] = each_RoleName;
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

            ~UpdateGroupRoleResponse() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["OperationReason"], OperationReason);
                FromJsonUtilP(input["ProfileVersion"], ProfileVersion);
                FromJsonUtilE(input["SetResult"], SetResult);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_OperationReason; ToJsonUtilS(OperationReason, each_OperationReason); output["OperationReason"] = each_OperationReason;
                Json::Value each_ProfileVersion; ToJsonUtilP(ProfileVersion, each_ProfileVersion); output["ProfileVersion"] = each_ProfileVersion;
                Json::Value each_SetResult; ToJsonUtilE(SetResult, each_SetResult); output["SetResult"] = each_SetResult;
                return output;
            }
        };

    }
}

#endif
