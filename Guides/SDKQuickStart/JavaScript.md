# Getting Started with the PlayFab JavaScript SDK #

## Introduction ##
The PlayFab JavaScript SDK allows JavaScript developers to access the power of the PlayFab Client API from within JavaScript programs.  
Follow these steps to create a simple JavaScript web app that will register a user with the PlayFab backend service.

## Prerequisites ##
You will need to have some things ready in order to use this guide.

- Your favorite JavaScript development tools.  At the least, you will need a web server and a text editing tool.
- A little knowledge of PlayFab.  See [The PlayFab Beginner’s Guide](https://api.playfab.com/docs/beginners-guide) for an overview of how PlayFab works.  For more depth, download a copy of the [PlayFab Technical Overview](https://playfab.com/wp-content/uploads/2015/12/PlayFabTechnicalWhitePaper_2015.12.09.pdf). 
- A PlayFab Developer account.  See [PlayFab Developer Account](https://developer.playfab.com/en-us/studios) to sign up for your own free PlayFab account.

## Steps ##
Follow these steps to create your first PlayFab / JavaScript project. By the way, in PlayFab each project or title is called a game.

### Add a game to PlayFab ###
First you will create a new PlayFab game, and make a note of the Title ID for later use in PlayFab calls.

1. Open the [Game Manager](https://developer.playfab.com/en-us/studios), PlayFab’s web based tool for adding, viewing and changing your games. You should see your games listed by studio.  If you just created your account, you will see a default studio called **My Game Studio**, and a default game called **My Game**. 
2. Create a new game by clicking **Create a new game**, and name it "Getting Started".  You can fill in the rest of the information on this page, or leave it blank.  Click **Create Game** to add this game to your PlayFab account.  
3. Return to the main view in the Game Manager by clicking the PlayFab logo in the upper left corner of the screen. You will see a tile for your new game showing the game title and Title ID. The Title ID is a unique value used by PlayFab to identify this game. Make a note of the Title ID for the new game. You will need this value later.

![PlayFab Title Tile](https://raw.githubusercontent.com/PlayFab/PlayFab-Samples/recipe_dev/Guides/SDKQuickStart/Assets/images/TitleTile.png "PlayFab Title Tile in Game Manager")

### Add the PlayFab JavaScript SDK to your web server ###
You can program the PlayFab API in two ways:

- Directly through a HTTP web API, which is described in [PlayFab API documentation](https://api.playfab.com/Documentation).
- Through platform specific libraries which are listed in [Available SDKs](https://api.playfab.com/sdks). These SDKs do the work of making API calls and handling responses.

You can access the PlayFab Client, Server and Administrative APIs using these SDKs. For JavaScript developers using the Client API, the easiest way to get started is to download and add the PlayFab JavaScript API folder to your project. For the duration of this guide we will assume that you are hosting the project at the root of an empty web server that can be accessed as localhost in your browser of choice.

![API Sets](https://raw.githubusercontent.com/PlayFab/PlayFab-Samples/recipe_dev/Guides/SDKQuickStart/Assets/images/pf_apiSets.png "Import the SDK into your Unity project")

1.	From the [JavaScript SDK](https://api.playfab.com/sdks/javascript) page click **Download PlayFab SDK**. Unzip the folder, and add the unzipped folder to the root of your web-server.
2.	The SDK contains several sample test files that can be deleted. Follow the instructions in the [PlayFab JavaScript SDK](https://github.com/PlayFab/JavaScriptSDK) GitHub project.

### Create a simple web project ###

Create two text files named code.js and index.html in the root of your server, and add the following framework code to index.html. There is nothing special about this code, it is just the framework to support the working code you will be adding later.

    <!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
    <html lang="en">

	    <head>
		   <meta http-equiv="content-type" content="text/html; charset=utf-8">
		   <title>Getting Started with PlayFab</title>
		   <script src="https://ajax.googleapis.com/ajax/libs/jquery/2.2.0/jquery.min.js"></script>
	    </head>

	    <body>
	    </body>
    </html>

### Add PlayFab specific code to the HTML file ###
Add a reference to your copy of the PlayFab SDK. Place this line of code after the other script tags in the head section.

		   <script type="text/javascript" src="/JavaScriptSDK-versioned/PlayFabSDK/PlayFabClientApi.js"></script>

Now add a reference to the code.js file you just made.

           <script type="text/javascript" src="code.js"> </script>

Now add a control to the body so that you can make an API call.

		   <button id="login" class="stdButton" style="height:100%;">LOGIN</button>

### Add PlayFab specific JavaScript to the .js file ###

This code will be used to authenticate the player.
Normally you would add code to create a unique ID and save that unique ID in **localStorage** (see the [PlayFab PrizeWheel Recipe](https://github.com/PlayFab/PlayFab-Samples/tree/master/Recipes/PrizeWheel) for an example of how that works), but for now you will use a pre-generated identifier to keep the code simple. 

Every time the game logs into PlayFab this unique value is used to find the user in the Studio's user database.  The first time you log in with this identifier a user will be created in PlayFab, and from that point onward every time you log in with this id you will be connected to the same user.

All SDK calls follow a common pattern using a request and a result class.  You pass in the request and you get a callback with the result or error. **LoginWithCustomIDRequest** holds the request data, and **AuthenticationCallback** handles the returned data.

![API Calling Pattern](https://raw.githubusercontent.com/PlayFab/PlayFab-Samples/recipe_dev/Guides/SDKQuickStart/Assets/images/pf_callingPattern.png "Most SDKs follow a similar Call / Response Pattern")

This is also where you use the title ID that you made note of earlier in the Game Manager.

    function Authenticate() {
		// Authenticate using hard-coded strings for TitleID and CustomID;
	    PlayFab.settings.titleId = "{yourtitleid}";

        var LoginWithCustomIDRequest = {
		    "TitleId" : PlayFab.settings.titleId,
		    "CustomId" : "f5bf7f96-0399-4510-88a6-3e3a42a90f5e",
		    "CreateAccount" : true
	    };

	    console.log("Logging into PlayFab...");
	    PlayFabClientSDK.LoginWithCustomID(LoginWithCustomIDRequest, AuthenticationCallback);
    }

    function AuthenticationCallback(response, error) {
	    if(error)
	    {
	        console.log(error);
	    }	
	    else
	    {
		    var result = response.data;
		    console.log("Login Successful. Welcome Player: " + result.PlayFabId);
		    console.log("Your session ticket is: " + result.SessionTicket);
	    }
    }

Finally you need to wire up the button you added in the html file to the **Authenticate** function. Do this by adding code to the top of the code.js file.

    $( document ).ready(function() {
        console.log( "ready!" );
        $("#login").click(function() {
		Authenticate();
	    });
    });

Now point your browser at [http://localhost](http://localhost). You should see the** login** button in the upper left corner of the screen.

Open the developer tools in your browser, and open the console window. In Chrome, you would do this by clicking on the three horizontal lines in the upper right corner of the program, then click **More tools** from the drop down menu, and finally click **Developer tools**. This displays the developer tools window, where one of the tabs at the top is **Console**.  Click on this to see any messages sent from your code to the console. If you are using another browser, see the browser documentation for instructions on how to do this.


### Test your JavaScript Project ###
Click the **login** button at the top of the screen.  If all goes according to plan, you will see debug trace in the console window that will tell you the result of the logon attempt. If successful, the player will be logged in to PlayFab with a session ticket that is valid for 24 hours. The returned PlayFab ID in the Login method can now be used for subsequent API calls while the player interacts with your game. 
Once you have created a PlayFab account for a player from any game in your studio, their PlayFab account ID is available for all of the games in your studio.

### Confirm the new player in the Game Manager ###
You can now return to the Game Manager and confirm that the player has been created. Your new player should be immediately visible from the PlayStream Debugger. 

![PlayStream Debugger](https://raw.githubusercontent.com/PlayFab/PlayFab-Samples/recipe_dev/Guides/SDKQuickStart/Assets/images/PlayStreamDebugger.png "Clicking the Player ID will take you to the corresponding player details.")

**To view recently logged in players**:

1.	Open [Game Manager](https://developer.playfab.com/en-us/studios).
2.	Click on your title, **Getting Started**.
3.	In the left sidebar, click on the **Players** tab.  You will see a list of players who have been added to your Getting Started game.

### What just happened? ###
You used **LoginWithCustomID** to establish a connection with PlayFab and connect to a unique player for one of your titles.  If no player was found, a new player was created and associated with the unique ID that you passed in.
**LoginWithCustomIDRequest** was created to hold the parameters for the call, and **AuthenticationCallback** was created to handle the returned data. 

**LoginWithCustomID** returns a session identifier which you will use to identify this player for the remainder of this game session.  The session identifier is stored for later use in the global **PlayFabId**.

## Next steps ##
Congratulations on your first PlayFab API call.  Expand on what you have learned and explore what else PlayFab can do for you by exploring [Recipes](https://api.playfab.com/docs/recipe-index), [Tutorials and Guides](https://api.playfab.com/docs/tutorials).  The [PlayFab Unity SDK](https://github.com/PlayFab/UnitySDK) on GitHub also has useful information, including  "PlayFabClientSample" and "PlayFabCombinedTestingSample" which contain more examples of how to make calls to PlayFab from JavaScript. 

