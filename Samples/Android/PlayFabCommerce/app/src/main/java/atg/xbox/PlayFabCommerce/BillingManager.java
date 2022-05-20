//package atg.xbox.PlayFabCommerce;
//
//import android.app.Activity;
//import androidx.annotation.Nullable;
//import android.util.Log;
//
//import com.android.billingclient.api.BillingClient;
//import com.android.billingclient.api.BillingClientStateListener;
//import com.android.billingclient.api.BillingFlowParams;
//import com.android.billingclient.api.ConsumeResponseListener;
//import com.android.billingclient.api.Purchase;
//import com.android.billingclient.api.PurchasesUpdatedListener;
//import com.android.billingclient.api.SkuDetails;
//import com.android.billingclient.api.SkuDetailsParams;
//import com.android.billingclient.api.SkuDetailsResponseListener;
//
//import java.util.ArrayList;
//import java.util.Arrays;
//import java.util.HashMap;
//import java.util.List;
//import java.util.Map;
//import java.util.Objects;
//
//class BillingManager
//{
//    private final String TAG = getClass().getSimpleName();
//
//    private final BillingClient mBillingClient;
//    private final PlayFabMain.BillingUpdatesListener mBillingUpdatesListener;
//
//    // Real money In-app products defined in Google Play Console (product IDs)
//    private final ArrayList<String> mSkuList = new ArrayList<>(Arrays.asList("1000tc", "100tc"));
//
//    private final Map<String, SkuDetails> mSkuDetailsMap = new HashMap<>();
//
//    public Map<String, SkuDetails> getSkuDetailsMap()
//    {
//        return mSkuDetailsMap;
//    }
//
//    public BillingManager(Activity activity, final PlayFabMain.BillingUpdatesListener billingUpdatesListener)
//    {
//        mBillingUpdatesListener = billingUpdatesListener;
//
//        mBillingClient = BillingClient.newBuilder(activity).setListener(new PurchasesUpdatedListener()
//        {
//            @Override
//            public void onPurchasesUpdated(int responseCode, @Nullable List<Purchase> purchases)
//            {
//                if (responseCode == BillingClient.BillingResponse.OK)
//                {
//                    Log.i(TAG, "onPurchasesUpdated - OK");
//                    for (Purchase purchase : Objects.requireNonNull(purchases))
//                    {
//                        ProcessPurchase(purchase);
//                    }
//
//                    mBillingUpdatesListener.onPurchasesUpdated(purchases);
//                }
//                else if (responseCode == BillingClient.BillingResponse.USER_CANCELED)
//                {
//                    Log.i(TAG, "onPurchasesUpdated - user cancelled the purchase flow - skipping");
//                }
//                else if (responseCode == BillingClient.BillingResponse.ITEM_ALREADY_OWNED)
//                {
//                    Log.i(TAG, "onPurchasesUpdated - item already owned");
//                }
//                else
//                {
//                    Log.w(TAG, "onPurchasesUpdated got unknown resultCode: " + responseCode);
//                }
//            }
//        }).build();
//
//        mBillingClient.startConnection(new BillingClientStateListener()
//        {
//            @Override
//            public void onBillingSetupFinished(@BillingClient.BillingResponse int billingResponseCode)
//            {
//                if (billingResponseCode == BillingClient.BillingResponse.OK)
//                {
//                    // The billing client is ready. You can query purchases here.
//                    RetrieveBillingCatalog();
//                }
//
//                mBillingUpdatesListener.onBillingClientSetupFinished();
//            }
//            @Override
//            public void onBillingServiceDisconnected()
//            {
//                // Try to restart the connection on the next request to
//                // Google Play by calling the startConnection() method.
//            }
//        });
//    }
//
//    private void ProcessPurchase(Purchase purchase)
//    {
//        Log.d(TAG, "Process " + purchase);
//
//        final PlayFabOpManager pfman = PlayFabOpManager.getInstance();
//
//        SkuDetails detail = mSkuDetailsMap.get(purchase.getSku());
//        boolean isSuccess;
//
//        if (detail != null)
//        {
//            // Validate purchase with PlayFab, see more info in function definition
//            isSuccess = pfman.ValidateGooglePlayPurchase(
//                    purchase.getSku(),
//                    purchase.getOriginalJson(),
//                    purchase.getSignature(),
//                    detail.getPriceCurrencyCode(),
//                    detail.getPriceAmountMicros() / 10000);
//
//            if (isSuccess)
//            {
//                // If successful, since the real money items are consumables, consume
//                ConsumePurchaseToken(purchase.getSku(), purchase.getPurchaseToken());
//            }
//        }
//        else
//        {
//            Log.d(TAG, purchase.getSku() + " not found in mSkuDetailsMap?!");
//        }
//    }
//
//    private void ConsumePurchaseToken(final String sku, String purchaseToken)
//    {
//        // There is no distinction between durable and consumable in Google Play
//        // A consumable is simply a purchase that has been consumed, so it can be purchased again
//        // An unconsumed owned product will return ITEM_ALREADY_OWNED by launchBillingFlow
//        ConsumeResponseListener listener = new ConsumeResponseListener()
//        {
//            @Override
//            public void onConsumeResponse(@BillingClient.BillingResponse int responseCode, String outToken)
//            {
//                if (responseCode == BillingClient.BillingResponse.OK)
//                {
//                    Log.d(TAG, sku + " consumed");
//                }
//
//                mBillingUpdatesListener.onConsumeFinished(outToken, responseCode);
//            }
//        };
//
//        mBillingClient.consumeAsync(purchaseToken, listener);
//    }
//
//    private void RetrieveBillingCatalog()
//    {
//        // Retrieves list of In-app products set up in Google Play Console
//        SkuDetailsParams.Builder params = SkuDetailsParams.newBuilder();
//        params.setSkusList(mSkuList).setType(BillingClient.SkuType.INAPP);
//        mBillingClient.querySkuDetailsAsync(params.build(),
//                new SkuDetailsResponseListener()
//                {
//                    @Override
//                    public void onSkuDetailsResponse(int responseCode, List<SkuDetails> skuDetailsList)
//                    {
//                        for(SkuDetails detail : skuDetailsList)
//                        {
//                            Log.d(TAG,"Sku: " + detail.getTitle() + " \"" + detail.getDescription() + "\" " + detail.getPrice() + " " + detail.getPriceCurrencyCode());
//                            mSkuDetailsMap.put(detail.getSku(), detail);
//                        }
//                    }
//                });
//    }
//
//    public void PurchaseSku(Activity activity, SkuDetails detail)
//    {
//        // This brings up the purchase UI, and the activity is paused,
//        // so onResume is called when this flow ends
//        BillingFlowParams flowParams = BillingFlowParams.newBuilder()
//                .setSkuDetails(detail)
//                .build();
//
//        int responseCode = mBillingClient.launchBillingFlow(activity, flowParams);
//    }
//
//    void CheckOutstandingPurchases()
//    {
//        // This is called judiciously to ensure that unconsumed purchases are handled
//        // (i.e. sent to PlayFab for validation)
//        // Consumed purchases are not returned by queryPurchases
//        Purchase.PurchasesResult purchasesResult = mBillingClient.queryPurchases(BillingClient.SkuType.INAPP);
//
//        if(purchasesResult.getResponseCode() == BillingClient.BillingResponse.OK)
//        {
//            Log.d(TAG, "CheckOutstandingPurchases: " + purchasesResult.getPurchasesList().size() + " found");
//
//            for (Purchase purchase : purchasesResult.getPurchasesList())
//            {
//                ProcessPurchase(purchase);
//            }
//
//            mBillingUpdatesListener.onPurchasesUpdated(purchasesResult.getPurchasesList());
//        }
//    }
//}
