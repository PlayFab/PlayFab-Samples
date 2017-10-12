using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using PlayFab;
using PlayFab.ClientModels;

#if FACEBOOK 
using Facebook.Unity;
#endif

public class LoginWindowView : MonoBehaviour {
    //Debug Flag to simulate a reset
    public bool ClearPlayerPrefs;

    //Meta fields for objects in the UI
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

    //Meta references to panels we need to show / hide
    public GameObject RegisterPanel;
    public GameObject Panel;
    public GameObject Next;

    //Settings for what data to get from playfab on login.
    public GetPlayerCombinedInfoRequestParams InfoRequestParams;

    //Reference to our Authentication service
    private PlayFabAuthService _AuthService = PlayFabAuthService.Instance;


    public void Awake()
    {

#if FACEBOOK
        FB.Init(OnFBInitComplete, OnFBHideUnity);
#endif

        if (ClearPlayerPrefs)
        {
            _AuthService.UnlinkSilentAuth();
            _AuthService.ClearRememberMe();
            _AuthService.AuthType = Authtypes.None;
        }

        //Set our remember me button to our remembered state.
        RememberMe.isOn = _AuthService.RememberMe;

        //Subscribe to our Remember Me toggle
        RememberMe.onValueChanged.AddListener((toggle) =>
        {
            _AuthService.RememberMe = toggle;
        });
    }

    public void Start()
    {

        //Hide all our panels until we know what UI to display
        Panel.SetActive(false);
        Next.SetActive(false);
        RegisterPanel.SetActive(false);

        //Subscribe to events that happen after we authenticate
        PlayFabAuthService.OnDisplayAuthentication += OnDisplayAuthentication;
        PlayFabAuthService.OnLoginSuccess += OnLoginSuccess;
        PlayFabAuthService.OnPlayFabError += OnPlayFaberror;


        //Bind to UI buttons to perform actions when user interacts with the UI.
        LoginButton.onClick.AddListener(OnLoginClicked);
        PlayAsGuestButton.onClick.AddListener(OnPlayAsGuestClicked);
        LoginWithFacebook.onClick.AddListener(OnLoginWithFacebookClicked);
        LoginWithGoogle.onClick.AddListener(OnLoginWithGoogleClicked);
        RegisterButton.onClick.AddListener(OnRegisterButtonClicked);
        CancelRegisterButton.onClick.AddListener(OnCancelRegisterButtonClicked);

        //Set the data we want at login from what we chose in our meta data.
        _AuthService.InfoRequestParams = InfoRequestParams;

        //Start the authentication process.
        _AuthService.Authenticate();
    }


    /// <summary>
    /// Login Successfully - Goes to next screen.
    /// </summary>
    /// <param name="result"></param>
    private void OnLoginSuccess(PlayFab.ClientModels.LoginResult result)
    {
        Debug.LogFormat("Logged In as: {0}", result.PlayFabId);
        
        //Show our next screen if we logged in successfully.
        Panel.SetActive(false);
        Next.SetActive(true);
    }

    /// <summary>
    /// Error handling for when Login returns errors.
    /// </summary>
    /// <param name="error"></param>
    private void OnPlayFaberror(PlayFabError error)
    {
        //There are more cases which can be caught, below are some
        //of the basic ones.
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

        //Also report to debug console, this is optional.
        Debug.Log(error.Error);
        Debug.LogError(error.GenerateErrorReport());
    }

    /// <summary>
    /// Choose to display the Auth UI or any other action.
    /// </summary>
    private void OnDisplayAuthentication()
    {

#if FACEBOOK
        if (FB.IsInitialized)
        {
            Debug.LogFormat("FB is Init: AccessToken:{0} IsLoggedIn:{1}",AccessToken.CurrentAccessToken.TokenString, FB.IsLoggedIn);
            if (AccessToken.CurrentAccessToken == null || !FB.IsLoggedIn)
            {
                Panel.SetActive(true);
            }
        }
        else
        {
            Panel.SetActive(true);
            Debug.Log("FB Not Init");
        }
#else
        //Here we have choses what to do when AuthType is None.
        Panel.SetActive(true);
#endif
        /*
         * Optionally we could Not do the above and force login silently
         * 
         * _AuthService.Authenticate(Authtypes.Silent);
         * 
         * This example, would auto log them in by device ID and they would
         * never see any UI for Authentication.
         * 
         */
    }

