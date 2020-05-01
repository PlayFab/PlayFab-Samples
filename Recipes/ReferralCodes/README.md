# Referral Codes

Referral codes allow you to reward players who refer new players to your title. The new player enters a code (provided from a friend) to gain a referral award. Additionally, the referring player is also rewarded. Players can obtain rewards by referring other players multiple times up to a maximum limit; however, each player account can only be referred one time.  

In this demo, the referred player is awarded a "Premium Starter Pack", an item bundle containing several items useful to new players. Additionally, it limits each player to one starter pack.

After redeeming a referral code, the referred player is granted a "ReferralBadge", a permanent inventory item that signifies that the player has already been referred. Those that refer players get 10 Gems, an award that can be redeemed a limited number of times.

## Prerequisites

* A [PlayFab account](https://developer.playfab.com/en-US/sign-up)
* A PlayFab title

At least one of the following:

* To run the Unity sample, an installed copy of the Unity Editor. To install Unity for personal use via Unity Hub, or Unity+ for professional use, see [Download Unity](https://unity3d.com/get-unity/download).
* A web server to run the Javascript sample.

## How it works

1. Client A obtains a valid session ticket using one of the various authentication pathways (required to make Client API Calls)
2. Client A generates a referral code (the player ID) from the game client and gives the code to a friend (Client B)
3. Client B downloads their copy and logs in to obtain a valid session ticket via one of the various Authentication pathways (required to make Client API Calls)
4. Client B enters the referral code into their game client and hits redeem
5. Client B's game client then passes the referral code to `RedeemReferral` (a Cloud Script) for referral redemption which does the following:
    1) Check the referree's inventory and ensure that a "ReferralBadge" does not exist
    2) Before proceeding check the provided referral code to ensure that the code is valid
    3) Grant "Premium Starter Pack" to the referree
    4) Grant "ReferralBadge" to the referree and add the referrer's code to the ItemInstance annotation // added after to ensure container has been awarded
    5) Get the referrer's PlayerData key "Referrals" and ensure that the limit has not been hit
    6) Grant the referrer the VC
    7) Add the referree's PlayFab ID to the Referrals array and write the data back to the referrer
    8) Return the details to the referree's client

## Preparation

Before you begin, locate the Catalog.json and CloudScript.js files. If you have downloaded the repo locally, the JSON file is located in the \Recipes\ProgressiveRewards\PlayFab-JSON folder. The CloudScript.js file is located in the \Recipes\ProgressiveRewards\ folder.

1. Log in to [Game Manager](https://developer.playfab.com/).
2. Select your title.
3. In left navigation pane, select **Economy**, then select the **Currency** tab.
4. Select **New Currency**. Enter the following values to create a Virtual Currency:

    | Property | Value | Detail |
    | ---: | :---: | --- |
    | Code | GM | Abbreviation for our VC |
    | Name | Gems | Name of our VC |
    | Initial Deposit | 5 | How many each player gets with a new account |

5. Select **Save Currency**.
5. Select the **Catalog** tab, the select **Upload JSON**.
6. Select the Catalog.json file, then select **Upload File**.
7. In left navigation pane, select **Automation**, then select **Revisions**.
8. Select **Upload New Revision**, select the CloudScript.js file and then select **Save as revision**.

## Unity 3d Example Setup Instructions

Download the [PlayFlab Unity 3D SDK](https://aka.ms/playfabunitysdkdownload) from GitHub.

1. Open a new or existing project.
2. Locate locate the PlayFlab Unity 3D SDK and import it into your Project.
3. Locate the ProgressiveRewardsRecipe.unitypackage file and import it into your project. If you have downloaded the repo locally, it is located in the \Recipes\ProgressiveRewards\Example-Unity3d\ folder. Other wise you can download it from the [PlayFab-Samples GitHub repo](https://github.com/PlayFab/PlayFab-Samples/raw/master/Recipes/ReferralCodes/Example-Unity3d/ReferralCodesRecipe.unitypackage).
4. In the **Project** window, open **Assets &gt; PlayFab Recipes &gt; ReferralCodes &gt; Scenes** and add the ReferralCodes scene to your Hierarchy.
5. In the **Hierarchy** windows, then select the Main Camera under the ReferralCodes scene.
6. In the **Inspector** window, in the Referral Code Demo script component, set **Play Fab Title Id** to the Title ID for your PlayFab title.
7. Run the scene. Call-by-call status updates are displayed in the console.

## JavaScript Example Setup Instructions

1. Copy the Example-JavaScript folder to your web server. If you have downloaded the repo locally, the folder is located at \PlayFab-Samples-master\Recipes\ReferralCodes\Example-JavaScript.
2. In your browser, navigate to the index.html page.
3. Enter in your title ID
    * This example automatically generates a GUID on login. You can instead use and ID for any user that you choose.
    * After logging in, the ID is saved into your browser's localstorage
4. Open your browser's developer console to see call-by-call status updates.

## Additional Resources

* For information about debugging CloudScript, see the "Advanced: Debugging CloudScript" section of [Writing custom CloudScript](https://docs.microsoft.com/en-us/gaming/playfab/features/automation/cloudscript/writing-custom-cloudscript#advanced-debugging-cloudscript).
* For information about Catalogs, see [Catalogs](https://docs.microsoft.com/en-us/gaming/playfab/features/commerce/items/catalogs).
