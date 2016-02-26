using UnityEngine;
using UnityEngine.UI;
using System;
using System.Collections.Generic;
using PlayFab;
using PlayFab.ClientModels;

public class ReferralCodeDemo : MonoBehaviour {
	// UI 
	public Button redeem;
	public InputField inputReferralCode;
	public Text myReferralCode;
	public Text referredBy;
	public Transform redeemGroup;
	public Transform referredGroup;
	
	// INSPECTOR TWEAKABLES
	public string playFabTitleId = string.Empty;
	public string badgeName = "referralBadge";
	
	// PLAYFAB DATA
	List<ItemInstance> inventory = new List<ItemInstance>();
	
	private bool wasReferralBageFound; 
	
	void Awake()
	{
		LockUI();
	}
	
	// Use this for initialization
	void Start () 
	{
		// set TitleID in the SDK
		PlayFab.PlayFabSettings.TitleId = this.playFabTitleId;
		AuthenticateWithPlayFab();
		// get cloudscript url
		// login custom id
		// get inv & check for Referral Badge
		// unlock UI
		// await redeem clicked
		
	}
	
	
	// Update is called once per frame
	void Update () {
		
	}
	
	
	public void OnRedeemClicked()
	{
		RedeemReferralCode();
	}
	
	
	void HideRedeemGroup()
	{
		this.redeemGroup.gameObject.SetActive(false);
	}
	
	void ShowRedeemGroup()
	{
		this.redeemGroup.gameObject.SetActive(true);
		HideReferredGroup();
	}
	
	void HideReferredGroup()
	{
		this.referredGroup.gameObject.SetActive(false);	
	}
	
	void ShowReferredGroup()
	{
		this.referredGroup.gameObject.SetActive(true);
		HideRedeemGroup();
	}
	
	void UnlockUI()
	{
		SearchForReferralBadge();
		if(this.wasReferralBageFound == true)
		{
			ShowReferredGroup();
		}
		else
		{
			ShowRedeemGroup();
		}
		this.redeem.interactable = true;
		
	}
	
	void LockUI()
	{
		HideRedeemGroup();
		HideReferredGroup();
		this.redeem.interactable = false;
	}
	
	
	
	void AuthenticateWithPlayFab()
	{
		PlayFabClientAPI.ProcessApiCallback<LoginResult> OnLoginSuccess = (LoginResult result) => {
			Debug.Log(string.Format("Login Successful. Welcome Player:{0}!", result.PlayFabId));
			Debug.Log(string.Format("Your session ticket is: {0}", result.SessionTicket));
			Debug.Log(string.Format("Your friend referral code is: {0}", result.PlayFabId));
			this.myReferralCode.text = string.Format("REFERRAL CODE [{0}]", result.PlayFabId);
			GetInventory();
			GetCloudScriptURL();
		};
		
		Debug.Log("Logging into PlayFab...");
		LoginWithCustomIDRequest request = new LoginWithCustomIDRequest() { TitleId = this.playFabTitleId, CustomId = SystemInfo.deviceUniqueIdentifier, CreateAccount = true };
		PlayFabClientAPI.LoginWithCustomID(request, OnLoginSuccess, OnApiCallError, null);
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
	
	void GetInventory()
	{
		PlayFabClientAPI.ProcessApiCallback<GetUserInventoryResult> OnGetInventoryResult = (GetUserInventoryResult result) => {
			Debug.Log(string.Format("Inventory retrieved. You have {0} items.", result.Inventory.Count));
			this.inventory = result.Inventory;
			
			int gmBalance;
			result.VirtualCurrency.TryGetValue("GM", out gmBalance);
			Debug.Log(string.Format("You have {0} Gems.", gmBalance));

		};
		
		Debug.Log("Getting the player inventory...");
		GetUserInventoryRequest request = new GetUserInventoryRequest();
		PlayFabClientAPI.GetUserInventory(request, OnGetInventoryResult, OnApiCallError);
	}

	void SearchForReferralBadge()
	{
		foreach(var itemInstance in this.inventory)
		{
			if(itemInstance.ItemId == this.badgeName)
			{
				this.wasReferralBageFound = true;
				this.referredBy.text = string.Format(itemInstance.Annotation);
			}
		}
	}

	void RedeemReferralCode()
	{
		PlayFabClientAPI.ProcessApiCallback<RunCloudScriptResult> OnCloudScriptSuccess = (RunCloudScriptResult result) => {
			Debug.Log("SUCCESS!...\nYou Just Recieved:");
			List<ItemInstance> grantedItems =\PlayFab.SimpleJson.DeserializeObject<List<ItemInstance>>(result.ResultsEncoded);
			
			if(grantedItems != null)
			{
				string output = string.Empty;
				foreach(var itemInstance in grantedItems)
				{			
					output += string.Format("\t {0} \n", itemInstance.DisplayName); 
				}
				
				this.inventory.AddRange(grantedItems);
				SearchForReferralBadge();
				ShowReferredGroup();
				Debug.Log(output);
				Debug.Log(result.ActionLog); 
			}
			else
			{
				Debug.LogError("An error occured when attemtpting to deserialize the granted items.");
			}
			
		};
		
		Debug.Log("REDEEMING...");
		RunCloudScriptRequest request = new RunCloudScriptRequest() { 
			ActionId = "RedeemReferral", 
			Params = new { 
				referralCode = this.inputReferralCode.text 
			}
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
