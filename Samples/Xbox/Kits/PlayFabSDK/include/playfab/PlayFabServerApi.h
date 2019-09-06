#pragma once

#ifdef ENABLE_PLAYFABSERVER_API

#include "playfab/PlayFabHttp.h"
#include "playfab/PlayFabServerDataModels.h"

namespace PlayFab
{
    /// <summary>
    /// Main interface for PlayFab Sdk, specifically all Server APIs
    /// </summary>
    class PlayFabServerAPI
    {
    public:
        static size_t Update();
        static void ForgetAllCredentials();


        // ------------ Generated API calls
        static void AddCharacterVirtualCurrency(ServerModels::AddCharacterVirtualCurrencyRequest& request, ProcessApiCallback<ServerModels::ModifyCharacterVirtualCurrencyResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void AddFriend(ServerModels::AddFriendRequest& request, ProcessApiCallback<ServerModels::EmptyResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void AddPlayerTag(ServerModels::AddPlayerTagRequest& request, ProcessApiCallback<ServerModels::AddPlayerTagResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void AddSharedGroupMembers(ServerModels::AddSharedGroupMembersRequest& request, ProcessApiCallback<ServerModels::AddSharedGroupMembersResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void AddUserVirtualCurrency(ServerModels::AddUserVirtualCurrencyRequest& request, ProcessApiCallback<ServerModels::ModifyUserVirtualCurrencyResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void AuthenticateSessionTicket(ServerModels::AuthenticateSessionTicketRequest& request, ProcessApiCallback<ServerModels::AuthenticateSessionTicketResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void AwardSteamAchievement(ServerModels::AwardSteamAchievementRequest& request, ProcessApiCallback<ServerModels::AwardSteamAchievementResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void BanUsers(ServerModels::BanUsersRequest& request, ProcessApiCallback<ServerModels::BanUsersResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void ConsumeItem(ServerModels::ConsumeItemRequest& request, ProcessApiCallback<ServerModels::ConsumeItemResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void CreateSharedGroup(ServerModels::CreateSharedGroupRequest& request, ProcessApiCallback<ServerModels::CreateSharedGroupResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void DeleteCharacterFromUser(ServerModels::DeleteCharacterFromUserRequest& request, ProcessApiCallback<ServerModels::DeleteCharacterFromUserResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void DeleteSharedGroup(ServerModels::DeleteSharedGroupRequest& request, ProcessApiCallback<ServerModels::EmptyResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void DeleteUsers(ServerModels::DeleteUsersRequest& request, ProcessApiCallback<ServerModels::DeleteUsersResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void DeregisterGame(ServerModels::DeregisterGameRequest& request, ProcessApiCallback<ServerModels::DeregisterGameResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void EvaluateRandomResultTable(ServerModels::EvaluateRandomResultTableRequest& request, ProcessApiCallback<ServerModels::EvaluateRandomResultTableResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void ExecuteCloudScript(ServerModels::ExecuteCloudScriptServerRequest& request, ProcessApiCallback<ServerModels::ExecuteCloudScriptResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetAllSegments(ServerModels::GetAllSegmentsRequest& request, ProcessApiCallback<ServerModels::GetAllSegmentsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetAllUsersCharacters(ServerModels::ListUsersCharactersRequest& request, ProcessApiCallback<ServerModels::ListUsersCharactersResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetCatalogItems(ServerModels::GetCatalogItemsRequest& request, ProcessApiCallback<ServerModels::GetCatalogItemsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetCharacterData(ServerModels::GetCharacterDataRequest& request, ProcessApiCallback<ServerModels::GetCharacterDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetCharacterInternalData(ServerModels::GetCharacterDataRequest& request, ProcessApiCallback<ServerModels::GetCharacterDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetCharacterInventory(ServerModels::GetCharacterInventoryRequest& request, ProcessApiCallback<ServerModels::GetCharacterInventoryResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetCharacterLeaderboard(ServerModels::GetCharacterLeaderboardRequest& request, ProcessApiCallback<ServerModels::GetCharacterLeaderboardResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetCharacterReadOnlyData(ServerModels::GetCharacterDataRequest& request, ProcessApiCallback<ServerModels::GetCharacterDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetCharacterStatistics(ServerModels::GetCharacterStatisticsRequest& request, ProcessApiCallback<ServerModels::GetCharacterStatisticsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetContentDownloadUrl(ServerModels::GetContentDownloadUrlRequest& request, ProcessApiCallback<ServerModels::GetContentDownloadUrlResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetFriendLeaderboard(ServerModels::GetFriendLeaderboardRequest& request, ProcessApiCallback<ServerModels::GetLeaderboardResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetFriendsList(ServerModels::GetFriendsListRequest& request, ProcessApiCallback<ServerModels::GetFriendsListResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetLeaderboard(ServerModels::GetLeaderboardRequest& request, ProcessApiCallback<ServerModels::GetLeaderboardResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetLeaderboardAroundCharacter(ServerModels::GetLeaderboardAroundCharacterRequest& request, ProcessApiCallback<ServerModels::GetLeaderboardAroundCharacterResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetLeaderboardAroundUser(ServerModels::GetLeaderboardAroundUserRequest& request, ProcessApiCallback<ServerModels::GetLeaderboardAroundUserResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetLeaderboardForUserCharacters(ServerModels::GetLeaderboardForUsersCharactersRequest& request, ProcessApiCallback<ServerModels::GetLeaderboardForUsersCharactersResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetPlayerCombinedInfo(ServerModels::GetPlayerCombinedInfoRequest& request, ProcessApiCallback<ServerModels::GetPlayerCombinedInfoResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetPlayerProfile(ServerModels::GetPlayerProfileRequest& request, ProcessApiCallback<ServerModels::GetPlayerProfileResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetPlayerSegments(ServerModels::GetPlayersSegmentsRequest& request, ProcessApiCallback<ServerModels::GetPlayerSegmentsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetPlayersInSegment(ServerModels::GetPlayersInSegmentRequest& request, ProcessApiCallback<ServerModels::GetPlayersInSegmentResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetPlayerStatistics(ServerModels::GetPlayerStatisticsRequest& request, ProcessApiCallback<ServerModels::GetPlayerStatisticsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetPlayerStatisticVersions(ServerModels::GetPlayerStatisticVersionsRequest& request, ProcessApiCallback<ServerModels::GetPlayerStatisticVersionsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetPlayerTags(ServerModels::GetPlayerTagsRequest& request, ProcessApiCallback<ServerModels::GetPlayerTagsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetPlayFabIDsFromFacebookIDs(ServerModels::GetPlayFabIDsFromFacebookIDsRequest& request, ProcessApiCallback<ServerModels::GetPlayFabIDsFromFacebookIDsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetPlayFabIDsFromFacebookInstantGamesIds(ServerModels::GetPlayFabIDsFromFacebookInstantGamesIdsRequest& request, ProcessApiCallback<ServerModels::GetPlayFabIDsFromFacebookInstantGamesIdsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetPlayFabIDsFromNintendoSwitchDeviceIds(ServerModels::GetPlayFabIDsFromNintendoSwitchDeviceIdsRequest& request, ProcessApiCallback<ServerModels::GetPlayFabIDsFromNintendoSwitchDeviceIdsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetPlayFabIDsFromSteamIDs(ServerModels::GetPlayFabIDsFromSteamIDsRequest& request, ProcessApiCallback<ServerModels::GetPlayFabIDsFromSteamIDsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetPublisherData(ServerModels::GetPublisherDataRequest& request, ProcessApiCallback<ServerModels::GetPublisherDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetRandomResultTables(ServerModels::GetRandomResultTablesRequest& request, ProcessApiCallback<ServerModels::GetRandomResultTablesResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetSharedGroupData(ServerModels::GetSharedGroupDataRequest& request, ProcessApiCallback<ServerModels::GetSharedGroupDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetTime(ServerModels::GetTimeRequest& request, ProcessApiCallback<ServerModels::GetTimeResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetTitleData(ServerModels::GetTitleDataRequest& request, ProcessApiCallback<ServerModels::GetTitleDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetTitleInternalData(ServerModels::GetTitleDataRequest& request, ProcessApiCallback<ServerModels::GetTitleDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetTitleNews(ServerModels::GetTitleNewsRequest& request, ProcessApiCallback<ServerModels::GetTitleNewsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetUserAccountInfo(ServerModels::GetUserAccountInfoRequest& request, ProcessApiCallback<ServerModels::GetUserAccountInfoResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetUserBans(ServerModels::GetUserBansRequest& request, ProcessApiCallback<ServerModels::GetUserBansResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetUserData(ServerModels::GetUserDataRequest& request, ProcessApiCallback<ServerModels::GetUserDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetUserInternalData(ServerModels::GetUserDataRequest& request, ProcessApiCallback<ServerModels::GetUserDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetUserInventory(ServerModels::GetUserInventoryRequest& request, ProcessApiCallback<ServerModels::GetUserInventoryResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetUserPublisherData(ServerModels::GetUserDataRequest& request, ProcessApiCallback<ServerModels::GetUserDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetUserPublisherInternalData(ServerModels::GetUserDataRequest& request, ProcessApiCallback<ServerModels::GetUserDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetUserPublisherReadOnlyData(ServerModels::GetUserDataRequest& request, ProcessApiCallback<ServerModels::GetUserDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetUserReadOnlyData(ServerModels::GetUserDataRequest& request, ProcessApiCallback<ServerModels::GetUserDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GrantCharacterToUser(ServerModels::GrantCharacterToUserRequest& request, ProcessApiCallback<ServerModels::GrantCharacterToUserResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GrantItemsToCharacter(ServerModels::GrantItemsToCharacterRequest& request, ProcessApiCallback<ServerModels::GrantItemsToCharacterResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GrantItemsToUser(ServerModels::GrantItemsToUserRequest& request, ProcessApiCallback<ServerModels::GrantItemsToUserResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GrantItemsToUsers(ServerModels::GrantItemsToUsersRequest& request, ProcessApiCallback<ServerModels::GrantItemsToUsersResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void ModifyItemUses(ServerModels::ModifyItemUsesRequest& request, ProcessApiCallback<ServerModels::ModifyItemUsesResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void MoveItemToCharacterFromCharacter(ServerModels::MoveItemToCharacterFromCharacterRequest& request, ProcessApiCallback<ServerModels::MoveItemToCharacterFromCharacterResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void MoveItemToCharacterFromUser(ServerModels::MoveItemToCharacterFromUserRequest& request, ProcessApiCallback<ServerModels::MoveItemToCharacterFromUserResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void MoveItemToUserFromCharacter(ServerModels::MoveItemToUserFromCharacterRequest& request, ProcessApiCallback<ServerModels::MoveItemToUserFromCharacterResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void NotifyMatchmakerPlayerLeft(ServerModels::NotifyMatchmakerPlayerLeftRequest& request, ProcessApiCallback<ServerModels::NotifyMatchmakerPlayerLeftResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void RedeemCoupon(ServerModels::RedeemCouponRequest& request, ProcessApiCallback<ServerModels::RedeemCouponResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void RedeemMatchmakerTicket(ServerModels::RedeemMatchmakerTicketRequest& request, ProcessApiCallback<ServerModels::RedeemMatchmakerTicketResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void RefreshGameServerInstanceHeartbeat(ServerModels::RefreshGameServerInstanceHeartbeatRequest& request, ProcessApiCallback<ServerModels::RefreshGameServerInstanceHeartbeatResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void RegisterGame(ServerModels::RegisterGameRequest& request, ProcessApiCallback<ServerModels::RegisterGameResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void RemoveFriend(ServerModels::RemoveFriendRequest& request, ProcessApiCallback<ServerModels::EmptyResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void RemovePlayerTag(ServerModels::RemovePlayerTagRequest& request, ProcessApiCallback<ServerModels::RemovePlayerTagResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void RemoveSharedGroupMembers(ServerModels::RemoveSharedGroupMembersRequest& request, ProcessApiCallback<ServerModels::RemoveSharedGroupMembersResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void ReportPlayer(ServerModels::ReportPlayerServerRequest& request, ProcessApiCallback<ServerModels::ReportPlayerServerResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void RevokeAllBansForUser(ServerModels::RevokeAllBansForUserRequest& request, ProcessApiCallback<ServerModels::RevokeAllBansForUserResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void RevokeBans(ServerModels::RevokeBansRequest& request, ProcessApiCallback<ServerModels::RevokeBansResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void RevokeInventoryItem(ServerModels::RevokeInventoryItemRequest& request, ProcessApiCallback<ServerModels::RevokeInventoryResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void RevokeInventoryItems(ServerModels::RevokeInventoryItemsRequest& request, ProcessApiCallback<ServerModels::RevokeInventoryItemsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void SendCustomAccountRecoveryEmail(ServerModels::SendCustomAccountRecoveryEmailRequest& request, ProcessApiCallback<ServerModels::SendCustomAccountRecoveryEmailResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void SendEmailFromTemplate(ServerModels::SendEmailFromTemplateRequest& request, ProcessApiCallback<ServerModels::SendEmailFromTemplateResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void SendPushNotification(ServerModels::SendPushNotificationRequest& request, ProcessApiCallback<ServerModels::SendPushNotificationResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void SetFriendTags(ServerModels::SetFriendTagsRequest& request, ProcessApiCallback<ServerModels::EmptyResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void SetGameServerInstanceData(ServerModels::SetGameServerInstanceDataRequest& request, ProcessApiCallback<ServerModels::SetGameServerInstanceDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void SetGameServerInstanceState(ServerModels::SetGameServerInstanceStateRequest& request, ProcessApiCallback<ServerModels::SetGameServerInstanceStateResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void SetGameServerInstanceTags(ServerModels::SetGameServerInstanceTagsRequest& request, ProcessApiCallback<ServerModels::SetGameServerInstanceTagsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void SetPlayerSecret(ServerModels::SetPlayerSecretRequest& request, ProcessApiCallback<ServerModels::SetPlayerSecretResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void SetPublisherData(ServerModels::SetPublisherDataRequest& request, ProcessApiCallback<ServerModels::SetPublisherDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void SetTitleData(ServerModels::SetTitleDataRequest& request, ProcessApiCallback<ServerModels::SetTitleDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void SetTitleInternalData(ServerModels::SetTitleDataRequest& request, ProcessApiCallback<ServerModels::SetTitleDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void SubtractCharacterVirtualCurrency(ServerModels::SubtractCharacterVirtualCurrencyRequest& request, ProcessApiCallback<ServerModels::ModifyCharacterVirtualCurrencyResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void SubtractUserVirtualCurrency(ServerModels::SubtractUserVirtualCurrencyRequest& request, ProcessApiCallback<ServerModels::ModifyUserVirtualCurrencyResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UnlockContainerInstance(ServerModels::UnlockContainerInstanceRequest& request, ProcessApiCallback<ServerModels::UnlockContainerItemResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UnlockContainerItem(ServerModels::UnlockContainerItemRequest& request, ProcessApiCallback<ServerModels::UnlockContainerItemResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UpdateAvatarUrl(ServerModels::UpdateAvatarUrlRequest& request, ProcessApiCallback<ServerModels::EmptyResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UpdateBans(ServerModels::UpdateBansRequest& request, ProcessApiCallback<ServerModels::UpdateBansResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UpdateCharacterData(ServerModels::UpdateCharacterDataRequest& request, ProcessApiCallback<ServerModels::UpdateCharacterDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UpdateCharacterInternalData(ServerModels::UpdateCharacterDataRequest& request, ProcessApiCallback<ServerModels::UpdateCharacterDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UpdateCharacterReadOnlyData(ServerModels::UpdateCharacterDataRequest& request, ProcessApiCallback<ServerModels::UpdateCharacterDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UpdateCharacterStatistics(ServerModels::UpdateCharacterStatisticsRequest& request, ProcessApiCallback<ServerModels::UpdateCharacterStatisticsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UpdatePlayerStatistics(ServerModels::UpdatePlayerStatisticsRequest& request, ProcessApiCallback<ServerModels::UpdatePlayerStatisticsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UpdateSharedGroupData(ServerModels::UpdateSharedGroupDataRequest& request, ProcessApiCallback<ServerModels::UpdateSharedGroupDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UpdateUserData(ServerModels::UpdateUserDataRequest& request, ProcessApiCallback<ServerModels::UpdateUserDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UpdateUserInternalData(ServerModels::UpdateUserInternalDataRequest& request, ProcessApiCallback<ServerModels::UpdateUserDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UpdateUserInventoryItemCustomData(ServerModels::UpdateUserInventoryItemDataRequest& request, ProcessApiCallback<ServerModels::EmptyResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UpdateUserPublisherData(ServerModels::UpdateUserDataRequest& request, ProcessApiCallback<ServerModels::UpdateUserDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UpdateUserPublisherInternalData(ServerModels::UpdateUserInternalDataRequest& request, ProcessApiCallback<ServerModels::UpdateUserDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UpdateUserPublisherReadOnlyData(ServerModels::UpdateUserDataRequest& request, ProcessApiCallback<ServerModels::UpdateUserDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UpdateUserReadOnlyData(ServerModels::UpdateUserDataRequest& request, ProcessApiCallback<ServerModels::UpdateUserDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void WriteCharacterEvent(ServerModels::WriteServerCharacterEventRequest& request, ProcessApiCallback<ServerModels::WriteEventResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void WritePlayerEvent(ServerModels::WriteServerPlayerEventRequest& request, ProcessApiCallback<ServerModels::WriteEventResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void WriteTitleEvent(ServerModels::WriteTitleEventRequest& request, ProcessApiCallback<ServerModels::WriteEventResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);

    private:
        PlayFabServerAPI(); // Private constructor, static class should never have an instance
        PlayFabServerAPI(const PlayFabServerAPI& other); // Private copy-constructor, static class should never have an instance

        // ------------ Generated result handlers
        static void OnAddCharacterVirtualCurrencyResult(CallRequestContainer& request);
        static void OnAddFriendResult(CallRequestContainer& request);
        static void OnAddPlayerTagResult(CallRequestContainer& request);
        static void OnAddSharedGroupMembersResult(CallRequestContainer& request);
        static void OnAddUserVirtualCurrencyResult(CallRequestContainer& request);
        static void OnAuthenticateSessionTicketResult(CallRequestContainer& request);
        static void OnAwardSteamAchievementResult(CallRequestContainer& request);
        static void OnBanUsersResult(CallRequestContainer& request);
        static void OnConsumeItemResult(CallRequestContainer& request);
        static void OnCreateSharedGroupResult(CallRequestContainer& request);
        static void OnDeleteCharacterFromUserResult(CallRequestContainer& request);
        static void OnDeleteSharedGroupResult(CallRequestContainer& request);
        static void OnDeleteUsersResult(CallRequestContainer& request);
        static void OnDeregisterGameResult(CallRequestContainer& request);
        static void OnEvaluateRandomResultTableResult(CallRequestContainer& request);
        static void OnExecuteCloudScriptResult(CallRequestContainer& request);
        static void OnGetAllSegmentsResult(CallRequestContainer& request);
        static void OnGetAllUsersCharactersResult(CallRequestContainer& request);
        static void OnGetCatalogItemsResult(CallRequestContainer& request);
        static void OnGetCharacterDataResult(CallRequestContainer& request);
        static void OnGetCharacterInternalDataResult(CallRequestContainer& request);
        static void OnGetCharacterInventoryResult(CallRequestContainer& request);
        static void OnGetCharacterLeaderboardResult(CallRequestContainer& request);
        static void OnGetCharacterReadOnlyDataResult(CallRequestContainer& request);
        static void OnGetCharacterStatisticsResult(CallRequestContainer& request);
        static void OnGetContentDownloadUrlResult(CallRequestContainer& request);
        static void OnGetFriendLeaderboardResult(CallRequestContainer& request);
        static void OnGetFriendsListResult(CallRequestContainer& request);
        static void OnGetLeaderboardResult(CallRequestContainer& request);
        static void OnGetLeaderboardAroundCharacterResult(CallRequestContainer& request);
        static void OnGetLeaderboardAroundUserResult(CallRequestContainer& request);
        static void OnGetLeaderboardForUserCharactersResult(CallRequestContainer& request);
        static void OnGetPlayerCombinedInfoResult(CallRequestContainer& request);
        static void OnGetPlayerProfileResult(CallRequestContainer& request);
        static void OnGetPlayerSegmentsResult(CallRequestContainer& request);
        static void OnGetPlayersInSegmentResult(CallRequestContainer& request);
        static void OnGetPlayerStatisticsResult(CallRequestContainer& request);
        static void OnGetPlayerStatisticVersionsResult(CallRequestContainer& request);
        static void OnGetPlayerTagsResult(CallRequestContainer& request);
        static void OnGetPlayFabIDsFromFacebookIDsResult(CallRequestContainer& request);
        static void OnGetPlayFabIDsFromFacebookInstantGamesIdsResult(CallRequestContainer& request);
        static void OnGetPlayFabIDsFromNintendoSwitchDeviceIdsResult(CallRequestContainer& request);
        static void OnGetPlayFabIDsFromSteamIDsResult(CallRequestContainer& request);
        static void OnGetPublisherDataResult(CallRequestContainer& request);
        static void OnGetRandomResultTablesResult(CallRequestContainer& request);
        static void OnGetSharedGroupDataResult(CallRequestContainer& request);
        static void OnGetTimeResult(CallRequestContainer& request);
        static void OnGetTitleDataResult(CallRequestContainer& request);
        static void OnGetTitleInternalDataResult(CallRequestContainer& request);
        static void OnGetTitleNewsResult(CallRequestContainer& request);
        static void OnGetUserAccountInfoResult(CallRequestContainer& request);
        static void OnGetUserBansResult(CallRequestContainer& request);
        static void OnGetUserDataResult(CallRequestContainer& request);
        static void OnGetUserInternalDataResult(CallRequestContainer& request);
        static void OnGetUserInventoryResult(CallRequestContainer& request);
        static void OnGetUserPublisherDataResult(CallRequestContainer& request);
        static void OnGetUserPublisherInternalDataResult(CallRequestContainer& request);
        static void OnGetUserPublisherReadOnlyDataResult(CallRequestContainer& request);
        static void OnGetUserReadOnlyDataResult(CallRequestContainer& request);
        static void OnGrantCharacterToUserResult(CallRequestContainer& request);
        static void OnGrantItemsToCharacterResult(CallRequestContainer& request);
        static void OnGrantItemsToUserResult(CallRequestContainer& request);
        static void OnGrantItemsToUsersResult(CallRequestContainer& request);
        static void OnModifyItemUsesResult(CallRequestContainer& request);
        static void OnMoveItemToCharacterFromCharacterResult(CallRequestContainer& request);
        static void OnMoveItemToCharacterFromUserResult(CallRequestContainer& request);
        static void OnMoveItemToUserFromCharacterResult(CallRequestContainer& request);
        static void OnNotifyMatchmakerPlayerLeftResult(CallRequestContainer& request);
        static void OnRedeemCouponResult(CallRequestContainer& request);
        static void OnRedeemMatchmakerTicketResult(CallRequestContainer& request);
        static void OnRefreshGameServerInstanceHeartbeatResult(CallRequestContainer& request);
        static void OnRegisterGameResult(CallRequestContainer& request);
        static void OnRemoveFriendResult(CallRequestContainer& request);
        static void OnRemovePlayerTagResult(CallRequestContainer& request);
        static void OnRemoveSharedGroupMembersResult(CallRequestContainer& request);
        static void OnReportPlayerResult(CallRequestContainer& request);
        static void OnRevokeAllBansForUserResult(CallRequestContainer& request);
        static void OnRevokeBansResult(CallRequestContainer& request);
        static void OnRevokeInventoryItemResult(CallRequestContainer& request);
        static void OnRevokeInventoryItemsResult(CallRequestContainer& request);
        static void OnSendCustomAccountRecoveryEmailResult(CallRequestContainer& request);
        static void OnSendEmailFromTemplateResult(CallRequestContainer& request);
        static void OnSendPushNotificationResult(CallRequestContainer& request);
        static void OnSetFriendTagsResult(CallRequestContainer& request);
        static void OnSetGameServerInstanceDataResult(CallRequestContainer& request);
        static void OnSetGameServerInstanceStateResult(CallRequestContainer& request);
        static void OnSetGameServerInstanceTagsResult(CallRequestContainer& request);
        static void OnSetPlayerSecretResult(CallRequestContainer& request);
        static void OnSetPublisherDataResult(CallRequestContainer& request);
        static void OnSetTitleDataResult(CallRequestContainer& request);
        static void OnSetTitleInternalDataResult(CallRequestContainer& request);
        static void OnSubtractCharacterVirtualCurrencyResult(CallRequestContainer& request);
        static void OnSubtractUserVirtualCurrencyResult(CallRequestContainer& request);
        static void OnUnlockContainerInstanceResult(CallRequestContainer& request);
        static void OnUnlockContainerItemResult(CallRequestContainer& request);
        static void OnUpdateAvatarUrlResult(CallRequestContainer& request);
        static void OnUpdateBansResult(CallRequestContainer& request);
        static void OnUpdateCharacterDataResult(CallRequestContainer& request);
        static void OnUpdateCharacterInternalDataResult(CallRequestContainer& request);
        static void OnUpdateCharacterReadOnlyDataResult(CallRequestContainer& request);
        static void OnUpdateCharacterStatisticsResult(CallRequestContainer& request);
        static void OnUpdatePlayerStatisticsResult(CallRequestContainer& request);
        static void OnUpdateSharedGroupDataResult(CallRequestContainer& request);
        static void OnUpdateUserDataResult(CallRequestContainer& request);
        static void OnUpdateUserInternalDataResult(CallRequestContainer& request);
        static void OnUpdateUserInventoryItemCustomDataResult(CallRequestContainer& request);
        static void OnUpdateUserPublisherDataResult(CallRequestContainer& request);
        static void OnUpdateUserPublisherInternalDataResult(CallRequestContainer& request);
        static void OnUpdateUserPublisherReadOnlyDataResult(CallRequestContainer& request);
        static void OnUpdateUserReadOnlyDataResult(CallRequestContainer& request);
        static void OnWriteCharacterEventResult(CallRequestContainer& request);
        static void OnWritePlayerEventResult(CallRequestContainer& request);
        static void OnWriteTitleEventResult(CallRequestContainer& request);

    };
}

#endif
