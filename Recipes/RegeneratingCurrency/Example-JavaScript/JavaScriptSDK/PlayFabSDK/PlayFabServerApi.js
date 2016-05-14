var PlayFab = typeof PlayFab != 'undefined' ? PlayFab : {};

if(!PlayFab.settings) {
    PlayFab.settings = {
        titleId: null, // You must set this value for PlayFabSdk to work properly (Found in the Game Manager for your title, at the PlayFab Website)
        developerSecretKey: null, // For security reasons you must never expose this value to the client or players - You must set this value for Server-APIs to work properly (Found in the Game Manager for your title, at the PlayFab Website)
        advertisingIdType: null,
        advertisingIdValue: null,

        // disableAdvertising is provided for completeness, but changing it is not suggested
        // Disabling this may prevent your advertising-related PlayFab marketplace partners from working correctly
        disableAdvertising: false,
        AD_TYPE_IDFA: "Idfa",
        AD_TYPE_ANDROID_ID: "Android_Id"
    }
}

if(!PlayFab._internalSettings) {
    PlayFab._internalSettings = {
        sessionTicket: null,
        sdkVersion: "0.17.160502",
        productionServerUrl: ".playfabapi.com",
        logicServerUrl: null,

        GetServerUrl: function () {
            return "https://" + PlayFab.settings.titleId + PlayFab._internalSettings.productionServerUrl;
        },

        GetLogicServerUrl: function () {
            return PlayFab._internalSettings.logicServerUrl;
        },

        ExecuteRequest: function (completeUrl, data, authkey, authValue, callback) {
            if (callback != null && typeof (callback) != "function")
                throw "Callback must be null of a function";

            if (data == null)
                data = {};

            var startTime = new Date();
            var requestBody = JSON.stringify(data);

            var xhr = new XMLHttpRequest();
            // window.console.log("URL: " + completeUrl);
            xhr.open("POST", completeUrl, true);

            xhr.setRequestHeader('Content-Type', 'application/json');

            if (authkey != null)
                xhr.setRequestHeader(authkey, authValue);

            xhr.setRequestHeader('X-PlayFabSDK', "JavaScriptSDK-" + PlayFab._internalSettings.sdkVersion);

            xhr.onloadend = function () {
                if (callback == null)
                    return;

                var result;
                try {
                    // window.console.log("parsing json result: " + xhr.responseText);
                    result = JSON.parse(xhr.responseText);
                } catch (e) {
                    result = {
                        code: 503, // Service Unavailable
                        status: "Service Unavailable",
                        error: "Connection error",
                        errorCode: 2, // PlayFabErrorCode.ConnectionError
                        errorMessage: xhr.responseText
                    };
                }

                result.CallBackTimeMS = new Date() - startTime;

                if (result.code === 200)
                    callback(result, null);
                else
                    callback(null, result);
            }

            xhr.onerror = function () {
                if (callback == null)
                    return;

                var result;
                try {
                    result = JSON.parse(xhr.responseText);
                } catch (e) {
                    result = {
                        code: 503, // Service Unavailable
                        status: "Service Unavailable",
                        error: "Connection error",
                        errorCode: 2, // PlayFabErrorCode.ConnectionError
                        errorMessage: xhr.responseText
                    };
                }

                result.CallBackTimeMS = new Date() - startTime;
                callback(null, result);
            }

            xhr.send(requestBody);
        }
    }
}

