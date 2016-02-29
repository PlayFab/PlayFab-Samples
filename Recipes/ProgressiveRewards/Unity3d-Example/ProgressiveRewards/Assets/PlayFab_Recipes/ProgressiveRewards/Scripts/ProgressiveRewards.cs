using UnityEngine;
using UnityEngine.UI;
using System;
using System.Collections.Generic;
using PlayFab;
using PlayFab.ClientModels;

public class ProgressiveRewards : MonoBehaviour {
	// UI 
	public Button checkInBtn;
	public Text directions;
	
	// INSPECTOR TWEAKABLES
	public string playFabTitleId = string.Empty;
	
	// Use this for initialization
	void Start () {
		PlayFab.PlayFabSettings.TitleId = this.playFabTitleId;
		LockUI();
		AuthenticateWithPlayFab();
	}
	
	void UnlockUI()
	{
		this.checkInBtn.interactable = true;
		this.directions.gameObject.SetActive(true);
	}
	
	void LockUI()
	{
		this.checkInBtn.interactable = false;
		this.directions.gameObject.SetActive(false);
	}
	
	void GetCloudScriptURL()
	{
		PlayFabClientAPI.ProcessApiCallback<GetCloudScriptUrlResult> OnGetCloudScriptSuccess = (GetCloudScriptUrlResult result) => {
			PlayFab.PlayFabSettings.LogicServerUrl = result.Url;
			Debug.Log("LogicServer ( A.K.A. Cloud Script)  Endpoint retrived.");
			UnlockUI();
		};
		
		PlayFabClientAPI.GetCloudScriptUrl(new GetCloudScriptUrlRequest(), OnGetCloudScriptSuccess, OnApiCallError);
	}
	
	void AuthenticateWithPlayFab()
	{
		PlayFabClientAPI.ProcessApiCallback<LoginResult> OnLoginSuccess = (LoginResult result) => {
			Debug.Log(string.Format("Login Successful. Welcome Player:{0}!", result.PlayFabId));
			Debug.Log(string.Format("Your session ticket is: {0}", result.SessionTicket));
			GetCloudScriptURL();
		};
		
		Debug.Log("Logging into PlayFab...");
		LoginWithCustomIDRequest request = new LoginWithCustomIDRequest() { TitleId = this.playFabTitleId, CustomId = SystemInfo.deviceUniqueIdentifier, CreateAccount = true };
		PlayFabClientAPI.LoginWithCustomID(request, OnLoginSuccess, OnApiCallError, null);
	}
	
	public void CheckIn()
	{
		PlayFabClientAPI.ProcessApiCallback<RunCloudScriptResult> OnCloudScriptSuccess = (RunCloudScriptResult result) => {
			Debug.Log("CheckIn Results:");
			List<ItemInstance> grantedItems = PlayFab.SimpleJson.DeserializeObject<List<ItemInstance>>(result.ResultsEncoded);
				
			if(grantedItems.Count > 0)
			{
				Debug.Log(string.Format("You were granted {0} items:", grantedItems.Count));
				
				string output = string.Empty;
				foreach(var item in grantedItems)
				{
					output += string.Format("\t {0}: {1}\n", item.ItemId, item.Annotation);
				}
				Debug.Log(output);
			}
			else
			{
				Debug.Log("CheckIn Successful! No items granted. \n" + result.ActionLog);
			}
		};
		
		Debug.Log("Checking-in with Server...");
		RunCloudScriptRequest request = new RunCloudScriptRequest() { 
			ActionId = "CheckIn", 
		};
		
		PlayFabClientAPI.RunCloudScript(request, OnCloudScriptSuccess, OnApiCallError);
	}
	
	void OnApiCallError(PlayFabError err)
	{
		string http = string.Format("HTTP:{0}", err.HttpCode);
		string message = string.Format("ERROR:{0} -- {1}", err.Error, err.ErrorMessage);
		string details = string.Empty;
		
		if(err.ErrorDetails != null)
		{
			foreach(var detail in err.ErrorDetails)
			{
				details += string.Format("{0} \n", detail.ToString());
			}
		}
		
		Debug.LogError(string.Format("{0}\n {1}\n {2}\n", http, message, details));
	}
}
