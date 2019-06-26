#if !DISABLE_PLAYFABENTITY_API

using System;
using System.Collections.Generic;
using PlayFab.EconomyModels;
using PlayFab.Internal;

namespace PlayFab
{
    /// <summary>
    /// API methods for managing User Generated Content. API methods for managing the catalog. Inventory manages in-game assets
    /// for any given entity.
    /// </summary>
    public static class PlayFabEconomyAPI
    {
        static PlayFabEconomyAPI() {}


        /// <summary>
        /// Verify entity login.
        /// </summary>
        public static bool IsEntityLoggedIn()
        {
            return PlayFabSettings.staticPlayer.IsEntityLoggedIn();
        }

        /// <summary>
        /// Clear the Client SessionToken which allows this Client to call API calls requiring login.
        /// A new/fresh login will be required after calling this.
        /// </summary>
        public static void ForgetAllCredentials()
        {
            PlayFabSettings.staticPlayer.ForgetAllCredentials();
        }

        /// <summary>
        /// Increase virtual currencies amount.
        /// </summary>
        public static void AddVirtualCurrencies(AddVirtualCurrenciesRequest request, Action<AddVirtualCurrenciesResult> resultCallback, Action<PlayFabError> errorCallback, object customData = null, Dictionary<string, string> extraHeaders = null)
        {
            var context = (request == null ? null : request.AuthenticationContext) ?? PlayFabSettings.staticPlayer;


            PlayFabHttp.MakeApiCall("/Inventory/AddVirtualCurrencies", request, AuthType.EntityToken, resultCallback, errorCallback, customData, extraHeaders, context);
        }

        /// <summary>
        /// Consume inventory items.
        /// </summary>
        public static void ConsumeInventoryItems(ConsumeInventoryItemsRequest request, Action<ConsumeInventoryItemsResult> resultCallback, Action<PlayFabError> errorCallback, object customData = null, Dictionary<string, string> extraHeaders = null)
        {
            var context = (request == null ? null : request.AuthenticationContext) ?? PlayFabSettings.staticPlayer;


            PlayFabHttp.MakeApiCall("/Inventory/ConsumeInventoryItems", request, AuthType.EntityToken, resultCallback, errorCallback, customData, extraHeaders, context);
        }

        /// <summary>
        /// Create a bundle
        /// </summary>
        public static void CreateBundle(CreateBundleRequest request, Action<CreateBundleResult> resultCallback, Action<PlayFabError> errorCallback, object customData = null, Dictionary<string, string> extraHeaders = null)
        {
            var context = (request == null ? null : request.AuthenticationContext) ?? PlayFabSettings.staticPlayer;


            PlayFabHttp.MakeApiCall("/Catalog/CreateBundle", request, AuthType.EntityToken, resultCallback, errorCallback, customData, extraHeaders, context);
        }

        /// <summary>
        /// Create a currency
        /// </summary>
        public static void CreateCurrency(CreateCurrencyRequest request, Action<CreateCurrencyResult> resultCallback, Action<PlayFabError> errorCallback, object customData = null, Dictionary<string, string> extraHeaders = null)
        {
            var context = (request == null ? null : request.AuthenticationContext) ?? PlayFabSettings.staticPlayer;


            PlayFabHttp.MakeApiCall("/Catalog/CreateCurrency", request, AuthType.EntityToken, resultCallback, errorCallback, customData, extraHeaders, context);
        }

        /// <summary>
        /// Creates a new item in the working catalog using provided metadata.
        /// </summary>
        public static void CreateDraftItem(CreateDraftItemRequest request, Action<CreateDraftItemResult> resultCallback, Action<PlayFabError> errorCallback, object customData = null, Dictionary<string, string> extraHeaders = null)
        {
            var context = (request == null ? null : request.AuthenticationContext) ?? PlayFabSettings.staticPlayer;


            PlayFabHttp.MakeApiCall("/Catalog/CreateDraftItem", request, AuthType.EntityToken, resultCallback, errorCallback, customData, extraHeaders, context);
        }

        /// <summary>
        /// Creates a new community catalog item in the working catalog using provided metadata.
        /// </summary>
        public static void CreateDraftUgcItem(CreateDraftItemRequest request, Action<CreateDraftItemResult> resultCallback, Action<PlayFabError> errorCallback, object customData = null, Dictionary<string, string> extraHeaders = null)
        {
            var context = (request == null ? null : request.AuthenticationContext) ?? PlayFabSettings.staticPlayer;


            PlayFabHttp.MakeApiCall("/UserGeneratedContent/CreateDraftUgcItem", request, AuthType.EntityToken, resultCallback, errorCallback, customData, extraHeaders, context);
        }

        /// <summary>
        /// Creates or updates a review for the specified item.
        /// </summary>
        public static void CreateOrUpdateReview(CreateOrUpdateReviewRequest request, Action<CreateOrUpdateReviewResult> resultCallback, Action<PlayFabError> errorCallback, object customData = null, Dictionary<string, string> extraHeaders = null)
        {
            var context = (request == null ? null : request.AuthenticationContext) ?? PlayFabSettings.staticPlayer;


            PlayFabHttp.MakeApiCall("/Catalog/CreateOrUpdateReview", request, AuthType.EntityToken, resultCallback, errorCallback, customData, extraHeaders, context);
        }

        /// <summary>
        /// Create a store
        /// </summary>
        public static void CreateStore(CreateStoreRequest request, Action<CreateStoreResult> resultCallback, Action<PlayFabError> errorCallback, object customData = null, Dictionary<string, string> extraHeaders = null)
        {
            var context = (request == null ? null : request.AuthenticationContext) ?? PlayFabSettings.staticPlayer;


            PlayFabHttp.MakeApiCall("/Catalog/CreateStore", request, AuthType.EntityToken, resultCallback, errorCallback, customData, extraHeaders, context);
        }

