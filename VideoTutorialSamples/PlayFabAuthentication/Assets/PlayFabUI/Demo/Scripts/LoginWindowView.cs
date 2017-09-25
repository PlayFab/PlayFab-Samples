using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class LoginWindowView : MonoBehaviour {
    public InputField Username;
    public InputField Password;
    public Button LoginButton;
    public Button PlayAsGuestButton;
    public Button LoginWithFacebook;
    public Button LoginWithGoogle;

    public PlayFab.UI.ProgressBarView ProgressBar;

    public void Awake()
    {
        ValidateLoginType((firstTimeUser) =>
        {
            if (firstTimeUser)
            {
                //Setup Button Bindings
                LoginButton.onClick.AddListener(OnLoginClicked);
                PlayAsGuestButton.onClick.AddListener(OnPlayAsGuestClicked);
                LoginWithFacebook.onClick.AddListener(OnLoginWithFacebookClicked);
                LoginWithGoogle.onClick.AddListener(OnLoginWithGoogleClicked);
            }
            else
            { 
                //Go To Profile Screen
            }
        });
    }

    public void ValidateLoginType(Action<bool> callback)
    {
        callback(true);
    }

    private void OnPlayAsGuestClicked()
    {
        ProgressBar.UpdateLabel("Logging In As Guest ...");
        ProgressBar.UpdateProgress(0f);
        ProgressBar.AnimateProgress(0, 1, ()=> {
            ProgressBar.UpdateLabel(string.Empty);
            ProgressBar.UpdateProgress(0f);
        });
    }

    private void OnLoginClicked()
    {
        
    }

    private void OnLoginWithFacebookClicked()
    {

    }

    private void OnLoginWithGoogleClicked()
    {

    }

}
