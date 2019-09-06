//--------------------------------------------------------------------------------------
// PlayfabStorage.cpp
//
// Advanced Technology Group (ATG)
// Copyright (C) Microsoft Corporation. All rights reserved.
//--------------------------------------------------------------------------------------

#include "pch.h"
#include "PlayfabStorage.h"
#include "ATGColors.h"

extern void ExitSample();

using namespace DirectX;
using namespace PlayFab;
using namespace ClientModels;
using namespace EntityModels;

using Microsoft::WRL::ComPtr;

namespace
{
    const int c_sampleUIPanel = 2000;
    const int c_noticePopUpPanel = 7000;
    const int c_fileOptionsPopUpPanel = 8000;
    const int c_uploadPopUpPanel = 9000;

    const int c_assetStorageCheckBox = 2201;
	const int c_entityStorageCheckBox = 2202;

    void WrapString(std::wstring &string, size_t lineWidth)
    {
        if(string.find(L'\n') != std::wstring::npos)
            return;

        for (size_t line = lineWidth; line < string.length(); line += lineWidth)
        {
            string.insert(line,L"\n");
        }
    }
}

Sample::Sample() :
    m_frame(0)
{
	//Assets are preloaded on the server, so hard coding what is there
	time_t originalTime;
	struct tm timeBufferStruct;
	localtime_s(&timeBufferStruct, &originalTime);
	timeBufferStruct.tm_year = 118;
	timeBufferStruct.tm_mon = 4;
	timeBufferStruct.tm_mday = 7;
	originalTime = mktime(&timeBufferStruct);

	m_assetFileList.emplace_back(FileInfo("test.dat", originalTime, 22));
	m_assetFileList.emplace_back(FileInfo("test.txt", originalTime, 15));
	
m_httpCallManager = std::make_unique<ATG::HttpCallManager>();
	m_deviceResources = std::make_unique<DX::DeviceResources>(DXGI_FORMAT_B8G8R8A8_UNORM, DXGI_FORMAT_UNKNOWN);
    m_liveResources = std::make_shared<ATG::LiveResources>();
    m_liveInfoHUD = std::make_unique<ATG::LiveInfoHUD>(L"Title Storage Sample");

    ATG::UIConfig uiconfig;
    m_ui = std::make_shared<ATG::UIManager>(uiconfig);
}

