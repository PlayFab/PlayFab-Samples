## Progressive Reward System
### Description:
Reward players for logging in over consecutive days with progressive item grants.  This example uses a three-tier reward table providing different items for 2, 5, 7 day log-in streaks. Cloud-Script logic acts as the authoritative server and performs the grant directly into the player's inventory.   

### Ingredients:
  * [Accounts](https://api.playfab.com/docs/building-blocks#Accounts)
  * [Player Data](https://api.playfab.com/docs/building-blocks#Player_Data)
  * [Player Inventory](https://api.playfab.com/docs/building-blocks#Player_Inventory)
  * [Virtual Currency](https://api.playfab.com/docs/building-blocks#Virtual_Currency)
  * [Catalog & CatalogItems (Bundle / Container)](https://api.playfab.com/docs/building-blocks#Catalog)
  * [Cloud Script](https://api.playfab.com/docs/building-blocks#Cloud_Script)

### Preparation:
  1. Use the Game Manager to configure a Virtual Currency for your title:

  | Property | Value | Detail
  ---: | :---: | --- 
  Code | ST | Abbreviation for our VC
  Name | SpinTicket | Name of our VC
  Initial Deposit | 1 | Ensure that the player can spin at least once on day one.
  Recharge Rate | 1 | this sets the VC to regenerate 1 unit per day
  Recharge Max | 5 | this caps the regeneration to the specified number, this is useful for allowing players to 

  2. Upload [this example catalog](/Recipes/ProgressiveRewards/PlayFab-JSON/RegeneratingCurrency.json) or use your own. 
    * If using your own, ensure that you have items mapping to the three-tier reward table.
  3. Upload & deploy [this Cloud Script](/Recipes/ProgressiveRewards/CloudScript.js), or ensure that yours has a corresponding method.
  4. Add the following TitleData record:
    * **Key** : ProgressiveRewardTable
    * **Value**: 
    ```javascript
{   
  "Level1" : { 
      "MinStreak" : 2, 
      "Reward" : "Bronze_CheckInChest" },
  "Level2" : { 
      "MinStreak" : 5, 
      "Reward" : "Silver_CheckInChest" },
  "Level3" : { 
      "MinStreak" : 7, 
      "Reward" : "Gold_CheckInChest" } 
}
``` 


### Process Walkthrough:
  1. Client obtains a valid session ticket via one of the various Authentication pathways (required to make Client API Calls)
  2. After logging in, the client calls into Cloud Script and executes "CheckIn". 
  3. "CheckIn" performs the following:
    1. Read currentPlayerId's ReadOnlyData: "CheckInTracker"
    	* If this is the first login, create a new record.
    2. Ensure that the player is eligible for an reward:
       * Must have logged in to a streak > 1
       * Must have been > 24 hrs since last grant
       * Must not have been more than 48 hours after the last grant (otherwise the streak will have been broken)
    3. Increment next grant window
    4. Write back changes to ReadOnlyPlayerData ("CheckInTracker")
    5. Read the "ProgressiveRewardTable" key from TitleData
    6. Look up the reward corresponding to the player's login streak 
    7. Grant item to player
    8. Return the details to the client 

### Cloud Script:
In this example, after authentication, your players would "check in", a process which, calls the corresponding Cloud Script function. **CheckIn** securely calculates the Player's reward state and makes the needed item grants. The results of any actions performed in Cloud Script are then passed back to inform the client.