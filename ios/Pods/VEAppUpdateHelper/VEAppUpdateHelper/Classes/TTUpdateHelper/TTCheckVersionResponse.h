//
//  TTCheckVersionResponse.h
//  TTAppUpdateHelper
//
//  Created by Sunhaiyuan on 2018/3/30.
//  Copyright © 2018 Bytedance. All rights reserved.
//

#import <JSONModel/JSONModel.h>

@interface TTAppUpdateModel : JSONModel

@property (nonatomic, copy) NSString<Optional> *tipsVersionName;//大版本号，和请求字段一致
@property (nonatomic, strong) NSString<Optional> *tipsVersionCode;//小版本号，和请求字段一致
@property (nonatomic, copy) NSString<Optional> *whatsNew;//下载后的升级提示
@property (nonatomic, copy) NSString<Optional> *title;//弹窗标题
@property (nonatomic, strong) NSNumber<Optional> *enable_popup;//是否需要弹窗,若不需要弹窗，客户端自行处理，
@property (nonatomic, copy) NSString<Optional> *downloadURL;//安装包下载地址
@property (nonatomic, strong) NSNumber<Optional> *enable_force_update;//是否开启强制更新，若开启强制更新，不能关闭弹窗
@end

@class TTCheckVersionResponseDataModel;

@interface TTCheckVersionResponse : JSONModel

@property (nonatomic, copy) NSString *message;
@property (nonatomic, strong) TTAppUpdateModel *data;

@end


