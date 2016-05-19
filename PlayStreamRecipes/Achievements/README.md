## Achievement Badges
### Description:
Track Players' progress based on custom achievement parameters. This example uses the CustomData properties within the ItemInstance to store the achievement details and current status.  

### Ingredients (Building Blocks):
  * [Accounts](https://api.playfab.com/docs/building-blocks#Accounts)
  * [Catalog & CatalogItems (Bundle / Container)](https://api.playfab.com/docs/building-blocks#Catalog)
  * [Virtual Currency](https://api.playfab.com/docs/building-blocks#Virtual_Currency)
  * [Player Inventory](https://api.playfab.com/docs/building-blocks#Player_Inventory)
  * [Cloud Script](https://api.playfab.com/docs/building-blocks#Cloud_Script)
  * [PlayStream](https://api.playfab.com/docs/building-blocks#PlayStream)

### Preparation:
  1. Use the Game Manager to configure a Virtual Currency for your title:

  | Property | Value | Detail
  ---: | :---: | --- 
  Code | Au | Abbreviation for our VC
  Name | Gold | Name of our VC
  Initial Deposit | 1000 | How many each player gets with a new account

  2. Upload [this example catalog](/PlayStreamRecipes/Achievements/PlayFab-JSON/Catalog.json) or use your own.
    * If using your own, ensure that you have items corresponding to those in the example catalog.
    * These catalog items contain CustomData defining the parameters used to evaluate achievement progress.
  3. Upload & deploy [this Cloud Script](/PlayStreamRecipes/Achievements/CloudScript.js), or ensure that yours has corresponding methods.
``` 

### Mechanic Walkthrough:
  1. Client obtains a valid session ticket via one of the various authentication pathways (required to make Client API Calls)
  2. After logging in, the client plays the game which naturally triggers built in PlayStream events. 
  3. Some events are used to trigger the evaluation and tracking logic which keeps player badge progress up-to-date. These Achievements / Events are: 
    * Social Player (triggered by: player_linked_account)
    * Millionaire (triggered by: player_virtual_currency_balance_changed) 
    * VIP (triggered by: player_vc_item_purchased)
    * Bottoms Up (triggers by: player_consumed_item)
    * Brawler (triggered by: player_statistic_changed)
  4. During evaluation, the event data is compared with the ItemInstance CustomData to determine if any updates are required.
    * If an achievement is determined to be completed, a time stamp will be added to mark the point of completion. 
    * If updates are required Cloud Script writes the new values into CustomData.
 
### Cloud Script:
In this example, these methods are called via PlayStream actions. These actions securely update the corresponding Player's achievement badges. Progress updates are then available after the client refreshes their inventory.

### Testing the Achievements:
Due to the nature of achievements, they are often unlocked slowly over the course of a player's lifetime. For the sake of expediency, I have included a way to quickly trigger these achievements. See ps_recipe_testing.txt for details on spoofing these events. 

----

#### Unity 3d Example Setup Instructions:
Import the following asset packages into a new or existing Unity project:
  * Ensure you have the latest SDK [here](https://github.com/PlayFab/UnitySDK/raw/versioned/PlayFabClientSDK.unitypackage).
  * Ensure you have the recipe files [here]().
  
  1. ...TBD