// Initialize the Direct3D resources required to run.
void Sample::Initialize(IUnknown* window)
{
	m_window = Windows::UI::Core::CoreWindow::GetForCurrentThread();

	m_gamePad = std::make_unique<GamePad>();

	m_ui->LoadLayout(L".\\Assets\\SampleUI.csv", L".\\Assets");

	m_liveResources->Initialize();

	m_deviceResources->SetWindow(window);

	m_deviceResources->CreateDeviceResources();
	CreateDeviceDependentResources();

	m_deviceResources->CreateWindowSizeDependentResources();
	CreateWindowSizeDependentResources();

	m_playFabResources = std::make_shared<ATG::PlayFabResources>(L"DC0");

	//Get PlayFab entity token
	m_playFabResources->SetPlayFabUserChangedCallback([this](PlayFab::ClientModels::LoginResult loginResult)
    {
		GetEntityTokenRequest tokenRequest;
		PlayFabEntityAPI::GetEntityToken(tokenRequest,
			[this](const GetEntityTokenResponse& result, void*)
		{
			// a mutex is needed if PlayFabSettings::threadedCallbacks == true
			m_entityTokenResult = result;
			OutputDebugString(L"PlayFab entity token successful\n");
			
			//Set the default to asset
			ChangeStorageType(StorageType::Asset);
		}
			, [this](const PlayFab::PlayFabError& error, void*)
		{
			OutputDebugString(L"There was a problem getting an entity token from PlayFab\n");
			OutputDebugStringA(error.ErrorMessage.c_str());
			OutputDebugStringA(error.HttpStatus.c_str());

			switch (error.ErrorCode)
			{
			case PlayFabErrorCode::PlayFabErrorEntityTokenExpired:
				OutputDebugString(L"Token has expired.\n");
				break;
			case PlayFabErrorCode::PlayFabErrorEntityTokenInvalid:
				OutputDebugString(L"Token is invalid.\n");
				break;
			case PlayFabErrorCode::PlayFabErrorEntityTokenRevoked:
				OutputDebugString(L"Token has been revoked.\n");
				break;
			case PlayFabErrorCode::PlayFabErrorNotAuthenticated:
				OutputDebugString(L"No auth.\n");
				break;
			default:
				OutputDebugString(L"Unknown PlayFab error.\n");
			}

			ShowNoticePopUp(L"Error", L"There was a problem getting an entity token from PlayFab");
		});
	});

    m_liveResources->SetUserChangedCallback([this](ATG::XboxLiveUser user)
    {
        m_liveInfoHUD->SetUser(m_liveResources->GetLiveContext());
		m_ui->FindPanel<ATG::IPanel>(c_sampleUIPanel)->Show();
    });

    m_liveResources->SetUserSignOutCompletedCallback([this](ATG::XboxLiveUser user)
    {
        m_liveInfoHUD->SetUser(m_liveResources->GetLiveContext());
		m_ui->FindPanel<ATG::IPanel>(c_sampleUIPanel)->Close();
    });

    m_liveResources->Initialize();
    m_liveInfoHUD->Initialize(m_liveResources->GetLiveContext());
	m_playFabResources->Initialize();

    SetupUI();
}

#pragma region UI Methods
void Sample::SetupUI()
{
    using namespace ATG;

    ListViewConfig config = { 10, 3100, 100, c_sampleUIPanel };
    m_listView = std::make_unique<ListView<FileInfo, PlayfabStorageViewRow>>(m_ui, config);
    m_listView->ClearAllRows();

    // When the ListItem is selected, show the File Option Popup
    m_listView->SetSelectedCallback([this](ATG::IPanel *, ATG::IControl *control)
    {
        auto storageMetadata = reinterpret_cast<FileInfo*>(control->GetUser());
        ShowFileOptions(storageMetadata, m_selectedStorageType != StorageType::Asset);
    });
    // File Option to download selected file
    m_ui->FindControl<ATG::Button>(c_fileOptionsPopUpPanel, 8001)->SetCallback([this](ATG::IPanel *, ATG::IControl *control)
    {
        auto address = reinterpret_cast<FileInfo*>(control->GetUser());
        
		if (address->UrlData.length() == 0)
		{
			GetUrlAndDownloadBlob(address->Name);
		}
		else
		{
			DownloadBlob(address->UrlData);
		}
    });
    // File Option to delete selected file
    m_ui->FindControl<ATG::Button>(c_fileOptionsPopUpPanel, 8002)->SetCallback([this](ATG::IPanel *, ATG::IControl *control)
    {
		auto filename = reinterpret_cast<std::string*>(control->GetUser());
        DeleteBlob(*filename);
    });

    // Upload button selected
    m_ui->FindControl<ATG::Button>(c_sampleUIPanel, 2206)->SetCallback([this](ATG::IPanel *, ATG::IControl *)
    {
        bool canUploadBinary = m_selectedStorageType != StorageType::Asset;
        auto button = m_ui->FindControl<ATG::Button>(c_uploadPopUpPanel, 9002);
        button->SetEnabled(canUploadBinary);

		ShowFileUploadOptions(m_selectedStorageType == StorageType::EntityData);
    });
    // Upload the JSON blob
    m_ui->FindControl<ATG::Button>(c_uploadPopUpPanel, 9001)->SetCallback([this](ATG::IPanel *, ATG::IControl *)
    {
		UploadEntityBlob(std::string("EntityStorageBlob.json"),
			std::string("{\n\"isThisJson\": 1,\n\"monstersKilled\": 10,\n\"playerClass\": \"warrior\"\n}"));

		ChangeStorageType(StorageType::EntityData);
	});
    // Upload the binary blob
    m_ui->FindControl<ATG::Button>(c_uploadPopUpPanel, 9002)->SetCallback([this](ATG::IPanel *, ATG::IControl *)
    {
		UploadEntityBlob(std::string("EntityStorageBlob.dat"),
                   std::string("This is a entity storage test."));
	
		ChangeStorageType(StorageType::EntityData);
	});

    // Storage Location options
    m_ui->FindControl<ATG::CheckBox>(c_sampleUIPanel, c_assetStorageCheckBox)->SetCallback([this](ATG::IPanel *parent, ATG::IControl *)
    {
        dynamic_cast<ATG::CheckBox*>(parent->Find(c_assetStorageCheckBox))->SetChecked(true);
		dynamic_cast<ATG::CheckBox*>(parent->Find(c_entityStorageCheckBox))->SetChecked(false);

        ChangeStorageType(StorageType::Asset);
    });
	m_ui->FindControl<ATG::CheckBox>(c_sampleUIPanel, c_entityStorageCheckBox)->SetCallback([this](ATG::IPanel *parent, ATG::IControl *)
	{
		dynamic_cast<ATG::CheckBox*>(parent->Find(c_assetStorageCheckBox))->SetChecked(false);
		dynamic_cast<ATG::CheckBox*>(parent->Find(c_entityStorageCheckBox))->SetChecked(true);

		ChangeStorageType(StorageType::EntityData);
	});
}

