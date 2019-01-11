#pragma once

#ifndef DISABLE_PLAYFABCLIENT_API

#include <playfab/PlayFabCallRequestContainer.h>
#include <playfab/PlayFabHttp.h>
#include <playfab/PlayFabClientDataModels.h>

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
        static void GetPlayFabIDsFromXboxLiveIDs(ClientModels::GetPlayFabIDsFromXboxLiveIDsRequest& request, ProcessApiCallback<ClientModels::GetPlayFabIDsFromXboxLiveIDsResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
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
        static void LinkOpenIdConnect(ClientModels::LinkOpenIdConnectRequest& request, ProcessApiCallback<ClientModels::EmptyResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
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
        static void LoginWithOpenIdConnect(ClientModels::LoginWithOpenIdConnectRequest& request, ProcessApiCallback<ClientModels::LoginResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
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
        static void ReportDeviceInfo(ClientModels::DeviceInfoRequest& request, ProcessApiCallback<ClientModels::EmptyResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
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
        static void UnlinkOpenIdConnect(ClientModels::UninkOpenIdConnectRequest& request, ProcessApiCallback<ClientModels::EmptyResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UnlinkSteamAccount(ClientModels::UnlinkSteamAccountRequest& request, ProcessApiCallback<ClientModels::UnlinkSteamAccountResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UnlinkTwitch(ClientModels::UnlinkTwitchAccountRequest& request, ProcessApiCallback<ClientModels::UnlinkTwitchAccountResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UnlinkWindowsHello(ClientModels::UnlinkWindowsHelloAccountRequest& request, ProcessApiCallback<ClientModels::UnlinkWindowsHelloAccountResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UnlinkXboxAccount(ClientModels::UnlinkXboxAccountRequest& request, ProcessApiCallback<ClientModels::UnlinkXboxAccountResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UnlockContainerInstance(ClientModels::UnlockContainerInstanceRequest& request, ProcessApiCallback<ClientModels::UnlockContainerItemResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UnlockContainerItem(ClientModels::UnlockContainerItemRequest& request, ProcessApiCallback<ClientModels::UnlockContainerItemResult> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static void UpdateAvatarUrl(ClientModels::UpdateAvatarUrlRequest& request, ProcessApiCallback<ClientModels::EmptyResponse> callback, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
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
        static void OnAcceptTradeResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnAddFriendResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnAddGenericIDResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnAddOrUpdateContactEmailResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnAddSharedGroupMembersResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnAddUsernamePasswordResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnAddUserVirtualCurrencyResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnAndroidDevicePushNotificationRegistrationResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnAttributeInstallResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnCancelTradeResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnConfirmPurchaseResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnConsumeItemResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnConsumeXboxEntitlementsResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnCreateSharedGroupResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnExecuteCloudScriptResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnGetAccountInfoResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnGetAllUsersCharactersResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnGetCatalogItemsResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnGetCharacterDataResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnGetCharacterInventoryResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnGetCharacterLeaderboardResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnGetCharacterReadOnlyDataResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnGetCharacterStatisticsResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnGetContentDownloadUrlResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnGetCurrentGamesResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnGetFriendLeaderboardResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnGetFriendLeaderboardAroundPlayerResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnGetFriendsListResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnGetGameServerRegionsResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnGetLeaderboardResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnGetLeaderboardAroundCharacterResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnGetLeaderboardAroundPlayerResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnGetLeaderboardForUserCharactersResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnGetPaymentTokenResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnGetPhotonAuthenticationTokenResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnGetPlayerCombinedInfoResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnGetPlayerProfileResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnGetPlayerSegmentsResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnGetPlayerStatisticsResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnGetPlayerStatisticVersionsResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnGetPlayerTagsResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnGetPlayerTradesResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnGetPlayFabIDsFromFacebookIDsResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnGetPlayFabIDsFromFacebookInstantGamesIdsResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnGetPlayFabIDsFromGameCenterIDsResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnGetPlayFabIDsFromGenericIDsResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnGetPlayFabIDsFromGoogleIDsResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnGetPlayFabIDsFromKongregateIDsResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnGetPlayFabIDsFromNintendoSwitchDeviceIdsResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnGetPlayFabIDsFromSteamIDsResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnGetPlayFabIDsFromTwitchIDsResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnGetPlayFabIDsFromXboxLiveIDsResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnGetPublisherDataResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnGetPurchaseResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnGetSharedGroupDataResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnGetStoreItemsResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnGetTimeResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnGetTitleDataResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnGetTitleNewsResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnGetTitlePublicKeyResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnGetTradeStatusResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnGetUserDataResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnGetUserInventoryResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnGetUserPublisherDataResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnGetUserPublisherReadOnlyDataResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnGetUserReadOnlyDataResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnGetWindowsHelloChallengeResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnGrantCharacterToUserResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnLinkAndroidDeviceIDResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnLinkCustomIDResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnLinkFacebookAccountResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnLinkFacebookInstantGamesIdResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnLinkGameCenterAccountResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnLinkGoogleAccountResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnLinkIOSDeviceIDResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnLinkKongregateResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnLinkNintendoSwitchDeviceIdResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnLinkOpenIdConnectResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnLinkSteamAccountResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnLinkTwitchResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnLinkWindowsHelloResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnLinkXboxAccountResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnLoginWithAndroidDeviceIDResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnLoginWithCustomIDResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnLoginWithEmailAddressResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnLoginWithFacebookResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnLoginWithFacebookInstantGamesIdResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnLoginWithGameCenterResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnLoginWithGoogleAccountResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnLoginWithIOSDeviceIDResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnLoginWithKongregateResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnLoginWithNintendoSwitchDeviceIdResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnLoginWithOpenIdConnectResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnLoginWithPlayFabResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnLoginWithSteamResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnLoginWithTwitchResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnLoginWithWindowsHelloResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnLoginWithXboxResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnMatchmakeResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnOpenTradeResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnPayForPurchaseResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnPurchaseItemResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnRedeemCouponResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnRegisterForIOSPushNotificationResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnRegisterPlayFabUserResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnRegisterWithWindowsHelloResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnRemoveContactEmailResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnRemoveFriendResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnRemoveGenericIDResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnRemoveSharedGroupMembersResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnReportDeviceInfoResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnReportPlayerResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnRestoreIOSPurchasesResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnSendAccountRecoveryEmailResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnSetFriendTagsResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnSetPlayerSecretResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnStartGameResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnStartPurchaseResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnSubtractUserVirtualCurrencyResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnUnlinkAndroidDeviceIDResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnUnlinkCustomIDResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnUnlinkFacebookAccountResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnUnlinkFacebookInstantGamesIdResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnUnlinkGameCenterAccountResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnUnlinkGoogleAccountResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnUnlinkIOSDeviceIDResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnUnlinkKongregateResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnUnlinkNintendoSwitchDeviceIdResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnUnlinkOpenIdConnectResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnUnlinkSteamAccountResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnUnlinkTwitchResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnUnlinkWindowsHelloResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnUnlinkXboxAccountResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnUnlockContainerInstanceResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnUnlockContainerItemResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnUpdateAvatarUrlResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnUpdateCharacterDataResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnUpdateCharacterStatisticsResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnUpdatePlayerStatisticsResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnUpdateSharedGroupDataResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnUpdateUserDataResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnUpdateUserPublisherDataResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnUpdateUserTitleDisplayNameResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnValidateAmazonIAPReceiptResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnValidateGooglePlayPurchaseResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnValidateIOSReceiptResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnValidateWindowsStoreReceiptResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnWriteCharacterEventResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnWritePlayerEventResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);
        static void OnWriteTitleEventResult(int httpCode, std::string result, CallRequestContainerBase& reqContainer);


        // Private, Client-Specific
        static void MultiStepClientLogin(bool needsAttribution);
        static bool ValidateResult(PlayFabResultCommon& resultCommon, CallRequestContainer& container);
    };
}

#endif
