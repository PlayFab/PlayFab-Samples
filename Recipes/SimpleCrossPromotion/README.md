## Simple In-Game Cross Promotion 
### Description:
This example shows off how you can use Player Publisher Data to reward players that play more than one of your games. This mechanic depends on each client "checking-in" after Authentication. The check-in process occurs in Cloud Script's secure environment. Mechanics like this are a useful tool when running a cross-promotional campaign to your existing players. 

### Ingredients:
  * [Accounts](https://api.playfab.com/docs/building-blocks#Accounts)
  * [Title Data](https://api.playfab.com/docs/building-blocks#Title_Data)
  * [Player Data](https://api.playfab.com/docs/building-blocks#Player_Data)
  * [Player Inventory](https://api.playfab.com/docs/building-blocks#Player_Inventory)
  * [Virtual Currency](https://api.playfab.com/docs/building-blocks#Virtual_Currency)
  * [Catalog & CatalogItems (Bundle / Container)](https://api.playfab.com/docs/building-blocks#Catalog)
  * [Cloud Script](https://api.playfab.com/docs/building-blocks#Cloud_Script)

### Preparation:


### Process Walkthrough:
  1. Client obtains a valid session ticket via one of the various Authentication pathways (required to make Client API Calls)
  2. Client checks-in via calling into the Cloud Script method "CheckIn". 
  3. Cloud Script reads the Player Publisher Data and determines if the player is elidigible for a reward.
  4. Award results passed back to client for updating the player.


### Cloud Script:
In this example we are using Cloud Script to act as the secure server ensuring that the CheckIn logic processing and item grants happen on a trusted machine. The results of any actions performed in Cloud Script are then passed back to inform the client.

----

#### Unity 3d Example Setup Instructions:
  1. Download project assets. 
  2. Add assets to your project. 
  3. Open to the CrossPromotional scene.
  4. Add your title ID to the CrossPromotional.cs script via the Unity Inspector.
  5. Run the scene and observe the console for call-by-call status updates.