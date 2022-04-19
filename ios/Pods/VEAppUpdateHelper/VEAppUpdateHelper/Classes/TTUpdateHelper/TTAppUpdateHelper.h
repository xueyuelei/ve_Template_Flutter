//
//  TTUpdateHelper.h
//  TTAppUpdateHelper
//
//  Created by Sunhaiyuan on 2018/3/27.
//  Copyright © 2018 Bytedance. All rights reserved.

#import <Foundation/Foundation.h>
#import "TTCheckVersionResponse.h"

typedef void(^TTAppUpdateHandleBlock)(void);

/** TTAppUpdateHelperProtocol
 * 弹窗升级协议
 * 如果需要自定义弹窗需要实现此协议来获取数据的回调
 */
@protocol TTAppUpdateHelperProtocol <NSObject>

@required
/**
 @param model 弹窗显示Model
 @param error 错误信息
 */
- (void)showUpdateViewWithModel:(TTAppUpdateModel *)model error:(NSError *)error;

/**
 告诉代理需要关闭弹窗,代理对象应该只在该方法中关闭弹窗
 */
- (void)dismissTipView;

@optional

//弹窗不展示回调，包括各种异常情况，配置的不展示弹窗由newVersionHitButUpdateViewShouldNotShow回调
- (void)updateViewShouldNotShow;

//新版本命中，但是配置了不展示弹窗
- (void)newVersionHitButUpdateViewShouldNotShow;
 
/*
自己处理下载链接
 */
- (void)openWithDownloadUrl:(NSString *)downloadUrl;


@end

@interface TTAppUpdateHelper : NSObject

/**
* 初始化 TTAppUpdateHelper
@param did  device_id 设备id
@param aid 应用id 如: 1112
@param delegate 代理对象
*/
- (instancetype)initWithDeviceID:(NSString *)did
                             aid:(NSString *)aid
                        delegate:(id <TTAppUpdateHelperProtocol>)delegate;

@property (nonatomic, copy) TTAppUpdateHandleBlock updateBlock; //升级按钮点击处理Block,必须调用
@property (nonatomic, copy) TTAppUpdateHandleBlock closeBlock;  //关闭按钮点击处理Block，必须调用

@property (nonatomic, copy) NSNumber *callType;  //是否开启频控  0不进行频控  1进行频控  默认1

@property (nonatomic, assign) NSInteger popupTimeInterval;//不进行频控不更新值
@property (nonatomic, assign) NSInteger maxPopTimesWithinInterval;

@property (nonatomic, copy) NSString *city; //用于TF精准放量，格式为<省市>直辖市表示省

//客户自定义数据
@property (nonatomic, copy) NSDictionary *customData;//用户自己需要上传的数据，接口请求时会把里面的key:value一起带上
/**
 * 开始检查更新
 */
- (void)startCheckVersion;

/// 五位版本号，带 `.`，比如 `7.4.4.00`
/// 直接读取 Bunlde 文件
+ (NSString *)longBuildVersionStr;

/// 三位版本号，带 `.`，比如 `7.4.4`
/// 直接读取 Bunlde 文件
+ (NSString *)versionString;

/// 转换五位版本号，不带 `.`，比如 `74400`
/// 位数不足，不会自动补齐！！！
+ (NSInteger)versionStringToInteger:(NSString *)versionString;

/// 是否安装了 TestFlight，需要在主线程调用
+ (BOOL)hasInstallTestFlightApp;

@end
