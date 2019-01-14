package atg.xbox.PlayFabCommerce;

import android.app.Activity;
import android.util.Log;

import com.playfab.PlayFabClientAPI;
import com.playfab.PlayFabClientModels;
import com.playfab.PlayFabErrors;
import com.playfab.PlayFabSettings;

import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Objects;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.FutureTask;

public class PlayFabOpManager
{
    private static PlayFabOpManager sInstance = null;

    private final String TAG = getClass().getSimpleName();

    private final Map<String, PlayFabClientModels.CatalogItem> mCatalogItems = new HashMap<>();
    private final Map<String, Long> mStorePrices = new HashMap<>();
    private final Map<String, PlayFabClientModels.ItemInstance> mInventoryItems = new HashMap<>();
    private final Map<String, Integer> mVirtualConsumables = new HashMap<>();
    private final Map<String, Integer> mVirtualCurrencies = new HashMap<>();

    private final String cVC = "TC";
    private final String cTitleId = "4E29";
    private final String cCatalogId = "0.1";
    private final String cStoreId = "Normal";

    public static PlayFabOpManager getInstance()
    {
        if(sInstance == null)
        {
            sInstance = new PlayFabOpManager();
        }

        return sInstance;
    }

    public Map<String, PlayFabClientModels.CatalogItem> getCatalogItems()
    {
        return mCatalogItems;
    }

    public Map<String, Long> getStorePrices()
    {
        return mStorePrices;
    }

    public Map<String, PlayFabClientModels.ItemInstance> getInventoryItems() { return mInventoryItems; }

    public Map<String, Integer> getVirtualConsumables()
    {
        return mVirtualConsumables;
    }

    public Map<String, Integer> getVirtualCurrencies()
    {
        return mVirtualCurrencies;
    }

    // Copied from doc code snippets. This is a utility function PlayFab hasn't put into the core SDK yet.
    private <RT> String CompileErrorsFromResult(PlayFabErrors.PlayFabResult<RT> result)
    {
        if (result == null || result.Error == null)
        {
            return null;
        }

        String errorMessage = "";
        if (result.Error.errorMessage != null)
        {
            errorMessage += result.Error.errorMessage;
        }
        if (result.Error.errorDetails != null)
        {
            for (Map.Entry<String, List<String>> pair : result.Error.errorDetails.entrySet())
            {
                for (String msg : pair.getValue())
                {
                    errorMessage += "\n" + pair.getKey() + ": " + msg;
                }
            }
        }
        return errorMessage;
    }

    public String LoginWithGoogleAccount(final String authCode)
    {
        PlayFabSettings.TitleId = cTitleId;

        // https://api.playfab.com/documentation/Client/method/LoginWithGoogleAccount
        PlayFabClientModels.LoginWithGoogleAccountRequest req = new PlayFabClientModels.LoginWithGoogleAccountRequest();

        req.TitleId = PlayFabSettings.TitleId;
        req.ServerAuthCode = authCode;
        req.CreateAccount = true;

        PlayFabErrors.PlayFabResult<PlayFabClientModels.LoginResult> result = PlayFabClientAPI.LoginWithGoogleAccount(req);

        String errors = PlayFabOpManager.getInstance().CompileErrorsFromResult(result);
        Log.d(TAG, "LoginWithGoogleAccount: " + (errors == null? "success" : errors));

        if(errors == null);
        {
            Log.d(TAG, "PlayFabId " + result.Result.PlayFabId + " newlyCreated " + result.Result.NewlyCreated);
        }

        return errors;
    }

