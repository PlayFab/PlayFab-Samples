//--------------------------------------------------------------------------------------
// PlayFabCommerce.h
//
// Advanced Technology Group (ATG)
// Copyright (C) Microsoft Corporation. All rights reserved.
//--------------------------------------------------------------------------------------

#pragma once

#include "DeviceResources.h"
#include "StepTimer.h"
#include "PlayFabResourcesXDK.h"

// ATG TK
#include "TextConsole.h"
#include "SampleGUI.h"

// Live TK
#include "LiveResourcesXDK.h"
#include "LiveInfoHUD.h"
#include "HttpCall.h"
#include "ImageManager.h"

// A basic sample implementation that creates a D3D11 device and
// provides a render loop.
class Sample
{
    // UI constants
    static const int c_mainPanel = 100;

    static const int c_twistLabel1 = 200;
    static const int c_twistLabel2 = 201;

	static const int c_addToCart = 211;

    static const int c_consumables = 2999;
    static const int c_checkout = 3000;
    static const int c_clearcart = 3001;

    static const int c_popup = 6000;
    static const int c_ynPopup = 7000;
    static const int c_progressPopup = 8000;
    static const int c_checkoutPopup = 9000;

    static const int c_imageStart = 3900;

    static const int c_imageStore = 3999;

    static const int c_price = 4000;
    static const int c_discount = 4001;
    static const int c_description = 4002;

    static const int c_inventoryStart = 4110;

    static const int c_total = 4149;
    static const int c_currency = 4150;

    static const int c_cartNum = 3102;
    static const int c_cartCount = 3110;
    static const int c_cartItem = 3111;
    static const int c_cartCost = 3112;

    static const int c_checkbox = 4200;

    static const int c_virtualItemKeyStart = 10000;
    static const int c_xboxlItemKeyStart = 20000;

    static const int c_blipDuration = 100;

    // dynamic item list constants
    static const int c_height = 50;
    static const int c_width = 400;
    static const int c_width2 = 300;
    static const int c_gap = 3;
    static const int c_left = 200;
    static const int c_top = 200;
    static const int c_numList = 12;

public:

    Sample() noexcept(false);

    // Initialization and management
    void Initialize(IUnknown* window);

    // Basic game loop
    void Tick();

    // Messages
    void OnSuspending();
    void OnResuming();

    // Properties
    bool RequestHDRMode() const { return m_deviceResources ? (m_deviceResources->GetDeviceOptions() & DX::DeviceResources::c_EnableHDR) != 0 : false; }

private:

    void Update(DX::StepTimer const& timer);
    void Render();

    void Clear();

    void CreateDeviceDependentResources();
    void CreateWindowSizeDependentResources();

    // Device resources.
    std::unique_ptr<DX::DeviceResources>        m_deviceResources;

    // Rendering loop timer.
    uint64_t                                    m_frame;
    DX::StepTimer                               m_timer;

    // Input devices.
    std::unique_ptr<DirectX::GamePad>           m_gamePad;

    DirectX::GamePad::ButtonStateTracker        m_gamePadButtons;

    // DirectXTK objects.
    std::unique_ptr<DirectX::GraphicsMemory>    m_graphicsMemory;
    
    bool m_showConsole;
    std::unique_ptr<DX::TextConsole>		    m_console;

    // Xbox Live objects.
    std::shared_ptr<ATG::LiveResources>         m_liveResources;
    std::unique_ptr<ATG::LiveInfoHUD>           m_liveInfoHUD; 

    std::shared_ptr<ATG::HttpCallManager>       m_callManager;
    std::shared_ptr<ImageManager>               m_imageManager;

    Windows::Services::Store::StoreContext^     m_storeContext;

    std::shared_ptr<ATG::PlayFabResources>      m_playFabResources;

    // Sample operations
    std::unique_ptr<ATG::UIManager>             m_ui;

    bool m_updateUI;
    bool m_inProgress;
    bool m_showXboxItems;

    uint32_t m_selectedControl;

    unsigned FindImageIndex(std::string id);

    void InitializeUI();
    void UpdateUI();

    void AddToCart();
    void ClearCart();

    bool IsManualConsumeXboxConsumables() const;

    // StoreOps
    void SetStoreContext(Windows::Xbox::System::User^ user);
    void RetrieveMSCatalog();
    void UpdateQuantities();
    void PurchaseMSItem(Platform::String^ storeId);
    void ForceWipeMSQuantities();

    // PlayFabOps
    void HandlePFError(const PlayFab::PlayFabError& error);
	void HandlePFError(const std::exception& e);

    void RetrievePFCatalog();
    void UpdatePFInventory();
	void UpdatePFStorePrices();
    void PurchasePFItem(std::string id, uint32_t price);
    void ConsumePFItem(std::string id);
    void Checkout();
    void ConsumeXboxConsumables();

    // Internal structures
    struct tConsumable
    {
        tConsumable(Windows::Services::Store::StoreProduct^ s) : storeProduct(s), quantity(0) {};
        Windows::Services::Store::StoreProduct^ storeProduct;
        uint32_t quantity;
    };

    std::map<std::wstring, tConsumable> m_XboxConsumables;
    std::map<std::string, PlayFab::ClientModels::CatalogItem> m_catalogItems;
    std::map<std::string, PlayFab::ClientModels::ItemInstance> m_inventoryItems;
    std::map<std::string, int> m_storePrices;

    std::map<std::string, int> m_virtualConsumables;
    std::map<std::string, int> m_virtualCurrencies;

    std::map<std::wstring, uint32_t> m_cart;
    
    std::vector<uint32_t> m_virtualItemButtons;

    std::set<unsigned> m_addedItems;
    std::set<unsigned> m_removedItems;
};