        /// <summary>
        /// Create a subscription
        /// </summary>
        public static void CreateSubscription(CreateSubscriptionRequest request, Action<CreateSubscriptionResult> resultCallback, Action<PlayFabError> errorCallback, object customData = null, Dictionary<string, string> extraHeaders = null)
        {
            var context = (request == null ? null : request.AuthenticationContext) ?? PlayFabSettings.staticPlayer;


            PlayFabHttp.MakeApiCall("/Catalog/CreateSubscription", request, AuthType.EntityToken, resultCallback, errorCallback, customData, extraHeaders, context);
        }

        /// <summary>
        /// Creates one or more upload URLs which can be used by the client to upload raw mod file data.
        /// </summary>
        public static void CreateUgcUploadUrls(CreateUploadUrlsRequest request, Action<CreateUploadUrlsResult> resultCallback, Action<PlayFabError> errorCallback, object customData = null, Dictionary<string, string> extraHeaders = null)
        {
            var context = (request == null ? null : request.AuthenticationContext) ?? PlayFabSettings.staticPlayer;


            PlayFabHttp.MakeApiCall("/UserGeneratedContent/CreateUgcUploadUrls", request, AuthType.EntityToken, resultCallback, errorCallback, customData, extraHeaders, context);
        }

        /// <summary>
        /// Creates one or more upload URLs which can be used by the client to upload raw file data.
        /// </summary>
        public static void CreateUploadUrls(CreateUploadUrlsRequest request, Action<CreateUploadUrlsResult> resultCallback, Action<PlayFabError> errorCallback, object customData = null, Dictionary<string, string> extraHeaders = null)
        {
            var context = (request == null ? null : request.AuthenticationContext) ?? PlayFabSettings.staticPlayer;


            PlayFabHttp.MakeApiCall("/Catalog/CreateUploadUrls", request, AuthType.EntityToken, resultCallback, errorCallback, customData, extraHeaders, context);
        }

        /// <summary>
        /// Delete a bundle by friendly Id
        /// </summary>
        public static void DeleteBundleByFriendlyId(DeleteBundleByFriendlyIdRequest request, Action<DeleteBundleResult> resultCallback, Action<PlayFabError> errorCallback, object customData = null, Dictionary<string, string> extraHeaders = null)
        {
            var context = (request == null ? null : request.AuthenticationContext) ?? PlayFabSettings.staticPlayer;


            PlayFabHttp.MakeApiCall("/Catalog/DeleteBundleByFriendlyId", request, AuthType.EntityToken, resultCallback, errorCallback, customData, extraHeaders, context);
        }

        /// <summary>
        /// Delete a bundle by Id
        /// </summary>
        public static void DeleteBundleById(DeleteBundleByIdRequest request, Action<DeleteBundleResult> resultCallback, Action<PlayFabError> errorCallback, object customData = null, Dictionary<string, string> extraHeaders = null)
        {
            var context = (request == null ? null : request.AuthenticationContext) ?? PlayFabSettings.staticPlayer;


            PlayFabHttp.MakeApiCall("/Catalog/DeleteBundleById", request, AuthType.EntityToken, resultCallback, errorCallback, customData, extraHeaders, context);
        }

        /// <summary>
        /// Removes an item from working catalog and all published versions from the public catalog.
        /// </summary>
        public static void DeleteItem(DeleteItemRequest request, Action<DeleteItemResult> resultCallback, Action<PlayFabError> errorCallback, object customData = null, Dictionary<string, string> extraHeaders = null)
        {
            var context = (request == null ? null : request.AuthenticationContext) ?? PlayFabSettings.staticPlayer;


            PlayFabHttp.MakeApiCall("/Catalog/DeleteItem", request, AuthType.EntityToken, resultCallback, errorCallback, customData, extraHeaders, context);
        }

        /// <summary>
        /// Delete a store by friendly Id
        /// </summary>
        public static void DeleteStoreByFriendlyId(DeleteStoreByFriendlyIdRequest request, Action<DeleteStoreResult> resultCallback, Action<PlayFabError> errorCallback, object customData = null, Dictionary<string, string> extraHeaders = null)
        {
            var context = (request == null ? null : request.AuthenticationContext) ?? PlayFabSettings.staticPlayer;


            PlayFabHttp.MakeApiCall("/Catalog/DeleteStoreByFriendlyId", request, AuthType.EntityToken, resultCallback, errorCallback, customData, extraHeaders, context);
        }

        /// <summary>
        /// Delete a store by Id
        /// </summary>
        public static void DeleteStoreById(DeleteStoreByIdRequest request, Action<DeleteStoreResult> resultCallback, Action<PlayFabError> errorCallback, object customData = null, Dictionary<string, string> extraHeaders = null)
        {
            var context = (request == null ? null : request.AuthenticationContext) ?? PlayFabSettings.staticPlayer;


            PlayFabHttp.MakeApiCall("/Catalog/DeleteStoreById", request, AuthType.EntityToken, resultCallback, errorCallback, customData, extraHeaders, context);
        }

        /// <summary>
        /// Delete a subscription by friendly Id
        /// </summary>
        public static void DeleteSubscriptionByFriendlyId(DeleteSubscriptionByFriendlyIdRequest request, Action<DeleteSubscriptionResult> resultCallback, Action<PlayFabError> errorCallback, object customData = null, Dictionary<string, string> extraHeaders = null)
        {
            var context = (request == null ? null : request.AuthenticationContext) ?? PlayFabSettings.staticPlayer;


            PlayFabHttp.MakeApiCall("/Catalog/DeleteSubscriptionByFriendlyId", request, AuthType.EntityToken, resultCallback, errorCallback, customData, extraHeaders, context);
        }