    public void RetrievePFCatalog()
    {
        // https://api.playfab.com/documentation/client/method/GetCatalogItems
        PlayFabClientModels.GetCatalogItemsRequest req = new PlayFabClientModels.GetCatalogItemsRequest();

        PlayFabErrors.PlayFabResult<PlayFabClientModels.GetCatalogItemsResult> result = PlayFabClientAPI.GetCatalogItems(req);
        String errors = CompileErrorsFromResult(result);

        Log.d(TAG, "GetCatalogItems: " + (errors == null? "success" : errors));
        if(result.Result != null)
        {
            mCatalogItems.clear();

            Log.d(TAG,result.Result.Catalog.size() + " items");
            for(PlayFabClientModels.CatalogItem item : result.Result.Catalog)
            {
                Log.d(TAG, "Catalog Item ID: " + item.ItemId + " DisplayName: " + item.DisplayName);

                mCatalogItems.put(item.ItemId, item);
            }
        }
    }

    public void UpdatePFInventory()
    {
        PlayFabClientModels.GetUserInventoryRequest req = new PlayFabClientModels.GetUserInventoryRequest();

        PlayFabErrors.PlayFabResult<PlayFabClientModels.GetUserInventoryResult> result = PlayFabClientAPI.GetUserInventory(req);

        String errors = CompileErrorsFromResult(result);

        Log.d(TAG, "GetUserInventory: " + (errors == null? "success" : errors));
        if(result.Result != null)
        {
            mInventoryItems.clear();
            mVirtualConsumables.clear();
            for (PlayFabClientModels.ItemInstance item : result.Result.Inventory)
            {
                mInventoryItems.put(item.ItemId, item);

                Log.d(TAG, "Inventory Item ID: " + item.ItemId +
                        " DisplayName: " + item.DisplayName +
                        " RemainingUses: " + item.RemainingUses +
                        " ItemInstanceId " + item.ItemInstanceId);

                if (item.BundleContents == null)
                {
                    // Only consider catalog items and not bundles, only these are displayed in UI
                    // Inventory may have multiple instances of an item (if not stackable), so make sure to accumulate
                    Integer count = mVirtualConsumables.containsKey(item.ItemId) ?
                            mVirtualConsumables.get(item.ItemId) + item.RemainingUses :
                            item.RemainingUses;

                    mVirtualConsumables.put(item.ItemId, count);
                }
            }

            for (Map.Entry<String, Integer> pair : result.Result.VirtualCurrency.entrySet())
            {
                mVirtualCurrencies.put(pair.getKey(), pair.getValue());
            }
        }
    }

    public void UpdatePFStorePrices()
    {
        // 4E29 catalog implemented a store, which can alter prices based on player segments
        PlayFabClientModels.GetStoreItemsRequest req = new PlayFabClientModels.GetStoreItemsRequest();
        req.StoreId = cStoreId;

        PlayFabErrors.PlayFabResult<PlayFabClientModels.GetStoreItemsResult> result = PlayFabClientAPI.GetStoreItems(req);

        String errors = CompileErrorsFromResult(result);
        Log.d(TAG, "GetStoreItems: " + (errors == null? "success" : errors));

        if(result.Result != null)
        {
            for(PlayFabClientModels.StoreItem item : result.Result.Store)
            {
                Log.d(TAG, "Store Item ID: " + item.ItemId);

                if(item.VirtualCurrencyPrices.containsKey(cVC))
                {
                    mStorePrices.put(item.ItemId, Objects.requireNonNull(item.VirtualCurrencyPrices.get(cVC)));
                }
            }
        }
    }

