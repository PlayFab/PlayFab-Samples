//--------------------------------------------------------------------------------------
// PlayFabCommerce.cpp
//
// Advanced Technology Group (ATG)
// Copyright (C) Microsoft Corporation. All rights reserved.
//--------------------------------------------------------------------------------------

#include "pch.h"
#include "PlayFabCommerce.h"

#include "ATGColors.h"

extern void ExitSample();

using namespace DirectX;

using Microsoft::WRL::ComPtr; 

// PlayFab constants
static const char* c_vc = "TC";
static const wchar_t* c_titleId = L"4E29";

Sample::Sample() noexcept(false) :
    m_frame(0)
{
    m_deviceResources = std::make_unique<DX::DeviceResources>();

    m_liveResources = std::make_shared<ATG::LiveResources>();
    m_liveInfoHUD = std::make_unique<ATG::LiveInfoHUD>(L"Fun with PlayFab Commerce");

    m_playFabResources = std::make_shared<ATG::PlayFabResources>(c_titleId);

    m_updateUI = false;
    m_inProgress = false;
    m_showXboxItems = false;
}

// Initialize the Direct3D resources required to run.
void Sample::Initialize(IUnknown* window)
{
    // Setting second param to false as .pngs in Assets use straight alpha
    ATG::UIConfig uiconfig(false, false);
    uiconfig.colorFocus = { 1.f, 0.427f, 0.125f, 1.f }; // #ff6d20 PlayFab orange

    m_ui = std::make_unique<ATG::UIManager>(uiconfig);
    m_ui->LoadLayout(L".\\Assets\\Layout.csv", L".\\Assets");

    m_callManager = std::make_shared<ATG::HttpCallManager>();
    m_imageManager = std::make_unique<ImageManager>(m_callManager);

    m_gamePad = std::make_unique<GamePad>();

    m_deviceResources->SetWindow(window);

    m_deviceResources->CreateDeviceResources();  
    CreateDeviceDependentResources();

    m_console = std::make_unique<DX::TextConsole>(m_deviceResources->GetD3DDeviceContext(), L".\\Courier_16.spritefont");
    m_console->SetDebugOutput(true);
    m_showConsole = false;

    m_deviceResources->CreateWindowSizeDependentResources();
    CreateWindowSizeDependentResources();

    m_liveResources->SetUserChangedCallback([this](ATG::XboxLiveUser)
    {
        m_liveInfoHUD->SetUser(m_liveResources->GetLiveContext());

        SetStoreContext(m_liveResources->GetUser());

        // START POINT: Once user signed in, can query Microsoft store services
        RetrieveMSCatalog();
    });

    m_liveResources->SetUserSignOutCompletedCallback([this](ATG::XboxLiveUser)
    {
        m_liveInfoHUD->SetUser(m_liveResources->GetLiveContext());
    });

    InitializeUI();

    m_liveResources->Initialize();
    m_liveInfoHUD->Initialize(m_liveResources->GetLiveContext());

    m_playFabResources->Initialize(); 
    
    m_playFabResources->SetPlayFabUserChangedCallback([this](PlayFab::ClientModels::LoginResult result)
    {
        // START POINT: Only starts up when there is a verified PlayFab user signin
        RetrievePFCatalog();

        UpdatePFInventory();
    });

    Windows::UI::Core::CoreWindow::GetForCurrentThread()->Activate();
}