        /// <summary>
        /// Delete a subscription by Id
        /// </summary>
        public static void DeleteSubscriptionById(DeleteSubscriptionByIdRequest request, Action<DeleteSubscriptionResult> resultCallback, Action<PlayFabError> errorCallback, object customData = null, Dictionary<string, string> extraHeaders = null)
        {
            var context = (request == null ? null : request.AuthenticationContext) ?? PlayFabSettings.staticPlayer;


            PlayFabHttp.MakeApiCall("/Catalog/DeleteSubscriptionById", request, AuthType.EntityToken, resultCallback, errorCallback, customData, extraHeaders, context);
        }

        /// <summary>
        /// Removes an item from working catalog and all published versions from the public catalog.
        /// </summary>
        public static void DeleteUgcItem(DeleteItemRequest request, Action<DeleteItemResult> resultCallback, Action<PlayFabError> errorCallback, object customData = null, Dictionary<string, string> extraHeaders = null)
        {
            var context = (request == null ? null : request.AuthenticationContext) ?? PlayFabSettings.staticPlayer;


            PlayFabHttp.MakeApiCall("/UserGeneratedContent/DeleteUgcItem", request, AuthType.EntityToken, resultCallback, errorCallback, customData, extraHeaders, context);
        }

        /// <summary>
        /// Get a bundle by Friendly Id
        /// </summary>
        public static void GetBundleByFriendlyId(GetBundleByFriendlyIdRequest request, Action<GetBundleResult> resultCallback, Action<PlayFabError> errorCallback, object customData = null, Dictionary<string, string> extraHeaders = null)
        {
            var context = (request == null ? null : request.AuthenticationContext) ?? PlayFabSettings.staticPlayer;


            PlayFabHttp.MakeApiCall("/Catalog/GetBundleByFriendlyId", request, AuthType.EntityToken, resultCallback, errorCallback, customData, extraHeaders, context);
        }

        /// <summary>
        /// Get a bundle by Id
        /// </summary>
        public static void GetBundleById(GetBundleByIdRequest request, Action<GetBundleResult> resultCallback, Action<PlayFabError> errorCallback, object customData = null, Dictionary<string, string> extraHeaders = null)
        {
            var context = (request == null ? null : request.AuthenticationContext) ?? PlayFabSettings.staticPlayer;


            PlayFabHttp.MakeApiCall("/Catalog/GetBundleById", request, AuthType.EntityToken, resultCallback, errorCallback, customData, extraHeaders, context);
        }

        /// <summary>
        /// Get a bundle by marketplace offer Id
        /// </summary>
        public static void GetBundleByMarketplaceOfferId(GetBundleByMarketplaceOfferIdRequest request, Action<GetBundleResult> resultCallback, Action<PlayFabError> errorCallback, object customData = null, Dictionary<string, string> extraHeaders = null)
        {
            var context = (request == null ? null : request.AuthenticationContext) ?? PlayFabSettings.staticPlayer;


            PlayFabHttp.MakeApiCall("/Catalog/GetBundleByMarketplaceOfferId", request, AuthType.EntityToken, resultCallback, errorCallback, customData, extraHeaders, context);
        }

        /// <summary>
        /// Gets the configuration for the catalog.
        /// </summary>
        public static void GetCatalogConfig(GetCatalogConfigRequest request, Action<GetCatalogConfigResult> resultCallback, Action<PlayFabError> errorCallback, object customData = null, Dictionary<string, string> extraHeaders = null)
        {
            var context = (request == null ? null : request.AuthenticationContext) ?? PlayFabSettings.staticPlayer;


            PlayFabHttp.MakeApiCall("/Catalog/GetCatalogConfig", request, AuthType.EntityToken, resultCallback, errorCallback, customData, extraHeaders, context);
        }

        /// <summary>
        /// Retrieve a currency by id
        /// </summary>
        public static void GetCurrencyById(GetCurrencyByIdRequest request, Action<GetCurrencyByIdResult> resultCallback, Action<PlayFabError> errorCallback, object customData = null, Dictionary<string, string> extraHeaders = null)
        {
            var context = (request == null ? null : request.AuthenticationContext) ?? PlayFabSettings.staticPlayer;


            PlayFabHttp.MakeApiCall("/Catalog/GetCurrencyById", request, AuthType.EntityToken, resultCallback, errorCallback, customData, extraHeaders, context);
        }

        /// <summary>
        /// Retrieves an item from the working catalog. This item represents the current working state of the catalog item.
        /// </summary>
        public static void GetDraftItem(GetDraftItemRequest request, Action<GetDraftItemResult> resultCallback, Action<PlayFabError> errorCallback, object customData = null, Dictionary<string, string> extraHeaders = null)
        {
            var context = (request == null ? null : request.AuthenticationContext) ?? PlayFabSettings.staticPlayer;


            PlayFabHttp.MakeApiCall("/Catalog/GetDraftItem", request, AuthType.EntityToken, resultCallback, errorCallback, customData, extraHeaders, context);
        }

        /// <summary>
        /// Retrieves a paginated list of the items from the draft catalog.
        /// </summary>
        public static void GetDraftItems(GetDraftItemsRequest request, Action<GetDraftItemsResult> resultCallback, Action<PlayFabError> errorCallback, object customData = null, Dictionary<string, string> extraHeaders = null)
        {
            var context = (request == null ? null : request.AuthenticationContext) ?? PlayFabSettings.staticPlayer;


            PlayFabHttp.MakeApiCall("/Catalog/GetDraftItems", request, AuthType.EntityToken, resultCallback, errorCallback, customData, extraHeaders, context);
        }

