//
//  NSMutableURLRequest+Signature.h
//  OneKit
//
//  Created by 朱元清 on 2021/1/13.
//
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSMutableURLRequest (OKSignature)

/*! 根据OneKit自动获取的AK,SK来签名 */
- (void)ok_autoSign;

/*! 根据传入的AK,SK参数来签名
 * @param AK AppKey
 * @param SK AppSecretKey
 */
- (void)ok_signWithAK:(NSString *)AK SK:(NSString *)SK;

// udid用于计量计费，该方法会自动将udid加入请求头，因为udid本身为异步获取，在首次启动时有一定概率获取不到
// 如果未获取到，则默认传"0"
- (void)ok_appendUdid;

- (void)ok_appendSDKVersion:(NSString *)version;

@end

NS_ASSUME_NONNULL_END
