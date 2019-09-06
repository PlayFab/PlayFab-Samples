#pragma once

#ifndef DISABLE_PLAYFABCLIENT_API

#include "playfab/PlayFabHttp.h"
#include "playfab/PlayFabEntityDataModels.h"

namespace PlayFab
{
    /// <summary>
    /// Main interface for PlayFab Sdk, specifically all Entity APIs
    /// </summary>
    class PlayFabEntityAPI
    {
    public:
        static size_t Update();
        static void ForgetAllCredentials();


        // ------------ Generated API calls
        static void AbortFileUploads(EntityModels::AbortFileUploadsRequest& request, ProcessApiCallback<EntityModels::AbortFileUploadsResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void AcceptGroupApplication(EntityModels::AcceptGroupApplicationRequest& request, ProcessApiCallback<EntityModels::EmptyResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void AcceptGroupInvitation(EntityModels::AcceptGroupInvitationRequest& request, ProcessApiCallback<EntityModels::EmptyResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void AddMembers(EntityModels::AddMembersRequest& request, ProcessApiCallback<EntityModels::EmptyResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void ApplyToGroup(EntityModels::ApplyToGroupRequest& request, ProcessApiCallback<EntityModels::ApplyToGroupResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void BlockEntity(EntityModels::BlockEntityRequest& request, ProcessApiCallback<EntityModels::EmptyResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void ChangeMemberRole(EntityModels::ChangeMemberRoleRequest& request, ProcessApiCallback<EntityModels::EmptyResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void CreateGroup(EntityModels::CreateGroupRequest& request, ProcessApiCallback<EntityModels::CreateGroupResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void CreateRole(EntityModels::CreateGroupRoleRequest& request, ProcessApiCallback<EntityModels::CreateGroupRoleResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void DeleteFiles(EntityModels::DeleteFilesRequest& request, ProcessApiCallback<EntityModels::DeleteFilesResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void DeleteGroup(EntityModels::DeleteGroupRequest& request, ProcessApiCallback<EntityModels::EmptyResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void DeleteRole(EntityModels::DeleteRoleRequest& request, ProcessApiCallback<EntityModels::EmptyResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void FinalizeFileUploads(EntityModels::FinalizeFileUploadsRequest& request, ProcessApiCallback<EntityModels::FinalizeFileUploadsResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetEntityToken(EntityModels::GetEntityTokenRequest& request, ProcessApiCallback<EntityModels::GetEntityTokenResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetFiles(EntityModels::GetFilesRequest& request, ProcessApiCallback<EntityModels::GetFilesResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetGlobalPolicy(EntityModels::GetGlobalPolicyRequest& request, ProcessApiCallback<EntityModels::GetGlobalPolicyResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetGroup(EntityModels::GetGroupRequest& request, ProcessApiCallback<EntityModels::GetGroupResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetObjects(EntityModels::GetObjectsRequest& request, ProcessApiCallback<EntityModels::GetObjectsResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetProfile(EntityModels::GetEntityProfileRequest& request, ProcessApiCallback<EntityModels::GetEntityProfileResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void InitiateFileUploads(EntityModels::InitiateFileUploadsRequest& request, ProcessApiCallback<EntityModels::InitiateFileUploadsResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void InviteToGroup(EntityModels::InviteToGroupRequest& request, ProcessApiCallback<EntityModels::InviteToGroupResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void IsMember(EntityModels::IsMemberRequest& request, ProcessApiCallback<EntityModels::IsMemberResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void ListGroupApplications(EntityModels::ListGroupApplicationsRequest& request, ProcessApiCallback<EntityModels::ListGroupApplicationsResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void ListGroupBlocks(EntityModels::ListGroupBlocksRequest& request, ProcessApiCallback<EntityModels::ListGroupBlocksResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void ListGroupInvitations(EntityModels::ListGroupInvitationsRequest& request, ProcessApiCallback<EntityModels::ListGroupInvitationsResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void ListGroupMembers(EntityModels::ListGroupMembersRequest& request, ProcessApiCallback<EntityModels::ListGroupMembersResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void ListMembership(EntityModels::ListMembershipRequest& request, ProcessApiCallback<EntityModels::ListMembershipResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void ListMembershipOpportunities(EntityModels::ListMembershipOpportunitiesRequest& request, ProcessApiCallback<EntityModels::ListMembershipOpportunitiesResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void RemoveGroupApplication(EntityModels::RemoveGroupApplicationRequest& request, ProcessApiCallback<EntityModels::EmptyResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void RemoveGroupInvitation(EntityModels::RemoveGroupInvitationRequest& request, ProcessApiCallback<EntityModels::EmptyResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void RemoveMembers(EntityModels::RemoveMembersRequest& request, ProcessApiCallback<EntityModels::EmptyResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void SetGlobalPolicy(EntityModels::SetGlobalPolicyRequest& request, ProcessApiCallback<EntityModels::SetGlobalPolicyResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void SetObjects(EntityModels::SetObjectsRequest& request, ProcessApiCallback<EntityModels::SetObjectsResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void SetProfilePolicy(EntityModels::SetEntityProfilePolicyRequest& request, ProcessApiCallback<EntityModels::SetEntityProfilePolicyResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UnblockEntity(EntityModels::UnblockEntityRequest& request, ProcessApiCallback<EntityModels::EmptyResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UpdateGroup(EntityModels::UpdateGroupRequest& request, ProcessApiCallback<EntityModels::UpdateGroupResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UpdateRole(EntityModels::UpdateGroupRoleRequest& request, ProcessApiCallback<EntityModels::UpdateGroupRoleResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);

    private:
        PlayFabEntityAPI(); // Private constructor, static class should never have an instance
        PlayFabEntityAPI(const PlayFabEntityAPI& other); // Private copy-constructor, static class should never have an instance

        // ------------ Generated result handlers
        static void OnAbortFileUploadsResult(CallRequestContainer& request);
        static void OnAcceptGroupApplicationResult(CallRequestContainer& request);
        static void OnAcceptGroupInvitationResult(CallRequestContainer& request);
        static void OnAddMembersResult(CallRequestContainer& request);
        static void OnApplyToGroupResult(CallRequestContainer& request);
        static void OnBlockEntityResult(CallRequestContainer& request);
        static void OnChangeMemberRoleResult(CallRequestContainer& request);
        static void OnCreateGroupResult(CallRequestContainer& request);
        static void OnCreateRoleResult(CallRequestContainer& request);
        static void OnDeleteFilesResult(CallRequestContainer& request);
        static void OnDeleteGroupResult(CallRequestContainer& request);
        static void OnDeleteRoleResult(CallRequestContainer& request);
        static void OnFinalizeFileUploadsResult(CallRequestContainer& request);
        static void OnGetEntityTokenResult(CallRequestContainer& request);
        static void OnGetFilesResult(CallRequestContainer& request);
        static void OnGetGlobalPolicyResult(CallRequestContainer& request);
        static void OnGetGroupResult(CallRequestContainer& request);
        static void OnGetObjectsResult(CallRequestContainer& request);
        static void OnGetProfileResult(CallRequestContainer& request);
        static void OnInitiateFileUploadsResult(CallRequestContainer& request);
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
        static void OnSetGlobalPolicyResult(CallRequestContainer& request);
        static void OnSetObjectsResult(CallRequestContainer& request);
        static void OnSetProfilePolicyResult(CallRequestContainer& request);
        static void OnUnblockEntityResult(CallRequestContainer& request);
        static void OnUpdateGroupResult(CallRequestContainer& request);
        static void OnUpdateRoleResult(CallRequestContainer& request);

    };
}

#endif