void Sample::ShowNoticePopUp(const wchar_t *title, const wchar_t *message)
{
	std::wstring titleCapture = title, messageCapture = message;

	auto uiUpdate = [this, titleCapture, messageCapture]() {
		m_ui->FindControl<ATG::TextLabel>(c_noticePopUpPanel, 7001)->SetText(titleCapture.c_str());
		m_ui->FindControl<ATG::TextLabel>(c_noticePopUpPanel, 7002)->SetText(messageCapture.c_str());
		m_ui->FindPanel<ATG::IPanel>(c_noticePopUpPanel)->Show();
	};

	m_window->Dispatcher->RunAsync(Windows::UI::Core::CoreDispatcherPriority::Normal, ref new Windows::UI::Core::DispatchedHandler(uiUpdate));
}

void Sample::ShowFileOptions(void *blob, bool canDelete)
{
    m_ui->FindControl<ATG::Button>(c_fileOptionsPopUpPanel,8001)->SetUser(blob);
    auto deleteBtn = m_ui->FindControl<ATG::Button>(c_fileOptionsPopUpPanel, 8002);
    deleteBtn->SetEnabled(canDelete);
    deleteBtn->SetUser(blob);
    m_ui->FindPanel<ATG::IPanel>(c_fileOptionsPopUpPanel)->Show();
}

void Sample::ShowFileUploadOptions(bool canBinary)
{
	auto binaryBtn = m_ui->FindControl<ATG::Button>(c_uploadPopUpPanel, 9002);
	binaryBtn->SetEnabled(canBinary);
	m_ui->FindPanel<ATG::IPanel>(c_uploadPopUpPanel)->Show();
}
#pragma endregion

