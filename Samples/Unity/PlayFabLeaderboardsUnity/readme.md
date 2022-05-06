# PlayFab Leaderboards Unity Sample
This sample was created with Unity 2018.3

### Description

This sample demonstrates reading and writing from/to leaderboards from within a Unity title. The sample covers lowest score/best time, high score and cumulative score leaderboards.

### Known Issues

There are no known issues.

### Building the Sample

**Build Requirements**

* Unity 2018.3 or later
* Visual Studio 2017 (15.7 update) or later

**PlayFab Configuration**

* Create the 'best_time' leaderboard
  * __Statistic Name:__ best_time
  * __Reset Frequency:__ Manually
  * __Aggregation Method:__ Minimum
* Create the 'high_score' leaderboard
  * __Statistic Name:__ high_score
  * __Reset Frequency:__ Manually
  * __Aggregation Method:__ Maximum
* Create the 'total_score' leaderboard
  * __Statistic Name:__ total_score
  * __Reset Frequency:__ Manually
  * __Aggregation Method:__ Sum
* Copy the contents of 'cloudscript.js' to your cloud script
* The following rule needs to be created to link the client calls to the cloud script
  * __Name:__ update_statistic
  * __Event type:__ Custom Event - update_statistic
  * __Action:__ Execute Cloud Script
  * __Cloud Script Function:__ updateStatistic

 ### Using the Sample
 
**Requirements**
* PlayFab title (created on PlayFab.com)
  * Title must be configured correctly (see PlayFab Configuration above)
* Initial Setup
  * Update PlayFabSharedSettings.asset to replace the TitleID value with your title ID.

**Using the Sample**

* Use the left and right arrows to switch leaderboards
* Enter a numeric value in the Value box and press any of the post buttons to post that value as the relevant score type
* Press Refresh to retrieve the latest leaderboard data
  * Switching leaderboards will also refresh the data.

### Update History

* January 14, 2019
  * Initial release
 
### Privacy Statement

For more information about Microsoft’s privacy policies in general, see the [Microsoft Privacy Statement](https://privacy.microsoft.com/en-us/privacystatement/).
