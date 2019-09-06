//--------------------------------------------------------------------------------------
// PlayFabOps.cpp
//
// Advanced Technology Group (ATG)
// Copyright (C) Microsoft Corporation. All rights reserved.
//--------------------------------------------------------------------------------------

#include "pch.h"
#include "PlayFabCommerce.h"

#include "playfab\PlayFabClientApi.h"
#include "playfab\PlayFabClientDataModels.h"

static const char* c_vc = "TC";
static const char* c_catalog = "0.1";
static const char* c_store = "Normal";

using namespace PlayFab;

void Sample::HandlePFError(const PlayFab::PlayFabError& error)
{
    m_console->Format(L"An error occurred with a PlayFab API\n");
    m_console->Format(L"PlayFab error code: %i\n%S: %S\n%S\nHTTP error: %i %S\n",
        error.ErrorCode,
        error.ErrorName.c_str(),
        error.ErrorMessage.c_str(),
        error.UrlPath.c_str(),
        error.HttpCode,
        error.HttpStatus.c_str());

    std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;

    std::wstring str = L"PlayFab error [";
    str += std::to_wstring(error.ErrorCode);
    str += L"] ";
    str += converter.from_bytes(error.ErrorMessage);

	auto popup = m_ui->Find(c_popup);
	static_cast<ATG::TextLabel*>(popup->Find(c_popup + 1))->SetText(str.c_str());

	popup->Show();

    m_inProgress = false;
}

void Sample::HandlePFError(const std::exception& e)
{
	std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;

	auto msg = converter.from_bytes(e.what());

	m_console->Format(L"PlayFab API exception: %s\n", msg.c_str());

	std::wstring str = L"PlayFab exception ";
	str += msg;

	auto popup = m_ui->Find(c_popup);
	static_cast<ATG::TextLabel*>(popup->Find(c_popup + 1))->SetText(str.c_str());

	popup->Show();

	m_inProgress = false;
}

void Sample::RetrievePFCatalog()
{
    m_inProgress = true;

    PlayFab::ClientModels::GetCatalogItemsRequest req;

    // https://api.playfab.com/documentation/client/method/GetCatalogItems
    PlayFabClientAPI::GetCatalogItems(req,
        [this](const PlayFab::ClientModels::GetCatalogItemsResult& result, void*)
    {
        std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;

        for (auto& item : result.Catalog)
        {
            m_catalogItems.insert_or_assign(item.ItemId, item);

            m_console->Format(L"Catalog Item ID: %s DisplayName: %s\n",
                converter.from_bytes(item.ItemId).c_str(),
                converter.from_bytes(item.DisplayName).c_str());
        }

		UpdatePFStorePrices();
       
    },
        [this](const PlayFab::PlayFabError& error, void*)
    {
        HandlePFError(error);
    });
}

void Sample::UpdatePFStorePrices()
{
	// 4E29 catalog implemented a store, which can alter prices based on player segments
	PlayFab::ClientModels::GetStoreItemsRequest req;
	req.StoreId = c_store;

	// https://api.playfab.com/documentation/client/method/GetStoreItems
	PlayFabClientAPI::GetStoreItems(req,
		[this](const PlayFab::ClientModels::GetStoreItemsResult& result, void*)
	{
		std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;

		for (auto& item : result.Store)
		{
			m_console->Format(L"Store Item ID: %s\n",
				converter.from_bytes(item.ItemId).c_str());

			if (item.VirtualCurrencyPrices.find(c_vc) != item.VirtualCurrencyPrices.end())
			{
				m_storePrices.insert_or_assign(item.ItemId, item.VirtualCurrencyPrices.at(c_vc));
			}
		}

		m_inProgress = false;
		m_updateUI = true;
	},
		[this](const PlayFab::PlayFabError& error, void*)
	{
		HandlePFError(error);
	});
}

