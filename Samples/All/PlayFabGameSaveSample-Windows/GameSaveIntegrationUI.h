#pragma once

struct RemoteConnectDialogState
{
    bool showDialog = false;
    std::string url;
    std::string code;
    uint32_t userIdentifier = 0;
};

struct SyncProgressDialogState
{
    bool showDialog = false;
    PFLocalUserHandle localUserHandle = nullptr;
    PFGameSaveFilesSyncState syncState = PFGameSaveFilesSyncState::NotStarted;
    uint64_t currentBytes = 0;
    uint64_t totalBytes = 0;
    bool isDownloading = false;
};

struct SyncFailedDialogState
{
    bool showDialog = false;
    PFLocalUserHandle localUserHandle = nullptr;
    HRESULT errorCode = S_OK;
};

struct ActiveDeviceContentionDialogState
{
    bool showDialog = false;
    PFLocalUserHandle localUserHandle = nullptr;
    PFGameSaveDescriptor localGameSave = {};
    PFGameSaveDescriptor remoteGameSave = {};
};

struct ConflictDialogState
{
    bool showDialog = false;
    PFLocalUserHandle localUserHandle = nullptr;
    PFGameSaveDescriptor localGameSave = {};
    PFGameSaveDescriptor remoteGameSave = {};
    std::string localThumbnailUri;
    std::string remoteThumbnailUri;
    uint32_t localThumbnailTextureId = 0;
    uint32_t remoteThumbnailTextureId = 0;
    float localThumbnailWidth = 0.0f;
    float localThumbnailHeight = 0.0f;
    float remoteThumbnailWidth = 0.0f;
    float remoteThumbnailHeight = 0.0f;
    bool localThumbnailLoadAttempted = false;
    bool remoteThumbnailLoadAttempted = false;
};

struct OutOfStorageDialogState
{
    bool showDialog = false;
    PFLocalUserHandle localUserHandle = nullptr;
    uint64_t requiredBytes = 0;
};

struct ActiveDeviceChangedDialogState
{
    bool showDialog = false;
    PFLocalUserHandle localUserHandle = nullptr;
    PFGameSaveDescriptor activeDevice = {};
};

struct CloudDataConfirmationDialogState
{
    bool showDialog = false;
    PFLocalUserHandle localUserHandle = nullptr;
    PFGameSaveDescriptor remoteGameSave = {};
};

struct SpopPromptDialogState
{
    bool showDialog = false;
    uint32_t userIdentifier = 0;
    XUserPlatformOperation operation = nullptr;
    std::string modernGamertag;
    std::string modernGamertagSuffix;
};

// Note: Dialog states are part of the global GameState struct

#ifdef ENABLE_STEAM_SDK
// Remote connection UI for XUser on Steam Deck
void ShowRemoteConnectDialogForXUserOnSteamDeck(const std::string& url, const std::string& code, uint32_t userIdentifier);
void RenderRemoteConnectDialogForXUserOnSteamDeck();
void CloseRemoteConnectDialogForXUserOnSteamDeck();
#endif

// Sync progress dialog functions
void ShowSyncProgressDialog(PFLocalUserHandle localUserHandle, PFGameSaveFilesSyncState syncState, uint64_t currentBytes, uint64_t totalBytes);
void RenderSyncProgressDialog();
void CloseSyncProgressDialog();

// Sync failed dialog functions
void ShowSyncFailedDialog(PFLocalUserHandle localUserHandle, HRESULT errorCode);
void RenderSyncFailedDialog();
void CloseSyncFailedDialog();

// Active device contention dialog functions
void ShowActiveDeviceContentionDialog(PFLocalUserHandle localUserHandle, PFGameSaveDescriptor* localGameSave, PFGameSaveDescriptor* remoteGameSave);
void RenderActiveDeviceContentionDialog();
void CloseActiveDeviceContentionDialog();

// Conflict dialog functions
void ShowConflictDialog(PFLocalUserHandle localUserHandle, PFGameSaveDescriptor* localGameSave, PFGameSaveDescriptor* remoteGameSave);
void RenderConflictDialog();
void CloseConflictDialog();

// Out of storage dialog functions
void ShowOutOfStorageDialog(PFLocalUserHandle localUserHandle, uint64_t requiredBytes);
void RenderOutOfStorageDialog();
void CloseOutOfStorageDialog();

// Cloud data confirmation dialog functions
void ShowCloudDataConfirmationDialog(PFLocalUserHandle localUserHandle, PFGameSaveDescriptor* remoteGameSave);
void RenderCloudDataConfirmationDialog();
void CloseCloudDataConfirmationDialog();

#ifdef ENABLE_STEAM_SDK
// SPOP prompt UI for XUser on Steam Deck
void ShowSpopPromptDialogForXUserOnSteamDeck(uint32_t userIdentifier, XUserPlatformOperation* operation, const std::string& modernGamertag, const std::string& modernGamertagSuffix);
void RenderSpopPromptDialogForXUserOnSteamDeck();
void CloseSpopPromptDialogForXUserOnSteamDeck();
#endif

