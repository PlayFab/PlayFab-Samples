#if !DISABLE_PLAYFABENTITY_API
using System;
using System.Collections.Generic;
using PlayFab.SharedModels;

namespace PlayFab.EconomyModels
{
    /// <summary>
    /// Given an entity type, entity identifier and container details, will increase the entity's currencies by a specific
    /// amount.
    /// </summary>
    [Serializable]
    public class AddVirtualCurrenciesRequest : PlayFabRequestCommon
    {
        /// <summary>
        /// A list of currencies to modify
        /// </summary>
        public List<CurrencyDetails> Currencies;
        /// <summary>
        /// The entity to perform this action on.
        /// </summary>
        public EntityKey Entity;
        /// <summary>
        /// The Idempotency Id for this request
        /// </summary>
        public string IdempotencyId;
    }

    [Serializable]
    public class AddVirtualCurrenciesResult : PlayFabResultCommon
    {
        public List<CurrencyResponseDto> Currencies;
        /// <summary>
        /// The Idempotency Id for this request
        /// </summary>
        public string IdempotencyId;
    }

    [Serializable]
    public class CatalogAlternateId : PlayFabBaseModel
    {
        /// <summary>
        /// Type of the alternate Id
        /// </summary>
        public string Type;
        /// <summary>
        /// Value of the alternate Id
        /// </summary>
        public string Value;
    }

    [Serializable]
    public class CatalogConfig : PlayFabBaseModel
    {
        /// <summary>
        /// A list of title player accounts that will have admin permissions.
        /// </summary>
        public List<string> Admins;
        /// <summary>
        /// The set of configuration that only applies to catalog items.
        /// </summary>
        public CatalogSpecificConfig Catalog;
        /// <summary>
        /// A list of deep link formats.
        /// </summary>
        public List<DeepLinkFormat> DeepLinkFormats;
        /// <summary>
        /// A list of display properties to index.
        /// </summary>
        public List<DisplayPropertyIndexInfo> DisplayPropertyIndexInfos;
        /// <summary>
        /// A set of player entity keys that are allowed to review content.
        /// </summary>
        public List<string> Reviewers;
        /// <summary>
        /// The set of configuration that only applies to user generated contents.
        /// </summary>
        public UserGeneratedContentSpecificConfig UserGeneratedContent;
    }

    [Serializable]
    public class CatalogItemMetadata : PlayFabBaseModel
    {
        /// <summary>
        /// Indicates whether there can be multiple stacks of this item.
        /// </summary>
        public bool? AllowMultipleStacks;
        /// <summary>
        /// The alternate IDs associated with this item.
        /// </summary>
        public List<CatalogAlternateId> AlternateIds;
        /// <summary>
        /// The set of contents associated with this item.
        /// </summary>
        public List<Content> Contents;
        /// <summary>
        /// The client-defined type of the item.
        /// </summary>
        public string ContentType;
        /// <summary>
        /// The date and time when this item was created.
        /// </summary>
        public DateTime? CreationDate;
        /// <summary>
        /// The ID of the creator of this catalog item.
        /// </summary>
        public EntityKey CreatorEntityKey;
        /// <summary>
        /// The set of platform specific deep links for this item.
        /// </summary>
        public List<DeepLink> DeepLinks;
        /// <summary>
        /// A dictionary of localized descriptions. Key is language code and localized string is the value. The neutral locale is
        /// required.
        /// </summary>
        public Dictionary<string,string> Description;
        /// <summary>
        /// Game specific properties for display purposes. This is an arbitrary JSON blob.
        /// </summary>
        public object DisplayProperties;
        /// <summary>
        /// The user provided version of the item for display purposes.
        /// </summary>
        public string DisplayVersion;
        /// <summary>
        /// The date of when the item will cease to be available. If not provided then the product will be available indefinitely.
        /// </summary>
        public DateTime? EndDate;
        /// <summary>
        /// The current ETag value that can be used for optimistic concurrency in the If-None-Match header.
        /// </summary>
        public string ETag;
        /// <summary>
        /// The unique ID of the item.
        /// </summary>
        public string Id;
        /// <summary>
        /// The images associated with this item. Images can be thumbnails or screenshots.
        /// </summary>
        public List<Image> Images;
        /// <summary>
        /// Indicates whether the item is a consumable or durable.
        /// </summary>
        public bool? IsConsumable;
        /// <summary>
        /// Indicates if the item is hidden.
        /// </summary>
        public bool? IsHidden;
        /// <summary>
        /// Indicates if this item can be stacked or if they should be handled individually.
        /// </summary>
        public bool? IsStackable;
        /// <summary>
        /// The item references associated with this item.
        /// </summary>
        public List<CatalogItemReference> ItemReferences;
        /// <summary>
        /// The date and time this item was last updated.
        /// </summary>
        public DateTime? LastModifiedDate;
        /// <summary>
        /// The moderation state for this item.
        /// </summary>
        public ModerationState Moderation;
        /// <summary>
        /// The payout information of the payee.
        /// </summary>
        public PayoutInfo PayoutInfo;
        /// <summary>
        /// The platforms supported by this item.
        /// </summary>
        public List<string> Platforms;
        /// <summary>
        /// The base price of this item.
        /// </summary>
        public CatalogPrice Price;
        /// <summary>
        /// Rating summary for this UGC item.
        /// </summary>
        public Rating Rating;
        /// <summary>
        /// The title or namespace that this item belongs to.
        /// </summary>
        public EntityKey SourceEntityKey;
        /// <summary>
        /// The date of when the item will be available. If not provided then the product will appear immediately.
        /// </summary>
        public DateTime? StartDate;
        /// <summary>
        /// Additional metadata for subscription items.
        /// </summary>
        public SubscriptionDetails Subscription;
        /// <summary>
        /// The list of tags that are associated with this item.
        /// </summary>
        public List<string> Tags;
        /// <summary>
        /// A dictionary of localized titles. Key is language code and localized string is the value. The neutral locale is
        /// required.
        /// </summary>
        public Dictionary<string,string> Title;
        /// <summary>
        /// The high-level type of the item.
        /// </summary>
        public string Type;
    }

    [Serializable]
    public class CatalogItemReference : PlayFabBaseModel
    {
        /// <summary>
        /// The amount of the catalog item.
        /// </summary>
        public int? Amount;
        /// <summary>
        /// The unique ID of the catalog item.
        /// </summary>
        public string Id;
        /// <summary>
        /// The price of the catalog item.
        /// </summary>
        public CatalogPrice Price;
    }

    [Serializable]
    public class CatalogPrice : PlayFabBaseModel
    {
        /// <summary>
        /// The amount the payee will receive.
        /// </summary>
        public double? PayoutAmount;
        /// <summary>
        /// Prices of the catalog item.
        /// </summary>
        public List<CatalogPriceInstance> Prices;
        /// <summary>
        /// Sort setting of the catalog item.
        /// </summary>
        public int? Sort;
    }

    [Serializable]
    public class CatalogPriceAmount : PlayFabBaseModel
    {
        /// <summary>
        /// The amount of the catalog price.
        /// </summary>
        public int Amount;
        /// <summary>
        /// The currency ID of the catalog price.
        /// </summary>
        public string CurrencyId;
    }

    [Serializable]
    public class CatalogPriceInstance : PlayFabBaseModel
    {
        /// <summary>
        /// The amounts of the catalog item price.
        /// </summary>
        public List<CatalogPriceAmount> Amounts;
    }

    [Serializable]
    public class CatalogSearchRequest : PlayFabRequestCommon
    {
        /// <summary>
        /// The entity to perform this action on.
        /// </summary>
        public EntityKey Entity;
        /// <summary>
        /// An OData filter used to refine the search query.
        /// </summary>
        public string Filter;
        /// <summary>
        /// An OData orderBy used to order the results of the search query.
        /// </summary>
        public string OrderBy;
        /// <summary>
        /// The text to search for.
        /// </summary>
        public string Search;
        /// <summary>
        /// An OData select query option used to augment the search results. If not defined, the default search result metadata will
        /// be returned.
        /// </summary>
        public string Select;
        /// <summary>
        /// The number of results to skip.
        /// </summary>
        public int Skip;
        /// <summary>
        /// The title or namespace to search under.
        /// </summary>
        public EntityKey SourceEntityKey;
        /// <summary>
        /// The ID of the title that this catalog item is associated with.
        /// </summary>
        public string TitleId;
        /// <summary>
        /// The number of results to retrieve.
        /// </summary>
        public int Top;
    }

    [Serializable]
    public class CatalogSearchResult : PlayFabResultCommon
    {
        /// <summary>
        /// The total count of hits for the search query.
        /// </summary>
        public int? Count;
        /// <summary>
        /// The paginated set of results for the search query.
        /// </summary>
        public List<CatalogItemMetadata> Items;
    }