void Sample::UpdatePFInventory()
{
    m_inProgress = true;

    // https://api.playfab.com/documentation/client/method/GetUserInventory
    PlayFab::ClientModels::GetUserInventoryRequest req;
    PlayFabClientAPI::GetUserInventory(req,
        [this](const PlayFab::ClientModels::GetUserInventoryResult& result, void*)
    {
        std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;

        std::map<std::string, int> previous = m_virtualConsumables;
        m_virtualConsumables.clear();

        m_inventoryItems.clear();

        for (auto& item : result.Inventory)
        {
            m_inventoryItems.insert_or_assign(item.ItemId, item);

            m_console->Format(L"Inventory Item ID: %s DisplayName: %s RemainingUses: %d ItemInstanceId %s\n",
                converter.from_bytes(item.ItemId).c_str(),
                converter.from_bytes(item.DisplayName).c_str(),
                item.RemainingUses,
                converter.from_bytes(item.ItemInstanceId).c_str()
            );

            // Durables will also be returned in inventory, but this sample is concerned with consumables only
            // Bundles are also returned, many of these are Xbox bridge items, so not interested in these either
            if (item.RemainingUses.isNull() == false && item.BundleContents.size() == 0)
            {
                if (m_virtualConsumables.find(item.ItemId) == m_virtualConsumables.end())
                {
                    m_virtualConsumables.insert(std::pair<std::string, int>(item.ItemId, item.RemainingUses));
                }
                else
                {
                    // can have multiple distinct inventory items of the same ItemId, make sure to consolidate
                    m_virtualConsumables[item.ItemId] += item.RemainingUses;
                }
            }
        }

        for (auto& consumable : previous)
        {
            // Compare previous results with current to determine deltas
            auto it = m_virtualConsumables.find(consumable.first);
            if (it != m_virtualConsumables.end())
            {
                if (it->second > consumable.second)
                {
                    m_addedItems.insert(FindImageIndex(consumable.first));
                }

                if (it->second < consumable.second)
                {
                    m_removedItems.insert(FindImageIndex(consumable.first));
                }
            }
            else
            {
                if (consumable.second > 0)
                {
                    // when it goes to 0, inventory won't even return it, add fake entry for UI update
                    m_virtualConsumables.insert(std::pair<std::string, int>(consumable.first, 0));
                    m_removedItems.insert(FindImageIndex(consumable.first));
                }
            }
        }

        for (auto& consumable : m_virtualConsumables)
        {
            // Compare current with previous to find new unique items
            auto it = previous.find(consumable.first);
            if (it == previous.end())
            {
                m_addedItems.insert(FindImageIndex(consumable.first));
            }
        }

        previous.clear();
        previous = m_virtualCurrencies;

        for (auto& currency : result.VirtualCurrency)
        {
            m_console->Format(L"Inventory Virtual Currency ID: %s Quantity: %d\n",
                converter.from_bytes(currency.first).c_str(),
                currency.second);

            m_virtualCurrencies.insert_or_assign(currency.first, currency.second);
        }

		bool currencyChanged = false;
        for (auto& currency : previous)
        {
            // Compare previous results with current to determine deltas
            auto it = m_virtualCurrencies.find(currency.first);
            if (it != m_virtualCurrencies.end())
            {
                if (it->second > currency.second)
                {
                    m_addedItems.insert(c_currency - c_inventoryStart);
					currencyChanged = true;
                }

                if (it->second < currency.second)
                {
                    m_removedItems.insert(c_currency - c_inventoryStart);
					currencyChanged = true;
                }
            }
            else
            {
                if (currency.second > 0)
                {
                    // when it goes to 0, inventory won't even return it, add fake entry for UI update
                    m_virtualCurrencies.insert_or_assign(currency.first, 0);
                    m_removedItems.insert(c_currency - c_inventoryStart);
                    currencyChanged = true;
                }
            }
        }

        for (auto& currency : m_virtualCurrencies)
        {
            // Compare current with previous to find new unique items
            auto it = previous.find(currency.first);
            if (it == previous.end())
            {
                m_addedItems.insert(c_currency - c_inventoryStart);
                currencyChanged = true;
            }
        }

		previous.clear();

		if (currencyChanged)
		{
			// 4E29 defined a player segment that switches stores (i.e. price points) based on virtual currency balance
			// so when this is changed, update to check for new price points
			UpdatePFStorePrices();
		}
		else
		{
			m_updateUI = true;
			m_inProgress = false;
		}
    },
        [this](const PlayFab::PlayFabError& error, void*)
    {
        HandlePFError(error);
    });
}

