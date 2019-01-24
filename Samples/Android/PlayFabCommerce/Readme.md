PlayFabCommerce sample for Android
=

This sample uses Android's in-app billing API and PlayFab client API to demonstrate an in-app store that exchanges real money for virtual items in PlayFab Economy.

## Installing the sample

The app can be deployed from Android Studio to a compatible AVD, supporting SDK level 21 or above and using Google Play services (not just Google API). This is because signin with a valid Google account is required. It can also be deployed to any physical Android Device meeting the SDK requirements (5.0/Lollipop).

Due to signing requirements, the deployed app may not successfully launch the real money billing flow, resulting in responseCode 4 for onPurchasesUpdated(). If this occurs, try installing the Play Store version prior to deploying the development version.

The app can also be installed from the Play Store after joining the [PlayFabCommerce test group][1]. After joining (approval required, please contact [ATG Marketplace team][2]), go to the [opt-in link][3] and follow the steps to install the app on your device.

[1]: https://groups.google.com/forum/#!forum/playfabcommerce-test-group
[2]: mailto:xboxatgservices@gmail.com?subject=Request%20access%20to%20PlayFabCommerce%20Google%20group
[3]: https://play.google.com/apps/testing/atg.xbox.PlayFabCommerce

## Usage
The app uses a virtual currency, **TC**. Each new player starts with a seed amount and you can immediately exchange these for virtual items. These are items in the list with a TC price. Inventory of purchased virtual items will show at the bottom. Selecting the buttons in the inventory will simply decrement the quantity of each.

You can replenish TC by exchanging real money, denoted by the items that have a real currency price. By default, this will use or ask for a valid payment instrument and, if available, it will actually **take your money**. You can to contact ATG Marketplace team to have your account added to the test licensing list or to request tokens.

ATG is not responsible for any charges you make. Refunds will need to go through the Google refund request process (Search "Request a refund for a Google Play purchase").

## Code overview
* `PlayFabMain`: App lifecycle and UI-related code, as well as handling of the Google signin button.
* `PlayFabOpManager`: All PlayFab operations. Most operations use the synchronous versions as for small catalogs/inventories, blocking is not an issue. Look at PurchasePFItem for an example of using the async variant to avoid blocking, but will require using a callback interface to report results.
* `BillingManager`: All In-App Billing operations. Note this uses the Play Billing Library and not AIDL interface.

The code has gone through Android Studio code analysis and most reasonable warnings and suggestions should already be addressed. That said, any suggestions on Java/Android best practices are welcome.

## For more information

More information covering how to configure for signin and addons on both Google and PlayFab sides can be found in the accompanying Tutorial doc.
