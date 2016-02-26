-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
Daily Prize Wheel
-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

Description:
A daily prize wheel gives players a 'spin' to recieve a prize in exchange for a ticket that gets regenerates daily. The simplest way to achieve this mechanic is to use a bundle or container with a drop table that acts as the 'RNG spin' in combination with a regenerating Virtual Currency that act as the ticket-to-spin. 

This technique ensures that players can only 'spin' at most one time per 24 hour period. Additionally, you can easily cap how many 'spin' tokens can be saved through the Virtual Currency settings.  

Ingredients:
	* Accounts
	* Virtual Currency
	* Player Inventory
	* Catalog & CatalogItems (Bundle / Container)
	* Drop Table

Preparation:
	* Must have a catalog with some items that can be granted to a player.
	* Use the Game Manager to create a DropTable called "DailySpin" containing all of the items on the 'wheel'.
	* Adjust the weight for each item; establishing the odds-to-recieve 
	* Create a new item called "SpinResult". Convert the item to a container or bundle. Add the "DailySpin" droptable to your item.
	  * Use a catalog if you want your players to manually open the container
	  * Use a bundle if you want the result to be automatically added after the spin. 
    * Use the Game Manager to configure a Virtual Currency:
    	* Code: "ST"
     	* Name: "Spin Ticket"
     	* Initial Deposit: "1"       	// ensure that the player can spin at least once on day one.
     	* Recharge Rate: "1" 			// this sets the VC to regenerate 1 unit per day
     	* Recharge Max: "5"				// this caps the regeneration to the specified number, this is useful for allowing players to bank up to 5 spin tokens at a time

Assembly:
  * Client obtains a valid session ticket via one of the various Authentication pathways (required to make Client API Calls)
  * Provide the client with a mechanism to spin (this feature is disabled or hidden if the user does not have any Spin Tickets)
  * After clicking spin, the client attempts to purchase a SpinResult in exchange for 1 Spin Ticket
  * After recieving the client's request, PlayFab will:
    * Deduct a Spin Ticket from the Player's VC balance  
    * Award the bundle / container to the player's inventory 
    * Send a response with the updated information back to the client
  * Upon recieving the response, the client can display the award

  Other Notes:
    * Selling additional Spin Tickets via IAP