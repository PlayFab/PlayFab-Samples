using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using PlayFab;
using PlayFab.ClientModels;
using System;

public class GettingStarted : MonoBehaviour {

	// Use this for initialization
	void Start () {

        var request = new LoginWithCustomIDRequest()
        {
            TitleId = PlayFabSettings.TitleId,
            CustomId = SystemInfo.deviceUniqueIdentifier,
            CreateAccount = true
        };

        PlayFabClientAPI.LoginWithCustomID(request, OnLoginSuccess, OnLoginError);

	}

    private void OnLoginSuccess(LoginResult result)
    {
        Debug.LogFormat("Login Success: {0}", result.PlayFabId);
        Debug.LogFormat("Session: {0}", result.SessionTicket);
    }

    private void OnLoginError(PlayFabError error)
    {
        Debug.Log(error.GenerateErrorReport());
    }

}