    [Serializable]
    public class CatalogSpecificConfig : PlayFabBaseModel
    {
        /// <summary>
        /// The set of content types that will be used for validation and if no values are provided then anything is allowed.
        /// </summary>
        public List<string> ContentTypes;
        /// <summary>
        /// The set of tags that will be used for validation and if no values are provided then anything is allowed.
        /// </summary>
        public List<string> Tags;
    }

    public enum ConcernCategory
    {
        None,
        OffensiveContent,
        ChildExploitation,
        MalwareOrVirus,
        PrivacyConcerns,
        MisleadingApp,
        PoorPerformance,
        ReviewResponse,
        SpamAdvertising,
        Profanity
    }

    /// <summary>
    /// Given an entity type, entity identifier and container details, will consume the specified inventory items.
    /// </summary>
    [Serializable]
    public class ConsumeInventoryItemsRequest : PlayFabRequestCommon
    {
        /// <summary>
        /// The entity to perform this action on.
        /// </summary>
        public EntityKey Entity;
        /// <summary>
        /// The Idempotency Id for this request
        /// </summary>
        public string IdempotencyId;
        /// <summary>
        /// A list of Items to modify
        /// </summary>
        public List<InventoryItemDetails> Items;
    }

    [Serializable]
    public class ConsumeInventoryItemsResult : PlayFabResultCommon
    {
        /// <summary>
        /// The Idempotency Id for this request
        /// </summary>
        public string IdempotencyId;
        public List<InventoryItemResponseDto> Items;
    }

    public enum ContainerType
    {
        None,
        Bundles,
        Stores,
        Subscriptions
    }

    [Serializable]
    public class Content : PlayFabBaseModel
    {
        public string Id;
        /// <summary>
        /// The maximum client version that this content is compatible with.
        /// </summary>
        public string MaxClientVersion;
        /// <summary>
        /// The minimum client version that this content is compatible with.
        /// </summary>
        public string MinClientVersion;
        /// <summary>
        /// The list of tags that are associated with this content.
        /// </summary>
        public List<string> Tags;
        /// <summary>
        /// The client-defined type of the content.
        /// </summary>
        public string Type;
        /// <summary>
        /// The Azure CDN URL for retrieval of the catalog item binary content.
        /// </summary>
        public string Url;
    }

    /// <summary>
    /// Create bundle request
    /// </summary>
    [Serializable]
    public class CreateBundleRequest : PlayFabRequestCommon
    {
        /// <summary>
        /// Allow overwrite
        /// </summary>
        public bool AllowOverwrite;
        /// <summary>
        /// Bundle details
        /// </summary>
        public CatalogItemMetadata Bundle;
        /// <summary>
        /// The Idempotency Id for this request
        /// </summary>
        public string IdempotencyId;
    }

    /// <summary>
    /// Create bundle result
    /// </summary>
    [Serializable]
    public class CreateBundleResult : PlayFabResultCommon
    {
        public CatalogItemMetadata Bundle;
        /// <summary>
        /// The Idempotency Id for this request
        /// </summary>
        public string IdempotencyId;
    }

    /// <summary>
    /// Given an entity type, and currency details, create a currency.
    /// </summary>
    [Serializable]
    public class CreateCurrencyRequest : PlayFabRequestCommon
    {
        /// <summary>
        /// Metadata describing the new currency item to be created.
        /// </summary>
        public CatalogItemMetadata Currency;
        /// <summary>
        /// The entity to perform this action on.
        /// </summary>
        public EntityKey Entity;
    }

    [Serializable]
    public class CreateCurrencyResult : PlayFabResultCommon
    {
        /// <summary>
        /// Updated metadata describing the catalog item just created.
        /// </summary>
        public CatalogItemMetadata CurrencyMetadata;
        /// <summary>
        /// The entity to perform this action on.
        /// </summary>
        public EntityKey Entity;
    }

    /// <summary>
    /// The item will not be published to the public catalog until the user makes a call to the PublishItem API.
    /// </summary>
    [Serializable]
    public class CreateDraftItemRequest : PlayFabRequestCommon
    {
        /// <summary>
        /// The entity to perform this action on.
        /// </summary>
        public EntityKey Entity;
        /// <summary>
        /// Metadata describing the new catalog item to be created.
        /// </summary>
        public CatalogItemMetadata Item;
    }

    [Serializable]
    public class CreateDraftItemResult : PlayFabResultCommon
    {
        /// <summary>
        /// Updated metadata describing the catalog item just created.
        /// </summary>
        public CatalogItemMetadata Item;
    }

    [Serializable]
    public class CreateOrUpdateReviewRequest : PlayFabRequestCommon
    {
        /// <summary>
        /// The entity to perform this action on.
        /// </summary>
        public EntityKey Entity;
        /// <summary>
        /// The ID of the item to submit a review for.
        /// </summary>
        public string ItemId;
        /// <summary>
        /// The review to submit.
        /// </summary>
        public ReviewSubmission Review;
    }

    [Serializable]
    public class CreateOrUpdateReviewResult : PlayFabResultCommon
    {
    }

    /// <summary>
    /// Create store request
    /// </summary>
    [Serializable]
    public class CreateStoreRequest : PlayFabRequestCommon
    {
        /// <summary>
        /// Allow overwrite
        /// </summary>
        public bool AllowOverwrite;
        /// <summary>
        /// The entity to perform this action on.
        /// </summary>
        public EntityKey Entity;
        /// <summary>
        /// The Idempotency Id for this request
        /// </summary>
        public string IdempotencyId;
        /// <summary>
        /// Store details
        /// </summary>
        public CatalogItemMetadata Store;
    }

    /// <summary>
    /// Create store result
    /// </summary>
    [Serializable]
    public class CreateStoreResult : PlayFabResultCommon
    {
        /// <summary>
        /// The Idempotency Id for this request
        /// </summary>
        public string IdempotencyId;
        public CatalogItemMetadata Store;
    }

    /// <summary>
    /// Create subscription request
    /// </summary>
    [Serializable]
    public class CreateSubscriptionRequest : PlayFabRequestCommon
    {
        /// <summary>
        /// Allow overwrite
        /// </summary>
        public bool AllowOverwrite;
        /// <summary>
        /// The Idempotency Id for this request
        /// </summary>
        public string IdempotencyId;
        /// <summary>
        /// Subscription details
        /// </summary>
        public CatalogItemMetadata Subscription;
    }

    /// <summary>
    /// Create subscription result
    /// </summary>
    [Serializable]
    public class CreateSubscriptionResult : PlayFabResultCommon
    {
        /// <summary>
        /// The Idempotency Id for this request
        /// </summary>
        public string IdempotencyId;
        public CatalogItemMetadata Subscription;
    }

    /// <summary>
    /// Upload URLs point to Azure Blobs; clients must follow the Microsoft Azure Storage Blob Service REST API pattern for
    /// uploading content. The response contains upload URLs and IDs for each file. The IDs and URLs returned must be added to
    /// the item metadata and commited using the CreateDraftItem or UpdateDraftItem Item APIs.
    /// </summary>
    [Serializable]
    public class CreateUploadUrlsRequest : PlayFabRequestCommon
    {
        /// <summary>
        /// The entity to perform this action on.
        /// </summary>
        public EntityKey Entity;
        /// <summary>
        /// Description of the files to be uploaded by the client.
        /// </summary>
        public List<UploadInfo> Files;
        /// <summary>
        /// The title or namespace that this content belongs to.
        /// </summary>
        public EntityKey SourceEntityKey;
    }

    [Serializable]
    public class CreateUploadUrlsResult : PlayFabResultCommon
    {
        /// <summary>
        /// Urls and metadata for the files to be uploaded by the client.
        /// </summary>
        public List<UploadUrlMetadata> UploadUrls;
    }

    [Serializable]
    public class CurrencyDetails : PlayFabBaseModel
    {
        public CatalogAlternateId AlternateId;
        public int Amount;
        public string CurrencyId;
        public string InstanceId;
    }

    [Serializable]
    public class CurrencyResponseDto : PlayFabBaseModel
    {
        public int Amount;
        public int? ChangedAmount;
        public string CurrencyId;
    }

    [Serializable]
    public class DeepLink : PlayFabBaseModel
    {
        /// <summary>
        /// Target platform for this deep link.
        /// </summary>
        public string Platform;
        /// <summary>
        /// The deep link for this platform.
        /// </summary>
        public string Url;
    }