void Sample::PurchasePFItem(std::string id, uint32_t price)
{
    m_inProgress = true;

    PlayFab::ClientModels::PurchaseItemRequest req;

    req.ItemId = id;
    req.Price = price;
    req.StoreId = c_store;
    req.VirtualCurrency = c_vc;

    // https://api.playfab.com/documentation/client/method/PurchaseItem
    PlayFabClientAPI::PurchaseItem(req,
        [this](const PlayFab::ClientModels::PurchaseItemResult& result, void*)
    {
        std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;

        for (auto& item : result.Items)
        {
            m_console->Format(L"Purchased Item ID: %s DisplayName: %s\n",
                converter.from_bytes(item.ItemId).c_str(),
                converter.from_bytes(item.DisplayName).c_str());
        }

        UpdatePFInventory();

    },
        [this](const PlayFab::PlayFabError& error, void*)
    {
        HandlePFError(error);
    });
}

void Sample::ConsumePFItem(std::string id)
{
    auto it = m_inventoryItems.find(id);
    
    if(it != m_inventoryItems.end())
    {
        if(it->second.RemainingUses > 0)
        {
            m_inProgress = true;

            PlayFab::ClientModels::ConsumeItemRequest req;
            req.ItemInstanceId = it->second.ItemInstanceId;
            req.ConsumeCount = 1;

            // https://api.playfab.com/documentation/client/method/ConsumeItem
            PlayFabClientAPI::ConsumeItem(req,
                [this, id](const PlayFab::ClientModels::ConsumeItemResult& result, void*)
            {
                std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;

                m_console->Format(L"%s consumed, %d remaining\n", converter.from_bytes(id).c_str(), result.RemainingUses);

                UpdatePFInventory();
            },
                [this](const PlayFab::PlayFabError& error, void*)
            {
                HandlePFError(error);
            });
        }
    }
}

