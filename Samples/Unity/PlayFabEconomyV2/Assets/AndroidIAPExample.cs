using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

using Unity.VisualScripting;
using UnityEngine;
using UnityEngine.Purchasing;
using UnityEngine.Purchasing.Extension;

using PlayFab;
using PlayFab.ClientModels;
using PlayFab.EconomyModels;

using CatalogItem = PlayFab.EconomyModels.CatalogItem;

/**
 * Unity behavior that implements the the Unity IAP Store interface.
 * 
 * Attach as an asset to your Scene.
 */
public class AndroidIAPExample : MonoBehaviour, IDetailedStoreListener
{

    // Bundles for sale on the Google Play Store.
    private Dictionary<string, PlayFab.EconomyModels.CatalogItem> GooglePlayCatalog;

    // In-game items for sale at the example vendor.
    private Dictionary<string, PlayFab.EconomyModels.CatalogItem> StorefrontCatalog;

    private string purchaseIdempotencyId = null;

    private PlayFabEconomyAPIAsyncResult lastAPICallResult = null;

    private static PlayFabEconomyAPIAsync economyAPI = new();

    private static IStoreController m_StoreController;

    /**
     * True if the Store Controller, extensions, and Catalog are set.
     */
    public bool IsInitialized
    {
        get
        {
            return m_StoreController != null
                && GooglePlayCatalog != null
                && StorefrontCatalog != null;
        }
    }

    /**
     * Returns false as this is just sample code.
     * 
     * @todo Implement this functionality for your game.
     */
    public bool UserHasExistingSave
    {
        get
        {
            return false;
        }
    }

    /**
     * Integrates game purchasing with the Unity IAP API.
     */
    public void BuyProductByID(string productID)
    {
        if (!IsInitialized) throw new Exception("IAP Service is not initialized!");

        m_StoreController.InitiatePurchase(productID);
    }

    /**
     * Purchases a PlayFab inventory item by ID.
     * 
     * @see the PlayFabEconomyAPIAsync class for details on error handling
     * and calling patterns.
     */
    async public Task<bool> PlayFabPurchaseItemByID(string itemID, PlayFabEconomyAPIAsyncResult result)
    {
        if (!IsInitialized) throw new Exception("IAP Service is not initialized!");

        Debug.Log("Player buying product " + itemID);

        if (string.IsNullOrEmpty(purchaseIdempotencyId))
        {
            purchaseIdempotencyId = Guid.NewGuid().ToString();
        }

        GetItemRequest getVillagerStoreRequest = new GetItemRequest()
        {
            AlternateId = new CatalogAlternateId()
            {
                Type = "FriendlyId",
                Value = "villagerstore"
            }
        };
        GetItemResponse getStoreResponse = await economyAPI.getItemAsync(getVillagerStoreRequest);
        if (getStoreResponse == null || string.IsNullOrEmpty(getStoreResponse?.Item?.Id))
        {
            result.error = "Unable to contact the store. Check your internet connection and try again in a few minutes.";
            return false;
        }

        CatalogPriceAmount price = StorefrontCatalog.FirstOrDefault(item => item.Key == itemID).Value.PriceOptions.Prices.FirstOrDefault().Amounts.FirstOrDefault();
        PurchaseInventoryItemsRequest purchaseInventoryItemsRequest = new PurchaseInventoryItemsRequest()
        {
            Amount = 1,
            Item = new InventoryItemReference()
            {
                Id = itemID
            },
            PriceAmounts = new List<PurchasePriceAmount>
            {
                new PurchasePriceAmount()
                {
                    Amount = price.Amount,
                    ItemId = price.ItemId
                }
            },
            IdempotencyId = purchaseIdempotencyId,
            StoreId = getStoreResponse.Item.Id
        };
        PurchaseInventoryItemsResponse purchaseInventoryItemsResponse = await economyAPI.purchaseInventoryItemsAsync(purchaseInventoryItemsRequest);
        if (purchaseInventoryItemsResponse == null || purchaseInventoryItemsResponse?.TransactionIds.Count < 1)
        {
            result.error = "Unable to purchase. Try again in a few minutes.";
            return false;
        }

        purchaseIdempotencyId = "";
        result.message = "Purchasing!";
        return true;
    }

    private void InitializePurchasing()
    {
        if (IsInitialized) return;

        var builder = ConfigurationBuilder.Instance(StandardPurchasingModule.Instance(AppStore.GooglePlay));

        foreach (CatalogItem item in GooglePlayCatalog.Values)
        {
            var googlePlayItemId = item.AlternateIds.FirstOrDefault(item => item.Type == "GooglePlay")?.Value;
            if (!googlePlayItemId.IsUnityNull()) {
                builder.AddProduct(googlePlayItemId, ProductType.Consumable);
            }
        }

        UnityPurchasing.Initialize(this, builder);
    }