    [Serializable]
    public class DeepLinkFormat : PlayFabBaseModel
    {
        /// <summary>
        /// The format of the deep link to return. The format should contain '{id}' to represent where the item ID should be placed.
        /// </summary>
        public string Format;
        /// <summary>
        /// The target platform for the deep link.
        /// </summary>
        public string Platform;
    }

    /// <summary>
    /// Delete bundle by friendly Id request
    /// </summary>
    [Serializable]
    public class DeleteBundleByFriendlyIdRequest : PlayFabRequestCommon
    {
        /// <summary>
        /// The friendly Id of target bundle.
        /// </summary>
        public string FriendlyId;
        /// <summary>
        /// The Idempotency Id for this request
        /// </summary>
        public string IdempotencyId;
        /// <summary>
        /// The title or namespace the bundle is in.
        /// </summary>
        public EntityKey SourceEntityKey;
    }

    /// <summary>
    /// Delete bundle by Id request
    /// </summary>
    [Serializable]
    public class DeleteBundleByIdRequest : PlayFabRequestCommon
    {
        /// <summary>
        /// Id of target bundle
        /// </summary>
        public string Id;
        /// <summary>
        /// The Idempotency Id for this request
        /// </summary>
        public string IdempotencyId;
        /// <summary>
        /// The title or namespace the bundle is in.
        /// </summary>
        public EntityKey SourceEntityKey;
    }

    /// <summary>
    /// Delete bundle result
    /// </summary>
    [Serializable]
    public class DeleteBundleResult : PlayFabResultCommon
    {
        /// <summary>
        /// The Idempotency Id for this request
        /// </summary>
        public string IdempotencyId;
    }

    [Serializable]
    public class DeleteItemRequest : PlayFabRequestCommon
    {
        /// <summary>
        /// The entity to perform this action on.
        /// </summary>
        public EntityKey Entity;
        /// <summary>
        /// ID of the catalog item to delete.
        /// </summary>
        public string ItemId;
    }

    [Serializable]
    public class DeleteItemResult : PlayFabResultCommon
    {
    }

    /// <summary>
    /// Delete store by Friendly Id request
    /// </summary>
    [Serializable]
    public class DeleteStoreByFriendlyIdRequest : PlayFabRequestCommon
    {
        /// <summary>
        /// The entity to perform this action on.
        /// </summary>
        public EntityKey Entity;
        /// <summary>
        /// The friendly Id of target store.
        /// </summary>
        public string FriendlyId;
        /// <summary>
        /// The Idempotency Id for this request
        /// </summary>
        public string IdempotencyId;
        /// <summary>
        /// The title or namespace the store is in.
        /// </summary>
        public EntityKey SourceEntityKey;
    }

    /// <summary>
    /// Delete store by Id request
    /// </summary>
    [Serializable]
    public class DeleteStoreByIdRequest : PlayFabRequestCommon
    {
        /// <summary>
        /// The entity to perform this action on.
        /// </summary>
        public EntityKey Entity;
        /// <summary>
        /// Id of target store
        /// </summary>
        public string Id;
        /// <summary>
        /// The Idempotency Id for this request
        /// </summary>
        public string IdempotencyId;
        /// <summary>
        /// The title or namespace the store is in.
        /// </summary>
        public EntityKey SourceEntityKey;
    }

    /// <summary>
    /// Delete store result
    /// </summary>
    [Serializable]
    public class DeleteStoreResult : PlayFabResultCommon
    {
        /// <summary>
        /// The Idempotency Id for this request
        /// </summary>
        public string IdempotencyId;
    }

    /// <summary>
    /// Delete Subscription by friendly Id request
    /// </summary>
    [Serializable]
    public class DeleteSubscriptionByFriendlyIdRequest : PlayFabRequestCommon
    {
        /// <summary>
        /// The friendly Id of target subscription.
        /// </summary>
        public string FriendlyId;
        /// <summary>
        /// The Idempotency Id for this request
        /// </summary>
        public string IdempotencyId;
        /// <summary>
        /// The title or namespace the subscription is in.
        /// </summary>
        public EntityKey SourceEntityKey;
    }

    /// <summary>
    /// Delete subscription by Id request
    /// </summary>
    [Serializable]
    public class DeleteSubscriptionByIdRequest : PlayFabRequestCommon
    {
        /// <summary>
        /// The Id of target subscription
        /// </summary>
        public string Id;
        /// <summary>
        /// The Idempotency Id for this request
        /// </summary>
        public string IdempotencyId;
        /// <summary>
        /// The title or namespace the subscription is in.
        /// </summary>
        public EntityKey SourceEntityKey;
    }

    /// <summary>
    /// Delete subscription result
    /// </summary>
    [Serializable]
    public class DeleteSubscriptionResult : PlayFabResultCommon
    {
        /// <summary>
        /// The Idempotency Id for this request
        /// </summary>
        public string IdempotencyId;
    }

    [Serializable]
    public class DisplayPropertyIndexInfo : PlayFabBaseModel
    {
        /// <summary>
        /// The property name in the 'DisplayProperties' property to be indexed.
        /// </summary>
        public string Name;
        /// <summary>
        /// The type of the property to be indexed.
        /// </summary>
        public DisplayPropertyType? Type;
    }

    public enum DisplayPropertyType
    {
        QueryDateTime,
        QueryDouble,
        QueryString,
        SearchString
    }

    /// <summary>
    /// Combined entity type and ID structure which uniquely identifies a single entity.
    /// </summary>
    [Serializable]
    public class EntityKey : PlayFabBaseModel
    {
        /// <summary>
        /// Unique ID of the entity.
        /// </summary>
        public string Id;
        /// <summary>
        /// Entity type. See https://api.playfab.com/docs/tutorials/entities/entitytypes
        /// </summary>
        public string Type;
    }

    /// <summary>
    /// Get bundle by friendly Id request
    /// </summary>
    [Serializable]
    public class GetBundleByFriendlyIdRequest : PlayFabRequestCommon
    {
        /// <summary>
        /// Whether to expand the referenced items
        /// </summary>
        public bool ExpandReferencedItems;
        /// <summary>
        /// The friendly Id of target bundle.
        /// </summary>
        public string FriendlyId;
        /// <summary>
        /// The title or namespace the item is in.
        /// </summary>
        public EntityKey SourceEntityKey;
    }

    /// <summary>
    /// Get bundle by Id request
    /// </summary>
    [Serializable]
    public class GetBundleByIdRequest : PlayFabRequestCommon
    {
        /// <summary>
        /// Whether to expand the referenced items
        /// </summary>
        public bool ExpandReferencedItems;
        /// <summary>
        /// Id of target bundle
        /// </summary>
        public string Id;
        /// <summary>
        /// The title or namespace the item is in.
        /// </summary>
        public EntityKey SourceEntityKey;
    }

    /// <summary>
    /// Get bundle by marketplace offer Id request
    /// </summary>
    [Serializable]
    public class GetBundleByMarketplaceOfferIdRequest : PlayFabRequestCommon
    {
        /// <summary>
        /// Whether to expand the referenced items
        /// </summary>
        public bool ExpandReferencedItems;
        /// <summary>
        /// The Marketplace offer Id of target bundle.
        /// </summary>
        public CatalogAlternateId MarketplaceOfferId;
        /// <summary>
        /// The title or namespace the item is in.
        /// </summary>
        public EntityKey SourceEntityKey;
    }

    /// <summary>
    /// Get bundle result
    /// </summary>
    [Serializable]
    public class GetBundleResult : PlayFabResultCommon
    {
        public CatalogItemMetadata Bundle;
        /// <summary>
        /// The Idempotency Id for this request
        /// </summary>
        public string IdempotencyId;
        public List<CatalogItemMetadata> ReferencedItems;
    }

    [Serializable]
    public class GetCatalogConfigRequest : PlayFabRequestCommon
    {
    }

    [Serializable]
    public class GetCatalogConfigResult : PlayFabResultCommon
    {
        public CatalogConfig Config;
    }

    [Serializable]
    public class GetCurrencyByIdRequest : PlayFabRequestCommon
    {
        /// <summary>
        /// ID of the currency to retrieve.
        /// </summary>
        public string CurrencyId;
        /// <summary>
        /// The entity to perform this action on.
        /// </summary>
        public EntityKey Entity;
    }

    [Serializable]
    public class GetCurrencyByIdResult : PlayFabResultCommon
    {
        /// <summary>
        /// Full metadata of the currency requested.
        /// </summary>
        public CatalogItemMetadata Currency;
    }

    [Serializable]
    public class GetDraftItemRequest : PlayFabRequestCommon
    {
        /// <summary>
        /// The entity to perform this action on.
        /// </summary>
        public EntityKey Entity;
        /// <summary>
        /// ID of the catalog item to retrieve from the working catalog.
        /// </summary>
        public string ItemId;
    }

