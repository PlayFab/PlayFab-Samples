# Regenerating Currency

A Regenerating Currency system provides a play-limiting mechanism (similar to lives / hearts from Candy Crush) that slowly refills depleted resources over time until they reach their maximum value. This is often accompanied by the ability to purchase additional lives.  PlayFab offers services to enable purchases using VC or IAP.

This example mimics gameplay through a CloudScript method called "Battle". While battling, the player can receive Gems at the cost of sometimes losing a life. Logic in CloudScript prevents players from battling if they do not have any lives. Extra lives regenerate every five minutes and are also available to purchase in exchange for Gems.

## How it works

1. Client obtains a valid session ticket via one of the various authentication pathways (required to make Client API Calls)
2. Client battles via calling into the Cloud Script method "Battle".
3. Cloud Script calculates Battle results and makes any Gem Additions, Life Losses and data updates to reflect results.
4. Results passed back to client for updating the player.
5. If a player loses all their lives, they must wait or purchase more in exchange for gems.

## Prerequisites

* A [PlayFab account](https://developer.playfab.com/en-US/sign-up)
* A PlayFab title

At least one of the following:

* To run the Unity sample, an installed copy of the Unity Editor. To install Unity for personal use via Unity Hub, or Unity+ for professional use, see [Download Unity](https://unity3d.com/get-unity/download).
* A web server to run the Javascript sample.

## Preparation

Before you begin, locate the Catalog.json and CloudScript.js files. If you have downloaded the repo locally, the JSON file is located in the \Recipes\RegeneratingCurrency\PlayFab-JSON folder. The CloudScript.js file is located in the \Recipes\RegeneratingCurrency\ folder.

1. Log in to [Game Manager](https://developer.playfab.com/).
2. Select your title.
3. In left navigation pane, select **Economy**, then select the **Currency** tab.
4. Select **New Currency**. Enter the following values to create a Virtual Currency:

  | Property | Value | Detail |
  | ---: | :---: | --- |
  | Code | LV | Abbreviation for our VC |
  | Name | Lives | Name of our VC |
  | Initial Deposit | 1 | ensure that the player can spin on their first login |
  | Recharge Rate | 288 |  Every 5 minutes: 24hr*60min / 5min |
  | Recharge Max | 5 | this caps the regeneration to the specified number |

5. Select **Save Currency**.
6. Add a second Virtual Currency to match the following parameters:

  | Property | Value | Detail |
  | ---: | :---: | --- |
  | Code | GM | Abbreviation for our VC |
  | Name | Gems | Name of our VC |
  | Initial Deposit | 5 | How many each player gets with a new account |

7. Select **Save Currency**.
8. Select the **Catalog** tab, the select **Upload JSON**.
9. Select the Catalog.json file, then select **Upload File**.
10. In left navigation pane, select **Automation**, then select **Revisions**.
11. Select **Upload New Revision**, select the CloudScript.js file and then select **Save as revision**.

## Unity 3d Example Setup Instructions

Download the [PlayFlab Unity 3D SDK](https://aka.ms/playfabunitysdkdownload) from GitHub.

1. Open a new or existing project.
2. Locate locate the PlayFlab Unity 3D SDK and import it into your Project.
3. Locate the ProgressiveRewardsRecipe.unitypackage file and import it into your project. If you have downloaded the repo locally, it is located in the \Recipes\ProgressiveRewards\Example-Unity3d\ folder. Other wise you can download it from the [PlayFab-Samples GitHub repo](https://github.com/PlayFab/PlayFab-Samples/raw/master/Recipes/RegeneratingCurrency/Example-Unity3d/ReferralCodesRecipe.unitypackage).
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
