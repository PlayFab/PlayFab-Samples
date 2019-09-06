#pragma once

#ifndef DISABLE_PLAYFABCLIENT_API

#include "playfab/PlayFabHttp.h"
#include "playfab/PlayFabClientDataModels.h"

namespace PlayFab
{
    /// <summary>
    /// Main interface for PlayFab Sdk, specifically all Client APIs
    /// </summary>
    class PlayFabClientAPI
    {
    public:
        static size_t Update();
        static void ForgetAllCredentials();


        // Public, Client-Specific
        static bool IsClientLoggedIn();

        // ------------ Generated API calls
        static void AcceptTrade(ClientModels::AcceptTradeRequest& request, ProcessApiCallback<ClientModels::AcceptTradeResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void AddFriend(ClientModels::AddFriendRequest& request, ProcessApiCallback<ClientModels::AddFriendResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void AddGenericID(ClientModels::AddGenericIDRequest& request, ProcessApiCallback<ClientModels::AddGenericIDResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void AddOrUpdateContactEmail(ClientModels::AddOrUpdateContactEmailRequest& request, ProcessApiCallback<ClientModels::AddOrUpdateContactEmailResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void AddSharedGroupMembers(ClientModels::AddSharedGroupMembersRequest& request, ProcessApiCallback<ClientModels::AddSharedGroupMembersResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void AddUsernamePassword(ClientModels::AddUsernamePasswordRequest& request, ProcessApiCallback<ClientModels::AddUsernamePasswordResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void AddUserVirtualCurrency(ClientModels::AddUserVirtualCurrencyRequest& request, ProcessApiCallback<ClientModels::ModifyUserVirtualCurrencyResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void AndroidDevicePushNotificationRegistration(ClientModels::AndroidDevicePushNotificationRegistrationRequest& request, ProcessApiCallback<ClientModels::AndroidDevicePushNotificationRegistrationResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void AttributeInstall(ClientModels::AttributeInstallRequest& request, ProcessApiCallback<ClientModels::AttributeInstallResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void CancelTrade(ClientModels::CancelTradeRequest& request, ProcessApiCallback<ClientModels::CancelTradeResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void ConfirmPurchase(ClientModels::ConfirmPurchaseRequest& request, ProcessApiCallback<ClientModels::ConfirmPurchaseResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void ConsumeItem(ClientModels::ConsumeItemRequest& request, ProcessApiCallback<ClientModels::ConsumeItemResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void ConsumeXboxEntitlements(ClientModels::ConsumeXboxEntitlementsRequest& request, ProcessApiCallback<ClientModels::ConsumeXboxEntitlementsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void CreateSharedGroup(ClientModels::CreateSharedGroupRequest& request, ProcessApiCallback<ClientModels::CreateSharedGroupResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void ExecuteCloudScript(ClientModels::ExecuteCloudScriptRequest& request, ProcessApiCallback<ClientModels::ExecuteCloudScriptResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetAccountInfo(ClientModels::GetAccountInfoRequest& request, ProcessApiCallback<ClientModels::GetAccountInfoResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetAllUsersCharacters(ClientModels::ListUsersCharactersRequest& request, ProcessApiCallback<ClientModels::ListUsersCharactersResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetCatalogItems(ClientModels::GetCatalogItemsRequest& request, ProcessApiCallback<ClientModels::GetCatalogItemsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetCharacterData(ClientModels::GetCharacterDataRequest& request, ProcessApiCallback<ClientModels::GetCharacterDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetCharacterInventory(ClientModels::GetCharacterInventoryRequest& request, ProcessApiCallback<ClientModels::GetCharacterInventoryResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetCharacterLeaderboard(ClientModels::GetCharacterLeaderboardRequest& request, ProcessApiCallback<ClientModels::GetCharacterLeaderboardResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetCharacterReadOnlyData(ClientModels::GetCharacterDataRequest& request, ProcessApiCallback<ClientModels::GetCharacterDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetCharacterStatistics(ClientModels::GetCharacterStatisticsRequest& request, ProcessApiCallback<ClientModels::GetCharacterStatisticsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetContentDownloadUrl(ClientModels::GetContentDownloadUrlRequest& request, ProcessApiCallback<ClientModels::GetContentDownloadUrlResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetCurrentGames(ClientModels::CurrentGamesRequest& request, ProcessApiCallback<ClientModels::CurrentGamesResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetFriendLeaderboard(ClientModels::GetFriendLeaderboardRequest& request, ProcessApiCallback<ClientModels::GetLeaderboardResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetFriendLeaderboardAroundPlayer(ClientModels::GetFriendLeaderboardAroundPlayerRequest& request, ProcessApiCallback<ClientModels::GetFriendLeaderboardAroundPlayerResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetFriendsList(ClientModels::GetFriendsListRequest& request, ProcessApiCallback<ClientModels::GetFriendsListResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetGameServerRegions(ClientModels::GameServerRegionsRequest& request, ProcessApiCallback<ClientModels::GameServerRegionsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetLeaderboard(ClientModels::GetLeaderboardRequest& request, ProcessApiCallback<ClientModels::GetLeaderboardResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetLeaderboardAroundCharacter(ClientModels::GetLeaderboardAroundCharacterRequest& request, ProcessApiCallback<ClientModels::GetLeaderboardAroundCharacterResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetLeaderboardAroundPlayer(ClientModels::GetLeaderboardAroundPlayerRequest& request, ProcessApiCallback<ClientModels::GetLeaderboardAroundPlayerResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetLeaderboardForUserCharacters(ClientModels::GetLeaderboardForUsersCharactersRequest& request, ProcessApiCallback<ClientModels::GetLeaderboardForUsersCharactersResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetPaymentToken(ClientModels::GetPaymentTokenRequest& request, ProcessApiCallback<ClientModels::GetPaymentTokenResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetPhotonAuthenticationToken(ClientModels::GetPhotonAuthenticationTokenRequest& request, ProcessApiCallback<ClientModels::GetPhotonAuthenticationTokenResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetPlayerCombinedInfo(ClientModels::GetPlayerCombinedInfoRequest& request, ProcessApiCallback<ClientModels::GetPlayerCombinedInfoResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetPlayerProfile(ClientModels::GetPlayerProfileRequest& request, ProcessApiCallback<ClientModels::GetPlayerProfileResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetPlayerSegments(ClientModels::GetPlayerSegmentsRequest& request, ProcessApiCallback<ClientModels::GetPlayerSegmentsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetPlayerStatistics(ClientModels::GetPlayerStatisticsRequest& request, ProcessApiCallback<ClientModels::GetPlayerStatisticsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetPlayerStatisticVersions(ClientModels::GetPlayerStatisticVersionsRequest& request, ProcessApiCallback<ClientModels::GetPlayerStatisticVersionsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetPlayerTags(ClientModels::GetPlayerTagsRequest& request, ProcessApiCallback<ClientModels::GetPlayerTagsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetPlayerTrades(ClientModels::GetPlayerTradesRequest& request, ProcessApiCallback<ClientModels::GetPlayerTradesResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetPlayFabIDsFromFacebookIDs(ClientModels::GetPlayFabIDsFromFacebookIDsRequest& request, ProcessApiCallback<ClientModels::GetPlayFabIDsFromFacebookIDsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetPlayFabIDsFromFacebookInstantGamesIds(ClientModels::GetPlayFabIDsFromFacebookInstantGamesIdsRequest& request, ProcessApiCallback<ClientModels::GetPlayFabIDsFromFacebookInstantGamesIdsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetPlayFabIDsFromGameCenterIDs(ClientModels::GetPlayFabIDsFromGameCenterIDsRequest& request, ProcessApiCallback<ClientModels::GetPlayFabIDsFromGameCenterIDsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetPlayFabIDsFromGenericIDs(ClientModels::GetPlayFabIDsFromGenericIDsRequest& request, ProcessApiCallback<ClientModels::GetPlayFabIDsFromGenericIDsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetPlayFabIDsFromGoogleIDs(ClientModels::GetPlayFabIDsFromGoogleIDsRequest& request, ProcessApiCallback<ClientModels::GetPlayFabIDsFromGoogleIDsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetPlayFabIDsFromKongregateIDs(ClientModels::GetPlayFabIDsFromKongregateIDsRequest& request, ProcessApiCallback<ClientModels::GetPlayFabIDsFromKongregateIDsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetPlayFabIDsFromNintendoSwitchDeviceIds(ClientModels::GetPlayFabIDsFromNintendoSwitchDeviceIdsRequest& request, ProcessApiCallback<ClientModels::GetPlayFabIDsFromNintendoSwitchDeviceIdsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetPlayFabIDsFromSteamIDs(ClientModels::GetPlayFabIDsFromSteamIDsRequest& request, ProcessApiCallback<ClientModels::GetPlayFabIDsFromSteamIDsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetPlayFabIDsFromTwitchIDs(ClientModels::GetPlayFabIDsFromTwitchIDsRequest& request, ProcessApiCallback<ClientModels::GetPlayFabIDsFromTwitchIDsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetPublisherData(ClientModels::GetPublisherDataRequest& request, ProcessApiCallback<ClientModels::GetPublisherDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetPurchase(ClientModels::GetPurchaseRequest& request, ProcessApiCallback<ClientModels::GetPurchaseResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetSharedGroupData(ClientModels::GetSharedGroupDataRequest& request, ProcessApiCallback<ClientModels::GetSharedGroupDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetStoreItems(ClientModels::GetStoreItemsRequest& request, ProcessApiCallback<ClientModels::GetStoreItemsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetTime(ClientModels::GetTimeRequest& request, ProcessApiCallback<ClientModels::GetTimeResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetTitleData(ClientModels::GetTitleDataRequest& request, ProcessApiCallback<ClientModels::GetTitleDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetTitleNews(ClientModels::GetTitleNewsRequest& request, ProcessApiCallback<ClientModels::GetTitleNewsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetTitlePublicKey(ClientModels::GetTitlePublicKeyRequest& request, ProcessApiCallback<ClientModels::GetTitlePublicKeyResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetTradeStatus(ClientModels::GetTradeStatusRequest& request, ProcessApiCallback<ClientModels::GetTradeStatusResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetUserData(ClientModels::GetUserDataRequest& request, ProcessApiCallback<ClientModels::GetUserDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetUserInventory(ClientModels::GetUserInventoryRequest& request, ProcessApiCallback<ClientModels::GetUserInventoryResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetUserPublisherData(ClientModels::GetUserDataRequest& request, ProcessApiCallback<ClientModels::GetUserDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetUserPublisherReadOnlyData(ClientModels::GetUserDataRequest& request, ProcessApiCallback<ClientModels::GetUserDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetUserReadOnlyData(ClientModels::GetUserDataRequest& request, ProcessApiCallback<ClientModels::GetUserDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GetWindowsHelloChallenge(ClientModels::GetWindowsHelloChallengeRequest& request, ProcessApiCallback<ClientModels::GetWindowsHelloChallengeResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void GrantCharacterToUser(ClientModels::GrantCharacterToUserRequest& request, ProcessApiCallback<ClientModels::GrantCharacterToUserResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void LinkAndroidDeviceID(ClientModels::LinkAndroidDeviceIDRequest& request, ProcessApiCallback<ClientModels::LinkAndroidDeviceIDResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void LinkCustomID(ClientModels::LinkCustomIDRequest& request, ProcessApiCallback<ClientModels::LinkCustomIDResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void LinkFacebookAccount(ClientModels::LinkFacebookAccountRequest& request, ProcessApiCallback<ClientModels::LinkFacebookAccountResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void LinkFacebookInstantGamesId(ClientModels::LinkFacebookInstantGamesIdRequest& request, ProcessApiCallback<ClientModels::LinkFacebookInstantGamesIdResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void LinkGameCenterAccount(ClientModels::LinkGameCenterAccountRequest& request, ProcessApiCallback<ClientModels::LinkGameCenterAccountResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void LinkGoogleAccount(ClientModels::LinkGoogleAccountRequest& request, ProcessApiCallback<ClientModels::LinkGoogleAccountResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void LinkIOSDeviceID(ClientModels::LinkIOSDeviceIDRequest& request, ProcessApiCallback<ClientModels::LinkIOSDeviceIDResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void LinkKongregate(ClientModels::LinkKongregateAccountRequest& request, ProcessApiCallback<ClientModels::LinkKongregateAccountResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void LinkNintendoSwitchDeviceId(ClientModels::LinkNintendoSwitchDeviceIdRequest& request, ProcessApiCallback<ClientModels::LinkNintendoSwitchDeviceIdResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void LinkSteamAccount(ClientModels::LinkSteamAccountRequest& request, ProcessApiCallback<ClientModels::LinkSteamAccountResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void LinkTwitch(ClientModels::LinkTwitchAccountRequest& request, ProcessApiCallback<ClientModels::LinkTwitchAccountResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void LinkWindowsHello(ClientModels::LinkWindowsHelloAccountRequest& request, ProcessApiCallback<ClientModels::LinkWindowsHelloAccountResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void LinkXboxAccount(ClientModels::LinkXboxAccountRequest& request, ProcessApiCallback<ClientModels::LinkXboxAccountResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void LoginWithAndroidDeviceID(ClientModels::LoginWithAndroidDeviceIDRequest& request, ProcessApiCallback<ClientModels::LoginResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void LoginWithCustomID(ClientModels::LoginWithCustomIDRequest& request, ProcessApiCallback<ClientModels::LoginResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void LoginWithEmailAddress(ClientModels::LoginWithEmailAddressRequest& request, ProcessApiCallback<ClientModels::LoginResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void LoginWithFacebook(ClientModels::LoginWithFacebookRequest& request, ProcessApiCallback<ClientModels::LoginResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void LoginWithFacebookInstantGamesId(ClientModels::LoginWithFacebookInstantGamesIdRequest& request, ProcessApiCallback<ClientModels::LoginResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void LoginWithGameCenter(ClientModels::LoginWithGameCenterRequest& request, ProcessApiCallback<ClientModels::LoginResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void LoginWithGoogleAccount(ClientModels::LoginWithGoogleAccountRequest& request, ProcessApiCallback<ClientModels::LoginResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void LoginWithIOSDeviceID(ClientModels::LoginWithIOSDeviceIDRequest& request, ProcessApiCallback<ClientModels::LoginResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void LoginWithKongregate(ClientModels::LoginWithKongregateRequest& request, ProcessApiCallback<ClientModels::LoginResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void LoginWithNintendoSwitchDeviceId(ClientModels::LoginWithNintendoSwitchDeviceIdRequest& request, ProcessApiCallback<ClientModels::LoginResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void LoginWithPlayFab(ClientModels::LoginWithPlayFabRequest& request, ProcessApiCallback<ClientModels::LoginResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void LoginWithSteam(ClientModels::LoginWithSteamRequest& request, ProcessApiCallback<ClientModels::LoginResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void LoginWithTwitch(ClientModels::LoginWithTwitchRequest& request, ProcessApiCallback<ClientModels::LoginResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void LoginWithWindowsHello(ClientModels::LoginWithWindowsHelloRequest& request, ProcessApiCallback<ClientModels::LoginResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void LoginWithXbox(ClientModels::LoginWithXboxRequest& request, ProcessApiCallback<ClientModels::LoginResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void Matchmake(ClientModels::MatchmakeRequest& request, ProcessApiCallback<ClientModels::MatchmakeResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void OpenTrade(ClientModels::OpenTradeRequest& request, ProcessApiCallback<ClientModels::OpenTradeResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void PayForPurchase(ClientModels::PayForPurchaseRequest& request, ProcessApiCallback<ClientModels::PayForPurchaseResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void PurchaseItem(ClientModels::PurchaseItemRequest& request, ProcessApiCallback<ClientModels::PurchaseItemResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void RedeemCoupon(ClientModels::RedeemCouponRequest& request, ProcessApiCallback<ClientModels::RedeemCouponResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void RegisterForIOSPushNotification(ClientModels::RegisterForIOSPushNotificationRequest& request, ProcessApiCallback<ClientModels::RegisterForIOSPushNotificationResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void RegisterPlayFabUser(ClientModels::RegisterPlayFabUserRequest& request, ProcessApiCallback<ClientModels::RegisterPlayFabUserResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void RegisterWithWindowsHello(ClientModels::RegisterWithWindowsHelloRequest& request, ProcessApiCallback<ClientModels::LoginResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void RemoveContactEmail(ClientModels::RemoveContactEmailRequest& request, ProcessApiCallback<ClientModels::RemoveContactEmailResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void RemoveFriend(ClientModels::RemoveFriendRequest& request, ProcessApiCallback<ClientModels::RemoveFriendResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void RemoveGenericID(ClientModels::RemoveGenericIDRequest& request, ProcessApiCallback<ClientModels::RemoveGenericIDResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void RemoveSharedGroupMembers(ClientModels::RemoveSharedGroupMembersRequest& request, ProcessApiCallback<ClientModels::RemoveSharedGroupMembersResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void ReportDeviceInfo(ClientModels::DeviceInfoRequest& request, ProcessApiCallback<ClientModels::EmptyResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void ReportPlayer(ClientModels::ReportPlayerClientRequest& request, ProcessApiCallback<ClientModels::ReportPlayerClientResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void RestoreIOSPurchases(ClientModels::RestoreIOSPurchasesRequest& request, ProcessApiCallback<ClientModels::RestoreIOSPurchasesResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void SendAccountRecoveryEmail(ClientModels::SendAccountRecoveryEmailRequest& request, ProcessApiCallback<ClientModels::SendAccountRecoveryEmailResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void SetFriendTags(ClientModels::SetFriendTagsRequest& request, ProcessApiCallback<ClientModels::SetFriendTagsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void SetPlayerSecret(ClientModels::SetPlayerSecretRequest& request, ProcessApiCallback<ClientModels::SetPlayerSecretResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void StartGame(ClientModels::StartGameRequest& request, ProcessApiCallback<ClientModels::StartGameResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void StartPurchase(ClientModels::StartPurchaseRequest& request, ProcessApiCallback<ClientModels::StartPurchaseResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void SubtractUserVirtualCurrency(ClientModels::SubtractUserVirtualCurrencyRequest& request, ProcessApiCallback<ClientModels::ModifyUserVirtualCurrencyResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UnlinkAndroidDeviceID(ClientModels::UnlinkAndroidDeviceIDRequest& request, ProcessApiCallback<ClientModels::UnlinkAndroidDeviceIDResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UnlinkCustomID(ClientModels::UnlinkCustomIDRequest& request, ProcessApiCallback<ClientModels::UnlinkCustomIDResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UnlinkFacebookAccount(ClientModels::UnlinkFacebookAccountRequest& request, ProcessApiCallback<ClientModels::UnlinkFacebookAccountResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UnlinkFacebookInstantGamesId(ClientModels::UnlinkFacebookInstantGamesIdRequest& request, ProcessApiCallback<ClientModels::UnlinkFacebookInstantGamesIdResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UnlinkGameCenterAccount(ClientModels::UnlinkGameCenterAccountRequest& request, ProcessApiCallback<ClientModels::UnlinkGameCenterAccountResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UnlinkGoogleAccount(ClientModels::UnlinkGoogleAccountRequest& request, ProcessApiCallback<ClientModels::UnlinkGoogleAccountResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UnlinkIOSDeviceID(ClientModels::UnlinkIOSDeviceIDRequest& request, ProcessApiCallback<ClientModels::UnlinkIOSDeviceIDResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UnlinkKongregate(ClientModels::UnlinkKongregateAccountRequest& request, ProcessApiCallback<ClientModels::UnlinkKongregateAccountResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UnlinkNintendoSwitchDeviceId(ClientModels::UnlinkNintendoSwitchDeviceIdRequest& request, ProcessApiCallback<ClientModels::UnlinkNintendoSwitchDeviceIdResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UnlinkSteamAccount(ClientModels::UnlinkSteamAccountRequest& request, ProcessApiCallback<ClientModels::UnlinkSteamAccountResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UnlinkTwitch(ClientModels::UnlinkTwitchAccountRequest& request, ProcessApiCallback<ClientModels::UnlinkTwitchAccountResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UnlinkWindowsHello(ClientModels::UnlinkWindowsHelloAccountRequest& request, ProcessApiCallback<ClientModels::UnlinkWindowsHelloAccountResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UnlinkXboxAccount(ClientModels::UnlinkXboxAccountRequest& request, ProcessApiCallback<ClientModels::UnlinkXboxAccountResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UnlockContainerInstance(ClientModels::UnlockContainerInstanceRequest& request, ProcessApiCallback<ClientModels::UnlockContainerItemResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UnlockContainerItem(ClientModels::UnlockContainerItemRequest& request, ProcessApiCallback<ClientModels::UnlockContainerItemResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UpdateAvatarUrl(ClientModels::UpdateAvatarUrlRequest& request, ProcessApiCallback<ClientModels::EmptyResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UpdateCharacterData(ClientModels::UpdateCharacterDataRequest& request, ProcessApiCallback<ClientModels::UpdateCharacterDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UpdateCharacterStatistics(ClientModels::UpdateCharacterStatisticsRequest& request, ProcessApiCallback<ClientModels::UpdateCharacterStatisticsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UpdatePlayerStatistics(ClientModels::UpdatePlayerStatisticsRequest& request, ProcessApiCallback<ClientModels::UpdatePlayerStatisticsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UpdateSharedGroupData(ClientModels::UpdateSharedGroupDataRequest& request, ProcessApiCallback<ClientModels::UpdateSharedGroupDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UpdateUserData(ClientModels::UpdateUserDataRequest& request, ProcessApiCallback<ClientModels::UpdateUserDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UpdateUserPublisherData(ClientModels::UpdateUserDataRequest& request, ProcessApiCallback<ClientModels::UpdateUserDataResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UpdateUserTitleDisplayName(ClientModels::UpdateUserTitleDisplayNameRequest& request, ProcessApiCallback<ClientModels::UpdateUserTitleDisplayNameResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void ValidateAmazonIAPReceipt(ClientModels::ValidateAmazonReceiptRequest& request, ProcessApiCallback<ClientModels::ValidateAmazonReceiptResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void ValidateGooglePlayPurchase(ClientModels::ValidateGooglePlayPurchaseRequest& request, ProcessApiCallback<ClientModels::ValidateGooglePlayPurchaseResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void ValidateIOSReceipt(ClientModels::ValidateIOSReceiptRequest& request, ProcessApiCallback<ClientModels::ValidateIOSReceiptResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void ValidateWindowsStoreReceipt(ClientModels::ValidateWindowsReceiptRequest& request, ProcessApiCallback<ClientModels::ValidateWindowsReceiptResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void WriteCharacterEvent(ClientModels::WriteClientCharacterEventRequest& request, ProcessApiCallback<ClientModels::WriteEventResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void WritePlayerEvent(ClientModels::WriteClientPlayerEventRequest& request, ProcessApiCallback<ClientModels::WriteEventResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void WriteTitleEvent(ClientModels::WriteTitleEventRequest& request, ProcessApiCallback<ClientModels::WriteEventResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);

    private:
        PlayFabClientAPI(); // Private constructor, static class should never have an instance
        PlayFabClientAPI(const PlayFabClientAPI& other); // Private copy-constructor, static class should never have an instance

        // ------------ Generated result handlers
        static void OnAcceptTradeResult(CallRequestContainer& request);
        static void OnAddFriendResult(CallRequestContainer& request);
        static void OnAddGenericIDResult(CallRequestContainer& request);
        static void OnAddOrUpdateContactEmailResult(CallRequestContainer& request);
        static void OnAddSharedGroupMembersResult(CallRequestContainer& request);
        static void OnAddUsernamePasswordResult(CallRequestContainer& request);
        static void OnAddUserVirtualCurrencyResult(CallRequestContainer& request);
        static void OnAndroidDevicePushNotificationRegistrationResult(CallRequestContainer& request);
        static void OnAttributeInstallResult(CallRequestContainer& request);
        static void OnCancelTradeResult(CallRequestContainer& request);
        static void OnConfirmPurchaseResult(CallRequestContainer& request);
        static void OnConsumeItemResult(CallRequestContainer& request);
        static void OnConsumeXboxEntitlementsResult(CallRequestContainer& request);
        static void OnCreateSharedGroupResult(CallRequestContainer& request);
        static void OnExecuteCloudScriptResult(CallRequestContainer& request);
        static void OnGetAccountInfoResult(CallRequestContainer& request);
        static void OnGetAllUsersCharactersResult(CallRequestContainer& request);
        static void OnGetCatalogItemsResult(CallRequestContainer& request);
        static void OnGetCharacterDataResult(CallRequestContainer& request);
        static void OnGetCharacterInventoryResult(CallRequestContainer& request);
        static void OnGetCharacterLeaderboardResult(CallRequestContainer& request);
        static void OnGetCharacterReadOnlyDataResult(CallRequestContainer& request);
        static void OnGetCharacterStatisticsResult(CallRequestContainer& request);
        static void OnGetContentDownloadUrlResult(CallRequestContainer& request);
        static void OnGetCurrentGamesResult(CallRequestContainer& request);
        static void OnGetFriendLeaderboardResult(CallRequestContainer& request);
        static void OnGetFriendLeaderboardAroundPlayerResult(CallRequestContainer& request);
        static void OnGetFriendsListResult(CallRequestContainer& request);
        static void OnGetGameServerRegionsResult(CallRequestContainer& request);
        static void OnGetLeaderboardResult(CallRequestContainer& request);
        static void OnGetLeaderboardAroundCharacterResult(CallRequestContainer& request);
        static void OnGetLeaderboardAroundPlayerResult(CallRequestContainer& request);
        static void OnGetLeaderboardForUserCharactersResult(CallRequestContainer& request);
        static void OnGetPaymentTokenResult(CallRequestContainer& request);
        static void OnGetPhotonAuthenticationTokenResult(CallRequestContainer& request);
        static void OnGetPlayerCombinedInfoResult(CallRequestContainer& request);
        static void OnGetPlayerProfileResult(CallRequestContainer& request);
        static void OnGetPlayerSegmentsResult(CallRequestContainer& request);
        static void OnGetPlayerStatisticsResult(CallRequestContainer& request);
        static void OnGetPlayerStatisticVersionsResult(CallRequestContainer& request);
        static void OnGetPlayerTagsResult(CallRequestContainer& request);
        static void OnGetPlayerTradesResult(CallRequestContainer& request);
        static void OnGetPlayFabIDsFromFacebookIDsResult(CallRequestContainer& request);
        static void OnGetPlayFabIDsFromFacebookInstantGamesIdsResult(CallRequestContainer& request);
        static void OnGetPlayFabIDsFromGameCenterIDsResult(CallRequestContainer& request);
        static void OnGetPlayFabIDsFromGenericIDsResult(CallRequestContainer& request);
        static void OnGetPlayFabIDsFromGoogleIDsResult(CallRequestContainer& request);
        static void OnGetPlayFabIDsFromKongregateIDsResult(CallRequestContainer& request);
        static void OnGetPlayFabIDsFromNintendoSwitchDeviceIdsResult(CallRequestContainer& request);
        static void OnGetPlayFabIDsFromSteamIDsResult(CallRequestContainer& request);
        static void OnGetPlayFabIDsFromTwitchIDsResult(CallRequestContainer& request);
        static void OnGetPublisherDataResult(CallRequestContainer& request);
        static void OnGetPurchaseResult(CallRequestContainer& request);
        static void OnGetSharedGroupDataResult(CallRequestContainer& request);
        static void OnGetStoreItemsResult(CallRequestContainer& request);
        static void OnGetTimeResult(CallRequestContainer& request);
        static void OnGetTitleDataResult(CallRequestContainer& request);
        static void OnGetTitleNewsResult(CallRequestContainer& request);
        static void OnGetTitlePublicKeyResult(CallRequestContainer& request);
        static void OnGetTradeStatusResult(CallRequestContainer& request);
        static void OnGetUserDataResult(CallRequestContainer& request);
        static void OnGetUserInventoryResult(CallRequestContainer& request);
        static void OnGetUserPublisherDataResult(CallRequestContainer& request);
        static void OnGetUserPublisherReadOnlyDataResult(CallRequestContainer& request);
        static void OnGetUserReadOnlyDataResult(CallRequestContainer& request);
        static void OnGetWindowsHelloChallengeResult(CallRequestContainer& request);
        static void OnGrantCharacterToUserResult(CallRequestContainer& request);
        static void OnLinkAndroidDeviceIDResult(CallRequestContainer& request);
        static void OnLinkCustomIDResult(CallRequestContainer& request);
        static void OnLinkFacebookAccountResult(CallRequestContainer& request);
        static void OnLinkFacebookInstantGamesIdResult(CallRequestContainer& request);
        static void OnLinkGameCenterAccountResult(CallRequestContainer& request);
        static void OnLinkGoogleAccountResult(CallRequestContainer& request);
        static void OnLinkIOSDeviceIDResult(CallRequestContainer& request);
        static void OnLinkKongregateResult(CallRequestContainer& request);
        static void OnLinkNintendoSwitchDeviceIdResult(CallRequestContainer& request);
        static void OnLinkSteamAccountResult(CallRequestContainer& request);
        static void OnLinkTwitchResult(CallRequestContainer& request);
        static void OnLinkWindowsHelloResult(CallRequestContainer& request);
        static void OnLinkXboxAccountResult(CallRequestContainer& request);
        static void OnLoginWithAndroidDeviceIDResult(CallRequestContainer& request);
        static void OnLoginWithCustomIDResult(CallRequestContainer& request);
        static void OnLoginWithEmailAddressResult(CallRequestContainer& request);
        static void OnLoginWithFacebookResult(CallRequestContainer& request);
        static void OnLoginWithFacebookInstantGamesIdResult(CallRequestContainer& request);
        static void OnLoginWithGameCenterResult(CallRequestContainer& request);
        static void OnLoginWithGoogleAccountResult(CallRequestContainer& request);
        static void OnLoginWithIOSDeviceIDResult(CallRequestContainer& request);
        static void OnLoginWithKongregateResult(CallRequestContainer& request);
        static void OnLoginWithNintendoSwitchDeviceIdResult(CallRequestContainer& request);
        static void OnLoginWithPlayFabResult(CallRequestContainer& request);
        static void OnLoginWithSteamResult(CallRequestContainer& request);
        static void OnLoginWithTwitchResult(CallRequestContainer& request);
        static void OnLoginWithWindowsHelloResult(CallRequestContainer& request);
        static void OnLoginWithXboxResult(CallRequestContainer& request);
        static void OnMatchmakeResult(CallRequestContainer& request);
        static void OnOpenTradeResult(CallRequestContainer& request);
        static void OnPayForPurchaseResult(CallRequestContainer& request);
        static void OnPurchaseItemResult(CallRequestContainer& request);
        static void OnRedeemCouponResult(CallRequestContainer& request);
        static void OnRegisterForIOSPushNotificationResult(CallRequestContainer& request);
        static void OnRegisterPlayFabUserResult(CallRequestContainer& request);
        static void OnRegisterWithWindowsHelloResult(CallRequestContainer& request);
        static void OnRemoveContactEmailResult(CallRequestContainer& request);
        static void OnRemoveFriendResult(CallRequestContainer& request);
        static void OnRemoveGenericIDResult(CallRequestContainer& request);
        static void OnRemoveSharedGroupMembersResult(CallRequestContainer& request);
        static void OnReportDeviceInfoResult(CallRequestContainer& request);
        static void OnReportPlayerResult(CallRequestContainer& request);
        static void OnRestoreIOSPurchasesResult(CallRequestContainer& request);
        static void OnSendAccountRecoveryEmailResult(CallRequestContainer& request);
        static void OnSetFriendTagsResult(CallRequestContainer& request);
        static void OnSetPlayerSecretResult(CallRequestContainer& request);
        static void OnStartGameResult(CallRequestContainer& request);
        static void OnStartPurchaseResult(CallRequestContainer& request);
        static void OnSubtractUserVirtualCurrencyResult(CallRequestContainer& request);
        static void OnUnlinkAndroidDeviceIDResult(CallRequestContainer& request);
        static void OnUnlinkCustomIDResult(CallRequestContainer& request);
        static void OnUnlinkFacebookAccountResult(CallRequestContainer& request);
        static void OnUnlinkFacebookInstantGamesIdResult(CallRequestContainer& request);
        static void OnUnlinkGameCenterAccountResult(CallRequestContainer& request);
        static void OnUnlinkGoogleAccountResult(CallRequestContainer& request);
        static void OnUnlinkIOSDeviceIDResult(CallRequestContainer& request);
        static void OnUnlinkKongregateResult(CallRequestContainer& request);
        static void OnUnlinkNintendoSwitchDeviceIdResult(CallRequestContainer& request);
        static void OnUnlinkSteamAccountResult(CallRequestContainer& request);
        static void OnUnlinkTwitchResult(CallRequestContainer& request);
        static void OnUnlinkWindowsHelloResult(CallRequestContainer& request);
        static void OnUnlinkXboxAccountResult(CallRequestContainer& request);
        static void OnUnlockContainerInstanceResult(CallRequestContainer& request);
        static void OnUnlockContainerItemResult(CallRequestContainer& request);
        static void OnUpdateAvatarUrlResult(CallRequestContainer& request);
        static void OnUpdateCharacterDataResult(CallRequestContainer& request);
        static void OnUpdateCharacterStatisticsResult(CallRequestContainer& request);
        static void OnUpdatePlayerStatisticsResult(CallRequestContainer& request);
        static void OnUpdateSharedGroupDataResult(CallRequestContainer& request);
        static void OnUpdateUserDataResult(CallRequestContainer& request);
        static void OnUpdateUserPublisherDataResult(CallRequestContainer& request);
        static void OnUpdateUserTitleDisplayNameResult(CallRequestContainer& request);
        static void OnValidateAmazonIAPReceiptResult(CallRequestContainer& request);
        static void OnValidateGooglePlayPurchaseResult(CallRequestContainer& request);
        static void OnValidateIOSReceiptResult(CallRequestContainer& request);
        static void OnValidateWindowsStoreReceiptResult(CallRequestContainer& request);
        static void OnWriteCharacterEventResult(CallRequestContainer& request);
        static void OnWritePlayerEventResult(CallRequestContainer& request);
        static void OnWriteTitleEventResult(CallRequestContainer& request);


        // Private, Client-Specific
        static void MultiStepClientLogin(bool needsAttribution);
    };
}

#endif