    [Serializable]
    public class GetDraftItemResult : PlayFabResultCommon
    {
        /// <summary>
        /// Full metadata of the catalog item requested.
        /// </summary>
        public CatalogItemMetadata Item;
    }

    [Serializable]
    public class GetDraftItemsRequest : PlayFabRequestCommon
    {
        /// <summary>
        /// An opaque token used to retrieve the next page of items created by the caller, if any are available. Should be null on
        /// initial request.
        /// </summary>
        public string ContinuationToken;
        /// <summary>
        /// Number of items to retrieve. Maximum page size is 10.
        /// </summary>
        public int Count;
        /// <summary>
        /// The entity to perform this action on.
        /// </summary>
        public EntityKey Entity;
    }

    [Serializable]
    public class GetDraftItemsResult : PlayFabResultCommon
    {
        /// <summary>
        /// An opaque token used to retrieve the next page of items, if any are available.
        /// </summary>
        public string ContinuationToken;
        /// <summary>
        /// The total number of items created by the caller.
        /// </summary>
        public int Count;
        /// <summary>
        /// A set of items created by the caller.
        /// </summary>
        public List<CatalogItemMetadata> Items;
    }

    /// <summary>
    /// Given an entity type, entity identifier and container details, will get the entity's inventory items.
    /// </summary>
    [Serializable]
    public class GetInventoryItemsRequest : PlayFabRequestCommon
    {
        /// <summary>
        /// The entity to perform this action on.
        /// </summary>
        public EntityKey Entity;
        /// <summary>
        /// The Idempotency Id for this request
        /// </summary>
        public string IdempotencyId;
        /// <summary>
        /// Property bag for receipt generation
        /// </summary>
        public Dictionary<string,string> ReceiptData;
        /// <summary>
        /// Whether or not to generate a receipt
        /// </summary>
        public bool ShouldGenerateReceipt;
    }

    [Serializable]
    public class GetInventoryItemsResult : PlayFabResultCommon
    {
        /// <summary>
        /// The Idempotency Id for this request
        /// </summary>
        public string IdempotencyId;
        public List<InventoryItemResponseDto> Items;
        public string Receipt;
        public List<SubscriptionItemResponseDto> Subscriptions;
    }

    [Serializable]
    public class GetMyReviewRequest : PlayFabRequestCommon
    {
        /// <summary>
        /// The entity to perform this action on.
        /// </summary>
        public EntityKey Entity;
        /// <summary>
        /// The ID of the item to retrieve the user's review for.
        /// </summary>
        public string ItemId;
    }

    [Serializable]
    public class GetMyReviewResult : PlayFabResultCommon
    {
        /// <summary>
        /// The review the user submitted for the requested item.
        /// </summary>
        public Review Review;
    }

    [Serializable]
    public class GetPublishedItemRequest : PlayFabRequestCommon
    {
        /// <summary>
        /// The entity to perform this action on.
        /// </summary>
        public EntityKey Entity;
        /// <summary>
        /// ID of the catalog item to retrieve from the working catalog.
        /// </summary>
        public string ItemId;
    }

    [Serializable]
    public class GetPublishedItemResult : PlayFabResultCommon
    {
        /// <summary>
        /// Full metadata of the catalog item requested.
        /// </summary>
        public CatalogItemMetadata Item;
    }

    [Serializable]
    public class GetReviewsRequest : PlayFabRequestCommon
    {
        /// <summary>
        /// The entity to perform this action on.
        /// </summary>
        public EntityKey Entity;
        /// <summary>
        /// The ID of the item to retrieve reviews for.
        /// </summary>
        public string ItemId;
        /// <summary>
        /// An OData orderBy used to order the results of the query.
        /// </summary>
        public string OrderBy;
        /// <summary>
        /// The number of review results to skip. If not specified, defaults to 0.
        /// </summary>
        public int Skip;
        /// <summary>
        /// The number of review results to retrieve. If not specified, defaults to 10.
        /// </summary>
        public int Top;
    }

    [Serializable]
    public class GetReviewsResult : PlayFabResultCommon
    {
        /// <summary>
        /// An opaque token used to retrieve the next page of reviews, if any are available.
        /// </summary>
        public string ContinuationToken;
        /// <summary>
        /// The total number of reviews associated with this item.
        /// </summary>
        public int Count;
        /// <summary>
        /// The entity to perform this action on.
        /// </summary>
        public EntityKey Entity;
        /// <summary>
        /// The paginated set of results.
        /// </summary>
        public List<Review> Reviews;
    }

    /// <summary>
    /// Get store by friendly Id request
    /// </summary>
    [Serializable]
    public class GetStoreByFriendlyIdRequest : PlayFabRequestCommon
    {
        /// <summary>
        /// Whether to expand the referenced items
        /// </summary>
        public bool ExpandReferencedItems;
        /// <summary>
        /// The friendly Id of target store.
        /// </summary>
        public string FriendlyId;
        /// <summary>
        /// The title or namespace the item is in.
        /// </summary>
        public EntityKey SourceEntityKey;
    }

    /// <summary>
    /// Get store by Id request
    /// </summary>
    [Serializable]
    public class GetStoreByIdRequest : PlayFabRequestCommon
    {
        /// <summary>
        /// Whether to expand the referenced items
        /// </summary>
        public bool ExpandReferencedItems;
        /// <summary>
        /// Id of target store
        /// </summary>
        public string Id;
        /// <summary>
        /// The title or namespace the item is in.
        /// </summary>
        public EntityKey SourceEntityKey;
    }

    /// <summary>
    /// Get store result
    /// </summary>
    [Serializable]
    public class GetStoreResult : PlayFabResultCommon
    {
        /// <summary>
        /// The Idempotency Id for this request
        /// </summary>
        public string IdempotencyId;
        public List<CatalogItemMetadata> ReferencedItems;
        public CatalogItemMetadata Store;
    }

    /// <summary>
    /// Get subscription by friendly Id request
    /// </summary>
    [Serializable]
    public class GetSubscriptionByFriendlyIdRequest : PlayFabRequestCommon
    {
        /// <summary>
        /// Whether to expand the referenced items
        /// </summary>
        public bool ExpandReferencedItems;
        /// <summary>
        /// The friendly Id of target subscription.
        /// </summary>
        public string FriendlyId;
        /// <summary>
        /// The title or namespace the item is in.
        /// </summary>
        public EntityKey SourceEntityKey;
    }

    /// <summary>
    /// Get subscription by Id request
    /// </summary>
    [Serializable]
    public class GetSubscriptionByIdRequest : PlayFabRequestCommon
    {
        /// <summary>
        /// Whether to expand the referenced items
        /// </summary>
        public bool ExpandReferencedItems;
        /// <summary>
        /// Id of target subscription
        /// </summary>
        public string Id;
        /// <summary>
        /// The title or namespace the item is in.
        /// </summary>
        public EntityKey SourceEntityKey;
    }

    /// <summary>
    /// Get subscription by marketplace offer Id request
    /// </summary>
    [Serializable]
    public class GetSubscriptionByMarketplaceOfferIdRequest : PlayFabRequestCommon
    {
        /// <summary>
        /// Whether to expand the referenced items
        /// </summary>
        public bool ExpandReferencedItems;
        /// <summary>
        /// The Marketplace offer Id of target bundle.
        /// </summary>
        public CatalogAlternateId MarketplaceOfferId;
        /// <summary>
        /// The title or namespace the item is in.
        /// </summary>
        public EntityKey SourceEntityKey;
    }

    /// <summary>
    /// Get subscription result
    /// </summary>
    [Serializable]
    public class GetSubscriptionResult : PlayFabResultCommon
    {
        /// <summary>
        /// The Idempotency Id for this request
        /// </summary>
        public string IdempotencyId;
        public List<CatalogItemMetadata> ReferencedItems;
        public CatalogItemMetadata Subscription;
    }

    [Serializable]
    public class GetUgcItemModerationStateRequest : PlayFabRequestCommon
    {
        /// <summary>
        /// The entity to perform this action on.
        /// </summary>
        public EntityKey Entity;
        /// <summary>
        /// ID of the UGC item to get the moderation state for.
        /// </summary>
        public string ItemId;
    }

    [Serializable]
    public class GetUgcItemModerationStateResult : PlayFabResultCommon
    {
        /// <summary>
        /// The current moderation state for the requested item.
        /// </summary>
        public ModerationState State;
    }

    /// <summary>
    /// Given an entity type, entity identifier and container details, will get the entity's virtual currencies.
    /// </summary>
    [Serializable]
    public class GetVirtualCurrenciesRequest : PlayFabRequestCommon
    {
        /// <summary>
        /// The entity to perform this action on.
        /// </summary>
        public EntityKey Entity;
        /// <summary>
        /// The Idempotency Id for this request
        /// </summary>
        public string IdempotencyId;
    }

