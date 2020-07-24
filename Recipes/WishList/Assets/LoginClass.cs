using System;

using PlayFab;
using PlayFab.GroupsModels;
using PlayFab.ClientModels;
using PlayFab.DataModels;
using PlayFab.Json;

using System.Collections;
using System.Collections.Generic;
using UnityEngine;

using UnityEngine.UI;

public class LoginClass : MonoBehaviour {

    /* 
        The following variables store the entity key ID and entity key type of the player
        who is currently logged in. 
    */
    private static string player_entityKeyId;
    private static string player_entityKeyType;

    /*
        When the player clicks the button to log in, the Client calls LoginWithPlayFabRequest to return
        the login token. Authenticate the client in order to call other PlayFab Client APIs.

    */

    public void loginButtonClicked() {

        if (string.IsNullOrEmpty(PlayFabSettings.staticSettings.TitleId)){
            /*
            Please change the titleId below to your own titleId from PlayFab Game Manager.
            If you have already set the value in the Editor Extensions, this can be skipped.
            */
            PlayFabSettings.staticSettings.TitleId = "13C25";
        }

        var request = new LoginWithPlayFabRequest {Username = "shane", TitleId = "13C25", Password = "leetcode"};
        PlayFabClientAPI.LoginWithPlayFab(request, OnLoginSuccess, OnLoginFailure);

    }

    /*
        Upon successful login, set up the store for our game and find the user's wish list.

        @param result: the PlayFab LoginResult object which occurs upon a successful call to LoginWithPlayFab

        When the player clicks the button to log in, the Client calls LoginWithPlayFabRequest to return
        the login token. Authenticate the client in order to call other PlayFab Client APIs.

    */

    private void OnLoginSuccess(LoginResult result) {

        LoginClass.player_entityKeyId = result.EntityToken.Entity.Id;
        LoginClass.player_entityKeyType = result.EntityToken.Entity.Type;

        PlayFab.GroupsModels.EntityKey entity = new PlayFab.GroupsModels.EntityKey {Id = LoginClass.player_entityKeyId, Type = LoginClass.player_entityKeyType };

        var request = new ListMembershipRequest { Entity = entity };

        /* Set up the store buttons for the Unity game. This will change depending on the nature of your game. */

        StoreSetup.StoreStart();

        /* Now that the player has logged in, find their wish list. If not found, create it. */

        WishList.FindOrCreateWishList(LoginClass.player_entityKeyId, LoginClass.player_entityKeyType);

    }

    /*
        Upon failure of LoginWithPlayFab, print the error the the unity Debug Logs.
    */

    private void OnLoginFailure(PlayFabError error) {
        Debug.LogError(error.GenerateErrorReport());
    }

    /*
        Getter for the player's entity key type. This will likely be title_player_account.
    */

    public static string getPlayerEntityKeyType() {
        return LoginClass.player_entityKeyType;
    }

    /*
        Getter for the player's entity key ID.
    */

    public static string getPlayerEntityKeyId() {
        return LoginClass.player_entityKeyId;
    }

    /*
        Log in as the device. Subsequent logins from the same device will enter the ame account.
    */

    public void AuthenticateWithPlayFab() {

        Debug.Log("Logging into PlayFab...");

        LoginWithCustomIDRequest request = new LoginWithCustomIDRequest() { TitleId="13C25", CustomId = SystemInfo.deviceUniqueIdentifier, CreateAccount = true };
        PlayFabClientAPI.LoginWithCustomID(request, OnLoginSuccess, OnLoginFailure, null);
    
    }
}
