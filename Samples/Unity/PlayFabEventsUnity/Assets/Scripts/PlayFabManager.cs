using System.Collections.Generic;
using PlayFab;
using PlayFab.ClientModels;
using UnityEngine;
using UnityEngine.UI;

public static class PlayFabManager
{
    public static void Login(System.Action<LoginResult> onSuccess, System.Action<PlayFabError> onFailed)

    {
#if UNITY_ANDROID
        PlayFabClientAPI.LoginWithAndroidDeviceID(
            // Request
            new LoginWithAndroidDeviceIDRequest
            {
                CreateAccount = true,
                AndroidDevice = SystemInfo.deviceModel,
                OS = SystemInfo.operatingSystem,
                AndroidDeviceId = SystemInfo.deviceUniqueIdentifier
            },
            // Success
            (LoginResult result) => 
            {
                Debug.Log("Login completed.");
                IsLoggedIn = true;
            },
            // Failure
            (PlayFabError error) => 
            {
                Debug.LogError("Login failed.");
                Debug.LogError(error.GenerateErrorReport());
            }
            );
#elif UNITY_IOS
        PlayFabClientAPI.LoginWithIOSDeviceID(
            // Request
            new LoginWithIOSDeviceIDRequest
            {
                CreateAccount = true,
                DeviceId = SystemInfo.deviceUniqueIdentifier,
                DeviceModel = SystemInfo.deviceModel,
                OS = SystemInfo.operatingSystem
            },
            // Success
            (LoginResult result) => 
            {
                Debug.Log("Login completed.");
                IsLoggedIn = true;
            },
            // Failure
            (PlayFabError error) => 
            {
                Debug.LogError("Login failed.");
                Debug.LogError(error.GenerateErrorReport());
            }
            );
#else
        PlayFabClientAPI.LoginWithCustomID(
            // Request
            new LoginWithCustomIDRequest
            {
                CustomId = System.Guid.NewGuid().ToString(),
                CreateAccount = true
            },
            // Success
            (LoginResult result) =>
            {
                Debug.Log("Login completed.");
                IsLoggedIn = true;
                onSuccess(result);
            },
            // Failure
            (PlayFabError error) =>
            {
                Debug.LogError("Login failed.");
                Debug.LogError(error.GenerateErrorReport());
                onFailed(error);
            }
            );
#endif
    }

    // Flag set after successfull Playfab Login
    public static bool IsLoggedIn = false;
}