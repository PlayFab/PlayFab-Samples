using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using PlayFab;
using PlayFab.ClientModels;
using System;

public enum Authtypes
{
    None,
    Silent,
    UsernameAndPassword,
    EmailAndPassword,
    RegisterPlayFabAccount,
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
    public string AuthTicket;
    public GetPlayerCombinedInfoRequestParams InfoRequestParams;
    
    public static string PlayFabId;


    public bool RememberMe {
        get {
            return PlayerPrefs.GetInt("PlayFabLoginRemember", 0) == 0 ? false : true;
        }
        set {
            PlayerPrefs.SetInt("PlayFabLoginRemember", value ? 1 : 0);
        }
    }  
    
    public Authtypes AuthType {
        get {
            return (Authtypes)PlayerPrefs.GetInt("PlayFabAuthType", 0);
        }
        set {

            PlayerPrefs.SetInt("PlayFabAuthType", (int) value);
        }
    }

    private string RememberMeId
    {
        get {
            return PlayerPrefs.GetString("PlayFabIdPassGuid", "");
        }
        set
        {
            var guid = string.IsNullOrEmpty(value) ? Guid.NewGuid().ToString() : value;
            PlayerPrefs.SetString("PlayFabIdPassGuid", guid);
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

            case Authtypes.EmailAndPassword:
                AuthenticateEmailPassword();
                break;
            case Authtypes.RegisterPlayFabAccount:
                AddAccountAndPassword();
                break;

            case Authtypes.Facebook:
                break;

            case Authtypes.Google:
                break;

        }


    }

    private void AuthenticateEmailPassword()
    {
        if (RememberMe && !string.IsNullOrEmpty(RememberMeId))
        {
            PlayFabClientAPI.LoginWithCustomID(new LoginWithCustomIDRequest()
            {
                TitleId = PlayFabSettings.TitleId,
                CustomId = RememberMeId,
                CreateAccount = true,
                InfoRequestParameters = InfoRequestParams
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
            return;
        }

        //a good catch:  
        if (!RememberMe && string.IsNullOrEmpty(Email) && string.IsNullOrEmpty(Password))
        {
            OnDisplayAuthentication.Invoke();
            return;
        }

        PlayFabClientAPI.LoginWithEmailAddress(new LoginWithEmailAddressRequest()
        {
            TitleId = PlayFabSettings.TitleId,
            Email = Email,
            Password = Password,
            InfoRequestParameters = InfoRequestParams
        }, (result) =>
        {
            if (RememberMe)
            {
                RememberMeId = Guid.NewGuid().ToString();
                AuthType = Authtypes.EmailAndPassword;
            }

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

    private void AddAccountAndPassword()
    {
        SilentlyAuthenticate((loginResult) => {
            PlayFabClientAPI.AddUsernamePassword(new AddUsernamePasswordRequest() {
                Username = !string.IsNullOrEmpty(Username) ? Username : loginResult.PlayFabId, //Because it is required & Unique and not supplied by User.
                Email = Email,
                Password = Password,
            }, (addResult) => {
                if (OnLoginSuccess != null)
                {
                    if (RememberMe)
                    {
                        RememberMeId = Guid.NewGuid().ToString();
                    }
                    AuthType = Authtypes.EmailAndPassword;
                    OnLoginSuccess.Invoke(loginResult);
                }
            }, (error) => {
                if (OnPlayFabError != null)
                {
                    OnPlayFabError.Invoke(error);
                }
            });

        });
    }

    private void SilentlyAuthenticate(System.Action<LoginResult> callback = null)
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
            CreateAccount = true,
            InfoRequestParameters = InfoRequestParams
        }, (result) => {
            if (callback == null && OnLoginSuccess != null)
            {
                OnLoginSuccess.Invoke(result);
            }else if (callback != null)
            {
                callback.Invoke(result);
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
            CreateAccount = true,
            InfoRequestParameters = InfoRequestParams
        }, (result) => {
            if (callback == null && OnLoginSuccess != null)
            {
                OnLoginSuccess.Invoke(result);
            }else if (callback != null)
            {
                callback.Invoke(result);
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
            CreateAccount = true,
            InfoRequestParameters = InfoRequestParams
        }, (result) => {
            if (callback == null && OnLoginSuccess != null)
            {
                OnLoginSuccess.Invoke(result);
            }else if (callback != null)
            {
                callback.Invoke(result);
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
