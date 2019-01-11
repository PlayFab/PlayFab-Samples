#pragma once

#ifndef DISABLE_PLAYFABENTITY_API

#include <playfab/PlayFabCallRequestContainer.h>
#include <playfab/PlayFabHttp.h>
#include <playfab/PlayFabGroupsDataModels.h>

namespace PlayFab
{
    /// <summary>
    /// Main interface for PlayFab Sdk, specifically all Groups APIs
    /// </summary>
    class PlayFabGroupsAPI
    {
    public:
        static size_t Update();
        static void ForgetAllCredentials();


        // ------------ Generated API calls
        static void AcceptGroupApplication(GroupsModels::AcceptGroupApplicationRequest& request, ProcessApiCallback<GroupsModels::EmptyResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void AcceptGroupInvitation(GroupsModels::AcceptGroupInvitationRequest& request, ProcessApiCallback<GroupsModels::EmptyResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void AddMembers(GroupsModels::AddMembersRequest& request, ProcessApiCallback<GroupsModels::EmptyResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void ApplyToGroup(GroupsModels::ApplyToGroupRequest& request, ProcessApiCallback<GroupsModels::ApplyToGroupResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void BlockEntity(GroupsModels::BlockEntityRequest& request, ProcessApiCallback<GroupsModels::EmptyResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void ChangeMemberRole(GroupsModels::ChangeMemberRoleRequest& request, ProcessApiCallback<GroupsModels::EmptyResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void CreateGroup(GroupsModels::CreateGroupRequest& request, ProcessApiCallback<GroupsModels::CreateGroupResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void CreateRole(GroupsModels::CreateGroupRoleRequest& request, ProcessApiCallback<GroupsModels::CreateGroupRoleResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void DeleteGroup(GroupsModels::DeleteGroupRequest& request, ProcessApiCallback<GroupsModels::EmptyResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void DeleteRole(GroupsModels::DeleteRoleRequest& request, ProcessApiCallback<GroupsModels::EmptyResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetGroup(GroupsModels::GetGroupRequest& request, ProcessApiCallback<GroupsModels::GetGroupResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void InviteToGroup(GroupsModels::InviteToGroupRequest& request, ProcessApiCallback<GroupsModels::InviteToGroupResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void IsMember(GroupsModels::IsMemberRequest& request, ProcessApiCallback<GroupsModels::IsMemberResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void ListGroupApplications(GroupsModels::ListGroupApplicationsRequest& request, ProcessApiCallback<GroupsModels::ListGroupApplicationsResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void ListGroupBlocks(GroupsModels::ListGroupBlocksRequest& request, ProcessApiCallback<GroupsModels::ListGroupBlocksResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void ListGroupInvitations(GroupsModels::ListGroupInvitationsRequest& request, ProcessApiCallback<GroupsModels::ListGroupInvitationsResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void ListGroupMembers(GroupsModels::ListGroupMembersRequest& request, ProcessApiCallback<GroupsModels::ListGroupMembersResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void ListMembership(GroupsModels::ListMembershipRequest& request, ProcessApiCallback<GroupsModels::ListMembershipResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void ListMembershipOpportunities(GroupsModels::ListMembershipOpportunitiesRequest& request, ProcessApiCallback<GroupsModels::ListMembershipOpportunitiesResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void RemoveGroupApplication(GroupsModels::RemoveGroupApplicationRequest& request, ProcessApiCallback<GroupsModels::EmptyResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void RemoveGroupInvitation(GroupsModels::RemoveGroupInvitationRequest& request, ProcessApiCallback<GroupsModels::EmptyResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void RemoveMembers(GroupsModels::RemoveMembersRequest& request, ProcessApiCallback<GroupsModels::EmptyResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UnblockEntity(GroupsModels::UnblockEntityRequest& request, ProcessApiCallback<GroupsModels::EmptyResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UpdateGroup(GroupsModels::UpdateGroupRequest& request, ProcessApiCallback<GroupsModels::UpdateGroupResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UpdateRole(GroupsModels::UpdateGroupRoleRequest& request, ProcessApiCallback<GroupsModels::UpdateGroupRoleResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);

    private:
        PlayFabGroupsAPI(); // Private constructor, static class should never have an instance
        PlayFabGroupsAPI(const PlayFabGroupsAPI& other); // Private copy-constructor, static class should never have an instance

        // ------------ Generated result handlers
        static void OnAcceptGroupApplicationResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnAcceptGroupInvitationResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnAddMembersResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnApplyToGroupResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnBlockEntityResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnChangeMemberRoleResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnCreateGroupResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnCreateRoleResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnDeleteGroupResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnDeleteRoleResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnGetGroupResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnInviteToGroupResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnIsMemberResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnListGroupApplicationsResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnListGroupBlocksResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnListGroupInvitationsResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnListGroupMembersResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnListMembershipResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnListMembershipOpportunitiesResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnRemoveGroupApplicationResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnRemoveGroupInvitationResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnRemoveMembersResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnUnblockEntityResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnUpdateGroupResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnUpdateRoleResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);

        static bool ValidateResult(PlayFabResultCommon& resultCommon, CallRequestContainer& container);
    };
}

#endif
