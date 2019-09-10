//--------------------------------------------------------------------------------------
// PlayfabStorage.h
//
// Advanced Technology Group (ATG)
// Copyright (C) Microsoft Corporation. All rights reserved.
//--------------------------------------------------------------------------------------

#pragma once

#include "DeviceResources.h"
#include "StepTimer.h"

#include "SampleGUI.h"
#include "LiveResourcesXDK.h"
#include "ListView.h"
#include "LiveInfoHUD.h"
#include "HttpCall.h"

#include "PlayFabResourcesXDK.h"
#include "playfab/PlayFabClientDataModels.h"
#include "playfab/PlayFabClientApi.h"
#include "playfab/PlayFabEntityDataModels.h"
#include "playfab/PlayFabEntityApi.h"
#include "playfab/PlayFabSettings.h"

struct FileInfo
{
	std::string Name;
	std::string UrlData;
	time_t		LastModified;
	int			Size;

	FileInfo(std::string Name, time_t LastModified, int Size):
		Name(Name), LastModified(LastModified), Size(Size)
	{}

	FileInfo(PlayFab::EntityModels::GetFileMetadata metadata):
		Name(metadata.FileName), UrlData(metadata.DownloadUrl), LastModified(metadata.LastModified), Size(metadata.Size)
	{}
};

// Helper class for displaying the list of files in Title Storage
class PlayfabStorageViewRow
{
public:
    void Show();
    void Hide();
    void SetControls(ATG::IPanel *parent, int rowStart);
    void Update(const FileInfo &item);
    void SetSelectedCallback(ATG::IControl::callback_t callback);
private:
    ATG::Button    *m_selectBtn;
    ATG::TextLabel *m_fileName;
    ATG::TextLabel *m_size;
	ATG::TextLabel *m_dateModified;
};

// A basic sample implementation that creates a D3D11 device and
// provides a render loop.
class Sample
{
public:

    Sample();

    // Initialization and management
    void Initialize(IUnknown* window);

    // Basic game loop
    void Tick();

    // Messages
    void OnSuspending();
    void OnResuming();

	enum StorageType
	{
		Asset,
		EntityData
	};

    // Storage calls
    void ChangeStorageType(StorageType type);
	void GetUrlAndDownloadBlob(std::string filename);
	void DownloadBlob(std::string url);
	void DeleteBlob(std::string filename);
	void UploadEntityBlob(std::string filename, std::string buffer);

    void ShowNoticePopUp(const wchar_t *noticeType, const wchar_t *message);
    void ShowFileOptions(void *blob, bool canDelete);
	void ShowFileUploadOptions(bool canBinary);

private:

    void Update(DX::StepTimer const& timer);
    void Render();

    void Clear();

    void CreateDeviceDependentResources();
    void CreateWindowSizeDependentResources();

    void SetupUI();

    // Device resources.
    std::unique_ptr<DX::DeviceResources>				m_deviceResources;

    // Rendering loop timer.
    uint64_t											m_frame;
    DX::StepTimer										m_timer;

    // Input devices.
    std::unique_ptr<DirectX::GamePad>					m_gamePad;
	DirectX::GamePad::ButtonStateTracker				m_gamePadButtons;

    // DirectXTK objects.
    std::unique_ptr<DirectX::GraphicsMemory>			m_graphicsMemory;

	// PlayFab objects.
	std::shared_ptr<ATG::PlayFabResources>				m_playFabResources;
	PlayFab::EntityModels::GetEntityTokenResponse		m_entityTokenResult;

	// Xbox Live objects
    std::shared_ptr<ATG::LiveResources>					m_liveResources;
    std::unique_ptr<ATG::LiveInfoHUD>					m_liveInfoHUD;
	std::unique_ptr<ATG::HttpCallManager>				m_httpCallManager;

    // UI Objects
    std::shared_ptr<ATG::UIManager>						m_ui;
    std::unique_ptr<ListView<FileInfo, PlayfabStorageViewRow>> m_listView;
	StorageType											m_selectedStorageType;

	// File info
	std::vector<FileInfo>								m_assetFileList;
	std::vector<FileInfo>								m_currentFileList;

	Platform::Agile<Windows::UI::Core::CoreWindow>		m_window;
};
