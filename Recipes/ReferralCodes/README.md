-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
Invite a Friend Code Reward 
-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
Description:
Players can enter a code (provided from a friend) to gain a referral award. Additionally, the referring player should also get an award. The referring player can be awarded can be obtainaned multiple times. 

Refer a friend and that friend gets an Premium Starter Pack and you get 10 Gems!

Ingredients:
  * Accounts
  * Player Data
  * Player Inventory
  * Catalog & CatalogItems (Bundle / Container)
  * Virtual Currency
  * Cloud Script

Preparation:
  * Must have a catalog with some items that can be granted to a player.
  * For this demo, we will be awarding the referee a "Premium Starter Pack", a container item with containing several useful items for new players 
  * Additionally, we want to limit each player to 1 starter pack, to do this we will be using another item "ReferralBadge". After redeeming a referal code, the referree will be granted a "ReferralBadge", a permenant inventory item that signifies that the player has already been referred.  
  * Use the Game Manager to configure a Virtual Currency (optional -- but useful if you intend to grant VC like 10 Gems)

Assembly:
  * Client A obtains a valid session ticket via one of the various Authentication pathways (required to make Client API Calls)
  * Client A generates a referral code (the player ID) from the game client and gives the code to a friend (Client B). //this is done physically
  * Client B downloads the game and logs in to obtain a valid session ticket via one of the various Authentication pathways (required to make Client API Calls)
  * Client B enters the referral code into the game client 
  * Client B's game client then passes the referral code to "RedeemReferral" (a Cloud Script) for referral redemption
  * RedeemReferral will:
    * Check the referree's inventory and ensure that a "ReferralBadge" does not exist
    * Before proceeding check the provided referal code to ensure that the code is valid. 
    * Grant "Premium Starter Pack" to the referree
    * Grant "ReferralBadge" to the referree and add the referer's code to the ItemInstance annotation  // added after to ensure container has been awarded.
    * Get the referer's PlayerData key "Referals" and ensure that the limit has not been hit
    * Grant the referrer the VC 
    * Add the referree's PlayFab ID to the Referrals array and write the data back to the referrer
    * Return the details to the referree's client 

Cloud Script:
  * 