void Sample::Checkout()
{
    // Checkout of cart of items involves three stages:
    // 1. StartPurchase which finalizes the cart where no more items can be added to the transaction and 
    //    total cost in the supported currencies is computed; order ID is assigned here and used below
    // 2. PayForPurchase which a user confirmation of which currency to use to pay for the cart items
    // 3. ConfirmPurchase which executes the transaction and returns items purchased if successful

    m_inProgress = true;

    std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;

    PlayFab::ClientModels::StartPurchaseRequest spreq;

    for (auto& item : m_cart)
    {
        PlayFab::ClientModels::ItemPurchaseRequest ipreq;
        ipreq.ItemId = converter.to_bytes(item.first);
        ipreq.Quantity = item.second;

        spreq.Items.push_back(ipreq);
        spreq.StoreId = c_store;
    }

    // https://api.playfab.com/documentation/client/method/StartPurchase
	PlayFabClientAPI::StartPurchase(spreq,
		[this](const PlayFab::ClientModels::StartPurchaseResult& result, void*)
	{
		std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;

		for (auto& item : result.Contents)
		{
			m_console->Format(L"Cart Item ID: %s DisplayName: %s\n",
				converter.from_bytes(item.ItemId).c_str(),
				converter.from_bytes(item.DisplayName).c_str());
		}

		int subtotal = 0;
		std::string currency = "";
		std::string providername = "";
		std::string orderid = result.OrderId;

		for (auto& paymentoption : result.PaymentOptions)
		{
			m_console->Format(L"Payment option: %s Price: %d / %d\n",
				converter.from_bytes(paymentoption.Currency).c_str(),
				paymentoption.Price,
				result.VirtualCurrencyBalances.at(paymentoption.Currency));

			if (paymentoption.Currency == c_vc)
			{
				subtotal = paymentoption.Price;
				currency = paymentoption.Currency;
				providername = paymentoption.ProviderName;
			}
		}

		// show confirmation popup first
		auto popup = m_ui->Find(c_ynPopup);

		std::wstring str = L"Confirm purchase of items for ";

		str += std::to_wstring(subtotal);
		str += L" ";
		str += converter.from_bytes(c_vc);
		str += L"?";

		static_cast<ATG::TextLabel*>(popup->Find(c_ynPopup + 1))->SetText(str.c_str());

		static_cast<ATG::Button*>(popup->Find(c_ynPopup + 2))->SetCallback([this, popup, currency, providername, orderid](ATG::IPanel*, ATG::IControl*)
		{
			PlayFab::ClientModels::PayForPurchaseRequest req;

			req.Currency = currency;
			req.ProviderName = providername;
			req.OrderId = orderid;

			// https://api.playfab.com/documentation/client/method/PayForPurchase
			PlayFabClientAPI::PayForPurchase(req,
				[this](const PlayFab::ClientModels::PayForPurchaseResult& result, void*)
			{
				std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;

				m_console->Format(L"Cost of transaction: %s %u\n",
					converter.from_bytes(result.PurchaseCurrency).c_str(), result.PurchasePrice);

				PlayFab::ClientModels::ConfirmPurchaseRequest req;
				req.OrderId = result.OrderId;

				// https://api.playfab.com/documentation/client/method/ConfirmPurchase
				PlayFabClientAPI::ConfirmPurchase(req,
					[this](const PlayFab::ClientModels::ConfirmPurchaseResult& result, void*)
				{
					std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;

					for (auto& item : result.Items)
					{
						m_console->Format(L"Purchased Item ID: %s DisplayName: %s\n",
							converter.from_bytes(item.ItemId).c_str(),
							converter.from_bytes(item.DisplayName).c_str());
					}

					UpdatePFInventory();
				},
					[this](const PlayFab::PlayFabError& error, void*)
				{
					HandlePFError(error);
				});
			},
				[this](const PlayFab::PlayFabError& error, void*)
			{
				HandlePFError(error);
			});

			ClearCart();

			popup->Close();
		});

		static_cast<ATG::Button*>(popup->Find(c_ynPopup + 3))->SetCallback([this, popup](ATG::IPanel*, ATG::IControl*)
		{
			// user declined purchase
			m_inProgress = false;

			popup->Close();
		});

		popup->Show();
	},
		[this](const PlayFab::PlayFabError& error, void*)
	{
		HandlePFError(error);
	});

}

void Sample::ConsumeXboxConsumables()
{
    // Bridges any Microsoft inventory consumables with corresponding PlayFab bundles
    // See readme for more details
    m_inProgress = true;

    auto async = m_liveResources->GetUser()->GetTokenAndSignatureAsync("POST", "https://playfabapi.com", "");

    concurrency::create_task(async).then([=](concurrency::task<Windows::Xbox::System::GetTokenAndSignatureResult^> result)
    {
        try
        {
            auto token = result.get();
            static char buffer[4000] = {};
            sprintf_s(buffer, "%S", token->Token->Data());

            PlayFab::ClientModels::ConsumeXboxEntitlementsRequest req;
            req.XboxToken = buffer;
            req.CatalogVersion = c_catalog;

            // https://api.playfab.com/documentation/client/method/ConsumeXboxEntitlements
            PlayFabClientAPI::ConsumeXboxEntitlements(req,
                [this](const PlayFab::ClientModels::ConsumeXboxEntitlementsResult& result, void*)
            {
                std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;

                for (auto& item : result.Items)
                {
                    m_console->Format(L"Item ID: %s DisplayName: %s\n",
                        converter.from_bytes(item.ItemId).c_str(),
                        converter.from_bytes(item.DisplayName).c_str());
                }

                UpdatePFInventory();
                UpdateQuantities();
            },
                [this](const PlayFab::PlayFabError& error, void*)
            {
                HandlePFError(error);
            });
        }
        catch (Platform::Exception^ ex)
        {
            wchar_t buffer[1000] = {};
            swprintf_s(buffer, L"HRESULT: 0x%x\nMessage: %s\n", ex->HResult, ex->Message->Data());
            OutputDebugString(L"Failed to get Xbox Live token\n");
            OutputDebugString(buffer);
        }
    });
}