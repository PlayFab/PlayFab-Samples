# PlayFab Testing Tools Repository
 These items are for use in testing the various push notification systems for your title.

###Tools:
  * [Unity Push Plugin and Example Project](/TestingTools/PushNotifications/PushDebuggerProject.unitypackage) - Provides an asset package with useful examples for testing client side push notifications. Built on Unity 5.3.4, using our own plugin. For more information about push notifications, [start here](http://api.playfab.com/docs/push-basics).
 
 To send test push notifications from the client, you will need to add the following method to your title's Cloud Script. 

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