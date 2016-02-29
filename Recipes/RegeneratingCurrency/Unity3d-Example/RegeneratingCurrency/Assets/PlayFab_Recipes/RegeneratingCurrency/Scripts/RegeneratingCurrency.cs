using UnityEngine;
using UnityEngine.UI;
using System;
using System.Collections.Generic;
using PlayFab;
using PlayFab.ClientModels;

public class RegeneratingCurrency : MonoBehaviour {
	// UI 
	public Button battleBtn;
	public Button buyLivesBtn;
	public Text livesValue;
	public Text gemsValue;
	public Text livesRegen;
	
	// INSPECTOR TWEAKABLES
	public string playFabTitleId = string.Empty;
	
	// PLAYFAB DATA
	const string extraLivesBundleId = "extraLifeBundle"; 
	const int livesBundlePrice = 50;
	const string gmCode = "GM";
	const string lvCode = "LV";
	DateTime nextFreeTicket = new DateTime();
	
	// Use this for initialization
	void Start () {
		PlayFab.PlayFabSettings.TitleId = this.playFabTitleId;
		LockUI();
		AuthenticateWithPlayFab();
		
	}
	
	// Update is called once per frame
	void Update () {
		
		this.livesRegen.text = string.Format("Next life in: {0:n0} seconds", nextFreeTicket.Subtract(DateTime.Now).TotalSeconds);
	}
	
	void UnlockUI()
	{
		this.battleBtn.interactable = true;
		this.buyLivesBtn.interactable = true;
		this.livesRegen.gameObject.SetActive(true);
		this.gemsValue.gameObject.SetActive(true);
		this.livesValue.gameObject.SetActive(true);
	}
	
	void LockUI()
	{
		this.battleBtn.interactable = false;
		this.buyLivesBtn.interactable = false;
		this.livesRegen.gameObject.SetActive(false);
		this.gemsValue.gameObject.SetActive(false);
		this.livesValue.gameObject.SetActive(false);
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
			GetInventory();
			GetCloudScriptURL();
		};
		
		Debug.Log("Logging into PlayFab...");
		LoginWithCustomIDRequest request = new LoginWithCustomIDRequest() { TitleId = this.playFabTitleId, CustomId = SystemInfo.deviceUniqueIdentifier, CreateAccount = true };
		PlayFabClientAPI.LoginWithCustomID(request, OnLoginSuccess, OnApiCallError, null);
	}
	
	void GetInventory()
	{
		PlayFabClientAPI.ProcessApiCallback<GetUserInventoryResult> OnGetInventoryResult = (GetUserInventoryResult result) => {
			Debug.Log(string.Format("Inventory retrieved. You have {0} items.", result.Inventory.Count));
			
			int gmBalance;
			result.VirtualCurrency.TryGetValue(gmCode, out gmBalance);
			Debug.Log(string.Format("You have {0} Gems.", gmBalance));
			this.gemsValue.text = string.Format("x{0}", gmBalance);
			
			int lvBalance;
			result.VirtualCurrency.TryGetValue(lvCode, out lvBalance);
			Debug.Log(string.Format("You have {0} Lives", lvBalance));
			this.livesValue.text = string.Format("x{0}", lvBalance);
			
			VirtualCurrencyRechargeTime rechargeDetails;
			if(result.VirtualCurrencyRechargeTimes.TryGetValue(lvCode, out rechargeDetails))
			{
				this.nextFreeTicket = rechargeDetails.RechargeTime;
				Debug.Log(string.Format("Your next free ticket will arrive at: {0}", nextFreeTicket));
				this.livesRegen.text = string.Format("Next life in: {0} seconds", nextFreeTicket.Subtract(DateTime.Now).TotalSeconds);
			}
			
			UnlockUI();
		};
		
		Debug.Log("Getting the player inventory...");
		GetUserInventoryRequest request = new GetUserInventoryRequest();
		PlayFabClientAPI.GetUserInventory(request, OnGetInventoryResult, OnApiCallError);
	}
	
	public void TryBuyLives()
	{
		PlayFabClientAPI.ProcessApiCallback<PurchaseItemResult> OnApiCallSuccess = (PurchaseItemResult result) => { 
			Debug.Log("Lives Purchased!");
			Debug.Log(string.Format("{0}", result.Items[1].DisplayName));
			GetInventory();
		};
		
		Debug.Log("Purchaseing Lives...");
		PurchaseItemRequest request = new PurchaseItemRequest() { ItemId = extraLivesBundleId, VirtualCurrency = gmCode, Price = livesBundlePrice };
		PlayFabClientAPI.PurchaseItem(request, OnApiCallSuccess, OnApiCallError);
	}
	
	public void ToBattle()
	{
		PlayFabClientAPI.ProcessApiCallback<RunCloudScriptResult> OnCloudScriptSuccess = (RunCloudScriptResult result) => {
			Debug.Log("BATTLE REPORT:");
			BattleResults grantedItems = PlayFab.SimpleJson.DeserializeObject<BattleResults>(result.ResultsEncoded);
			
			if(grantedItems != null)
			{
				Debug.Log(string.Format("You found {0} gems. \n You lost {1} lives.", grantedItems.gemsFound, grantedItems.lostALife ? 1 : 0));
				//Debug.Log(result.ActionLog); 
				 
				GetInventory();
			}
			else
			{
				Debug.LogError("An error occured when attemtpting to deserialize the BattleResults.");
			}
		};
		
		Debug.Log("BATTLING...");
		RunCloudScriptRequest request = new RunCloudScriptRequest() { 
			ActionId = "Battle", 
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


public class BattleResults
{
	public int gemsFound { get; set; }
	public bool lostALife { get; set; }
}