    [Serializable]
    public class GetVirtualCurrenciesResult : PlayFabResultCommon
    {
        public List<CurrencyResponseDto> Currencies;
        /// <summary>
        /// The Idempotency Id for this request
        /// </summary>
        public string IdempotencyId;
    }

    /// <summary>
    /// Given an entity type, entity identifier and container details, will grant the specified inventory items.
    /// </summary>
    [Serializable]
    public class GrantInventoryItemsRequest : PlayFabRequestCommon
    {
        /// <summary>
        /// The entity to perform this action on.
        /// </summary>
        public EntityKey Entity;
        /// <summary>
        /// The Idempotency Id for this request
        /// </summary>
        public string IdempotencyId;
        /// <summary>
        /// A list of Items to modify
        /// </summary>
        public List<InventoryItemDetails> Items;
    }

    [Serializable]
    public class GrantInventoryItemsResult : PlayFabResultCommon
    {
        /// <summary>
        /// The Idempotency Id for this request
        /// </summary>
        public string IdempotencyId;
        public List<InventoryItemResponseDto> Items;
    }

    [Serializable]
    public class HelpfulnessVoteRequest : PlayFabRequestCommon
    {
        /// <summary>
        /// The entity to perform this action on.
        /// </summary>
        public EntityKey Entity;
        public bool IsHelpful;
        /// <summary>
        /// The ID of the review to submit a helpfulness vote for.
        /// </summary>
        public string ReviewId;
    }

    [Serializable]
    public class HelpfulnessVoteResult : PlayFabResultCommon
    {
    }

    [Serializable]
    public class Image : PlayFabBaseModel
    {
        public string Id;
        /// <summary>
        /// The optional list of locales that are supported by this image.
        /// </summary>
        public List<string> Locales;
        /// <summary>
        /// The client-defined tag associated with this image.
        /// </summary>
        public string Tag;
        /// <summary>
        /// The client-defined type of this image.
        /// </summary>
        public string Type;
        /// <summary>
        /// The URL for retrieval of the image.
        /// </summary>
        public string Url;
    }

    [Serializable]
    public class InventoryItemDetails : PlayFabBaseModel
    {
        public CatalogAlternateId AlternateId;
        public string Duration;
        public DateTime? ExpirationDate;
        public string InstanceId;
        public bool IsSubscription;
        public string ItemId;
        public string Marketplace;
        public bool? MergeProperties;
        public string Origin;
        public string OriginId;
        public Dictionary<string,string> Properties;
        public int Quantity;
    }

    [Serializable]
    public class InventoryItemResponseDto : PlayFabBaseModel
    {
        public int Amount;
        public int? ChangedAmount;
        public string InstanceId;
        public string ItemId;
        public Dictionary<string,string> Properties;
        public string Receipt;
    }

    [Serializable]
    public class ModerationState : PlayFabBaseModel
    {
        /// <summary>
        /// The date and time this moderation state was last updated.
        /// </summary>
        public DateTime? LastModifiedDate;
        /// <summary>
        /// The current stated reason for the associated item being moderated.
        /// </summary>
        public string Reason;
        /// <summary>
        /// The current moderation status for the associated item.
        /// </summary>
        public ModerationStatus? Status;
    }

    public enum ModerationStatus
    {
        Unknown,
        AwaitingModeration,
        Approved,
        Rejected
    }

    [Serializable]
    public class PayoutInfo : PlayFabBaseModel
    {
        /// <summary>
        /// The Dev Center account ID of the payee.
        /// </summary>
        public string AccountSellerId;
        /// <summary>
        /// The tax code for payout calculations.
        /// </summary>
        public string TaxCode;
        /// <summary>
        /// The Universal account ID of the payee.
        /// </summary>
        public string Uaid;
    }

    /// <summary>
    /// The call kicks off a workflow to publish the item to the public catalog. The Publish Status API should be used to
    /// monitor the publish job.
    /// </summary>
    [Serializable]
    public class PublishItemRequest : PlayFabRequestCommon
    {
        /// <summary>
        /// The entity to perform this action on.
        /// </summary>
        public EntityKey Entity;
        /// <summary>
        /// ETag of the catalog item to published from the working catalog to the public catalog. Used for optimistic concurrency.
        /// If the provided ETag does not match the ETag in the current working catalog, the request will be reject. If not
        /// provided, the current version of the document in the working catalog will be published.
        /// </summary>
        public string ETag;
        /// <summary>
        /// ID of the catalog item to publish from the working catalog to the public catalog.
        /// </summary>
        public string ItemId;
    }

    [Serializable]
    public class PublishItemResult : PlayFabResultCommon
    {
    }

    public enum PublishResult
    {
        Unknown,
        Pending,
        Succeeded,
        Failed,
        Canceled
    }

    [Serializable]
    public class PublishStatusRequest : PlayFabRequestCommon
    {
        /// <summary>
        /// The entity to perform this action on.
        /// </summary>
        public EntityKey Entity;
        /// <summary>
        /// ID of the catalog item to publish from the working catalog to the public catalog.
        /// </summary>
        public string ItemId;
    }

    [Serializable]
    public class PublishStatusResult : PlayFabResultCommon
    {
        /// <summary>
        /// High level state of the publish.
        /// </summary>
        public PublishResult? Result;
        /// <summary>
        /// Descriptive message about the current status of the publish.
        /// </summary>
        public string StatusMessage;
    }

    /// <summary>
    /// Purchase item by friendly Id request
    /// </summary>
    [Serializable]
    public class PurchaseItemByFriendlyIdRequest : PlayFabRequestCommon
    {
        /// <summary>
        /// Sets a value indicating whether the purchased item should be automatically consumed. The specified item quantity will be
        /// both increased and decreased.
        /// </summary>
        public bool AutoConsume;
        /// <summary>
        /// The currencies used to pay for item.
        /// </summary>
        public List<PurchaseItemCurrency> Currencies;
        /// <summary>
        /// The entity to perform this action on.
        /// </summary>
        public EntityKey Entity;
        /// <summary>
        /// The Idempotency Id for this request
        /// </summary>
        public string IdempotencyId;
        /// <summary>
        /// Friendly identifier of the item to purchase.
        /// </summary>
        public string ItemFriendlyId;
        /// <summary>
        /// Additional properties to be associated with purchased item.
        /// </summary>
        public Dictionary<string,string> Properties;
        /// <summary>
        /// The quantity of the item to purchase.
        /// </summary>
        public int Quantity;
        /// <summary>
        /// Indicates if the full inventory should be returned.
        /// </summary>
        public bool ReturnInventory;
        /// <summary>
        /// The store to buy the item through.
        /// </summary>
        public PurchaseStoreInfo Store;
        /// <summary>
        /// The Universal account ID for the creator of the item.
        /// </summary>
        public string Uaid;
    }

    /// <summary>
    /// Purchase item by Id request
    /// </summary>
    [Serializable]
    public class PurchaseItemByIdRequest : PlayFabRequestCommon
    {
        /// <summary>
        /// Sets a value indicating whether the purchased item should be automatically consumed. The specified item quantity will be
        /// both increased and decreased.
        /// </summary>
        public bool AutoConsume;
        /// <summary>
        /// The currencies used to pay for item.
        /// </summary>
        public List<PurchaseItemCurrency> Currencies;
        /// <summary>
        /// The entity to perform this action on.
        /// </summary>
        public EntityKey Entity;
        /// <summary>
        /// The Idempotency Id for this request
        /// </summary>
        public string IdempotencyId;
        /// <summary>
        /// Unique identifier of the item to purchase.
        /// </summary>
        public string ItemId;
        /// <summary>
        /// Additional properties to be associated with purchased item.
        /// </summary>
        public Dictionary<string,string> Properties;
        /// <summary>
        /// The quantity of the item to purchase.
        /// </summary>
        public int Quantity;
        /// <summary>
        /// Indicates if the full inventory should be returned.
        /// </summary>
        public bool ReturnInventory;
        /// <summary>
        /// The store to buy the item through.
        /// </summary>
        public PurchaseStoreInfo Store;
        /// <summary>
        /// The Universal account ID for the creator of the item.
        /// </summary>
        public string Uaid;
    }

    [Serializable]
    public class PurchaseItemCurrency : PlayFabBaseModel
    {
        /// <summary>
        /// The unique identifier of the currency.
        /// </summary>
        public string CurrencyId;
        /// <summary>
        /// Price the client expects to pay for the item.
        /// </summary>
        public int ExpectedPrice;
    }