    public void PurchasePFItem(final String itemId, final Long currentPrice, final Activity activity, final PlayFabMain.PlayFabPurchaseListener purchaseListener)
    {
        // This utilizes the Async variant of the API in order to not block the UI thread
        // Purchasing bundles that grant large numbers of items will tend to take quite some time
        final Thread thread = new Thread()
        {
            public void run()
            {
                // https://api.playfab.com/documentation/client/method/PurchaseItem
                final PlayFabClientModels.PurchaseItemRequest req = new PlayFabClientModels.PurchaseItemRequest();
                req.ItemId = itemId;
                req.Price = currentPrice.intValue();
                req.StoreId = cStoreId;
                req.VirtualCurrency = cVC;

                FutureTask<PlayFabErrors.PlayFabResult<PlayFabClientModels.PurchaseItemResult>> task = PlayFabClientAPI.PurchaseItemAsync(req);
                task.run();

                while(task != null)
                {
                    try
                    {
                        if (task.isDone())
                        {
                            PlayFabErrors.PlayFabResult<PlayFabClientModels.PurchaseItemResult> result;

                            result = task.get();
                            final String errors = CompileErrorsFromResult(result);
                            Log.d(TAG, "PurchaseItem: " + (errors == null ? "success" : errors));

                            if (result.Result != null)
                            {
                                for (PlayFabClientModels.ItemInstance item : result.Result.Items)
                                {
                                    Log.d(TAG, "Purchased Item ID: " + item.ItemId + " DisplayName: " + item.DisplayName.toString());
                                }

                                UpdatePFInventory();
                                UpdatePFStorePrices();
                            }

                            // callback for PlayFabMain to invoke UI update
                            purchaseListener.onPurchaseComplete(errors);

                            task = null;
                            this.join();
                        }

                        Thread.sleep(100);
                    }
                    catch (InterruptedException | ExecutionException e)
                    {
                        e.printStackTrace();
                    }
                }
            }
        };

        thread.start();
    }

    public void ConsumePFItem(String itemId)
    {
        if(mInventoryItems.containsKey(itemId))
        {
            PlayFabClientModels.ItemInstance it = mInventoryItems.get(itemId);
            if(it.RemainingUses > 0)
            {
                // https://api.playfab.com/documentation/client/method/ConsumeItem
                PlayFabClientModels.ConsumeItemRequest req = new PlayFabClientModels.ConsumeItemRequest();
                req.ItemInstanceId = it.ItemInstanceId;
                req.ConsumeCount = 1;

                PlayFabErrors.PlayFabResult<PlayFabClientModels.ConsumeItemResult> result = PlayFabClientAPI.ConsumeItem(req);

                String errors = CompileErrorsFromResult(result);
                Log.d(TAG, "ConsumeItem: " + (errors == null? "success" : errors));

                if(result.Result != null)
                {
                    Log.d(TAG, itemId + " consumed, " + result.Result.RemainingUses + " remaining");

                    UpdatePFInventory();
                }
            }
        }
    }

    public boolean ValidateGooglePlayPurchase(String sku, String receiptJson, String signature, String currencyCode, Long purchasePrice)
    {
        // https://api.playfab.com/documentation/client/method/ValidateGooglePlayPurchase
        PlayFabClientModels.ValidateGooglePlayPurchaseRequest req = new PlayFabClientModels.ValidateGooglePlayPurchaseRequest();

        req.ReceiptJson = receiptJson;
        req.Signature = signature;

        // The price value will be added to the Value to date for the player.
        // This can be seen in the Player overview and also globally for the title in the PlayFab Dashboard
        // Note that by default the currencyCode does not affect anything, and the integer is assumed to be USD
        // Contact PlayFab devrel for enabling a conversion service that would do the proper conversion
        req.CurrencyCode = currencyCode;
        req.PurchasePrice = purchasePrice;

        Log.d(TAG, "Sku: " + sku + " PriceMicros: " + purchasePrice + " CurrencyCode: " + currencyCode);

        PlayFabErrors.PlayFabResult<PlayFabClientModels.ValidateGooglePlayPurchaseResult> result = PlayFabClientAPI.ValidateGooglePlayPurchase(req);

        String errors = CompileErrorsFromResult(result);
        Log.d(TAG, "ValidateGooglePlayPurchase: " + (errors == null? "success" : errors));

        if(result.Result != null)
        {
            Log.d(TAG, "Successful validation of " + sku + "! Refreshing inventory...");

            UpdatePFInventory();
        }

        return (errors == null);
    }
}