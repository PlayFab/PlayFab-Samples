//GLOBALS for ease of use
var achv_catalog = "Achievements";
var achv_itemClass = "AchievementBadge";
var achv_completeEvent = "achievement_badge_complete";
var default_vc_code = "Au";
var bottomsUp_itemClass = "Potion";

// the values here correspond to the Catalog ItemId
var achv = {
	"SocialPlayer" : "badge_01",
	"Millionaire" : "badge_02",
	"VIP" : "badge_03",
	"BottomsUp" : "badge_04",
	"Brawler" : "badge_05"
};

// the values here correspond to the PlayStream event name
var achv_eventNames = {
	"SocialPlayer" : "link_facebook",
	"Millionaire" : "vc_changed",
	"VIP" : "item_purchased",
	"BottomsUp" : "item_consumed",
	"Brawler" : "stat_update"
};


handlers.EvaluateSocialPlayer = function (args, context)
{
	// limit so that this call only be triggered by a valid PlayStream Event
	if(context.playerProfile == null || context.playStreamEvent == null)
	{
		return "A null context was provided, perhaps this was called in error?";
	}
	else if(context.playStreamEvent.EventName != achv_eventNames["SocialPlayer"])
	{
		return "Event name mismatch. Cannot continue.";
	}

	var badgeInstance = GetBadgeByIdAndClass(achv["SocialPlayer"], achv_itemClass, context); 
	if(!badgeInstance)
	{
		//User does not have achievement, need to grant it
		badgeInstance = {};
		badgeInstance.ItemId = achv["SocialPlayer"];
		badgeInstance = GrantBadge(badgeInstance, context);
	}

	// User does have achievement, update the progress
	var abort = false;
	var changesMade = false;

	// set the start date if not already set
	if(badgeInstance.CustomData && badgeInstance.CustomData.hasOwnProperty("DateStarted"))
	{
		badgeInstance.CustomData["DateStarted"] = badgeInstance.CustomData["DateStarted"] == "0" ? Today().toDateString() : badgeInstance.CustomData["DateStarted"];
		changesMade = true;
	}

	// evaluate badge status
	if(badgeInstance.CustomData && badgeInstance.CustomData.hasOwnProperty("DateAchieved"))
	{
		if(badgeInstance.CustomData["DateAchieved"] != "0")
		{
			// this player has already achieved this badge, no further processing.
			return "Player has already completed " + badgeInstance.ItemId;
		}
		else
		{
			// this player just completed this badge
			badgeInstance.CustomData["DateAchieved"] = Today().toDateString();
			changesMade = true;
			WriteAchievementCompleteEvent(achv_completeEvent, badgeInstance.ItemId, context);
		}
	}	
	else
	{
		abort = true;
	}
	
	if(!abort && changesMade)
	{
		UpdateBadgeCustomData(badgeInstance, context);
		return "Badge Updated!";
	}
	else if (abort)
	{
		return "Aborted process due to a mismatch within the CustomData for " + badgeInstance.ItemId;
	}
	else
	{
		return "Evaluation Completed.";
	}
}

