using PlayFab;
using PlayFab.ClientModels;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System;
using UnityEngine.UI;

#if UNITY_ANDROID
using PlayFab.Android;
#endif

public class DefaultBehaviour : MonoBehaviour {
    public Text PushMessageText;
    public Text ItemCountText;
    public DefaultIAPBehaviour IAPService;
    private const string ANDROID_PUSH_SENDER_ID = "718447176723"; // TODO: Use your own FCM SenderId

    public void Start()
    {
#if UNITY_IOS || UNITY_IPHONE
        UnityEngine.iOS.NotificationServices.RegisterForNotifications(UnityEngine.iOS.NotificationType.Alert | UnityEngine.iOS.NotificationType.Badge | UnityEngine.iOS.NotificationType.Sound, true);
#endif

#if UNITY_ANDROID
        PlayFabAndroidPushPlugin.OnGcmSetupStep += OnGcmSetupSteps;
        PlayFabAndroidPushPlugin.OnGcmMessage += OnGcmMessage;
        PlayFabAndroidPushPlugin.Init();
#endif

        var device_id = SystemInfo.deviceUniqueIdentifier;
#if UNITY_ANDROID
        AndroidJavaClass up = new AndroidJavaClass("com.unity3d.player.UnityPlayer");
        AndroidJavaObject currentActivity = up.GetStatic<AndroidJavaObject>("currentActivity");
        AndroidJavaObject contentResolver = currentActivity.Call<AndroidJavaObject>("getContentResolver");
        AndroidJavaClass secure = new AndroidJavaClass("android.provider.Settings$Secure");
        device_id = secure.CallStatic<string>("getString", contentResolver, "android_id");

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
#endif
#if Unity_IOS || UNITY_IPHONE
        var req = new LoginWithIOSDeviceIDRequest()
        {
            DeviceId = device_id,
            DeviceModel = SystemInfo.deviceModel,
            OS = SystemInfo.operatingSystem,
            TitleId = PlayFabSettings.TitleId,
            CreateAccount = true,
            InfoRequestParameters = new GetPlayerCombinedInfoRequestParams()
            {
                GetUserInventory = true
            }
        };
        PlayFabClientAPI.LoginWithIOSDeviceID(req, (result) => {
            Debug.Log("Login With IOS Successful");

            string hexToken = string.Empty;
            byte[] token = UnityEngine.iOS.NotificationServices.deviceToken;
            if (token != null)
            {
                RegisterForIOSPushNotificationRequest request = new RegisterForIOSPushNotificationRequest();
                request.DeviceToken = System.BitConverter.ToString(token).Replace("-", "").ToLower();
                hexToken = request.DeviceToken;
                Debug.Log(hexToken);
                PlayFabClientAPI.RegisterForIOSPushNotification(request, null, null);
            }
            else
            {
                Debug.Log("Push Token was null!");
            }

            PlayFabClientAPI.GetCatalogItems(new GetCatalogItemsRequest()
            {
                CatalogVersion = "Items"
            }, (catalogResult) => {
                IAPService.CatalogItems = catalogResult.Catalog;
                IAPService.InitializePurchasing();

                var itemCount = result.InfoResultPayload.UserInventory.Count;
                ItemCountText.text = string.Format("{0}", itemCount);

            }, null);
        }, null);
#endif

    }

#if UNITY_ANDROID
    private void OnGcmMessage(PlayFabNotificationPackage package)
    {
        PushMessageText.text = package.Message;
    }

    private void OnGcmSetupSteps(PlayFabAndroidPushPlugin.PushSetupStatus status)
    {
        Debug.LogFormat("OnGCMLog: {0}", status);
    }
#endif

    public void ErrorCallback(PlayFabError error)
    {
        Debug.Log("mytesterror"  + error.GenerateErrorReport());
    }

    public void ExitApplication()
    {
        Application.Quit();
    }
}
