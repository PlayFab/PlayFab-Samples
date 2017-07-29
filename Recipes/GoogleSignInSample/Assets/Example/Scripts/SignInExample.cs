using UnityEngine;
using UnityEngine.UI;
using GooglePlayGames;
using GooglePlayGames.BasicApi;
using System;
using PlayFab;
using PlayFab.ClientModels;


public class SignInExample : MonoBehaviour {
    public Button SignInButton;
    public Text GoogleStatusText;

    private void Start()
    {
        PlayGamesClientConfiguration config = new PlayGamesClientConfiguration.Builder()
            .AddOauthScope("profile")
            .RequestServerAuthCode(false)
            .Build();

        PlayGamesPlatform.InitializeInstance(config);
        PlayGamesPlatform.DebugLogEnabled = true;
        PlayGamesPlatform.Activate();

        if (SignInButton != null)
        {
            SignInButton.onClick.AddListener(OnSignInButtonClicked);
        }
        else
        {
            Debug.Log("Please link your button in the inspector.");
        }
        
    }

    private void OnDestroy()
    {
        SignInButton.onClick.RemoveListener(OnSignInButtonClicked);
    }

    private void OnSignInButtonClicked()
    {
        Social.localUser.Authenticate((bool success) => {
            GoogleStatusText.text = "Google Signed In";
            var serverAuthCode = PlayGamesPlatform.Instance.GetServerAuthCode();
            Debug.Log("Server Auth Code: " + serverAuthCode);

            PlayFabClientAPI.LoginWithGoogleAccount(new LoginWithGoogleAccountRequest()
            {
                TitleId = PlayFabSettings.TitleId,
                ServerAuthCode = serverAuthCode,
                CreateAccount = true
            }, (result) => {
                GoogleStatusText.text = "Signed In as " + result.PlayFabId;

            }, OnPlayFabError);

        });
        
    }

    private void OnPlayFabError(PlayFabError error)
    {
        Debug.LogError(error.GenerateErrorReport());
    }


}
