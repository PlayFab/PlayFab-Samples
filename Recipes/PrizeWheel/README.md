## Daily Prize Wheel
### Description:
A daily prize wheel gives players a 'spin' to recieve a prize in exchange for a ticket. Tickets in this example are using PlayFab's regenerating Virtual Currency to ensure that the player is granted 1 ticket each day. The simplest way to achieve our intened "wheel of prizes' mechanic is to use a bundle or container with a drop table to control the distribution odds to recieving each item. 

This technique ensures that players can only 'spin' at most one time per 24 hour period. Additionally, you can easily cap how many 'spin' tickets can be saved through the Virtual Currency settings. In this example we are allowing the player to bank up to 5 spin tickets 

### Ingredients (Building Blocks):
  * [Accounts](https://api.playfab.com/docs/building-blocks#Accounts)
  * [Player Inventory](https://api.playfab.com/docs/building-blocks#Player_Inventory)
  * [Virtual Currency](https://api.playfab.com/docs/building-blocks#Virtual_Currency)
  * [Catalog & CatalogItems (Bundle / Container)](https://api.playfab.com/docs/building-blocks#Catalog)
  * [Drop Table](https://api.playfab.com/docs/building-blocks#Drop_Table)

###Preparation:
  1. Use the Game Manager to configure a Virtual Currency for your title:

  | Property | Value | Detail
  ---: | :---: | --- 
  Code | ST | Abbreviation for our VC
  Name | Spin Ticket | Name of our VC
  Initial Deposit | 1 | ensure that the player can spin on their first login
  Recharge Rate | 1 | this sets the VC to regenerate 1 unit per day
  Recharge Max | 5 | this caps the regeneration to the specified number, this is useful for allowing players to bank up to 5 spin tickets at a time

  2. Upload [this example catalog](/Recipes/PrizeWheel/PlayFab-JSON/Catalog.json) or use your own. 
    * If using your own, ensure that you have items that can be granted to a player. from the wheel.

  3. Upload [this drop table](/Recipes/PrizeWheel/PlayFab-JSON/DropTable.json) using the Game Manager. The droptable should contain all of the items on the 'wheel'.

### Mechanic Walkthrough:
  1. Client obtains a valid session ticket via one of the various authentication pathways (required to make Client API Calls)
  2. After logging-in the client needs a mechanism to trigger a spin
  3. After triggering the spin, the client attempts to purchase a SpinResult in exchange for 1 Spin Ticket
  4. After recieving the client's request, PlayFab will:
    * Deduct a Spin Ticket from the Player's VC balance  
    * Award the bundle / container to the player's inventory 
    * Send a response with the updated information back to the client
  5. Upon recieving the response, the client can display the award to the player.

----

#### Unity 3d Example Setup Instructions:
Import the following asset packages into a new or existing Unity project:
  * Ensure you have the latest SDK [here](https://github.com/PlayFab/UnitySDK/raw/versioned/PlayFabClientSDK.unitypackage).
  * Ensure you have the recipe files [here](https://github.com/PlayFab/PlayFab-Samples/raw/master/Recipes/PrizeWheel/Unity3d-Example/PrizeWheelRecipe.unitypackage)
  
  1. Add assets to your project. 
  2. Open the PrizeWheel scene.
  3. Add your title ID to the PrizeWheel.cs script via the Unity Inspector.
  4. Run the scene and observe the console for call-by-call status updates.

----

#### JavaScript Example Setup Instructions:
  1. Copy [this folder](/Recipes/SimpleCrossPromotion/Example-JavaScript) to your web server. 
  2. Navigate to index.html  
  3. Enter in your title ID
    * This example automatically generates a GUID on login; however, You may choose any id you like.
    * After logging in whatever id was used will be saved into your browser's localstorage
  4. Observe your browser's developer console for call-by-call status updates.