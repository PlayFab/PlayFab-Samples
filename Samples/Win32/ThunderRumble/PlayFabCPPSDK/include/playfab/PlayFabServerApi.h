#pragma once

#ifdef ENABLE_PLAYFABSERVER_API

#include <playfab/PlayFabCallRequestContainer.h>
#include <playfab/PlayFabHttp.h>
#include <playfab/PlayFabServerDataModels.h>

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
        static void AddFriend(ServerModels::AddFriendRequest& request, ProcessApiCallback<ServerModels::EmptyResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void AddPlayerTag(ServerModels::AddPlayerTagRequest& request, ProcessApiCallback<ServerModels::AddPlayerTagResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void AddSharedGroupMembers(ServerModels::AddSharedGroupMembersRequest& request, ProcessApiCallback<ServerModels::AddSharedGroupMembersResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void AddUserVirtualCurrency(ServerModels::AddUserVirtualCurrencyRequest& request, ProcessApiCallback<ServerModels::ModifyUserVirtualCurrencyResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void AuthenticateSessionTicket(ServerModels::AuthenticateSessionTicketRequest& request, ProcessApiCallback<ServerModels::AuthenticateSessionTicketResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void AwardSteamAchievement(ServerModels::AwardSteamAchievementRequest& request, ProcessApiCallback<ServerModels::AwardSteamAchievementResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void BanUsers(ServerModels::BanUsersRequest& request, ProcessApiCallback<ServerModels::BanUsersResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void ConsumeItem(ServerModels::ConsumeItemRequest& request, ProcessApiCallback<ServerModels::ConsumeItemResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void CreateSharedGroup(ServerModels::CreateSharedGroupRequest& request, ProcessApiCallback<ServerModels::CreateSharedGroupResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void DeleteCharacterFromUser(ServerModels::DeleteCharacterFromUserRequest& request, ProcessApiCallback<ServerModels::DeleteCharacterFromUserResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void DeletePlayer(ServerModels::DeletePlayerRequest& request, ProcessApiCallback<ServerModels::DeletePlayerResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void DeleteSharedGroup(ServerModels::DeleteSharedGroupRequest& request, ProcessApiCallback<ServerModels::EmptyResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
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
        static void GetPlayFabIDsFromXboxLiveIDs(ServerModels::GetPlayFabIDsFromXboxLiveIDsRequest& request, ProcessApiCallback<ServerModels::GetPlayFabIDsFromXboxLiveIDsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetPublisherData(ServerModels::GetPublisherDataRequest& request, ProcessApiCallback<ServerModels::GetPublisherDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetRandomResultTables(ServerModels::GetRandomResultTablesRequest& request, ProcessApiCallback<ServerModels::GetRandomResultTablesResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetServerCustomIDsFromPlayFabIDs(ServerModels::GetServerCustomIDsFromPlayFabIDsRequest& request, ProcessApiCallback<ServerModels::GetServerCustomIDsFromPlayFabIDsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
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
        static void LinkXboxAccount(ServerModels::LinkXboxAccountRequest& request, ProcessApiCallback<ServerModels::LinkXboxAccountResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void LoginWithServerCustomId(ServerModels::LoginWithServerCustomIdRequest& request, ProcessApiCallback<ServerModels::ServerLoginResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void LoginWithXbox(ServerModels::LoginWithXboxRequest& request, ProcessApiCallback<ServerModels::ServerLoginResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void ModifyItemUses(ServerModels::ModifyItemUsesRequest& request, ProcessApiCallback<ServerModels::ModifyItemUsesResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void MoveItemToCharacterFromCharacter(ServerModels::MoveItemToCharacterFromCharacterRequest& request, ProcessApiCallback<ServerModels::MoveItemToCharacterFromCharacterResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void MoveItemToCharacterFromUser(ServerModels::MoveItemToCharacterFromUserRequest& request, ProcessApiCallback<ServerModels::MoveItemToCharacterFromUserResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void MoveItemToUserFromCharacter(ServerModels::MoveItemToUserFromCharacterRequest& request, ProcessApiCallback<ServerModels::MoveItemToUserFromCharacterResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void NotifyMatchmakerPlayerLeft(ServerModels::NotifyMatchmakerPlayerLeftRequest& request, ProcessApiCallback<ServerModels::NotifyMatchmakerPlayerLeftResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void RedeemCoupon(ServerModels::RedeemCouponRequest& request, ProcessApiCallback<ServerModels::RedeemCouponResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void RedeemMatchmakerTicket(ServerModels::RedeemMatchmakerTicketRequest& request, ProcessApiCallback<ServerModels::RedeemMatchmakerTicketResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void RefreshGameServerInstanceHeartbeat(ServerModels::RefreshGameServerInstanceHeartbeatRequest& request, ProcessApiCallback<ServerModels::RefreshGameServerInstanceHeartbeatResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void RegisterGame(ServerModels::RegisterGameRequest& request, ProcessApiCallback<ServerModels::RegisterGameResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void RemoveFriend(ServerModels::RemoveFriendRequest& request, ProcessApiCallback<ServerModels::EmptyResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
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
        static void SetFriendTags(ServerModels::SetFriendTagsRequest& request, ProcessApiCallback<ServerModels::EmptyResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void SetGameServerInstanceData(ServerModels::SetGameServerInstanceDataRequest& request, ProcessApiCallback<ServerModels::SetGameServerInstanceDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void SetGameServerInstanceState(ServerModels::SetGameServerInstanceStateRequest& request, ProcessApiCallback<ServerModels::SetGameServerInstanceStateResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void SetGameServerInstanceTags(ServerModels::SetGameServerInstanceTagsRequest& request, ProcessApiCallback<ServerModels::SetGameServerInstanceTagsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void SetPlayerSecret(ServerModels::SetPlayerSecretRequest& request, ProcessApiCallback<ServerModels::SetPlayerSecretResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void SetPublisherData(ServerModels::SetPublisherDataRequest& request, ProcessApiCallback<ServerModels::SetPublisherDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void SetTitleData(ServerModels::SetTitleDataRequest& request, ProcessApiCallback<ServerModels::SetTitleDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void SetTitleInternalData(ServerModels::SetTitleDataRequest& request, ProcessApiCallback<ServerModels::SetTitleDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void SubtractCharacterVirtualCurrency(ServerModels::SubtractCharacterVirtualCurrencyRequest& request, ProcessApiCallback<ServerModels::ModifyCharacterVirtualCurrencyResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void SubtractUserVirtualCurrency(ServerModels::SubtractUserVirtualCurrencyRequest& request, ProcessApiCallback<ServerModels::ModifyUserVirtualCurrencyResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UnlinkXboxAccount(ServerModels::UnlinkXboxAccountRequest& request, ProcessApiCallback<ServerModels::UnlinkXboxAccountResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UnlockContainerInstance(ServerModels::UnlockContainerInstanceRequest& request, ProcessApiCallback<ServerModels::UnlockContainerItemResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UnlockContainerItem(ServerModels::UnlockContainerItemRequest& request, ProcessApiCallback<ServerModels::UnlockContainerItemResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UpdateAvatarUrl(ServerModels::UpdateAvatarUrlRequest& request, ProcessApiCallback<ServerModels::EmptyResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UpdateBans(ServerModels::UpdateBansRequest& request, ProcessApiCallback<ServerModels::UpdateBansResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UpdateCharacterData(ServerModels::UpdateCharacterDataRequest& request, ProcessApiCallback<ServerModels::UpdateCharacterDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UpdateCharacterInternalData(ServerModels::UpdateCharacterDataRequest& request, ProcessApiCallback<ServerModels::UpdateCharacterDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UpdateCharacterReadOnlyData(ServerModels::UpdateCharacterDataRequest& request, ProcessApiCallback<ServerModels::UpdateCharacterDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UpdateCharacterStatistics(ServerModels::UpdateCharacterStatisticsRequest& request, ProcessApiCallback<ServerModels::UpdateCharacterStatisticsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UpdatePlayerStatistics(ServerModels::UpdatePlayerStatisticsRequest& request, ProcessApiCallback<ServerModels::UpdatePlayerStatisticsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UpdateSharedGroupData(ServerModels::UpdateSharedGroupDataRequest& request, ProcessApiCallback<ServerModels::UpdateSharedGroupDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UpdateUserData(ServerModels::UpdateUserDataRequest& request, ProcessApiCallback<ServerModels::UpdateUserDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UpdateUserInternalData(ServerModels::UpdateUserInternalDataRequest& request, ProcessApiCallback<ServerModels::UpdateUserDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UpdateUserInventoryItemCustomData(ServerModels::UpdateUserInventoryItemDataRequest& request, ProcessApiCallback<ServerModels::EmptyResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
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
        static void OnAddCharacterVirtualCurrencyResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnAddFriendResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnAddPlayerTagResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnAddSharedGroupMembersResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnAddUserVirtualCurrencyResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnAuthenticateSessionTicketResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnAwardSteamAchievementResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnBanUsersResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnConsumeItemResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnCreateSharedGroupResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnDeleteCharacterFromUserResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnDeletePlayerResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnDeleteSharedGroupResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnDeregisterGameResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnEvaluateRandomResultTableResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnExecuteCloudScriptResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnGetAllSegmentsResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnGetAllUsersCharactersResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnGetCatalogItemsResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnGetCharacterDataResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnGetCharacterInternalDataResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnGetCharacterInventoryResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnGetCharacterLeaderboardResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnGetCharacterReadOnlyDataResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnGetCharacterStatisticsResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnGetContentDownloadUrlResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnGetFriendLeaderboardResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnGetFriendsListResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnGetLeaderboardResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnGetLeaderboardAroundCharacterResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnGetLeaderboardAroundUserResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnGetLeaderboardForUserCharactersResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnGetPlayerCombinedInfoResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnGetPlayerProfileResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnGetPlayerSegmentsResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnGetPlayersInSegmentResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnGetPlayerStatisticsResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnGetPlayerStatisticVersionsResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnGetPlayerTagsResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnGetPlayFabIDsFromFacebookIDsResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnGetPlayFabIDsFromFacebookInstantGamesIdsResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnGetPlayFabIDsFromNintendoSwitchDeviceIdsResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnGetPlayFabIDsFromSteamIDsResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnGetPlayFabIDsFromXboxLiveIDsResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnGetPublisherDataResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnGetRandomResultTablesResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnGetServerCustomIDsFromPlayFabIDsResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnGetSharedGroupDataResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnGetTimeResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnGetTitleDataResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnGetTitleInternalDataResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnGetTitleNewsResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnGetUserAccountInfoResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnGetUserBansResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnGetUserDataResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnGetUserInternalDataResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnGetUserInventoryResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnGetUserPublisherDataResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnGetUserPublisherInternalDataResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnGetUserPublisherReadOnlyDataResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnGetUserReadOnlyDataResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnGrantCharacterToUserResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnGrantItemsToCharacterResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnGrantItemsToUserResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnGrantItemsToUsersResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnLinkXboxAccountResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnLoginWithServerCustomIdResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnLoginWithXboxResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnModifyItemUsesResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnMoveItemToCharacterFromCharacterResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnMoveItemToCharacterFromUserResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnMoveItemToUserFromCharacterResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnNotifyMatchmakerPlayerLeftResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnRedeemCouponResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnRedeemMatchmakerTicketResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnRefreshGameServerInstanceHeartbeatResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnRegisterGameResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnRemoveFriendResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnRemovePlayerTagResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnRemoveSharedGroupMembersResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnReportPlayerResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnRevokeAllBansForUserResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnRevokeBansResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnRevokeInventoryItemResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnRevokeInventoryItemsResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnSendCustomAccountRecoveryEmailResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnSendEmailFromTemplateResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnSendPushNotificationResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnSetFriendTagsResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnSetGameServerInstanceDataResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnSetGameServerInstanceStateResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnSetGameServerInstanceTagsResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnSetPlayerSecretResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnSetPublisherDataResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnSetTitleDataResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnSetTitleInternalDataResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnSubtractCharacterVirtualCurrencyResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnSubtractUserVirtualCurrencyResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnUnlinkXboxAccountResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnUnlockContainerInstanceResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnUnlockContainerItemResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnUpdateAvatarUrlResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnUpdateBansResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnUpdateCharacterDataResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnUpdateCharacterInternalDataResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnUpdateCharacterReadOnlyDataResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnUpdateCharacterStatisticsResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnUpdatePlayerStatisticsResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnUpdateSharedGroupDataResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnUpdateUserDataResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnUpdateUserInternalDataResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnUpdateUserInventoryItemCustomDataResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnUpdateUserPublisherDataResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnUpdateUserPublisherInternalDataResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnUpdateUserPublisherReadOnlyDataResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnUpdateUserReadOnlyDataResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnWriteCharacterEventResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnWritePlayerEventResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnWriteTitleEventResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);

        static bool ValidateResult(PlayFabResultCommon& resultCommon, CallRequestContainer& container);
    };
}

#endif
