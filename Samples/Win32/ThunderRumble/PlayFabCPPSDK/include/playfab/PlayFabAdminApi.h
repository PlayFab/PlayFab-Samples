#pragma once

#ifdef ENABLE_PLAYFABADMIN_API

#include <playfab/PlayFabCallRequestContainer.h>
#include <playfab/PlayFabHttp.h>
#include <playfab/PlayFabAdminDataModels.h>

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
        static void AbortTaskInstance(AdminModels::AbortTaskInstanceRequest& request, ProcessApiCallback<AdminModels::EmptyResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
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
        static void DeleteTask(AdminModels::DeleteTaskRequest& request, ProcessApiCallback<AdminModels::EmptyResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
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
        static void UpdateTask(AdminModels::UpdateTaskRequest& request, ProcessApiCallback<AdminModels::EmptyResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
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
        static void OnAbortTaskInstanceResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnAddNewsResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnAddPlayerTagResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnAddServerBuildResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnAddUserVirtualCurrencyResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnAddVirtualCurrencyTypesResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnBanUsersResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnCheckLimitedEditionItemAvailabilityResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnCreateActionsOnPlayersInSegmentTaskResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnCreateCloudScriptTaskResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnCreatePlayerSharedSecretResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnCreatePlayerStatisticDefinitionResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnDeleteContentResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnDeleteMasterPlayerAccountResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnDeletePlayerResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnDeletePlayerSharedSecretResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnDeleteStoreResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnDeleteTaskResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnDeleteTitleResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnExportMasterPlayerDataResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnGetActionsOnPlayersInSegmentTaskInstanceResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnGetAllSegmentsResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnGetCatalogItemsResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnGetCloudScriptRevisionResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnGetCloudScriptTaskInstanceResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnGetCloudScriptVersionsResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnGetContentListResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnGetContentUploadUrlResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnGetDataReportResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnGetMatchmakerGameInfoResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnGetMatchmakerGameModesResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnGetPlayedTitleListResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnGetPlayerIdFromAuthTokenResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnGetPlayerProfileResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnGetPlayerSegmentsResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnGetPlayerSharedSecretsResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnGetPlayersInSegmentResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnGetPlayerStatisticDefinitionsResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnGetPlayerStatisticVersionsResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnGetPlayerTagsResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnGetPolicyResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnGetPublisherDataResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnGetRandomResultTablesResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnGetServerBuildInfoResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnGetServerBuildUploadUrlResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnGetStoreItemsResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnGetTaskInstancesResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnGetTasksResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnGetTitleDataResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnGetTitleInternalDataResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnGetUserAccountInfoResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnGetUserBansResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnGetUserDataResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnGetUserInternalDataResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnGetUserInventoryResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnGetUserPublisherDataResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnGetUserPublisherInternalDataResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnGetUserPublisherReadOnlyDataResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnGetUserReadOnlyDataResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnGrantItemsToUsersResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnIncrementLimitedEditionItemAvailabilityResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnIncrementPlayerStatisticVersionResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnListServerBuildsResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnListVirtualCurrencyTypesResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnModifyMatchmakerGameModesResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnModifyServerBuildResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnRefundPurchaseResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnRemovePlayerTagResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnRemoveServerBuildResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnRemoveVirtualCurrencyTypesResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnResetCharacterStatisticsResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnResetPasswordResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnResetUserStatisticsResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnResolvePurchaseDisputeResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnRevokeAllBansForUserResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnRevokeBansResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnRevokeInventoryItemResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnRevokeInventoryItemsResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnRunTaskResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnSendAccountRecoveryEmailResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnSetCatalogItemsResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnSetPlayerSecretResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnSetPublishedRevisionResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnSetPublisherDataResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnSetStoreItemsResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnSetTitleDataResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnSetTitleInternalDataResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnSetupPushNotificationResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnSubtractUserVirtualCurrencyResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnUpdateBansResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnUpdateCatalogItemsResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnUpdateCloudScriptResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnUpdatePlayerSharedSecretResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnUpdatePlayerStatisticDefinitionResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnUpdatePolicyResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnUpdateRandomResultTablesResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnUpdateStoreItemsResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnUpdateTaskResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnUpdateUserDataResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnUpdateUserInternalDataResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnUpdateUserPublisherDataResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnUpdateUserPublisherInternalDataResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnUpdateUserPublisherReadOnlyDataResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnUpdateUserReadOnlyDataResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnUpdateUserTitleDisplayNameResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);

        static bool ValidateResult(PlayFabResultCommon& resultCommon, CallRequestContainer& container);
    };
}

#endif
