# PlayFab SpaceRumble Unity Sample
*This sample was created on Unity 2018.3.1f1*

### Description

This sample demonstrates a simple single-player mobile game that utilizes PlayFab for:
 - User Accounts
 - User Title Data
 - Title Data
 - Events that trigger CloudScript
 - Leaderboards
 
### Known Issues
 
There are no konwn issues.
 
### Building the Sample
 
**Build Requirements**
 - Unity 2018.3.1f1 or later
 - Visual Studio 2017 (Update 15.7) or later
 - Android/iOS device (for best experience)
  
### Using the Sample
  
**Requirements**
   
 - The project is configured to expect specific title configuration.  The title is pre-configured to use PlayFab Title ID "FACD" and as such should work out-of-the-box.  If you wish to adapt it to your own needs, please see the Configuration Section below.
   
**Basic Usage**
   
After proceeding past the welcome page, you will be prompted to sign in to PlayFab.  You can use an existing account, create a new one or sign in as a guest.  You may also choose to be remembered to avoid this dialog in the future.
   
After sign in, the Main Menu will give the option to Play, view the Leaderboards or adjust the Options.  The Options page lets you specify a custom user name as well as clearing out the saved sign in information.
   
Playing the game consists of flying around the space arena and destroying the enemy satellites as quickly as possible.  The game gathers several stats which are reflected in the leaderboards.

**Organization**

The scripts all exist in the `Assets\Scripts` folder.  This is further subdivided by Game scripts, PlayFab scripts and UI scripts.

### Configuration

This sample relies the following being configured in the PlayFab developer portal.

**Leaderboards**

The following Leaderboards are configured as **Manual** reset **Sum** statistics:
 - games_played
 - satellite_hit
 - satellites_destroyed
 - total_damage
 - total_round_time
 
**Title Data** 

The following Title Data values:
 - MOTD - A string Message of the Day
 
**User Title Data**

User Title Data values are dynamically created and updated from the client.

**Cloud Script**

The following cloud script is required:

```javascript
handlers.updateStatistic = function (args, context) {
  var event = context.playStreamEvent;

  if(event != null) {
    var request = {
      PlayFabId: currentPlayerId,
      Statistics: [{
        StatisticName: event.stat_name,
        Value: event.value
      }]
    };

    server.UpdatePlayerStatistics(request);
  }    
};

handlers.updateStatistics = function (args, context) {
  var event = context.playStreamEvent;

  if(event != null) {
    var stats = event.stats;
    var statArray = [];
    
    for(var key in stats) {
    	var value = stats[key];  
    	statArray.push({StatisticName: key, Value: value});
	}
    
    var request = {
      PlayFabId: currentPlayerId, 
      Statistics: statArray
    };
    
    server.UpdatePlayerStatistics(request);
  }    
};
```

***Automation Rules***

The following rules need to be created to link the client calls to the cloud script:

 - update_statstic: Custom Event, Execute Cloud Script, updateStatistic
 - update_statstics: Custom Event, Execute Cloud Script, updateStatistics
 
### UpdateHistory

 - Jan 2019, Initial release

### Privacy Statement

For more information about Microsoft’s privacy policies, see the [Microsoft Privacy Statement](https://privacy.microsoft.com/en-us/privacystatement/).