    /**
     * Attempts to log the player in via the Android Device ID.
     */
    private void Login()
    {
        // Best practice is to soft-login with a unique ID, then prompt the player to finish 
        // creating a PlayFab account in order to retrive cross-platform saves or other benefits.
        if (UserHasExistingSave)
        {
            // @todo Integrate this with the save system.
            LoginWithPlayFabRequest loginWithPlayFabRequest = new()
            {
                Username = "",
                Password = ""
            };
            PlayFabClientAPI.LoginWithPlayFab(loginWithPlayFabRequest, OnRegistration, OnPlayFabError);
            return;
        }

        // AndroidDeviceID will prompt for permissions on newer devices.
        // Using a non-device specific GUID and saving to a local file
        // is a better approach. PlayFab does allow you to link multiple
        // Android device IDs to a single PlayFab account.
        PlayFabClientAPI.LoginWithAndroidDeviceID(new LoginWithAndroidDeviceIDRequest()
        {
            CreateAccount = true,
            AndroidDeviceId = SystemInfo.deviceUniqueIdentifier
        }, result => {
            RefreshIAPItems();
        }, error => Debug.LogError(error.GenerateErrorReport()));
    }

    /**
     * Draw a debug IMGUI for testing examples.
     *
     * Use UI Toolkit for your production game runtime UI instead.
     */
    public void OnGUI()
    {
        // Support high-res devices.
        GUI.matrix = Matrix4x4.TRS(new Vector3(0, 0, 0), Quaternion.identity, new Vector3(3, 3, 3));

        if (!IsInitialized)
        {
            GUILayout.Label("Initializing IAP and logging in...");
            return;
        }

        if (!string.IsNullOrEmpty(purchaseIdempotencyId)
            && (!string.IsNullOrEmpty(lastAPICallResult?.message)
                || !string.IsNullOrEmpty(lastAPICallResult?.error)))
        {
            GUILayout.Label(lastAPICallResult?.message + lastAPICallResult?.error);
        }

        GUILayout.Label("Shop for game currency bundles.");
        // Draw a purchase menu for each catalog item.
        foreach (CatalogItem item in GooglePlayCatalog.Values)
        {
            // Use a dictionary to select the proper language.
            if (GUILayout.Button("Get " + (item.Title.ContainsKey("en-US") ? item.Title["en-US"] : item.Title["NEUTRAL"])))
            {
                BuyProductByID(item.AlternateIds.FirstOrDefault(item => item.Type == "GooglePlay").Value);
            }
        }

        GUILayout.Label("Hmmm. (Translation: Welcome to my humble Villager store.)");
        // Draw a purchase menu for each catalog item.
        foreach (CatalogItem item in StorefrontCatalog.Values)
        {
            // Use a dictionary to select the proper language.
            if (GUILayout.Button("Buy "
                + (item.Title.ContainsKey("en-US") ? item.Title["en-US"] : item.Title["NEUTRAL"]
                + ": "
                + item.PriceOptions.Prices.FirstOrDefault().Amounts.FirstOrDefault().Amount.ToString()
                + " Diamonds"
                )))
            {
                PlayFabPurchaseItemByID(item.Id, lastAPICallResult);
            }
        }
    }

    private void OnRegistration(LoginResult result)
    {
        PlayFabSettings.staticPlayer.ClientSessionTicket = result.SessionTicket;
    }

    public void OnInitialized(IStoreController controller, IExtensionProvider extensions)
    {
        m_StoreController = controller;
    }

    public void OnInitializeFailed(InitializationFailureReason error)
    {
        Debug.Log("OnInitializeFailed InitializationFailureReason:" + error);
    }

    public void OnInitializeFailed(InitializationFailureReason error, string message)
    {
        Debug.Log("OnInitializeFailed InitializationFailureReason:" + error + message);
    }

    private void OnPlayFabError(PlayFabError error)
    {
        Debug.LogError(error.GenerateErrorReport());
    }

    public void OnPurchaseFailed(UnityEngine.Purchasing.Product product, PurchaseFailureReason failureReason)
    {
        Debug.Log(string.Format("OnPurchaseFailed: FAIL. Product: '{0}', PurchaseFailureReason: {1}",
            product.definition.storeSpecificId, failureReason));
    }

    public void OnPurchaseFailed(UnityEngine.Purchasing.Product product, PurchaseFailureDescription failureDescription)
    {
        Debug.Log(string.Format("OnPurchaseFailed: FAIL. Product: '{0}', PurchaseFailureReason: {1}",
            product.definition.storeSpecificId, failureDescription));
    }

