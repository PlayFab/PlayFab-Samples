# PlayFab Testing Tools Repository
 These items are for use in testing and debugging the various PlayFab systems.

###Tools:
  * [Unity Push Plugin and Example Project](/TestingTools/PushNotifications/) - Provides an asset package with useful examples for testing client side push notifications. Built on Unity 5.3.4, using our own plugin. For more information about push notifications, [start here](http://api.playfab.com/docs/push-basics).

  * [Using Custom JSON Data](/TestingTools/CustomJsonParser/) - End-to-end demonstration of how to override PlayFab's built-in JSON parser to use your preferred library. In this example we are showing how to use JSON.net, but the same process would be used for most libraries. This is particularly helpful when you are building to platforms that do not work with SimpleJson. 