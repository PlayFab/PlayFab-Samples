## Simple In-Game Cross Promotion 
### Description:
This example shows off how you can use Player Publisher Data to reward players that play more than one of your games. This mechanic depends on each client "checking-in" after Authentication. The check-in process occurs in Cloud Script's secure environment. Mechanics like this are a useful tool when running a cross-promotional campaign to your existing players. 

### Ingredients (Building Blocks):
  * [Accounts](https://api.playfab.com/docs/building-blocks#Accounts)
  * [Title Data](https://api.playfab.com/docs/building-blocks#Title_Data)
  * [Player Data](https://api.playfab.com/docs/building-blocks#Player_Data)
  * [Player Inventory](https://api.playfab.com/docs/building-blocks#Player_Inventory)
  * [Virtual Currency](https://api.playfab.com/docs/building-blocks#Virtual_Currency)
  * [Catalog & CatalogItems (Bundle / Container)](https://api.playfab.com/docs/building-blocks#Catalog)
  * [Cloud Script](https://api.playfab.com/docs/building-blocks#Cloud_Script)

### Preparation:
  1. Use the Game Manager to configure a second Virtual Currency for your title:

  | Property | Value | Detail
  ---: | :---: | --- 
  Code | GM | Abbreviation for our VC
  Name | Gems | Name of our VC
  Initial Deposit | 5 | How many each player gets with a new account

  2. Upload [this example catalog](/Recipes/SimpleCrossPromotion/PlayFab-JSON/Catalog.json) or use your own.
	  * If using your own, ensure that you have items that can be granted to players.
  3. Upload & deploy [this Cloud Script](/Recipes/SimpleCrossPromotion/CloudScript.js), or ensure that yours has corresponding methods.  
  4. Add the following TitleData record:
	  * **Key** : CrossPromotionalRewards
	  * **Value**:

```JavaScript
{ 
  	"E5A" : "chromePaint",  
	"632D" : "biggerHat" 
}
``` 
  5. To properly test this you will need to have multiple titles with the similar Cloud Scripts & TitleData. This pattern allows you to have different rewards for each individual catalog. Ensure that your 2nd and third titles match the values in your TitleData:CrossPromotionalRewards (See step #4).

### Mechanic Walkthrough:
  1. Client obtains a valid session ticket via one of the various authentication pathways (required to make Client API Calls)
  2. Client checks-in via calling into the Cloud Script method "CheckIn". 
  3. Cloud Script reads the Player Publisher Data and determines if the player is eligible for a reward.
  4. Award results passed back to client for updating the player.


### Cloud Script:
In this example we are using Cloud Script to act as the secure server ensuring that the CheckIn logic processing and item grants happen on a trusted machine. The results of any actions performed in Cloud Script are then passed back to inform the client.

----

#### Unity 3d Example Setup Instructions:
Import the following asset packages into a new or existing Unity project:
  * Ensure you have the latest SDK [here](https://github.com/PlayFab/UnitySDK/raw/versioned/PlayFabClientSDK.unitypackage).
  * Ensure you have the recipe files [here](https://github.com/PlayFab/PlayFab-Samples/raw/master/Recipes/SimpleCrossPromotion/Example-Unity3d/SimpleCrossPromotionRecipe.unitypackage).
  
  1. Add assets to your project. 
  2. Open to the CrossPromotional scene.
  3. Add your title ID to the CrossPromotional.cs script via the Unity Inspector.
  4. Run the scene and observe the console for call-by-call status updates.

----

#### JavaScript Example Setup Instructions:
  1. Copy [this folder](/Recipes/SimpleCrossPromotion/Example-JavaScript) to your web server. 
  2. Navigate to index.html  
  3. Enter in your title ID
    * This example automatically generates a GUID on login; however, You may choose any id you like.
    * After logging in whatever id was used will be saved into your browser's localstorage
  4. Observe your browser's developer console for call-by-call status updates.