#pragma region Title Storage
void Sample::ChangeStorageType(StorageType type)
{
    m_selectedStorageType = type;

	switch (type)
	{
	case StorageType::Asset:
		m_currentFileList = m_assetFileList;
		m_listView->UpdateRows(m_currentFileList);
		break;
	case StorageType::EntityData:
	{
		GetFilesRequest fileRequest;
		fileRequest.Entity = m_entityTokenResult.Entity;

		//Get file list associated with the entity
		PlayFabEntityAPI::GetFiles(fileRequest,
			[this](const GetFilesResponse& result, void*)
		{
			// a mutex is needed if PlayFabSettings::threadedCallbacks == true
			OutputDebugString(L"PlayFab entity files found successfully\n");
			
			m_currentFileList.clear();

			for (auto file : result.Metadata)
			{
				m_currentFileList.emplace_back(FileInfo(file.second));
			}

			m_listView->UpdateRows(m_currentFileList);
		}
			, [this](const PlayFab::PlayFabError& error, void*)
		{
			m_listView->ClearAllRows();
			OutputDebugString(L"There was a problem getting entity files from PlayFab\n");
			OutputDebugStringA(error.ErrorMessage.c_str());
			OutputDebugStringA(error.HttpStatus.c_str());

			ShowNoticePopUp(L"Error", L"There was a problem getting an entity files from PlayFab");
		});
	}
		break;
	}

    m_ui->FindControl<ATG::Button>(c_sampleUIPanel, 2206)->SetEnabled(type != StorageType::Asset);
}

// Pulls data out of the blob metadata for display
void PlayfabStorageViewRow::Update(const FileInfo &item)
{
	char tempString[26];
	ctime_s(tempString, 26, &item.LastModified);
	std::string timeString(tempString);

	// Extract information from the blob metadata for display
    m_fileName->SetText(std::wstring(item.Name.begin(), item.Name.end()).c_str());
    m_size->SetText(std::to_wstring((int)item.Size).c_str());
	m_dateModified->SetText(std::wstring(timeString.begin(), timeString.end()).c_str());

	// Save the current blob for easier access then selection action is triggered
    m_selectBtn->SetUser(reinterpret_cast<void*>(&const_cast<FileInfo&>(item)));
}

void Sample::GetUrlAndDownloadBlob(std::string filename)
{
	GetContentDownloadUrlRequest downloadRequest;
	downloadRequest.Key = filename;

	//Get the URL for asset download
	PlayFabClientAPI::GetContentDownloadUrl(downloadRequest,
		[this](const GetContentDownloadUrlResult& result, void*)
	{
		// a mutex is needed if PlayFabSettings::threadedCallbacks == true
		OutputDebugString(L"PlayFab download URL successfully acquired\n");

		DownloadBlob(result.URL);
	}
		, [this](const PlayFab::PlayFabError& error, void*)
	{
		OutputDebugString(L"There was a problem getting a download url from PlayFab\n");
		OutputDebugStringA(error.ErrorMessage.c_str());
		OutputDebugStringA(error.HttpStatus.c_str());

		switch (error.ErrorCode)
		{
		case PlayFabErrorCode::PlayFabErrorEntityTokenExpired:
			OutputDebugString(L"Token has expired.\n");
			break;
		case PlayFabErrorCode::PlayFabErrorEntityTokenInvalid:
			OutputDebugString(L"Token is invalid.\n");
			break;
		case PlayFabErrorCode::PlayFabErrorEntityTokenRevoked:
			OutputDebugString(L"Token has been revoked.\n");
			break;
		case PlayFabErrorCode::PlayFabErrorNotAuthenticated:
			OutputDebugString(L"No auth.\n");
			break;
		default:
			OutputDebugString(L"Unknown PlayFab error.\n");
		}

		ShowNoticePopUp(L"Error", L"There was a problem getting a download url from PlayFab");
	});
}

// Downloads the specified blob in the selected storage type.
void Sample::DownloadBlob(std::string url)
{
	std::wstring uri(url.begin(), url.end());

	m_httpCallManager->MakeHttpCall(
		L"GET",
		uri.c_str(),
		std::vector<ATG::HttpHeader>(),
		[this](ATG::HttpResponse *response)
	{
		// Response body is a unsigned char array and it needs to become a wstring for parsing
		std::string body(reinterpret_cast<char *>(response->ResponseBody().get()), response->ResponseBodySize());
		std::wstring wbody(body.begin(), body.end());

		WrapString(wbody, 56);
		std::wstring noticeMessage = L"Downloaded Blob Contents:\n";
		noticeMessage.append(wbody);

		// Show popup with file contents
		ShowNoticePopUp(L"Download Result", noticeMessage.c_str());
	});
}

