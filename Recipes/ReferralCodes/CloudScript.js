// defining these up top so we can easily change these later if we need to.
var VIRTUAL_CURRENCY_CODE = "GM";                           // currency code for our Gems VC
var PLAYER_REFERRAL_KEY = "Referrals";                      // PlayerDataReadOnly key to retrieve referral information 
var MAXIMUM_REFERRALS = 10;                                 // this could also be set in TitleData
var REFERRAL_BONUS_BUNDLE = "premiumStarterPack";           // the item to grant to the requester
var REFERRAL_BADGE = "referralBadge";                       // the itemId for the item that signifies that a player has been referred

// args.referralCode expected from Client
handlers.RedeemReferral = function(args) {

    try{
        if(args == null || typeof args.referralCode === undefined || args.referralCode === "")
        {
            throw "Failed to redeem. args.referralCode is undefined or blank.";
        }
        else if(args.referralCode === currentPlayerId)
        {
            throw "You are not allowed to refer yourself.";
        }

        //Check the player's inventory to ensure that a "ReferralBadge" does not exist
        var GetUserInventoryRequest = {
            "PlayFabId": currentPlayerId
        };

        var GetUserInventoryResult = server.GetUserInventory(GetUserInventoryRequest);
        for(var index in GetUserInventoryResult.Inventory)
        {
            if(GetUserInventoryResult.Inventory[index].ItemId === REFERRAL_BADGE)
            {
                throw "You are only allowed one Referral Badge.";
            }
        }

        //Before proceeding, validate the provided referral code. Use a Try / Catch block if you want to do more before returning the error to the client.
        var GetUserReadOnlyDataRequest = {
            "PlayFabId": args.referralCode,
            "Keys": [ PLAYER_REFERRAL_KEY ]
        }; 
        var GetUserReadOnlyDataResult = server.GetUserReadOnlyData(GetUserReadOnlyDataRequest);
        var referralValues = [];

        if(!GetUserReadOnlyDataResult.Data.hasOwnProperty(PLAYER_REFERRAL_KEY))
        {
            // This was a valid referral code, but this is the first redeemed code.
            referralValues.push(currentPlayerId);
            ProcessReferrer(args.referralCode, referralValues);
        }
        else
        {
            // This was a valid referral code, now we need to extract the JSON array
            referralValues = JSON.parse(GetUserReadOnlyDataResult.Data[PLAYER_REFERRAL_KEY].Value);
            if(Array.isArray(referralValues))
            {
                // need to ensure we have not exceeded the MAXIMUM_REFERRALS
                if(referralValues.length < MAXIMUM_REFERRALS)
                {
                    // here we know that the referrer has not exceeded the max, so we will add the current player 
                    referralValues.push(currentPlayerId);
                    ProcessReferrer(args.referralCode, referralValues);
                }
                else
                {
                    // Referrer has exceeded the MAXIMUM_REFERRALS
                    // this is not an error, but the referrer does not get their reward.
                    log.info("Player:" + args.referralCode + " has hit the maximum number of referrals (" + MAXIMUM_REFERRALS + ")." );
                }
            }
            else
            {
                throw "An error occurred when parsing the referrer's player data.";
            }
        }
        // finally, reward the calling player
        return GrantReferralBonus(args.referralCode);
    } catch(e) {
        var retObj = {};
        retObj["errorDetails"] = "Error: " + e;
        return retObj;
    }
};

function ProcessReferrer(id, referrals)
{
    // write back data to the referrer
    var UpdateUserReadOnlyDataRequest = {
        "PlayFabId": id,
        "Data": {}
    };
    UpdateUserReadOnlyDataRequest.Data[PLAYER_REFERRAL_KEY] = JSON.stringify(referrals);
    var UpdateUserReadOnlyDataResult = server.UpdateUserReadOnlyData(UpdateUserReadOnlyDataRequest);

    // grant the reward to the referrer
    var AddUserVirtualCurrencyRequest = {
        "PlayFabId" : id,
        "VirtualCurrency": VIRTUAL_CURRENCY_CODE,
        "Amount": 10
    };
    var AddUserVirtualCurrencyResult = server.AddUserVirtualCurrency(AddUserVirtualCurrencyRequest);

    log.info(AddUserVirtualCurrencyRequest.Amount + " " + VIRTUAL_CURRENCY_CODE + " granted to " + id);
}

function GrantReferralBonus(code)
{
    var GrantItemsToUserRequest = {
        "PlayFabId" : currentPlayerId,
        "ItemIds" : [ REFERRAL_BADGE, REFERRAL_BONUS_BUNDLE ],
        "Annotation" : "Referred by: " + code
    };

    var GrantItemsToUserResult = server.GrantItemsToUser(GrantItemsToUserRequest);
    return GrantItemsToUserResult.ItemGrantResults;
}
