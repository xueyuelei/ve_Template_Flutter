//
//  TTAppUpdateDefaltDelegate.h
//  TTAppUpdateHelper
//
//  Created by 谭培 on 2019/9/26.
//

#import <Foundation/Foundation.h>
#import "TTAppUpdateTipView.h"

NS_ASSUME_NONNULL_BEGIN

@protocol TTAppUpdateDelegate <NSObject>

@required

/*
在此实现跳转弹窗的逻辑，根据[model.enable_popup boolValue]来决定是否开启弹窗
*/
- (void)updateViewShouldShow:(TTAppUpdateTipView *)tipView model:(TTAppUpdateModel *)model;

/**
 在此实现关闭弹窗的逻辑
 */
- (void)updateViewShouldClosed:(TTAppUpdateTipView *)tipView;

@optional

//新版本命中，但是配置了不展示弹窗
- (void)newVersionHitButUpdateViewShouldNotShow;

//弹窗不展示回调
- (void)updateViewShouldNotShow;

/*
 自己处理下载链接
*/
- (void)openWithDownloadUrl:(NSString *)downloadUrl;


@end

@interface TTAppUpdateHelperDefault : NSObject

@property (nonatomic, weak) id <TTAppUpdateDelegate> delegate;

@property (nonatomic, copy) NSNumber *callType;  //调用的类型  0表示用户主动调用，不进行频控，如用户点击检查版本  1表示被动调用，会进行频控，如冷启动  默认是1

@property (nonatomic, assign) NSInteger popupTimeInterval;//不进行频控不更新值
@property (nonatomic, assign) NSInteger maxPopTimesWithinInterval;

@property (nonatomic, copy) NSString *city;
 
//客户自定义数据
@property (nonatomic, copy) NSDictionary *customData;//用户自己需要上传的数据，接口请求时会把里面的key:value一起带上

- (instancetype)initWithDeviceID:(NSString *)did
                             aid:(NSString *)aid
                        delegate:( id <TTAppUpdateDelegate>)delegate;

- (void)startCheckVersion;

@end



NS_ASSUME_NONNULL_END