        /// <summary>
        /// Retrieves an item from the working catalog. This item represents the current working state of the community item.
        /// </summary>
        public static void GetDraftUgcItem(GetDraftItemRequest request, Action<GetDraftItemResult> resultCallback, Action<PlayFabError> errorCallback, object customData = null, Dictionary<string, string> extraHeaders = null)
        {
            var context = (request == null ? null : request.AuthenticationContext) ?? PlayFabSettings.staticPlayer;


            PlayFabHttp.MakeApiCall("/UserGeneratedContent/GetDraftUgcItem", request, AuthType.EntityToken, resultCallback, errorCallback, customData, extraHeaders, context);
        }

        /// <summary>
        /// Retrieves a paginated list of the items created by a user.
        /// </summary>
        public static void GetDraftUgcItems(GetDraftItemsRequest request, Action<GetDraftItemsResult> resultCallback, Action<PlayFabError> errorCallback, object customData = null, Dictionary<string, string> extraHeaders = null)
        {
            var context = (request == null ? null : request.AuthenticationContext) ?? PlayFabSettings.staticPlayer;


            PlayFabHttp.MakeApiCall("/UserGeneratedContent/GetDraftUgcItems", request, AuthType.EntityToken, resultCallback, errorCallback, customData, extraHeaders, context);
        }

        /// <summary>
        /// Get current inventory items.
        /// </summary>
        public static void GetInventoryItems(GetInventoryItemsRequest request, Action<GetInventoryItemsResult> resultCallback, Action<PlayFabError> errorCallback, object customData = null, Dictionary<string, string> extraHeaders = null)
        {
            var context = (request == null ? null : request.AuthenticationContext) ?? PlayFabSettings.staticPlayer;


            PlayFabHttp.MakeApiCall("/Inventory/GetInventoryItems", request, AuthType.EntityToken, resultCallback, errorCallback, customData, extraHeaders, context);
        }

        /// <summary>
        /// Get a paginated set of reviews associated with the specified item.
        /// </summary>
        public static void GetItemReviews(GetReviewsRequest request, Action<GetReviewsResult> resultCallback, Action<PlayFabError> errorCallback, object customData = null, Dictionary<string, string> extraHeaders = null)
        {
            var context = (request == null ? null : request.AuthenticationContext) ?? PlayFabSettings.staticPlayer;


            PlayFabHttp.MakeApiCall("/Catalog/GetItemReviews", request, AuthType.EntityToken, resultCallback, errorCallback, customData, extraHeaders, context);
        }

        /// <summary>
        /// Get a summary of all reviews associated with the specified item.
        /// </summary>
        public static void GetItemReviewSummary(ReviewSummaryRequest request, Action<ReviewSummaryResult> resultCallback, Action<PlayFabError> errorCallback, object customData = null, Dictionary<string, string> extraHeaders = null)
        {
            var context = (request == null ? null : request.AuthenticationContext) ?? PlayFabSettings.staticPlayer;


            PlayFabHttp.MakeApiCall("/Catalog/GetItemReviewSummary", request, AuthType.EntityToken, resultCallback, errorCallback, customData, extraHeaders, context);
        }

        /// <summary>
        /// Gets the submitted review for the specifed item by the authenticated user.
        /// </summary>
        public static void GetMyReview(GetMyReviewRequest request, Action<GetMyReviewResult> resultCallback, Action<PlayFabError> errorCallback, object customData = null, Dictionary<string, string> extraHeaders = null)
        {
            var context = (request == null ? null : request.AuthenticationContext) ?? PlayFabSettings.staticPlayer;


            PlayFabHttp.MakeApiCall("/Catalog/GetMyReview", request, AuthType.EntityToken, resultCallback, errorCallback, customData, extraHeaders, context);
        }

        /// <summary>
        /// Retrieves an item from the public catalog.
        /// </summary>
        public static void GetPublishedItem(GetPublishedItemRequest request, Action<GetPublishedItemResult> resultCallback, Action<PlayFabError> errorCallback, object customData = null, Dictionary<string, string> extraHeaders = null)
        {
            var context = (request == null ? null : request.AuthenticationContext) ?? PlayFabSettings.staticPlayer;


            PlayFabHttp.MakeApiCall("/Catalog/GetPublishedItem", request, AuthType.EntityToken, resultCallback, errorCallback, customData, extraHeaders, context);
        }

        /// <summary>
        /// Retrieves an item from the public catalog.
        /// </summary>
        public static void GetPublishedUgcItem(GetPublishedItemRequest request, Action<GetPublishedItemResult> resultCallback, Action<PlayFabError> errorCallback, object customData = null, Dictionary<string, string> extraHeaders = null)
        {
            var context = (request == null ? null : request.AuthenticationContext) ?? PlayFabSettings.staticPlayer;


            PlayFabHttp.MakeApiCall("/UserGeneratedContent/GetPublishedUgcItem", request, AuthType.EntityToken, resultCallback, errorCallback, customData, extraHeaders, context);
        }

        /// <summary>
        /// Gets the status of a publish of an item.
        /// </summary>
        public static void GetPublishStatus(PublishStatusRequest request, Action<PublishStatusResult> resultCallback, Action<PlayFabError> errorCallback, object customData = null, Dictionary<string, string> extraHeaders = null)
        {
            var context = (request == null ? null : request.AuthenticationContext) ?? PlayFabSettings.staticPlayer;


            PlayFabHttp.MakeApiCall("/Catalog/GetPublishStatus", request, AuthType.EntityToken, resultCallback, errorCallback, customData, extraHeaders, context);
        }

        /// <summary>
        /// Get a store by Friendly Id
        /// </summary>
        public static void GetStoreByFriendlyId(GetStoreByFriendlyIdRequest request, Action<GetStoreResult> resultCallback, Action<PlayFabError> errorCallback, object customData = null, Dictionary<string, string> extraHeaders = null)
        {
            var context = (request == null ? null : request.AuthenticationContext) ?? PlayFabSettings.staticPlayer;


            PlayFabHttp.MakeApiCall("/Catalog/GetStoreByFriendlyId", request, AuthType.EntityToken, resultCallback, errorCallback, customData, extraHeaders, context);
        }

