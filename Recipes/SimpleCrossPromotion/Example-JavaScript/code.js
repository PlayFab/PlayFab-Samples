$( document ).ready(function() {
    console.log( "ready!" );
    StartUpCheck();
    
});

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

	$("#checkin").click(function(){
		CheckIn();
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
		GetCloudScript();
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
		$(".exampleUI").show();
	}
}

function CheckIn()
{
	console.log("Checking-in with Server...");
	var RunCloudScriptRequest = {
		"ActionId" : "CheckIn"
	};

	PlayFabClientSDK.RunCloudScript(RunCloudScriptRequest, CheckInCallback);
}

function CheckInCallback(response, error)
{
	if(error)
	{
		OutputError(error);
	}	
	else
	{
		console.log("CheckIn Results:");
		var grantedItems = response.data.Results;

		if(grantedItems.length > 0)
		{
			Debug.Log("You were granted " + grantedItems.length + " items:");

			var output = "";
			for(var item in grantedItems)
			{
				output += "\t " + item.ItemId + " : " + item.Annotation + "\n";
			}
			console.log(output);
		}
		else
		{
			console.log("CheckIn Successful! No items granted. \n" + response.data.ActionLog);
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