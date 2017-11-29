using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class LoggedInWindowView : MonoBehaviour {
    public Toggle RememberMe;

    private PlayFabAuthService _AuthService = PlayFabAuthService.Instance;

    // Use this for initialization
    void OnEnable () {
        RememberMe.isOn = _AuthService.RememberMe;
        RememberMe.onValueChanged.AddListener(OnRememberMeChanged);
	}

    private void OnDisable()
    {
        RememberMe.onValueChanged.RemoveListener(OnRememberMeChanged);
    }

    private void OnRememberMeChanged(bool toggle)
    {
        _AuthService.RememberMe = toggle;
    }
}