        /// <summary>
        /// Get a store by Id
        /// </summary>
        public static void GetStoreById(GetStoreByIdRequest request, Action<GetStoreResult> resultCallback, Action<PlayFabError> errorCallback, object customData = null, Dictionary<string, string> extraHeaders = null)
        {
            var context = (request == null ? null : request.AuthenticationContext) ?? PlayFabSettings.staticPlayer;


            PlayFabHttp.MakeApiCall("/Catalog/GetStoreById", request, AuthType.EntityToken, resultCallback, errorCallback, customData, extraHeaders, context);
        }

        /// <summary>
        /// Get a subscription by Friendly Id
        /// </summary>
        public static void GetSubscriptionByFriendlyId(GetSubscriptionByFriendlyIdRequest request, Action<GetSubscriptionResult> resultCallback, Action<PlayFabError> errorCallback, object customData = null, Dictionary<string, string> extraHeaders = null)
        {
            var context = (request == null ? null : request.AuthenticationContext) ?? PlayFabSettings.staticPlayer;


            PlayFabHttp.MakeApiCall("/Catalog/GetSubscriptionByFriendlyId", request, AuthType.EntityToken, resultCallback, errorCallback, customData, extraHeaders, context);
        }

        /// <summary>
        /// Get a subscription by Id
        /// </summary>
        public static void GetSubscriptionById(GetSubscriptionByIdRequest request, Action<GetSubscriptionResult> resultCallback, Action<PlayFabError> errorCallback, object customData = null, Dictionary<string, string> extraHeaders = null)
        {
            var context = (request == null ? null : request.AuthenticationContext) ?? PlayFabSettings.staticPlayer;


            PlayFabHttp.MakeApiCall("/Catalog/GetSubscriptionById", request, AuthType.EntityToken, resultCallback, errorCallback, customData, extraHeaders, context);
        }

        /// <summary>
        /// Get a subscription by marketplace offer Id
        /// </summary>
        public static void GetSubscriptionByMarketplaceOfferId(GetSubscriptionByMarketplaceOfferIdRequest request, Action<GetSubscriptionResult> resultCallback, Action<PlayFabError> errorCallback, object customData = null, Dictionary<string, string> extraHeaders = null)
        {
            var context = (request == null ? null : request.AuthenticationContext) ?? PlayFabSettings.staticPlayer;


            PlayFabHttp.MakeApiCall("/Catalog/GetSubscriptionByMarketplaceOfferId", request, AuthType.EntityToken, resultCallback, errorCallback, customData, extraHeaders, context);
        }

        /// <summary>
        /// Gets the moderation state for an item, including the concern category and string reason.
        /// </summary>
        public static void GetUgcItemModerationState(GetUgcItemModerationStateRequest request, Action<GetUgcItemModerationStateResult> resultCallback, Action<PlayFabError> errorCallback, object customData = null, Dictionary<string, string> extraHeaders = null)
        {
            var context = (request == null ? null : request.AuthenticationContext) ?? PlayFabSettings.staticPlayer;


            PlayFabHttp.MakeApiCall("/UserGeneratedContent/GetUgcItemModerationState", request, AuthType.EntityToken, resultCallback, errorCallback, customData, extraHeaders, context);
        }

        /// <summary>
        /// Gets the status of a publish of an item.
        /// </summary>
        public static void GetUgcPublishStatus(PublishStatusRequest request, Action<PublishStatusResult> resultCallback, Action<PlayFabError> errorCallback, object customData = null, Dictionary<string, string> extraHeaders = null)
        {
            var context = (request == null ? null : request.AuthenticationContext) ?? PlayFabSettings.staticPlayer;


            PlayFabHttp.MakeApiCall("/UserGeneratedContent/GetUgcPublishStatus", request, AuthType.EntityToken, resultCallback, errorCallback, customData, extraHeaders, context);
        }

        /// <summary>
        /// Get current virtual currencies.
        /// </summary>
        public static void GetVirtualCurrencies(GetVirtualCurrenciesRequest request, Action<GetVirtualCurrenciesResult> resultCallback, Action<PlayFabError> errorCallback, object customData = null, Dictionary<string, string> extraHeaders = null)
        {
            var context = (request == null ? null : request.AuthenticationContext) ?? PlayFabSettings.staticPlayer;


            PlayFabHttp.MakeApiCall("/Inventory/GetVirtualCurrencies", request, AuthType.EntityToken, resultCallback, errorCallback, customData, extraHeaders, context);
        }

        /// <summary>
        /// Grant inventory items.
        /// </summary>
        public static void GrantInventoryItems(GrantInventoryItemsRequest request, Action<GrantInventoryItemsResult> resultCallback, Action<PlayFabError> errorCallback, object customData = null, Dictionary<string, string> extraHeaders = null)
        {
            var context = (request == null ? null : request.AuthenticationContext) ?? PlayFabSettings.staticPlayer;


            PlayFabHttp.MakeApiCall("/Inventory/GrantInventoryItems", request, AuthType.EntityToken, resultCallback, errorCallback, customData, extraHeaders, context);
        }

        /// <summary>
        /// Initiates a publish of an item from the working catalog to the public catalog.
        /// </summary>
        public static void PublishItem(PublishItemRequest request, Action<PublishItemResult> resultCallback, Action<PlayFabError> errorCallback, object customData = null, Dictionary<string, string> extraHeaders = null)
        {
            var context = (request == null ? null : request.AuthenticationContext) ?? PlayFabSettings.staticPlayer;


            PlayFabHttp.MakeApiCall("/Catalog/PublishItem", request, AuthType.EntityToken, resultCallback, errorCallback, customData, extraHeaders, context);
        }

