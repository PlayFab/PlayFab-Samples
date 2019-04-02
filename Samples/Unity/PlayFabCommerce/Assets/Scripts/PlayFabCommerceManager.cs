using System.Collections.Generic;
using PlayFab.ClientModels;
using UnityEngine;
using UnityEngine.Purchasing;
using PlayFab;
using PlayFab.Json;
using System;

// Used by the UI to display the catalog items
public interface ICatalogItem
{
    string Id { get; }
    string DisplayName { get; }
    string CostString { get; }
    bool IsNativeCatalog { get; }
}

public class PlayFabCommerceManager : MonoBehaviour, IStoreListener {

    private static PlayFabCommerceManager _instance;
    public static PlayFabCommerceManager Instance
    {
        get
        {
            if (_instance == null)
            {
                _instance = new PlayFabCommerceManager();
            }
            return _instance;
        }
    }

    // Configuration for PlayFab APIs
    private readonly string cStoreId = "Normal";
    private readonly string cVC = "TC";

    // UI Objects
    public ProductViewManager catalogView;
    public InventoryViewManager inventoryView;
    public GameObject spinnerScreen;

    // Unity IAP for real money purchases
    private IStoreController controller;
    private IExtensionProvider extensions;

    // Objects for locally caching catalog and player inventory
    private Dictionary<string, ICatalogItem> catalog = new Dictionary<string, ICatalogItem>();
    private Dictionary<string, PlayFab.ClientModels.ItemInstance> playerInventory = new Dictionary<string, ItemInstance>();
    private Dictionary<string, int> playerWallet = new Dictionary<string, int>();

    // Use this for initialization
    void Start()
    {
        _instance = this;

        // Set up Unity IAP for real money purchases
#if UNITY_ANDROID && !UNITY_EDITOR
        // https://docs.unity3d.com/Manual/UnityIAPGoogleConfiguration.html
        var builder = ConfigurationBuilder.Instance(StandardPurchasingModule.Instance());

        builder.AddProduct("100tc", ProductType.Consumable, new IDs
        {
            { "100tc", GooglePlay.Name }
        }).AddProduct("1000tc", ProductType.Consumable, new IDs
        {
            { "1000tc", GooglePlay.Name }
        });

        UnityPurchasing.Initialize(this, builder);
#endif

        PlayFabAuthService.OnLoginSuccess += SignInSuccess;

    }

    // When the user is signed in update the catalog and their inventory
    private void SignInSuccess(LoginResult success)
    {
        RefreshCatalog();
        RefreshInventory();

        catalogView.ViewInit();
        inventoryView.ViewInit();
    }

    internal void RefreshCatalog()
    {
        catalog.Clear();

        // If we aren't in the editor, add the real money items to the catalog
#if UNITY_ANDROID && !UNITY_EDITOR
        catalog.Add("100tc", new NativeCatalogItem
        {
            item = controller.products.WithID("100tc")
        });

        catalog.Add("1000tc", new NativeCatalogItem
        {
            item = controller.products.WithID("1000tc")
        });
#endif

        PlayFabClientAPI.GetCatalogItems(new PlayFab.ClientModels.GetCatalogItemsRequest(), AquiredCatalogItems, OnError);
    }

    private void AquiredCatalogItems(GetCatalogItemsResult result)
    {
        var list = new List<ICatalogItem>();
        foreach (var item in result.Catalog)
        {
            if (item.VirtualCurrencyPrices != null && item.VirtualCurrencyPrices.ContainsKey("TC"))
            {
                var catalogItem = new PlayFabCatalogItem { item = item };
                catalog.Add(item.ItemId, catalogItem);
                list.Add(catalogItem);
            }
        }

#if UNITY_ANDROID && !UNITY_EDITOR
        list.Add(catalog["100tc"]);
        list.Add(catalog["1000tc"]);
#endif

        catalogView.AquiredCatalogItems(list);

        // The prices of catalog items might have changed due to user possible user segment changes based on purchase
        PlayFabClientAPI.GetStoreItems(new GetStoreItemsRequest() { StoreId = cStoreId },
            storeResult =>
            {
                foreach (var item in storeResult.Store)
                {
                    ((PlayFabCatalogItem)catalog[item.ItemId]).item.VirtualCurrencyPrices = item.VirtualCurrencyPrices;

                    catalogView.RefreshStorePrices();
                }
            },
            OnError);
    }

    internal void RefreshInventory()
    {
        PlayFabClientAPI.GetUserInventory(new PlayFab.ClientModels.GetUserInventoryRequest(), UpdatePlayerInventory, OnError);
    }

    internal void UpdatePlayerInventory(GetUserInventoryResult result)
    {
        playerWallet = result.VirtualCurrency;

        inventoryView.UpdatePlayerInventory(result);
    }

    // Initiate Purchase
    internal void PurchaseItem(ICatalogItem item)
    {
        if (item.IsNativeCatalog)
        {
            // Use Unity IAP for real money purchases
            controller.InitiatePurchase(((NativeCatalogItem)item).item);
        }
        else
        {
            // PlayFab purcahse using virtual currency
            var catalogItem = ((PlayFabCatalogItem)item).item;

            var request = new PurchaseItemRequest
            {
                ItemId = catalogItem.ItemId,
                Price = (int)catalogItem.VirtualCurrencyPrices[cVC],
                StoreId = cStoreId,
                VirtualCurrency = cVC
            };

            PlayFabClientAPI.PurchaseItem(request, OnPurchaseSuccess, OnError);

            spinnerScreen.SetActive(true);
        }
    }

