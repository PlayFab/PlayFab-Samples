using PlayFab.ClientModels;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

#if UNITY_ANDROID && !UNITY_EDITOR
using Google;
#endif

public class SignInButton : MonoBehaviour {

    private Button button;
    private Canvas canvas;

    public string webClientId = "858987003262-qio1p0t7j7krvh7pa8c2qau099tdjhea.apps.googleusercontent.com";

   

#if UNITY_ANDROID && !UNITY_EDITOR
    private GoogleSignInConfiguration configuration;
#endif
    void Start()
    {
        canvas = GetComponentInParent<Canvas>();

        button = GetComponent<Button>();

        button.onClick.AddListener(SignInUser);

        PlayFabAuthService.OnLoginSuccess += SignInSuccess;

    }

    private void Awake()
    {
#if UNITY_ANDROID && !UNITY_EDITOR
        configuration = new GoogleSignInConfiguration
        {
            WebClientId = webClientId,
            RequestIdToken = true
        };
#endif
    }

    void SignInUser()
    {
        Debug.Log("Signing In");

#if UNITY_ANDROID && !UNITY_EDITOR
        GoogleSignIn.Configuration = configuration;
        GoogleSignIn.Configuration.UseGameSignIn = false;
        GoogleSignIn.Configuration.RequestIdToken = true;
        GoogleSignIn.Configuration.RequestAuthCode = true;

        GoogleSignIn.DefaultInstance.SignIn().ContinueWith(task =>
        {
            if (task.IsFaulted)
            {
                using (IEnumerator<System.Exception> enumerator =
                        task.Exception.InnerExceptions.GetEnumerator())
                {
                    if (enumerator.MoveNext())
                    {
                        GoogleSignIn.SignInException error =
                                (GoogleSignIn.SignInException)enumerator.Current;
                        Debug.Log("Got Error: " + error.Status + " " + error.Message);
                    }
                    else
                    {
                        Debug.Log("Got Unexpected Exception?!?" + task.Exception);
                    }
                }
            }
            else if (task.IsCanceled)
            {
                Debug.Log("Canceled");
            }
            else
            {
                Debug.Log("Welcome: " + task.Result.DisplayName + "!");


                PlayFabAuthService.Instance.AuthCode = task.Result.AuthCode;
                PlayFabAuthService.Instance.Authenticate(Authtypes.GoogleAccount);
            }
        });
#else
        PlayFabAuthService.Instance.Authenticate(Authtypes.Silent);
#endif
    }

    void SignInSuccess(LoginResult result)
    {
        GetComponentInChildren<Text>().text = "Signed In";

        button.enabled = false;

        canvas.gameObject.SetActive(false);
    }
}