        /// <summary>
        /// Initiates a publish of a item from the working catalog to the public catalog.
        /// </summary>
        public static void PublishUgcItem(PublishItemRequest request, Action<PublishItemResult> resultCallback, Action<PlayFabError> errorCallback, object customData = null, Dictionary<string, string> extraHeaders = null)
        {
            var context = (request == null ? null : request.AuthenticationContext) ?? PlayFabSettings.staticPlayer;


            PlayFabHttp.MakeApiCall("/UserGeneratedContent/PublishUgcItem", request, AuthType.EntityToken, resultCallback, errorCallback, customData, extraHeaders, context);
        }

        /// <summary>
        /// Purchase an item, bundle or subscription by friendly id.
        /// </summary>
        public static void PurchaseItemByFriendlyId(PurchaseItemByFriendlyIdRequest request, Action<PurchaseItemResult> resultCallback, Action<PlayFabError> errorCallback, object customData = null, Dictionary<string, string> extraHeaders = null)
        {
            var context = (request == null ? null : request.AuthenticationContext) ?? PlayFabSettings.staticPlayer;


            PlayFabHttp.MakeApiCall("/Catalog/PurchaseItemByFriendlyId", request, AuthType.EntityToken, resultCallback, errorCallback, customData, extraHeaders, context);
        }

        /// <summary>
        /// Purchase an item, bundle or subscription by id.
        /// </summary>
        public static void PurchaseItemById(PurchaseItemByIdRequest request, Action<PurchaseItemResult> resultCallback, Action<PlayFabError> errorCallback, object customData = null, Dictionary<string, string> extraHeaders = null)
        {
            var context = (request == null ? null : request.AuthenticationContext) ?? PlayFabSettings.staticPlayer;


            PlayFabHttp.MakeApiCall("/Catalog/PurchaseItemById", request, AuthType.EntityToken, resultCallback, errorCallback, customData, extraHeaders, context);
        }

        /// <summary>
        /// Submit a report for a review
        /// </summary>
        public static void ReportReview(ReportReviewRequest request, Action<ReportReviewResult> resultCallback, Action<PlayFabError> errorCallback, object customData = null, Dictionary<string, string> extraHeaders = null)
        {
            var context = (request == null ? null : request.AuthenticationContext) ?? PlayFabSettings.staticPlayer;


            PlayFabHttp.MakeApiCall("/Catalog/ReportReview", request, AuthType.EntityToken, resultCallback, errorCallback, customData, extraHeaders, context);
        }

        /// <summary>
        /// Submit a report for an item, indicating in what way the item is inappropriate.
        /// </summary>
        public static void ReportUgcItem(ReportItemRequest request, Action<ReportItemResult> resultCallback, Action<PlayFabError> errorCallback, object customData = null, Dictionary<string, string> extraHeaders = null)
        {
            var context = (request == null ? null : request.AuthenticationContext) ?? PlayFabSettings.staticPlayer;


            PlayFabHttp.MakeApiCall("/UserGeneratedContent/ReportUgcItem", request, AuthType.EntityToken, resultCallback, errorCallback, customData, extraHeaders, context);
        }

        /// <summary>
        /// Execute a search against the public catalog using the provided search parameters and returns a set of paginated results.
        /// </summary>
        public static void Search(CatalogSearchRequest request, Action<CatalogSearchResult> resultCallback, Action<PlayFabError> errorCallback, object customData = null, Dictionary<string, string> extraHeaders = null)
        {
            var context = (request == null ? null : request.AuthenticationContext) ?? PlayFabSettings.staticPlayer;


            PlayFabHttp.MakeApiCall("/Catalog/Search", request, AuthType.EntityToken, resultCallback, errorCallback, customData, extraHeaders, context);
        }

        /// <summary>
        /// Execute a search against the set of all bundles, using the provided search parameters and returns a set of paginated
        /// results
        /// </summary>
        public static void SearchBundles(SearchBundlesRequest request, Action<SearchBundlesResult> resultCallback, Action<PlayFabError> errorCallback, object customData = null, Dictionary<string, string> extraHeaders = null)
        {
            var context = (request == null ? null : request.AuthenticationContext) ?? PlayFabSettings.staticPlayer;


            PlayFabHttp.MakeApiCall("/Catalog/SearchBundles", request, AuthType.EntityToken, resultCallback, errorCallback, customData, extraHeaders, context);
        }

        /// <summary>
        /// Search for a given item (by friendly id) and return a set of bundles/subscriptions/stores containing the item
        /// </summary>
        public static void SearchForItemsContainingItemByFriendlyId(SearchForItemsContainingItemByFriendlyIdRequest request, Action<SearchForItemsContainingItemResult> resultCallback, Action<PlayFabError> errorCallback, object customData = null, Dictionary<string, string> extraHeaders = null)
        {
            var context = (request == null ? null : request.AuthenticationContext) ?? PlayFabSettings.staticPlayer;


            PlayFabHttp.MakeApiCall("/Catalog/SearchForItemsContainingItemByFriendlyId", request, AuthType.EntityToken, resultCallback, errorCallback, customData, extraHeaders, context);
        }

        /// <summary>
        /// Search for a given item (by id) and return a set of bundles/subscriptions/stores containing the item
        /// </summary>
        public static void SearchForItemsContainingItemById(SearchForItemsContainingItemByIdRequest request, Action<SearchForItemsContainingItemResult> resultCallback, Action<PlayFabError> errorCallback, object customData = null, Dictionary<string, string> extraHeaders = null)
        {
            var context = (request == null ? null : request.AuthenticationContext) ?? PlayFabSettings.staticPlayer;


            PlayFabHttp.MakeApiCall("/Catalog/SearchForItemsContainingItemById", request, AuthType.EntityToken, resultCallback, errorCallback, customData, extraHeaders, context);
        }

