//
//  myViewController.m
//  Runner
//
//  Created by bytedance on 2022/4/18.
//

#import "myViewController.h"
#import <VEAppUpdateHelper/TTAppUpdateHelperDefault.h>
#import <OneKit/OneKitApp.h>
#import <OneKit/OKServiceCenter.h>
#import <OneKit/OKApplicationInfo.h>
#import <OneKit/OKServices.h>
#import <OneKit/OKStartUpFunction.h>

@interface myViewController ()<TTAppUpdateDelegate>
@property (nonatomic, strong) TTAppUpdateHelperDefault *updateHelper;
@end

@implementation myViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
}

- (IBAction)buttonClicked:(id)sender {
    [self update];
    [self.updateHelper startCheckVersion];
}

- (void)update {
    if(!self.updateHelper) {
        __block id<OKDeviceService> deviceService = [[OKServiceCenter sharedInstance] serviceForProtocol:@protocol(OKDeviceService)];
        OKApplicationInfo *info = [OKApplicationInfo sharedInstance];
        TTAppUpdateHelperDefault *defaultHelper = [[TTAppUpdateHelperDefault alloc] initWithDeviceID:deviceService.deviceID
                                                                                                 aid:info.appID delegate:self];
        
        self.updateHelper = defaultHelper;
        self.updateHelper.callType = @(0);
        self.updateHelper.city = @"Shanghai";
        
    }
}

#pragma mark TTAppUpdateDelegate
- (void)updateViewShouldShow:(TTAppUpdateTipView *)tipView model:(TTAppUpdateModel *)model {
    //弹窗开启弹窗，先判断url有效性
    if ([self verifyWebUrlAddress:model.downloadURL]) {
        [tipView show];
    }
    //弹窗关闭业务自己处理数据，不用处理tipView
}

- (void)updateViewShouldClosed:(TTAppUpdateTipView *)tipView {
    [tipView hide];
    self.updateHelper = nil;
}

- (BOOL)verifyWebUrlAddress:(NSString *)webUrl
{
    if (!webUrl) {
          return NO;
      }
    return [UIApplication.sharedApplication canOpenURL:[NSURL URLWithString:webUrl]];
}
/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end
