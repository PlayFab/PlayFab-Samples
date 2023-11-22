package atg.xbox.PlayFabCommerce;

import android.content.DialogInterface;
import android.content.Intent;
import android.graphics.Color;
import android.graphics.drawable.ColorDrawable;
import android.os.Build;
import android.os.Bundle;
import android.os.StrictMode;
import androidx.core.widget.TextViewCompat;
import androidx.appcompat.app.AlertDialog;
import androidx.appcompat.app.AppCompatActivity;
import android.text.Spannable;
import android.text.SpannableString;
import android.text.style.StrikethroughSpan;
import android.text.style.TextAppearanceSpan;
import android.util.Log;
import android.view.Gravity;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.LinearLayout;
import android.widget.ProgressBar;
import android.widget.TextView;

import com.android.billingclient.api.BillingClient;
import com.android.billingclient.api.Purchase;
import com.android.billingclient.api.SkuDetails;

import com.google.android.gms.common.SignInButton;
import com.google.android.gms.games.AuthenticationResult;
import com.google.android.gms.games.GamesSignInClient;
import com.google.android.gms.games.PlayGames;
import com.google.android.gms.games.PlayGamesSdk;

import com.playfab.PlayFabClientModels;

import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Objects;


public class PlayFabMain extends AppCompatActivity
{
    private static final String cVC = "TC";

    private final String TAG = getClass().getSimpleName();

    private BillingManager mBillingManager;

    /**
     * Listener to the updates that happen when purchases list was updated or consumption of the
     * item was finished
     */
    public interface BillingUpdatesListener
    {
        void onBillingClientSetupFinished();
        void onConsumeFinished(String token, @BillingClient.BillingResponse int result);
        void onPurchasesUpdated(List<Purchase> purchases);
    }

    public interface PlayFabPurchaseListener
    {
        void onPurchaseComplete(String errors);
    }

    private final int RC_SIGN_IN = 9001;

    private final Map<String, Integer> mCatalogButtonMap = new HashMap<>();

    // Fixed mapping for the inventory label/button and item
    private final Map<String, Integer> mInventoryLabelMap = new HashMap<String, Integer>()
    {
        {
            put("Sword", R.id.label1);
            put("Shield", R.id.label2);
            put("Bow", R.id.label3);
            put("Gem", R.id.label4);
            put("Arrow", R.id.label5);
            put("Potion", R.id.label6);
        }
    };

    private final Map<String, Integer> mInventoryButtonMap = new HashMap<String, Integer>()
    {
        {
            put("Sword", R.id.button1);
            put("Shield", R.id.button2);
            put("Bow", R.id.button3);
            put("Gem", R.id.button4);
            put("Arrow", R.id.button5);
            put("Potion", R.id.button6);
        }
    };

    @Override
    protected void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
        PlayGamesSdk.initialize(this);

        setContentView(R.layout.activity_play_fab_main);

        Objects.requireNonNull(getSupportActionBar()).setBackgroundDrawable(new ColorDrawable(Color.parseColor("#ff6d20")));

        // Need this to avoid android.osNetworkOnMainThreadException by StrictMode$AndroidBlockGuardPolicy.onNetwork
        StrictMode.ThreadPolicy policy = new StrictMode.ThreadPolicy.Builder().permitAll().build();
        StrictMode.setThreadPolicy(policy);

        // Set the dimensions of the sign-in button.
        SignInButton signInButton = findViewById(R.id.sign_in_button);
        signInButton.setSize(SignInButton.SIZE_STANDARD);

        GamesSignInClient gamesSignInClient = PlayGames.getGamesSignInClient(this);

        com.google.android.gms.tasks.OnCompleteListener<AuthenticationResult> onAuthenticationComplete = isAuthenticatedTask -> {
            boolean taskCompletedSuccessfully = isAuthenticatedTask.isSuccessful();
            boolean isAuthenticated =
                    (taskCompletedSuccessfully &&
                            isAuthenticatedTask.getResult().isAuthenticated());

            if (isAuthenticated) {
                ViewGroup layout = (ViewGroup) signInButton.getParent();
                if (layout != null)
                {
                    layout.removeView(signInButton);
                }

                // Continue with Play Games Services
                Log.d(TAG, "The user IS authenticated");
                gamesSignInClient.requestServerSideAccess(getString(R.string.server_client_id), false).addOnCompleteListener( task -> {
                    if (task.isSuccessful()) {
                        String serverAuthCode = task.getResult();
                        Log.d(TAG, "Server auth code is: " + serverAuthCode);
                    }
                });
            } else {
                // Disable your integration with Play Games Services or show a
                // login button to ask  players to sign-in. Clicking it should
                // call GamesSignInClient.signIn().
                Log.d(TAG, "The user is NOT authenticated");
            }
        };