        /// <summary>
        /// Execute a search against a specified store (by friendly id) using the provided search parameters and return a set of
        /// paginated results
        /// </summary>
        public static void SearchInStoreByFriendlyId(SearchInStoreByFriendlyIdRequest request, Action<SearchInStoreResult> resultCallback, Action<PlayFabError> errorCallback, object customData = null, Dictionary<string, string> extraHeaders = null)
        {
            var context = (request == null ? null : request.AuthenticationContext) ?? PlayFabSettings.staticPlayer;


            PlayFabHttp.MakeApiCall("/Catalog/SearchInStoreByFriendlyId", request, AuthType.EntityToken, resultCallback, errorCallback, customData, extraHeaders, context);
        }

        /// <summary>
        /// Execute a search against a specified store (by id) using the provided search parameters and return a set of paginated
        /// results
        /// </summary>
        public static void SearchInStoreById(SearchInStoreByIdRequest request, Action<SearchInStoreResult> resultCallback, Action<PlayFabError> errorCallback, object customData = null, Dictionary<string, string> extraHeaders = null)
        {
            var context = (request == null ? null : request.AuthenticationContext) ?? PlayFabSettings.staticPlayer;


            PlayFabHttp.MakeApiCall("/Catalog/SearchInStoreById", request, AuthType.EntityToken, resultCallback, errorCallback, customData, extraHeaders, context);
        }

        /// <summary>
        /// Execute a search against the set of all stores, using the provided search parameters and returns a set of paginated
        /// results
        /// </summary>
        public static void SearchStores(SearchStoresRequest request, Action<SearchStoresResult> resultCallback, Action<PlayFabError> errorCallback, object customData = null, Dictionary<string, string> extraHeaders = null)
        {
            var context = (request == null ? null : request.AuthenticationContext) ?? PlayFabSettings.staticPlayer;


            PlayFabHttp.MakeApiCall("/Catalog/SearchStores", request, AuthType.EntityToken, resultCallback, errorCallback, customData, extraHeaders, context);
        }

        /// <summary>
        /// Execute a search against the set of all subscriptions, using the provided search parameters and returns a set of
        /// paginated results
        /// </summary>
        public static void SearchSubscriptions(SearchSubscriptionsRequest request, Action<SearchSubscriptionsResult> resultCallback, Action<PlayFabError> errorCallback, object customData = null, Dictionary<string, string> extraHeaders = null)
        {
            var context = (request == null ? null : request.AuthenticationContext) ?? PlayFabSettings.staticPlayer;


            PlayFabHttp.MakeApiCall("/Catalog/SearchSubscriptions", request, AuthType.EntityToken, resultCallback, errorCallback, customData, extraHeaders, context);
        }

        /// <summary>
        /// Set inventory items
        /// </summary>
        public static void SetInventoryItems(SetInventoryItemsRequest request, Action<SetInventoryItemsResult> resultCallback, Action<PlayFabError> errorCallback, object customData = null, Dictionary<string, string> extraHeaders = null)
        {
            var context = (request == null ? null : request.AuthenticationContext) ?? PlayFabSettings.staticPlayer;


            PlayFabHttp.MakeApiCall("/Inventory/SetInventoryItems", request, AuthType.EntityToken, resultCallback, errorCallback, customData, extraHeaders, context);
        }

        /// <summary>
        /// Sets the moderation state for an item, including the concern category and string reason.
        /// </summary>
        public static void SetUgcItemModerationState(SetUgcItemModerationStateRequest request, Action<SetUgcItemModerationStateResult> resultCallback, Action<PlayFabError> errorCallback, object customData = null, Dictionary<string, string> extraHeaders = null)
        {
            var context = (request == null ? null : request.AuthenticationContext) ?? PlayFabSettings.staticPlayer;


            PlayFabHttp.MakeApiCall("/UserGeneratedContent/SetUgcItemModerationState", request, AuthType.EntityToken, resultCallback, errorCallback, customData, extraHeaders, context);
        }

        /// <summary>
        /// Set virtual currencies
        /// </summary>
        public static void SetVirtualCurrencies(SetVirtualCurrenciesRequest request, Action<SetVirtualCurrenciesResult> resultCallback, Action<PlayFabError> errorCallback, object customData = null, Dictionary<string, string> extraHeaders = null)
        {
            var context = (request == null ? null : request.AuthenticationContext) ?? PlayFabSettings.staticPlayer;


            PlayFabHttp.MakeApiCall("/Inventory/SetVirtualCurrencies", request, AuthType.EntityToken, resultCallback, errorCallback, customData, extraHeaders, context);
        }

        /// <summary>
        /// Submit a vote for a review, indicating whether the review was helpful or unhelpful.
        /// </summary>
        public static void SubmitHelpfulnessVote(HelpfulnessVoteRequest request, Action<HelpfulnessVoteResult> resultCallback, Action<PlayFabError> errorCallback, object customData = null, Dictionary<string, string> extraHeaders = null)
        {
            var context = (request == null ? null : request.AuthenticationContext) ?? PlayFabSettings.staticPlayer;


            PlayFabHttp.MakeApiCall("/Catalog/SubmitHelpfulnessVote", request, AuthType.EntityToken, resultCallback, errorCallback, customData, extraHeaders, context);
        }

        /// <summary>
        /// Decrease virtual currencies amount.
        /// </summary>
        public static void SubtractVirtualCurrencies(SubtractVirtualCurrenciesRequest request, Action<SubtractVirtualCurrenciesResult> resultCallback, Action<PlayFabError> errorCallback, object customData = null, Dictionary<string, string> extraHeaders = null)
        {
            var context = (request == null ? null : request.AuthenticationContext) ?? PlayFabSettings.staticPlayer;


            PlayFabHttp.MakeApiCall("/Inventory/SubtractVirtualCurrencies", request, AuthType.EntityToken, resultCallback, errorCallback, customData, extraHeaders, context);
        }

