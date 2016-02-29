## Invite a Friend Code Reward 
### Description:
Players can enter a code (provided from a friend) to gain a referral award. Additionally, the referring player should also get an award. The referring player can be awarded can be obtainaned multiple times. 

 For this demo, we will be awarding the referee a "Premium Starter Pack", a item bundle containing several useful items for new players. Additionally, we want to limit each player to 1 starter pack, to do this we will be using another item "ReferralBadge". After redeeming a referal code, the referree will be granted a "ReferralBadge", a permenant inventory item that signifies that the player has already been referred. Those that refer players get 10 Gems and can capped on how many times they can recieve this bonus.

### Ingredients:
  * [Accounts](https://api.playfab.com/docs/building-blocks#Accounts)
  * [Player Data](https://api.playfab.com/docs/building-blocks#Player_Data)
  * [Player Inventory](https://api.playfab.com/docs/building-blocks#Player_Inventory)
  * [Virtual Currency](https://api.playfab.com/docs/building-blocks#Virtual_Currency)
  * [Catalog & CatalogItems (Bundle / Container)](https://api.playfab.com/docs/building-blocks#Catalog)
  * [Cloud Script](https://api.playfab.com/docs/building-blocks#Cloud_Script)

### Preparation:
  1. Use the Game Manager to configure a Virtual Currency for your title:

  | Property | Value | Detail
  ---: | :---: | --- 
  Code | GM | Abbreviation for our VC
  Name | Gems | Name of our VC
  Initial Deposit | 5 | How many each player gets with a new account

  2. Upload [this example catalog](/Recipes/ReferralCodes/PlayFab-JSON/Catalog.json) or use your own.
    * If using your own, ensure that you have items that can be granted in the referral process.

  3. Upload & deploy [this Cloud Script](/Recipes/ReferralCodes/CloudScript.js), or ensure that yours has a corresponding methods.

### Process Walkthrough:
  1. Client A obtains a valid session ticket via one of the various Authentication pathways (required to make Client API Calls)
  2. Client A generates a referral code (the player ID) from the game client and gives the code to a friend (Client B). //this is done outside the game
  3. Client B downloads their copy and logs in to obtain a valid session ticket via one of the various Authentication pathways (required to make Client API Calls)
  4. Client B enters the referral code into their game client and hits redeem
  5. Client B's game client then passes the referral code to "RedeemReferral" (a Cloud Script) for referral redemption
    * RedeemReferral will:
      1) Check the referree's inventory and ensure that a "ReferralBadge" does not exist
      2) Before proceeding check the provided referal code to ensure that the code is valid. 
      3) Grant "Premium Starter Pack" to the referree
      4) Grant "ReferralBadge" to the referree and add the referer's code to the ItemInstance annotation  // added after to ensure container has been awarded.
      5) Get the referer's PlayerData key "Referals" and ensure that the limit has not been hit
      6) Grant the referrer the VC 
      7) Add the referree's PlayFab ID to the Referrals array and write the data back to the referrer
      8) Return the details to the referree's client 

### Cloud Script:
In this example we are using Cloud Script to act as the secure server ensuring that the referral processing and item grants happen on a trusted machine. The results of any actions performed in Cloud Script are then passed back to inform the client.


----

#### Unity 3d Example Setup Instructions:
Open the stand alone project in unity or import our asset packages into your existing project.
  * Ensure you have the latest SDK [here](https://github.com/PlayFab/UnitySDK/raw/versioned/PlayFabClientSDK.unitypackage).
  * Ensure you have the recipe files [here](/Recipes/ReferralCodes/Unity3d-Example/ReferralCodes.unitypackage).
  
  1. Add assets to your project. 
  2. Open to the ReferraCodes scene.
  3. Add your title ID to the ReferraCodes.cs script via the Unity Inspector.
  4. Run the scene and observe the console for call-by-call status updates.