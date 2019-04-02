#import <StoreKit/StoreKit.h>

// Callback to Unity identifying the subject, JSON message body and optional app receipt.
// Note that App Receipts are sent separately to the JSON body for performance reasons.
typedef void (*UnityPurchasingCallback)(const char* subject, const char* payload, const char* receipt, const char* transactionId);

@interface ProductDefinition : NSObject

@property (nonatomic, strong) NSString *id;
@property (nonatomic, strong) NSString *storeSpecificId;
@property (nonatomic, strong) NSString *type;

@end


@interface ReceiptRefresher : NSObject <SKRequestDelegate>

@property (nonatomic, strong) void (^callback)(BOOL);

@end


@interface UnityPurchasing : NSObject <SKProductsRequestDelegate, SKPaymentTransactionObserver> {
    UnityPurchasingCallback messageCallback;
    NSMutableDictionary* validProducts;
    NSSet* productIds;
    SKProductsRequest *request;
    NSMutableDictionary *pendingTransactions;
    NSMutableSet *finishedTransactions;
    // Dictionary that maps product IDs to the most recent transaction receipt (base 64 encoded).
    NSMutableDictionary<NSString *, NSString *> *transactionReceipts;
}

+ (NSArray*) deserializeProductDefs:(NSString*)json;
+ (ProductDefinition*) deserializeProductDef:(NSString*)json;
+ (NSString*) serializeProductMetadata:(NSArray*)products;

-(void) restorePurchases;
-(NSString*) getAppReceipt;
-(NSString*) getTransactionReceiptForProductId:(NSString *)productId;
-(void) addTransactionObserver;
@property (nonatomic, strong) ReceiptRefresher* receiptRefresher;
@property (nonatomic, strong) SKReceiptRefreshRequest* refreshRequest;
@property BOOL simulateAskToBuyEnabled;
@property (nonatomic, copy, readwrite) NSString* applicationUsername;
@property (nonatomic) BOOL interceptPromotionalPurchases;

@end

