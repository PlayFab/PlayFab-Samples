## Progressive Reward System
### Description:
Reward players for logging in over consecutive days with progressive item grants.  This example uses a three-tier reward table providing different items for 2, 5, 7 day log-in streaks. Cloud-Script logic acts as the authoritative server and performs the grant directly into the player's inventory.   

### Ingredients (Building Blocks):
  * [Accounts](https://api.playfab.com/docs/tutorials/building-blocks#Accounts)
  * [Title Data](https://api.playfab.com/docs/tutorials/building-blocks#Title_Data)
  * [Player Data](https://api.playfab.com/docs/tutorials/building-blocks#Player_Data)
  * [Player Inventory](https://api.playfab.com/docs/tutorials/building-blocks#Player_Inventory)
  * [Virtual Currency](https://api.playfab.com/docs/tutorials/building-blocks#Virtual_Currency)
  * [Catalog & CatalogItems (Bundle / Container)](https://api.playfab.com/docs/tutorials/building-blocks#Catalog)
  * [Cloud Script](https://api.playfab.com/docs/tutorials/building-blocks#Cloud_Script)

### Preparation:
  1. Under the **Economy &gt; Currencies** section of the Game Manager add a second Virtual Currency to match the following parameters:

  | Property | Value | Detail
  ---: | :---: | --- 
  Code | GM | Abbreviation for our VC
  Name | Gems | Name of our VC
  Initial Deposit | 5 | How many each player gets with a new account
  
  3. Next, under the Catalog tab, add a new catalog called **ProgressiveRewards**.
  2. Navigate back to the top-level catalogs view and click on the small black arrow in the top-right corner of the "ProgressiveRewards Catalog". Choose the Upload JSON option and provide [this catalog file](/Recipes/ProgressiveRewards/PlayFab-JSON/Catalog.json) or use your own.
    * If using your own, ensure that you have items mapping to the three-tier reward table.
  3. Under the **Servers &gt; CloudScript** section of the Game Manager, upload & deploy [this .js file](/Recipes/ProgressiveRewards/CloudScript.js), or ensure that yours has corresponding methods.
  4. Under the **Content &gt; Title Data** section of the Game Manager, add the following TitleData record:
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

### Mechanic Walkthrough:
  1. Client obtains a valid session ticket via one of the various authentication pathways (required to make Client API Calls)
  2. After logging in, the client calls into Cloud Script and executes "CheckIn". 
  3. "CheckIn" performs the following:
    1. Read currentPlayerId's ReadOnlyData: "CheckInTracker"
    	* If this is the first login, create a new record.
    2. Ensure that the player is eligible for an reward:
       * Must have logged in to a streak > 1
       * Must have been > 24 hrs since last grant
       * Must have been < 48 hours after the last grant (otherwise the streak will have been broken)
    3. Increment next grant window
    4. Write back changes to ReadOnlyPlayerData ("CheckInTracker")
    5. Read the "ProgressiveRewardTable" key from TitleData
    6. Look up the reward corresponding to the player's login streak 
    7. Grant item to player
    8. Return the details to the client 
    9. Testing Level 2 & 3 rewards requires:
      * Either waiting the specified login period 
      * or using the Admin API to directly set the Player's data to specific points prior to check-in. 

### Cloud Script:
In this example, after authentication, your players would "check in", a process which, calls the corresponding Cloud Script function. **CheckIn** securely calculates the Player's reward state and makes the needed item grants. The results of any actions performed in Cloud Script are then passed back to inform the client.

----

#### Unity 3d Example Setup Instructions:
Import the following asset packages into a new or existing Unity project:

  * Ensure you have the latest SDK [here](https://github.com/PlayFab/UnitySDK/raw/versioned/Packages/UnitySDK.unitypackage).
  * Ensure you have the recipe files [here](https://github.com/PlayFab/PlayFab-Samples/raw/master/Recipes/ProgressiveRewards/Example-Unity3d/ProgressiveRewardsRecipe.unitypackage).
  
  1. Add assets to your project. 
  2. Open to the ProgressiveRewards scene.
  3. Add your title ID to the ProgressiveRewards.cs via the Unity Inspector.
  4. Run the scene and observe the console for call-by-call status updates.

----

#### JavaScript Example Setup Instructions:
  1. Copy [this folder](/Recipes/SimpleCrossPromotion/Example-JavaScript) to your web server. 
  2. Navigate to index.html  
  3. Enter in your title ID
    * This example automatically generates a GUID on login; however, You may choose any id you like.
    * After logging in whatever id was used will be saved into your browser's localstorage
  4. Observe your browser's developer console for call-by-call status updates.
