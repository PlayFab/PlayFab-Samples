#pragma once

#ifdef ENABLE_PLAYFABENTITY_API

#include "playfab/PlayFabHttp.h"
#include "playfab/PlayFabGroupsDataModels.h"

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
        static void AcceptGroupApplication(GroupsModels::AcceptGroupApplicationRequest& request, ProcessApiCallback<GroupsModels::EmptyResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void AcceptGroupInvitation(GroupsModels::AcceptGroupInvitationRequest& request, ProcessApiCallback<GroupsModels::EmptyResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void AddMembers(GroupsModels::AddMembersRequest& request, ProcessApiCallback<GroupsModels::EmptyResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void ApplyToGroup(GroupsModels::ApplyToGroupRequest& request, ProcessApiCallback<GroupsModels::ApplyToGroupResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void BlockEntity(GroupsModels::BlockEntityRequest& request, ProcessApiCallback<GroupsModels::EmptyResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void ChangeMemberRole(GroupsModels::ChangeMemberRoleRequest& request, ProcessApiCallback<GroupsModels::EmptyResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void CreateGroup(GroupsModels::CreateGroupRequest& request, ProcessApiCallback<GroupsModels::CreateGroupResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void CreateRole(GroupsModels::CreateGroupRoleRequest& request, ProcessApiCallback<GroupsModels::CreateGroupRoleResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void DeleteGroup(GroupsModels::DeleteGroupRequest& request, ProcessApiCallback<GroupsModels::EmptyResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void DeleteRole(GroupsModels::DeleteRoleRequest& request, ProcessApiCallback<GroupsModels::EmptyResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetGroup(GroupsModels::GetGroupRequest& request, ProcessApiCallback<GroupsModels::GetGroupResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void InviteToGroup(GroupsModels::InviteToGroupRequest& request, ProcessApiCallback<GroupsModels::InviteToGroupResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void IsMember(GroupsModels::IsMemberRequest& request, ProcessApiCallback<GroupsModels::IsMemberResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void ListGroupApplications(GroupsModels::ListGroupApplicationsRequest& request, ProcessApiCallback<GroupsModels::ListGroupApplicationsResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void ListGroupBlocks(GroupsModels::ListGroupBlocksRequest& request, ProcessApiCallback<GroupsModels::ListGroupBlocksResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void ListGroupInvitations(GroupsModels::ListGroupInvitationsRequest& request, ProcessApiCallback<GroupsModels::ListGroupInvitationsResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void ListGroupMembers(GroupsModels::ListGroupMembersRequest& request, ProcessApiCallback<GroupsModels::ListGroupMembersResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void ListMembership(GroupsModels::ListMembershipRequest& request, ProcessApiCallback<GroupsModels::ListMembershipResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void ListMembershipOpportunities(GroupsModels::ListMembershipOpportunitiesRequest& request, ProcessApiCallback<GroupsModels::ListMembershipOpportunitiesResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void RemoveGroupApplication(GroupsModels::RemoveGroupApplicationRequest& request, ProcessApiCallback<GroupsModels::EmptyResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void RemoveGroupInvitation(GroupsModels::RemoveGroupInvitationRequest& request, ProcessApiCallback<GroupsModels::EmptyResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void RemoveMembers(GroupsModels::RemoveMembersRequest& request, ProcessApiCallback<GroupsModels::EmptyResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UnblockEntity(GroupsModels::UnblockEntityRequest& request, ProcessApiCallback<GroupsModels::EmptyResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UpdateGroup(GroupsModels::UpdateGroupRequest& request, ProcessApiCallback<GroupsModels::UpdateGroupResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UpdateRole(GroupsModels::UpdateGroupRoleRequest& request, ProcessApiCallback<GroupsModels::UpdateGroupRoleResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);

    private:
        PlayFabGroupsAPI(); // Private constructor, static class should never have an instance
        PlayFabGroupsAPI(const PlayFabGroupsAPI& other); // Private copy-constructor, static class should never have an instance

        // ------------ Generated result handlers
        static void OnAcceptGroupApplicationResult(CallRequestContainer& request);
        static void OnAcceptGroupInvitationResult(CallRequestContainer& request);
        static void OnAddMembersResult(CallRequestContainer& request);
        static void OnApplyToGroupResult(CallRequestContainer& request);
        static void OnBlockEntityResult(CallRequestContainer& request);
        static void OnChangeMemberRoleResult(CallRequestContainer& request);
        static void OnCreateGroupResult(CallRequestContainer& request);
        static void OnCreateRoleResult(CallRequestContainer& request);
        static void OnDeleteGroupResult(CallRequestContainer& request);
        static void OnDeleteRoleResult(CallRequestContainer& request);
        static void OnGetGroupResult(CallRequestContainer& request);
        static void OnInviteToGroupResult(CallRequestContainer& request);
        static void OnIsMemberResult(CallRequestContainer& request);
        static void OnListGroupApplicationsResult(CallRequestContainer& request);
        static void OnListGroupBlocksResult(CallRequestContainer& request);
        static void OnListGroupInvitationsResult(CallRequestContainer& request);
        static void OnListGroupMembersResult(CallRequestContainer& request);
        static void OnListMembershipResult(CallRequestContainer& request);
        static void OnListMembershipOpportunitiesResult(CallRequestContainer& request);
        static void OnRemoveGroupApplicationResult(CallRequestContainer& request);
        static void OnRemoveGroupInvitationResult(CallRequestContainer& request);
        static void OnRemoveMembersResult(CallRequestContainer& request);
        static void OnUnblockEntityResult(CallRequestContainer& request);
        static void OnUpdateGroupResult(CallRequestContainer& request);
        static void OnUpdateRoleResult(CallRequestContainer& request);

    };
}

#endif