handlers.EvaluateMillionaire = function (args, context)
{
	// limit so that this call only be triggered by a valid PlayStream Event
	if(context.playerProfile == null || context.playStreamEvent == null)
	{
		return "A null context was provided, perhaps this was called in error?";
	}
	else if(context.playStreamEvent.EventName != achv_eventNames["Millionaire"])
	{
		return "Event name mismatch. Cannot continue.";
	}

	var badgeInstance = GetBadgeByIdAndClass(achv["Millionaire"], achv_itemClass, context); 
	if(!badgeInstance)
	{
		//User does not have achievement, need to grant it
		badgeInstance = {};
		badgeInstance.ItemId = achv["Millionaire"];
		badgeInstance = GrantBadge(badgeInstance, context);
	}

	// User does have achievement, update the progress
	var abort = false;
	var changesMade = false;

	// set the start date if not already set
	if(badgeInstance.CustomData && badgeInstance.CustomData.hasOwnProperty("DateStarted"))
	{
		badgeInstance.CustomData["DateStarted"] = badgeInstance.CustomData["DateStarted"] == "0" ? Today().toDateString() : badgeInstance.CustomData["DateStarted"];
		changesMade = true;
	}

	// update the CurrentValue
	var previousValue = 0;
	if(badgeInstance.CustomData && badgeInstance.CustomData.hasOwnProperty("CurrentValue"))
	{
		// here we are tracking our historic best (highest) value
		previousValue = parseInt(badgeInstance.CustomData["CurrentValue"]);
		if(context.playStreamEvent.VirtualCurrencyBalance > previousValue)
		{
			badgeInstance.CustomData["CurrentValue"] = context.playStreamEvent.VirtualCurrencyBalance;
			changesMade = true;
		}
	}
	else
	{
		abort = true;
	}

	// compare current value to the threshold
	if(badgeInstance.CustomData && badgeInstance.CustomData.hasOwnProperty("DateAchieved") && badgeInstance.CustomData.hasOwnProperty("Threshold") && badgeInstance.CustomData.hasOwnProperty("CurrentValue"))
	{
		if(badgeInstance.CustomData["DateAchieved"] != "0")
		{
			if(changesMade)
			{
				UpdateBadgeCustomData(badgeInstance, context);
			}

			// This player has already achieved this badge, no further processing.
			return "Player has already completed " + badgeInstance.ItemId;
		}

		if(parseInt(badgeInstance.CustomData["CurrentValue"]) >= parseInt(badgeInstance.CustomData["Threshold"]))
		{
			// this player just completed this badge
			badgeInstance.CustomData["DateAchieved"] = Today().toDateString();
			changesMade = true;
			WriteAchievementCompleteEvent(achv_completeEvent, badgeInstance.ItemId, context);
		}
	}	
	else
	{
		abort = true;
	}
	
	if(!abort && changesMade)
	{
		UpdateBadgeCustomData(badgeInstance, context);
		return "Badge Updated!";
	}
	else if (abort)
	{
		return "Aborted process due to a mismatch within the CustomData for " + badgeInstance.ItemId;
	}
	else
	{
		return "Evaluation Completed.";
	}
}

handlers.EvaluateBigPurchase = function (args, context)
{
	// limit so that this call only be triggered by a valid PlayStream Event
	if(context.playerProfile == null || context.playStreamEvent == null)
	{
		return "A null context was provided, perhaps this was called in error?";
	}
	else if(context.playStreamEvent.EventName != achv_eventNames["VIP"])
	{
		return "Event name mismatch. Cannot continue.";
	}

	var badgeInstance = GetBadgeByIdAndClass(achv["VIP"], achv_itemClass, context); 
	if(!badgeInstance)
	{
		//User does not have achievement, need to grant it
		badgeInstance = {};
		badgeInstance.ItemId = achv["VIP"];
		badgeInstance = GrantBadge(badgeInstance, context);
	}

	// User does have achievement, update the progress
	var abort = false;
	var changesMade = false;

	// set the start date if not already set
	if(badgeInstance.CustomData && badgeInstance.CustomData.hasOwnProperty("DateStarted"))
	{
		badgeInstance.CustomData["DateStarted"] = badgeInstance.CustomData["DateStarted"] == "0" ? Today().toDateString() : badgeInstance.CustomData["DateStarted"];
		changesMade = true;
	}

	// here we are tracking our historic best (highest) value
	var previousBest = 0;
	if(badgeInstance.CustomData && badgeInstance.CustomData.hasOwnProperty("Best"))
	{
		previousBest = parseInt(badgeInstance.CustomData["Best"]);
		if(context.playStreamEvent.UnitPrice > previousBest)
		{
			badgeInstance.CustomData["Best"] = context.playStreamEvent.UnitPrice;
			changesMade = true;
		}
	}
	else
	{
		abort = true;
	}

	// evaluate badge status 
	if(badgeInstance.CustomData && badgeInstance.CustomData.hasOwnProperty("DateAchieved"))
	{
		if(badgeInstance.CustomData["DateAchieved"] != "0")
		{
			if(changesMade)
			{
				UpdateBadgeCustomData(badgeInstance, context);
			}
			// This player has already achieved this badge, no further processing.
			return "Player has already completed " + badgeInstance.ItemId;
		}
		else
		{
			// this player just completed this badge
			badgeInstance.CustomData["DateAchieved"] = Today().toDateString();
			changesMade = true;
			WriteAchievementCompleteEvent(achv_completeEvent, badgeInstance.ItemId, context);
		}
	}	
	else
	{
		abort = true;
	}
	
	if(!abort && changesMade)
	{
		UpdateBadgeCustomData(badgeInstance, context);
		return "Badge Updated!";
	}
	else if (abort)
	{
		return "Aborted process due to a mismatch within the CustomData for " + badgeInstance.ItemId;
	}
	else
	{
		return "Evaluation Completed.";
	}
}

