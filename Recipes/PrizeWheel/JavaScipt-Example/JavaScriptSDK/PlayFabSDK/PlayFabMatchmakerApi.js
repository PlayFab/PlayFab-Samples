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
        sdkVersion: "0.11.160222",
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

PlayFab.MatchmakerApi = {
    AuthUser: function (request, callback) {
        if (PlayFab.settings.developerSecretKey == null) throw "Must have PlayFab.settings.developerSecretKey set to call this method";

        PlayFab._internalSettings.ExecuteRequest(PlayFab._internalSettings.GetServerUrl() + "/Matchmaker/AuthUser", request, "X-SecretKey", PlayFab.settings.developerSecretKey, callback);
    },

    PlayerJoined: function (request, callback) {
        if (PlayFab.settings.developerSecretKey == null) throw "Must have PlayFab.settings.developerSecretKey set to call this method";

        PlayFab._internalSettings.ExecuteRequest(PlayFab._internalSettings.GetServerUrl() + "/Matchmaker/PlayerJoined", request, "X-SecretKey", PlayFab.settings.developerSecretKey, callback);
    },

    PlayerLeft: function (request, callback) {
        if (PlayFab.settings.developerSecretKey == null) throw "Must have PlayFab.settings.developerSecretKey set to call this method";

        PlayFab._internalSettings.ExecuteRequest(PlayFab._internalSettings.GetServerUrl() + "/Matchmaker/PlayerLeft", request, "X-SecretKey", PlayFab.settings.developerSecretKey, callback);
    },

    StartGame: function (request, callback) {
        if (PlayFab.settings.developerSecretKey == null) throw "Must have PlayFab.settings.developerSecretKey set to call this method";

        PlayFab._internalSettings.ExecuteRequest(PlayFab._internalSettings.GetServerUrl() + "/Matchmaker/StartGame", request, "X-SecretKey", PlayFab.settings.developerSecretKey, callback);
    },

    UserInfo: function (request, callback) {
        if (PlayFab.settings.developerSecretKey == null) throw "Must have PlayFab.settings.developerSecretKey set to call this method";

        PlayFab._internalSettings.ExecuteRequest(PlayFab._internalSettings.GetServerUrl() + "/Matchmaker/UserInfo", request, "X-SecretKey", PlayFab.settings.developerSecretKey, callback);
    },
};

var PlayFabMatchmakerSDK = PlayFab.MatchmakerApi;