    /**
     * Callback for Store purchases.
     * 
     * @note This code does not account for purchases that were pending and are
     *   delivered on application start. Production code should account for these
     *   cases.
     *
     * @see https://docs.unity3d.com/Packages/com.unity.purchasing@4.8/api/UnityEngine.Purchasing.PurchaseProcessingResult.html
     */
    public PurchaseProcessingResult ProcessPurchase(PurchaseEventArgs purchaseEvent)
    {
        if (!IsInitialized)
        {
            return PurchaseProcessingResult.Complete;
        }

        if (purchaseEvent.purchasedProduct == null)
        {
            Debug.LogWarning("Attempted to process purchase with unknown product. Ignoring.");
            return PurchaseProcessingResult.Complete;
        }

        if (string.IsNullOrEmpty(purchaseEvent.purchasedProduct.receipt))
        {
            Debug.LogWarning("Attempted to process purchase with no receipt. Ignoring.");
            return PurchaseProcessingResult.Complete;
        }

        Debug.Log("Attempting purchase with receipt " + purchaseEvent.purchasedProduct.receipt.Serialize().ToString());
        RedeemGooglePlayInventoryItemsRequest request = new()
        {
            Purchases = new List<GooglePlayProductPurchase> {
                new GooglePlayProductPurchase() {
                    ProductId = purchaseEvent.purchasedProduct.receipt,
                    Token = GooglePurchase.FromJson(purchaseEvent.purchasedProduct.receipt).PayloadData?.signature
                }
            }
        };
        RedeemGooglePlayInventoryItemsResponse redeemResponse = new();
        PlayFabEconomyAPI.RedeemGooglePlayInventoryItems(request, result => {
            redeemResponse = result;
            Debug.Log("Processed receipt validation.");
        },
            error => Debug.Log("Validation failed: " + error.GenerateErrorReport()));
        if (redeemResponse?.Failed.Count > 0)
        {
            Debug.Log("Validation failed for " + redeemResponse.Failed.Count + " receipts.");
            Debug.Log(redeemResponse.Failed.Serialize().ToSafeString());
        }
        else
        {
            Debug.Log("Validation succeeded!");
        }

        return PurchaseProcessingResult.Complete;
    }

    /**
     * Queries the PlayFab Economy Catalog V2 for updated listings
     * and then fills the local catalog objects.
     */
    private async void RefreshIAPItems()
    {
        GooglePlayCatalog = new Dictionary<string, PlayFab.EconomyModels.CatalogItem>();
        SearchItemsRequest playCatalogRequest = new()
        {
            Count = 50,
            Filter = "Platforms/any(platform: platform eq 'GooglePlay')"
        };
        SearchItemsResponse playCatalogResponse;
        do
        {
            playCatalogResponse = await economyAPI.searchItemsAsync(playCatalogRequest);
            Debug.Log("Search response: " + playCatalogResponse.Serialize().ToSafeString());
            foreach (CatalogItem item in playCatalogResponse.Items)
            {
                GooglePlayCatalog.Add(item.Id, item);
            }
        } while (playCatalogResponse.ContinuationToken != null
            && playCatalogResponse.ContinuationToken != "");
        Debug.Log("Completed pulling from PlayFab Economy v2 googleplay Catalog: "
            + GooglePlayCatalog.Count()
            + " items retrieved");

        StorefrontCatalog = new Dictionary<string, PlayFab.EconomyModels.CatalogItem>();
        GetItemRequest storeCatalogRequest = new()
        {
            AlternateId = new CatalogAlternateId()
            {
                Type = "FriendlyId",
                Value = "villagerstore"
            }
        };
        GetItemResponse storeCatalogResponse;
        storeCatalogResponse = await economyAPI.getItemAsync(storeCatalogRequest);
        List<string> itemIds = new() { };
        foreach (CatalogItemReference item in storeCatalogResponse.Item.ItemReferences)
        {
            itemIds.Add(item.Id);
        }
        GetItemsRequest itemsCatalogRequest = new()
        {
            Ids = itemIds
        };
        GetItemsResponse itemsCatalogResponse = await economyAPI.getItemsAsync(itemsCatalogRequest);
        foreach (CatalogItem item in itemsCatalogResponse.Items)
        {
            StorefrontCatalog.Add(item.Id, item);
        }
        Debug.Log("Completed pulling from PlayFab Economy v2 villagerstore store: "
            + StorefrontCatalog.Count()
            + " items retrieved");
        
        InitializePurchasing();
    }