    /// <summary>
    /// Play As a guest, which means they are going to silently authenticate
    /// by device ID or Custom ID
    /// </summary>
    private void OnPlayAsGuestClicked()
    {

        ProgressBar.UpdateLabel("Logging In As Guest ...");
        ProgressBar.UpdateProgress(0f);
        ProgressBar.AnimateProgress(0, 1, () => {
            ProgressBar.UpdateLabel(string.Empty);
            ProgressBar.UpdateProgress(0f);
        });

        _AuthService.Authenticate(Authtypes.Silent);
    }

    /// <summary>
    /// Login Button means they've selected to submit a username (email) / password combo
    /// Note: in this flow if no account is found, it will ask them to register.
    /// </summary>
    private void OnLoginClicked()
    {
        ProgressBar.UpdateLabel(string.Format("Logging In As {0} ...", Username.text));
        ProgressBar.UpdateProgress(0f);
        ProgressBar.AnimateProgress(0, 1, () => {
            //second loop
            ProgressBar.UpdateProgress(0f);
            ProgressBar.AnimateProgress(0, 1, () => {
                ProgressBar.UpdateLabel(string.Empty);
                ProgressBar.UpdateProgress(0f);
            });
        });

        _AuthService.Email = Username.text;
        _AuthService.Password = Password.text;
        _AuthService.Authenticate(Authtypes.EmailAndPassword);
    }

    /// <summary>
    /// No account was found, and they have selected to register a username (email) / password combo.
    /// </summary>
    private void OnRegisterButtonClicked()
    {
        if (Password.text != ConfirmPassword.text)
        {
            ProgressBar.UpdateLabel("Passwords do not Match.");
            return;
        }

        ProgressBar.UpdateLabel(string.Format("Registering User {0} ...", Username.text));
        ProgressBar.UpdateProgress(0f);
        ProgressBar.AnimateProgress(0, 1, () => {
            //second loop
            ProgressBar.UpdateProgress(0f);
            ProgressBar.AnimateProgress(0, 1, () => {
                ProgressBar.UpdateLabel(string.Empty);
                ProgressBar.UpdateProgress(0f);
            });
        });

        _AuthService.Email = Username.text;
        _AuthService.Password = Password.text;
        _AuthService.Authenticate(Authtypes.RegisterPlayFabAccount);
    }

    /// <summary>
    /// They have opted to cancel the Registration process.
    /// Possibly they typed the email address incorrectly.
    /// </summary>
    private void OnCancelRegisterButtonClicked()
    {
        //Reset all forms
        Username.text = string.Empty;
        Password.text = string.Empty;
        ConfirmPassword.text = string.Empty;
        //Show panels
        RegisterPanel.SetActive(false);
        Next.SetActive(false);
    }


    /// <summary>
    /// Login with a facebook account.  This kicks off the request to facebook
    /// </summary>
    private void OnLoginWithFacebookClicked()
    {
        ProgressBar.UpdateLabel("Logging In to Facebook..");
#if FACEBOOK
        FB.LogInWithReadPermissions(new List<string>() { "public_profile", "email", "user_friends" }, OnHandleFBResult);
#endif
    }
#if FACEBOOK
    private void OnHandleFBResult(ILoginResult result)
    {
        if (result.Cancelled)
        {
            ProgressBar.UpdateLabel("Facebook Login Cancelled.");
            ProgressBar.UpdateProgress(0);
        }
        else if(result.Error != null) {
            ProgressBar.UpdateLabel(result.Error);
            ProgressBar.UpdateProgress(0);
        }
        else
        {
            ProgressBar.AnimateProgress(0, 1, () => {
                //second loop
                ProgressBar.UpdateProgress(0f);
                ProgressBar.AnimateProgress(0, 1, () => {
                    ProgressBar.UpdateLabel(string.Empty);
                    ProgressBar.UpdateProgress(0f);
                });
            });
            _AuthService.AuthTicket = result.AccessToken.TokenString;
            _AuthService.Authenticate(Authtypes.Facebook);
        }
    }

    private void OnFBInitComplete()
    {
        if(AccessToken.CurrentAccessToken != null)
        {
            _AuthService.AuthTicket = AccessToken.CurrentAccessToken.TokenString;
            _AuthService.Authenticate(Authtypes.Facebook);
        }
    }

    private void OnFBHideUnity(bool isUnityShown)
    {
        //do nothing.
    }
#endif


    /// <summary>
    /// Login with a google account.  This kicks off the request to google play games.
    /// </summary>
    private void OnLoginWithGoogleClicked()
    {

    }

}
