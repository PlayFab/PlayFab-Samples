# Simple In-Game Cross Promotion

In-Game Cross Promotion allows you to reward players that play more than one of your games. This example shows how you can use Player Publisher Data to implement this paradigm.

## How it works

In-Game Cross Promotion depends on each client "checking-in" after Authentication. The check-in process occurs in CloudScript's secure environment.

1. The client obtains a valid session ticket via one of the various authentication pathways (required to make Client API Calls).
2. The client checks-in by calling the CloudScript method `CheckIn`.
3. `CheckIn` method reads the Player Publisher Data and determines whether the player is eligible for a reward.
4. Award results are passed back to the client to update the player.

## Prerequisites

* A [PlayFab account](https://developer.playfab.com/en-US/sign-up)
* A PlayFab title

At least one of the following:

* To run the Unity sample, an installed copy of the Unity Editor. To install Unity for personal use via Unity Hub, or Unity+ for professional use, see [Download Unity](https://unity3d.com/get-unity/download).
* A web server to run the Javascript sample.

## Preparation

Before you begin, locate the Catalog.json and CloudScript.js files. If you have downloaded the repo locally, the JSON file is located in the \Recipes\SimpleCrossPromotion\PlayFab-JSON folder. The CloudScript.js file is located in the \Recipes\SimpleCrossPromotion\ folder.

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
6. Select the **Catalog** tab, the select **Upload JSON**.
7. Select the Catalog.json file, then select **Upload File**.
8. In the **Title Data** window, under **Title Data** select **Upload JSON**.
9. Select the TitleData.json file, the select **Upload**.
10. In left navigation pane, select **Automation**, then select **Revisions**.
11. Select **Upload New Revision**, select the CloudScript.js file and then select **Save as revision**.

To fully test this recipe you must have multiple titles with the similar CloudScript scripts & TitleData. This pattern allows you to have different rewards for each individual catalog. Ensure that your 2nd and third titles match the values in your TitleData > CrossPromotionalRewards.

## Unity 3d Example Setup Instructions

Download the [PlayFlab Unity 3D SDK](https://aka.ms/playfabunitysdkdownload) from GitHub.

1. Open a new or existing project.
2. Locate locate the PlayFlab Unity 3D SDK and import it into your Project.
3. Locate the ProgressiveRewardsRecipe.unitypackage file and import it into your project. If you have downloaded the repo locally, it is located in the \Recipes\ProgressiveRewards\Example-Unity3d\ folder. Other wise you can download it from the [PlayFab-Samples GitHub repo](https://github.com/PlayFab/PlayFab-Samples/raw/master/Recipes/SimpleCrossPromotion/Example-Unity3d/SimpleCrossPromotionRecipe.unitypackage).
4. In the **Project** window, open **Assets &gt; PlayFab Recipes &gt; ReferralCodes &gt; Scenes** and add the ReferralCodes scene to your Hierarchy.
5. In the **Hierarchy** windows, then select the Main Camera under the ReferralCodes scene.
6. In the **Inspector** window, in the Referral Code Demo script component, set **Play Fab Title Id** to the Title ID for your PlayFab title.
7. Run the scene. Call-by-call status updates are displayed in the console.  

## JavaScript Example Setup Instructions

1. Copy the Example-JavaScript folder to your web server. If you have downloaded the repo locally, the folder is located at \PlayFab-Samples-master\Recipes\RegeneratingCurrency\Example-JavaScript.
2. In your browser, navigate to the index.html page.
3. Enter in your title ID
    * This example automatically generates a GUID on login. You can instead use and ID for any user that you choose.
    * After logging in, the ID is saved into your browser's localstorage
4. Open your browser's developer console to see call-by-call status updates.

## Additional Resources

* For information about debugging CloudScript, see the "Advanced: Debugging CloudScript" section of [Writing custom CloudScript](https://docs.microsoft.com/en-us/gaming/playfab/features/automation/cloudscript/writing-custom-cloudscript#advanced-debugging-cloudscript).
* For information about Catalogs, see [Catalogs](https://docs.microsoft.com/en-us/gaming/playfab/features/commerce/items/catalogs).