// Deletes the specified blob in the selected storage type.
void Sample::DeleteBlob(std::string filename)
{
	DeleteFilesRequest deleteRequest;
	deleteRequest.Entity = m_entityTokenResult.Entity;
	deleteRequest.FileNames.emplace_back(filename);

	PlayFabEntityAPI::DeleteFiles(deleteRequest,
		[this](const DeleteFilesResponse&, void*)
	{
		// a mutex is needed if PlayFabSettings::threadedCallbacks == true
		OutputDebugString(L"PlayFab file delete successful\n");
		ChangeStorageType(m_selectedStorageType);
	}
		, [this](const PlayFab::PlayFabError& error, void*)
	{
		OutputDebugString(L"There was a problem deleting files from PlayFab\n");
		OutputDebugStringA(error.ErrorMessage.c_str());
		OutputDebugStringA(error.HttpStatus.c_str());

		switch (error.ErrorCode)
		{
		case PlayFabErrorCode::PlayFabErrorEntityFileOperationPending:
			OutputDebugString(L"File operation is already pending.\n");
			break;
		case PlayFabErrorCode::PlayFabErrorFileNotFound:
			OutputDebugString(L"File not found.\n");
			break;
		default:
			OutputDebugString(L"Unknown PlayFab error.\n");
		}

		ShowNoticePopUp(L"Error", L"There was a problem deleting files from PlayFab");
	});
}

