
# Progressive Reward System

A progressive reward system allows you to reward players for logging in over consecutive days with progressive item grants. This example uses a three-tier reward table providing different items for 2, 5, 7 day log-in streaks. Cloud-Script logic acts as the authoritative server and performs the grant directly into the player's inventory.

## Prerequisites

* A [PlayFab account](https://developer.playfab.com/en-US/sign-up)
* A PlayFab title

At least one of the following:

* To run the Unity sample, an installed copy of the Unity Editor. To install Unity for personal use via Unity Hub, or Unity+ for professional use, see [Download Unity](https://unity3d.com/get-unity/download).
* A web server to run the Javascript sample.

## How it works

1. The client calls an authentication method to obtain a session ticket. This is required to make Client API Calls.
2. After logging in, the client calls the PlayFab SDK method  `ExecuteCloudScript` to execute a CloudScript method called `CheckIn`.
3. `CheckIn` performs the following:

    1. Calls the CloudScript method `CheckInTracker` to retrieve the current players ReadOnlyData.
        * If this is the first login, create a new record.
    2. Verifies that the player is eligible for a reward:
        * Must have logged in to a streak > 1
        * Must have been > 24 hrs since last grant
        * Must have been < 48 hours after the last grant (otherwise the streak will have been broken)
    3. Increments the next grant window.
    4. Write changes back to ReadOnlyPlayerData (`CheckInTracker`).
    5. Read the `ProgressiveRewardTable` key from `TitleData`.
    6. Look up the reward corresponding to the player's login streak.
    7. Grants the item to the player.
    8. Returns the details to the client.

Testing Level 2 and 3 rewards requires:

* Either waiting the specified login period.
* or using the Admin API to directly set the Player's data to specific points prior to check-in.

## Preparation

Before you begin, locate the Catalog.json, TitleData.json, and CloudScript.js files. If you have downloaded the repo locally, the JSON files are located in the \Recipes\ProgressiveRewards\PlayFab-JSON folder. The CloudScript.js file is located in the \Recipes\ProgressiveRewards\ folder.

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
7. In left navigation pane, select **Content**.
8. In the **Title Data** window, under **Title Data** select **Upload JSON**.
9. Select the TitleData.json file, the select **Upload**.
10. In left navigation pane, select **Automation**, then select **Revisions**.
11. Select **Upload New Revision**, select the CloudScript.js file and then select **Save as revision**.

## Unity 3d Example Setup Instructions

Download the [PlayFlab Unity 3D SDK](https://aka.ms/playfabunitysdkdownload) from GitHub.

1. Open a new or existing project.
2. Locate locate the PlayFlab Unity 3D SDK and import it into your Project.
3. Locate the ProgressiveRewardsRecipe.unitypackage file and import it into your project. If you have downloaded the repo locally, it is located in the \Recipes\ProgressiveRewards\Example-Unity3d\ folder. Other wise you can download it from the [PlayFab-Samples GitHub repo](https://github.com/PlayFab/PlayFab-Samples/raw/master/Recipes/ProgressiveRewards/Example-Unity3d/ProgressiveRewardsRecipe.unitypackage).
4. In the **Project** window, open **Assets &gt; PlayFab Recipes &gt; ProgressiveRewards &gt; Scenes** and add the ProgressiveReward scene to your Hierarchy.
5. In the **Hierarchy** windows, then select the Main Camera under the ProgressiveRewards scene.
6. In the **Inspector** window, in the Progressive Rewards script component, set **Play Fab Title Id** to the Title ID for your PlayFab title.
7. Run the scene. Call-by-call status updates are displayed in the console.

## JavaScript Example Setup Instructions

1. Copy the Example-JavaScript folder to your web server. If you have downloaded the repo locally, the folder is located at \PlayFab-Samples-master\Recipes\ProgressiveRewards\Example-JavaScript.
2. In your browser, navigate to the index.html page.
3. Enter in your title ID
    * This example automatically generates a GUID on login. You can instead use and ID for any user that you choose.
    * After logging in, the ID is saved into your browser's localstorage
4. Open your browser's developer console to see call-by-call status updates.

## Additional Resources

* For information about debugging CloudScript, see the "Advanced: Debugging CloudScript" section of [Writing custom CloudScript](https://docs.microsoft.com/en-us/gaming/playfab/features/automation/cloudscript/writing-custom-cloudscript#advanced-debugging-cloudscript).
* For information about Catalogs, see [Catalogs](https://docs.microsoft.com/en-us/gaming/playfab/features/commerce/items/catalogs).
* For information about Title Data, see [Title Data](https://docs.microsoft.com/en-us/gaming/playfab/features/config/titledata/).