# Getting Started with the PlayFab Unity SDK #
## Introduction ##
The PlayFab Unity SDK allows Unity developers to access the power of the PlayFab API from within the Unity game development environment.  
Follow these steps to create a simple Unity project that will register a user with the PlayFab backend service.
## Prerequisites ##
You will need to have some things ready in order to use this guide.

- A current copy of Unity.  See [Get Unity](http://unity3d.com/get-unity "Get Unity") if you don’t have Unity installed yet.  Version 5.3.1f1 was used for these instructions.  Some of the steps below may have changed if you have a later version.
- A little knowledge of PlayFab.  See [The PlayFab Beginner’s Guide](https://api.playfab.com/docs/beginners-guide) for an overview of how PlayFab works.  For more depth, download a copy of the [PlayFab Technical Overview](https://playfab.com/wp-content/uploads/2015/12/PlayFabTechnicalWhitePaper_2015.12.09.pdf). 
- A PlayFab Developer account.  See [PlayFab Developer Account](https://developer.playfab.com/en-us/studios) to sign up for your own free PlayFab account.

## Steps ##
Follow these steps to create your first PlayFab / Unity project. By the way, in PlayFab each project or title is called a game.
### Add a game to PlayFab ###
First you will create a new PlayFab game, and make a note of the Title ID for later use in PlayFab calls.

1. Open the [Game Manager](https://developer.playfab.com/en-us/studios), PlayFab’s web based tool for adding, viewing and changing your games. You should see your games listed by studio.  If you just created your account, you will see a default studio called **My Game Studio**, and a default game called **My Game**. 
2. Create a new game by clicking **Create a new game**, and name it "Getting Started".  You can fill in the rest of the information on this page, or leave it blank.  Click **Create Game** to add this game to your PlayFab account.  
3. Return to the main view in the Game Manager by clicking the PlayFab logo in the upper left corner of the screen. You will see a tile for your new game showing the game title and Title ID. The Title ID is a unique value used by PlayFab to identify this game. Make a note of the Title ID since you will need it later.


![PlayFab Title Tile](https://raw.githubusercontent.com/PlayFab/PlayFab-Samples/recipe_dev/Guides/SDKQuickStart/Assets/images/TitleTile.png "PlayFab Title Tile in Game Manager")


### Add the PlayFab Unity package to Unity ###

You can program the PlayFab API in two ways:

- Directly through a HTTP web API, which is described in [PlayFab API documentation](https://api.playfab.com/Documentation).
- Through platform specific libraries which are listed in [Available SDKs](https://api.playfab.com/sdks). These SDKs do the work of making API calls and handling responses.

![API Calling Pattern](https://raw.githubusercontent.com/PlayFab/PlayFab-Samples/recipe_dev/Guides/SDKQuickStart/Assets/images/pf_callingPattern.png "Most SDKs follow a similar Call / Response Pattern")

You can access the PlayFab Client, Server and Administrative APIs using these SDKs. For Unity developers using the Client API, the easiest way to get started is to import the PlayFab Unity Package.

![API Sets](https://raw.githubusercontent.com/PlayFab/PlayFab-Samples/recipe_dev/Guides/SDKQuickStart/Assets/images/pf_apiSets.png "Import the SDK into your Unity project")

1.  From the [Unity SDK](https://api.playfab.com/sdks/unity) page click **Download Unity Package**, and save the package to a location that you can find later.
2.  Open Unity and create a new project named **Getting Started with PlayFab**. Click **Create Project**, which will create the project and open it in Unity.
3.  In Unity, import the package you just downloaded.  Click on the **Assets** menu, click **Import Package**, then **Custom Package**.
4.  In the **Import Package** dialog, navigate to the location of the downloaded package and select it.
5.  The next window you see is the **Import Unity Package** dialog, and it shows a list of the contents of the package.  Make certain that everything is checked, and then click Import.

![Unity AssetPackage Import](https://raw.githubusercontent.com/PlayFab/PlayFab-Samples/recipe_dev/Guides/SDKQuickStart/Assets/images/UnityImportSDK.png "Import the SDK into your Unity project")

### Create a Unity script ###
Click the **Play** button in Unity, and note that nothing happens.  No behavior has been added to the game objects in the Unity project yet, so no code runs when you click **Play**.  In this section you will add code that will be executed when you run your project. 
This code will connect to the PlayFab service and will either register a new player with a custom ID, or log in an existing player if they have already been registered with that ID. This is just one of several ways you can authenticate a user.

1.  Create a game object in Unity by clicking **Create Empty** in the **GameObject** menu.  Name this object “PlayFab Manager”.
2.  Create an empty script by clicking the Assets menu and then clicking **Create** and **C# Script**.  Name the new script "PlayFabManager".
Note that the new script contains stub code for a Start method, and an Update method.  As you might expect the Start method is called once at the start of the game, and the Update method is called once per frame. SDK calls make API requests across the network so they should not be called every frame.

###Add PlayFab specific code to the script###

Add using statements to the file to tell Unity to use PlayFab.

    using PlayFab;
    using PlayFab.ClientModels;

Add a global property at the start of the PlayFabManager class to keep track of the player's PlayFab ID. You'll need this value in other PlayFab API calls.

    public string PlayFabId; 

Set the PlayFab TitleID in the Start method.  Use the title ID for your game that you made a note of earlier in this document.

    void Start () 
    {
        PlayFabSettings.TitleId = "{your title id}";
    } 

Create a new method to hold the Login code. It’s recommended that you use the Unity property [SystemInfo.deviceUniqueIdentifier](http://docs.unity3d.com/ScriptReference/SystemInfo-deviceUniqueIdentifier.html) if available to create a unique ID, as shown in the following example code. Note that this call is not be available for all versions of Unity.

All SDK calls follow a common pattern using a request and a result class.  You pass in the request and you get a callback with the result or error. This example uses lambda notation, however you can also pass in explicit delegates for the result and error callbacks.

	void Login(string titleId)  
	{
	    LoginWithCustomIDRequest request = new LoginWithCustomIDRequest()
	    {
	        TitleId = titleId,
	        CreateAccount = true,
	        CustomId = SystemInfo.deviceUniqueIdentifier
	    };
	
	    PlayFabClientAPI.LoginWithCustomID(request, (result) => {
	        string PlayFabId = result.PlayFabId;
	
	        if(result.NewlyCreated)
	        {
	            Debug.Log("Got PlayFabID: " + PlayFabId + "(new account)");
	        }
	        else
	        {
	            Debug.Log("Got PlayFabID: " + PlayFabId + "(existing account)");
	        }
	    },
	    (error) => {
	        Debug.Log("Error logging in player with custom ID:");
	        Debug.Log(error.ErrorMessage);
	    });
	} 

And finally add a call to your new Login method in the Start method. The Start method now looks like this:

    void Start () 
    {
        PlayFabSettings.TitleId = "{your title id}";
        Login (PlayFabSettings.TitleId);
    } 

### Add the script to a game object ###
The script will not execute unless it is added to a game object.  In the Unity editor, drag and drop the script to the **PlayFabManager** game object that you made earlier, which is visible in the hierarchy pane.
### Test your Unity Project ###
Click the run button at the top of the screen.  If all goes according to plan, you will see debug trace in the console window that will tell you the result of the logon attempt. If successful, the player will be logged in to PlayFab with a session ticket that's valid for 24 hours. The returned PlayFab ID in the Login method can now be used for subsequent API calls while the player interacts with your game. 
Once you have created a PlayFab account for a player from any game in your studio, their PlayFab account ID is available for all of the games in your studio.
### Confirm the new player in the Game Manager ###
You can now return to the Game Manager and confirm that the player has been created. Your new player should be immediately visible from the PlayStream Debugger. 

![PlayStream Debugger](https://raw.githubusercontent.com/PlayFab/PlayFab-Samples/recipe_dev/Guides/SDKQuickStart/Assets/images/PlayStreamDebugger.png "Clicking the Player ID will take you to the corresponding player details.")

**To view recently logged in players**:
1.  Open [Game Manager](https://developer.playfab.com/en-us/studios).
2.  Click on your title, **Getting Started**.
3.  In the left sidebar, click on the **Players** tab.  You will see a list of players who have been added to your Getting Started game.

### What just happened? ###
You used **[LoginWithCustomID](https://api.playfab.com/Documentation/Client/method/LoginWithCustomID)** to establish a connection with PlayFab and connect to a unique player for one of your titles.  If no player was found, a new player was created and associated with the unique ID that you passed in.
The class **LoginWithCustomIDRequest** was created to hold the parameters for the call. 
One of the parameters, **CustomId** was set by calling the Unity API call **SystemInfo.deviceUniqueIdentifier**. This call returns a unique value based on properties of the hardware the player is using. On a given device it will always return the same result, making it easy to identify the player between sessions.
**[LoginWithCustomID](https://api.playfab.com/Documentation/Client/method/LoginWithCustomID)** returns a session identifier which you will use to identify this player for the remainder of this game session.  The session identifier is stored for later use in the global **PlayFabId**.

![Unity Output](https://raw.githubusercontent.com/PlayFab/PlayFab-Samples/recipe_dev/Guides/SDKQuickStart/Assets/images/UnityConsoleOutput.png "Our output shows our Player ID and account creation status.")

## Next steps ##
Congratulations on your first PlayFab API call.  Expand on what you have learned and explore what else PlayFab can do for you by exploring [Recipes](https://api.playfab.com/docs/recipe-index), [Tutorials and Guides](https://api.playfab.com/docs/tutorials).  The [PlayFab Unity SDK](https://github.com/PlayFab/UnitySDK) on GitHub also has useful information, including  "PlayFabClientSample" and "PlayFabCombinedTestingSample" which contain more examples of how to make calls to PlayFab from Unity. 
To continue what you have been learning see these tutorials:

- [Using Player Data](https://api.playfab.com/docs/using-player-data)
- [Using Title Data](https://api.playfab.com/docs/using-title-data)
- [Using Publisher Data](https://api.playfab.com/docs/using-publisher-data)

