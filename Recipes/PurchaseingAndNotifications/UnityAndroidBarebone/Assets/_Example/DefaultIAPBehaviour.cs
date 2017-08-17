using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.Purchasing;
using UnityEngine.UI;
using PlayFab;
using PlayFab.ClientModels;
using UnityEngine.Purchasing.Security;

public class DefaultIAPBehaviour : MonoBehaviour, IStoreListener
{
    public List<CatalogItem> CatalogItems;
    public Text ReceiptValidationText;
    public Text ItemCountText;
    public Toggle ProcessReceipt;

    public string AmazonUserId;

    private static IStoreController m_StoreController;          // The Unity Purchasing system.
    private static IExtensionProvider m_StoreExtensionProvider; // The store-specific Purchasing subsystems.

    // Apple App Store-specific product identifier for the subscription product.
    private static string kProductNameAppleSubscription = "com.unity3d.subscription.new";

    // Google Play Store-specific product identifier subscription product.
    private static string kProductNameGooglePlaySubscription = "com.unity3d.subscription.original";

    public void InitializePurchasing()
    {
        // If we have already connected to Purchasing ...
        if (IsInitialized())
        {
            // ... we are done here.
            return;
        }

        // Create a builder, first passing in a suite of Unity provided stores.
        var builder = ConfigurationBuilder.Instance(StandardPurchasingModule.Instance());

        foreach (var item in CatalogItems)
        {
            if (item.ItemId == "Generic_Item_02")
            {
                builder.AddProduct(item.ItemId, ProductType.Subscription);
            }
            else
            {
                builder.AddProduct(item.ItemId, ProductType.Consumable);
            }
        }

        // Kick off the remainder of the set-up with an asynchrounous call, passing the configuration 
        // and this class' instance. Expect a response either in OnInitialized or OnInitializeFailed.
        UnityPurchasing.Initialize(this, builder);
    }

    private bool IsInitialized()
    {
        // Only say we are initialized if both the Purchasing references are set.
        return m_StoreController != null && m_StoreExtensionProvider != null;
    }

    public void OnInitialized(IStoreController controller, IExtensionProvider extensions)
    {
        // Purchasing has succeeded initializing. Collect our Purchasing references.
        Debug.Log("OnInitialized: PASS");

        // Overall Purchasing system, configured with products for this application.
        m_StoreController = controller;
        // Store specific subsystem, for accessing device-specific store features.
        m_StoreExtensionProvider = extensions;
    }

    public void OnInitializeFailed(InitializationFailureReason error)
    {
        // Purchasing set-up has not succeeded. Check error for reason. Consider sharing this reason with the user.
        Debug.Log("OnInitializeFailed InitializationFailureReason:" + error);
    }

    public void OnPurchaseFailed(Product product, PurchaseFailureReason failureReason)
    {
        // A product purchase attempt did not succeed. Check failureReason for more detail. Consider sharing 
        // this reason with the user to guide their troubleshooting actions.
        Debug.Log(string.Format("OnPurchaseFailed: FAIL. Product: '{0}', PurchaseFailureReason: {1}", product.definition.storeSpecificId, failureReason));
    }

