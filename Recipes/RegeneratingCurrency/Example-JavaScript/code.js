$( document ).ready(function() {
    console.log( "ready!" );
    StartUpCheck();
    
});

// SOME GLOBALS
var areLivesCapped = true;
var nextAwardDate = new Date(Date.now());;
var updateLoop;

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

	$("#battle").click(function() {
		ToBattle();
	});

	$("#buyLives").click(function(){
		TryBuyLives();
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

		$(".loginUI").hide();
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
		console.log("Inventory retrieved. You have " + result.Inventory.length + " items.");


		var gmBalance = result.VirtualCurrency.hasOwnProperty("GM") ? result.VirtualCurrency["GM"] : 0;
		console.log("You have " + gmBalance + " Gems.");
		$("#gmValue").text("x"+gmBalance);

		var lvBalance = result.VirtualCurrency.hasOwnProperty("LV") ? result.VirtualCurrency["LV"] : 0;
		console.log("You have " + lvBalance + " Lives.");
		$("#lvValue").text("x"+lvBalance);

		var rechargeDetails;
		if(result.VirtualCurrencyRechargeTimes.hasOwnProperty("LV"))
		{
			rechargeDetails = result.VirtualCurrencyRechargeTimes["LV"];
			if(lvBalance < rechargeDetails.RechargeMax)
			{
				nextAwardDate = new Date(Date.now());
				nextAwardDate.setSeconds(nextAwardDate.getSeconds() + rechargeDetails.SecondsToRecharge);

				areLivesCapped = false;
				console.log("Next life in: " + rechargeDetails.SecondsToRecharge + " seconds.");

				$("#regenValue").text("Next life in: " + rechargeDetails.SecondsToRecharge + " seconds.");
				updateLoop = setInterval(UpdateLoop, 1000); // set our update loop to tick once every second.
			}
			else
			{
				clearInterval(updateLoop); // cancel the update loop
				$("#regenValue").text("");

				areLivesCapped = true;
				console.log("Tickets only regenerate to a maximum of " + rechargeDetails.RechargeMax + ", and you currently have "+ lvBalance + ".");
			}
		}
		$(".exampleUI").show();
	}
}

function TryBuyLives()
{
	console.log("Purchaseing Lives...");
	var PurchaseItemRequest = {
		"CatalogVersion": "RegeneratingCurrency",
		"ItemId" : "extraLivesBundle",
		"VirtualCurrency" : "GM",
		"Price" : 50
	};
	PlayFabClientSDK.PurchaseItem(PurchaseItemRequest, TryBuyLivesCallback);
}

function TryBuyLivesCallback(request, error)
{
	if(error)
	{
		OutputError(error);
	}	
	else
	{
		var result = request.data;
		console.log("Lives Purchased!");
		GetInventory();
	}
}

function ToBattle()
{
	console.log("Battling...");
	var ExecuteCloudScriptRequest = {
		"FunctionName" : "Battle"
	};

	PlayFabClientSDK.ExecuteCloudScript(ExecuteCloudScriptRequest, ToBattleCallback);
}

function ToBattleCallback(response, error)
{
	if(error)
	{
		OutputError(error);
	}	
	else if(response.data.Error)
	{
		// Output any errors that occured in Cloud Script
		OutputError(response.data.Error);
	}
	else
	{
		console.log("BATTLE REPORT:");
		var grantedItems = JSON.parse(response.data.FunctionResult);

		if(grantedItems)
		{
			var livesLost = grantedItems.lostALife ? 1 : 0;
			console.log("You found "+ grantedItems.gemsFound +" gems. \n You lost "+ livesLost +" lives.");
			GetInventory();
		}
		else
		{
			console.log("An error occured when attemtpting to deserialize the BattleResults.");
		}
	}
}

function UpdateLoop()
{
	if(areLivesCapped == false)
	{
		var secondsLeft = (nextAwardDate.getTime() - Date.now()) * 0.001; // date math in milliseconds, converted to seconds
		if(secondsLeft <= 0)
		{
			$("#regenValue").text("Fetching timer...");
			GetInventory();
		}
		else
		{
			$("#regenValue").text("Next life in: " + secondsLeft.toFixed(0) + " seconds");
		}
	}
}

function OutputError(error)
{
	console.error(error);
}

// creates a standard GUID string that will be used as our custom ID
function CreateGUID()
{
	//http://stackoverflow.com/questions/105034/create-guid-uuid-in-javascript
	return 'xxxxxxxx-xxxx-4xxx-yxxx-xxxxxxxxxxxx'.replace(/[xy]/g, function(c) {var r = Math.random()*16|0,v=c=='x'?r:r&0x3|0x8;return v.toString(16);});
}