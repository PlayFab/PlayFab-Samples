$( document ).ready(function() {
    console.log( "ready!" );
    StartUpCheck();
    
});

//Some GLOBALS
var inventory;
var badgeName = "referralBadge";

function StartUpCheck()
{
	// check for a stored TitleId to use
	if (localStorage.titleId) 
	{
	    $("#inputTitleId").val(localStorage.titleId);
	} 
	else 
	{
		$("#inputTitleId").val("Enter your Title Id");
	}

	// check for a stored UserId to use
	if (localStorage.userId) 
	{
	    $("#inputUserId").val(localStorage.userId);
	} 
	else 
	{
		$("#inputUserId").val(CreateGUID());
	}
	
	// hook up our buttons
	$("#login").click(function() {
		Authenticate();
	});

	$("#redeem").click(function() {
		RedeemReferralCode();
	});

	// hide the main ui until we are authenticated
	$(".exampleUI").hide();
}

function Authenticate()
{
	// save our local GUID and Title Id so we use the same one (or at least until our cookies are cleared)
	localStorage.titleId = $("#inputTitleId").val();
	localStorage.userId = $("#inputUserId").val();

	PlayFab.settings.titleId = $("#inputTitleId").val();
	var LoginWithCustomIDRequest = {
		"TitleId" : PlayFab.settings.titleId,
		"CustomId" : $("#inputUserId").val(),
		"CreateAccount" : true
	};

	console.log("Logging into PlayFab...");
	PlayFabClientSDK.LoginWithCustomID(LoginWithCustomIDRequest, AuthenticationCallback);
}

function AuthenticationCallback(response, error)
{
	if(error)
	{
		OutputError(error);
	}	
	else
	{
		var result = response.data;
		console.log("Login Successful. Welcome Player: " + result.PlayFabId);
		console.log("Your session ticket is: " + result.SessionTicket);
		console.log("Your friend referral code is: " + result.PlayFabId);

		$("#referralValue").text("[" + result.PlayFabId + "]");

		$(".loginUI").hide();
		GetCloudScript();
		GetInventory();
	}
}

function GetInventory()
{
	console.log("Getting the player inventory...");
	PlayFabClientSDK.GetUserInventory({}, GetInventoryCallback);
}

function GetInventoryCallback(response, error)
{
	if(error)
	{
		OutputError(error);
	}	
	else
	{
		var result = response.data;
		var gmBalance = result.VirtualCurrency.hasOwnProperty("GM") ? result.VirtualCurrency["GM"] : 0;
		console.log("You have " + gmBalance + " Gems.");
		
		inventory = result.Inventory;
		console.log("Inventory retrieved. You have " + result.Inventory.length + " items.");

		SearchForReferralBadge();
		$(".exampleUI").show();
	}
}

function GetCloudScript()
{
	PlayFabClientSDK.GetCloudScriptUrl({}, GetCloudScriptCallback);
}

function GetCloudScriptCallback(response, error)
{
	if(error)
	{
		OutputError(error);
	}	
	else
	{
		console.log("LogicServer ( A.K.A. Cloud Script)  Endpoint retrived.");
	}
}

function RedeemReferralCode()
{
	console.log("REDEEMING...");
	var RunCloudScriptRequest = {
		"ActionId" : "RedeemReferral",
		"Params" : {
			"referralCode" : $("#inputReferralCode").val()
		}
	};

	PlayFabClientSDK.RunCloudScript(RunCloudScriptRequest, RedeemReferralCodeCallback);
}

function RedeemReferralCodeCallback(response, error)
{
	if(error)
	{
		OutputError(error);
	}	
	else
	{
		console.log("SUCCESS!...\nYou Just Recieved:");
		var grantedItems = response.data.Results;

		if(grantedItems)
		{
			var output = "";
			for(var item in grantedItems )
			{
				output += "\t " + grantedItems[item].itemId + " \n"; 
			}
			inventory.push(grantedItems);

			console.log(output);
			console.log(response.data.ActionLog);

			SearchForReferralBadge();

			$("#redeemUI").hide();

		}
		else
		{
			console.log("An error occured when attemtpting to deserialize the BattleResults.");
		}
	}
}

function SearchForReferralBadge()
{
	for(var index in inventory)
	{
		if(inventory[index].ItemId == this.badgeName)
		{
			console.log("Referral Badge Found!");
			wasReferralBageFound = true;
			$("#redeemUI").hide();
			$("#referredBy").text(inventory[index].Annotation);
			$("#referredUI").show();
		}
	}
}

function OutputError(error)
{
	console.log(error);
}

// creates a standard GUID string that will be used as our custom ID
function CreateGUID()
{
	//http://stackoverflow.com/questions/105034/create-guid-uuid-in-javascript
	return 'xxxxxxxx-xxxx-4xxx-yxxx-xxxxxxxxxxxx'.replace(/[xy]/g, function(c) {var r = Math.random()*16|0,v=c=='x'?r:r&0x3|0x8;return v.toString(16);});
}