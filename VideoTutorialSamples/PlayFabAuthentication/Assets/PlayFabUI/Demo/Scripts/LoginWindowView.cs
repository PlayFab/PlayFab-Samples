using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using PlayFab;
using PlayFab.ClientModels;

public class LoginWindowView : MonoBehaviour {
    public bool ClearPlayerPrefs;
    public InputField Username;
    public InputField Password;
    public InputField ConfirmPassword;
    
    public Button LoginButton;
    public Button PlayAsGuestButton;
    public Button LoginWithFacebook;
    public Button LoginWithGoogle;
    public Button RegisterButton;
    public Button CancelRegisterButton;
    public Toggle RememberMe;

    public PlayFab.UI.ProgressBarView ProgressBar;

    public GameObject RegisterPanel;
    public GameObject Panel;
    public GameObject Next;

    public GetPlayerCombinedInfoRequestParams InfoRequestParams;


    public string _PlayFabId;
    public string _SessionTicket;

    private PlayFabAuthService _AuthService = new PlayFabAuthService();

    public void Awake()
    {
        RememberMe.onValueChanged.AddListener((toggle) =>
        {
            _AuthService.RememberMe = toggle;
        });
    }

    public void Start()
    {
        if (ClearPlayerPrefs)
        {
            _AuthService.AuthType = Authtypes.None;
        }

        Panel.SetActive(false);
        Next.SetActive(false);
        RegisterPanel.SetActive(false);

        PlayFabAuthService.OnDisplayAuthentication += OnDisplayAuthentication;
        PlayFabAuthService.OnLoginSuccess += OnLoginSuccess;
        PlayFabAuthService.OnPlayFabError += OnPlayFaberror;


        //Setup Button Bindings
        LoginButton.onClick.AddListener(OnLoginClicked);
        PlayAsGuestButton.onClick.AddListener(OnPlayAsGuestClicked);
        LoginWithFacebook.onClick.AddListener(OnLoginWithFacebookClicked);
        LoginWithGoogle.onClick.AddListener(OnLoginWithGoogleClicked);
        RegisterButton.onClick.AddListener(OnRegisterButtonClicked);
        CancelRegisterButton.onClick.AddListener(OnCancelRegisterButtonClicked);

        _AuthService.InfoRequestParams = InfoRequestParams;

        _AuthService.Authenticate();
    }

    private void OnLoginSuccess(LoginResult result)
    {
        Debug.LogFormat("Logged In as: {0}", result.PlayFabId);
        _PlayFabId = result.PlayFabId;
        _SessionTicket = result.SessionTicket;

        Panel.SetActive(false);
        Next.SetActive(true);
    }

    private void OnPlayFaberror(PlayFabError error)
    {

        switch (error.Error)
        {
            case PlayFabErrorCode.InvalidEmailAddress:
            case PlayFabErrorCode.InvalidPassword:
            case PlayFabErrorCode.InvalidEmailOrPassword:
                ProgressBar.UpdateLabel("Invalid Email or Password");
                break;

            case PlayFabErrorCode.AccountNotFound:
                RegisterPanel.SetActive(true);
                return;
            default:
                ProgressBar.UpdateLabel(error.GenerateErrorReport());
                break;
                
        }
        Debug.Log(error.Error);
        Debug.LogError(error.GenerateErrorReport());
    }


    private void OnDisplayAuthentication()
    {
        Panel.SetActive(true);
    }

    private void OnPlayAsGuestClicked()
    {

        ProgressBar.UpdateLabel("Logging In As Guest ...");
        ProgressBar.UpdateProgress(0f);
        ProgressBar.AnimateProgress(0, 1, () => {
            ProgressBar.UpdateLabel(string.Empty);
            ProgressBar.UpdateProgress(0f);
        });

        _AuthService.AuthType = Authtypes.Silent;
        _AuthService.Authenticate();
    }

    private void OnLoginClicked()
    {
        _AuthService.AuthType = Authtypes.EmailAndPassword;
        _AuthService.Email = Username.text;
        _AuthService.Password = Password.text;
        _AuthService.Authenticate();
    }

    private void OnRegisterButtonClicked()
    {
        if (Password.text != ConfirmPassword.text)
        {
            ProgressBar.UpdateLabel("Passwords do not Match.");
            return;
        }

        _AuthService.AuthType = Authtypes.RegisterPlayFabAccount;
        _AuthService.Email = Username.text;
        _AuthService.Password = Password.text;
        _AuthService.Authenticate();
    }

    private void OnCancelRegisterButtonClicked()
    {
        RegisterPanel.SetActive(false);
        Next.SetActive(false);
    }


    private void OnLoginWithFacebookClicked()
    {

    }

    private void OnLoginWithGoogleClicked()
    {

    }

}