PlayFab.ServerApi = {
    AuthenticateSessionTicket: function (request, callback) {
        if (PlayFab.settings.developerSecretKey == null) throw "Must have PlayFab.settings.developerSecretKey set to call this method";

        PlayFab._internalSettings.ExecuteRequest(PlayFab._internalSettings.GetServerUrl() + "/Server/AuthenticateSessionTicket", request, "X-SecretKey", PlayFab.settings.developerSecretKey, callback);
    },

    GetPlayFabIDsFromFacebookIDs: function (request, callback) {
        if (PlayFab.settings.developerSecretKey == null) throw "Must have PlayFab.settings.developerSecretKey set to call this method";

        PlayFab._internalSettings.ExecuteRequest(PlayFab._internalSettings.GetServerUrl() + "/Server/GetPlayFabIDsFromFacebookIDs", request, "X-SecretKey", PlayFab.settings.developerSecretKey, callback);
    },

    GetPlayFabIDsFromSteamIDs: function (request, callback) {
        if (PlayFab.settings.developerSecretKey == null) throw "Must have PlayFab.settings.developerSecretKey set to call this method";

        PlayFab._internalSettings.ExecuteRequest(PlayFab._internalSettings.GetServerUrl() + "/Server/GetPlayFabIDsFromSteamIDs", request, "X-SecretKey", PlayFab.settings.developerSecretKey, callback);
    },

    GetUserAccountInfo: function (request, callback) {
        if (PlayFab.settings.developerSecretKey == null) throw "Must have PlayFab.settings.developerSecretKey set to call this method";

        PlayFab._internalSettings.ExecuteRequest(PlayFab._internalSettings.GetServerUrl() + "/Server/GetUserAccountInfo", request, "X-SecretKey", PlayFab.settings.developerSecretKey, callback);
    },

    SendPushNotification: function (request, callback) {
        if (PlayFab.settings.developerSecretKey == null) throw "Must have PlayFab.settings.developerSecretKey set to call this method";

        PlayFab._internalSettings.ExecuteRequest(PlayFab._internalSettings.GetServerUrl() + "/Server/SendPushNotification", request, "X-SecretKey", PlayFab.settings.developerSecretKey, callback);
    },

    DeleteUsers: function (request, callback) {
        if (PlayFab.settings.developerSecretKey == null) throw "Must have PlayFab.settings.developerSecretKey set to call this method";

        PlayFab._internalSettings.ExecuteRequest(PlayFab._internalSettings.GetServerUrl() + "/Server/DeleteUsers", request, "X-SecretKey", PlayFab.settings.developerSecretKey, callback);
    },

    GetLeaderboard: function (request, callback) {
        if (PlayFab.settings.developerSecretKey == null) throw "Must have PlayFab.settings.developerSecretKey set to call this method";

        PlayFab._internalSettings.ExecuteRequest(PlayFab._internalSettings.GetServerUrl() + "/Server/GetLeaderboard", request, "X-SecretKey", PlayFab.settings.developerSecretKey, callback);
    },

    GetLeaderboardAroundUser: function (request, callback) {
        if (PlayFab.settings.developerSecretKey == null) throw "Must have PlayFab.settings.developerSecretKey set to call this method";

        PlayFab._internalSettings.ExecuteRequest(PlayFab._internalSettings.GetServerUrl() + "/Server/GetLeaderboardAroundUser", request, "X-SecretKey", PlayFab.settings.developerSecretKey, callback);
    },

    GetPlayerStatistics: function (request, callback) {
        if (PlayFab.settings.developerSecretKey == null) throw "Must have PlayFab.settings.developerSecretKey set to call this method";

        PlayFab._internalSettings.ExecuteRequest(PlayFab._internalSettings.GetServerUrl() + "/Server/GetPlayerStatistics", request, "X-SecretKey", PlayFab.settings.developerSecretKey, callback);
    },

    GetPlayerStatisticVersions: function (request, callback) {
        if (PlayFab.settings.developerSecretKey == null) throw "Must have PlayFab.settings.developerSecretKey set to call this method";

        PlayFab._internalSettings.ExecuteRequest(PlayFab._internalSettings.GetServerUrl() + "/Server/GetPlayerStatisticVersions", request, "X-SecretKey", PlayFab.settings.developerSecretKey, callback);
    },

    GetUserData: function (request, callback) {
        if (PlayFab.settings.developerSecretKey == null) throw "Must have PlayFab.settings.developerSecretKey set to call this method";

        PlayFab._internalSettings.ExecuteRequest(PlayFab._internalSettings.GetServerUrl() + "/Server/GetUserData", request, "X-SecretKey", PlayFab.settings.developerSecretKey, callback);
    },

    GetUserInternalData: function (request, callback) {
        if (PlayFab.settings.developerSecretKey == null) throw "Must have PlayFab.settings.developerSecretKey set to call this method";

        PlayFab._internalSettings.ExecuteRequest(PlayFab._internalSettings.GetServerUrl() + "/Server/GetUserInternalData", request, "X-SecretKey", PlayFab.settings.developerSecretKey, callback);
    },

    GetUserPublisherData: function (request, callback) {
        if (PlayFab.settings.developerSecretKey == null) throw "Must have PlayFab.settings.developerSecretKey set to call this method";

        PlayFab._internalSettings.ExecuteRequest(PlayFab._internalSettings.GetServerUrl() + "/Server/GetUserPublisherData", request, "X-SecretKey", PlayFab.settings.developerSecretKey, callback);
    },

    GetUserPublisherInternalData: function (request, callback) {
        if (PlayFab.settings.developerSecretKey == null) throw "Must have PlayFab.settings.developerSecretKey set to call this method";

        PlayFab._internalSettings.ExecuteRequest(PlayFab._internalSettings.GetServerUrl() + "/Server/GetUserPublisherInternalData", request, "X-SecretKey", PlayFab.settings.developerSecretKey, callback);
    },

    GetUserPublisherReadOnlyData: function (request, callback) {
        if (PlayFab.settings.developerSecretKey == null) throw "Must have PlayFab.settings.developerSecretKey set to call this method";

        PlayFab._internalSettings.ExecuteRequest(PlayFab._internalSettings.GetServerUrl() + "/Server/GetUserPublisherReadOnlyData", request, "X-SecretKey", PlayFab.settings.developerSecretKey, callback);
    },

    GetUserReadOnlyData: function (request, callback) {
        if (PlayFab.settings.developerSecretKey == null) throw "Must have PlayFab.settings.developerSecretKey set to call this method";

        PlayFab._internalSettings.ExecuteRequest(PlayFab._internalSettings.GetServerUrl() + "/Server/GetUserReadOnlyData", request, "X-SecretKey", PlayFab.settings.developerSecretKey, callback);
    },

    GetUserStatistics: function (request, callback) {
        if (PlayFab.settings.developerSecretKey == null) throw "Must have PlayFab.settings.developerSecretKey set to call this method";

        PlayFab._internalSettings.ExecuteRequest(PlayFab._internalSettings.GetServerUrl() + "/Server/GetUserStatistics", request, "X-SecretKey", PlayFab.settings.developerSecretKey, callback);
    },

    UpdatePlayerStatistics: function (request, callback) {
        if (PlayFab.settings.developerSecretKey == null) throw "Must have PlayFab.settings.developerSecretKey set to call this method";

        PlayFab._internalSettings.ExecuteRequest(PlayFab._internalSettings.GetServerUrl() + "/Server/UpdatePlayerStatistics", request, "X-SecretKey", PlayFab.settings.developerSecretKey, callback);
    },

    UpdateUserData: function (request, callback) {
        if (PlayFab.settings.developerSecretKey == null) throw "Must have PlayFab.settings.developerSecretKey set to call this method";

        PlayFab._internalSettings.ExecuteRequest(PlayFab._internalSettings.GetServerUrl() + "/Server/UpdateUserData", request, "X-SecretKey", PlayFab.settings.developerSecretKey, callback);
    },

    UpdateUserInternalData: function (request, callback) {
        if (PlayFab.settings.developerSecretKey == null) throw "Must have PlayFab.settings.developerSecretKey set to call this method";

        PlayFab._internalSettings.ExecuteRequest(PlayFab._internalSettings.GetServerUrl() + "/Server/UpdateUserInternalData", request, "X-SecretKey", PlayFab.settings.developerSecretKey, callback);
    },

    UpdateUserPublisherData: function (request, callback) {
        if (PlayFab.settings.developerSecretKey == null) throw "Must have PlayFab.settings.developerSecretKey set to call this method";

        PlayFab._internalSettings.ExecuteRequest(PlayFab._internalSettings.GetServerUrl() + "/Server/UpdateUserPublisherData", request, "X-SecretKey", PlayFab.settings.developerSecretKey, callback);
    },

    UpdateUserPublisherInternalData: function (request, callback) {
        if (PlayFab.settings.developerSecretKey == null) throw "Must have PlayFab.settings.developerSecretKey set to call this method";

        PlayFab._internalSettings.ExecuteRequest(PlayFab._internalSettings.GetServerUrl() + "/Server/UpdateUserPublisherInternalData", request, "X-SecretKey", PlayFab.settings.developerSecretKey, callback);
    },

    UpdateUserPublisherReadOnlyData: function (request, callback) {
        if (PlayFab.settings.developerSecretKey == null) throw "Must have PlayFab.settings.developerSecretKey set to call this method";

        PlayFab._internalSettings.ExecuteRequest(PlayFab._internalSettings.GetServerUrl() + "/Server/UpdateUserPublisherReadOnlyData", request, "X-SecretKey", PlayFab.settings.developerSecretKey, callback);
    },

    UpdateUserReadOnlyData: function (request, callback) {
        if (PlayFab.settings.developerSecretKey == null) throw "Must have PlayFab.settings.developerSecretKey set to call this method";

        PlayFab._internalSettings.ExecuteRequest(PlayFab._internalSettings.GetServerUrl() + "/Server/UpdateUserReadOnlyData", request, "X-SecretKey", PlayFab.settings.developerSecretKey, callback);
    },

    UpdateUserStatistics: function (request, callback) {
        if (PlayFab.settings.developerSecretKey == null) throw "Must have PlayFab.settings.developerSecretKey set to call this method";

        PlayFab._internalSettings.ExecuteRequest(PlayFab._internalSettings.GetServerUrl() + "/Server/UpdateUserStatistics", request, "X-SecretKey", PlayFab.settings.developerSecretKey, callback);
    },

    GetCatalogItems: function (request, callback) {
        if (PlayFab.settings.developerSecretKey == null) throw "Must have PlayFab.settings.developerSecretKey set to call this method";

        PlayFab._internalSettings.ExecuteRequest(PlayFab._internalSettings.GetServerUrl() + "/Server/GetCatalogItems", request, "X-SecretKey", PlayFab.settings.developerSecretKey, callback);
    },

    GetPublisherData: function (request, callback) {
        if (PlayFab.settings.developerSecretKey == null) throw "Must have PlayFab.settings.developerSecretKey set to call this method";

        PlayFab._internalSettings.ExecuteRequest(PlayFab._internalSettings.GetServerUrl() + "/Server/GetPublisherData", request, "X-SecretKey", PlayFab.settings.developerSecretKey, callback);
    },

    GetTitleData: function (request, callback) {
        if (PlayFab.settings.developerSecretKey == null) throw "Must have PlayFab.settings.developerSecretKey set to call this method";

        PlayFab._internalSettings.ExecuteRequest(PlayFab._internalSettings.GetServerUrl() + "/Server/GetTitleData", request, "X-SecretKey", PlayFab.settings.developerSecretKey, callback);
    },

    GetTitleInternalData: function (request, callback) {
        if (PlayFab.settings.developerSecretKey == null) throw "Must have PlayFab.settings.developerSecretKey set to call this method";

        PlayFab._internalSettings.ExecuteRequest(PlayFab._internalSettings.GetServerUrl() + "/Server/GetTitleInternalData", request, "X-SecretKey", PlayFab.settings.developerSecretKey, callback);
    },

    GetTitleNews: function (request, callback) {
        if (PlayFab.settings.developerSecretKey == null) throw "Must have PlayFab.settings.developerSecretKey set to call this method";

        PlayFab._internalSettings.ExecuteRequest(PlayFab._internalSettings.GetServerUrl() + "/Server/GetTitleNews", request, "X-SecretKey", PlayFab.settings.developerSecretKey, callback);
    },

    SetPublisherData: function (request, callback) {
        if (PlayFab.settings.developerSecretKey == null) throw "Must have PlayFab.settings.developerSecretKey set to call this method";

        PlayFab._internalSettings.ExecuteRequest(PlayFab._internalSettings.GetServerUrl() + "/Server/SetPublisherData", request, "X-SecretKey", PlayFab.settings.developerSecretKey, callback);
    },

    SetTitleData: function (request, callback) {
        if (PlayFab.settings.developerSecretKey == null) throw "Must have PlayFab.settings.developerSecretKey set to call this method";

        PlayFab._internalSettings.ExecuteRequest(PlayFab._internalSettings.GetServerUrl() + "/Server/SetTitleData", request, "X-SecretKey", PlayFab.settings.developerSecretKey, callback);
    },

    SetTitleInternalData: function (request, callback) {
        if (PlayFab.settings.developerSecretKey == null) throw "Must have PlayFab.settings.developerSecretKey set to call this method";

        PlayFab._internalSettings.ExecuteRequest(PlayFab._internalSettings.GetServerUrl() + "/Server/SetTitleInternalData", request, "X-SecretKey", PlayFab.settings.developerSecretKey, callback);
    },

    AddCharacterVirtualCurrency: function (request, callback) {
        if (PlayFab.settings.developerSecretKey == null) throw "Must have PlayFab.settings.developerSecretKey set to call this method";

        PlayFab._internalSettings.ExecuteRequest(PlayFab._internalSettings.GetServerUrl() + "/Server/AddCharacterVirtualCurrency", request, "X-SecretKey", PlayFab.settings.developerSecretKey, callback);
    },

    AddUserVirtualCurrency: function (request, callback) {
        if (PlayFab.settings.developerSecretKey == null) throw "Must have PlayFab.settings.developerSecretKey set to call this method";

        PlayFab._internalSettings.ExecuteRequest(PlayFab._internalSettings.GetServerUrl() + "/Server/AddUserVirtualCurrency", request, "X-SecretKey", PlayFab.settings.developerSecretKey, callback);
    },

    ConsumeItem: function (request, callback) {
        if (PlayFab.settings.developerSecretKey == null) throw "Must have PlayFab.settings.developerSecretKey set to call this method";

        PlayFab._internalSettings.ExecuteRequest(PlayFab._internalSettings.GetServerUrl() + "/Server/ConsumeItem", request, "X-SecretKey", PlayFab.settings.developerSecretKey, callback);
    },

    EvaluateRandomResultTable: function (request, callback) {
        if (PlayFab.settings.developerSecretKey == null) throw "Must have PlayFab.settings.developerSecretKey set to call this method";

        PlayFab._internalSettings.ExecuteRequest(PlayFab._internalSettings.GetServerUrl() + "/Server/EvaluateRandomResultTable", request, "X-SecretKey", PlayFab.settings.developerSecretKey, callback);
    },

    GetCharacterInventory: function (request, callback) {
        if (PlayFab.settings.developerSecretKey == null) throw "Must have PlayFab.settings.developerSecretKey set to call this method";

        PlayFab._internalSettings.ExecuteRequest(PlayFab._internalSettings.GetServerUrl() + "/Server/GetCharacterInventory", request, "X-SecretKey", PlayFab.settings.developerSecretKey, callback);
    },

    GetUserInventory: function (request, callback) {
        if (PlayFab.settings.developerSecretKey == null) throw "Must have PlayFab.settings.developerSecretKey set to call this method";

        PlayFab._internalSettings.ExecuteRequest(PlayFab._internalSettings.GetServerUrl() + "/Server/GetUserInventory", request, "X-SecretKey", PlayFab.settings.developerSecretKey, callback);
    },

    GrantItemsToCharacter: function (request, callback) {
        if (PlayFab.settings.developerSecretKey == null) throw "Must have PlayFab.settings.developerSecretKey set to call this method";

        PlayFab._internalSettings.ExecuteRequest(PlayFab._internalSettings.GetServerUrl() + "/Server/GrantItemsToCharacter", request, "X-SecretKey", PlayFab.settings.developerSecretKey, callback);
    },

    GrantItemsToUser: function (request, callback) {
        if (PlayFab.settings.developerSecretKey == null) throw "Must have PlayFab.settings.developerSecretKey set to call this method";

        PlayFab._internalSettings.ExecuteRequest(PlayFab._internalSettings.GetServerUrl() + "/Server/GrantItemsToUser", request, "X-SecretKey", PlayFab.settings.developerSecretKey, callback);
    },

    GrantItemsToUsers: function (request, callback) {
        if (PlayFab.settings.developerSecretKey == null) throw "Must have PlayFab.settings.developerSecretKey set to call this method";

        PlayFab._internalSettings.ExecuteRequest(PlayFab._internalSettings.GetServerUrl() + "/Server/GrantItemsToUsers", request, "X-SecretKey", PlayFab.settings.developerSecretKey, callback);
    },

    ModifyItemUses: function (request, callback) {
        if (PlayFab.settings.developerSecretKey == null) throw "Must have PlayFab.settings.developerSecretKey set to call this method";

        PlayFab._internalSettings.ExecuteRequest(PlayFab._internalSettings.GetServerUrl() + "/Server/ModifyItemUses", request, "X-SecretKey", PlayFab.settings.developerSecretKey, callback);
    },

    MoveItemToCharacterFromCharacter: function (request, callback) {
        if (PlayFab.settings.developerSecretKey == null) throw "Must have PlayFab.settings.developerSecretKey set to call this method";

        PlayFab._internalSettings.ExecuteRequest(PlayFab._internalSettings.GetServerUrl() + "/Server/MoveItemToCharacterFromCharacter", request, "X-SecretKey", PlayFab.settings.developerSecretKey, callback);
    },

    MoveItemToCharacterFromUser: function (request, callback) {
        if (PlayFab.settings.developerSecretKey == null) throw "Must have PlayFab.settings.developerSecretKey set to call this method";

        PlayFab._internalSettings.ExecuteRequest(PlayFab._internalSettings.GetServerUrl() + "/Server/MoveItemToCharacterFromUser", request, "X-SecretKey", PlayFab.settings.developerSecretKey, callback);
    },

    MoveItemToUserFromCharacter: function (request, callback) {
        if (PlayFab.settings.developerSecretKey == null) throw "Must have PlayFab.settings.developerSecretKey set to call this method";

        PlayFab._internalSettings.ExecuteRequest(PlayFab._internalSettings.GetServerUrl() + "/Server/MoveItemToUserFromCharacter", request, "X-SecretKey", PlayFab.settings.developerSecretKey, callback);
    },

    RedeemCoupon: function (request, callback) {
        if (PlayFab.settings.developerSecretKey == null) throw "Must have PlayFab.settings.developerSecretKey set to call this method";

        PlayFab._internalSettings.ExecuteRequest(PlayFab._internalSettings.GetServerUrl() + "/Server/RedeemCoupon", request, "X-SecretKey", PlayFab.settings.developerSecretKey, callback);
    },

    ReportPlayer: function (request, callback) {
        if (PlayFab.settings.developerSecretKey == null) throw "Must have PlayFab.settings.developerSecretKey set to call this method";

        PlayFab._internalSettings.ExecuteRequest(PlayFab._internalSettings.GetServerUrl() + "/Server/ReportPlayer", request, "X-SecretKey", PlayFab.settings.developerSecretKey, callback);
    },

    RevokeInventoryItem: function (request, callback) {
        if (PlayFab.settings.developerSecretKey == null) throw "Must have PlayFab.settings.developerSecretKey set to call this method";

        PlayFab._internalSettings.ExecuteRequest(PlayFab._internalSettings.GetServerUrl() + "/Server/RevokeInventoryItem", request, "X-SecretKey", PlayFab.settings.developerSecretKey, callback);
    },

    SubtractCharacterVirtualCurrency: function (request, callback) {
        if (PlayFab.settings.developerSecretKey == null) throw "Must have PlayFab.settings.developerSecretKey set to call this method";

        PlayFab._internalSettings.ExecuteRequest(PlayFab._internalSettings.GetServerUrl() + "/Server/SubtractCharacterVirtualCurrency", request, "X-SecretKey", PlayFab.settings.developerSecretKey, callback);
    },

    SubtractUserVirtualCurrency: function (request, callback) {
        if (PlayFab.settings.developerSecretKey == null) throw "Must have PlayFab.settings.developerSecretKey set to call this method";

        PlayFab._internalSettings.ExecuteRequest(PlayFab._internalSettings.GetServerUrl() + "/Server/SubtractUserVirtualCurrency", request, "X-SecretKey", PlayFab.settings.developerSecretKey, callback);
    },

    UnlockContainerInstance: function (request, callback) {
        if (PlayFab.settings.developerSecretKey == null) throw "Must have PlayFab.settings.developerSecretKey set to call this method";

        PlayFab._internalSettings.ExecuteRequest(PlayFab._internalSettings.GetServerUrl() + "/Server/UnlockContainerInstance", request, "X-SecretKey", PlayFab.settings.developerSecretKey, callback);
    },

    UnlockContainerItem: function (request, callback) {
        if (PlayFab.settings.developerSecretKey == null) throw "Must have PlayFab.settings.developerSecretKey set to call this method";

        PlayFab._internalSettings.ExecuteRequest(PlayFab._internalSettings.GetServerUrl() + "/Server/UnlockContainerItem", request, "X-SecretKey", PlayFab.settings.developerSecretKey, callback);
    },

    UpdateUserInventoryItemCustomData: function (request, callback) {
        if (PlayFab.settings.developerSecretKey == null) throw "Must have PlayFab.settings.developerSecretKey set to call this method";

        PlayFab._internalSettings.ExecuteRequest(PlayFab._internalSettings.GetServerUrl() + "/Server/UpdateUserInventoryItemCustomData", request, "X-SecretKey", PlayFab.settings.developerSecretKey, callback);
    },

    NotifyMatchmakerPlayerLeft: function (request, callback) {
        if (PlayFab.settings.developerSecretKey == null) throw "Must have PlayFab.settings.developerSecretKey set to call this method";

        PlayFab._internalSettings.ExecuteRequest(PlayFab._internalSettings.GetServerUrl() + "/Server/NotifyMatchmakerPlayerLeft", request, "X-SecretKey", PlayFab.settings.developerSecretKey, callback);
    },

    RedeemMatchmakerTicket: function (request, callback) {
        if (PlayFab.settings.developerSecretKey == null) throw "Must have PlayFab.settings.developerSecretKey set to call this method";

        PlayFab._internalSettings.ExecuteRequest(PlayFab._internalSettings.GetServerUrl() + "/Server/RedeemMatchmakerTicket", request, "X-SecretKey", PlayFab.settings.developerSecretKey, callback);
    },

    AwardSteamAchievement: function (request, callback) {
        if (PlayFab.settings.developerSecretKey == null) throw "Must have PlayFab.settings.developerSecretKey set to call this method";

        PlayFab._internalSettings.ExecuteRequest(PlayFab._internalSettings.GetServerUrl() + "/Server/AwardSteamAchievement", request, "X-SecretKey", PlayFab.settings.developerSecretKey, callback);
    },

    LogEvent: function (request, callback) {
        if (PlayFab.settings.developerSecretKey == null) throw "Must have PlayFab.settings.developerSecretKey set to call this method";

        PlayFab._internalSettings.ExecuteRequest(PlayFab._internalSettings.GetServerUrl() + "/Server/LogEvent", request, "X-SecretKey", PlayFab.settings.developerSecretKey, callback);
    },

    WriteCharacterEvent: function (request, callback) {
        if (PlayFab.settings.developerSecretKey == null) throw "Must have PlayFab.settings.developerSecretKey set to call this method";

        PlayFab._internalSettings.ExecuteRequest(PlayFab._internalSettings.GetServerUrl() + "/Server/WriteCharacterEvent", request, "X-SecretKey", PlayFab.settings.developerSecretKey, callback);
    },

    WritePlayerEvent: function (request, callback) {
        if (PlayFab.settings.developerSecretKey == null) throw "Must have PlayFab.settings.developerSecretKey set to call this method";

        PlayFab._internalSettings.ExecuteRequest(PlayFab._internalSettings.GetServerUrl() + "/Server/WritePlayerEvent", request, "X-SecretKey", PlayFab.settings.developerSecretKey, callback);
    },

    WriteTitleEvent: function (request, callback) {
        if (PlayFab.settings.developerSecretKey == null) throw "Must have PlayFab.settings.developerSecretKey set to call this method";

        PlayFab._internalSettings.ExecuteRequest(PlayFab._internalSettings.GetServerUrl() + "/Server/WriteTitleEvent", request, "X-SecretKey", PlayFab.settings.developerSecretKey, callback);
    },

    AddSharedGroupMembers: function (request, callback) {
        if (PlayFab.settings.developerSecretKey == null) throw "Must have PlayFab.settings.developerSecretKey set to call this method";

        PlayFab._internalSettings.ExecuteRequest(PlayFab._internalSettings.GetServerUrl() + "/Server/AddSharedGroupMembers", request, "X-SecretKey", PlayFab.settings.developerSecretKey, callback);
    },

    CreateSharedGroup: function (request, callback) {
        if (PlayFab.settings.developerSecretKey == null) throw "Must have PlayFab.settings.developerSecretKey set to call this method";

        PlayFab._internalSettings.ExecuteRequest(PlayFab._internalSettings.GetServerUrl() + "/Server/CreateSharedGroup", request, "X-SecretKey", PlayFab.settings.developerSecretKey, callback);
    },

    DeleteSharedGroup: function (request, callback) {
        if (PlayFab.settings.developerSecretKey == null) throw "Must have PlayFab.settings.developerSecretKey set to call this method";

        PlayFab._internalSettings.ExecuteRequest(PlayFab._internalSettings.GetServerUrl() + "/Server/DeleteSharedGroup", request, "X-SecretKey", PlayFab.settings.developerSecretKey, callback);
    },

    GetSharedGroupData: function (request, callback) {
        if (PlayFab.settings.developerSecretKey == null) throw "Must have PlayFab.settings.developerSecretKey set to call this method";

        PlayFab._internalSettings.ExecuteRequest(PlayFab._internalSettings.GetServerUrl() + "/Server/GetSharedGroupData", request, "X-SecretKey", PlayFab.settings.developerSecretKey, callback);
    },

    RemoveSharedGroupMembers: function (request, callback) {
        if (PlayFab.settings.developerSecretKey == null) throw "Must have PlayFab.settings.developerSecretKey set to call this method";

        PlayFab._internalSettings.ExecuteRequest(PlayFab._internalSettings.GetServerUrl() + "/Server/RemoveSharedGroupMembers", request, "X-SecretKey", PlayFab.settings.developerSecretKey, callback);
    },

    UpdateSharedGroupData: function (request, callback) {
        if (PlayFab.settings.developerSecretKey == null) throw "Must have PlayFab.settings.developerSecretKey set to call this method";

        PlayFab._internalSettings.ExecuteRequest(PlayFab._internalSettings.GetServerUrl() + "/Server/UpdateSharedGroupData", request, "X-SecretKey", PlayFab.settings.developerSecretKey, callback);
    },

    ExecuteCloudScript: function (request, callback) {
        if (PlayFab.settings.developerSecretKey == null) throw "Must have PlayFab.settings.developerSecretKey set to call this method";

        PlayFab._internalSettings.ExecuteRequest(PlayFab._internalSettings.GetServerUrl() + "/Server/ExecuteCloudScript", request, "X-SecretKey", PlayFab.settings.developerSecretKey, callback);
    },

    GetContentDownloadUrl: function (request, callback) {
        if (PlayFab.settings.developerSecretKey == null) throw "Must have PlayFab.settings.developerSecretKey set to call this method";

        PlayFab._internalSettings.ExecuteRequest(PlayFab._internalSettings.GetServerUrl() + "/Server/GetContentDownloadUrl", request, "X-SecretKey", PlayFab.settings.developerSecretKey, callback);
    },

    DeleteCharacterFromUser: function (request, callback) {
        if (PlayFab.settings.developerSecretKey == null) throw "Must have PlayFab.settings.developerSecretKey set to call this method";

        PlayFab._internalSettings.ExecuteRequest(PlayFab._internalSettings.GetServerUrl() + "/Server/DeleteCharacterFromUser", request, "X-SecretKey", PlayFab.settings.developerSecretKey, callback);
    },

    GetAllUsersCharacters: function (request, callback) {
        if (PlayFab.settings.developerSecretKey == null) throw "Must have PlayFab.settings.developerSecretKey set to call this method";

        PlayFab._internalSettings.ExecuteRequest(PlayFab._internalSettings.GetServerUrl() + "/Server/GetAllUsersCharacters", request, "X-SecretKey", PlayFab.settings.developerSecretKey, callback);
    },

    GetCharacterLeaderboard: function (request, callback) {
        if (PlayFab.settings.developerSecretKey == null) throw "Must have PlayFab.settings.developerSecretKey set to call this method";

        PlayFab._internalSettings.ExecuteRequest(PlayFab._internalSettings.GetServerUrl() + "/Server/GetCharacterLeaderboard", request, "X-SecretKey", PlayFab.settings.developerSecretKey, callback);
    },

    GetCharacterStatistics: function (request, callback) {
        if (PlayFab.settings.developerSecretKey == null) throw "Must have PlayFab.settings.developerSecretKey set to call this method";

        PlayFab._internalSettings.ExecuteRequest(PlayFab._internalSettings.GetServerUrl() + "/Server/GetCharacterStatistics", request, "X-SecretKey", PlayFab.settings.developerSecretKey, callback);
    },

    GetLeaderboardAroundCharacter: function (request, callback) {
        if (PlayFab.settings.developerSecretKey == null) throw "Must have PlayFab.settings.developerSecretKey set to call this method";

        PlayFab._internalSettings.ExecuteRequest(PlayFab._internalSettings.GetServerUrl() + "/Server/GetLeaderboardAroundCharacter", request, "X-SecretKey", PlayFab.settings.developerSecretKey, callback);
    },

    GetLeaderboardForUserCharacters: function (request, callback) {
        if (PlayFab.settings.developerSecretKey == null) throw "Must have PlayFab.settings.developerSecretKey set to call this method";

        PlayFab._internalSettings.ExecuteRequest(PlayFab._internalSettings.GetServerUrl() + "/Server/GetLeaderboardForUserCharacters", request, "X-SecretKey", PlayFab.settings.developerSecretKey, callback);
    },

    GrantCharacterToUser: function (request, callback) {
        if (PlayFab.settings.developerSecretKey == null) throw "Must have PlayFab.settings.developerSecretKey set to call this method";

        PlayFab._internalSettings.ExecuteRequest(PlayFab._internalSettings.GetServerUrl() + "/Server/GrantCharacterToUser", request, "X-SecretKey", PlayFab.settings.developerSecretKey, callback);
    },

    UpdateCharacterStatistics: function (request, callback) {
        if (PlayFab.settings.developerSecretKey == null) throw "Must have PlayFab.settings.developerSecretKey set to call this method";

        PlayFab._internalSettings.ExecuteRequest(PlayFab._internalSettings.GetServerUrl() + "/Server/UpdateCharacterStatistics", request, "X-SecretKey", PlayFab.settings.developerSecretKey, callback);
    },

    GetCharacterData: function (request, callback) {
        if (PlayFab.settings.developerSecretKey == null) throw "Must have PlayFab.settings.developerSecretKey set to call this method";

        PlayFab._internalSettings.ExecuteRequest(PlayFab._internalSettings.GetServerUrl() + "/Server/GetCharacterData", request, "X-SecretKey", PlayFab.settings.developerSecretKey, callback);
    },

    GetCharacterInternalData: function (request, callback) {
        if (PlayFab.settings.developerSecretKey == null) throw "Must have PlayFab.settings.developerSecretKey set to call this method";

        PlayFab._internalSettings.ExecuteRequest(PlayFab._internalSettings.GetServerUrl() + "/Server/GetCharacterInternalData", request, "X-SecretKey", PlayFab.settings.developerSecretKey, callback);
    },

    GetCharacterReadOnlyData: function (request, callback) {
        if (PlayFab.settings.developerSecretKey == null) throw "Must have PlayFab.settings.developerSecretKey set to call this method";

        PlayFab._internalSettings.ExecuteRequest(PlayFab._internalSettings.GetServerUrl() + "/Server/GetCharacterReadOnlyData", request, "X-SecretKey", PlayFab.settings.developerSecretKey, callback);
    },

    UpdateCharacterData: function (request, callback) {
        if (PlayFab.settings.developerSecretKey == null) throw "Must have PlayFab.settings.developerSecretKey set to call this method";

        PlayFab._internalSettings.ExecuteRequest(PlayFab._internalSettings.GetServerUrl() + "/Server/UpdateCharacterData", request, "X-SecretKey", PlayFab.settings.developerSecretKey, callback);
    },

    UpdateCharacterInternalData: function (request, callback) {
        if (PlayFab.settings.developerSecretKey == null) throw "Must have PlayFab.settings.developerSecretKey set to call this method";

        PlayFab._internalSettings.ExecuteRequest(PlayFab._internalSettings.GetServerUrl() + "/Server/UpdateCharacterInternalData", request, "X-SecretKey", PlayFab.settings.developerSecretKey, callback);
    },

    UpdateCharacterReadOnlyData: function (request, callback) {
        if (PlayFab.settings.developerSecretKey == null) throw "Must have PlayFab.settings.developerSecretKey set to call this method";

        PlayFab._internalSettings.ExecuteRequest(PlayFab._internalSettings.GetServerUrl() + "/Server/UpdateCharacterReadOnlyData", request, "X-SecretKey", PlayFab.settings.developerSecretKey, callback);
    },
};

var PlayFabServerSDK = PlayFab.ServerApi;
