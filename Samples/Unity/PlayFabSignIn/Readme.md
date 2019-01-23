# PlayFab Sign In for Unity Sample

*This sample was created on Unity 2018.3*

### Description

This sample demonstrates a simple PlayFab sign in flow.  You may log in with an email/password, create an account or log in as a guest.  Sign in info may be remembered across executions of the sample.
 
### Known Issues
 
There are no known issues.
 
### Building the Sample
 
**Build Requirements**
 - Unity 2018.3 or later
 - Visual Studio 2017 (Update 15.7) or later
 - Android/iOS device (for best experience)
  
### Using the Sample
  
**Requirements**
   
 - The project requires a valid PlayFab Title Id.  This can be configured with the PlayFab Editor Extensions for Unity or by specifying it in the `Assets/PlayFabSdk/Shared/Public/Resources/PlayFabSharedSettings.asset` properties.
   
**Basic Usage**
   
Upon launching, you will be prompted to sign in to PlayFab.  You can use an existing account, create a new one or sign in as a guest.  You may also choose to be remembered to avoid this dialog in the future.
   
After sign in, you can choose to clear sign in and start again and/or clear any remembered login settings.

**Organization**

The scripts all exist in the `Assets\Scripts` folder.  This is further subdivided by `PlayFab` scripts and `UI` scripts.

### Update History

 - Jan 2019, Initial release

### Privacy Statement

For more information about Microsoft’s privacy policies, see the [Microsoft Privacy Statement](https://privacy.microsoft.com/en-us/privacystatement/).
