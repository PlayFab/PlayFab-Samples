// defining these up top so we can easily change these later if we need to.
var CURRENT_TITLE_CODE = "";                                 // the TitleId of the current title
var CROSS_PROMOTIONAL_TRACKING = "CrossPromotionalTracking";    // used as a key on the UserPublisherDataReadOnly
var CROSS_PROMOTIONAL_REWARDS = "CrossPromotionalRewards";       // used as a key on TitleData -- contains the item grant table linking the valid titles to items
var CROSS_PROMOTIONAL_CATALOG = "CrossPromotional";

handlers.CheckIn = function(args) {
	var GetUserPublisherReadOnlyDataRequest = {
        "PlayFabId": currentPlayerId,
        "Keys": [ CROSS_PROMOTIONAL_TRACKING ]
    }; 
    var GetUserPublisherReadOnlyDataResult = server.GetUserPublisherReadOnlyData(GetUserPublisherReadOnlyDataRequest);
    
    // need to ensure that our data field exists
    var trackedTitles = {}; // this would be the first login ever (across any title), so we have to make sure our record exists.
    if(GetUserPublisherReadOnlyDataResult.Data.hasOwnProperty(CROSS_PROMOTIONAL_TRACKING))
    {
    	trackedTitles = JSON.parse(GetUserPublisherReadOnlyDataResult.Data[CROSS_PROMOTIONAL_TRACKING].Value);
    }

    // check to see if we have logged into this title with this account before
    if(!trackedTitles.hasOwnProperty(CURRENT_TITLE_CODE))
    {
        // this was the first time we have checked into this title, so we need to add a record for this title
        trackedTitles[CURRENT_TITLE_CODE] = { "Redeemed":[] };
        log.info("First time logging into " + CURRENT_TITLE_CODE + ". PublisherData record created.");
    }


    // get this title's reward table so we know what items to grant. 
	var GetTitleDataRequest = {
    	"Keys": [ CROSS_PROMOTIONAL_REWARDS ]
    }; 
    var GetTitleDataResult = server.GetTitleData(GetTitleDataRequest);
    

    if(!GetTitleDataResult.Data.hasOwnProperty(CROSS_PROMOTIONAL_REWARDS))
    {
    	// throw here or silent error?
    	log.error("Rewards table could not be found. No rewards will be given. Exiting...");
    	
        // write back updated data to PlayFab
        UpdatePromoTracking(trackedTitles);
        return;
    }
    else
    {
    	var rewardTable = JSON.parse(GetTitleDataResult.Data[CROSS_PROMOTIONAL_REWARDS]);
    	var grantedItems = [];

    	// loop through each title logged to the tracker and make the neccessacery item grants given this title's settings
    	for(var title in trackedTitles)
    	{
    		if(title === CURRENT_TITLE_CODE)
    		{
    			continue; // we dont reward for logging into this title; however, we should still track it so other titles can grant.
    		}	
    		else if(trackedTitles[CURRENT_TITLE_CODE].Redeemed.indexOf(title) === -1)
    		{
    			// found a record that has not been awarded. Check to see if we have a corresponding reward
    			if(rewardTable.hasOwnProperty(title))
    			{
    				var items = GrantItems(rewardTable[title], title);

                    if(items.length > 0) // should only update the tracker if we actually grant something.
                    {
                        trackedTitles[CURRENT_TITLE_CODE].Redeemed.push(title);
                        grantedItems = grantedItems.concat(items);
                    }
    			}
    			else
    			{
    				log.info("Title login found, but no corresponding reward for title "+ title +" was defined.");
    			}
    		}
    	}

	    // write back updated data to PlayFab
        UpdatePromoTracking(trackedTitles);

    	return JSON.stringify(grantedItems);
    }
};



function UpdatePromoTracking(data)
{
    var UpdateUserPublisherReadOnlyDataRequest = {
        "PlayFabId": currentPlayerId,
        "Data": {}
    };
    UpdateUserPublisherReadOnlyDataRequest.Data[CROSS_PROMOTIONAL_TRACKING] = JSON.stringify(data);

    server.UpdateUserPublisherReadOnlyData(UpdateUserPublisherReadOnlyDataRequest);
}



function GrantItems(items, titleId)
{
	log.info("Granting: " + items);
    var parsed = Array.isArray(items) ? items : [ items ];

    var GrantItemsToUserRequest = {
        "CatalogVersion" : CROSS_PROMOTIONAL_CATALOG, 
        "PlayFabId" : currentPlayerId,
        "ItemIds" : parsed,
        "Annotation" : "Granted for logging into: " + titleId
    };

    var GrantItemsToUserResult = server.GrantItemsToUser(GrantItemsToUserRequest);
    return GrantItemsToUserResult.ItemGrantResults;
}