#pragma region Frame Update
// Executes basic render loop.
void Sample::Tick()
{
    PIXBeginEvent(PIX_COLOR_DEFAULT, L"Frame %I64u", m_frame);

    auto responses = m_callManager->DoWork();
    for (auto &response : responses)
    {
        response.Process();
    }

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

    PlayFab::PlayFabClientAPI::Update();

    UpdateUI();

    auto pad = m_gamePad->GetState(0);
    if (pad.IsConnected())
    {
        m_ui->Update(elapsedTime, pad);

        m_gamePadButtons.Update(pad);

        // Global button operations
        // Some button-specific operations set by Button::SetCallback

        if (pad.IsViewPressed())
        {
            m_showConsole = !m_showConsole;
        }

        if (m_gamePadButtons.menu == GamePad::ButtonStateTracker::PRESSED)
        {
            Windows::Xbox::UI::SystemUI::ShowAccountPickerAsync(nullptr, Windows::Xbox::UI::AccountPickerOptions::None);
        }

        if (m_gamePadButtons.x == GamePad::ButtonStateTracker::PRESSED)
        {
            AddToCart();
        }

        static unsigned heldCount = 0;

        if (m_gamePadButtons.y == GamePad::ButtonStateTracker::HELD)
        {
            heldCount++;
            if (heldCount == 50)
            {
                ClearCart();
            }
        }

        if (m_gamePadButtons.y == GamePad::ButtonStateTracker::RELEASED)
        {
            if (heldCount < 50)
            {
                Checkout();
            }
            heldCount = 0;
        }

        if (m_gamePadButtons.leftShoulder == GamePad::ButtonStateTracker::PRESSED || m_gamePadButtons.rightShoulder == GamePad::ButtonStateTracker::PRESSED)
        {
            m_showXboxItems = !m_showXboxItems;
            m_updateUI = true;
        }

        if (m_gamePadButtons.leftTrigger == GamePad::ButtonStateTracker::PRESSED)
        {
            if (m_virtualConsumables.find("Bow") != m_virtualConsumables.end() && m_virtualConsumables.at("Bow") > 0)
            {
                ConsumePFItem("Arrow");
                if (std::rand() % 10 == 0)
                {
                    ConsumePFItem("Bow");
                }
            }
            else
            {
                auto popup = m_ui->Find(c_popup);
                static_cast<ATG::TextLabel*>(popup->Find(c_popup + 1))->SetText(L"You don't have a bow!");
                popup->Show();
            }
        }

        if (m_gamePadButtons.rightTrigger == GamePad::ButtonStateTracker::PRESSED)
        {
            ConsumePFItem("Potion");
        }

        if (m_gamePadButtons.leftStick == GamePad::ButtonStateTracker::PRESSED)
        {
            m_ui->FindControl<ATG::TextLabel>(c_ynPopup, c_ynPopup + 1)->SetText(L"Do you want to call ConsumeXboxConsumables?");
            m_ui->FindControl<ATG::Button>(c_ynPopup, c_ynPopup + 2)->SetCallback([this](ATG::IPanel*, ATG::IControl*)
            {
                m_ui->Find(c_ynPopup)->Close();
                ConsumeXboxConsumables();
            });

            m_ui->Find(c_ynPopup)->Show();
        }
        if (m_gamePadButtons.rightStick == GamePad::ButtonStateTracker::PRESSED)
        {
            m_ui->FindControl<ATG::TextLabel>(c_ynPopup, c_ynPopup + 1)->SetText(L"Are you sure you want to decrement all your (Microsoft) consumables?");
            m_ui->FindControl<ATG::Button>(c_ynPopup, c_ynPopup + 2)->SetCallback([this](ATG::IPanel*, ATG::IControl*)
            {
                m_ui->Find(c_ynPopup)->Close();
                ForceWipeMSQuantities();
            });

            m_ui->Find(c_ynPopup)->Show();
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

    if (m_showConsole)
    {
        m_console->Render();
    }

    auto context = m_deviceResources->GetD3DDeviceContext();
    PIXBeginEvent(context, PIX_COLOR_DEFAULT, L"Render");
        
    m_liveInfoHUD->Render();

    m_ui->Render();

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
    auto depthStencil = m_deviceResources->GetDepthStencilView();

    context->ClearRenderTargetView(renderTarget, ATG::Colors::Background);
    context->ClearDepthStencilView(depthStencil, D3D11_CLEAR_DEPTH | D3D11_CLEAR_STENCIL, 1.0f, 0);

    context->OMSetRenderTargets(1, &renderTarget, depthStencil);

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

    m_imageManager->RestoreDevice(device);

    m_liveInfoHUD->RestoreDevice(context);

    // Let UI create Direct3D resources.
    m_ui->RestoreDevice(context);
}

// Allocate all memory resources that change on a window SizeChanged event.
void Sample::CreateWindowSizeDependentResources()
{
    RECT size = m_deviceResources->GetOutputSize();

    // Configure debug console
    m_console->SetWindow({ size.left + 100, size.top + 50, size.right - 100, size.bottom - 50 });
    m_console->SetForegroundColor(DirectX::Colors::YellowGreen);

    m_ui->SetWindow(size);
}
#pragma endregion

#pragma region Sample operations
static std::map<std::string, unsigned> c_image =
{
    { "Arrow",	 0 },
    { "Bow",	 1 },
    { "Mystery", 2 },
    { "Gem",	 3 },
    { "Potion",  4 },
    { "Shield",  5 },
    { "Sword",	 6 }
};

unsigned Sample::FindImageIndex(std::string id)
{
    for (auto& image : c_image)
    {
        if (std::strstr(id.c_str(), image.first.c_str()) != nullptr)
        {
            return image.second;
        }
    }

    return 0;
}

void Sample::InitializeUI()
{
    m_ui->Find(c_mainPanel)->Show();

    m_ui->FindControl<ATG::TextLabel>(c_mainPanel, c_price)->SetVisible(false);
    m_ui->FindControl<ATG::TextLabel>(c_mainPanel, c_discount)->SetVisible(false);
    m_ui->FindControl<ATG::Legend>(c_mainPanel, c_checkout)->SetVisible(false);
    m_ui->FindControl<ATG::Legend>(c_mainPanel, c_clearcart)->SetVisible(false);
    m_ui->FindControl<ATG::TextLabel>(c_mainPanel, c_consumables)->SetVisible(false);

    for (auto& image : c_image)
    {
        m_ui->FindControl<ATG::Image>(c_mainPanel, c_imageStart + image.second)->SetVisible(false);
    }
}

void Sample::UpdateUI()
{
    static int numStoreItems = 0;
    static int numVirtualItems = 0;

    static int blipcount = 0;

    // Progress popup
    if (m_inProgress && !m_ui->Find(c_progressPopup)->IsVisible())
    {
        m_ui->Find(c_progressPopup)->Show();
    }

    if (!m_inProgress && m_ui->Find(c_progressPopup)->IsVisible())
    {
        m_ui->Find(c_progressPopup)->Close();
    }

    if(m_ui->Find(c_progressPopup)->IsVisible())
    {
        std::wstring str = L"Transaction in progress, please wait ...";
        static unsigned num = 1;
        for (unsigned i = 0; i < num; ++i)
        {
            str += L".";
        }
        num = (num > 15) ? 0 : num + 1;
        m_ui->FindControl<ATG::TextLabel>(c_progressPopup, c_progressPopup + 1)->SetText(str.c_str());
    }

    // This is set as a result of various operations (purchase complete, item consumed, etc.)
    if (m_updateUI)
    {
        if (numStoreItems == 0 && m_XboxConsumables.size() > 0)
        {
            // For each entry found in catalog, add a new button to the UI
            for (auto& consumable: m_XboxConsumables)
            {
                auto sp = consumable.second.storeProduct;
                unsigned key = c_virtualItemKeyStart + numStoreItems;

                int y = numStoreItems * c_height + c_top + numStoreItems * c_gap;
                RECT r = { c_left, y, c_left + c_width, y + c_height };

                auto button = new ATG::Button(key, sp->Title->Data(), r);
                button->SetStyle(ATG::Button::c_StyleFontBold);

                auto storeId = sp->StoreId;
                button->SetCallback([this, storeId](ATG::IPanel*, ATG::IControl*)
                {
                    PurchaseMSItem(storeId);
                });

                auto desc = sp->Description->Data();
                auto price = sp->Price->FormattedPrice->Data();
                button->SetFocusCb([this, key, storeId, desc, price](ATG::IPanel*, ATG::IControl*)
                {
                    auto image = m_imageManager->GetImage(storeId->Data());
                    if (image != nullptr)
                    {
                        // downloaded image found
                        m_ui->RegisterImage(key, image);
                        m_ui->FindControl<ATG::Image>(c_mainPanel, c_imageStore)->SetImageId(key);
                        m_ui->FindControl<ATG::Image>(c_mainPanel, c_imageStore)->SetVisible(true);
                    }
                    else
                    {
                        m_ui->FindControl<ATG::Image>(c_mainPanel, c_imageStore)->SetVisible(false);
                    }

                    m_selectedControl = key;
                    
                    m_ui->FindControl<ATG::TextLabel>(c_mainPanel, c_price)->SetText(price);
                    m_ui->FindControl<ATG::TextLabel>(c_mainPanel, c_description)->SetText(desc);
                });

                m_ui->FindPanel<ATG::IPanel>(c_mainPanel)->Add(button);
                m_ui->FindPanel<ATG::IPanel>(c_mainPanel)->SetFocus(button);

                button->SetEnabled(false);
                button->SetVisible(false);

                numStoreItems++;
            }

            // fill out list with blanks
            for (int i = numStoreItems; i < c_numList; ++i)
            {
                unsigned key = c_virtualItemKeyStart + i;
                int y = i * c_height + c_top + i * c_gap;
                RECT r = { c_left, y, c_left + c_width, y + c_height };

                auto label = new ATG::TextLabel(key, L"", r);
                label->SetBackgroundColor(ATG::Colors::DarkGrey);
                m_ui->FindPanel<ATG::IPanel>(c_mainPanel)->Add(label);
            }
        }

        if (numVirtualItems == 0 && m_catalogItems.size() > 0)
        {
            // For each entry found in catalog, add a new button to the UI
            for (auto& item : m_catalogItems)
            {
                auto priceIter = item.second.VirtualCurrencyPrices.find(c_vc);
                if (priceIter != item.second.VirtualCurrencyPrices.end())
                {
                    int key = c_xboxlItemKeyStart + numVirtualItems;

                    int y = numVirtualItems * c_height + c_top + numVirtualItems * c_gap;
                    RECT r = { c_left, y, c_left + c_width, y + c_height };
                    
                    auto id = item.second.ItemId;

                    // price according to catalog
                    auto basePrice = priceIter->second;

                    std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;

                    auto button = new ATG::Button(key, converter.from_bytes(id).c_str(), r);
                    button->SetStyle(ATG::Button::c_StyleFontBold);
                    button->SetCallback([this, item, id, basePrice](ATG::IPanel*, ATG::IControl*)
                    {
                        std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;

                        // check if there is a store price override
                        auto it = m_storePrices.find(item.first);
                        auto currentPrice = it != m_storePrices.end() ? it->second : basePrice;

                        std::wstring str = L"Purchase ";
                        str += converter.from_bytes(id);
                        str += L" for ";
                        str += std::to_wstring(currentPrice);
                        str += L" ";
                        str += converter.from_bytes(c_vc);
                        str += L"?";
                        m_ui->FindControl<ATG::TextLabel>(c_ynPopup, c_ynPopup + 1)->SetText(str.c_str());
                        m_ui->FindControl<ATG::Button>(c_ynPopup, c_ynPopup + 2)->SetCallback([this, id, currentPrice](ATG::IPanel*, ATG::IControl*)
                        {
                            m_ui->Find(c_ynPopup)->Close();
                            PurchasePFItem(id, currentPrice);
                        });

                        m_ui->Find(c_ynPopup)->Show();
                    });

                    button->SetFocusCb([this, item, id, basePrice, key](ATG::IPanel*, ATG::IControl*)
                    {
                        m_selectedControl = key;

                        std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;

                        for (auto& image : c_image)
                        {
                            m_ui->FindControl<ATG::Image>(c_mainPanel, c_imageStart + image.second)->SetVisible(false);
                        }

                        m_ui->FindControl<ATG::Image>(c_mainPanel, c_imageStart + FindImageIndex(id))->SetVisible(true);

                        // check if there is a store price override
                        auto it = m_storePrices.find(item.first);
                        auto currentPrice = it != m_storePrices.end() ? it->second : basePrice;

                        wchar_t str[100] = L"";
                        swprintf_s(str, L"%d %s", currentPrice, converter.from_bytes(c_vc).c_str());
                        m_ui->FindControl<ATG::TextLabel>(c_mainPanel, c_price)->SetVisible(true);
                        m_ui->FindControl<ATG::TextLabel>(c_mainPanel, c_price)->SetText(str);
                        m_ui->FindControl<ATG::TextLabel>(c_mainPanel, c_discount)->SetVisible(false);
                        m_ui->FindControl<ATG::TextLabel>(c_mainPanel, c_description)->SetText(L"");

                        if (basePrice != currentPrice)
                        {
                            swprintf_s(str, L"%2.1f%% OFF", (1.f - (float(currentPrice) / float(basePrice))) * 100.f);

                            m_ui->FindControl<ATG::TextLabel>(c_mainPanel, c_discount)->SetText(str);
                            m_ui->FindControl<ATG::TextLabel>(c_mainPanel, c_discount)->SetVisible(true);
                        }
                    });

                    m_ui->FindPanel<ATG::IPanel>(c_mainPanel)->Add(button);
                    m_ui->FindPanel<ATG::IPanel>(c_mainPanel)->SetFocus(button);
                    
                    m_virtualItemButtons.push_back(key);
                    numVirtualItems++;
                }
            }

            // fill out list with blanks
            for (int i = numVirtualItems; i < c_numList; ++i)
            {
                unsigned key = c_xboxlItemKeyStart + i;
                int y = i * c_height + c_top + i * c_gap;
                RECT r = { c_left, y, c_left + c_width, y + c_height };

                auto label = new ATG::TextLabel(key, L"", r);
                label->SetBackgroundColor(ATG::Colors::DarkGrey);
                m_ui->FindPanel<ATG::IPanel>(c_mainPanel)->Add(label);
            }
        }

        // Toggle showing Xbox and PF items
        for (int i = 0; numStoreItems > 0 && i < c_numList; ++i)
        {
            if (i < numStoreItems)
            {
                auto button = m_ui->FindControl<ATG::Button>(c_mainPanel, c_virtualItemKeyStart + i);
                button->SetEnabled(m_showXboxItems);
                button->SetVisible(m_showXboxItems);

                if (m_showXboxItems && i == 0)
                {
                    m_ui->FindControl<ATG::TextLabel>(c_mainPanel, c_twistLabel1)->SetForegroundColor(ATG::Colors::White);
                    m_ui->FindControl<ATG::TextLabel>(c_mainPanel, c_twistLabel1)->SetBackgroundColor(ATG::Colors::DarkGrey);
                    m_ui->FindControl<ATG::TextLabel>(c_mainPanel, c_twistLabel2)->SetForegroundColor(ATG::Colors::LightGrey);
                    m_ui->FindControl<ATG::TextLabel>(c_mainPanel, c_twistLabel2)->SetBackgroundColor({ 0.f, 0.f, 0.f, 0.f });
                    m_ui->FindPanel<ATG::IPanel>(c_mainPanel)->SetFocus(button);

					m_ui->FindControl<ATG::Legend>(c_mainPanel, c_addToCart)->SetVisible(false);

                    if (IsManualConsumeXboxConsumables())
                    {
                        m_ui->FindControl<ATG::TextLabel>(c_mainPanel, c_consumables)->SetVisible();
                    }

                    m_ui->FindControl<ATG::TextLabel>(c_mainPanel, c_discount)->SetVisible(false);

                    for (auto& image : c_image)
                    {
                        m_ui->FindControl<ATG::Image>(c_mainPanel, c_imageStart + image.second)->SetVisible(false);
                    }
				
                }
            }
            else
            {
                auto label = m_ui->FindControl<ATG::TextLabel>(c_mainPanel, c_virtualItemKeyStart + i);
                label->SetVisible(m_showXboxItems);
            }
        }

        for (int i = 0; numVirtualItems > 0 && i < c_numList; ++i)
        {
            if (i < numVirtualItems)
            {
                auto button = m_ui->FindControl<ATG::Button>(c_mainPanel, c_xboxlItemKeyStart + i);
                button->SetEnabled(!m_showXboxItems);
                button->SetVisible(!m_showXboxItems);

                if (!m_showXboxItems && i == 0)
                {
                    m_ui->FindControl<ATG::TextLabel>(c_mainPanel, c_twistLabel1)->SetForegroundColor(ATG::Colors::LightGrey);
                    m_ui->FindControl<ATG::TextLabel>(c_mainPanel, c_twistLabel1)->SetBackgroundColor({ 0.f, 0.f, 0.f, 0.f });
                    m_ui->FindControl<ATG::TextLabel>(c_mainPanel, c_twistLabel2)->SetForegroundColor(ATG::Colors::White);
                    m_ui->FindControl<ATG::TextLabel>(c_mainPanel, c_twistLabel2)->SetBackgroundColor(ATG::Colors::DarkGrey);
                    m_ui->FindPanel<ATG::IPanel>(c_mainPanel)->SetFocus(button);
                    m_ui->FindControl<ATG::TextLabel>(c_mainPanel, c_consumables)->SetVisible(false);

					m_ui->FindControl<ATG::Legend>(c_mainPanel, c_addToCart)->SetVisible(true);

                    m_ui->FindControl<ATG::Image>(c_mainPanel, c_imageStore)->SetVisible(false);
                }
            }
            else
            {
                auto label = m_ui->FindControl<ATG::TextLabel>(c_mainPanel, c_xboxlItemKeyStart + i);
                label->SetVisible(!m_showXboxItems);
            }
        }

        if (m_virtualConsumables.size() > 0 || m_virtualCurrencies.size() > 0)
        {
            std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;

            std::wstring str = L"";

            // Populate inventory quantity
            for (auto& consumable : m_virtualConsumables)
            {
                auto count = c_image.find(consumable.first);
                if (count != c_image.end())
                {
                    m_ui->FindControl<ATG::TextLabel>(c_mainPanel, c_inventoryStart + count->second)->SetText(std::to_wstring(consumable.second).c_str());
                }
            }

            // Populate virtual currency quantity
            for (auto& currency : m_virtualCurrencies)
            {
                str += std::to_wstring(currency.second);
                str += L" ";
                str += converter.from_bytes(currency.first);
                str += L"\n";
            }
            m_ui->FindControl<ATG::TextLabel>(c_mainPanel, c_currency)->SetText(str.c_str());
        }

        if (m_XboxConsumables.size() > 0)
        {
            std::wstring str = L"";

            for (auto& consumable : m_XboxConsumables)
            {
                str += L"(";
                str += consumable.second.storeProduct->StoreId->Data();
                str += L")";
                str += consumable.second.storeProduct->Title->Data();
                str += L": ";
                str += std::to_wstring(consumable.second.quantity);
                str += L"\n";
            }
            m_ui->FindControl<ATG::TextLabel>(c_mainPanel, c_consumables)->SetText(str.c_str());
        }

        // Briefly change quantity color of any purchased or consumed items
        if (blipcount == 0 && (m_addedItems.size() > 0 || m_removedItems.size() > 0))
        {
            for (auto& index : m_addedItems)
            {
                m_ui->FindControl<ATG::TextLabel>(c_mainPanel, c_inventoryStart + index)->SetForegroundColor(DirectX::Colors::Yellow);
            }

            for (auto& index : m_removedItems)
            {
                m_ui->FindControl<ATG::TextLabel>(c_mainPanel, c_inventoryStart + index)->SetForegroundColor(DirectX::Colors::Red);
            }

            blipcount = c_blipDuration;
        }

        m_updateUI = false;
    }

    // Reset any quantity color change color set above
    if (blipcount == 1)
    {
        for (auto& index : m_removedItems)
        {
            m_ui->FindControl<ATG::TextLabel>(c_mainPanel, c_inventoryStart + index)->SetForegroundColor(ATG::Colors::White);
        }
        m_removedItems.clear();

        for (auto& index : m_addedItems)
        {
            m_ui->FindControl<ATG::TextLabel>(c_mainPanel, c_inventoryStart + index)->SetForegroundColor(ATG::Colors::White);
        }
        m_addedItems.clear();
    }
    blipcount = (blipcount > 0) ? blipcount - 1 : 0;
}

void Sample::AddToCart()
{
    auto it = std::find(m_virtualItemButtons.begin(), m_virtualItemButtons.end(), m_selectedControl);
    if (it != m_virtualItemButtons.end())
    {
        auto button = m_ui->FindControl<ATG::Button>(c_mainPanel, *it);
        m_console->Format(L"Add to cart: %s\n", button->GetText());

        if (m_cart.find(button->GetText()) != m_cart.end())
        {
            m_cart.at(button->GetText()) += 1;
        }
        else
        {
            m_cart.insert_or_assign(button->GetText(), 1);
        }

        std::wstring counts = L"";
        std::wstring items = L"";
        std::wstring costs = L"";

        std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;

        unsigned count = 0;
        unsigned total = 0;
        for (auto& cartItem : m_cart)
        {
            counts += std::to_wstring(cartItem.second);
            counts += L"\n";
            count += cartItem.second;

            items += cartItem.first;
            items += L"\n";

            unsigned price = 0;
            auto spit = m_storePrices.find(converter.to_bytes(cartItem.first));
            if (spit != m_storePrices.end())
            {
                // found for store-based price
                price = spit->second;
            }
            else
            {
                // retrieve price from catalog
                auto catalogItem = m_catalogItems.at(converter.to_bytes(cartItem.first));
                auto ciit = catalogItem.VirtualCurrencyPrices.find(c_vc);
                if (ciit != catalogItem.VirtualCurrencyPrices.end())
                {
                    price = ciit->second;
                }
            }

            auto subtotal = price * cartItem.second;
            total += subtotal;
            costs += std::to_wstring(subtotal);
            costs += L" ";
            costs += converter.from_bytes(c_vc);
            costs += L"\n";
        }

        m_ui->FindControl<ATG::TextLabel>(c_mainPanel, c_cartCount)->SetText(counts.c_str());
        m_ui->FindControl<ATG::TextLabel>(c_mainPanel, c_cartItem)->SetText(items.c_str());
        m_ui->FindControl<ATG::TextLabel>(c_mainPanel, c_cartCost)->SetText(costs.c_str());

        counts = std::to_wstring(count);
        counts += L" item";
        counts += count > 1 ? L"s" : L"";
        m_ui->FindControl<ATG::TextLabel>(c_mainPanel, c_cartNum)->SetText(counts.c_str());

        costs = std::to_wstring(total);
        costs += L" ";
        costs += converter.from_bytes(c_vc);

        m_ui->FindControl<ATG::TextLabel>(c_mainPanel, c_total)->SetText(costs.c_str());

        if (m_cart.size() > 0)
        {
            m_ui->FindControl<ATG::Legend>(c_mainPanel, c_checkout)->SetVisible(true);
            m_ui->FindControl<ATG::Legend>(c_mainPanel, c_clearcart)->SetVisible(true);
        }
    }
}

void Sample::ClearCart()
{
    m_cart.clear();

    m_ui->FindControl<ATG::TextLabel>(c_mainPanel, c_cartNum)->SetText(L"0 items");

    m_ui->FindControl<ATG::TextLabel>(c_mainPanel, c_cartCount)->SetText(L"");
    m_ui->FindControl<ATG::TextLabel>(c_mainPanel, c_cartItem)->SetText(L"");
    m_ui->FindControl<ATG::TextLabel>(c_mainPanel, c_cartCost)->SetText(L"");

    m_ui->FindControl<ATG::TextLabel>(c_mainPanel, c_total)->SetText(L"");

    m_ui->FindControl<ATG::Legend>(c_mainPanel, c_checkout)->SetVisible(false);
    m_ui->FindControl<ATG::Legend>(c_mainPanel, c_clearcart)->SetVisible(false);
}

bool Sample::IsManualConsumeXboxConsumables() const
{
    return m_ui->FindControl<ATG::CheckBox>(c_mainPanel, c_checkbox)->IsChecked();
}

#pragma endregion