    // Start is called before the first frame update.
    public void Start()
    {
        Login();
    }

    // Update is called once per frame.
    public void Update() { }
}

// Utility classes for the sample.
public class PlayFabEconomyAPIAsyncResult
{
    public string error = null;

    public string message = null;
}

/**
 * Example Async wrapper for PlayFab API's.
 * 
 * This is just a quick sample for example purposes.
 * 
 * Write your own customer Logger implementation to log and handle errors
 * for user-facing scenarios. Use tags and map which PlayFab errors require your
 * game to handle GUI or gameplay updates vs which should be logged to crash and
 * error reporting services.
 */
public class PlayFabEconomyAPIAsync
{
    // @see https://learn.microsoft.com/en-us/rest/api/playfab/economy/catalog/get-item
    private TaskCompletionSource<GetItemResponse> getItemAsyncTaskSource;

    public void onGetItemRequestComplete(GetItemResponse response)
    {
        getItemAsyncTaskSource.SetResult(response);
    }

    public Task<GetItemResponse> getItemAsync(GetItemRequest request)
    {
        getItemAsyncTaskSource = new();
        PlayFabEconomyAPI.GetItem(request, onGetItemRequestComplete, error => Debug.LogError(error.GenerateErrorReport()));
        return getItemAsyncTaskSource.Task;
    }

    // @see https://learn.microsoft.com/en-us/rest/api/playfab/economy/catalog/get-items
    private TaskCompletionSource<GetItemsResponse> getItemsAsyncTaskSource;

    public void onGetItemsRequestComplete(GetItemsResponse response)
    {
        getItemsAsyncTaskSource.SetResult(response);
    }

    public Task<GetItemsResponse> getItemsAsync(GetItemsRequest request)
    {
        getItemsAsyncTaskSource = new();
        PlayFabEconomyAPI.GetItems(request, onGetItemsRequestComplete, error => Debug.LogError(error.GenerateErrorReport()));
        return getItemsAsyncTaskSource.Task;
    }

    // @see https://learn.microsoft.com/en-us/rest/api/playfab/economy/inventory/purchase-inventory-items
    private TaskCompletionSource<PurchaseInventoryItemsResponse> purchaseInventoryItemsAsyncTaskSource;

    public void OnPurchaseInventoryItemsRequestComplete(PurchaseInventoryItemsResponse response)
    {
        purchaseInventoryItemsAsyncTaskSource.SetResult(response);
    }

    public Task<PurchaseInventoryItemsResponse> purchaseInventoryItemsAsync(PurchaseInventoryItemsRequest request)
    {
        purchaseInventoryItemsAsyncTaskSource = new();
        PlayFabEconomyAPI.PurchaseInventoryItems(request,
            OnPurchaseInventoryItemsRequestComplete,
            error => { Debug.LogError(error.GenerateErrorReport()); });
        return purchaseInventoryItemsAsyncTaskSource.Task;
    }

    // @see https://learn.microsoft.com/en-us/rest/api/playfab/economy/catalog/search-items
    private TaskCompletionSource<SearchItemsResponse> searchItemsAsyncTaskSource;

    public void OnSearchItemsRequestComplete(SearchItemsResponse response)
    {
        searchItemsAsyncTaskSource.SetResult(response);
    }

    public Task<SearchItemsResponse> searchItemsAsync(SearchItemsRequest request) {
        searchItemsAsyncTaskSource = new();
        PlayFabEconomyAPI.SearchItems(request, OnSearchItemsRequestComplete, error => Debug.LogError(error.GenerateErrorReport()));
        return searchItemsAsyncTaskSource.Task;
    }
}

public class PurchaseJsonData
{
    public string orderId;
    public string packageName;
    public string productId;
    public long   purchaseTime;
    public int    purchaseState;
    public string purchaseToken;
}

public class PurchasePayloadData
{
    public PurchaseJsonData JsonData;

    public string signature;
    public string json;

    public static PurchasePayloadData FromJson(string json)
    {
        var payload = JsonUtility.FromJson<PurchasePayloadData>(json);
        payload.JsonData = JsonUtility.FromJson<PurchaseJsonData>(json);
        return payload;
    }
}

public class GooglePurchase
{
    public PurchasePayloadData PayloadData;

    public string Store;
    public string TransactionID;
    public string Payload;

    public static GooglePurchase FromJson(string json)
    {
        var purchase = JsonUtility.FromJson<GooglePurchase>(json);
        // Only fake receipts are returned in Editor play.
        if (Application.isEditor)
        {
            return purchase;
        }
        purchase.PayloadData = PurchasePayloadData.FromJson(purchase.Payload);
        return purchase;
    }
}