handlers.EvaluateBottomsUp = function (args, context)
{
	var catalog, catalogItem;
	if(context.playerProfile == null || context.playStreamEvent == null)
	{
		return "A null context was provided, perhaps this was called in error?";
	}
	else if(context.playStreamEvent.EventName != achv_eventNames["BottomsUp"])
	{
		return "Event name mismatch. Cannot continue.";
	}
	else
	{
		catalog = GetCatalog(achv_catalog);
		if(!catalog)
		{
			return "Ran into an error when fetching the items catalog.";
		}

		catalogItem = catalog.find((element, index, array)=> { return element.ItemId == context.playStreamEvent.ItemId }); 

		if(!catalogItem || catalogItem.ItemClass != bottomsUp_itemClass)
		{
			return "Item is not a potion. Exiting.";
		}
	}

	var badgeInstance = GetBadgeByIdAndClass(achv["BottomsUp"], achv_itemClass, context); 
	if(!badgeInstance)
	{
		// User does not have achievement, need to grant it
		badgeInstance = {};
		badgeInstance.ItemId = achv["BottomsUp"];
		badgeInstance = GrantBadge(badgeInstance, context, catalog); // this time we already got the catalog, so we can pass it along.
	}

	// User does have achievement, update the progress
	var abort = false;
	var changesMade = false;

	// set the start date if not already set
	if(badgeInstance.CustomData && badgeInstance.CustomData.hasOwnProperty("DateStarted"))
	{
		badgeInstance.CustomData["DateStarted"] = badgeInstance.CustomData["DateStarted"] == "0" ? Today().toDateString() : badgeInstance.CustomData["DateStarted"];
		changesMade = true;
	}

	// update the CurrentValue
	var previousValue = 0;
	var consumed = parseInt(context.playStreamEvent.PreviousUsesRemaining) - parseInt(context.playStreamEvent.UsesRemaining);
	if(badgeInstance.CustomData && badgeInstance.CustomData.hasOwnProperty("CurrentValue"))
	{
		// here we are tracking our historic best (highest) value
		badgeInstance.CustomData["CurrentValue"] = parseInt(badgeInstance.CustomData["CurrentValue"]) + consumed;
		changesMade = true;
	}
	else
	{
		abort = true;
	}

	// compare current value to the threshold
	if(badgeInstance.CustomData && badgeInstance.CustomData.hasOwnProperty("DateAchieved") && badgeInstance.CustomData.hasOwnProperty("Threshold") && badgeInstance.CustomData.hasOwnProperty("CurrentValue"))
	{
		if(badgeInstance.CustomData["DateAchieved"] != "0")
		{
			if(changesMade)
			{
				UpdateBadgeCustomData(badgeInstance, context);
			}

			// This player has already achieved this badge, no further processing.
			return "Player has already completed " + badgeInstance.ItemId;
		}

		if(parseInt(badgeInstance.CustomData["CurrentValue"]) >= parseInt(badgeInstance.CustomData["Threshold"]))
		{
			// this player just completed this badge
			badgeInstance.CustomData["DateAchieved"] = Today().toDateString();
			changesMade = true;
			WriteAchievementCompleteEvent(achv_completeEvent, badgeInstance.ItemId, context);
		}
	}	
	else
	{
		abort = true;
	}
	
	if(!abort && changesMade)
	{
		UpdateBadgeCustomData(badgeInstance, context);
		return "Badge Updated!";
	}
	else if (abort)
	{
		return "Aborted process due to a mismatch within the CustomData for " + badgeInstance.ItemId;
	}
	else
	{
		return "Evaluation Completed.";
	}
}

