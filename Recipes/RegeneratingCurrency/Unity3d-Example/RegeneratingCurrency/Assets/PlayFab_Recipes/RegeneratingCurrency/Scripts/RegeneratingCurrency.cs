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
	private bool areLivesCapped = true;
	
	// INSPECTOR TWEAKABLES
	public string playFabTitleId = string.Empty;
	
	// PLAYFAB DATA
	const string extraLivesBundleId = "extraLivesBundle"; 
	const int livesBundlePrice = 50;
	const string gmCode = "GM";
	const string lvCode = "LV";
	DateTime nextFreeTicket = new DateTime();

	
	// Use this for initialization
	void Start () 
	{
		LockUI();
		PlayFab.PlayFabSettings.TitleId = this.playFabTitleId;
		if(string.IsNullOrEmpty(PlayFab.PlayFabSettings.TitleId))
		{
			Debug.LogWarning("Title Id was not set. To continue, enter your title id in the inspector.");
		}
		
		AuthenticateWithPlayFab();
	}
	
	// Update is called once per frame
	void Update () {
		
		if(this.areLivesCapped == false)
		{
			if(nextFreeTicket.Subtract(DateTime.Now).TotalSeconds <= 0)
			{
				this.livesRegen.text = "Fetching timer...";
				GetInventory();
			}
			else
			{
				this.livesRegen.text = string.Format("Next life in: {0:n0} seconds", nextFreeTicket.Subtract(DateTime.Now).TotalSeconds);
			}
			
		}
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
		PlayFabClientAPI.GetCloudScriptUrl(new GetCloudScriptUrlRequest(), OnGetCloudScriptCallback, OnApiCallError);
	}
	
	void OnGetCloudScriptCallback(GetCloudScriptUrlResult result)
	{
		PlayFab.PlayFabSettings.LogicServerUrl = result.Url;
		Debug.Log("LogicServer ( A.K.A. Cloud Script)  Endpoint retrived.");
		UnlockUI();
	}
	
	void AuthenticateWithPlayFab()
	{
		Debug.Log("Logging into PlayFab...");
		LoginWithCustomIDRequest request = new LoginWithCustomIDRequest() { TitleId = this.playFabTitleId, CustomId = SystemInfo.deviceUniqueIdentifier, CreateAccount = true };
		PlayFabClientAPI.LoginWithCustomID(request, OnLoginCallback, OnApiCallError, null);
	}
	
	void OnLoginCallback(LoginResult result) 
	{
		Debug.Log(string.Format("Login Successful. Welcome Player:{0}!", result.PlayFabId));
		Debug.Log(string.Format("Your session ticket is: {0}", result.SessionTicket));
		GetInventory();
		GetCloudScriptURL();
	}
	
	void GetInventory()
	{
		Debug.Log("Getting the player inventory...");
		GetUserInventoryRequest request = new GetUserInventoryRequest();
		PlayFabClientAPI.GetUserInventory(request, OnGetInventoryCallback, OnApiCallError);
	}
	
	void OnGetInventoryCallback(GetUserInventoryResult result)
	{
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
			string textOut = string.Empty;
			if(lvBalance < rechargeDetails.RechargeMax)
			{
				this.nextFreeTicket = DateTime.Now.AddSeconds(rechargeDetails.SecondsToRecharge);
				textOut = string.Format("Next life in: {0:n0} seconds", rechargeDetails.SecondsToRecharge);
				this.livesRegen.text = textOut;
				this.areLivesCapped = false;
			}
			else
			{
				textOut = string.Format("Lives only regenerate to a maximum of {0}, and you currently have {1}.", rechargeDetails.RechargeMax, lvBalance);
				this.livesRegen.text = string.Empty;
				this.areLivesCapped = true;
			}
			Debug.Log(textOut);
			
		}
		UnlockUI();
	}
	
	public void TryBuyLives()
	{
		Debug.Log("Purchaseing Lives...");
		PurchaseItemRequest request = new PurchaseItemRequest() { ItemId = extraLivesBundleId, VirtualCurrency = gmCode, Price = livesBundlePrice };
		PlayFabClientAPI.PurchaseItem(request, TryBuyLivesCallback, OnApiCallError);
	}
	
	void TryBuyLivesCallback (PurchaseItemResult result)
	{ 
		Debug.Log("Lives Purchased!");
		GetInventory();
	}
	
	public void ToBattle()
	{		
		Debug.Log("BATTLING...");
		RunCloudScriptRequest request = new RunCloudScriptRequest() { 
			ActionId = "Battle", 
		};
		
		PlayFabClientAPI.RunCloudScript(request, ToBattleCallback, OnApiCallError);
	}
	
	void ToBattleCallback (RunCloudScriptResult result)
	{
		Debug.Log("BATTLE REPORT:");
		BattleResults grantedItems = PlayFab.SimpleJson.DeserializeObject<BattleResults>(result.ResultsEncoded);
		
		if(grantedItems != null)
		{
			Debug.Log(string.Format("You found {0} gems. \n You lost {1} lives.", grantedItems.gemsFound, grantedItems.lostALife ? 1 : 0));
			GetInventory();
		}
		else
		{
			Debug.LogError("An error occured when attemtpting to deserialize the BattleResults.");
		}
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

// helper class used for deserializing cloud script return values.
public class BattleResults
{
	public int gemsFound { get; set; }
	public bool lostALife { get; set; }
}
