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

### 2. Install Dependencies (Required)

This sample requires SDL2 and Dear ImGui which are installed via vcpkg. You **must** run this step before building.

**Option A: Using the setup script (Recommended)**

```powershell
# Navigate to the project directory
cd "C:\git\PlayFab.C\Samples\PlayFabGameSaveSample-Windows"

# Run the setup script (will automatically find Visual Studio's vcpkg)
.\setup_vcpkg.bat
```

**Option B: Manual installation**

```powershell
# Navigate to the project directory first (important for manifest mode)
cd "C:\git\PlayFab.C\Samples\PlayFabGameSaveSample-Windows"

# Use Visual Studio's built-in vcpkg in manifest mode
# Option 1: Use VSINSTALLDIR environment variable (recommended)
"%VSINSTALLDIR%\VC\vcpkg\vcpkg.exe" install --triplet x64-windows
"%VSINSTALLDIR%\VC\vcpkg\vcpkg.exe" integrate install

# Option 2: Use default VS 2022 Community path (if VSINSTALLDIR not set)
"C:\Program Files\Microsoft Visual Studio\2022\Community\VC\vcpkg\vcpkg.exe" install --triplet x64-windows
"C:\Program Files\Microsoft Visual Studio\2022\Community\VC\vcpkg\vcpkg.exe" integrate install

# Option 3: Use default VS 2022 Enterprise path
"C:\Program Files\Microsoft Visual Studio\2022\Enterprise\VC\vcpkg\vcpkg.exe" install --triplet x64-windows
"C:\Program Files\Microsoft Visual Studio\2022\Enterprise\VC\vcpkg\vcpkg.exe" integrate install
```

This will install the following packages into the `vcpkg_installed` folder:
- SDL2
- imgui with SDL2 and OpenGL3 backends

### 3. Build the Project

**Using Visual Studio**
1. Open `PlayFabGameSaveSample.sln` in Visual Studio
2. Select the x64 platform (Debug or Release)
3. Build the solution (Ctrl+Shift+B)

### 4. Configure PlayFab

The sample automatically loads PlayFab configuration from `testTitleData.json` if it exists. The sample searches for this file in these locations (in order):

1. `..\..\..\Test\testTitleData.json` (relative to executable - works when running from x64\Debug or x64\Release)
2. `..\..\Test\testTitleData.json`
3. `..\Test\testTitleData.json`
4. `testTitleData.json` (same directory as executable)
5. `C:\git\PlayFab.C\Test\testTitleData.json` (absolute fallback)

**If using the existing testTitleData.json:**

The repository includes a `Test\testTitleData.json` file that will be automatically loaded.

**If creating your own configuration:**

Create a `testTitleData.json` file with the following format:

```json
{
  "titleId": "YOURTITLEID",
  "connectionString": "https://YOURTITLEID.playfabapi.com"
}
```

Replace `YOURTITLEID` with your actual PlayFab Title ID from the [PlayFab Game Manager](https://developer.playfab.com/).

**If no testTitleData.json is found:**

The sample will use placeholder values (`YOURTITLEID`) and you'll see a warning in the log. You'll need to either:
- Create a `testTitleData.json` file, or
- Manually update the values in `GameSaveIntegration.cpp`

Additionally, ensure your PlayFab title has GameSave features enabled.

## Steam SDK Integration (Optional)

The Steam SDK integration is **optional** and disabled by default. The sample will compile and run without the Steam SDK - you will only be able to use Xbox Live authentication.

### Enabling Steam SDK Support

If you want to enable Steam functionality (including Steam Deck support), follow these steps:

#### 1. Download the Steamworks SDK

1. Download the Steamworks SDK from [Steamworks Partner Portal](https://partner.steamgames.com/doc/sdk)
2. Extract the SDK to a location on your system (e.g., `C:\steamworks_sdk`)

The expected folder structure should be:
```
C:\steamworks_sdk\
├── public\
│   └── steam\
│       ├── steam_api.h
│       ├── isteamutils.h
│       └── ...
├── redistributable_bin\
│   └── win64\
│       └── steam_api64.dll
└── ...
```

#### 2. Enable Steam SDK in the Project

You can enable Steam SDK support using one of the following methods:

**Method 1: Edit the .vcxproj file directly**

Open `PlayFabGameSaveSample.vcxproj` and change:
```xml
<EnableSteamSDK Condition="'$(EnableSteamSDK)'==''">false</EnableSteamSDK>
```
to:
```xml
<EnableSteamSDK Condition="'$(EnableSteamSDK)'==''">true</EnableSteamSDK>
```

**Method 2: Set MSBuild property via command line**

Build with the property set:
```powershell
msbuild PlayFabGameSaveSample.vcxproj /p:EnableSteamSDK=true /p:Configuration=Debug /p:Platform=x64
```

**Method 3: Set environment variable**

Set the environment variable before building:
```powershell
$env:EnableSteamSDK = "true"
```

#### 3. Configure the Steam SDK Path (if needed)

By default, the project expects the Steam SDK at `C:\steamworks_sdk`. If you extracted it elsewhere, update the `SteamworksSDKPath` property in the `.vcxproj` file:

```xml
<SteamworksSDKPath Condition="'$(SteamworksSDKPath)'==''">YOUR_PATH_HERE</SteamworksSDKPath>
```

Or set it via environment variable:
```powershell
$env:SteamworksSDKPath = "D:\SDKs\steamworks_sdk"
```

### What Steam SDK Enables

When `ENABLE_STEAM_SDK` is defined, the following features become available:
- **Sign In via Steam**: Authenticate users through Steam
- **Steam Deck Support**: Full Steam Deck integration including:
  - Xbox Remote Connect dialog for Xbox Live sign-in on Steam Deck
  - SPOP (Single Point of Presence) prompts for multi-device scenarios
  - Steam Deck detection and platform-specific behavior

Without Steam SDK, the sample works with Xbox Live authentication only.

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
- `SteamIntegration.cpp`: Steam-specific authentication handling (only when `ENABLE_STEAM_SDK` is defined)

This sample provides a production-ready foundation for implementing PlayFab GameSaves in your own games.

## Troubleshooting

### Error: Cannot open include file: 'SDL2/SDL.h'

```
error C1083: Cannot open include file: 'SDL2/SDL.h': No such file or directory
```

**Cause**: The vcpkg dependencies (SDL2, imgui) have not been installed.

**Solution**: Run the vcpkg installation as described in "Setup Instructions > Step 2":

```powershell
cd "C:\git\PlayFab.C\Samples\PlayFabGameSaveSample-Windows"
.\setup_vcpkg.bat
```

Or manually:
```powershell
"C:\Program Files\Microsoft Visual Studio\2022\Enterprise\VC\vcpkg\vcpkg.exe" install --triplet x64-windows
```

After installation, you should see a `vcpkg_installed\x64-windows\include\SDL2` folder containing the SDL2 headers.

### Error: Cannot open include file: 'steam/steam_api.h'

```
error C1083: Cannot open include file: 'steam/steam_api.h': No such file or directory
```

**Cause**: Steam SDK is enabled but the Steamworks SDK is not installed.

**Solution**: Either:
1. **Disable Steam SDK** (default): Ensure `EnableSteamSDK` is set to `false` in the `.vcxproj` file
2. **Install the Steamworks SDK**: See "Steam SDK Integration (Optional)" section above