    public PurchaseProcessingResult ProcessPurchase(PurchaseEventArgs e)
    {
        PlayFabClientAPI.WritePlayerEvent(new WriteClientPlayerEventRequest() {
            EventName = "Player_Purchase_Receipt",
            Body = new Dictionary<string, object>
            {
                {"Purchase_Receipt", e.purchasedProduct.receipt }
            }
        }, null, null);

        //TODO: Bool to send receipt to playfab or not.
        if (ProcessReceipt.isOn)
        {
#if UNITY_ANDROID
#if !UNITY_AMAZON            
            var googleReceipt = PlayFab.Json.JsonWrapper.DeserializeObject<GoogleReceipt>(e.purchasedProduct.receipt);
            PlayFabClientAPI.ValidateGooglePlayPurchase(new ValidateGooglePlayPurchaseRequest()
            {
                CurrencyCode = e.purchasedProduct.metadata.isoCurrencyCode,
                PurchasePrice = (uint)e.purchasedProduct.metadata.localizedPrice * 100,
                ReceiptJson = e.purchasedProduct.receipt,
                Signature = googleReceipt.Payload.signature
            }, (result) =>
            {
                ReceiptValidationText.text = "Valid";
                ItemCountText.text = string.Format("{0}", int.Parse(ItemCountText.text) + 1);
            }, (error) =>
            {
                ReceiptValidationText.text = "InValid";
                Debug.Log(error.GenerateErrorReport());
            });
#else
            PlayFabClientAPI.ValidateAmazonIAPReceipt(new ValidateAmazonReceiptRequest() {
                CatalogVersion = "Items",
                CurrencyCode = e.purchasedProduct.metadata.isoCurrencyCode, 
                PurchasePrice = (int)e.purchasedProduct.metadata.localizedPrice * 100,
                UserId = AmazonUserId,
                ReceiptId = e.purchasedProduct.transactionID
            },(result)=> {
                ReceiptValidationText.text = "Valid";
                ItemCountText.text = string.Format("{0}", int.Parse(ItemCountText.text) + 1);
            }, (error)=> {
                ReceiptValidationText.text = "InValid";
                Debug.Log(error.GenerateErrorReport());
            });
#endif
#endif

#if UNITY_IOS || UNITY_IPHONE
            PlayFabClientAPI.ValidateIOSReceipt(new ValidateIOSReceiptRequest() {
                CurrencyCode = e.purchasedProduct.metadata.isoCurrencyCode,
                PurchasePrice = (int)e.purchasedProduct.metadata.localizedPrice * 100,
                ReceiptData = e.purchasedProduct.receipt
            },(result)=> {
                ReceiptValidationText.text = "Valid";
                ItemCountText.text = string.Format("{0}", int.Parse(ItemCountText.text) + 1);
            }, (error)=> {
                ReceiptValidationText.text = "InValid";
                Debug.Log(error.GenerateErrorReport());
            });

#endif

#if UNIYT_WSA_10_0 && WINDOWS_UWP
            PlayFabClientAPI.ValidateWindowsStoreReceipt(new ValidateWindowsReceiptRequest() {
                CatalogVersion = "Items",
                CurrencyCode = e.purchasedProduct.metadata.isoCurrencyCode,
                PurchasePrice = (uint)e.purchasedProduct.metadata.localizedPrice * 100,
                Receipt = e.purchasedProduct.receipt
            }, (result) => {
                ReceiptValidationText.text = "Valid";
                ItemCountText.text = string.Format("{0}", int.Parse(ItemCountText.text) + 1);
            }, (error) => {
                ReceiptValidationText.text = "InValid";
                Debug.Log(error.GenerateErrorReport());
            });
#endif
        }
        return PurchaseProcessingResult.Complete;
    }

    public void BuyConsumable(string ProductId)
    {
        // Buy the consumable product using its general identifier. Expect a response either 
        // through ProcessPurchase or OnPurchaseFailed asynchronously.
        BuyProductID(ProductId);
    }

    void BuyProductID(string productId)
    {
        // If Purchasing has been initialized ...
        if (IsInitialized())
        {
            // ... look up the Product reference with the general product identifier and the Purchasing 
            // system's products collection.
            Product product = m_StoreController.products.WithID(productId);

            // If the look up found a product for this device's store and that product is ready to be sold ... 
            if (product != null && product.availableToPurchase)
            {
                Debug.Log(string.Format("Purchasing product asychronously: '{0}'", product.definition.id));
                // ... buy the product. Expect a response either through ProcessPurchase or OnPurchaseFailed 
                // asynchronously.
                m_StoreController.InitiatePurchase(product);
            }
            // Otherwise ...
            else
            {
                // ... report the product look-up failure situation  
                Debug.Log("BuyProductID: FAIL. Not purchasing product, either is not found or is not available for purchase");
            }
        }
        // Otherwise ...
        else
        {
            // ... report the fact Purchasing has not succeeded initializing yet. Consider waiting longer or 
            // retrying initiailization.
            Debug.Log("BuyProductID FAIL. Not initialized.");
        }
    }

}

public class Json
{
    public string orderId { get; set; }
    public string packageName { get; set; }
    public string productId { get; set; }
    public long purchaseTime { get; set; }
    public int purchaseState { get; set; }
    public string purchaseToken { get; set; }
}

public class Payload
{
    public Json json { get; set; }
    public string signature { get; set; }
}

public class GoogleReceipt
{
    public string Store { get; set; }
    public string TransactionID { get; set; }
    public Payload Payload { get; set; }
}
