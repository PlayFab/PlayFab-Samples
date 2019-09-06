//--------------------------------------------------------------------------------------
// StoreOps.cpp
//
// Advanced Technology Group (ATG)
// Copyright (C) Microsoft Corporation. All rights reserved.
//--------------------------------------------------------------------------------------

#include "pch.h"
#include "PlayFabCommerce.h"

#include <collection.h>

using namespace Windows::Services::Store;

void Sample::SetStoreContext(Windows::Xbox::System::User^ user)
{
    m_storeContext = Windows::Services::Store::StoreContext::GetForUser(user);

    concurrency::create_task(m_storeContext->GetAppLicenseAsync())
        .then([this](StoreAppLicense ^license)
    {
        m_console->Format(L"%s %d %d\n", license->SkuStoreId->Data(), license->IsTrial, license->IsTrialOwnedByThisUser);
    });
}

// See https://docs.microsoft.com/en-us/uwp/api/Windows.Services.Store.StoreContext for API docs

void Sample::RetrieveMSCatalog()
{
    m_inProgress = true;

    auto productKinds = ref new Platform::Collections::Vector<Platform::String^>{ L"Consumable" };

    concurrency::create_task(m_storeContext->GetAssociatedStoreProductsAsync(productKinds))
        .then([this](StoreProductQueryResult ^result)
    {
        if (SUCCEEDED(result->ExtendedError.Value))
        {
            m_console->Format(L"%d products\n", result->Products->Size);
            for (auto& product : result->Products)
            {
                m_console->Format(L"%s: %s\n", product->Key->Data(), product->Value->Title->Data());

                m_XboxConsumables.insert_or_assign(product->Key->Data(), product->Value);

                for (auto image : product->Value->Images)
                {
                    // initiate download for the 300x300 app tile icon
                    if (image->ImagePurposeTag == L"Logo")
                    {
                        // use store id as image name
                        m_imageManager->DownloadImage(image->Uri->AbsoluteUri->Data(), product->Key->Data());
                    }
                }
            }

            m_updateUI = true;
            m_inProgress = false;

            UpdateQuantities();
        }
        else
        {
            m_console->Format(L"GetAssociatedStoreProductsAsync error 0x%x\n", result->ExtendedError.Value);
        }
    });

}

void Sample::UpdateQuantities()
{
    // For information purposes only
    // Consumption of consumable quantity is securely transacted server to server by ConsumeXboxEntitlements

    for (auto& c : m_XboxConsumables)
    {
        concurrency::create_task(m_storeContext->GetConsumableBalanceRemainingAsync(ref new Platform::String(c.first.c_str())))
            .then([this, &c](StoreConsumableResult^ result)
        {
            c.second.quantity = result->BalanceRemaining;
            m_console->Format(L"Store consumable %s quantity %u\n", c.first.c_str(), result->BalanceRemaining);
            m_updateUI = true;
        });
    }
}


void Sample::PurchaseMSItem(Platform::String^ storeId)
{
    // Invokes real money purchase
    concurrency::create_task(m_storeContext->RequestPurchaseAsync(storeId))
        .then([this](StorePurchaseResult^ result)
    {
        if (SUCCEEDED(result->ExtendedError.Value))
        {
            if (!IsManualConsumeXboxConsumables())
            {
                ConsumeXboxConsumables();
            }
            else
            {
                UpdateQuantities();
            }
        }
    });
}

void Sample::ForceWipeMSQuantities()
{
    for (auto& c : m_XboxConsumables)
    {
        concurrency::create_task(m_storeContext->GetConsumableBalanceRemainingAsync(ref new Platform::String(c.first.c_str())))
            .then([this, &c](StoreConsumableResult^ result)
        {
            c.second.quantity = result->BalanceRemaining;

            if (c.second.quantity > 0)
            {
                Platform::Guid trackingId;
                GUID guid;

                HRESULT hr = CoCreateGuid(&guid);
                if (SUCCEEDED(hr))
                {
                    trackingId = guid;
                }

                concurrency::create_task(m_storeContext->ReportConsumableFulfillmentAsync(ref new Platform::String(c.first.c_str()), c.second.quantity, trackingId))
                    .then([this, &c](StoreConsumableResult^ result)
                {
                    if (SUCCEEDED(result->ExtendedError.Value))
                    {
                        m_console->Format(L"Consumed %d of %s\n", c.second.quantity, c.first.c_str());
                        c.second.quantity = 0;
                    }
                    else
                    {
                        m_console->Format(L"ReportConsumableFulfillmentAsync error 0x%x\n", result->ExtendedError.Value);
                    }
                });
            }
        });
    }
}