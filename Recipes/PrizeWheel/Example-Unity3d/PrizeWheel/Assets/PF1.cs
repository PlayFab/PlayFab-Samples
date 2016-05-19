using UnityEngine;
using System.Collections;
using PlayFab;
using PlayFab.ClientModels;

public class PF1 : MonoBehaviour {

	// Use this for initialization
	void Start () {
		PlayFab.PlayFabSettings.TitleId = "A87";
		Login("A87"); 
	}
	
	// Update is called once per frame
	void Update () {
	
	}

	void Login(string titleId)  {
    LoginWithCustomIDRequest request = new LoginWithCustomIDRequest()
    {
        TitleId = titleId,
        CreateAccount = true,
        CustomId = "sdnajfhashifabjkfasdfsajkas"
    };

    PlayFabClientAPI.LoginWithCustomID(request, (result) => {
        string PlayFabId = result.PlayFabId;

        if(result.NewlyCreated)
        {
            Debug.Log("Got PlayFabID: " + PlayFabId + " (new account)");
        }
        else
        {
            Debug.Log("Got PlayFabID: " + PlayFabId + " (existing account)");
        }
    },
    (error) => {
        Debug.Log("Error logging in player with custom ID:");
        Debug.Log(error.ErrorMessage);
    });
} 
}
