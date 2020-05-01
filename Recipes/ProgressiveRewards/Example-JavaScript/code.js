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
		$(".exampleUI").show();
	}
}

function CheckIn()
{
	console.log("Checking-in with Server...");
	var ExecuteCloudScriptRequest = {
		"FunctionName" : "CheckIn"
	};

	PlayFabClientSDK.ExecuteCloudScript(ExecuteCloudScriptRequest, CheckInCallback);
}

function CheckInCallback(response, error)
{
	if(error)
	{
		OutputError(error);
	}	
	else if(response.data.Error)
	{
		// Output any errors that occurred in Cloud Script
		OutputError(response.data.Error);
	}
	else
	{
		console.log("CheckIn Results:");
		var grantedItems = JSON.parse(response.data.FunctionResult);

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
			console.log("CheckIn Successful! No items granted.");
			for(var z in response.data.Logs)
			{
				console.log(response.data.Logs[z]);
			}
		}
	}
}

function OutputError(error)
{
	console.error(error);
}

// creates a standard GUID string to use as our custom ID
function CreateGUID()
{
	//http://stackoverflow.com/questions/105034/create-guid-uuid-in-javascript
	return 'xxxxxxxx-xxxx-4xxx-yxxx-xxxxxxxxxxxx'.replace(/[xy]/g, function(c) {var r = Math.random()*16|0,v=c=='x'?r:r&0x3|0x8;return v.toString(16);});
}