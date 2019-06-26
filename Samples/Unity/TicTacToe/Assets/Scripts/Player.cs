// Copyright (C) Microsoft Corporation. All rights reserved.

using System;
using PlayFab;
using PlayFab.ClientModels;
using UnityEngine;

public class Player : MonoBehaviour
{
    private string _entityToken;
    private string _sessionTicket;
    private string _playFabId;
    public Board Board { get; set; }

    public string EntityToken 
    { 
        get 
        {
            if (string.IsNullOrEmpty(_entityToken))
            {
                UpdateCredentials();
            }
            return _entityToken;
        } 
        private set 
        {
            _entityToken = value;
        } 
    }

    public string PlayFabId
    {
        get
        {
            if (string.IsNullOrEmpty(_playFabId))
            {
                UpdateCredentials();
            }
            return _playFabId;
        }
        private set
        {
            _playFabId = value;
        }
    }

    public string SessionTicket
    {
        get
        {
            if (string.IsNullOrEmpty(_sessionTicket))
            {
                UpdateCredentials();
            }
            return _sessionTicket;
        }

        private set
        {
            _sessionTicket = value;
        }
    }

    private void UpdateCredentials()
    {
        // FOR DEMONSTRATIONAL PURPOSES ONLY
        // Assign relevant fields from the set of constants
        PlayFabSettings.TitleId = Constants.TITLE_ID;    
        PlayFabSettings.VerticalName = Constants.CLOUD_NAME;
        PlayFabSettings.CompressApiData = Constants.COMPRESS_API_DATA;

        // FOR DEMONSTRATIONAL PURPOSES ONLY
        // Create a new dummy account login request
        var loginRequest = new LoginWithCustomIDRequest
        {
            CustomId = GetPlayerCustomId(),
            CreateAccount = true
        };

        // Execute login request through the PlayFab SDK
        PlayFabClientAPI.LoginWithCustomID(
            loginRequest,
            (result) =>
            {
                // Save entity token for later use in the session
                EntityToken = result?.EntityToken.EntityToken;
                PlayFabId = result?.PlayFabId;
                SessionTicket = result?.SessionTicket;

                Debug.Log($"Login successful for player with Entity Token: {EntityToken}");

                Board.OnPlayerLoginCompleted();
            }, 
            (error) => 
            {
                // Provide error feedback to user in case of failure at login
                Debug.LogError("Could not login to PlayFab for Player.");
                Debug.LogError($"Response code: {error.HttpCode}");
                Debug.LogError($"Error details: {error.ErrorDetails}");
                Debug.LogError($"Error message: {error.ErrorMessage}");
            });
    }

    private string GetPlayerCustomId()
    {
        if (!PlayerPrefs.HasKey(Constants.PLAYFAB_PLAYER_CUSTOM_ID))
        {
            PlayerPrefs.SetString(Constants.PLAYFAB_PLAYER_CUSTOM_ID, Guid.NewGuid().ToString());
        }
        return PlayerPrefs.GetString(Constants.PLAYFAB_PLAYER_CUSTOM_ID);
    }

    // Grab a fresh token on start
    public void Start()
    {
        UpdateCredentials();
    }
}
