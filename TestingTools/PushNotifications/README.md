# Push Notification Deubgger
 These project can be deployed to devices for verifying your push notification system.

###Setup:

  1. Import the [asset package](https://github.com/PlayFab/PlayFab-Samples/blob/master/TestingTools/PushNotifications/PushDebuggerProject.unitypackage) into a new or existing Unity Project.
  2. Open the Debugger scene (PlayFabExamples/PushNotifications/Debugger.unity).
  3. Enter your Title ID & Google Project Id into the PlayFabLoginManager's Inspector.
    ![PlayFab Title Tile](https://raw.githubusercontent.com/PlayFab/PlayFab-Samples/recipe_dev/Guides/SDKQuickStart/Assets/images/TitleTile.png "PlayFab Title Tile in Game Manager")
    *  Google Project Id is only required when using Google Cloud Messaging (GCM).
    *  Apple Devices(APNS & APNS_SANDBOX) do not require additional project settings.  
 4. To send test push notifications from the client, you will need to add the following method to your title's Cloud Script. 

 ```JavaScript
 //Called from postman, successful push notification moments later
handlers.SendPushNote = function (args) 
{
 	var request = {};
 	request.Recipient = args.Id == undefined || args.Id == null ? currentPlayerId : args.Id;
 	request.Message = args.Msg == undefined || args.Msg == null ? "" : args.Msg;
 	request.Subject = args.Subject == undefined || args.Subject == null ? "" : args.Subject;

 	server.SendPushNotification(request); 
}
```
5. Build & deploy to your target device
![PlayFab Title Tile](https://raw.githubusercontent.com/PlayFab/PlayFab-Samples/recipe_dev/Guides/SDKQuickStart/Assets/images/TitleTile.png "PlayFab Title Tile in Game Manager") 

6. Register and send test notifications as needed.
![PlayFab Title Tile](https://raw.githubusercontent.com/PlayFab/PlayFab-Samples/recipe_dev/Guides/SDKQuickStart/Assets/images/TitleTile.png "PlayFab Title Tile in Game Manager") 