        // The Google Play Games SDK automatically signs in the current player.  All we need to do
        // is check to see if the player is currently authenticated or not.  If so, then we're all
        // set to use the Google Play Games APIs.  If not then we can keep the Sign In button
        // on the screen and allow the player to manually sign in later.
        gamesSignInClient.isAuthenticated().addOnCompleteListener(onAuthenticationComplete);

        signInButton.setOnClickListener(new View.OnClickListener()
        {
            @Override
            public void onClick(View view)
            {
                Log.d(TAG, "Click Google Sign In");
                gamesSignInClient.signIn().addOnCompleteListener(onAuthenticationComplete);
//                SetInProgress(true);
//                Intent signInIntent = mGoogleSignInClient.getSignInIntent();
//                startActivityForResult(signInIntent, RC_SIGN_IN);
            }
        });

        mBillingManager = new BillingManager(this, new BillingUpdatesListener()
        {
            @Override
            public void onBillingClientSetupFinished()
            {

            }

            @Override
            public void onConsumeFinished(String token, int result)
            {

            }

            @Override
            public void onPurchasesUpdated(List<Purchase> purchases)
            {
                UpdateUI();
            }
        });
    }

    @Override
    protected void onResume()
    {
        super.onResume();

        mBillingManager.CheckOutstandingPurchases();
    }

    private void SetInProgress(final boolean b)
    {
        runOnUiThread(new Runnable()
        {
            @Override
            public void run()
            {
                ProgressBar spinny = findViewById(R.id.spinny);
                spinny.setVisibility(b ? View.VISIBLE : View.INVISIBLE);
            }
        });
    }

    private void InitializeUI()
    {
        // This populates the main product list
        // Each row consists of an icon, the description of the product, and a button that shows the price

        LinearLayout linearLayout = findViewById(R.id.playfab_items);
        linearLayout.removeAllViewsInLayout();

        for(Map.Entry<String, SkuDetails> entry : mBillingManager.getSkuDetailsMap().entrySet())
        {
            // List the real money In-app products first
            final SkuDetails detail = entry.getValue();

            Button button = new Button(this);

            button.setText(detail.getPrice());

            button.setOnClickListener(new View.OnClickListener()
            {
                @Override
                public void onClick(View view)
                {
                    mBillingManager.PurchaseSku(PlayFabMain.this, detail);
                }
            });

            AddItemRow(entry.getKey(), StripTitleFromAddOnTitle(detail.getTitle()), button);
        }

        final PlayFabOpManager pfman = PlayFabOpManager.getInstance();

        for(Map.Entry<String, PlayFabClientModels.CatalogItem> entry : pfman.getCatalogItems().entrySet())
        {
            // Now show the PlayFab virtual currency items
            // Other PlayFab items and bundles are returned in the Catalog,
            // so ensure the item has a virtual currency price
            // (the others will not be purchasable by the app)
            final String itemId = entry.getValue().ItemId;

            final PlayFabClientModels.CatalogItem item = entry.getValue();

            if(item.VirtualCurrencyPrices != null && item.VirtualCurrencyPrices.containsKey(cVC))
            {
                Button button = new Button(this);

                // Note the button text, i.e. price is actually not set here, but in UpdateUI

                button.setOnClickListener(new View.OnClickListener()
                {
                    @Override
                    public void onClick(View view)
                    {
                        final Long basePrice = item.VirtualCurrencyPrices.get(cVC);
                        StartPurchasePFItem(pfman, itemId, basePrice);
                    }
                });

                AddItemRow(itemId, entry.getKey(), button);
            }
        }

        for(final Map.Entry<String, Integer> entry : mInventoryLabelMap.entrySet())
        {
            ((TextView)findViewById(entry.getValue())).setText(entry.getKey());
        }

        for(final Map.Entry<String, Integer> entry : mInventoryButtonMap.entrySet())
        {
            Button b = findViewById(entry.getValue());
            b.setText("");
            b.setOnClickListener(new View.OnClickListener()
            {
                @Override
                public void onClick(View v)
                {
                    SetInProgress(true);
                    pfman.ConsumePFItem(entry.getKey());
                    UpdateUI();
                }
            });
        }
    }

    private String StripTitleFromAddOnTitle(String title)
    {
        // Why does the addon title always get appended with (app title)?
        int pos = title.lastIndexOf("(");

        return title.substring(0, pos - 1);
    }

    private void AddItemRow(String itemId, String itemName, Button button)
    {
        int cRowHeight = 150;

        LinearLayout linearLayout = findViewById(R.id.playfab_items);

        LinearLayout row = new LinearLayout(this);
        row.setOrientation(LinearLayout.HORIZONTAL);

        LinearLayout.LayoutParams params = new LinearLayout.LayoutParams(LinearLayout.LayoutParams.MATCH_PARENT, cRowHeight);
        row.setLayoutParams(params);

        ImageView imageView = new ImageView(this);
        int resId = getResources().getIdentifier("icon_" + getIconFromItemId(itemId), "drawable", getPackageName());
        imageView.setImageResource(resId);

        params = new LinearLayout.LayoutParams(LinearLayout.LayoutParams.MATCH_PARENT, LinearLayout.LayoutParams.MATCH_PARENT, 0.5f);
        imageView.setLayoutParams(params);
        row.addView(imageView);

        TextView textView = new TextView(this);
        TextViewCompat.setTextAppearance(textView, R.style.TextAppearance_AppCompat_Large);
        textView.setText(itemName);
        textView.setTextAlignment(View.TEXT_ALIGNMENT_GRAVITY);
        textView.setGravity(Gravity.CENTER);
        textView.setTextColor(Color.WHITE);

        params = new LinearLayout.LayoutParams(LinearLayout.LayoutParams.MATCH_PARENT, LinearLayout.LayoutParams.MATCH_PARENT, 0.2f);
        textView.setLayoutParams(params);
        row.addView(textView);

        int id = View.generateViewId();
        button.setId(id);
        mCatalogButtonMap.put(itemId, id);

        // This is needed for SpannableText to work properly on a button
        button.setAllCaps(false);

        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.M)
        {
            button.setTextAppearance( R.style.TextAppearance_AppCompat_Large);
        }

        params = new LinearLayout.LayoutParams(LinearLayout.LayoutParams.MATCH_PARENT, LinearLayout.LayoutParams.MATCH_PARENT, 0.4f);
        button.setLayoutParams(params);
        row.addView(button);

        linearLayout.addView(row);
    }

    private void StartPurchasePFItem(final PlayFabOpManager pfman, final String itemId, Long basePrice)
    {
        AlertDialog.Builder confirmPopup = new AlertDialog.Builder(this);
        confirmPopup.setTitle("Purchase confirmation");

        final Long currentPrice = (pfman.getStorePrices().containsKey(itemId))? pfman.getStorePrices().get(itemId) : basePrice;
        confirmPopup.setMessage(String.format("Buy %s for %d %s?", itemId, currentPrice, cVC));
        confirmPopup.setPositiveButton("Yes", new DialogInterface.OnClickListener()
        {
            @Override
            public void onClick(DialogInterface dialog, int which)
            {
                dialog.cancel();
                SetInProgress(true);
                pfman.PurchasePFItem(itemId, currentPrice, PlayFabMain.this, new PlayFabPurchaseListener()
                {
                    @Override
                    public void onPurchaseComplete(String errors)
                    {
                        if(errors == null)
                        {
                            UpdateUI();
                        }
                        else
                        {
                            AlertDialog.Builder popup = new AlertDialog.Builder(PlayFabMain.this);
                            popup.setTitle("Purchase error");
                            popup.setMessage(errors);
                            popup.setPositiveButton("Doh", new DialogInterface.OnClickListener()
                            {
                                @Override
                                public void onClick(DialogInterface dialog, int which)
                                {
                                    dialog.cancel();
                                    SetInProgress(false);
                                }
                            });
                            popup.show();
                        }
                    }
                });
            }
        });

        confirmPopup.setNegativeButton("No", new DialogInterface.OnClickListener()
        {
            @Override
            public void onClick(DialogInterface dialog, int which)
            {
                dialog.cancel();
            }
        });

        confirmPopup.show();
    }

    private SpannableString FormatPriceString(Long basePrice, Long currentPrice)
    {
        // if there is an alternate price (from GetStoreItems), show that and the original price right after with strikethrough
        String pricestr = currentPrice.toString();
        if(!currentPrice.equals(basePrice))
        {
            pricestr += basePrice;
        }
        pricestr += cVC;

        SpannableString formattedstr = new SpannableString(pricestr);

        int sepidx = currentPrice.equals(basePrice)? currentPrice.toString().length() : currentPrice.toString().length() + basePrice.toString().length();
        int symbolidx = formattedstr.toString().indexOf(cVC);

        formattedstr.setSpan(new StrikethroughSpan(), currentPrice.toString().length(), sepidx, Spannable.SPAN_INCLUSIVE_EXCLUSIVE);
        formattedstr.setSpan(new TextAppearanceSpan(this, R.style.TextAppearance_AppCompat_Large), 0, symbolidx, Spannable.SPAN_INCLUSIVE_EXCLUSIVE);
        formattedstr.setSpan(new TextAppearanceSpan(this, R.style.TextAppearance_AppCompat_Medium), symbolidx, formattedstr.length(), Spannable.SPAN_INCLUSIVE_EXCLUSIVE);

        return formattedstr;
    }

    private String getIconFromItemId(String itemId)
    {
        itemId = itemId.toLowerCase();
        if(itemId.contains("arrow"))
        {
            return "arrow";
        }
        else if(itemId.contains("potion"))
        {
            return "potion";
        }
        else if(itemId.contains("mystery"))
        {
            return "crate";
        }
        else if(itemId.contains("100tc"))
        {
            return "coins_small";
        }
        else if(itemId.contains("1000tc"))
        {
            return "coins_large";
        }
        else
        {
            return itemId;
        }
    }

    private void UpdateUI()
    {
        // Ensure this is run on UI thread as this may be called by onPurchaseUpdates which is running on a separate thread
        // findViewById will not find elements otherwise
        runOnUiThread(new Runnable()
        {
            @Override
            public void run()
            {
                PlayFabOpManager pfman = PlayFabOpManager.getInstance();

                Integer balance = pfman.getVirtualCurrencies().get(cVC);

                SpannableString currencystr = new SpannableString(String.format("%d%s", balance, cVC));

                int symbolidx = currencystr.toString().indexOf(cVC);

                currencystr.setSpan(new TextAppearanceSpan(PlayFabMain.this,
                        R.style.TextAppearance_AppCompat_Large_Inverse), 0, symbolidx, Spannable.SPAN_INCLUSIVE_EXCLUSIVE);
                currencystr.setSpan(new TextAppearanceSpan(PlayFabMain.this,
                        R.style.TextAppearance_AppCompat_Medium_Inverse), symbolidx, currencystr.length(), Spannable.SPAN_INCLUSIVE_EXCLUSIVE);

                ((TextView) findViewById(R.id.text_currency_balance)).setText(currencystr, TextView.BufferType.SPANNABLE);

                for (Map.Entry<String, Integer> entry : mInventoryButtonMap.entrySet())
                {
                    String itemId = entry.getKey();
                    Integer count = pfman.getVirtualConsumables().containsKey(itemId) ? pfman.getVirtualConsumables().get(itemId) : 0;

                    ((Button) findViewById(entry.getValue())).setText(String.format("%d", count));
                }

                for (Map.Entry<String, Integer> entry : mCatalogButtonMap.entrySet())
                {
                    String itemId = entry.getKey();
                    PlayFabClientModels.CatalogItem item = pfman.getCatalogItems().get(itemId);
                    if (item != null)
                    {
                        // by definition, items assigned buttons will have proper virtual currency
                        Long basePrice = item.VirtualCurrencyPrices.get(cVC);
                        Long currentPrice = (pfman.getStorePrices().containsKey(itemId)) ? pfman.getStorePrices().get(itemId) : basePrice;

                        if (currentPrice != null)
                        {
                            SpannableString pricestr = FormatPriceString(basePrice, currentPrice);
                            ((Button) findViewById(entry.getValue())).setText(pricestr, TextView.BufferType.SPANNABLE);
                        }
                    }
                }

                SetInProgress(false);
            }
        });
    }

    @Override
    protected void onStart()
    {
        super.onStart();

        // Check for existing Google Sign In account, if the user is already signed in
        // the GoogleSignInAccount will be non-null.
//        GoogleSignInAccount account = GoogleSignIn.getLastSignedInAccount(this);

    }

    @Override
    public void onActivityResult(int requestCode, int resultCode, Intent data)
    {
        super.onActivityResult(requestCode, resultCode, data);
    }

    // As of the time of this writing (05/20/2022) PlayFab does not support logging in via the
    // Google Play Games SDK.  This is because the OAuth scopes requested by the Google Play Games
    // SDK (GPG SDK) do not allow the PlayFab service to access the player's Google Account Id,
    // they only allow the service to access the player's Google Play Games Player Id.  Therefore,
    // this method is no longer called in this sample, but it remains here so that we can easily
    // update it in the future if and when PlayFab adds support for logging in with a
    // Google Play Games Player Id.
    private void SignInPlayFab(final String authCode)
    {
        PlayFabOpManager pfman = PlayFabOpManager.getInstance();

        String errors = pfman.LoginWithGoogleAccount(authCode);

        if(errors == null)
        {
            pfman.RetrievePFCatalog();
            pfman.UpdatePFStorePrices();

            InitializeUI();

            pfman.UpdatePFInventory();

            UpdateUI();
        }
        else
        {
            AlertDialog.Builder popup = new AlertDialog.Builder(this);
            popup.setTitle("LoginWithGoogleAccount error");
            popup.setMessage(errors);
            popup.setPositiveButton("Doh", new DialogInterface.OnClickListener()
            {
                @Override
                public void onClick(DialogInterface dialog, int which)
                {
                    dialog.cancel();
                    SetInProgress(false);
                }
            });
            popup.show();
        }
    }
}