//--------------------------------------------------------------------------------------
// PlayFabManager.cs
//
// Advanced Technology Group (ATG)
// Copyright (C) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.
//--------------------------------------------------------------------------------------

using System.Collections.Generic;
using PlayFab;
using PlayFab.ClientModels;
using UnityEngine;

public static class PlayFabManager
{
    // Flag set after successfull PlayFab Login
    public static bool IsLoggedIn = false;

    // The user's Title specific DisplayName
    public static string UserDisplayName = null;

    ////////////////////////////////////////////////////////////////
    /// Load the user's account info to get their DisplayName
    /// 
    public static void LoadAccountData()
    {
        PlayFabClientAPI.GetAccountInfo(
            // Request
            new GetAccountInfoRequest
            {
                // No properties means get the calling user's info
            },
            // Success
            (GetAccountInfoResult response) =>
            {
                Debug.Log("GetAccountInfo completed.");
                UserDisplayName = response.AccountInfo.TitleInfo.DisplayName;
                IsAccountInfoLoaded = true;
            },
            // Failure
            (PlayFabError error) =>
            {
                Debug.LogError("GetAccountInfo failed.");
                Debug.LogError(error.GenerateErrorReport());
            }
            );
    }

    // Flag set when the user's AccountInfo is loaded
    public static bool IsAccountInfoLoaded = false;

    ////////////////////////////////////////////////////////////////
    /// Update the user's per-title DisplayName
    /// 
    public static void SetUserDisplayName(string name)
    {
        UserDisplayName = name;

        PlayFabClientAPI.UpdateUserTitleDisplayName(
            // Request
            new UpdateUserTitleDisplayNameRequest
            {
                DisplayName = name
            },
            // Success
            (UpdateUserTitleDisplayNameResult result) =>
            {
                Debug.Log("UpdateUserTitleDisplayName completed.");
            },
            // Failure
            (PlayFabError error) =>
            {
                Debug.LogError("UpdateUserTitleDisplayName failed.");
                Debug.LogError(error.GenerateErrorReport());
            }
            );
    }

    ////////////////////////////////////////////////////////////////
    /// Update the user's game stats in bulk
    /// 
    /// This uses a custom event to trigger cloudscript which
    /// performs the stat updates
    /// 
    public static void UpdateStatistics(Dictionary<string, object> values)
    {
        PlayFabClientAPI.WritePlayerEvent(
            // Request
            new WriteClientPlayerEventRequest
            {
                EventName = "update_statistics",
                Body = new Dictionary<string, object>
                {
                    { "stats", values }
                }
            },
            // Success
            (WriteEventResponse response) =>
            {
                Debug.Log("WritePlayerEvent (UpdateStatistics) completed.");
            },
            // Failure
            (PlayFabError error) =>
            {
                Debug.LogError("WritePlayerEvent failed.");
                Debug.LogError(error.GenerateErrorReport());
            }
            );
    }

    ////////////////////////////////////////////////////////////////
    /// Update a user's individual game stat
    /// 
    /// This uses a custom event to trigger cloudscript which
    /// performs the stat updates
    /// 
    public static void UpdateStatistic(string stat, int value)
    {
        PlayFabClientAPI.WritePlayerEvent(
            // Request
            new WriteClientPlayerEventRequest
            {
                EventName = "update_statistic",
                Body = new Dictionary<string, object>
                {
                    { "stat_name", stat },
                    { "value", value }
                }
            },
            // Success
            (WriteEventResponse response) =>
            {
                Debug.Log("WritePlayerEvent (UpdateStatistic) completed.");
            },
            // Failure
            (PlayFabError error) =>
            {
                Debug.LogError("WritePlayerEvent failed.");
                Debug.LogError(error.GenerateErrorReport());
            }
            );
    }

    ////////////////////////////////////////////////////////////////
    /// Load the game's server configured data
    /// 
    public static void LoadTitleData()
    {
        PlayFabClientAPI.GetTitleData(
            // Request
            new GetTitleDataRequest
            {
                Keys = new List<string>
                {
                    "MOTD"
                }
            },
            // Success
            (GetTitleDataResult result) =>
            {
                Debug.Log("GetTitleData completed.");
                foreach (string key in result.Data.Keys)
                {
                    TitleData[key] = result.Data[key];
                }
                IsTitleDataLoaded = true;
            },
            // Failure
            (PlayFabError error) =>
            {
                Debug.LogError("GetTitleData failed.");
                Debug.LogError(error.GenerateErrorReport());
            }
            );
    }

    // Cache of the title data
    private static Dictionary<string, string> TitleData = new Dictionary<string, string>();

    // Flag set when TitleData is complete
    public static bool IsTitleDataLoaded = false;

    // Accessor for the TitleData
    public static string GetTitleDataValue(string key)
    {
        if (TitleData.ContainsKey(key))
        {
            return TitleData[key];
        }

        return null;
    }

    ////////////////////////////////////////////////////////////////
    /// Load the user's server data
    /// 
    public static void LoadUserData()
    {
        PlayFabClientAPI.GetUserData(
            // Request
            new GetUserDataRequest
            {
                Keys = new List<string>
                {
                    "ShipStyle",
                    "ShipColor"
                }
            },
            // Success
            (GetUserDataResult result) =>
            {
                Debug.Log("GetUserData completed.");
                UserData = result.Data;
                IsUserDataLoaded = true;
            },
            // Failure
            (PlayFabError error) =>
            {
                Debug.LogError("GetUserData failed.");
                Debug.LogError(error.GenerateErrorReport());
            }
            );
    }

    // Flag set when user data has loaded
    public static bool IsUserDataLoaded = false;

    // Access for user data
    public static string GetUserDataValue(string key)
    {
        if (UserData.ContainsKey(key))
        {
            return UserData[key].Value;
        }

        return null;
    }

    // Cache for user's server data
    private static Dictionary<string, UserDataRecord> UserData;

    ////////////////////////////////////////////////////////////////
    /// Write the user's data up to the server
    /// 
    public static void StoreUserData(int shipStyle, int shipColor)
    {
        if (!UserData.ContainsKey("ShipStyle"))
        {
            UserData["ShipStyle"] = new UserDataRecord { Value = shipStyle.ToString() };
            UserData["ShipColor"] = new UserDataRecord { Value = shipColor.ToString() };
        }
        else
        {
            UserData["ShipStyle"].Value = shipStyle.ToString();
            UserData["ShipColor"].Value = shipColor.ToString();
        }

        PlayFabClientAPI.UpdateUserData(
            // Request
            new UpdateUserDataRequest
            {
                Data = new Dictionary<string, string>
                {
                    { "ShipStyle", UserData["ShipStyle"].Value },
                    { "ShipColor", UserData["ShipColor"].Value }
                }
            },
            // Success
            (UpdateUserDataResult response) =>
            {
                Debug.Log("UpdateUserData completed.");
            },
            // Failure
            (PlayFabError error) =>
            {
                Debug.LogError("UpdateUserData failed.");
                Debug.LogError(error.GenerateErrorReport());
            }
            );
    }
}
