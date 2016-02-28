## Progressive Reward System
### Description:
Reward players with a reward that increases for consecutive (2, 5, 7 day) log-ins over several days. Cloud-Script logic acts as the authoritative server and performs the grant directly on the player's inventory.   

### Ingredients:
* hey

### Preparation:
  * Use / Create Catalog Items to award: "CheckInChestBronze", "CheckInChestilver", "CheckInChestGold"

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
	* Grant Item from AwardMatrix:
		* AwardMatrix: 
		  * 1 Day = 1 Credit = No reward.
		  * 2 Day = 2 - 4 Credits = "Bronze_CheckInChest"  
		  * 5 Day = 5 - 6 Credits = "Silver_CheckInChest"
 		  * 7 Day = 7 Credits = "Gold_CheckInChest"
  	* Return the details to the client 

### Cloud Script:
In this example we use Cloud Script to 