void Sample::UploadEntityBlob(std::string filename, std::string buffer)
{
	InitiateFileUploadsRequest initRequest;
	initRequest.Entity = m_entityTokenResult.Entity;
	initRequest.FileNames.emplace_back(filename);

	PlayFabEntityAPI::InitiateFileUploads(initRequest,
		[this, filename, buffer](const InitiateFileUploadsResponse& result, void*)
	{
		// a mutex is needed if PlayFabSettings::threadedCallbacks == true
		OutputDebugString(L"PlayFab file upload init successful\n");

		if (result.UploadDetails.size() == 0)
		{
			OutputDebugString(L"No upload addresses provided.\n");
			return;
		}

		std::wstring uri(result.UploadDetails.front().UploadUrl.begin(), result.UploadDetails.front().UploadUrl.end());
		std::vector<unsigned char> newBuffer(buffer.begin(), buffer.end());

		m_httpCallManager->MakeHttpCall(
			L"PUT",
			uri.c_str(),
			std::vector<ATG::HttpHeader>(),
			newBuffer,
			[this, filename](ATG::HttpResponse *)
		{
			FinalizeFileUploadsRequest finalRequest;
			finalRequest.Entity = m_entityTokenResult.Entity;
			finalRequest.FileNames.emplace_back(filename);

			PlayFabEntityAPI::FinalizeFileUploads(finalRequest,
				[this](const FinalizeFileUploadsResponse&, void*)
			{
				// a mutex is needed if PlayFabSettings::threadedCallbacks == true
				OutputDebugString(L"PlayFab file upload finalize successful\n");
				// Show popup with file contents
				ShowNoticePopUp(L"Upload Complete", L"");
			}
				, [this, filename](const PlayFab::PlayFabError& error, void*)
			{
				OutputDebugString(L"There was a problem uploading files to PlayFab\n");
				OutputDebugStringA(error.ErrorMessage.c_str());
				OutputDebugStringA(error.HttpStatus.c_str());

				switch (error.ErrorCode)
				{
				case PlayFabErrorCode::PlayFabErrorNoEntityFileOperationPending:
					OutputDebugString(L"No file operation is pending.\n");
					break;
				case PlayFabErrorCode::PlayFabErrorFileNotFound:
					OutputDebugString(L"File not found.\n");
					break;
				default:
					OutputDebugString(L"Unknown PlayFab error.\n");
				}

				ShowNoticePopUp(L"Error", L"There was a problem uploading data to PlayFab");

				AbortFileUploadsRequest abortRequest;
				abortRequest.Entity = m_entityTokenResult.Entity;
				abortRequest.FileNames.emplace_back(filename);

				PlayFabEntityAPI::AbortFileUploads(abortRequest,
					[this](const AbortFileUploadsResponse&, void*)
				{
					// a mutex is needed if PlayFabSettings::threadedCallbacks == true
					OutputDebugString(L"PlayFab file upload abort successful\n");
				}
					, [this, filename](const PlayFab::PlayFabError& error, void*)
				{
					OutputDebugString(L"There was a problem aborting uploaded files to PlayFab\n");
					OutputDebugStringA(error.ErrorMessage.c_str());
					OutputDebugStringA(error.HttpStatus.c_str());

					switch (error.ErrorCode)
					{
					case PlayFabErrorCode::PlayFabErrorNoEntityFileOperationPending:
						OutputDebugString(L"No file operation is pending.\n");
						break;
					case PlayFabErrorCode::PlayFabErrorFileNotFound:
						OutputDebugString(L"File not found.\n");
						break;
					default:
						OutputDebugString(L"Unknown PlayFab error.\n");
					}
				});
			});
		});
	}
		, [this](const PlayFab::PlayFabError& error, void*)
	{
		OutputDebugString(L"There was a problem uploading files to PlayFab\n");
		OutputDebugStringA(error.ErrorMessage.c_str());
		OutputDebugStringA(error.HttpStatus.c_str());

		switch (error.ErrorCode)
		{
		case PlayFabErrorCode::PlayFabErrorEntityFileOperationPending:
			OutputDebugString(L"File operation is already pending.\n");
			break;
		default:
			OutputDebugString(L"Unknown PlayFab error.\n");
		}

		ShowNoticePopUp(L"Error", L"There was a problem uploading files to PlayFab");
	});
}
#pragma endregion

#pragma region Frame Update
// Executes basic render loop.
void Sample::Tick()
{
    PIXBeginEvent(PIX_COLOR_DEFAULT, L"Frame %I64u", m_frame);

    m_timer.Tick([&]()
    {
        Update(m_timer);
    });

    Render();

    PIXEndEvent();
    m_frame++;
}

// Updates the world.
void Sample::Update(DX::StepTimer const& timer)
{
    PIXBeginEvent(PIX_COLOR_DEFAULT, L"Update");

    float elapsedTime = float(timer.GetElapsedSeconds());
	PlayFabClientAPI::Update();

	if (m_httpCallManager)
	{
		// Pump the call manager queue
		auto httpResponses = m_httpCallManager->DoWork();

		for (auto &httpResponse : httpResponses)
		{
			// Invoke response callbacks
			httpResponse.Process();
		}
	}

    auto pad = m_gamePad->GetState(0);
    if (pad.IsConnected())
    {
        m_gamePadButtons.Update(pad);

        if (!m_ui->Update(elapsedTime, pad))
        {
            if (pad.IsViewPressed())
            {
                ExitSample();
            }
            if (m_gamePadButtons.menu == GamePad::ButtonStateTracker::PRESSED)
            {
                Windows::Xbox::UI::SystemUI::ShowAccountPickerAsync(nullptr, Windows::Xbox::UI::AccountPickerOptions::None);
            }
        }
    }
    else
    {
        m_gamePadButtons.Reset();
    }

    PIXEndEvent();
}
#pragma endregion

