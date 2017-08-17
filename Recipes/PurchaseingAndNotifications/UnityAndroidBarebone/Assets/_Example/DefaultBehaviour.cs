using PlayFab;
using PlayFab.Android;
using PlayFab.ClientModels;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System;
using UnityEngine.UI;

public class DefaultBehaviour : MonoBehaviour {
    public Text PushMessageText;
    public Text ItemCountText;
    public DefaultIAPBehaviour IAPService;
    private const string ANDROID_PUSH_SENDER_ID = "718447176723"; // TODO: Use your own FCM SenderId

    public void Start()
    {
        PlayFabAndroidPushPlugin.OnGcmSetupStep += OnGcmSetupSteps;
        PlayFabAndroidPushPlugin.OnGcmMessage += OnGcmMessage;
        PlayFabAndroidPushPlugin.Init();

        AndroidJavaClass up = new AndroidJavaClass("com.unity3d.player.UnityPlayer");
        AndroidJavaObject currentActivity = up.GetStatic<AndroidJavaObject>("currentActivity");
        AndroidJavaObject contentResolver = currentActivity.Call<AndroidJavaObject>("getContentResolver");
        AndroidJavaClass secure = new AndroidJavaClass("android.provider.Settings$Secure");
        string device_id = secure.CallStatic<string>("getString", contentResolver, "android_id");

        var req = new LoginWithAndroidDeviceIDRequest()
        {
            AndroidDevice = SystemInfo.deviceModel,
            AndroidDeviceId = device_id,
            OS = SystemInfo.operatingSystem,
            TitleId = PlayFabSettings.TitleId,
            CreateAccount = true, 
            InfoRequestParameters = new GetPlayerCombinedInfoRequestParams()
            {
                GetUserInventory = true
            }
        };
        PlayFabClientAPI.LoginWithAndroidDeviceID(req, (result) => {
            Debug.Log("Login With Android Successful");
            PlayFabAndroidPushPlugin.TriggerManualRegistration();

            PlayFabClientAPI.GetCatalogItems(new GetCatalogItemsRequest() {
                CatalogVersion = "Items"
            }, (catalogResult) => {
                IAPService.CatalogItems = catalogResult.Catalog;
                IAPService.InitializePurchasing();

                var itemCount = result.InfoResultPayload.UserInventory.Count;
                ItemCountText.text = string.Format("{0}", itemCount);

            }, null);

        }, ErrorCallback);
    }

    private void OnGcmMessage(PlayFabNotificationPackage package)
    {
        PushMessageText.text = package.Message;
    }

    private void OnGcmSetupSteps(PlayFabAndroidPushPlugin.PushSetupStatus status)
    {
        Debug.LogFormat("OnGCMLog: {0}", status);
    }

    public void ErrorCallback(PlayFabError error)
    {
        Debug.Log("mytesterror"  + error.GenerateErrorReport());
    }

    public void ExitApplication()
    {
        Application.Quit();
    }
}
