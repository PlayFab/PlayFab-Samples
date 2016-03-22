if (typeof PlayFabClientSDK == 'undefined')
    console.log("PlayFabApiTest requires PlayFabClientApi.js to be pre-loaded.");
if (typeof PlayFabServerSDK == 'undefined')
    console.log("PlayFabApiTest requires PlayFabServerApi.js to be pre-loaded.");

var PlayFabApiTests = {
    testTitleDataFilename: "testTitleData.json", // TODO: Do not hard code the location of this file (javascript can't really do relative paths either)
    titleData: {
        titleId: null, // put titleId here
        developerSecretKey: null, // put secretKey here
        titleCanUpdateSettings: "true",
        userName: "put test username here",
        userEmail: "put valid email for userName here",
        userPassword: "put valid password for userName here",
        characterName: "put valid characterName for userName here",
    },
    testData: {
        playFabId: null, // Filled during login
        characterId: null, // Filled during character-access
        testNumber: null, // Used by several tests
    },
    testConstants: {
        TEST_KEY: "testCounter",
        TEST_STAT_NAME: "str",
    },

    ManualExecution: function () {
        $.getJSON(PlayFabApiTests.testTitleDataFilename, function (json) {
            if (PlayFabApiTests.SetUp(json))
                PlayFabApiTests.LoginTests();
        }).fail(function () {
            if (PlayFabApiTests.SetUp(PlayFabApiTests.titleData))
                PlayFabApiTests.LoginTests();
        });
    },

    LoginTests: function () {
        // All tests run completely synchronously, which is a bit tricky.
        //   Some test rely on data loaded from other tests, and there's no super easy to force tests to be sequential/dependent
        //   In fact, most of the tests return here before they're done, and report back success/fail in some arbitrary future

        QUnit.module("PlayFab Api Test");
        QUnit.test("InvalidLogin", PlayFabApiTests.InvalidLogin);
        QUnit.test("LoginOrRegister", PlayFabApiTests.LoginOrRegister);
        QUnit.test("LoginWithAdvertisingId", PlayFabApiTests.LoginWithAdvertisingId);

        setTimeout(function () { PlayFabApiTests.PostLoginTests(0); }, 200);
    },

    PostLoginTests: function (count) {
        if (count > 5)
            return;

        if (PlayFab._internalSettings.sessionTicket == null) {
            // Wait for login
            setTimeout(function () { PlayFabApiTests.PostLoginTests(count + 1); }, 200);
        } else {
            // Continue with other tests that require login
            QUnit.test("UserDataApi", PlayFabApiTests.UserDataApi);
            QUnit.test("UserStatisticsApi", PlayFabApiTests.UserStatisticsApi);
            QUnit.test("UserCharacter", PlayFabApiTests.UserCharacter);
            QUnit.test("LeaderBoard", PlayFabApiTests.LeaderBoard);
            QUnit.test("AccountInfo", PlayFabApiTests.AccountInfo);
            QUnit.test("CloudScript", PlayFabApiTests.CloudScript);
        }
    },

    SetUp: function (inputTitleData) {
        // All of these must exist for the titleData load to be successful
        var titleDataValid = inputTitleData.hasOwnProperty("titleId") && inputTitleData.titleId != null
        && inputTitleData.hasOwnProperty("developerSecretKey") && inputTitleData.developerSecretKey != null
        && inputTitleData.hasOwnProperty("titleCanUpdateSettings")
        && inputTitleData.hasOwnProperty("userName")
        && inputTitleData.hasOwnProperty("userEmail")
        && inputTitleData.hasOwnProperty("userPassword")
        && inputTitleData.hasOwnProperty("characterName");

        if (titleDataValid)
            PlayFabApiTests.titleData = inputTitleData;
        else
            console.log("testTitleData input file did not parse correctly");

        PlayFab.settings.titleId = PlayFabApiTests.titleData.titleId;
        PlayFab.settings.developerSecretKey = PlayFabApiTests.titleData.developerSecretKey;

        return titleDataValid;
    },
    
    CallbackWrapper: function (callbackName, Callback, assert) {
        return function (result, error) {
            try {
                Callback(result, error);
            } catch (e) {
                console.log("Exception thrown during " + callbackName + " callback: " + e.toString() + "\n" + e.stack); // Very irritatingly, qunit doesn't report failure results until all async callbacks return, which doesn't always happen when there's an exception
                assert.ok(false, "Exception thrown during " + callbackName + " callback: " + e.toString() + "\n" + e.stack);
            }
        };
    },
    
    SimpleCallbackWrapper: function (callbackName, Callback, assert) {
        return function () {
            try {
                Callback();
            } catch (e) {
                console.log("Exception thrown during " + callbackName + " callback: " + e.toString() + "\n" + e.stack); // Very irritatingly, qunit doesn't report failure results until all async callbacks return, which doesn't always happen when there's an exception
                assert.ok(false, "Exception thrown during " + callbackName + " callback: " + e.toString() + "\n" + e.stack);
            }
        };
    },

    VerifyNullError: function (result, error, assert, message) {
        var success = (result != null && error == null)
        if (!success)
            assert.ok(success, message);
        if (error != null)
            assert.ok(false, "PlayFab error message: " + error.errorMessage);
    },

    /// <summary>
    /// CLIENT API
    /// Try to deliberately log in with an inappropriate password,
    ///   and verify that the error displays as expected.
    /// </summary>
    InvalidLogin: function (assert) {
        var invalidRequest = {
            TitleId: PlayFab.settings.titleId,
            Email: PlayFabApiTests.titleData.userEmail,
            Password: PlayFabApiTests.titleData.userPassword + "INVALID",
        };

        var InvalidLoginCallback = function (result, error) {
            assert.ok(result == null, "Login should have failed");
            assert.ok(error != null, "Login should have failed");
            if (error != null)
                assert.ok(error.errorMessage.toLowerCase().indexOf("password") > -1, "Expect errorMessage about invalid password: " + error.errorMessage);
            invalidDone();
        };
        var invalidDone = assert.async();
        PlayFabClientSDK.LoginWithEmailAddress(invalidRequest, PlayFabApiTests.CallbackWrapper("InvalidLoginCallback", InvalidLoginCallback, assert));
    },

    /// <summary>
    /// CLIENT API
    /// Log in or create a user, track their PlayFabId
    /// </summary>
    LoginOrRegister: function (assert) {
        var loginRequest = {
            // Currently, you need to look up the correct format for this object in the API-docs:
            //   https://api.playfab.com/Documentation/Client/method/LoginWithEmailAddress
            TitleId: PlayFab.settings.titleId,
            Email: PlayFabApiTests.titleData.userEmail,
            Password: PlayFabApiTests.titleData.userPassword,
        };
        var registerRequest = {
            // Currently, you need to look up the correct format for this object in the API-docs:
            //   https://api.playfab.com/Documentation/Client/method/RegisterPlayFabUser
            TitleId: PlayFab.settings.titleId,
            Username: PlayFabApiTests.titleData.userName,
            Email: PlayFabApiTests.titleData.userEmail,
            Password: PlayFabApiTests.titleData.userPassword,
        };

        // We don't know at this point how many async calls we'll make
        var loginDone = null;
        var registerDone = null;

        var OptionalLoginCallback = function (result, error) {
            // First login falls back upon registration if login failed
            if (result == null) {
                // Register the character and try again
                registerDone = assert.async();
                PlayFabClientSDK.RegisterPlayFabUser(registerRequest, PlayFabApiTests.CallbackWrapper("RegisterCallback", RegisterCallback, assert));
                loginDone();
            }
            else {
                // Confirm the successful login
                MandatoryLoginCallback(result, error)
            }
        };
        var RegisterCallback = function (result, error) {
            // Second login MUST succeed
            PlayFabApiTests.VerifyNullError(result, error, assert, "Testing Registration result");

            // Log in again, this time with the newly registered account
            loginDone = assert.async();
            PlayFabClientSDK.LoginWithEmailAddress(loginRequest, PlayFabApiTests.CallbackWrapper("MandatoryLoginCallback", MandatoryLoginCallback, assert));
            registerDone();
        };
        var MandatoryLoginCallback = function (result, error) {
            // Login MUST succeed at some point during this test
            PlayFabApiTests.VerifyNullError(result, error, assert, "Testing Valid login result");
            assert.ok(PlayFab._internalSettings.sessionTicket != null, "Testing Login credentials cache");
            PlayFabApiTests.testData.playFabId = result.data.PlayFabId; // Save the PlayFabId, it will be used in other tests
            loginDone();
        };
        loginDone = assert.async();
        PlayFabClientSDK.LoginWithEmailAddress(loginRequest, PlayFabApiTests.CallbackWrapper("OptionalLoginCallback", OptionalLoginCallback, assert));
    },

    /// <summary>
    /// CLIENT API
    /// Test that the login call sequence sends the AdvertisingId when set
    /// </summary>
    LoginWithAdvertisingId: function (assert) {
        PlayFab.settings.advertisingIdType = PlayFab.settings.AD_TYPE_ANDROID_ID;
        PlayFab.settings.advertisingIdValue = "PlayFabTestId";

        assert.expect(0);
        var loginDone = assert.async();
        var count = -1;
        var FinishAdvertId = function () {
            count += 1;
            if (count > 10)
                assert.ok(false, "The advertisingId was not submitted properly");
            else if (PlayFab.settings.advertisingIdType === PlayFab.settings.AD_TYPE_ANDROID_ID + "_Successful")
                loginDone();
            else
                setTimeout(PlayFabApiTests.SimpleCallbackWrapper("FinishAdvertId", FinishAdvertId, assert), 200);
        };
        var AdvertLoginCallback = function (result, error) {
            setTimeout(PlayFabApiTests.SimpleCallbackWrapper("FinishAdvertId", FinishAdvertId, assert), 200);
        };
        var loginRequest = {
            TitleId: PlayFab.settings.titleId,
            Email: PlayFabApiTests.titleData.userEmail,
            Password: PlayFabApiTests.titleData.userPassword,
        };
        PlayFabClientSDK.LoginWithEmailAddress(loginRequest, PlayFabApiTests.CallbackWrapper("AdvertLoginCallback", AdvertLoginCallback, assert));
    },

    /// <summary>
    /// CLIENT API
    /// Test a sequence of calls that modifies saved data,
    ///   and verifies that the next sequential API call contains updated data.
    /// Verify that the data is correctly modified on the next call.
    /// Parameter types tested: string, Dictionary<string, string>, DateTime
    /// </summary>
    UserDataApi: function (assert) {
        var getDataRequest = {}; // null also works

        // This test is always exactly 3 async calls
        get1Done = assert.async();
        updateDone = assert.async();
        get2Done = assert.async();

        var GetDataCallback1 = function (result, error) {
            PlayFabApiTests.VerifyNullError(result, error, assert, "Testing GetUserData result");
            assert.ok(result.data.Data != null, "Testing GetUserData Data");
            assert.ok(result.data.Data.hasOwnProperty(PlayFabApiTests.testConstants.TEST_KEY), "Testing GetUserData DataKey");

            PlayFabApiTests.testData.testNumber = parseInt(result.data.Data[PlayFabApiTests.testConstants.TEST_KEY].Value, 10);
            PlayFabApiTests.testData.testNumber = (PlayFabApiTests.testData.testNumber + 1) % 100; // This test is about the expected value changing - but not testing more complicated issues like bounds

            var updateDataRequest = {}; // Can't create this until we have the testNumber value
            updateDataRequest.Data = {};
            updateDataRequest.Data[PlayFabApiTests.testConstants.TEST_KEY] = PlayFabApiTests.testData.testNumber;
            PlayFabClientSDK.UpdateUserData(updateDataRequest, PlayFabApiTests.CallbackWrapper("UpdateDataCallback", UpdateDataCallback, assert));
            get1Done();
        };
        var UpdateDataCallback = function (result, error) {
            PlayFabApiTests.VerifyNullError(result, error, assert, "Testing UpdateUserData result");

            PlayFabClientSDK.GetUserData(getDataRequest, PlayFabApiTests.CallbackWrapper("GetDataCallback2", GetDataCallback2, assert));
            updateDone();
        };
        var GetDataCallback2 = function (result, error) {
            PlayFabApiTests.VerifyNullError(result, error, assert, "Testing GetUserData result");
            assert.ok(result.data.Data != null, "Testing GetUserData Data");
            assert.ok(result.data.Data.hasOwnProperty(PlayFabApiTests.testConstants.TEST_KEY), "Testing GetUserData DataKey");

            var actualtestNumber = parseInt(result.data.Data[PlayFabApiTests.testConstants.TEST_KEY].Value, 10);
            var timeUpdated = new Date(result.data.Data[PlayFabApiTests.testConstants.TEST_KEY].LastUpdated);

            var now = Date.now();
            var testMin = now - (1000 * 60 * 5);
            var testMax = now + (1000 * 60 * 5);
            assert.equal(PlayFabApiTests.testData.testNumber, actualtestNumber, "Testing incrementing counter: " + PlayFabApiTests.testData.testNumber + "==" + actualtestNumber);
            assert.ok(testMin <= timeUpdated && timeUpdated <= testMax, "Testing incrementing timestamp: " + timeUpdated + " vs " + now);
            get2Done();
        };

        // Kick off this test process
        PlayFabClientSDK.GetUserData(getDataRequest, PlayFabApiTests.CallbackWrapper("GetDataCallback1", GetDataCallback1, assert));
    },

    /// <summary>
    /// CLIENT API
    /// Test a sequence of calls that modifies saved data,
    ///   and verifies that the next sequential API call contains updated data.
    /// Verify that the data is saved correctly, and that specific types are tested
    /// Parameter types tested: Dictionary<string, int> 
    /// </summary>
    UserStatisticsApi: function (assert) {
        var getStatsRequest = {}; // null also works

        // This test is always exactly 3 async calls
        get1Done = assert.async();
        updateDone = assert.async();
        get2Done = assert.async();

        var GetStatsCallback1 = function (result, error) {
            PlayFabApiTests.VerifyNullError(result, error, assert, "Testing GetUserStats result");
            assert.ok(result.data.UserStatistics != null, "Testing GetUserData Stats");
            assert.ok(result.data.UserStatistics.hasOwnProperty(PlayFabApiTests.testConstants.TEST_STAT_NAME), "Testing GetUserData Stat-value");

            PlayFabApiTests.testData.testNumber = result.data.UserStatistics[PlayFabApiTests.testConstants.TEST_STAT_NAME];
            PlayFabApiTests.testData.testNumber = (PlayFabApiTests.testData.testNumber + 1) % 100; // This test is about the expected value changing - but not testing more complicated issues like bounds

            var updateStatsRequest = {}; // Can't create this until we have the testNumber value
            updateStatsRequest.UserStatistics = {};
            updateStatsRequest.UserStatistics[PlayFabApiTests.testConstants.TEST_STAT_NAME] = PlayFabApiTests.testData.testNumber;
            PlayFabClientSDK.UpdateUserStatistics(updateStatsRequest, PlayFabApiTests.CallbackWrapper("UpdateStatsCallback", UpdateStatsCallback, assert));
            get1Done();
        };
        var UpdateStatsCallback = function (result, error) {
            PlayFabApiTests.VerifyNullError(result, error, assert, "Testing UpdateUserStats result");
            PlayFabClientSDK.GetUserStatistics(getStatsRequest, PlayFabApiTests.CallbackWrapper("GetStatsCallback2", GetStatsCallback2, assert));
            updateDone();
        };
        var GetStatsCallback2 = function (result, error) {
            PlayFabApiTests.VerifyNullError(result, error, assert, "Testing GetUserStats result");
            assert.ok(result.data.UserStatistics != null, "Testing GetUserData Stats");
            assert.ok(result.data.UserStatistics.hasOwnProperty(PlayFabApiTests.testConstants.TEST_STAT_NAME), "Testing GetUserData Stat-value");

            var actualtestNumber = result.data.UserStatistics[PlayFabApiTests.testConstants.TEST_STAT_NAME];

            assert.equal(PlayFabApiTests.testData.testNumber, actualtestNumber, "Testing incrementing stat: " + PlayFabApiTests.testData.testNumber + "==" + actualtestNumber);
            get2Done();
        };

        // Kick off this test process
        PlayFabClientSDK.GetUserStatistics(getStatsRequest, PlayFabApiTests.CallbackWrapper("GetStatsCallback1", GetStatsCallback1, assert));
    },

    /// <summary>
    /// SERVER API
    /// Get or create the given test character for the given user
    /// Parameter types tested: Contained-Classes, string
    /// </summary>
    UserCharacter: function (assert) {
        var getCharsRequest = {};
        var grantCharRequest = {
            TitleId: PlayFabApiTests.titleData.titleId,
            PlayFabId: PlayFabApiTests.testData.playFabId,
            CharacterName: PlayFabApiTests.titleData.CHAR_NAME,
            CharacterType: PlayFabApiTests.titleData.CHAR_TEST_TYPE,
        };

        // We don't know at this point how many async calls we'll make
        var getDone = null;
        var grantDone = null;

        var OptionalGetCharsCallback = function (result, error) {
            // First get chars falls back upon grant-char if target character not present
            if (result == null) {
                // Register the character and try again
                grantDone = assert.async();
                PlayFabServerSDK.GrantCharacterToUser(grantCharRequest, PlayFabApiTests.CallbackWrapper("GrantCharCallback", GrantCharCallback, assert));
                getDone();
            }
            else {
                // Confirm the successful login
                MandatoryGetCharsCallback(result, error)
            }
        };
        var GrantCharCallback = function (result, error) {
            // Second character callback MUST succeed
            PlayFabApiTests.VerifyNullError(result, error, assert, "Testing GrantCharacter result");

            // Get chars again, this time with the newly granted character
            getDone = assert.async();
            PlayFabClientSDK.GetAllUsersCharacters(getCharsRequest, PlayFabApiTests.CallbackWrapper("MandatoryGetCharsCallback", MandatoryGetCharsCallback, assert));
            grantDone();
        };
        var MandatoryGetCharsCallback = function (result, error) {
            // GetChars MUST succeed at some point during this test
            PlayFabApiTests.VerifyNullError(result, error, assert, "Testing GetChars result");

            for (var i in result.data.Characters)
                if (result.data.Characters[i].CharacterName == PlayFabApiTests.titleData.characterName)
                    PlayFabApiTests.testData.characterId = result.data.Characters[i].CharacterId; // Save the characterId, it will be used in other tests

            assert.ok(PlayFabApiTests.testData.characterId != null, "Searching for " + PlayFabApiTests.titleData.characterName + " on this account.");
            getDone();
        };
        getDone = assert.async();
        PlayFabClientSDK.GetAllUsersCharacters(getCharsRequest, PlayFabApiTests.CallbackWrapper("OptionalGetCharsCallback", OptionalGetCharsCallback, assert));
    },

    /// <summary>
    /// CLIENT AND SERVER API
    /// Test that leaderboard results can be requested
    /// Parameter types tested: List of contained-classes
    /// </summary>
    LeaderBoard: function (assert) {
        var clientRequest = {
            MaxResultsCount: 3,
            StatisticName: PlayFabApiTests.testConstants.TEST_STAT_NAME,
        };
        var serverRequest = {
            MaxResultsCount: 3,
            StatisticName: PlayFabApiTests.testConstants.TEST_STAT_NAME,
        };
        var lbDoneC = assert.async();
        var lbDoneS = assert.async();

        var getLeaderboardCallbackC = function (result, error) {
            PlayFabApiTests.VerifyNullError(result, error, assert, "Testing GetLeaderboard result");
            if (result != null) {
                assert.ok(result.data.Leaderboard != null, "Testing GetLeaderboard content");
                assert.ok(result.data.Leaderboard.length > 0, "Testing GetLeaderboard content-length");
            }

            lbDoneC();
        };
        var getLeaderboardCallbackS = function (result, error) {
            PlayFabApiTests.VerifyNullError(result, error, assert, "Testing GetLeaderboard result");
            if (result != null) {
                assert.ok(result.data.Leaderboard != null, "Testing GetLeaderboard content");
                assert.ok(result.data.Leaderboard.length > 0, "Testing GetLeaderboard content-length");
            }

            lbDoneS();
        };

        PlayFabClientSDK.GetLeaderboard(clientRequest, PlayFabApiTests.CallbackWrapper("getLeaderboardCallbackC", getLeaderboardCallbackC, assert));
        PlayFabServerSDK.GetLeaderboard(serverRequest, PlayFabApiTests.CallbackWrapper("getLeaderboardCallbackS", getLeaderboardCallbackS, assert));
    },

    /// <summary>
    /// CLIENT API
    /// Test that AccountInfo can be requested
    /// Parameter types tested: List of enum-as-strings converted to list of enums
    /// </summary>
    AccountInfo: function (assert) {
        var GetAccountInfoCallback = function (result, error) {
            PlayFabApiTests.VerifyNullError(result, error, assert, "Testing GetAccountInfo result");
            assert.ok(result.data.AccountInfo != null, "Testing GetAccountInfo");
            assert.ok(result.data.AccountInfo.TitleInfo != null, "Testing TitleInfo");
            assert.ok(result.data.AccountInfo.TitleInfo.Origination != null, "Testing Origination");
            assert.ok(result.data.AccountInfo.TitleInfo.Origination.length > 0, "Testing Origination string-Enum");
            getDone();
        };

        var getDone = assert.async();
        PlayFabClientSDK.GetAccountInfo({}, PlayFabApiTests.CallbackWrapper("GetAccountInfoCallback", GetAccountInfoCallback, assert));
    },

    /// <summary>
    /// CLIENT API
    /// Test that CloudScript can be properly set up and invoked
    /// </summary>
    CloudScript: function (assert) {
        var urlDone = null;
        var hwDone = null;

        if (PlayFab._internalSettings.logicServerUrl == null) {
            var getCloudUrlRequest = {};

            var GetCloudScriptUrlCallback = function (result, error) {
                PlayFabApiTests.VerifyNullError(result, error, assert, "Testing GetCloudUrl response");

                if (PlayFab._internalSettings.logicServerUrl != null)
                    PlayFabApiTests.CloudScript(assert); // Recursively call this test to get the case below
                else
                    assert.ok(false, "GetCloudScriptUrl did not retrieve the logicServerUrl");

                urlDone();
            };

            urlDone = assert.async();
            PlayFabClientSDK.GetCloudScriptUrl(getCloudUrlRequest, PlayFabApiTests.CallbackWrapper("GetCloudScriptUrlCallback", GetCloudScriptUrlCallback, assert));
        } else {
            var helloWorldRequest = { ActionId: "helloWorld" };

            var HelloWorldCallback = function (result, error) {
                PlayFabApiTests.VerifyNullError(result, error, assert, "Testing HelloWorld response");
                if (result != null) {
                    assert.ok(result.data.Results != null, "Testing HelloWorld result");
                    assert.ok(result.data.Results.messageValue != null, "Testing HelloWorld result message");
                    assert.equal(result.data.Results.messageValue, "Hello " + PlayFabApiTests.testData.playFabId + "!", "HelloWorld cloudscript result: " + result.data.Results.messageValue);
                }
                hwDone();
            };

            hwDone = assert.async();
            PlayFabClientSDK.RunCloudScript(helloWorldRequest, PlayFabApiTests.CallbackWrapper("HelloWorldCallback", HelloWorldCallback, assert));
        }
    },
};

PlayFabApiTests.ManualExecution();
