using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using PlayFab;
using PlayFab.ClientModels;

public enum Authtypes
{
    None,
    Silent,
    UsernameAndPassword,
    EmailAndPassword,
    Facebook,
    Google
}

public class PlayFabAuthService  {

    public delegate void DisplayAuthenticationEvent();
    public static event DisplayAuthenticationEvent OnDisplayAuthentication;

    public delegate void LoginSuccessEvent(LoginResult success);
    public static event LoginSuccessEvent OnLoginSuccess;
    
    public delegate void PlayFabErrorEvent(PlayFabError error);
    public static event PlayFabErrorEvent OnPlayFabError;

    public string Email;
    public string Username;
    public string Password;

    
    public Authtypes AuthType {
        get {
            return (Authtypes)PlayerPrefs.GetInt("PlayFabAuthType", 0);
        }
        set {

            PlayerPrefs.SetInt("PlayFabAuthType", (int) value);
        }
    }

    public void Authenticate(Authtypes authType)
    {
        AuthType = authType;
        Authenticate();
    }

    public void Authenticate()
    {
        var authType = AuthType;
        Debug.Log(authType);
        switch (authType)
        {
            case Authtypes.None:
                if (OnDisplayAuthentication != null)
                {
                    OnDisplayAuthentication.Invoke();
                }
                break;

            case Authtypes.Silent:
                SilentlyAuthenticate();
                break;

            case Authtypes.UsernameAndPassword:
                break;

            case Authtypes.EmailAndPassword:
                AuthenticateUsernamePassword();
                break;

            case Authtypes.Facebook:
                break;

            case Authtypes.Google:
                break;
        }


    }

    private void AuthenticateUsernamePassword()
    {
        PlayFabClientAPI.LoginWithEmailAddress(new LoginWithEmailAddressRequest()
        {
            TitleId = PlayFabSettings.TitleId,
            Email = Email,
            Password = Password,
        }, (result) =>
        {
            if (OnLoginSuccess != null)
            {
                OnLoginSuccess.Invoke(result);
            }
        }, (error) =>
        {
            if (OnPlayFabError != null)
            {
                OnPlayFabError.Invoke(error);
            }
        });
    }


    private void SilentlyAuthenticate()
    {
#if UNITY_ANDROID  && !UNITY_EDITOR
        AndroidJavaClass up = new AndroidJavaClass("com.unity3d.player.UnityPlayer");
        AndroidJavaObject currentActivity = up.GetStatic<AndroidJavaObject>("currentActivity");
        AndroidJavaObject contentResolver = currentActivity.Call<AndroidJavaObject>("getContentResolver");
        AndroidJavaClass secure = new AndroidJavaClass("android.provider.Settings$Secure");
        string deviceId = secure.CallStatic<string>("getString", contentResolver, "android_id");

        PlayFabClientAPI.LoginWithAndroidDeviceID(new LoginWithAndroidDeviceIDRequest() {
            TitleId = PlayFabSettings.TitleId,
            AndroidDevice = SystemInfo.deviceModel,
            OS = SystemInfo.operatingSystem,
            AndroidDeviceId = deviceId,
            CreateAccount = true
        }, (result) => {
            Debug.LogFormat("LoginSuccess is Null?", OnLoginSuccess == null);
            if(OnLoginSuccess != null)
            {
                Debug.Log("Login Success Triggered");
                OnLoginSuccess.Invoke(result);
            }

        }, (error) => {
            if(OnPlayFabError != null)
            {
                OnPlayFabError.Invoke(error);
            }
        });

#elif UNITY_IPHONE || UNITY_IOS && !UNITY_EDITOR
        PlayFabClientAPI.LoginWithIOSDeviceID(new LoginWithIOSDeviceIDRequest() {
            TitleId = PlayFabSettings.TitleId,
            DeviceModel = SystemInfo.deviceModel, 
            OS = SystemInfo.operatingSystem,
            DeviceId = SystemInfo.deviceUniqueIdentifier,
            CreateAccount = true
        }, (result) => {
            if (OnLoginSuccess != null)
            {
                OnLoginSuccess.Invoke(result);
            }
        }, (error) => {
            if (OnPlayFabError != null)
            {
                OnPlayFabError.Invoke(error);
            }
        });
#else
        PlayFabClientAPI.LoginWithCustomID(new LoginWithCustomIDRequest()
        {
            TitleId = PlayFabSettings.TitleId,
            CustomId = SystemInfo.deviceUniqueIdentifier,
            CreateAccount = true
        }, (result) => {
            if (OnLoginSuccess != null)
            {
                OnLoginSuccess.Invoke(result);
            }
        }, (error) => {
            if (OnPlayFabError != null)
            {
                OnPlayFabError.Invoke(error);
            }
        });
#endif
    }

}
