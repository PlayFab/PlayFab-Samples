
// A $( document ).ready() block.
$( document ).ready(function() {
    console.log( "ready!" );
    StartUpCheck();
    
});


function StartUpCheck()
{
	if (localStorage.titleId) 
	{
	    $("#inputTitleId").val(localStorage.titleId);
	} 
	else 
	{
		$("#inputTitleId").val("Enter your Title Id");
	}

	if (localStorage.userId) 
	{
	    $("#inputUserId").val(localStorage.userId);
	} 
	else 
	{
		$("#inputUserId").val(CreateGUID());
	}
	

	$("#login").click(function() {
		Authenticate();
	});

	$("#spin").click(function() {
		TryToSpin();
	});

	$(".exampleUI").hide();

}

function Authenticate()
{
	// save our local GUID and Title Id to make 
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

		$(".exampleInput").hide();
		$(".exampleUI").show();
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

		var stBalance = result.VirtualCurrency.hasOwnProperty("ST") ? result.VirtualCurrency["ST"] : 0;
		var rechargeDetails;
		var freeTicketDisplay = "Capped";

		if(result.VirtualCurrencyRechargeTimes.hasOwnProperty("ST"))
		{
			rechargeDetails = result.VirtualCurrencyRechargeTimes["ST"];
			if(stBalance < rechargeDetails.RechargeMax)
			{
				var nextFreeTicket = new Date(Date.now());
				nextFreeTicket.setSeconds(nextFreeTicket.getSeconds() + rechargeDetails.SecondsToRecharge);
				freeTicketDisplay = nextFreeTicket.toLocaleDateString() + " \n " +  nextFreeTicket.toLocaleTimeString('en-US');

				console.log("You have " + stBalance + " Spin Tickets.");
				console.log("Your next free ticket will arrive at: "+ freeTicketDisplay);
				
			}
			else
			{
				console.log("Tickets only regenerate to a maximum of " +rechargeDetails.RechargeMax + ", and you currently have "+ stBalance + ".");
			}
		}

		SetUI(stBalance, result.Inventory.length, freeTicketDisplay);
	}
}


function TryToSpin()
{
	console.log("Attempting to spin...");
	var PurchaseItemRequest = {
		"ItemId" : "PrizeWheel1",
		"VirtualCurrency" : "ST",
		"Price" : 1
	};
	PlayFabClientSDK.PurchaseItem(PurchaseItemRequest, TryToSpinCallback);
}

function TryToSpinCallback(request, error)
{
	if(error)
	{
		OutputError(error);
	}	
	else
	{
		var result = request.data;
		console.log("Ticket Accepted! \nSPINNING...");
		console.log("SPIN RESULT: "+ result.Items[1].DisplayName);
		GetInventory();
	}
}



function SetUI(stBalance, invCount, regenValue)
{
	$("#stValue").text("x"+stBalance);
	$("#invValue").text(invCount);
	$("#regenValue").text(regenValue);
}



//callback func(result, error)

function OutputError(error)
{
	console.log(error);
}

// creates a standard GUID string that will be used in our 
function CreateGUID()
{
	//http://stackoverflow.com/questions/105034/create-guid-uuid-in-javascript
	return 'xxxxxxxx-xxxx-4xxx-yxxx-xxxxxxxxxxxx'.replace(/[xy]/g, function(c) {var r = Math.random()*16|0,v=c=='x'?r:r&0x3|0x8;return v.toString(16);});
}