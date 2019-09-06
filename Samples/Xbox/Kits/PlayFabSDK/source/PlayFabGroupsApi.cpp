
#ifdef ENABLE_PLAYFABENTITY_API

#include "playfab/PlayFabGroupsApi.h"
#include "playfab/PlayFabHttp.h"
#include "playfab/PlayFabSettings.h"

namespace PlayFab
{
    using namespace GroupsModels;

    size_t PlayFabGroupsAPI::Update()
    {
        return PlayFabHttp::Get().Update();
    }

    void PlayFabGroupsAPI::ForgetAllCredentials()
    {
        return PlayFabSettings::ForgetAllCredentials();
    }

    // PlayFabGroups APIs

    void PlayFabGroupsAPI::AcceptGroupApplication(
        AcceptGroupApplicationRequest& request,
        ProcessApiCallback<EmptyResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Group/AcceptGroupApplication", L"X-EntityToken", PlayFabSettings::entityToken, requestJson, OnAcceptGroupApplicationResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<EmptyResult>(callback)), errorCallback, customData);
    }

    void PlayFabGroupsAPI::OnAcceptGroupApplicationResult(CallRequestContainer& request)
    {
        EmptyResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<EmptyResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabGroupsAPI::AcceptGroupInvitation(
        AcceptGroupInvitationRequest& request,
        ProcessApiCallback<EmptyResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Group/AcceptGroupInvitation", L"X-EntityToken", PlayFabSettings::entityToken, requestJson, OnAcceptGroupInvitationResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<EmptyResult>(callback)), errorCallback, customData);
    }

    void PlayFabGroupsAPI::OnAcceptGroupInvitationResult(CallRequestContainer& request)
    {
        EmptyResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<EmptyResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabGroupsAPI::AddMembers(
        AddMembersRequest& request,
        ProcessApiCallback<EmptyResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Group/AddMembers", L"X-EntityToken", PlayFabSettings::entityToken, requestJson, OnAddMembersResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<EmptyResult>(callback)), errorCallback, customData);
    }

    void PlayFabGroupsAPI::OnAddMembersResult(CallRequestContainer& request)
    {
        EmptyResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<EmptyResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabGroupsAPI::ApplyToGroup(
        ApplyToGroupRequest& request,
        ProcessApiCallback<ApplyToGroupResponse> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Group/ApplyToGroup", L"X-EntityToken", PlayFabSettings::entityToken, requestJson, OnApplyToGroupResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<ApplyToGroupResponse>(callback)), errorCallback, customData);
    }

    void PlayFabGroupsAPI::OnApplyToGroupResult(CallRequestContainer& request)
    {
        ApplyToGroupResponse outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<ApplyToGroupResponse> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabGroupsAPI::BlockEntity(
        BlockEntityRequest& request,
        ProcessApiCallback<EmptyResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Group/BlockEntity", L"X-EntityToken", PlayFabSettings::entityToken, requestJson, OnBlockEntityResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<EmptyResult>(callback)), errorCallback, customData);
    }

    void PlayFabGroupsAPI::OnBlockEntityResult(CallRequestContainer& request)
    {
        EmptyResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<EmptyResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabGroupsAPI::ChangeMemberRole(
        ChangeMemberRoleRequest& request,
        ProcessApiCallback<EmptyResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Group/ChangeMemberRole", L"X-EntityToken", PlayFabSettings::entityToken, requestJson, OnChangeMemberRoleResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<EmptyResult>(callback)), errorCallback, customData);
    }

    void PlayFabGroupsAPI::OnChangeMemberRoleResult(CallRequestContainer& request)
    {
        EmptyResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<EmptyResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabGroupsAPI::CreateGroup(
        CreateGroupRequest& request,
        ProcessApiCallback<CreateGroupResponse> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Group/CreateGroup", L"X-EntityToken", PlayFabSettings::entityToken, requestJson, OnCreateGroupResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<CreateGroupResponse>(callback)), errorCallback, customData);
    }

    void PlayFabGroupsAPI::OnCreateGroupResult(CallRequestContainer& request)
    {
        CreateGroupResponse outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<CreateGroupResponse> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabGroupsAPI::CreateRole(
        CreateGroupRoleRequest& request,
        ProcessApiCallback<CreateGroupRoleResponse> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Group/CreateRole", L"X-EntityToken", PlayFabSettings::entityToken, requestJson, OnCreateRoleResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<CreateGroupRoleResponse>(callback)), errorCallback, customData);
    }

    void PlayFabGroupsAPI::OnCreateRoleResult(CallRequestContainer& request)
    {
        CreateGroupRoleResponse outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<CreateGroupRoleResponse> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabGroupsAPI::DeleteGroup(
        DeleteGroupRequest& request,
        ProcessApiCallback<EmptyResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Group/DeleteGroup", L"X-EntityToken", PlayFabSettings::entityToken, requestJson, OnDeleteGroupResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<EmptyResult>(callback)), errorCallback, customData);
    }

    void PlayFabGroupsAPI::OnDeleteGroupResult(CallRequestContainer& request)
    {
        EmptyResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<EmptyResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabGroupsAPI::DeleteRole(
        DeleteRoleRequest& request,
        ProcessApiCallback<EmptyResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Group/DeleteRole", L"X-EntityToken", PlayFabSettings::entityToken, requestJson, OnDeleteRoleResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<EmptyResult>(callback)), errorCallback, customData);
    }

    void PlayFabGroupsAPI::OnDeleteRoleResult(CallRequestContainer& request)
    {
        EmptyResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<EmptyResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabGroupsAPI::GetGroup(
        GetGroupRequest& request,
        ProcessApiCallback<GetGroupResponse> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Group/GetGroup", L"X-EntityToken", PlayFabSettings::entityToken, requestJson, OnGetGroupResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<GetGroupResponse>(callback)), errorCallback, customData);
    }

    void PlayFabGroupsAPI::OnGetGroupResult(CallRequestContainer& request)
    {
        GetGroupResponse outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<GetGroupResponse> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabGroupsAPI::InviteToGroup(
        InviteToGroupRequest& request,
        ProcessApiCallback<InviteToGroupResponse> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Group/InviteToGroup", L"X-EntityToken", PlayFabSettings::entityToken, requestJson, OnInviteToGroupResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<InviteToGroupResponse>(callback)), errorCallback, customData);
    }

    void PlayFabGroupsAPI::OnInviteToGroupResult(CallRequestContainer& request)
    {
        InviteToGroupResponse outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<InviteToGroupResponse> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabGroupsAPI::IsMember(
        IsMemberRequest& request,
        ProcessApiCallback<IsMemberResponse> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Group/IsMember", L"X-EntityToken", PlayFabSettings::entityToken, requestJson, OnIsMemberResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<IsMemberResponse>(callback)), errorCallback, customData);
    }

    void PlayFabGroupsAPI::OnIsMemberResult(CallRequestContainer& request)
    {
        IsMemberResponse outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<IsMemberResponse> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabGroupsAPI::ListGroupApplications(
        ListGroupApplicationsRequest& request,
        ProcessApiCallback<ListGroupApplicationsResponse> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Group/ListGroupApplications", L"X-EntityToken", PlayFabSettings::entityToken, requestJson, OnListGroupApplicationsResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<ListGroupApplicationsResponse>(callback)), errorCallback, customData);
    }

    void PlayFabGroupsAPI::OnListGroupApplicationsResult(CallRequestContainer& request)
    {
        ListGroupApplicationsResponse outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<ListGroupApplicationsResponse> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabGroupsAPI::ListGroupBlocks(
        ListGroupBlocksRequest& request,
        ProcessApiCallback<ListGroupBlocksResponse> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Group/ListGroupBlocks", L"X-EntityToken", PlayFabSettings::entityToken, requestJson, OnListGroupBlocksResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<ListGroupBlocksResponse>(callback)), errorCallback, customData);
    }

    void PlayFabGroupsAPI::OnListGroupBlocksResult(CallRequestContainer& request)
    {
        ListGroupBlocksResponse outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<ListGroupBlocksResponse> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabGroupsAPI::ListGroupInvitations(
        ListGroupInvitationsRequest& request,
        ProcessApiCallback<ListGroupInvitationsResponse> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Group/ListGroupInvitations", L"X-EntityToken", PlayFabSettings::entityToken, requestJson, OnListGroupInvitationsResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<ListGroupInvitationsResponse>(callback)), errorCallback, customData);
    }

    void PlayFabGroupsAPI::OnListGroupInvitationsResult(CallRequestContainer& request)
    {
        ListGroupInvitationsResponse outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<ListGroupInvitationsResponse> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabGroupsAPI::ListGroupMembers(
        ListGroupMembersRequest& request,
        ProcessApiCallback<ListGroupMembersResponse> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Group/ListGroupMembers", L"X-EntityToken", PlayFabSettings::entityToken, requestJson, OnListGroupMembersResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<ListGroupMembersResponse>(callback)), errorCallback, customData);
    }

    void PlayFabGroupsAPI::OnListGroupMembersResult(CallRequestContainer& request)
    {
        ListGroupMembersResponse outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<ListGroupMembersResponse> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabGroupsAPI::ListMembership(
        ListMembershipRequest& request,
        ProcessApiCallback<ListMembershipResponse> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Group/ListMembership", L"X-EntityToken", PlayFabSettings::entityToken, requestJson, OnListMembershipResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<ListMembershipResponse>(callback)), errorCallback, customData);
    }

    void PlayFabGroupsAPI::OnListMembershipResult(CallRequestContainer& request)
    {
        ListMembershipResponse outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<ListMembershipResponse> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabGroupsAPI::ListMembershipOpportunities(
        ListMembershipOpportunitiesRequest& request,
        ProcessApiCallback<ListMembershipOpportunitiesResponse> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Group/ListMembershipOpportunities", L"X-EntityToken", PlayFabSettings::entityToken, requestJson, OnListMembershipOpportunitiesResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<ListMembershipOpportunitiesResponse>(callback)), errorCallback, customData);
    }

    void PlayFabGroupsAPI::OnListMembershipOpportunitiesResult(CallRequestContainer& request)
    {
        ListMembershipOpportunitiesResponse outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<ListMembershipOpportunitiesResponse> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabGroupsAPI::RemoveGroupApplication(
        RemoveGroupApplicationRequest& request,
        ProcessApiCallback<EmptyResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Group/RemoveGroupApplication", L"X-EntityToken", PlayFabSettings::entityToken, requestJson, OnRemoveGroupApplicationResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<EmptyResult>(callback)), errorCallback, customData);
    }

    void PlayFabGroupsAPI::OnRemoveGroupApplicationResult(CallRequestContainer& request)
    {
        EmptyResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<EmptyResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabGroupsAPI::RemoveGroupInvitation(
        RemoveGroupInvitationRequest& request,
        ProcessApiCallback<EmptyResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Group/RemoveGroupInvitation", L"X-EntityToken", PlayFabSettings::entityToken, requestJson, OnRemoveGroupInvitationResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<EmptyResult>(callback)), errorCallback, customData);
    }

    void PlayFabGroupsAPI::OnRemoveGroupInvitationResult(CallRequestContainer& request)
    {
        EmptyResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<EmptyResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabGroupsAPI::RemoveMembers(
        RemoveMembersRequest& request,
        ProcessApiCallback<EmptyResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Group/RemoveMembers", L"X-EntityToken", PlayFabSettings::entityToken, requestJson, OnRemoveMembersResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<EmptyResult>(callback)), errorCallback, customData);
    }

    void PlayFabGroupsAPI::OnRemoveMembersResult(CallRequestContainer& request)
    {
        EmptyResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<EmptyResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabGroupsAPI::UnblockEntity(
        UnblockEntityRequest& request,
        ProcessApiCallback<EmptyResult> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Group/UnblockEntity", L"X-EntityToken", PlayFabSettings::entityToken, requestJson, OnUnblockEntityResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<EmptyResult>(callback)), errorCallback, customData);
    }

    void PlayFabGroupsAPI::OnUnblockEntityResult(CallRequestContainer& request)
    {
        EmptyResult outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<EmptyResult> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabGroupsAPI::UpdateGroup(
        UpdateGroupRequest& request,
        ProcessApiCallback<UpdateGroupResponse> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Group/UpdateGroup", L"X-EntityToken", PlayFabSettings::entityToken, requestJson, OnUpdateGroupResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<UpdateGroupResponse>(callback)), errorCallback, customData);
    }

    void PlayFabGroupsAPI::OnUpdateGroupResult(CallRequestContainer& request)
    {
        UpdateGroupResponse outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<UpdateGroupResponse> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }

    void PlayFabGroupsAPI::UpdateRole(
        UpdateGroupRoleRequest& request,
        ProcessApiCallback<UpdateGroupRoleResponse> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttp& http = IPlayFabHttp::Get();
        auto requestJson = request.ToJson();
        http.AddRequest(L"/Group/UpdateRole", L"X-EntityToken", PlayFabSettings::entityToken, requestJson, OnUpdateRoleResult, SharedVoidPointer((callback == nullptr) ? nullptr : new ProcessApiCallback<UpdateGroupRoleResponse>(callback)), errorCallback, customData);
    }

    void PlayFabGroupsAPI::OnUpdateRoleResult(CallRequestContainer& request)
    {
        UpdateGroupRoleResponse outResult;
        outResult.FromJson(request.errorWrapper.Data);
        outResult.Request = request.request;

        auto internalPtr = request.successCallback.get();
        if (internalPtr != nullptr)
        {
            auto callback = (*static_cast<ProcessApiCallback<UpdateGroupRoleResponse> *>(internalPtr));
            callback(outResult, request.customData);
        }
    }
}

#endif