    /// <summary>
    /// Purchase item result
    /// </summary>
    [Serializable]
    public class PurchaseItemResult : PlayFabResultCommon
    {
        /// <summary>
        /// Details of the currencies used to purchase the items.
        /// </summary>
        public List<PurchaseItemResultCurrency> Currencies;
        /// <summary>
        /// The Idempotency Id for this request
        /// </summary>
        public string IdempotencyId;
        /// <summary>
        /// Details of the current inventory items.
        /// </summary>
        public List<PurchaseItemResultItem> InventoryItems;
        /// <summary>
        /// Indicates whether the number of inventory items is too large to be returned.
        /// </summary>
        public bool InventoryTooLarge;
        /// <summary>
        /// Details for the items purchased.
        /// </summary>
        public List<PurchaseItemResultItem> PurchasedItems;
    }

    [Serializable]
    public class PurchaseItemResultCurrency : PlayFabBaseModel
    {
        /// <summary>
        /// The total amount of the currency on inventory.
        /// </summary>
        public int Amount;
        /// <summary>
        /// The amount of the currency used in this call.
        /// </summary>
        public int ChangedAmount;
        /// <summary>
        /// The ID of the currency used in this purchase.
        /// </summary>
        public string CurrencyId;
    }

    [Serializable]
    public class PurchaseItemResultItem : PlayFabBaseModel
    {
        /// <summary>
        /// The total amount of the item on inventory.
        /// </summary>
        public int Amount;
        /// <summary>
        /// The amount of the item purchased in this call.
        /// </summary>
        public int? ChangedAmount;
        /// <summary>
        /// Friendly id of the item.
        /// </summary>
        public string FriendlyId;
        /// <summary>
        /// Unique item identifier for this specific instance of the item.
        /// </summary>
        public string InstanceId;
        /// <summary>
        /// Unique identifier of the item.
        /// </summary>
        public string ItemId;
        /// <summary>
        /// The type of item.
        /// </summary>
        public string ItemType;
        /// <summary>
        /// The properties associated to the currency.
        /// </summary>
        public Dictionary<string,string> Properties;
    }

    [Serializable]
    public class PurchaseStoreInfo : PlayFabBaseModel
    {
        /// <summary>
        /// The friendly identifier of the store.
        /// </summary>
        public string FriendlyId;
        /// <summary>
        /// The unique identifier of the store.
        /// </summary>
        public string Id;
    }

    [Serializable]
    public class Rating : PlayFabBaseModel
    {
        /// <summary>
        /// The average rating for this item
        /// </summary>
        public float? Average;
        /// <summary>
        /// The total count of 1 star ratings for this item
        /// </summary>
        public int? Count1Star;
        /// <summary>
        /// The total count of 2 star ratings for this item
        /// </summary>
        public int? Count2Star;
        /// <summary>
        /// The total count of 3 star ratings for this item
        /// </summary>
        public int? Count3Star;
        /// <summary>
        /// The total count of 4 star ratings for this item
        /// </summary>
        public int? Count4Star;
        /// <summary>
        /// The total count of 5 star ratings for this item
        /// </summary>
        public int? Count5Star;
        /// <summary>
        /// The total count of ratings for this item
        /// </summary>
        public int? TotalCount;
    }

    [Serializable]
    public class ReportItemRequest : PlayFabRequestCommon
    {
        /// <summary>
        /// Category of concern for this report.
        /// </summary>
        public ConcernCategory? Concern;
        /// <summary>
        /// The entity to perform this action on.
        /// </summary>
        public EntityKey Entity;
        /// <summary>
        /// ID of the item to report.
        /// </summary>
        public string ItemId;
        /// <summary>
        /// The string reason for this report.
        /// </summary>
        public string Reason;
    }

    [Serializable]
    public class ReportItemResult : PlayFabResultCommon
    {
    }

    /// <summary>
    /// Submit a report for an inappropriate review, allowing the submitting user to specify their concern.
    /// </summary>
    [Serializable]
    public class ReportReviewRequest : PlayFabRequestCommon
    {
        /// <summary>
        /// The reason this review is being reported.
        /// </summary>
        public ConcernCategory? ConcernCategory;
        /// <summary>
        /// The entity to perform this action on.
        /// </summary>
        public EntityKey Entity;
        /// <summary>
        /// The ID of the review to submit a report for.
        /// </summary>
        public string ReviewId;
    }

    [Serializable]
    public class ReportReviewResult : PlayFabResultCommon
    {
    }

    [Serializable]
    public class Review : PlayFabBaseModel
    {
        /// <summary>
        /// The number of negative helpfulness votes for this review.
        /// </summary>
        public int HelpfulNegative;
        /// <summary>
        /// Total number of helpfulness votes for this review.
        /// </summary>
        public int HelpfulnessVotes;
        /// <summary>
        /// The number of positive helpfulness votes for this review.
        /// </summary>
        public int HelpfulPositive;
        /// <summary>
        /// Indicates whether the review author has the item installed.
        /// </summary>
        public bool IsInstalled;
        /// <summary>
        /// The ID of the item being reviewed.
        /// </summary>
        public string ItemId;
        /// <summary>
        /// The version of the item being reviewed.
        /// </summary>
        public string ItemVersion;
        /// <summary>
        /// The locale for which this review was submitted in.
        /// </summary>
        public string Locale;
        /// <summary>
        /// Star rating associated with this review.
        /// </summary>
        public int Rating;
        /// <summary>
        /// The ID of the author of the review.
        /// </summary>
        public string ReviewerId;
        /// <summary>
        /// The ID of the review.
        /// </summary>
        public string ReviewId;
        /// <summary>
        /// The full text of this review.
        /// </summary>
        public string ReviewText;
        /// <summary>
        /// The date and time this review was last submitted.
        /// </summary>
        public DateTime Submitted;
        /// <summary>
        /// The title of this review.
        /// </summary>
        public string Title;
    }

    [Serializable]
    public class ReviewSubmission : PlayFabBaseModel
    {
        /// <summary>
        /// Indicates whether the review author has the item installed.
        /// </summary>
        public bool IsInstalled;
        /// <summary>
        /// The version of the item being reviewed.
        /// </summary>
        public string ItemVersion;
        /// <summary>
        /// Star rating associated with this review.
        /// </summary>
        public int Rating;
        /// <summary>
        /// The full text of this review.
        /// </summary>
        public string ReviewText;
        /// <summary>
        /// The title of this review.
        /// </summary>
        public string Title;
    }

    [Serializable]
    public class ReviewSummaryRequest : PlayFabRequestCommon
    {
        /// <summary>
        /// The entity to perform this action on.
        /// </summary>
        public EntityKey Entity;
        /// <summary>
        /// The ID of the item to retrieve the reviews summary for.
        /// </summary>
        public string ItemId;
    }

    [Serializable]
    public class ReviewSummaryResult : PlayFabResultCommon
    {
        public Review LeastFavorableReview;
        public Review MostFavorableReview;
        /// <summary>
        /// The summary of ratings associated with this item.
        /// </summary>
        public Rating Rating;
        /// <summary>
        /// The total number of reviews associated with this item.
        /// </summary>
        public int ReviewsCount;
    }

    [Serializable]
    public class ReviewTakedown : PlayFabBaseModel
    {
        /// <summary>
        /// The ID of the item associated with the review to take down.
        /// </summary>
        public string ItemId;
        /// <summary>
        /// The ID of the review to take down.
        /// </summary>
        public string ReviewId;
    }

    /// <summary>
    /// Search for bundles request
    /// </summary>
    [Serializable]
    public class SearchBundlesRequest : PlayFabRequestCommon
    {
        /// <summary>
        /// Whether the referenced items should be expanded.
        /// </summary>
        public bool ExpandReferencedItems;
        /// <summary>
        /// An OData filter used to refine the search query.
        /// </summary>
        public string Filter;
        /// <summary>
        /// The Idempotency Id for this request
        /// </summary>
        public string IdempotencyId;
        /// <summary>
        /// An OData orderBy used to order the results of the search query.
        /// </summary>
        public string OrderBy;
        /// <summary>
        /// The text to search for
        /// </summary>
        public string Search;
        /// <summary>
        /// The number of search results to skip.
        /// </summary>
        public int Skip;
        /// <summary>
        /// The title or namespace to search under.
        /// </summary>
        public EntityKey SourceEntityKey;
        /// <summary>
        /// The number of search results to retrieve.
        /// </summary>
        public int Top;
    }

    /// <summary>
    /// Search for bundles result
    /// </summary>
    [Serializable]
    public class SearchBundlesResult : PlayFabResultCommon
    {
        public List<GetBundleResult> Bundles;
        /// <summary>
        /// The Idempotency Id for this request
        /// </summary>
        public string IdempotencyId;
    }

