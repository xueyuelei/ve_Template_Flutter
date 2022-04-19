//
//  TTAppUpdateTipView.h
//  TTAppUpdateHelper
//  Created by Sunhaiyuan on 2018/3/27.
//  Copyright © 2018 Bytedance. All rights reserved.
#import <UIKit/UIKit.h>
#import "TTCheckVersionResponse.h"

@class TTAppUpdateTipView;

@protocol TTAppUpdateTipViewDelegate <NSObject>

- (void)tipViewUpdateButtonDidClicked:(TTAppUpdateTipView *)tipView;

- (void)tipViewCloseButtonDidClicked:(TTAppUpdateTipView *)tipView;

@end

@interface TTAppUpdateTipView : UIView

- (instancetype)initWithCheckVersionModel:(TTAppUpdateModel *)cvModel;
@property (nonatomic, strong) id<TTAppUpdateTipViewDelegate> delegate; // 需要主动释放即置 nil 即可，不能用 weak，可能会影响部分场景的弹窗关不掉
- (void)show;
- (void)hide;

@end
