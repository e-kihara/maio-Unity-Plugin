//
//  Maio.h
//  Maio
//
//
//
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <AVFoundation/AVFoundation.h>
#import <SystemConfiguration/SystemConfiguration.h>
#import <MobileCoreServices/MobileCoreServices.h>
#import <sys/sysctl.h>
#if __IPHONE_OS_VERSION_MAX_ALLOWED > __IPHONE_5_0
#import <AdSupport/AdSupport.h> // idfaの取得 用
#endif
#import <Maio/MaioDelegate.h>

@interface Maio: NSObject

/**
 *  maio SDK のバージョンを返します。
 */
+ (NSString *)sdkVersion;

/**
 *  広告の配信テストを行うかどうかを設定します。
 *
 *  @param adTestMode    広告のテスト配信を行う場合には YES、それ以外なら NO。アプリ開発中は YES にし、ストアに提出する際には NO にして下さい（既定値は NO）。
 */
+ (void)setAdTestMode:(BOOL)adTestMode
#ifndef DEBUG
__attribute__((deprecated("Deprecated on Release build")))
#endif
;

/// maio SDK からの通知を受け取るデリゲート
+ (id<MaioDelegate>)delegate;
/// maio SDK からの通知を受け取るデリゲートをセットします。
+ (void)setDelegate:(id<MaioDelegate>)delegate;

/**
 *  SDK のセットアップを開始します。
 *
 *  @param mediaId 管理画面にて発行されるアプリ識別子
 *  @param delegate SDK からの通知を受け取るデリゲート。通知を受け取る必要がない場合は nil を渡します。
 */
+ (void)startWithMediaId:(NSString *)mediaId delegate:(id<MaioDelegate>)delegate;

/**
 *  既定のゾーンの広告表示準備が整っていれば YES、そうでなければ NO を返します。
 */
+ (BOOL)canShow;

/**
 *  指定したゾーンの広告表示準備が整っていれば YES、そうでなければ NO を返します。
 *
 *  @param zoneId  広告の表示準備が整っているか確認したいゾーンの識別子
 */
+ (BOOL)canShowAtZoneId:(NSString *)zoneId;

/**
 *  既定のゾーンの広告を表示します。
 */
+ (void)show;

/**
 *  指定したゾーンの広告を表示します。
 *
 *  @param zoneId  広告を表示したいゾーンの識別子
 */
+ (void)showAtZoneId:(NSString *)zoneId;


+ (void)showWithViewController:(UIViewController *)vc;
+ (void)showAtZoneId:(NSString *)zoneEid vc:(UIViewController *)vc;

@end