        /// <summary>
        /// Submit a request to takedown one or more reviews.
        /// </summary>
        public static void TakedownReviews(TakedownReviewsRequest request, Action<TakedownReviewsResult> resultCallback, Action<PlayFabError> errorCallback, object customData = null, Dictionary<string, string> extraHeaders = null)
        {
            var context = (request == null ? null : request.AuthenticationContext) ?? PlayFabSettings.staticPlayer;


            PlayFabHttp.MakeApiCall("/Catalog/TakedownReviews", request, AuthType.EntityToken, resultCallback, errorCallback, customData, extraHeaders, context);
        }

        /// <summary>
        /// Update a bundle
        /// </summary>
        public static void UpdateBundle(UpdateBundleRequest request, Action<UpdateBundleResult> resultCallback, Action<PlayFabError> errorCallback, object customData = null, Dictionary<string, string> extraHeaders = null)
        {
            var context = (request == null ? null : request.AuthenticationContext) ?? PlayFabSettings.staticPlayer;


            PlayFabHttp.MakeApiCall("/Catalog/UpdateBundle", request, AuthType.EntityToken, resultCallback, errorCallback, customData, extraHeaders, context);
        }

        /// <summary>
        /// Gets the configuration for the catalog.
        /// </summary>
        public static void UpdateCatalogConfig(UpdateCatalogConfigRequest request, Action<UpdateCatalogConfigResult> resultCallback, Action<PlayFabError> errorCallback, object customData = null, Dictionary<string, string> extraHeaders = null)
        {
            var context = (request == null ? null : request.AuthenticationContext) ?? PlayFabSettings.staticPlayer;


            PlayFabHttp.MakeApiCall("/Catalog/UpdateCatalogConfig", request, AuthType.EntityToken, resultCallback, errorCallback, customData, extraHeaders, context);
        }

        /// <summary>
        /// Update a currency
        /// </summary>
        public static void UpdateCurrency(UpdateCurrencyRequest request, Action<UpdateCurrencyResult> resultCallback, Action<PlayFabError> errorCallback, object customData = null, Dictionary<string, string> extraHeaders = null)
        {
            var context = (request == null ? null : request.AuthenticationContext) ?? PlayFabSettings.staticPlayer;


            PlayFabHttp.MakeApiCall("/Catalog/UpdateCurrency", request, AuthType.EntityToken, resultCallback, errorCallback, customData, extraHeaders, context);
        }

        /// <summary>
        /// Update the metadata for an item in the working catalog.
        /// </summary>
        public static void UpdateDraftItem(UpdateDraftItemRequest request, Action<UpdateDraftItemResult> resultCallback, Action<PlayFabError> errorCallback, object customData = null, Dictionary<string, string> extraHeaders = null)
        {
            var context = (request == null ? null : request.AuthenticationContext) ?? PlayFabSettings.staticPlayer;


            PlayFabHttp.MakeApiCall("/Catalog/UpdateDraftItem", request, AuthType.EntityToken, resultCallback, errorCallback, customData, extraHeaders, context);
        }

        /// <summary>
        /// Update the metadata for an item in the working catalog.
        /// </summary>
        public static void UpdateDraftUgcItem(UpdateDraftItemRequest request, Action<UpdateDraftItemResult> resultCallback, Action<PlayFabError> errorCallback, object customData = null, Dictionary<string, string> extraHeaders = null)
        {
            var context = (request == null ? null : request.AuthenticationContext) ?? PlayFabSettings.staticPlayer;


            PlayFabHttp.MakeApiCall("/UserGeneratedContent/UpdateDraftUgcItem", request, AuthType.EntityToken, resultCallback, errorCallback, customData, extraHeaders, context);
        }

        /// <summary>
        /// Update inventory Items.
        /// </summary>
        public static void UpdateInventoryItemsProperties(UpdateInventoryItemsPropertiesRequest request, Action<UpdateInventoryPropertiesItemsResult> resultCallback, Action<PlayFabError> errorCallback, object customData = null, Dictionary<string, string> extraHeaders = null)
        {
            var context = (request == null ? null : request.AuthenticationContext) ?? PlayFabSettings.staticPlayer;


            PlayFabHttp.MakeApiCall("/Inventory/UpdateInventoryItemsProperties", request, AuthType.EntityToken, resultCallback, errorCallback, customData, extraHeaders, context);
        }

        /// <summary>
        /// Update a store
        /// </summary>
        public static void UpdateStore(UpdateStoreRequest request, Action<UpdateStoreResult> resultCallback, Action<PlayFabError> errorCallback, object customData = null, Dictionary<string, string> extraHeaders = null)
        {
            var context = (request == null ? null : request.AuthenticationContext) ?? PlayFabSettings.staticPlayer;


            PlayFabHttp.MakeApiCall("/Catalog/UpdateStore", request, AuthType.EntityToken, resultCallback, errorCallback, customData, extraHeaders, context);
        }

        /// <summary>
        /// Update a subscription
        /// </summary>
        public static void UpdateSubscription(UpdateSubscriptionRequest request, Action<UpdateSubscriptionResult> resultCallback, Action<PlayFabError> errorCallback, object customData = null, Dictionary<string, string> extraHeaders = null)
        {
            var context = (request == null ? null : request.AuthenticationContext) ?? PlayFabSettings.staticPlayer;


            PlayFabHttp.MakeApiCall("/Catalog/UpdateSubscription", request, AuthType.EntityToken, resultCallback, errorCallback, customData, extraHeaders, context);
        }


    }
}

#endif
