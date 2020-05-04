## Daily Prize Wheel
### Description:
A daily prize wheel gives players a 'spin' to receive a prize in exchange for a ticket. Tickets in this example are using PlayFab's regenerating Virtual Currency to ensure that the player is granted 1 ticket each day. The simplest way to achieve our intended 'wheel of prizes' mechanic is to use a bundle or container with a drop table to control the distribution odds of receiving each item.

This technique ensures that players can only 'spin' at most one time per 24 hour period. Additionally, you can easily cap how many 'spin' tickets can be saved through the Virtual Currency settings. In this example we are allowing the player to bank up to 5 spin tickets 

### Ingredients (Building Blocks):
  * [Accounts](https://api.playfab.com/docs/building-blocks#Accounts)
  * [Player Inventory](https://api.playfab.com/docs/building-blocks#Player_Inventory)
  * [Virtual Currency](https://api.playfab.com/docs/building-blocks#Virtual_Currency)
  * [Catalog & Catalog Items (Bundle / Container)](https://api.playfab.com/docs/building-blocks#Catalog)
  * [Drop Table](https://api.playfab.com/docs/building-blocks#Drop_Table)

###Preparation:
  1. Under the **Economy &gt; Currency** tab of Game Manager add a Virtual Currency to match the following parameters:

  | Property | Value | Detail
  ---: | :---: | --- 
  Code | ST | Abbreviation for our VC
  Name | Spin Ticket | Name of our VC
  Initial Deposit | 1 | ensure that the player can spin on their first login
  Recharge Rate | 1 | this sets the VC to regenerate 1 unit per day
  Recharge Max | 5 | this caps the regeneration to the specified number, this is useful for allowing players to bank up to 5 spin tickets at a time

  2. Under the **Catalogs** tab, select **Upload JSON** and upload [this JSON file](/Recipes/PrizeWheel/PlayFab-JSON/Catalog.json) - this will automatically create a catalog called **PrizeWheel** with the following five items:
   
 | DisplayName | Type | Detail
  ---: | :---: | --- 
  Card No. 1 | Item | First prize option
  Card No. 2 | Item | Second prize option
  Card No. 3 | Item | Third prize option
  Prize Wheel No. 1 | Item | This represents the spin that needs to be purchased for 1 Spin Ticket (ST)
  Spin Again! | Bundle | This bundle contains 1 Spin Ticket (ST) to allow another spin

  3. Select **Edit Catalog &gt; Make Primary Catalog &gt; Save**
  4. Navigate within the catalog to the **Drop Tables** tab.
  5. Upload [this JSON file](/Recipes/PrizeWheel/PlayFab-JSON/DropTable.json). The drop table contains all of the items on the 'wheel', giving a 33% chance for each Card item to be chosen, and a 1% chance to spin again.
  6. Navigate within the catalog to the **Items** tab.
  7. Select the **PrizeWheel1** item - this needs to be converted to a bundle containing the drop table.
  8. Under **Convert To...** select **Show Options &gt; Convert to bundle**
  9. Select **Save Item**
  10. Under **Bundle Contents** select **Add to bundle &gt; Drop Tables**
  11. Add the **PrizeWheel1** drop table and save the bundle

  **NOTE:** Instead of simply uploading the catalog JSON with Prize Wheel No. 1 as a bundle, steps 6-11 are necessary due to a bit of a chicken-and-egg problem: the catalog JSON cannot upload successfully, since the drop table doesn't exist; and if we swap the upload order, the drop table JSON will also fail, since the items don't exist.

### Mechanic Walkthrough:
  1. Client obtains a valid session ticket via one of the various authentication pathways (required to make Client API Calls)
  2. After logging-in the client needs a mechanism to trigger a spin
  3. After triggering the spin, the client attempts to purchase a SpinResult in exchange for 1 Spin Ticket
  4. After receiving the client's request, PlayFab will:
    * Deduct a Spin Ticket from the Player's VC balance  
    * Award the bundle / container to the player's inventory 
    * Send a response with the updated information back to the client
  5. Upon receiving the response, the client can display the award to the player.

----

#### Unity 3d Example Setup Instructions:
Import the following asset packages into a new or existing Unity project:

  * Ensure you have the latest SDK [here](https://github.com/PlayFab/UnitySDK/raw/versioned/Packages/UnitySDK.unitypackage).
  * Ensure you have the recipe files [here](https://github.com/PlayFab/PlayFab-Samples/raw/master/Recipes/PrizeWheel/Example-Unity3d/PrizeWheelRecipe.unitypackage)
  
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
