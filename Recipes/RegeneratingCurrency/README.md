## Regenerating Currency
### Description:
A play-limiting mechanic (similar to lives / hearts from Candy Crush) that slowly refills to a maximum over time. This also is often accompanied with a way to purchase additional lives for VC or IAP. PlayFab offers services to enable both.

In this example we are mimicking gameplay through a Cloud Script method called "Battle". While battling the player can receive Gems at the cost of sometimes losing a life. Logic in Cloud Script prevents players from battling if they do not have any lives. Extra lives regenerate every five minutes and are also available to purchase in exchange for Gems.

### Ingredients (Building Blocks):
  * [Accounts](https://api.playfab.com/docs/building-blocks#Accounts)
  * [Player Data](https://api.playfab.com/docs/building-blocks#Player_Data)
  * [Player Inventory](https://api.playfab.com/docs/building-blocks#Player_Inventory)
  * [Virtual Currency](https://api.playfab.com/docs/building-blocks#Virtual_Currency)
  * [Catalog & CatalogItems (Bundle / Container)](https://api.playfab.com/docs/building-blocks#Catalog)
  * [Cloud Script](https://api.playfab.com/docs/building-blocks#Cloud_Script)

### Preparation:
  1. Under the **Economy &gt; Currencies** section of the Game Manager add a Virtual Currency to match the following parameters:

  | Property | Value | Detail
  ---: | :---: | --- 
  Code | LV | Abbreviation for our VC
  Name | Lives | Name of our VC
  Initial Deposit | 1 | ensure that the player can spin on their first login
  Recharge Rate | 288 |  Every 5 minutes: 24hr*60min / 5min
  Recharge Max | 5 | this caps the regeneration to the specified number

  2. Under the **Economy &gt; Currencies** section of the Game Manager add a second Virtual Currency to match the following parameters:

  | Property | Value | Detail
  ---: | :---: | --- 
  Code | GM | Abbreviation for our VC
  Name | Gems | Name of our VC
  Initial Deposit | 5 | How many each player gets with a new account
  
  3. Next, under the Catalog tab, add a new catalog called **RegeneratingCurrency**.
  4. Navigate back to the top-level catalogs view and click on the small black arrow in the top-right corner of the "RegeneratingCurrency Catalog". Choose the Upload JSON option and provide [this catalog file](/Recipes/RegeneratingCurrency/PlayFab-JSON/Catalog.json) or use your own.
    * If using your own, ensure that you have items that can be granted to a player.
  5. Under the **Servers &gt; CloudScript** section of the Game Manager, upload & deploy [this .js file](/Recipes/RegeneratingCurrency/CloudScript.js), or ensure that yours has corresponding methods.  

### Mechanic Walkthrough:
  1. Client obtains a valid session ticket via one of the various authentication pathways (required to make Client API Calls)
  2. Client battles via calling into the Cloud Script method "Battle". 
  3. Cloud Script calculates Battle results and makes any Gem Additions, Life Losses and data updates to reflect results.
  4. Results passed back to client for updating the player.
  5. If a player loses all their lives, they must wait or purchase more in exchange for gems.


### Cloud Script:
In this example we are using Cloud Script to act as the secure server ensuring that the battle logic processing and item grants happen on a trusted machine. The results of any actions performed in Cloud Script are then passed back to inform the client.

----

#### Unity 3d Example Setup Instructions:
Import the following asset packages into a new or existing Unity project:

  * Ensure you have the latest SDK [here](https://github.com/PlayFab/UnitySDK/raw/versioned/Packages/UnitySDK.unitypackage).
  * Ensure you have the recipe files [here](https://github.com/PlayFab/PlayFab-Samples/raw/master/Recipes/RegeneratingCurrency/Example-Unity3d/RegeneratingCurrencyRecipe.unitypackage).
  
  1. Add assets to your project. 
  2. Open to the RegeneratingCurrency scene.
  3. Add your title ID to the RegeneratingCurrency.cs script via the Unity Inspector.
  4. Run the scene and observe the console for call-by-call status updates.

----

#### JavaScript Example Setup Instructions:
  1. Copy [this folder](/Recipes/SimpleCrossPromotion/Example-JavaScript) to your web server. 
  2. Navigate to index.html  
  3. Enter in your title ID
    * This example automatically generates a GUID on login; however, You may choose any id you like.
    * After logging in whatever id was used will be saved into your browser's localstorage
  4. Observe your browser's developer console for call-by-call status updates.
