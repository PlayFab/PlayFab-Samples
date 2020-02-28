![PlayFab logo](../../../images/Logo_Playfab_Blue_BG.jpg "PlayFab logo")

# PlayFab Messaging Sample
This sample demonstrates the use of SignalR combined with Azure Functions integrated with PlayFab to push notifications to clients.

## Prerequisites
* If you don’t already have Visual Studio 2019 installed, you can download and use the free [Visual Studio 2019 Community Edition](https://www.visualstudio.com/downloads/). Make sure that you enable Azure development during the Visual Studio setup.
* If you don't have an [Azure subscription](https://docs.microsoft.com/en-us/azure/guides/developer/azure-developer-guide#understanding-accounts-subscriptions-and-billing), create a [free account](https://azure.microsoft.com/free/?ref=microsoft.com&utm_source=microsoft.com&utm_medium=docs&utm_campaign=visualstudio) before you begin.
* You'll also need a [free PlayFab account](https://developer.playfab.com/en-US/sign-up) with a title created for testing purposes.

## Provision Azure Services
* Configure a SignalR Service instance as described in the section [here](https://docs.microsoft.com/en-us/azure/azure-signalr/signalr-quickstart-azure-functions-csharp#create-an-azure-signalr-service-instance).
* Create a Function app as described [here](https://docs.microsoft.com/en-us/azure/azure-functions/functions-create-first-azure-function#create-a-function-app).
> Please make note that you're required to create/specify a storage account as part of function app provisioning. You'll need this storage account later.

## Configure the settings in code
After cloning this repo, there are a few changes you'll need to make to the settings before it can be run and deployed.

### SignalR Connection String
1. Open the Azure portal to the SignalR service that you provisioned.
2. Navigate to "Keys" under "Settings"
3. Copy the full value under "CONNECTION STRING"
4. Open the local.settings.json file in the PlayFab.SignalRSample project in this repo
5. Find the AzureSignalRConnectionString setting
6. Replace the temporary string with the one copied from the Azure portal

### Storage Connection String
1. Open the Azure portal to the Storage Account you associated with your Function app earlier
2. Navigate to "Access Keys" under "Settings"
3. Copy the full value under "Connection String"
4. Open the local.settings.json file in the PlayFab.SignalRSample project in this repo.
5. Find the AzureWebJobsStorage setting
6. Replace the temporary string with the one copied from the Azure portal

### Set PlayFab Title Id
1. Navigate to the [PlayFab Game Manager](https://developer.playfab.com/)
2. Either create or Select the title you which to use for this sample and copy the (4 or 5 hex digit) title id
3. Open the Program.cs file in the MessagingClient project in this repo
4. Find this line:
```csharp
        // Title Id from PlayFab. Set this depending on the title you're integrating with.
        private const string TITLE_ID = "XXXXX";
```
5. Replace the "XXXXX" with the PlayFab title id

## Additional Azure configuration
Before we can build and deploy our solution, we need to configure a couple of things on our Azure resources.

### Create a queue
1. Open the Azure portal to the Storage Account you associated with your Function app earlier
2. Navigate to "Queues" under "Queue service" (you'll probably have to scroll down a bit)
3. Hit the big "+" button to add a queue
4. Name the queue "matchfound" and click OK

### Importing publish settings
1. Open the Azure portal to your Function app
2. Click the "Get publish profile"
3. Save the .PublishSettings file locally
4. Right Click on the PlayFab.SignalRSample project in Visual Studio
5. Choose the "Publish..." option
6. In the Publish Window click on "Start"
7. Click on the "Import Profile..." in the bottom left
8. Select the .PublishSettings file you downloaded earlier

## Build and Publish the Function app
1. Build the PlayFab.SignalRSample
2. It should download packages for SignalR, webjobs, and PlayFab
3. Verify the project builds successfully
4. Choose to publish the project using the publish settings from earlier

## Getting some Azure settings
Before we can start configuring things in PlayFab, we need to copy a few settings out of Azure.

### Determining Function Urls
1. Open the Azure portal to your Function app
2. Under "Function" click on each of the functions in series
3. For each, click on the "Get Function URL" link
4. Copy the URL for each to a scratch pad
> MatchFound will not have a URL. It's a Queue Function and isn't invoked by HTTP directly.

### Getting the Queue Connection String
1. Open the Azure portal to the Storage Account you associated with your Function app
2. Navigate to "Access Keys" under "Settings"
3. Copy the full value under "Connection String" to a scratch pad

## Configuring PlayFab
In order to stitch this all together, we also need to configure a few things in PlayFab.

### Matchmaking Queue
1. Choose Multiplayer from the BUILD section on the left
2. Go to the Matchmaking tab
3. Click the New Queue button in the top right
4. Set the Queue Name to "nr_simple"
5. Set both the Min and Max Match Size to 2
6. Save the Queue

### Register Http Azure Functions
> There are four functions to register, so there's a bit of repetition here. Three are standard HTTP functions and one is a Queue function. I'll describe each of these types.
1. Choose Automation from the BUILD section on the left
2. Go to the Cloud Script tab and click on "Functions (Preview)"
3. Click on Register Function
4. Select HTTP as the trigger type
5. Enter "GetSignalRConnection" as the Function name
6. Copy the associated Function URL from your scratch pad
7. Save the Function
8. Repeat steps 3-7 for Function names "PlayerLogin" and "SendChatMessage" as well

### Register Queue Azure Function
1. Choose Automation from the BUILD section on the left
2. Go to the Cloud Script tab and click on "Functions (Preview)"
3. Click on Register Function
4. Choose Queue as the trigger type
5. Enter "MatchFound" as the Function name
6. Enter "matchfound" as the Queue name
7. Copy the Storage Account connection string from your scratch pad

### Create Rules
> You'll need to create two rules, so just follow these steps twice for the two different rules.
1. Choose Automation from the BUILD section on the left
2. Go to the Rules tab
3. Click on New Rule
4. Set the Name to "Broadcast Friend Login"
5. Set the Event type to com.playfab.player_logged_in
6. Add an Action
7. Set the Type to Execute Azure Function
8. Slect 
9. Select "PlayerLogin" as the Cloud Script Azure Function selection
10. Save the rule
11. Repeat steps 3-10 using Name=Matchmaking Notifications, Event type=playfab.matchmaking.match_found, and Function=MatchFound

## Running the sample app
With all the configuration out of the way, we're free to run the app. The app is designed to run multiple local instances, so once you build it, you'll want to find the local executable to make it easy to launch multiple copies.

### What the app does
The app does these things in sequence
* Login to PlayFab using a unique id based on the local machine name
* Setup a SignalR connection
* Join a matchmaking queue
* Receive a notice via SignalR once matched
* Enter a chat channel with the other player in the match

## Things to note
* The SignalR service and the function app will spin down when not in use. That may mean you see delays an timeouts on first use or after idling for a while.
* While the app is running, is actually listening for broadcasts of additional logins, you should see those pretty quickly
* Once in chat, you can type lines of text to send to the other player.
* If there are more than two instances, there may be multiple matches, but only 2 players per match
* To exit after entering chat, just hit enter (send an empty chat line)