handlers.EvaluateBrawler = function (args, context)
{
	var catalog, catalogItem;
	if(context.playerProfile == null || context.playStreamEvent == null)
	{
		return "A null context was provided, perhaps this was called in error?";
	}
	else if(context.playStreamEvent.EventName != achv_eventNames["Brawler"])
	{
		return "Event name mismatch. Cannot continue.";
	}

	var badgeInstance = GetBadgeByIdAndClass(achv["Brawler"], achv_itemClass, context); 
	if(!badgeInstance)
	{
		// User does not have achievement, need to grant it
		badgeInstance = {};
		badgeInstance.ItemId = achv["Brawler"];
		badgeInstance = GrantBadge(badgeInstance, context);
	}

	// User does have achievement, update the progress
	var abort = false;
	var changesMade = false;

	// set the start date if not already set
	if(badgeInstance.CustomData && badgeInstance.CustomData.hasOwnProperty("DateStarted"))
	{
		badgeInstance.CustomData["DateStarted"] = badgeInstance.CustomData["DateStarted"] == "0" ? Today().toDateString() : badgeInstance.CustomData["DateStarted"];
		changesMade = true;
	}

	// update the CurrentValue
	if(badgeInstance.CustomData && badgeInstance.CustomData.hasOwnProperty("CurrentValue"))
	{
		// here we are tracking our historic best (highest) value
		badgeInstance.CustomData["CurrentValue"] = parseInt(context.playStreamEvent.StatisticValue);
		changesMade = true;
	}
	else
	{
		abort = true;
	}

	// compare current value to the threshold
	if(badgeInstance.CustomData && badgeInstance.CustomData.hasOwnProperty("DateAchieved") && badgeInstance.CustomData.hasOwnProperty("Threshold") && badgeInstance.CustomData.hasOwnProperty("CurrentValue"))
	{
		if(badgeInstance.CustomData["DateAchieved"] != "0")
		{
			if(changesMade)
			{
				UpdateBadgeCustomData(badgeInstance, context);
			}

			// This player has already achieved this badge, no further processing.
			return "Player has already completed " + badgeInstance.ItemId;
		}

		if(parseInt(badgeInstance.CustomData["CurrentValue"]) >= parseInt(badgeInstance.CustomData["Threshold"]))
		{
			// this player just completed this badge
			badgeInstance.CustomData["DateAchieved"] = Today().toDateString();
			changesMade = true;
			WriteAchievementCompleteEvent(achv_completeEvent, badgeInstance.ItemId, context);
		}
	}	
	else
	{
		abort = true;
	}
	
	if(!abort && changesMade)
	{
		UpdateBadgeCustomData(badgeInstance, context);
		return "Badge Updated!";
	}
	else if (abort)
	{
		return "Aborted process due to a mismatch within the CustomData for " + badgeInstance.ItemId;
	}
	else
	{
		return "Evaluation Completed.";
	}
}



/* HELPER FUNCTIONS ---------------------------------------------*/