    internal void OnPurchaseSuccess(PurchaseItemResult result)
    {
        // After the purchase is complete, request an update to the user's inventory and 
        // update the prices in case the user segment changed
        spinnerScreen.SetActive(false);
        PlayFabClientAPI.GetUserInventory(new PlayFab.ClientModels.GetUserInventoryRequest(), UpdatePlayerInventory, OnError);

        // The prices of catalog items might have changed due to user possible user segment changes based on purchase
        PlayFabClientAPI.GetStoreItems(new GetStoreItemsRequest() { StoreId = cStoreId },
            storeResult =>
            {
                foreach (var item in storeResult.Store)
                {
                    ((PlayFabCatalogItem)catalog[item.ItemId]).item.VirtualCurrencyPrices = item.VirtualCurrencyPrices;

                    catalogView.RefreshStorePrices();
                }
            },
            OnError);
    }

    internal void ConsumeSingleItem(ItemInstance item)
    {
        PlayFabClientAPI.ConsumeItem(new ConsumeItemRequest()
        {
            ItemInstanceId = item.ItemInstanceId,
            ConsumeCount = 1
        }, result =>
        {
            Debug.Log("Consume Succeeded, " + result.RemainingUses.ToString() + " uses remaining.");
            RefreshInventory();
        },
        OnError);

    }

    // Unity IAP
    public PurchaseProcessingResult ProcessPurchase(PurchaseEventArgs e)
    {
#if UNITY_ANDROID && !UNITY_EDITOR
        // https://api.playfab.com/docs/tutorials/landing-commerce/getting-started-unity-iap-android
        var googleReceipt = GooglePurchase.FromJson(e.purchasedProduct.receipt);

        var request = new ValidateGooglePlayPurchaseRequest()
        {
            CurrencyCode = e.purchasedProduct.metadata.isoCurrencyCode,
            PurchasePrice = (uint)(e.purchasedProduct.metadata.localizedPrice * 100),
            ReceiptJson = googleReceipt.PayloadData.json,
            Signature = googleReceipt.PayloadData.signature

        };

        PlayFabClientAPI.ValidateGooglePlayPurchase(request, result => 
        {
            RefreshCatalog(); 
            RefreshInventory();
        }, OnError);
#endif

        return PurchaseProcessingResult.Complete;
    }

    // Unity IAP
    public void OnPurchaseFailed(Product i, PurchaseFailureReason p)
    {
        
    }

    // Unity IAP
    public void OnInitialized(IStoreController controller, IExtensionProvider extensions)
    {
        this.controller = controller;
        this.extensions = extensions;
    }

    // Unity IAP
    public void OnInitializeFailed(InitializationFailureReason error)
    {
    }

    private void OnError(PlayFabError error)
    {
        spinnerScreen.SetActive(false);
        Debug.Log(error);
        PopupError.ShowErrorMessage("PlayFab", error.GenerateErrorReport());
    }

    // Simple wrapper for displaying in the UI
    private class PlayFabCatalogItem : ICatalogItem
    {
        public CatalogItem item;
        public string Id { get { return item.ItemId; } }
        public string DisplayName { get { return item.DisplayName; }  }
        public string CostString { get { return item.VirtualCurrencyPrices["TC"].ToString() + " TC"; } }
        public bool IsNativeCatalog { get { return false; } }
    }

    // Simple wrapper for displaying in the UI
    private class NativeCatalogItem : ICatalogItem
    {
        public Product item;
        public string Id { get { return item.definition.id; } }

        public string DisplayName { get { return item.metadata.localizedTitle.Remove(item.metadata.localizedTitle.IndexOf('(')); } }

        public string CostString { get { return item.metadata.localizedPriceString; } }

        public bool IsNativeCatalog { get { return true; } }
    }

    // Structures used to parse Google Receipts
    // https://api.playfab.com/docs/tutorials/landing-commerce/getting-started-unity-iap-android
    public class JsonData
    {
        // Json Fields, ! Case-sensetive

        public string orderId;
        public string packageName;
        public string productId;
        public long purchaseTime;
        public int purchaseState;
        public string purchaseToken;
    }

    public class PayloadData
    {
        public JsonData JsonData;

        // Json Fields, ! Case-sensetive
        public string signature;
        public string json;

        public static PayloadData FromJson(string json)
        {
            var payload = JsonUtility.FromJson<PayloadData>(json);
            payload.JsonData = JsonUtility.FromJson<JsonData>(payload.json);
            return payload;
        }
    }

    public class GooglePurchase
    {
        public PayloadData PayloadData;

        // Json Fields, ! Case-sensetive
        public string Store;
        public string TransactionID;
        public string Payload;

        public static GooglePurchase FromJson(string json)
        {
            var purchase = JsonUtility.FromJson<GooglePurchase>(json);
            purchase.PayloadData = PayloadData.FromJson(purchase.Payload);
            return purchase;
        }
    }

}

