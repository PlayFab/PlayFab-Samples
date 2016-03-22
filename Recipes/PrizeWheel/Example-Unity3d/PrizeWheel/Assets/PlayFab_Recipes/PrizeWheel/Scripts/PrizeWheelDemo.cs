﻿using UnityEngine;
using UnityEngine.UI;
using System;
using System.Collections.Generic;
using PlayFab;
using PlayFab.ClientModels;

public class PrizeWheelDemo : MonoBehaviour {
	// UI 
	public Button spin;
	public Text spinTicketBalance;
	public Text timeUntilNextFreeSpin;
	public Text itemCount;
	
	// INSPECTOR TWEAKABLES
	public string playFabTitleId = string.Empty;
	
	// Use this for initialization
	void Start () 
	{
		LockUI();
		// set TitleID in the SDK
		PlayFab.PlayFabSettings.TitleId = this.playFabTitleId;
		if(string.IsNullOrEmpty(PlayFab.PlayFabSettings.TitleId))
		{
			Debug.LogWarning("Title Id was not set. To continue, enter your title id in the inspector.");
		}
		AuthenticateWithPlayFab();
	}
	
	public void OnSpinClicked()
	{
		TryToSpin();
	}
	
	void SetUI(int tickets, int items, string nextFree)
	{
		this.spinTicketBalance.text = string.Format("x{0}", tickets);
		this.itemCount.text = string.Format("{0}", items);
		this.timeUntilNextFreeSpin.text = string.Format("{0}", nextFree);
	}
	
	void UnlockUI()
	{
		this.spin.interactable = true;
		this.itemCount.gameObject.SetActive(true);
		this.timeUntilNextFreeSpin.gameObject.SetActive(true);
		this.spinTicketBalance.gameObject.SetActive(true);
	}
	
	void LockUI()
	{
		this.spin.interactable = false;
		this.itemCount.gameObject.SetActive(false);
		this.timeUntilNextFreeSpin.gameObject.SetActive(false);
		this.spinTicketBalance.gameObject.SetActive(false);
	}
	
	
	void AuthenticateWithPlayFab()
	{
		Debug.Log("Logging into PlayFab...");
		LoginWithCustomIDRequest request = new LoginWithCustomIDRequest() { TitleId = this.playFabTitleId, CustomId = SystemInfo.deviceUniqueIdentifier, CreateAccount = true };
		PlayFabClientAPI.LoginWithCustomID(request, OnLoginCallback, OnApiCallError, null);
	}
	
	void OnLoginCallback (LoginResult result) 
	{
		Debug.Log(string.Format("Login Successful. Welcome Player:{0}!", result.PlayFabId));
		Debug.Log(string.Format("Your session ticket is: {0}", result.SessionTicket));
		GetInventory();
	}
	
	void GetInventory()
	{
		Debug.Log("Getting the player inventory...");
		GetUserInventoryRequest request = new GetUserInventoryRequest();
		PlayFabClientAPI.GetUserInventory(request, GetInventoryCallback, OnApiCallError);
	}
	
	void GetInventoryCallback (GetUserInventoryResult result)
	{
		Debug.Log(string.Format("Inventory retrieved. You have {0} items.", result.Inventory.Count));
		
		int stBalance;
		result.VirtualCurrency.TryGetValue("ST", out stBalance);
		
		VirtualCurrencyRechargeTime rechargeDetails;
		
		string freeTicketDisplay = string.Format("Capped");
		if(result.VirtualCurrencyRechargeTimes.TryGetValue("ST", out rechargeDetails))
		{
			if(stBalance < rechargeDetails.RechargeMax)
			{
				DateTime nextFreeTicket = new DateTime();
				nextFreeTicket = DateTime.Now.AddSeconds(rechargeDetails.SecondsToRecharge);
				Debug.Log(string.Format("You have {0} Spin Tickets.", stBalance));
				Debug.Log(string.Format("Your next free ticket will arrive at: {0}", nextFreeTicket));
				freeTicketDisplay = string.Format("{0}", nextFreeTicket);
			}
			else
			{
				Debug.Log(string.Format("Tickets only regenerate to a maximum of {0}, and you currently have {1}.", rechargeDetails.RechargeMax, stBalance));
			}
			
		}
		
		SetUI(stBalance, result.Inventory.Count, freeTicketDisplay);
		UnlockUI();
	}
	
	void TryToSpin()
	{
		Debug.Log("Attempting to spin...");
		PurchaseItemRequest request = new PurchaseItemRequest() { ItemId = "PrizeWheel1", VirtualCurrency = "ST", Price = 1 };
		PlayFabClientAPI.PurchaseItem(request, TryToSpinCallback, OnApiCallError);
	}
	
	void TryToSpinCallback (PurchaseItemResult result) 
	{ 
		Debug.Log("Ticket Accepted! \nSPINNING...");
		Debug.Log(string.Format("SPIN RESULT: {0}", result.Items[1].DisplayName));
		
		GetInventory();
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
