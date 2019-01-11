#include <stdafx.h>

#ifndef DISABLE_PLAYFABENTITY_API

#include <playfab/PlayFabGroupsApi.h>
#include <playfab/PlayFabHttp.h>
#include <playfab/PlayFabSettings.h>
#include <playfab/PlayFabError.h>

#pragma warning (disable: 4100) // formal parameters are part of a public interface

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
        ProcessApiCallback<EmptyResponse> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();

        Json::FastWriter writer;
        std::string jsonAsString = writer.write(requestJson);

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-EntityToken", PlayFabSettings::entityToken);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Group/AcceptGroupApplication",
            headers,
            jsonAsString,
            OnAcceptGroupApplicationResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<EmptyResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabGroupsAPI::OnAcceptGroupApplicationResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        EmptyResponse outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<EmptyResponse> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabGroupsAPI::AcceptGroupInvitation(
        AcceptGroupInvitationRequest& request,
        ProcessApiCallback<EmptyResponse> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();

        Json::FastWriter writer;
        std::string jsonAsString = writer.write(requestJson);

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-EntityToken", PlayFabSettings::entityToken);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Group/AcceptGroupInvitation",
            headers,
            jsonAsString,
            OnAcceptGroupInvitationResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<EmptyResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabGroupsAPI::OnAcceptGroupInvitationResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        EmptyResponse outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<EmptyResponse> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabGroupsAPI::AddMembers(
        AddMembersRequest& request,
        ProcessApiCallback<EmptyResponse> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();

        Json::FastWriter writer;
        std::string jsonAsString = writer.write(requestJson);

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-EntityToken", PlayFabSettings::entityToken);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Group/AddMembers",
            headers,
            jsonAsString,
            OnAddMembersResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<EmptyResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabGroupsAPI::OnAddMembersResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        EmptyResponse outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<EmptyResponse> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabGroupsAPI::ApplyToGroup(
        ApplyToGroupRequest& request,
        ProcessApiCallback<ApplyToGroupResponse> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();

        Json::FastWriter writer;
        std::string jsonAsString = writer.write(requestJson);

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-EntityToken", PlayFabSettings::entityToken);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Group/ApplyToGroup",
            headers,
            jsonAsString,
            OnApplyToGroupResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<ApplyToGroupResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabGroupsAPI::OnApplyToGroupResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        ApplyToGroupResponse outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<ApplyToGroupResponse> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabGroupsAPI::BlockEntity(
        BlockEntityRequest& request,
        ProcessApiCallback<EmptyResponse> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();

        Json::FastWriter writer;
        std::string jsonAsString = writer.write(requestJson);

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-EntityToken", PlayFabSettings::entityToken);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Group/BlockEntity",
            headers,
            jsonAsString,
            OnBlockEntityResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<EmptyResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabGroupsAPI::OnBlockEntityResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        EmptyResponse outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<EmptyResponse> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabGroupsAPI::ChangeMemberRole(
        ChangeMemberRoleRequest& request,
        ProcessApiCallback<EmptyResponse> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();

        Json::FastWriter writer;
        std::string jsonAsString = writer.write(requestJson);

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-EntityToken", PlayFabSettings::entityToken);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Group/ChangeMemberRole",
            headers,
            jsonAsString,
            OnChangeMemberRoleResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<EmptyResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabGroupsAPI::OnChangeMemberRoleResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        EmptyResponse outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<EmptyResponse> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabGroupsAPI::CreateGroup(
        CreateGroupRequest& request,
        ProcessApiCallback<CreateGroupResponse> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();

        Json::FastWriter writer;
        std::string jsonAsString = writer.write(requestJson);

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-EntityToken", PlayFabSettings::entityToken);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Group/CreateGroup",
            headers,
            jsonAsString,
            OnCreateGroupResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<CreateGroupResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabGroupsAPI::OnCreateGroupResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        CreateGroupResponse outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<CreateGroupResponse> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabGroupsAPI::CreateRole(
        CreateGroupRoleRequest& request,
        ProcessApiCallback<CreateGroupRoleResponse> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();

        Json::FastWriter writer;
        std::string jsonAsString = writer.write(requestJson);

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-EntityToken", PlayFabSettings::entityToken);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Group/CreateRole",
            headers,
            jsonAsString,
            OnCreateRoleResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<CreateGroupRoleResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabGroupsAPI::OnCreateRoleResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        CreateGroupRoleResponse outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<CreateGroupRoleResponse> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabGroupsAPI::DeleteGroup(
        DeleteGroupRequest& request,
        ProcessApiCallback<EmptyResponse> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();

        Json::FastWriter writer;
        std::string jsonAsString = writer.write(requestJson);

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-EntityToken", PlayFabSettings::entityToken);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Group/DeleteGroup",
            headers,
            jsonAsString,
            OnDeleteGroupResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<EmptyResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabGroupsAPI::OnDeleteGroupResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        EmptyResponse outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<EmptyResponse> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabGroupsAPI::DeleteRole(
        DeleteRoleRequest& request,
        ProcessApiCallback<EmptyResponse> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();

        Json::FastWriter writer;
        std::string jsonAsString = writer.write(requestJson);

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-EntityToken", PlayFabSettings::entityToken);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Group/DeleteRole",
            headers,
            jsonAsString,
            OnDeleteRoleResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<EmptyResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabGroupsAPI::OnDeleteRoleResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        EmptyResponse outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<EmptyResponse> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabGroupsAPI::GetGroup(
        GetGroupRequest& request,
        ProcessApiCallback<GetGroupResponse> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();

        Json::FastWriter writer;
        std::string jsonAsString = writer.write(requestJson);

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-EntityToken", PlayFabSettings::entityToken);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Group/GetGroup",
            headers,
            jsonAsString,
            OnGetGroupResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetGroupResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabGroupsAPI::OnGetGroupResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        GetGroupResponse outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<GetGroupResponse> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabGroupsAPI::InviteToGroup(
        InviteToGroupRequest& request,
        ProcessApiCallback<InviteToGroupResponse> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();

        Json::FastWriter writer;
        std::string jsonAsString = writer.write(requestJson);

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-EntityToken", PlayFabSettings::entityToken);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Group/InviteToGroup",
            headers,
            jsonAsString,
            OnInviteToGroupResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<InviteToGroupResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabGroupsAPI::OnInviteToGroupResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        InviteToGroupResponse outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<InviteToGroupResponse> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabGroupsAPI::IsMember(
        IsMemberRequest& request,
        ProcessApiCallback<IsMemberResponse> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();

        Json::FastWriter writer;
        std::string jsonAsString = writer.write(requestJson);

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-EntityToken", PlayFabSettings::entityToken);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Group/IsMember",
            headers,
            jsonAsString,
            OnIsMemberResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<IsMemberResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabGroupsAPI::OnIsMemberResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        IsMemberResponse outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<IsMemberResponse> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabGroupsAPI::ListGroupApplications(
        ListGroupApplicationsRequest& request,
        ProcessApiCallback<ListGroupApplicationsResponse> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();

        Json::FastWriter writer;
        std::string jsonAsString = writer.write(requestJson);

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-EntityToken", PlayFabSettings::entityToken);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Group/ListGroupApplications",
            headers,
            jsonAsString,
            OnListGroupApplicationsResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<ListGroupApplicationsResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabGroupsAPI::OnListGroupApplicationsResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        ListGroupApplicationsResponse outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<ListGroupApplicationsResponse> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabGroupsAPI::ListGroupBlocks(
        ListGroupBlocksRequest& request,
        ProcessApiCallback<ListGroupBlocksResponse> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();

        Json::FastWriter writer;
        std::string jsonAsString = writer.write(requestJson);

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-EntityToken", PlayFabSettings::entityToken);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Group/ListGroupBlocks",
            headers,
            jsonAsString,
            OnListGroupBlocksResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<ListGroupBlocksResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabGroupsAPI::OnListGroupBlocksResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        ListGroupBlocksResponse outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<ListGroupBlocksResponse> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabGroupsAPI::ListGroupInvitations(
        ListGroupInvitationsRequest& request,
        ProcessApiCallback<ListGroupInvitationsResponse> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();

        Json::FastWriter writer;
        std::string jsonAsString = writer.write(requestJson);

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-EntityToken", PlayFabSettings::entityToken);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Group/ListGroupInvitations",
            headers,
            jsonAsString,
            OnListGroupInvitationsResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<ListGroupInvitationsResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabGroupsAPI::OnListGroupInvitationsResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        ListGroupInvitationsResponse outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<ListGroupInvitationsResponse> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabGroupsAPI::ListGroupMembers(
        ListGroupMembersRequest& request,
        ProcessApiCallback<ListGroupMembersResponse> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();

        Json::FastWriter writer;
        std::string jsonAsString = writer.write(requestJson);

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-EntityToken", PlayFabSettings::entityToken);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Group/ListGroupMembers",
            headers,
            jsonAsString,
            OnListGroupMembersResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<ListGroupMembersResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabGroupsAPI::OnListGroupMembersResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        ListGroupMembersResponse outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<ListGroupMembersResponse> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabGroupsAPI::ListMembership(
        ListMembershipRequest& request,
        ProcessApiCallback<ListMembershipResponse> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();

        Json::FastWriter writer;
        std::string jsonAsString = writer.write(requestJson);

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-EntityToken", PlayFabSettings::entityToken);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Group/ListMembership",
            headers,
            jsonAsString,
            OnListMembershipResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<ListMembershipResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabGroupsAPI::OnListMembershipResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        ListMembershipResponse outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<ListMembershipResponse> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabGroupsAPI::ListMembershipOpportunities(
        ListMembershipOpportunitiesRequest& request,
        ProcessApiCallback<ListMembershipOpportunitiesResponse> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();

        Json::FastWriter writer;
        std::string jsonAsString = writer.write(requestJson);

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-EntityToken", PlayFabSettings::entityToken);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Group/ListMembershipOpportunities",
            headers,
            jsonAsString,
            OnListMembershipOpportunitiesResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<ListMembershipOpportunitiesResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabGroupsAPI::OnListMembershipOpportunitiesResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        ListMembershipOpportunitiesResponse outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<ListMembershipOpportunitiesResponse> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabGroupsAPI::RemoveGroupApplication(
        RemoveGroupApplicationRequest& request,
        ProcessApiCallback<EmptyResponse> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();

        Json::FastWriter writer;
        std::string jsonAsString = writer.write(requestJson);

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-EntityToken", PlayFabSettings::entityToken);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Group/RemoveGroupApplication",
            headers,
            jsonAsString,
            OnRemoveGroupApplicationResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<EmptyResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabGroupsAPI::OnRemoveGroupApplicationResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        EmptyResponse outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<EmptyResponse> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabGroupsAPI::RemoveGroupInvitation(
        RemoveGroupInvitationRequest& request,
        ProcessApiCallback<EmptyResponse> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();

        Json::FastWriter writer;
        std::string jsonAsString = writer.write(requestJson);

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-EntityToken", PlayFabSettings::entityToken);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Group/RemoveGroupInvitation",
            headers,
            jsonAsString,
            OnRemoveGroupInvitationResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<EmptyResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabGroupsAPI::OnRemoveGroupInvitationResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        EmptyResponse outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<EmptyResponse> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabGroupsAPI::RemoveMembers(
        RemoveMembersRequest& request,
        ProcessApiCallback<EmptyResponse> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();

        Json::FastWriter writer;
        std::string jsonAsString = writer.write(requestJson);

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-EntityToken", PlayFabSettings::entityToken);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Group/RemoveMembers",
            headers,
            jsonAsString,
            OnRemoveMembersResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<EmptyResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabGroupsAPI::OnRemoveMembersResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        EmptyResponse outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<EmptyResponse> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabGroupsAPI::UnblockEntity(
        UnblockEntityRequest& request,
        ProcessApiCallback<EmptyResponse> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();

        Json::FastWriter writer;
        std::string jsonAsString = writer.write(requestJson);

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-EntityToken", PlayFabSettings::entityToken);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Group/UnblockEntity",
            headers,
            jsonAsString,
            OnUnblockEntityResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<EmptyResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabGroupsAPI::OnUnblockEntityResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        EmptyResponse outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<EmptyResponse> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabGroupsAPI::UpdateGroup(
        UpdateGroupRequest& request,
        ProcessApiCallback<UpdateGroupResponse> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();

        Json::FastWriter writer;
        std::string jsonAsString = writer.write(requestJson);

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-EntityToken", PlayFabSettings::entityToken);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Group/UpdateGroup",
            headers,
            jsonAsString,
            OnUpdateGroupResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<UpdateGroupResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabGroupsAPI::OnUpdateGroupResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        UpdateGroupResponse outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<UpdateGroupResponse> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    void PlayFabGroupsAPI::UpdateRole(
        UpdateGroupRoleRequest& request,
        ProcessApiCallback<UpdateGroupRoleResponse> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();

        Json::FastWriter writer;
        std::string jsonAsString = writer.write(requestJson);

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-EntityToken", PlayFabSettings::entityToken);

        CallRequestContainer* reqContainer = new CallRequestContainer(
            "/Group/UpdateRole",
            headers,
            jsonAsString,
            OnUpdateRoleResult,
            customData);

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<UpdateGroupRoleResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        http.MakePostRequest(*reqContainer);
    }

    void PlayFabGroupsAPI::OnUpdateRoleResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(reqContainer);

        UpdateGroupRoleResponse outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<UpdateGroupRoleResponse> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }

        delete &container;
    }

    bool PlayFabGroupsAPI::ValidateResult(PlayFabResultCommon& resultCommon, CallRequestContainer& container)
    {
        if (container.errorWrapper.HttpCode == 200)
        {
            resultCommon.FromJson(container.errorWrapper.Data);
            resultCommon.Request = container.errorWrapper.Request;
            return true;
        }
        else // Process the error case
        {
            if (PlayFabSettings::globalErrorHandler != nullptr)
                PlayFabSettings::globalErrorHandler(container.errorWrapper, container.GetCustomData());
            if (container.errorCallback != nullptr)
                container.errorCallback(container.errorWrapper, container.GetCustomData());
            return false;
        }
    }
}

#endif
