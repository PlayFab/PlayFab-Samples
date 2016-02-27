// defining these up top so we can easily change these later if we need to.
var CHECK_IN_TRACKER = "CheckInTracker";    // used as a key on the UserPublisherDataReadOnly
var PROGRESSIVE_REWARD_TABLE = "ProgressiveRewardTable";
var PROGRESSIVE_MIN_CREDITS = "MinStreak";
var PROGRESSIVE_REWARD = "Reward";

var TRACKER_NEXT_GRANT = "NextEligibleGrant";
var TRACKER_LOGIN_STREAK = "LoginStreak";


handlers.CheckIn = function(args) {

	var GetUserReadOnlyDataRequest = {
        "PlayFabId": currentPlayerId,
        "Keys": [ CHECK_IN_TRACKER ]
    }; 
    var GetUserReadOnlyDataResponse = server.GetUserReadOnlyData(GetUserReadOnlyDataRequest);
    
    // need to ensure that our data field exists
    var tracker = {}; // this would be the first login ever (across any title), so we have to make sure our record exists.
    if(GetUserReadOnlyDataResponse.Data.hasOwnProperty(CHECK_IN_TRACKER))
    {
    	tracker = JSON.parse(GetUserReadOnlyDataResponse.Data[CHECK_IN_TRACKER].Value);
    }
    else
    {
    	tracker = ResetTracker();
  		
  		// write back updated data to PlayFab
  		UpdateTrackerData(tracker);

  		log.info("This was your first login, Login tomorrow to get a bonus!");
  		return [];
    }
	

	if(Date.now() > parseInt(tracker[TRACKER_NEXT_GRANT]))
	{	
		// Eligible for an item grant.
		//check to ensure that it has been less than 24 hours since the last grant window opened
		var timeWindow = new Date(parseInt(tracker[TRACKER_NEXT_GRANT]));
		timeWindow.setDate(timeWindow.getDate() + 1); // add 1 day 

		if(Date.now() > timeWindow.getTime())
		{
			// streak ended :(			
			tracker = ResetTracker();
			UpdateTrackerData(tracker);

			log.info("Your consecutive login streak has been broken. Login tomorrow to get a bonus!");
			return [];
		}

		// streak continues
		tracker[TRACKER_LOGIN_STREAK] += 1;
		var dateObj = new Date(Date.now());
		dateObj.setDate(dateObj.getDate() + 1); // add one day 
		tracker[TRACKER_NEXT_GRANT] = dateObj.getTime();

		// write back updated data to PlayFab
		log.info("Your consecutive login streak increased to: " + tracker[TRACKER_LOGIN_STREAK]);
		UpdateTrackerData(tracker);

		// Get this title's reward table so we know what items to grant. 
		var GetTitleDataRequest = {
	    	"Keys": [ PROGRESSIVE_REWARD_TABLE ]
	    }; 
	    var GetTitleDataResult = server.GetTitleData(GetTitleDataRequest);
	    
	    // ---
	    if(!GetTitleDataResult.Data.hasOwnProperty(PROGRESSIVE_REWARD_TABLE))
	    {
	    	// throw here or silent error?
	    	log.error("Rewards table could not be found. No rewards will be given. Exiting...");
	        return [];
	    }
	    else
	    {
	    	var rewardTable = JSON.parse(GetTitleDataResult.Data[PROGRESSIVE_REWARD_TABLE]);
	    	
	    	var reward;
	    	for(var level in rewardTable)
	    	{
	    		if( tracker[TRACKER_LOGIN_STREAK] >= rewardTable[level][PROGRESSIVE_MIN_CREDITS])
	    		{
	    			reward = rewardTable[level][PROGRESSIVE_REWARD];
	    		}
	    	}

			var grantedItems = [];
	    	if(reward)
			{
				grantedItems = GrantItems(reward, tracker[TRACKER_LOGIN_STREAK]);
			}
			return grantedItems;
	    }
	}
	return [];
};


function ResetTracker()
{
	var reset = {};

	reset[TRACKER_LOGIN_STREAK] = 1;
	
	var dateObj = new Date(Date.now());
	dateObj.setDate(dateObj.getDate() + 1); // add one day 

	reset[TRACKER_NEXT_GRANT] = dateObj.getTime();
	return reset;
}


function UpdateTrackerData(data)
{
    var UpdateUserReadOnlyDataRequest = {
        "PlayFabId": currentPlayerId,
        "Data": {}
    };
    UpdateUserReadOnlyDataRequest.Data[CHECK_IN_TRACKER] = JSON.stringify(data);

    server.UpdateUserReadOnlyData(UpdateUserReadOnlyDataRequest);
}


function GrantItems(items, count)
{
	log.info("Granting: " + items);
    var parsed = Array.isArray(items) ? items : [ items ];

    var GrantItemsToUserRequest = {
        "PlayFabId" : currentPlayerId,
        "ItemIds" : parsed,
        "Annotation" : "Granted for logging in over " + count + " consecutive days."
    };

    var GrantItemsToUserResult = server.GrantItemsToUser(GrantItemsToUserRequest);
    return GrantItemsToUserResult.ItemGrantResults;
}