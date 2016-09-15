## Referral Codes
### Description:
Players can enter a code (provided from a friend) to gain a referral award. Additionally, the referring player is also rewarded. Players can obtain rewards from referring players multiple times up to a maximum limit; however, each player account may only be referred one time.  

For this demo, we will be awarding the referee a "Premium Starter Pack", an item bundle containing several items useful to new players. Additionally, we want to limit each player to 1 starter pack. 

After redeeming a referral code, the referree will be granted a "ReferralBadge", a permanent inventory item that signifies that the player has already been referred. Those that refer players get 10 Gems, an award that can be redeemed a limited number of times.

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
  Code | GM | Abbreviation for our VC
  Name | Gems | Name of our VC
  Initial Deposit | 5 | How many each player gets with a new account
  
  2. Next, under the Catalog tab, add a new catalog called **ReferralCode**.
  3. Navigate back to the top-level catalogs view and click on the small black arrow in the top-right corner of the "ReferralCode Catalog". Choose the Upload JSON option and provide [this example catalog](/Recipes/ReferralCodes/PlayFab-JSON/Catalog.json) or use your own.
    * If using your own, ensure that you have items that can be granted in the referral process.

  4. Under the **Servers &gt; CloudScript** section of the Game Manager, upload & deploy [this .js file](/Recipes/ReferralCodes/CloudScript.js), or ensure that yours has corresponding methods.

### Mechanic Walkthrough:
  1. Client A obtains a valid session ticket via one of the various authentication pathways (required to make Client API Calls)
  2. Client A generates a referral code (the player ID) from the game client and gives the code to a friend (Client B). //this is done outside the game
  3. Client B downloads their copy and logs in to obtain a valid session ticket via one of the various Authentication pathways (required to make Client API Calls)
  4. Client B enters the referral code into their game client and hits redeem
  5. Client B's game client then passes the referral code to "RedeemReferral" (a Cloud Script) for referral redemption
    * RedeemReferral will:
      1) Check the referree's inventory and ensure that a "ReferralBadge" does not exist
      2) Before proceeding check the provided referral code to ensure that the code is valid. 
      3) Grant "Premium Starter Pack" to the referree
      4) Grant "ReferralBadge" to the referree and add the referrer's code to the ItemInstance annotation // added after to ensure container has been awarded.
      5) Get the referrer's PlayerData key "Referrals" and ensure that the limit has not been hit
      6) Grant the referrer the VC 
      7) Add the referree's PlayFab ID to the Referrals array and write the data back to the referrer
      8) Return the details to the referree's client

### Cloud Script:
In this example we are using Cloud Script to act as the secure server ensuring that the referral processing and item grants happen on a trusted machine. The results of any actions performed in Cloud Script are then passed back to inform the client.


----

#### Unity 3d Example Setup Instructions:
Import the following asset packages into a new or existing Unity project:

  * Ensure you have the latest SDK [here](https://github.com/PlayFab/UnitySDK/raw/versioned/Packages/UnitySDK.unitypackage).
  * Ensure you have the recipe files [here](https://github.com/PlayFab/PlayFab-Samples/raw/master/Recipes/ReferralCodes/Example-Unity3d/ReferralCodesRecipe.unitypackage).
  
  1. Add assets to your project. 
  2. Open to the ReferralCodes scene.
  3. Add your title ID to the ReferralCodes.cs script via the Unity Inspector.
  4. Run the scene and observe the console for call-by-call status updates.

----

#### JavaScript Example Setup Instructions:
  1. Copy [this folder](/Recipes/SimpleCrossPromotion/Example-JavaScript) to your web server. 
  2. Navigate to index.html  
  3. Enter in your title ID
    * This example automatically generates a GUID on login; however, You may choose any id you like.
    * After logging in whatever id was used will be saved into your browser's localstorage
  4. Observe your browser's developer console for call-by-call status updates.
