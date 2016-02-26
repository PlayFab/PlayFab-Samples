// defining these up top so we can easily change these later if we need to.
var CHANCE_TO_DIE = 0.3333;
var GEM_MAX = 20;
var GEM_MIN = 10;                                 // this could also be set in TitleData
var LIVES_CURRENCY_CODE = "LV";
var GEMS_CURRENCY_CODE = "GM";

handlers.Battle = function(args) {
	var GetUserInventoryRequest = {
        "PlayFabId": currentPlayerId
    };

    var GetUserInventoryResult = server.GetUserInventory(GetUserInventoryRequest);
	var userInventory = GetUserInventoryResult.Inventory;
	var userVcBalances = GetUserInventoryResult.VirtualCurrency;
	var userVcRecharge = GetUserInventoryResult.VirtualCurrencyRechargeTimes;

	if(!CheckLives(userVcBalances))
	{
		throw "No lives remaining. Purchase additional lives or wait: " + userVcRecharge[LIVES_CURRENCY_CODE].SecondsToRecharge + " seconds.";
	}

	// calculate the battle...
	var gemsFound = Math.floor(Math.random() * (GEM_MAX - GEM_MIN + 1) + GEM_MIN);
	AddVc(userVcBalances, GEMS_CURRENCY_CODE, gemsFound);
	log.info("You found " + gemsFound + " gems.");

	var rollOfFate =  Math.floor(Math.random() * (10 - 1 + 1) + 1);
	var lostALife = rollOfFate <= Math.floor(10 * CHANCE_TO_DIE) ? true : false; 

	if(lostALife)
	{
		SubtractVc(userVcBalances, LIVES_CURRENCY_CODE, 1);
		log.info("You lost a life.");
	}

	var battleResults = {};
		battleResults.gemsFound = gemsFound;
		battleResults.lostALife = lostALife;

	return battleResults;
};


function CheckLives(vcBalnces)
{
	if(vcBalnces != null && vcBalnces.hasOwnProperty(LIVES_CURRENCY_CODE) && vcBalnces[LIVES_CURRENCY_CODE] > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

function AddVc(vcBalnces, code, qty)
{ 
	if(vcBalnces != null && vcBalnces.hasOwnProperty(code) &&  vcBalnces[code] > 0)
	{
		vcBalnces[code] += qty;
	}

	var AddUserVirtualCurrencyRequest = {
	    "PlayFabId" : currentPlayerId,
	    "VirtualCurrency": code,
	    "Amount": qty
    };
    var AddUserVirtualCurrencyResult = server.AddUserVirtualCurrency(AddUserVirtualCurrencyRequest);
}

function SubtractVc(vcBalnces, code, qty)
{
	if(vcBalnces != null && vcBalnces.hasOwnProperty(code) &&  vcBalnces[code] > 0)
	{
		vcBalnces[code] -= qty;
	}

	var SubtractUserVirtualCurrencyRequest = {
	    "PlayFabId" : currentPlayerId,
	    "VirtualCurrency": code,
	    "Amount": qty
    };

    var SubtractUserVirtualCurrencyResult = server.SubtractUserVirtualCurrency(SubtractUserVirtualCurrencyRequest);
}