#pragma region Frame Render
// Draws the scene.
void Sample::Render()
{
    // Don't try to render anything before the first Update.
    if (m_timer.GetFrameCount() == 0)
    {
        return;
    }

    // Prepare the render target to render a new frame.
    m_deviceResources->Prepare();
    Clear();

    auto context = m_deviceResources->GetD3DDeviceContext();
    PIXBeginEvent(context, PIX_COLOR_DEFAULT, L"Render");
    m_ui->Render();
    m_liveInfoHUD->Render();
    PIXEndEvent(context);

    // Show the new frame.
    PIXBeginEvent(context, PIX_COLOR_DEFAULT, L"Present");
    m_deviceResources->Present();
    m_graphicsMemory->Commit();
    PIXEndEvent(context);
}

// Helper method to clear the back buffers.
void Sample::Clear()
{
    auto context = m_deviceResources->GetD3DDeviceContext();
    PIXBeginEvent(context, PIX_COLOR_DEFAULT, L"Clear");

    // Clear the views.
    auto renderTarget = m_deviceResources->GetRenderTargetView();

    context->ClearRenderTargetView(renderTarget, ATG::Colors::Background);

    context->OMSetRenderTargets(1, &renderTarget, nullptr);

    // Set the viewport.
    auto viewport = m_deviceResources->GetScreenViewport();
    context->RSSetViewports(1, &viewport);

    PIXEndEvent(context);
}
#pragma endregion

#pragma region Message Handlers
// Message handlers
void Sample::OnSuspending()
{
    auto context = m_deviceResources->GetD3DDeviceContext();
    context->Suspend(0);
}

void Sample::OnResuming()
{
    auto context = m_deviceResources->GetD3DDeviceContext();
    context->Resume();
    m_timer.ResetElapsedTime();
    m_gamePadButtons.Reset();
    m_ui->Reset();
    m_liveResources->Refresh();
	m_playFabResources->Refresh();
}
#pragma endregion

#pragma region Direct3D Resources
// These are the resources that depend on the device.
void Sample::CreateDeviceDependentResources()
{
    auto device = m_deviceResources->GetD3DDevice();
    auto context = m_deviceResources->GetD3DDeviceContext();

    m_graphicsMemory = std::make_unique<GraphicsMemory>(device, m_deviceResources->GetBackBufferCount());

    m_ui->RestoreDevice(context);

    m_liveInfoHUD->RestoreDevice(context);
}

// Allocate all memory resources that change on a window SizeChanged event.
void Sample::CreateWindowSizeDependentResources()
{
    RECT fullscreen = m_deviceResources->GetOutputSize();
    static const RECT consoleDisplay = { 960, 150, 1838, 950 };

    m_ui->SetWindow(fullscreen);
}
#pragma endregion

#pragma region ListViewRow
void PlayfabStorageViewRow::Show()
{
    m_selectBtn->SetVisible(true);
    m_selectBtn->SetEnabled(true);
    m_dateModified->SetVisible(true);
    m_fileName->SetVisible(true);
    m_size->SetVisible(true);
}
void PlayfabStorageViewRow::Hide()
{
    m_selectBtn->SetVisible(false);
    m_selectBtn->SetEnabled(false);
    m_dateModified->SetVisible(false);
    m_fileName->SetVisible(false);
    m_size->SetVisible(false);
}

void PlayfabStorageViewRow::SetControls(ATG::IPanel *parent, int rowStart)
{
    m_selectBtn = dynamic_cast<ATG::Button*>(parent->Find(rowStart));
    m_fileName = dynamic_cast<ATG::TextLabel*>(parent->Find(rowStart + 1));
    m_size = dynamic_cast<ATG::TextLabel*>(parent->Find(rowStart + 2));
	m_dateModified = dynamic_cast<ATG::TextLabel*>(parent->Find(rowStart + 3));
}

void PlayfabStorageViewRow::SetSelectedCallback(ATG::IControl::callback_t callback)
{
    m_selectBtn->SetCallback(callback);
}
#pragma endregion