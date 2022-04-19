//
//  OneKitApp.h
//  OneKit
//
//  Created by bob on 2021/1/13.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

FOUNDATION_EXTERN NSString *kOKInfoFileResourceName;
FOUNDATION_EXTERN NSString *kOKInfoKeyAppID;

@interface OneKitApp : NSObject


/// 启动OneKit框架。应该在启动时尽早调用。
/// @param application 应用回调的代理。将各 SDK 所需回调集中后传入
/// @param launchOptions 应用启动选项。直接透传`application: didFinishLaunchingWithOptions:`的LaunchOptions参数。
+ (void)startApplication:(nullable id) application withLaunchOptions:(nullable NSDictionary<UIApplicationLaunchOptionsKey, id> *)launchOptions __deprecated_msg("此方法已过期。请使用`startWithithLaunchOptions:`。");

/// 相当于`startApplication:nil withLaunchOptions:launchOptionsl`。已过期，请勿再使用，后续版本将下掉此接口。
+ (void)startWithLaunchOptions:(nullable NSDictionary<UIApplicationLaunchOptionsKey, id> *)launchOptions;

/// 相当于`startWithLaunchOptions:nil`。已过期，请勿再使用，后续版本将下掉此接口。
+ (void)start __deprecated_msg("此方法已过期。请使用`startApplication:withithLaunchOptions:`。");

@end

NS_ASSUME_NONNULL_END
