## Wish List
### Description:
Players can save in-game items that they want to purchase or receive as a gift in the future to a wish list. Wish lists in this example use PlayFab entity groups. The player to whom the wish list belongs to is the administrator of the entity group, and players who can view the wishlist are members. The wish list is stored as an itemized CSV in the entity group's data.

This technique is designed for durable items, but can easily be extended to consumable items.

### Ingredients (Building Blocks):
  * [Accounts](https://api.playfab.com/docs/building-blocks#Accounts)
  * [Player Inventory](https://api.playfab.com/docs/building-blocks#Player_Inventory)
  * [Catalog & CatalogItems (Bundle / Container)](https://api.playfab.com/docs/building-blocks#Catalog)
  * [Entities](https://docs.microsoft.com/en-us/gaming/playfab/features/social/groups/quickstart)
  * [Entity Objects](https://docs.microsoft.com/en-us/rest/api/playfab/data/object?view=playfab-rest)

### Preparation ###

  1. Under the **Economy &gt; Catalogs** section of the Game Manager create a catalog called **game_items** and add the following items to the catalog:

| Item ID | Consumable |
| :-----: | :--------: |
|   cat   |  Durable   |
|   dog   |  Durable   |
|  mango  |  Durable   |

2. Next, under **Settings > Title Settings > API Features**, find the **Entity Global Title Policy** and add the following object to the array of policy objects.

```
  {
    "Action": "Read",
    "Effect": "Allow",
    "Resource": "pfrn:data--*!*/Profile/Objects/wishlist",
    "Principal": "*",
    "Comment": "",
    "Condition": null
  }
```

We want other players to view a player's wish list, but entity objects are not public by default. Still, we want the wishlist key-value pair to be public. Hence, we need to pudate the title's global policy to allow viewers to view wish list entity group data. We want this to be a title-wide policy so that it applies to all players.

### Mechanic Walkthrough:
#### Login ####

1. Client obtains a valid session ticket via LoginWithPlayFabRequest (required to make Client API Calls)
2. After logging in, the client calls GetObject on the title player entity to get their wish list. If the wish list is not found, a wish list is created. When a wish list is created, a CloudScript function is called to update the global policy, essentially enabling all players able to read a player's wish list. Specifically, any player can read the "wishlist" entity object data.
3. The buttons corresponding to items already on the wishlist change to green. The button text indicates that the item is on the wish list.

If you would like to login with a username and password, change the On Click function for the **Login_Button** to `loginButtonClicked()`, which is also in `LoginClass.cs`. The `loginButtonClicked` function enables you to enter a username and password, and login using those credentials.

#### Update wish list

1. UpdateWishlist takes in the ItemId as a string.
2. Client calls GetObjects on the entity group and reads the wish list, which is a CSV of ItemId's.
3. If the ItemId shows up in the CSV, then it is removed from the CSV. If the ItemId does not show up in the CSV, it is added to the CSV.
4. Client updates the player entity's wish list. The entity object with the key "wishlist" has its value set to the updated CSV.
5. If successful, the change is reflected in the Unity game. The color and text of the button corresponding to the item that was either added or removed from the wish list is changed.

#### View another player's wish list

1. Enter the other player's PlayFabId into the input field, and click the **Get Player Wish List** button.
2. Client gets the player's title-specific Player ID, creates an Entity Key for that object, and calls GetObjects. That player's wish list is then printed to the Unity Console if it exists.

----

#### Unity 3d Example Setup Instructions:
Import the following asset packages into a new or existing Unity project:

  * Ensure you have [the latest SDK](https://github.com/PlayFab/UnitySDK/raw/versioned/Packages/UnitySDK.unitypackage).
  * Ensure you have the [recipe files](https://github.com/PlayFab/PlayFab-Samples/raw/master/Recipes/PrizeWheel/Example-Unity3d/PrizeWheelRecipe.unitypackage).

1. Follow the [Unity Quickstart](https://docs.microsoft.com/en-us/gaming/playfab/sdks/unity3d/quickstart) to download and install the PlayFab SDK (follow the steps up to "Making your first API call"). Be sure to change PlayFab Editor Extensions to your specific PlayFab account, studio, and title.
2. Add Assets and ProjectSettings to your Unity project. Specifically, replace the Assets and ProjectSettings folders from your new Unity project with the folders with the corresponding settings in the Wish List Recipe GitHub repo.
3. Open the SampleScene scene
4. Change TitleId's in LoginClass.cs to your TitleId.
5. Run the scene and observe the console for call-by-call status updates
   1. Click login to authenticate your user. The client creates an account for your device, so subsequent logins from the same device load the same account.
   2. Click the three buttons in the top left corresponding to the game items (cat, dog, and mango). See how the buttons change in Unity, and how the Entity Group data changes in Game Manager.
   3. To view another player's wish list, type their PlayFabId into the input field below "Enter PlayFabId:". Then, click the **Get Player Wish List** button. In the Unity Debug Console, you will see their wish list printed in the form of an itemized CSV.