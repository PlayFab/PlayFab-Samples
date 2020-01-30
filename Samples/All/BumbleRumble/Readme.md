# PlayFab Party Sample - BumbleRumble

### Description

This sample demonstrates usage of PlayFab Party for Networking and Accessible Voice Chat as well as PlayFab Matchmaking.  Accessible Voice Chat includes full Speech-To-Text and Text-To-Speech capabilities.

PlayFab Party: https://docs.microsoft.com/en-us/gaming/playfab/features/multiplayer/networking/

PlayFab Matchmaking: https://docs.microsoft.com/en-us/gaming/playfab/features/multiplayer/matchmaking/

### Known Issues
 
There are no known issues.
 
### Building the Sample
 
**Build Requirements**
 - Visual Studio 2017 (Update 15.7) or later
 - Windows Desktop
   - Legacy DirectX SDK (June 2010)
     - https://www.microsoft.com/en-us/download/details.aspx?id=6812
 - Xbox One
   - July 2018 QFE 5 XDK (Xbox One)
     - https://developer.microsoft.com/en-us/games/xbox/partner/resources-softwaredownloads
  
This sample depends on some external and third-party open source libraries referenced as git submodules in directory `/External`. Please make sure to use `--recurse-submodules` command line parameter when cloning the git repo:
```
git clone --recurse-submodules <git-repo-url>
```
or run the following commands to sync the content of submodules if the repo was cloned earlier without the `--recurse-submodules` parameter:

```
git submodule update --init --recursive
```

**Config Requirements**
   
 The project is configured to expect specific PlayFab Title configuration.  The sample is pre-configured to work as-is but if you wish to adapt it to your own title, you will need to update the PlayFab Title ID that is specified in `config.cpp`
```
    const char* c_pfTitleId = "86E2";
```    
   
### Using the Sample

To debug the sample through Visual Studio on Windows, you will need to set your Working Directory in the Debug options of the project to `$(SolutionDir)\GameLayout`

Once you progress past the welcome screen, you will be signed in to PlayFab and taken to the main menu.

Selecting 'Play a Game' from the menu will begin matchmaking and attempt to find other players. If a match can be made, the matched players will be create and join a PlayFab Party network and enable voice chat with full transcriptions.

At this point all users' voice chat will be transcripted to text and displayed.  Pressing the `TAB` key or `View` button will bring up a simple text input box which will allow entry of text to be transcribed to voice.

There are quick text-only messages assigned to ALT-1 through ALT-4 or the D-Pad directions.

Speech-to-Text and Text-to-Speech are enabled and used by default.  The language setting can be changed in the `Options` menu.

### PlayFab Configuration

This sample requires the title be configured for Matchmaking and Party on the Multiplayer tab of Game Manager and relies on the following settings being configured in the PlayFab developer portal.

**Matchmaking Queue**

The sample expects a Matchmaking Queue named `nr_simple`.  This queue can have any rules you'd like, but at a minimun it is recommended to have your queue match 2-8 players.

**Cloud Script**

The following cloud script is required:

```javascript
handlers.set_game_network = function (args, context) {
  try {
    server.CreateSharedGroup({ SharedGroupId: args["entity"].Id });
  } catch(err) {
    log.info("Shared group " + args["entity"].Id + " already exists.");
    log.error(err);
  }

  var updateRequest = {
    SharedGroupId: args["entity"].Id,
    Data: {
      "network": args["network"],
      "invite": args["invite"]
    }
  };

  server.UpdateSharedGroupData(updateRequest);
};

handlers.get_game_network = function (args, context) {
  try {
    var getRes = server.GetSharedGroupData({ SharedGroupId: args["entity"].Id });
    return getRes.Data;
  } catch(err) {
    return;
  }
};

handlers.clear_game_network = function (args, context) {
  try {
    var updateRequest = {
      SharedGroupId: args["entity"].Id,
      KeysToRemove: [ "network", "invite" ]
    };

    server.UpdateSharedGroupData(updateRequest);
  } catch(err) {
  }
};
```
 
### Update History

 - Apr 2019, Initial release

### Privacy Statement

For more information about Microsoft’s privacy policies, see the [Microsoft Privacy Statement](https://privacy.microsoft.com/en-us/privacystatement/).
