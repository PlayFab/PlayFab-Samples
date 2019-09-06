#pragma once

#ifdef ENABLE_PLAYFABADMIN_API

#include "playfab/PlayFabHttp.h"
#include "playfab/PlayFabAdminDataModels.h"

namespace PlayFab
{
    /// <summary>
    /// Main interface for PlayFab Sdk, specifically all Admin APIs
    /// </summary>
    class PlayFabAdminAPI
    {
    public:
        static size_t Update();
        static void ForgetAllCredentials();


        // ------------ Generated API calls
        static void AbortTaskInstance(AdminModels::AbortTaskInstanceRequest& request, ProcessApiCallback<AdminModels::EmptyResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void AddNews(AdminModels::AddNewsRequest& request, ProcessApiCallback<AdminModels::AddNewsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void AddPlayerTag(AdminModels::AddPlayerTagRequest& request, ProcessApiCallback<AdminModels::AddPlayerTagResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void AddServerBuild(AdminModels::AddServerBuildRequest& request, ProcessApiCallback<AdminModels::AddServerBuildResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void AddUserVirtualCurrency(AdminModels::AddUserVirtualCurrencyRequest& request, ProcessApiCallback<AdminModels::ModifyUserVirtualCurrencyResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void AddVirtualCurrencyTypes(AdminModels::AddVirtualCurrencyTypesRequest& request, ProcessApiCallback<AdminModels::BlankResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void BanUsers(AdminModels::BanUsersRequest& request, ProcessApiCallback<AdminModels::BanUsersResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void CheckLimitedEditionItemAvailability(AdminModels::CheckLimitedEditionItemAvailabilityRequest& request, ProcessApiCallback<AdminModels::CheckLimitedEditionItemAvailabilityResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void CreateActionsOnPlayersInSegmentTask(AdminModels::CreateActionsOnPlayerSegmentTaskRequest& request, ProcessApiCallback<AdminModels::CreateTaskResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void CreateCloudScriptTask(AdminModels::CreateCloudScriptTaskRequest& request, ProcessApiCallback<AdminModels::CreateTaskResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void CreatePlayerSharedSecret(AdminModels::CreatePlayerSharedSecretRequest& request, ProcessApiCallback<AdminModels::CreatePlayerSharedSecretResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void CreatePlayerStatisticDefinition(AdminModels::CreatePlayerStatisticDefinitionRequest& request, ProcessApiCallback<AdminModels::CreatePlayerStatisticDefinitionResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void DeleteContent(AdminModels::DeleteContentRequest& request, ProcessApiCallback<AdminModels::BlankResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void DeleteMasterPlayerAccount(AdminModels::DeleteMasterPlayerAccountRequest& request, ProcessApiCallback<AdminModels::DeleteMasterPlayerAccountResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void DeletePlayer(AdminModels::DeletePlayerRequest& request, ProcessApiCallback<AdminModels::DeletePlayerResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void DeletePlayerSharedSecret(AdminModels::DeletePlayerSharedSecretRequest& request, ProcessApiCallback<AdminModels::DeletePlayerSharedSecretResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void DeleteStore(AdminModels::DeleteStoreRequest& request, ProcessApiCallback<AdminModels::DeleteStoreResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void DeleteTask(AdminModels::DeleteTaskRequest& request, ProcessApiCallback<AdminModels::EmptyResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void DeleteTitle(AdminModels::DeleteTitleRequest& request, ProcessApiCallback<AdminModels::DeleteTitleResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void ExportMasterPlayerData(AdminModels::ExportMasterPlayerDataRequest& request, ProcessApiCallback<AdminModels::ExportMasterPlayerDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetActionsOnPlayersInSegmentTaskInstance(AdminModels::GetTaskInstanceRequest& request, ProcessApiCallback<AdminModels::GetActionsOnPlayersInSegmentTaskInstanceResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetAllSegments(AdminModels::GetAllSegmentsRequest& request, ProcessApiCallback<AdminModels::GetAllSegmentsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetCatalogItems(AdminModels::GetCatalogItemsRequest& request, ProcessApiCallback<AdminModels::GetCatalogItemsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetCloudScriptRevision(AdminModels::GetCloudScriptRevisionRequest& request, ProcessApiCallback<AdminModels::GetCloudScriptRevisionResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetCloudScriptTaskInstance(AdminModels::GetTaskInstanceRequest& request, ProcessApiCallback<AdminModels::GetCloudScriptTaskInstanceResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetCloudScriptVersions(AdminModels::GetCloudScriptVersionsRequest& request, ProcessApiCallback<AdminModels::GetCloudScriptVersionsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetContentList(AdminModels::GetContentListRequest& request, ProcessApiCallback<AdminModels::GetContentListResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetContentUploadUrl(AdminModels::GetContentUploadUrlRequest& request, ProcessApiCallback<AdminModels::GetContentUploadUrlResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetDataReport(AdminModels::GetDataReportRequest& request, ProcessApiCallback<AdminModels::GetDataReportResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetMatchmakerGameInfo(AdminModels::GetMatchmakerGameInfoRequest& request, ProcessApiCallback<AdminModels::GetMatchmakerGameInfoResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetMatchmakerGameModes(AdminModels::GetMatchmakerGameModesRequest& request, ProcessApiCallback<AdminModels::GetMatchmakerGameModesResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetPlayedTitleList(AdminModels::GetPlayedTitleListRequest& request, ProcessApiCallback<AdminModels::GetPlayedTitleListResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetPlayerIdFromAuthToken(AdminModels::GetPlayerIdFromAuthTokenRequest& request, ProcessApiCallback<AdminModels::GetPlayerIdFromAuthTokenResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetPlayerProfile(AdminModels::GetPlayerProfileRequest& request, ProcessApiCallback<AdminModels::GetPlayerProfileResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetPlayerSegments(AdminModels::GetPlayersSegmentsRequest& request, ProcessApiCallback<AdminModels::GetPlayerSegmentsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetPlayerSharedSecrets(AdminModels::GetPlayerSharedSecretsRequest& request, ProcessApiCallback<AdminModels::GetPlayerSharedSecretsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetPlayersInSegment(AdminModels::GetPlayersInSegmentRequest& request, ProcessApiCallback<AdminModels::GetPlayersInSegmentResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetPlayerStatisticDefinitions(AdminModels::GetPlayerStatisticDefinitionsRequest& request, ProcessApiCallback<AdminModels::GetPlayerStatisticDefinitionsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetPlayerStatisticVersions(AdminModels::GetPlayerStatisticVersionsRequest& request, ProcessApiCallback<AdminModels::GetPlayerStatisticVersionsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetPlayerTags(AdminModels::GetPlayerTagsRequest& request, ProcessApiCallback<AdminModels::GetPlayerTagsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetPolicy(AdminModels::GetPolicyRequest& request, ProcessApiCallback<AdminModels::GetPolicyResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetPublisherData(AdminModels::GetPublisherDataRequest& request, ProcessApiCallback<AdminModels::GetPublisherDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetRandomResultTables(AdminModels::GetRandomResultTablesRequest& request, ProcessApiCallback<AdminModels::GetRandomResultTablesResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetServerBuildInfo(AdminModels::GetServerBuildInfoRequest& request, ProcessApiCallback<AdminModels::GetServerBuildInfoResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetServerBuildUploadUrl(AdminModels::GetServerBuildUploadURLRequest& request, ProcessApiCallback<AdminModels::GetServerBuildUploadURLResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetStoreItems(AdminModels::GetStoreItemsRequest& request, ProcessApiCallback<AdminModels::GetStoreItemsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetTaskInstances(AdminModels::GetTaskInstancesRequest& request, ProcessApiCallback<AdminModels::GetTaskInstancesResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetTasks(AdminModels::GetTasksRequest& request, ProcessApiCallback<AdminModels::GetTasksResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetTitleData(AdminModels::GetTitleDataRequest& request, ProcessApiCallback<AdminModels::GetTitleDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetTitleInternalData(AdminModels::GetTitleDataRequest& request, ProcessApiCallback<AdminModels::GetTitleDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetUserAccountInfo(AdminModels::LookupUserAccountInfoRequest& request, ProcessApiCallback<AdminModels::LookupUserAccountInfoResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetUserBans(AdminModels::GetUserBansRequest& request, ProcessApiCallback<AdminModels::GetUserBansResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetUserData(AdminModels::GetUserDataRequest& request, ProcessApiCallback<AdminModels::GetUserDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetUserInternalData(AdminModels::GetUserDataRequest& request, ProcessApiCallback<AdminModels::GetUserDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetUserInventory(AdminModels::GetUserInventoryRequest& request, ProcessApiCallback<AdminModels::GetUserInventoryResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetUserPublisherData(AdminModels::GetUserDataRequest& request, ProcessApiCallback<AdminModels::GetUserDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetUserPublisherInternalData(AdminModels::GetUserDataRequest& request, ProcessApiCallback<AdminModels::GetUserDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetUserPublisherReadOnlyData(AdminModels::GetUserDataRequest& request, ProcessApiCallback<AdminModels::GetUserDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetUserReadOnlyData(AdminModels::GetUserDataRequest& request, ProcessApiCallback<AdminModels::GetUserDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GrantItemsToUsers(AdminModels::GrantItemsToUsersRequest& request, ProcessApiCallback<AdminModels::GrantItemsToUsersResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void IncrementLimitedEditionItemAvailability(AdminModels::IncrementLimitedEditionItemAvailabilityRequest& request, ProcessApiCallback<AdminModels::IncrementLimitedEditionItemAvailabilityResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void IncrementPlayerStatisticVersion(AdminModels::IncrementPlayerStatisticVersionRequest& request, ProcessApiCallback<AdminModels::IncrementPlayerStatisticVersionResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void ListServerBuilds(AdminModels::ListBuildsRequest& request, ProcessApiCallback<AdminModels::ListBuildsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void ListVirtualCurrencyTypes(AdminModels::ListVirtualCurrencyTypesRequest& request, ProcessApiCallback<AdminModels::ListVirtualCurrencyTypesResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void ModifyMatchmakerGameModes(AdminModels::ModifyMatchmakerGameModesRequest& request, ProcessApiCallback<AdminModels::ModifyMatchmakerGameModesResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void ModifyServerBuild(AdminModels::ModifyServerBuildRequest& request, ProcessApiCallback<AdminModels::ModifyServerBuildResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void RefundPurchase(AdminModels::RefundPurchaseRequest& request, ProcessApiCallback<AdminModels::RefundPurchaseResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void RemovePlayerTag(AdminModels::RemovePlayerTagRequest& request, ProcessApiCallback<AdminModels::RemovePlayerTagResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void RemoveServerBuild(AdminModels::RemoveServerBuildRequest& request, ProcessApiCallback<AdminModels::RemoveServerBuildResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void RemoveVirtualCurrencyTypes(AdminModels::RemoveVirtualCurrencyTypesRequest& request, ProcessApiCallback<AdminModels::BlankResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void ResetCharacterStatistics(AdminModels::ResetCharacterStatisticsRequest& request, ProcessApiCallback<AdminModels::ResetCharacterStatisticsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void ResetPassword(AdminModels::ResetPasswordRequest& request, ProcessApiCallback<AdminModels::ResetPasswordResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void ResetUserStatistics(AdminModels::ResetUserStatisticsRequest& request, ProcessApiCallback<AdminModels::ResetUserStatisticsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void ResolvePurchaseDispute(AdminModels::ResolvePurchaseDisputeRequest& request, ProcessApiCallback<AdminModels::ResolvePurchaseDisputeResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void RevokeAllBansForUser(AdminModels::RevokeAllBansForUserRequest& request, ProcessApiCallback<AdminModels::RevokeAllBansForUserResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void RevokeBans(AdminModels::RevokeBansRequest& request, ProcessApiCallback<AdminModels::RevokeBansResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void RevokeInventoryItem(AdminModels::RevokeInventoryItemRequest& request, ProcessApiCallback<AdminModels::RevokeInventoryResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void RevokeInventoryItems(AdminModels::RevokeInventoryItemsRequest& request, ProcessApiCallback<AdminModels::RevokeInventoryItemsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void RunTask(AdminModels::RunTaskRequest& request, ProcessApiCallback<AdminModels::RunTaskResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void SendAccountRecoveryEmail(AdminModels::SendAccountRecoveryEmailRequest& request, ProcessApiCallback<AdminModels::SendAccountRecoveryEmailResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void SetCatalogItems(AdminModels::UpdateCatalogItemsRequest& request, ProcessApiCallback<AdminModels::UpdateCatalogItemsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void SetPlayerSecret(AdminModels::SetPlayerSecretRequest& request, ProcessApiCallback<AdminModels::SetPlayerSecretResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void SetPublishedRevision(AdminModels::SetPublishedRevisionRequest& request, ProcessApiCallback<AdminModels::SetPublishedRevisionResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void SetPublisherData(AdminModels::SetPublisherDataRequest& request, ProcessApiCallback<AdminModels::SetPublisherDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void SetStoreItems(AdminModels::UpdateStoreItemsRequest& request, ProcessApiCallback<AdminModels::UpdateStoreItemsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void SetTitleData(AdminModels::SetTitleDataRequest& request, ProcessApiCallback<AdminModels::SetTitleDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void SetTitleInternalData(AdminModels::SetTitleDataRequest& request, ProcessApiCallback<AdminModels::SetTitleDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void SetupPushNotification(AdminModels::SetupPushNotificationRequest& request, ProcessApiCallback<AdminModels::SetupPushNotificationResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void SubtractUserVirtualCurrency(AdminModels::SubtractUserVirtualCurrencyRequest& request, ProcessApiCallback<AdminModels::ModifyUserVirtualCurrencyResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UpdateBans(AdminModels::UpdateBansRequest& request, ProcessApiCallback<AdminModels::UpdateBansResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UpdateCatalogItems(AdminModels::UpdateCatalogItemsRequest& request, ProcessApiCallback<AdminModels::UpdateCatalogItemsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UpdateCloudScript(AdminModels::UpdateCloudScriptRequest& request, ProcessApiCallback<AdminModels::UpdateCloudScriptResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UpdatePlayerSharedSecret(AdminModels::UpdatePlayerSharedSecretRequest& request, ProcessApiCallback<AdminModels::UpdatePlayerSharedSecretResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UpdatePlayerStatisticDefinition(AdminModels::UpdatePlayerStatisticDefinitionRequest& request, ProcessApiCallback<AdminModels::UpdatePlayerStatisticDefinitionResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UpdatePolicy(AdminModels::UpdatePolicyRequest& request, ProcessApiCallback<AdminModels::UpdatePolicyResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UpdateRandomResultTables(AdminModels::UpdateRandomResultTablesRequest& request, ProcessApiCallback<AdminModels::UpdateRandomResultTablesResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UpdateStoreItems(AdminModels::UpdateStoreItemsRequest& request, ProcessApiCallback<AdminModels::UpdateStoreItemsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UpdateTask(AdminModels::UpdateTaskRequest& request, ProcessApiCallback<AdminModels::EmptyResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UpdateUserData(AdminModels::UpdateUserDataRequest& request, ProcessApiCallback<AdminModels::UpdateUserDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UpdateUserInternalData(AdminModels::UpdateUserInternalDataRequest& request, ProcessApiCallback<AdminModels::UpdateUserDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UpdateUserPublisherData(AdminModels::UpdateUserDataRequest& request, ProcessApiCallback<AdminModels::UpdateUserDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UpdateUserPublisherInternalData(AdminModels::UpdateUserInternalDataRequest& request, ProcessApiCallback<AdminModels::UpdateUserDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UpdateUserPublisherReadOnlyData(AdminModels::UpdateUserDataRequest& request, ProcessApiCallback<AdminModels::UpdateUserDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UpdateUserReadOnlyData(AdminModels::UpdateUserDataRequest& request, ProcessApiCallback<AdminModels::UpdateUserDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UpdateUserTitleDisplayName(AdminModels::UpdateUserTitleDisplayNameRequest& request, ProcessApiCallback<AdminModels::UpdateUserTitleDisplayNameResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);

    private:
        PlayFabAdminAPI(); // Private constructor, static class should never have an instance
        PlayFabAdminAPI(const PlayFabAdminAPI& other); // Private copy-constructor, static class should never have an instance

        // ------------ Generated result handlers
        static void OnAbortTaskInstanceResult(CallRequestContainer& request);
        static void OnAddNewsResult(CallRequestContainer& request);
        static void OnAddPlayerTagResult(CallRequestContainer& request);
        static void OnAddServerBuildResult(CallRequestContainer& request);
        static void OnAddUserVirtualCurrencyResult(CallRequestContainer& request);
        static void OnAddVirtualCurrencyTypesResult(CallRequestContainer& request);
        static void OnBanUsersResult(CallRequestContainer& request);
        static void OnCheckLimitedEditionItemAvailabilityResult(CallRequestContainer& request);
        static void OnCreateActionsOnPlayersInSegmentTaskResult(CallRequestContainer& request);
        static void OnCreateCloudScriptTaskResult(CallRequestContainer& request);
        static void OnCreatePlayerSharedSecretResult(CallRequestContainer& request);
        static void OnCreatePlayerStatisticDefinitionResult(CallRequestContainer& request);
        static void OnDeleteContentResult(CallRequestContainer& request);
        static void OnDeleteMasterPlayerAccountResult(CallRequestContainer& request);
        static void OnDeletePlayerResult(CallRequestContainer& request);
        static void OnDeletePlayerSharedSecretResult(CallRequestContainer& request);
        static void OnDeleteStoreResult(CallRequestContainer& request);
        static void OnDeleteTaskResult(CallRequestContainer& request);
        static void OnDeleteTitleResult(CallRequestContainer& request);
        static void OnExportMasterPlayerDataResult(CallRequestContainer& request);
        static void OnGetActionsOnPlayersInSegmentTaskInstanceResult(CallRequestContainer& request);
        static void OnGetAllSegmentsResult(CallRequestContainer& request);
        static void OnGetCatalogItemsResult(CallRequestContainer& request);
        static void OnGetCloudScriptRevisionResult(CallRequestContainer& request);
        static void OnGetCloudScriptTaskInstanceResult(CallRequestContainer& request);
        static void OnGetCloudScriptVersionsResult(CallRequestContainer& request);
        static void OnGetContentListResult(CallRequestContainer& request);
        static void OnGetContentUploadUrlResult(CallRequestContainer& request);
        static void OnGetDataReportResult(CallRequestContainer& request);
        static void OnGetMatchmakerGameInfoResult(CallRequestContainer& request);
        static void OnGetMatchmakerGameModesResult(CallRequestContainer& request);
        static void OnGetPlayedTitleListResult(CallRequestContainer& request);
        static void OnGetPlayerIdFromAuthTokenResult(CallRequestContainer& request);
        static void OnGetPlayerProfileResult(CallRequestContainer& request);
        static void OnGetPlayerSegmentsResult(CallRequestContainer& request);
        static void OnGetPlayerSharedSecretsResult(CallRequestContainer& request);
        static void OnGetPlayersInSegmentResult(CallRequestContainer& request);
        static void OnGetPlayerStatisticDefinitionsResult(CallRequestContainer& request);
        static void OnGetPlayerStatisticVersionsResult(CallRequestContainer& request);
        static void OnGetPlayerTagsResult(CallRequestContainer& request);
        static void OnGetPolicyResult(CallRequestContainer& request);
        static void OnGetPublisherDataResult(CallRequestContainer& request);
        static void OnGetRandomResultTablesResult(CallRequestContainer& request);
        static void OnGetServerBuildInfoResult(CallRequestContainer& request);
        static void OnGetServerBuildUploadUrlResult(CallRequestContainer& request);
        static void OnGetStoreItemsResult(CallRequestContainer& request);
        static void OnGetTaskInstancesResult(CallRequestContainer& request);
        static void OnGetTasksResult(CallRequestContainer& request);
        static void OnGetTitleDataResult(CallRequestContainer& request);
        static void OnGetTitleInternalDataResult(CallRequestContainer& request);
        static void OnGetUserAccountInfoResult(CallRequestContainer& request);
        static void OnGetUserBansResult(CallRequestContainer& request);
        static void OnGetUserDataResult(CallRequestContainer& request);
        static void OnGetUserInternalDataResult(CallRequestContainer& request);
        static void OnGetUserInventoryResult(CallRequestContainer& request);
        static void OnGetUserPublisherDataResult(CallRequestContainer& request);
        static void OnGetUserPublisherInternalDataResult(CallRequestContainer& request);
        static void OnGetUserPublisherReadOnlyDataResult(CallRequestContainer& request);
        static void OnGetUserReadOnlyDataResult(CallRequestContainer& request);
        static void OnGrantItemsToUsersResult(CallRequestContainer& request);
        static void OnIncrementLimitedEditionItemAvailabilityResult(CallRequestContainer& request);
        static void OnIncrementPlayerStatisticVersionResult(CallRequestContainer& request);
        static void OnListServerBuildsResult(CallRequestContainer& request);
        static void OnListVirtualCurrencyTypesResult(CallRequestContainer& request);
        static void OnModifyMatchmakerGameModesResult(CallRequestContainer& request);
        static void OnModifyServerBuildResult(CallRequestContainer& request);
        static void OnRefundPurchaseResult(CallRequestContainer& request);
        static void OnRemovePlayerTagResult(CallRequestContainer& request);
        static void OnRemoveServerBuildResult(CallRequestContainer& request);
        static void OnRemoveVirtualCurrencyTypesResult(CallRequestContainer& request);
        static void OnResetCharacterStatisticsResult(CallRequestContainer& request);
        static void OnResetPasswordResult(CallRequestContainer& request);
        static void OnResetUserStatisticsResult(CallRequestContainer& request);
        static void OnResolvePurchaseDisputeResult(CallRequestContainer& request);
        static void OnRevokeAllBansForUserResult(CallRequestContainer& request);
        static void OnRevokeBansResult(CallRequestContainer& request);
        static void OnRevokeInventoryItemResult(CallRequestContainer& request);
        static void OnRevokeInventoryItemsResult(CallRequestContainer& request);
        static void OnRunTaskResult(CallRequestContainer& request);
        static void OnSendAccountRecoveryEmailResult(CallRequestContainer& request);
        static void OnSetCatalogItemsResult(CallRequestContainer& request);
        static void OnSetPlayerSecretResult(CallRequestContainer& request);
        static void OnSetPublishedRevisionResult(CallRequestContainer& request);
        static void OnSetPublisherDataResult(CallRequestContainer& request);
        static void OnSetStoreItemsResult(CallRequestContainer& request);
        static void OnSetTitleDataResult(CallRequestContainer& request);
        static void OnSetTitleInternalDataResult(CallRequestContainer& request);
        static void OnSetupPushNotificationResult(CallRequestContainer& request);
        static void OnSubtractUserVirtualCurrencyResult(CallRequestContainer& request);
        static void OnUpdateBansResult(CallRequestContainer& request);
        static void OnUpdateCatalogItemsResult(CallRequestContainer& request);
        static void OnUpdateCloudScriptResult(CallRequestContainer& request);
        static void OnUpdatePlayerSharedSecretResult(CallRequestContainer& request);
        static void OnUpdatePlayerStatisticDefinitionResult(CallRequestContainer& request);
        static void OnUpdatePolicyResult(CallRequestContainer& request);
        static void OnUpdateRandomResultTablesResult(CallRequestContainer& request);
        static void OnUpdateStoreItemsResult(CallRequestContainer& request);
        static void OnUpdateTaskResult(CallRequestContainer& request);
        static void OnUpdateUserDataResult(CallRequestContainer& request);
        static void OnUpdateUserInternalDataResult(CallRequestContainer& request);
        static void OnUpdateUserPublisherDataResult(CallRequestContainer& request);
        static void OnUpdateUserPublisherInternalDataResult(CallRequestContainer& request);
        static void OnUpdateUserPublisherReadOnlyDataResult(CallRequestContainer& request);
        static void OnUpdateUserReadOnlyDataResult(CallRequestContainer& request);
        static void OnUpdateUserTitleDisplayNameResult(CallRequestContainer& request);

    };
}

#endif