// Write our custom properties to the player's item instance
function UpdateBadgeCustomData(badgeInstance, context)
{
	
	var updateUserInventoryItemCustomDataRequest = {}
	updateUserInventoryItemCustomDataRequest.PlayFabId = context.playerProfile.PlayerId;
	updateUserInventoryItemCustomDataRequest.ItemInstanceId = badgeInstance.ItemInstanceId;
	updateUserInventoryItemCustomDataRequest.Data = badgeInstance.CustomData;
	
	// local updates complete, now write back to server.
	var result = server.UpdateUserInventoryItemCustomData(updateUserInventoryItemCustomDataRequest);
}

// Send an event to signal a player's recent completion of a badge.
function WriteAchievementCompleteEvent(eventName, badgeId, context)
{
	var writePlayerEventRequest = {};
	writePlayerEventRequest.PlayFabId = context.playerProfile.PlayerId;
	writePlayerEventRequest.EventName = eventName;
	writePlayerEventRequest.Body = {};
	writePlayerEventRequest.Body["BadgeId"] = badgeId;
	var writePlauerEventResult = server.WritePlayerEvent(writePlayerEventRequest);
}

// Fetch a catalog from PlayFab
function GetCatalog(catalogName)
{
	var getCatalogItemsRequest = {};
	getCatalogItemsRequest.CatalogVersion = catalogName;
	var getCatalogItemsResult = server.GetCatalogItems(getCatalogItemsRequest);
	return getCatalogItemsResult.Catalog;
}

// Find a specific badge in a player's inventory
function GetBadgeByIdAndClass(badgeId, badgeClass, context)
{
	var getUserInventoryRequest = {};
	getUserInventoryRequest.PlayFabId = context.playerProfile.PlayerId;

	var getUserInventoryResult = server.GetUserInventory(getUserInventoryRequest);
	return getUserInventoryResult.Inventory.find((element, index, array)=> { return element.ItemClass == badgeClass &&  element.ItemId == badgeId;  }); 
}

// Grant a badge to a player. (achievements catalog optional)
function GrantBadge(badgeInstance, context, achievements)
{
	if(!achievements)
	{
		// need to add the default properties defined in the catalog, by default, there are none.
		achievements = GetCatalog(achv_catalog);
	}
	
	if(!achievements || achievements.length == 0)
	{
		throw "No Achievements Catalog Found... Cannot continue.";
	}

	var badgeCatalogItem = achievements.find((element, index, array)=> { return element.ItemId == badgeInstance.ItemId; });
	
	if(!badgeCatalogItem)
	{
		throw "Badge catalog item could not be found.";
	}

	var grantItemRequest = {}
	grantItemRequest.CatalogVersion = achv_catalog;
	grantItemRequest.PlayFabId = context.playerProfile.PlayerId;
	grantItemRequest.Annotation = "Started on: " + Today().toDateString();
	grantItemRequest.ItemIds = [badgeCatalogItem.ItemId];
	var grantItemResult = server.GrantItemsToUser(grantItemRequest);

	badgeInstance = grantItemResult.ItemGrantResults.length > 0 ? grantItemResult.ItemGrantResults[0] : undefined; // should only ever award one item at a time. This should always be on the 0 index.
	badgeInstance.CustomData = {};

	if(!badgeInstance)
	{
		throw "Badge grant failed.";
	}

	badgeCatalogItem.CustomData = JSON.parse(badgeCatalogItem.CustomData); // by design, this field gets auto-stringified. Need to parse back to an object before we can access.

	// assign the default CustomData values to our object (this keeps us from having to query for an updated instance).
	for(var key in badgeCatalogItem.CustomData)
	{
		badgeInstance.CustomData[key] = badgeCatalogItem.CustomData[key];
	}

	UpdateBadgeCustomData(badgeInstance, context);
	return badgeInstance;
}

// Get a date object for now.
function Today() { return new Date(Date.now()); }


