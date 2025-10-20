# PlayFab GameSave Sample

This sample demonstrates how to integrate PlayFab GameSaves into your game, providing cross-platform cloud save functionality with automatic conflict resolution and device management.

## What You'll Learn

This sample covers the essential PlayFab GameSave integration patterns that every game developer needs to implement:

### Core Integration
- **Initialization**: Setting up PlayFab services and GameSave functionality
- **User Authentication**: Supporting both Xbox Live and Steam authentication flows
- **Local Save Management**: Creating, loading, and deleting local save files
- **Cloud Synchronization**: Uploading saves to the cloud with UI feedback

### Conflict Resolution
PlayFab GameSaves automatically handles common multi-device scenarios:
- **Active Device Contention**: When a user is active on multiple devices simultaneously
- **Save Conflicts**: When local and cloud saves differ and user input is needed
- **Device Switching**: Seamless transitions when players move between devices

### Error Handling
- **Sync Failures**: Network issues, authentication problems, and retry logic
- **Storage Limits**: Handling out-of-storage scenarios with user-friendly dialogs
- **Offline Mode**: Graceful degradation when cloud services are unavailable

### UI Integration
The sample includes complete UI implementations for:
- Progress dialogs during sync operations
- Conflict resolution dialogs with save metadata comparison
- Error dialogs with appropriate user actions
- Device contention warnings and resolution options

**Note**: The UI implementations in this sample are designed for demonstration and reference purposes only. They do not include production-ready features such as localization, DPI scaling, resolution independence, accessibility support, or platform-specific styling. These dialogs should serve as a reference for understanding the required user interactions and data flow, but you should implement your own game-appropriate UI using your game's existing UI framework and design standards.

## Key Features Demonstrated

### Multi-Platform Support
- **Windows**: Native Xbox Live integration
- **Steam Deck**: Xbox Live authentication through Steam's XUser implementation
- **Steam**: Steam-specific authentication flows

### Save Data Management
- Local save file operations in platform-appropriate directories
- Automatic cloud backup and restore
- Save metadata tracking (device, timestamp, size)
- Quota management and storage monitoring

### User Experience
- Non-blocking sync operations with progress feedback
- Clear conflict resolution with visual save comparison
- Graceful error handling with actionable user options
- Seamless device switching notifications

## Setup Instructions

### 1. Install Visual Studio 2022

Make sure you have Visual Studio 2022 with the **Desktop development with C++** workload installed. This includes vcpkg automatically.

### 2. Install Dependencies (Automated)

The easiest way is to run the provided setup script:

```powershell
# Navigate to the project directory
cd "c:\git\PlayFabGameSaves\samples\PlayFabGameSaveSample-Windows"

# Run the setup script (will automatically find Visual Studio's vcpkg)
setup_vcpkg.bat
```

### 3. Manual Installation (Alternative)

If you prefer to install dependencies manually:

```powershell
# Navigate to the project directory first (important for manifest mode)
cd "c:\git\PlayFabGameSaves\samples\PlayFabGameSaveSample-Windows"

# Use Visual Studio's built-in vcpkg in manifest mode
# Option 1: Use VSINSTALLDIR environment variable (recommended)
"%VSINSTALLDIR%VC\vcpkg\vcpkg.exe" install --triplet x64-windows
"%VSINSTALLDIR%VC\vcpkg\vcpkg.exe" integrate install

# Option 2: Use default VS 2022 Community path (if VSINSTALLDIR not set)
# "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\vcpkg\vcpkg.exe" install --triplet x64-windows
# "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\vcpkg\vcpkg.exe" integrate install
```

### 4. Open the Project
There is no solution (.sln) file in this sample. Open the project file directly:
1. In Visual Studio select: File > Open > Project/Solution...
2. Choose `PlayFabGameSaveSample.vcxproj` in this folder.
3. Visual Studio will generate a temporary solution hosting this project.

(Alternatively you can double-click `PlayFabGameSaveSample.vcxproj` in Explorer to open it.)

### 5. Build the Project
1. Ensure the platform is set to `x64` (Debug or Release).
2. Build (Ctrl+Shift+B).

### 6. Configure PlayFab

Before running the sample, you'll need to configure your PlayFab title:
1. Update the PlayFab API endpoint and Title ID in `GameSaveIntegration.cpp`
2. Ensure your PlayFab title has GameSave features enabled

### 7. Configure Steamworks SDK Path
The project expects the Steamworks SDK to be available for Steam / Steam Deck authentication scenarios.

The Visual C++ project defines a user macro in the *.vcxproj* file:
```
<PropertyGroup Label="UserMacros">
  <SteamworksSDKPath Condition="'$(SteamworksSDKPath)'==''">C:\steamworks_sdk</SteamworksSDKPath>
</PropertyGroup>
```
If your Steamworks SDK is not located at `C:\steamworks_sdk`, do ONE of the following:
- Set an environment variable `SteamworksSDKPath` pointing to the root of your extracted Steamworks SDK before launching Visual Studio.
- OR edit `PlayFabGameSaveSample.vcxproj` and change the value of `<SteamworksSDKPath>` under the `UserMacros` group.

Required subfolders used by the build:
- Headers: `$(SteamworksSDKPath)\public`
- Libraries / DLL copy: `$(SteamworksSDKPath)\redistributable_bin\win64`
- Encrypted app ticket DLL: `$(SteamworksSDKPath)\public\steam\lib\win64`

During the post-build step the following DLLs are copied into the output directory:
- `steam_api64.dll`
- `sdkencryptedappticket64.dll`

Make sure these files exist in your SDK installation; otherwise adjust the path or update to a current Steamworks SDK.

## Implementation Guide

### Essential Code Patterns

**1. Initialize PlayFab GameSaves**
```cpp
RETURN_IF_FAILED(PFGameSaveFilesInitialize(&gsargs));
```

**2. Set up UI Callbacks optionally**
```cpp
PFGameSaveUICallbacks callbacks{};
callbacks.progressCallback = OnPFGameSaveFilesUiProgress;
callbacks.syncFailedCallback = OnPFGameSaveFilesUiSyncFailed;
callbacks.activeDeviceContentionCallback = OnPFGameSaveFilesUiActiveDeviceContention;
callbacks.conflictCallback = OnPFGameSaveFilesUiConflict;
callbacks.outOfStorageCallback = OnPFGameSaveFilesUiOutOfStorage;
RETURN_IF_FAILED(PFGameSaveFilesSetUiCallbacks(&callbacks));
```

**3. Add User to GameSaves**
```cpp
RETURN_IF_FAILED(PFGameSaveFilesAddUserWithUiAsync(localUserHandle, options, &async));
PFGameSaveFilesGetFolder(g_gameState.localUserHandle, MAX_PATH, saveFolder, nullptr);
```

**4. Read and Write Local Saves as normal in game**
Use standard file I/O operations to read and write local save files. The PlayFab GameSave system will handle synchronization with the cloud.

**5. Upload Saves to Cloud**
```cpp
RETURN_IF_FAILED(PFGameSaveFilesUploadWithUiAsync(localUserHandle, uploadOption, &async));
```

### Key Files to Study

- `GameSaveIntegration.cpp`: Core PlayFab GameSave implementation
- `GameSaveIntegrationUI.cpp`: Complete UI dialog implementations
- `SteamIntegration.cpp`: Steam-specific authentication handling
- `XUserFileStorage.cpp`: Platform-specific file storage logic for XUser on Steam Deck

This sample provides a production-ready foundation for implementing PlayFab GameSaves in your own games.
