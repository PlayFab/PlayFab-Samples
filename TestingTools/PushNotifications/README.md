# Push Notification Deubgger
 These project can be deployed to devices for verifying your push notification system.
 
 Before using this tool, ensure that you are familiar with our Push Notificaiton System:
 
  1. [Push Basics](https://api.playfab.com/docs/push-basics)
  2. [Push for iOS](https://api.playfab.com/docs/push-for-ios)
  3. [Push for Android](https://api.playfab.com/docs/push-for-android)

###Setup:

  1. Import the [asset package](https://github.com/PlayFab/PlayFab-Samples/blob/master/TestingTools/PushNotifications/PushDebuggerProject.unitypackage) into a new or existing Unity Project.
  2. Open the Debugger scene (PlayFabExamples/PushNotifications/Debugger.unity).
  3. Enter your Title ID & Google Project Id into the PlayFabLoginManager's Inspector.
    ![Unity Inspector](https://raw.githubusercontent.com/PlayFab/PlayFab-Samples/master/TestingTools/Assets/Images/PushInspector.png "Enter your Title Id & Google Project Id")
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
![Push Debugger UI](https://raw.githubusercontent.com/PlayFab/PlayFab-Samples/master/TestingTools/Assets/Images/PushRegistered.png "You should see something like this on your device.") 

6. Register and send test notifications as needed.

  * By default iOS devices "eat" messages sent while an app is the active app. To see messages come in, ensure that your app is in the background when you send the push notification. This requires you to send the message from an external source.
  * For Android, our Unity plugin provides overrides for routing the message in-game or to the notification bar. In-game messages will appear like the screenshot below. 
   
![Push Notifications](https://raw.githubusercontent.com/PlayFab/PlayFab-Samples/master/TestingTools/Assets/Images/TestPushConfirmation.png "A confirmation handled in-game") 