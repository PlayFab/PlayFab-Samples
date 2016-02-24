// defining these up top so we can easily change these later if we need to.
var VIRTUAL_CURRENCY_CODE = "GM";
var PLAYER_REFERRAL_KEY = "Referals";
var MAXIMUM_REFERRALS = 10;                                 // this could also be set in TitleData
var REFERRAL_BONUS_BUNDLE = "premiumStarterPack";
var REFERRAL_BADGE = "referralBadge";

// args.referralCode expected from Client
handlers.RedeemReferral = function(args) {

    if(args == null || typeof args.referralCode === undefined || args.referralCode === "")
    {
        throw "Failed to redeem. args.referralCode is undefined or blank";
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

    //Before proceeding, validate the provided referal code. Use a Try / Catch block if you want to do more before returning the error to the client.
    var GetUserInternalDataRequest = {
        "PlayFabId": args.referralCode,
        "Keys": [ PLAYER_REFERRAL_KEY ]
    } 
    var GetUserInternalDataResult = server.GetUserInternalData(GetUserInternalDataRequest)
    var referralValues = [];

    if(!GetUserInternalDataResult.Data.hasOwnProperty(PLAYER_REFERRAL_KEY))
    {
        // This was a valid referral code, but this is the first redeemed code.
        referralValues.push(currentPlayerId);
        ProcessReferrer(args.referralCode, referralValues);
    }
    else
    {
        // This was a valid referral code, now we need to extract the JSON array
        referralValues = JSON.parse(GetUserInternalDataResult.Data[PLAYER_REFERRAL_KEY].Value);
        if(Array.isArray(referralValues))
        {
            // need to ensure we have not exceded the MAXIMUM_REFERRALS
            if(referralValues.length < MAXIMUM_REFERRALS)
            {
                // here we know that the referrer has not exceeded the max, so we will add the current player 
                referralValues.push(currentPlayerId);
                ProcessReferrer(args.referralCode, referralValues);
            }
            else
            {
                // Referrer has exceeded the MAXIMUM_REFERRALS
                // this is not an error, but the referrer does not get thier reward.
                log.info("Player:" + args.referralCode + " has hit the maximum number of referrals (" + MAXIMUM_REFERRALS + ")." );
            }
        }
        else
        {
            throw "An error occured when parsing the referrer's player data.";
        }
    }

    // finally, reward the calling player
    return GrantReferalBonus(args.referralCode);
};



function ProcessReferrer(id, referals)
{
    // write back data to the referrer
    var UpdateUserInternalDataRequest = {
        "PlayFabId": id,
        "Data": {}
    };
    UpdateUserInternalDataRequest.Data[PLAYER_REFERRAL_KEY] = JSON.stringify(referals);
    var UpdateUserInternalDataResult = server.UpdateUserInternalData(UpdateUserInternalDataRequest);

    // grant the reward to the referrer
    var AddUserVirtualCurrencyRequest = {
        "PlayFabId" : id,
        "VirtualCurrency": VIRTUAL_CURRENCY_CODE,
        "Amount": 10
    };
    var AddUserVirtualCurrencyResult = server.AddUserVirtualCurrency(AddUserVirtualCurrencyRequest);

    log.info(AddUserVirtualCurrencyRequest.Amount + " " + VIRTUAL_CURRENCY_CODE + " granted to " + id);
}


function GrantReferalBonus(code)
{
    var GrantItemsToUserRequest = {
        "PlayFabId" : currentPlayerId,
        "ItemIds" : [ REFERRAL_BADGE, REFERRAL_BONUS_BUNDLE ],
        "Annotation" : "Referred by: " + code
    };

    var GrantItemsToUserResult = server.GrantItemsToUser(GrantItemsToUserRequest);
    return GrantItemsToUserResult.ItemGrantResults;
}