    /// <summary>
    /// Search for bundles/subscriptions/stores containing any item from a list of items. The items are referenced by Friendly
    /// Ids.
    /// </summary>
    [Serializable]
    public class SearchForItemsContainingItemByFriendlyIdRequest : PlayFabRequestCommon
    {
        /// <summary>
        /// Do we want to restrict the Search to Bundles/Subscriptions/Stores?
        /// </summary>
        public ContainerType? ContainerType;
        /// <summary>
        /// FriendlyIds of the items
        /// </summary>
        public List<string> FriendlyIds;
        /// <summary>
        /// The Idempotency Id for this request
        /// </summary>
        public string IdempotencyId;
        /// <summary>
        /// The title or namespace to search under.
        /// </summary>
        public EntityKey SourceEntityKey;
    }

    /// <summary>
    /// Search for bundles/subscriptions/stores containing any item from a list of items. The items are referenced by Ids.
    /// </summary>
    [Serializable]
    public class SearchForItemsContainingItemByIdRequest : PlayFabRequestCommon
    {
        /// <summary>
        /// Do we want to restrict the Search to Bundles/Subscriptions/Stores?
        /// </summary>
        public ContainerType? ContainerType;
        /// <summary>
        /// The Idempotency Id for this request
        /// </summary>
        public string IdempotencyId;
        /// <summary>
        /// Ids of the items
        /// </summary>
        public List<string> Ids;
        /// <summary>
        /// The title or namespace to search under.
        /// </summary>
        public EntityKey SourceEntityKey;
    }

    /// <summary>
    /// Search for items containing an item result
    /// </summary>
    [Serializable]
    public class SearchForItemsContainingItemResult : PlayFabResultCommon
    {
        /// <summary>
        /// List of Bundles containing the item.
        /// </summary>
        public List<CatalogItemMetadata> Bundles;
        /// <summary>
        /// The Idempotency Id for this request
        /// </summary>
        public string IdempotencyId;
        /// <summary>
        /// List of Stores containing the item.
        /// </summary>
        public List<CatalogItemMetadata> Stores;
        /// <summary>
        /// List of Subscriptions containing the item.
        /// </summary>
        public List<CatalogItemMetadata> Subscriptions;
    }

    /// <summary>
    /// Search for items within a store request. The store is referenced by Friendly Id.
    /// </summary>
    [Serializable]
    public class SearchInStoreByFriendlyIdRequest : PlayFabRequestCommon
    {
        /// <summary>
        /// An OData filter used to refine the search query.
        /// </summary>
        public string Filter;
        /// <summary>
        /// FriendlyId of target store
        /// </summary>
        public string FriendlyId;
        /// <summary>
        /// The Idempotency Id for this request
        /// </summary>
        public string IdempotencyId;
        /// <summary>
        /// An OData orderBy used to order the results of the search query.
        /// </summary>
        public string OrderBy;
        /// <summary>
        /// The text to search for
        /// </summary>
        public string Search;
        /// <summary>
        /// The number of search results to skip.
        /// </summary>
        public int Skip;
        /// <summary>
        /// The title or namespace to search under.
        /// </summary>
        public EntityKey SourceEntityKey;
        /// <summary>
        /// The number of search results to retrieve.
        /// </summary>
        public int Top;
    }

    /// <summary>
    /// Search for items within a store request. The store is referenced by Id.
    /// </summary>
    [Serializable]
    public class SearchInStoreByIdRequest : PlayFabRequestCommon
    {
        /// <summary>
        /// An OData filter used to refine the search query.
        /// </summary>
        public string Filter;
        /// <summary>
        /// Id of target store
        /// </summary>
        public string Id;
        /// <summary>
        /// The Idempotency Id for this request
        /// </summary>
        public string IdempotencyId;
        /// <summary>
        /// An OData orderBy used to order the results of the search query.
        /// </summary>
        public string OrderBy;
        /// <summary>
        /// The text to search for
        /// </summary>
        public string Search;
        /// <summary>
        /// The number of search results to skip.
        /// </summary>
        public int Skip;
        /// <summary>
        /// The title or namespace to search under.
        /// </summary>
        public EntityKey SourceEntityKey;
        /// <summary>
        /// The number of search results to retrieve.
        /// </summary>
        public int Top;
    }

    /// <summary>
    /// Search within a store result
    /// </summary>
    [Serializable]
    public class SearchInStoreResult : PlayFabResultCommon
    {
        /// <summary>
        /// The Idempotency Id for this request
        /// </summary>
        public string IdempotencyId;
        /// <summary>
        /// List of Items within the Store that satisfy the search condition.
        /// </summary>
        public List<CatalogItemMetadata> Items;
    }

    /// <summary>
    /// Search for stores request
    /// </summary>
    [Serializable]
    public class SearchStoresRequest : PlayFabRequestCommon
    {
        /// <summary>
        /// Whether the referenced items should be expanded.
        /// </summary>
        public bool ExpandReferencedItems;
        /// <summary>
        /// An OData filter used to refine the search query.
        /// </summary>
        public string Filter;
        /// <summary>
        /// The Idempotency Id for this request
        /// </summary>
        public string IdempotencyId;
        /// <summary>
        /// An OData orderBy used to order the results of the search query.
        /// </summary>
        public string OrderBy;
        /// <summary>
        /// The text to search for
        /// </summary>
        public string Search;
        /// <summary>
        /// The number of search results to skip.
        /// </summary>
        public int Skip;
        /// <summary>
        /// The title or namespace to search under.
        /// </summary>
        public EntityKey SourceEntityKey;
        /// <summary>
        /// The number of search results to retrieve.
        /// </summary>
        public int Top;
    }

    /// <summary>
    /// Search for stores result
    /// </summary>
    [Serializable]
    public class SearchStoresResult : PlayFabResultCommon
    {
        /// <summary>
        /// The Idempotency Id for this request
        /// </summary>
        public string IdempotencyId;
        public List<GetStoreResult> Stores;
    }

    /// <summary>
    /// Search for subscriptions request
    /// </summary>
    [Serializable]
    public class SearchSubscriptionsRequest : PlayFabRequestCommon
    {
        /// <summary>
        /// Whether the referenced items should be expanded.
        /// </summary>
        public bool ExpandReferencedItems;
        /// <summary>
        /// An OData filter used to refine the search query.
        /// </summary>
        public string Filter;
        /// <summary>
        /// The Idempotency Id for this request
        /// </summary>
        public string IdempotencyId;
        /// <summary>
        /// An OData orderBy used to order the results of the search query.
        /// </summary>
        public string OrderBy;
        /// <summary>
        /// The text to search for
        /// </summary>
        public string Search;
        /// <summary>
        /// The number of search results to skip.
        /// </summary>
        public int Skip;
        /// <summary>
        /// The title or namespace to search under.
        /// </summary>
        public EntityKey SourceEntityKey;
        /// <summary>
        /// The number of search results to retrieve.
        /// </summary>
        public int Top;
    }

    /// <summary>
    /// Search for subscriptions result
    /// </summary>
    [Serializable]
    public class SearchSubscriptionsResult : PlayFabResultCommon
    {
        /// <summary>
        /// The Idempotency Id for this request
        /// </summary>
        public string IdempotencyId;
        public List<GetSubscriptionResult> Subscriptions;
    }

    /// <summary>
    /// Given an entity type, entity identifier and container details, will set the entity's inventory items
    /// </summary>
    [Serializable]
    public class SetInventoryItemsRequest : PlayFabRequestCommon
    {
        /// <summary>
        /// The entity to perform this action on.
        /// </summary>
        public EntityKey Entity;
        /// <summary>
        /// The Idempotency Id for this request
        /// </summary>
        public string IdempotencyId;
        /// <summary>
        /// A list of Items to modify
        /// </summary>
        public List<InventoryItemDetails> Items;
    }

    [Serializable]
    public class SetInventoryItemsResult : PlayFabResultCommon
    {
        /// <summary>
        /// The Idempotency Id for this request
        /// </summary>
        public string IdempotencyId;
        public List<InventoryItemResponseDto> Items;
    }

    [Serializable]
    public class SetUgcItemModerationStateRequest : PlayFabRequestCommon
    {
        /// <summary>
        /// The entity to perform this action on.
        /// </summary>
        public EntityKey Entity;
        /// <summary>
        /// ID of the UGC item to set the moderation state for.
        /// </summary>
        public string ItemId;
        /// <summary>
        /// The reason for the moderation state change for the associated UGC item.
        /// </summary>
        public string Reason;
        /// <summary>
        /// The status to set for the associated UGC item.
        /// </summary>
        public ModerationStatus? Status;
    }

