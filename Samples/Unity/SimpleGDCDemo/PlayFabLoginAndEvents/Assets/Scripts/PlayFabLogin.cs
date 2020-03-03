using PlayFab;
using PlayFab.ClientModels;
using PlayFab.EventsModels;
using UnityEngine;
using System;
using System.Collections;
using System.Threading.Tasks;
using PlayFab.DataModels;
using System.Collections.Generic;

public class PlayFabLogin : MonoBehaviour
{
    bool loggedIn = false;

    public void Start()
    {
        if (string.IsNullOrEmpty(PlayFabSettings.TitleId))
        {
            /*
            Please change the titleId below to your own titleId from PlayFab Game Manager.
            If you have already set the value in the Editor Extensions, this can be skipped.
            */
            PlayFabSettings.TitleId = "7C1D";
        }
        var request = new LoginWithCustomIDRequest { CustomId = "GettingStartedGuide", CreateAccount = true };
        PlayFabClientAPI.LoginWithCustomID(request, OnLoginSuccess, OnLoginFailure);

        StartCoroutine(WriteTelemtry());
    }

    private void OnLoginSuccess(LoginResult result)
    {
        Debug.Log("Congratulations, you made your first successful API call!");
        loggedIn = true;
    }

    private void OnLoginFailure(PlayFabError error)
    {
        Debug.LogWarning("Something went wrong with your first API call.  :(");
        Debug.LogError("Here's some debug information:");
        Debug.LogError(error.GenerateErrorReport());
    }

    private void OnEventWriteSuccess(WriteEventsResponse result)
    {
        Debug.Log("Telemetry API call succeeded!");
    }

    private void OnEventWriteError(PlayFabError error)
    {
        Debug.LogWarning("Telemetry API call failed.  :(");
        Debug.LogError(error.GenerateErrorReport());
    }

    private EventContents CreateEventsContents(string name, int i)
    {
        string payload = "{\"Terminator\":\"Skynet\"}";
        EventContents eventContents = new EventContents();
        string eventName = name + i;
        eventContents.Name = eventName;
        eventContents.EventNamespace = "custom.playfab.events.default";
        eventContents.PayloadJSON = payload;
        return eventContents;
    }

    IEnumerator WriteTelemtry()
    {
        yield return new WaitUntil(() => loggedIn == true);
        // Write the PlayFab Event
        var telemetryRequest = new WriteEventsRequest();
        telemetryRequest.Events = new List<EventContents>();
        telemetryRequest.Events.Add(CreateEventsContents("event_Y_", 0));
        telemetryRequest.Events.Add(CreateEventsContents("event_Z_", 1));
        PlayFabEventsAPI.WriteEvents(telemetryRequest, OnEventWriteSuccess, OnEventWriteError);
    }
}