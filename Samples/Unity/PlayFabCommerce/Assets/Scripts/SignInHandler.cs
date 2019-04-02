using PlayFab.ClientModels;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class SignInHandler : MonoBehaviour {

    public Button SignInButton;
	// Use this for initialization
	void Start () {
        SignInButton.onClick.AddListener(SignInUser);

        PlayFabAuthService.OnLoginSuccess += SignInSuccess;

    }
	
    void SignInUser()
    {
        PlayFabAuthService.Instance.Authenticate(Authtypes.Silent);
    }

    void SignInSuccess(LoginResult result)
    {
        SignInButton.GetComponentInChildren<Text>().text = "Signed In";
    }
}