    [Serializable]
    public class SetUgcItemModerationStateResult : PlayFabResultCommon
    {
    }

    /// <summary>
    /// Given an entity type, entity identifier and container details, will set the entity's currencies to a specific amount.
    /// </summary>
    [Serializable]
    public class SetVirtualCurrenciesRequest : PlayFabRequestCommon
    {
        /// <summary>
        /// A list of currencies to modify
        /// </summary>
        public List<CurrencyDetails> Currencies;
        /// <summary>
        /// The entity to perform this action on.
        /// </summary>
        public EntityKey Entity;
        /// <summary>
        /// The Idempotency Id for this request
        /// </summary>
        public string IdempotencyId;
    }

    [Serializable]
    public class SetVirtualCurrenciesResult : PlayFabResultCommon
    {
        public List<CurrencyResponseDto> Currencies;
        /// <summary>
        /// The Idempotency Id for this request
        /// </summary>
        public string IdempotencyId;
    }

    [Serializable]
    public class SubscriptionDetails : PlayFabBaseModel
    {
        /// <summary>
        /// The length of time that the subscription will last.
        /// </summary>
        public double DurationInSeconds;
    }

    [Serializable]
    public class SubscriptionItemResponseDto : PlayFabBaseModel
    {
        public DateTime? ExpirationDate;
        public List<string> ItemIds;
        public string Marketplace;
        public string OfferId;
        public string Receipt;
    }

    /// <summary>
    /// Given an entity type, entity identifier and container details, will decrease the entity's currencies by a specific
    /// amount.
    /// </summary>
    [Serializable]
    public class SubtractVirtualCurrenciesRequest : PlayFabRequestCommon
    {
        /// <summary>
        /// A list of currencies to modify
        /// </summary>
        public List<CurrencyDetails> Currencies;
        /// <summary>
        /// The entity to perform this action on.
        /// </summary>
        public EntityKey Entity;
        /// <summary>
        /// The Idempotency Id for this request
        /// </summary>
        public string IdempotencyId;
    }

    [Serializable]
    public class SubtractVirtualCurrenciesResult : PlayFabResultCommon
    {
        public List<CurrencyResponseDto> Currencies;
        /// <summary>
        /// The Idempotency Id for this request
        /// </summary>
        public string IdempotencyId;
    }

    /// <summary>
    /// Submit a request to takedown one or more reviews, removing them from public view. Authors will still be able to see
    /// their reviews after being taken down.
    /// </summary>
    [Serializable]
    public class TakedownReviewsRequest : PlayFabRequestCommon
    {
        /// <summary>
        /// The entity to perform this action on.
        /// </summary>
        public EntityKey Entity;
        /// <summary>
        /// The set of reviews to take down.
        /// </summary>
        public List<ReviewTakedown> Reviews;
    }

    [Serializable]
    public class TakedownReviewsResult : PlayFabResultCommon
    {
    }

    /// <summary>
    /// Update bundle request
    /// </summary>
    [Serializable]
    public class UpdateBundleRequest : PlayFabRequestCommon
    {
        /// <summary>
        /// Bundle details
        /// </summary>
        public CatalogItemMetadata Bundle;
        /// <summary>
        /// The Idempotency Id for this request
        /// </summary>
        public string IdempotencyId;
    }

    /// <summary>
    /// Update bundle result
    /// </summary>
    [Serializable]
    public class UpdateBundleResult : PlayFabResultCommon
    {
        public CatalogItemMetadata Bundle;
        /// <summary>
        /// The Idempotency Id for this request
        /// </summary>
        public string IdempotencyId;
    }

    [Serializable]
    public class UpdateCatalogConfigRequest : PlayFabRequestCommon
    {
        public CatalogConfig Config;
        /// <summary>
        /// The entity to perform this action on.
        /// </summary>
        public EntityKey Entity;
    }

    [Serializable]
    public class UpdateCatalogConfigResult : PlayFabResultCommon
    {
    }

    [Serializable]
    public class UpdateCurrencyRequest : PlayFabRequestCommon
    {
        /// <summary>
        /// Updated metadata describing the currency item to be updated.
        /// </summary>
        public CatalogItemMetadata Currency;
        /// <summary>
        /// The entity to perform this action on.
        /// </summary>
        public EntityKey Entity;
    }

    [Serializable]
    public class UpdateCurrencyResult : PlayFabResultCommon
    {
        /// <summary>
        /// Updated metadata describing the currency item just updated.
        /// </summary>
        public CatalogItemMetadata Currency;
        /// <summary>
        /// The entity to perform this action on.
        /// </summary>
        public EntityKey Entity;
    }

    [Serializable]
    public class UpdateDraftItemRequest : PlayFabRequestCommon
    {
        /// <summary>
        /// The entity to perform this action on.
        /// </summary>
        public EntityKey Entity;
        /// <summary>
        /// Updated metadata describing the catalog item to be updated.
        /// </summary>
        public CatalogItemMetadata Item;
    }

    [Serializable]
    public class UpdateDraftItemResult : PlayFabResultCommon
    {
        /// <summary>
        /// Updated metadata describing the catalog item just updated.
        /// </summary>
        public CatalogItemMetadata Item;
    }

    /// <summary>
    /// Update the specified inventory items.
    /// </summary>
    [Serializable]
    public class UpdateInventoryItemsPropertiesRequest : PlayFabRequestCommon
    {
        /// <summary>
        /// The entity to perform this action on.
        /// </summary>
        public EntityKey Entity;
        /// <summary>
        /// The Idempotency Id for this request
        /// </summary>
        public string IdempotencyId;
        /// <summary>
        /// A list of Items to modify
        /// </summary>
        public List<InventoryItemDetails> Items;
    }

    [Serializable]
    public class UpdateInventoryPropertiesItemsResult : PlayFabResultCommon
    {
        /// <summary>
        /// The Idempotency Id for this request
        /// </summary>
        public string IdempotencyId;
        public List<InventoryItemResponseDto> Items;
        public List<SubscriptionItemResponseDto> Subscriptions;
    }

    /// <summary>
    /// Update store request
    /// </summary>
    [Serializable]
    public class UpdateStoreRequest : PlayFabRequestCommon
    {
        /// <summary>
        /// The entity to perform this action on.
        /// </summary>
        public EntityKey Entity;
        /// <summary>
        /// The Idempotency Id for this request
        /// </summary>
        public string IdempotencyId;
        /// <summary>
        /// Bundle details
        /// </summary>
        public CatalogItemMetadata Store;
    }

    /// <summary>
    /// Update store result
    /// </summary>
    [Serializable]
    public class UpdateStoreResult : PlayFabResultCommon
    {
        /// <summary>
        /// The Idempotency Id for this request
        /// </summary>
        public string IdempotencyId;
        public CatalogItemMetadata Store;
    }

    /// <summary>
    /// Update subscription request
    /// </summary>
    [Serializable]
    public class UpdateSubscriptionRequest : PlayFabRequestCommon
    {
        /// <summary>
        /// The Idempotency Id for this request
        /// </summary>
        public string IdempotencyId;
        /// <summary>
        /// subscription details
        /// </summary>
        public CatalogItemMetadata Subscription;
    }

    /// <summary>
    /// Update subscription result
    /// </summary>
    [Serializable]
    public class UpdateSubscriptionResult : PlayFabResultCommon
    {
        /// <summary>
        /// The Idempotency Id for this request
        /// </summary>
        public string IdempotencyId;
        public CatalogItemMetadata Subscription;
    }

    [Serializable]
    public class UploadInfo : PlayFabBaseModel
    {
        /// <summary>
        /// Name of the file to be uploaded.
        /// </summary>
        public string FileName;
        /// <summary>
        /// Size of the file to be uploaded, in bytes.
        /// </summary>
        public int FileSize;
    }

    [Serializable]
    public class UploadUrlMetadata : PlayFabBaseModel
    {
        /// <summary>
        /// Name of the file for which this upload url was requested.
        /// </summary>
        public string FileName;
        /// <summary>
        /// Unique identifier for the binary content to be uploaded to the target url.
        /// </summary>
        public string Id;
        /// <summary>
        /// Url for the binary content to be uploaded to.
        /// </summary>
        public string Url;
    }

    [Serializable]
    public class UserGeneratedContentSpecificConfig : PlayFabBaseModel
    {
        /// <summary>
        /// The set of content types that will be used for validation and if no values are provided then anything is allowed.
        /// </summary>
        public List<string> ContentTypes;
        /// <summary>
        /// Flag defining whether user generated content is enabled.
        /// </summary>
        public bool Enabled;
        /// <summary>
        /// The set of tags that will be used for validation and if no values are provided then anything is allowed.
        /// </summary>
        public List<string> Tags;
    }
}
#endif
