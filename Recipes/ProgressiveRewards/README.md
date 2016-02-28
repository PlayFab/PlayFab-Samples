## Progressive Reward System
### Description:
Reward players for logging in over consecutive days with progressive item grants.  for consecutive (2, 5, 7 day) log-ins over several days. Cloud-Script logic acts as the authoritative server and performs the grant directly on the player's inventory.   

### Ingredients:
  * [Accounts](https://api.playfab.com/docs/building-blocks#Accounts)
  * [Player Data](https://api.playfab.com/docs/building-blocks/Player_Data)
  * [Player Inventory](https://api.playfab.com/docs/building-blocks/Player_Inventory)
  * [Catalog & CatalogItems (Bundle / Container)](https://api.playfab.com/docs/building-blocks/Catalog)
  * [Cloud Script](https://api.playfab.com/docs/building-blocks/Cloud_Script)

### Preparation:
  * Use the Game Manager to configure a Virtual Currency:
  
  | Property | Value | Detail
  Code | ST | Abbreviation for our VC
  Name | SpinTicket | Name of our VC
  Initial Deposit | 1 | Ensure that the player can spin at least once on day one.
  Recharge Rate | 1 | this sets the VC to regenerate 1 unit per day
  Recharge Max | 5 | this caps the regeneration to the specified number, this is useful for allowing players to 

  * Upload [this example catalog](/Recipes/ProgressiveRewards/PlayFab-JSON/RegeneratingCurrency.json) or use your own. 
    * If using your own ensure that you have items mapping to the three-tier reward table.
  * Upload & deploy [this Cloud Script](/Recipes/ProgressiveRewards/CloudScript.js), or ensure that yours has a corresponding method.
  * Add the following TitleData record:
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


### Assembly:
  * Client obtains a valid session ticket via one of the various Authentication pathways (required to make Client API Calls)
  * After logging in, the client calls into Cloud Script and executes "CheckIn". 
  * "CheckIn" does the following:
    * Read currentPlayerId's InternalData key "CheckIn"
    	* - IF: Undefined, create a new {}
    	* - ELSE IF: Now - CheckIn.LastLoginTime > 24 hrs
    	  * Update CheckIn.LastLoginTime to Now
    	  * Increment CheckIn.Credits by 1
    	* - ELSE:   Reset CheckIn.Credits to 1
    	* Write back changes to "CheckIn"
	* Grant Item from **AwardMatrix**:
		
    | Level | Streak | Item Grant   
    --- | --- | ---
    0 | 1 | *n/a*
    1 | 2 - 4 | Bronze_CheckInChest
    2 | 5 - 6 | Silver_CheckInChest
    3 | 7+    | Gold_CheckInChest     
  	* Return the details to the client 

### Cloud Script:
In this example, after authentication, your players would "check in", a process which, calls the corresponding Cloud Script function. **CheckIn** securely calculates the Player's reward state and makes the needed item grants. The results of any actions performed in Cloud Script are then passed back to inform the client.