//
//  MLIAPManager.h
//  MLIAPurchaseManager
//
//  Created by mali on 16/5/14.
//  Copyright © 2016年 mali. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <StoreKit/StoreKit.h>

@protocol MLIAPManagerDelegate <NSObject>

@optional

- (void)receiveProduct:(SKProduct *)product;

- (void)successedWithReceipt:(NSData *)transactionReceipt;

- (void)failedPurchaseWithError:(NSString *)errorDescripiton;


@end


@interface MLIAPManager : NSObject

@property (nonatomic, assign)id<MLIAPManagerDelegate> delegate;


+ (instancetype)sharedManager;

- (BOOL)requestProductWithId:(NSString *)productId;
- (BOOL)purchaseProduct:(SKProduct *)skProduct;
- (BOOL)restorePurchase;
- (void)refreshReceipt;
- (void)finishTransaction;

@end




