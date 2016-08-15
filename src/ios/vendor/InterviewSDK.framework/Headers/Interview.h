//
//  Interview.h
//  InterviewSDK
//
//  Created by Eugine Korobovsky on 29.03.16.
//  Copyright © 2016 hintsolutions. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

//NS_ASSUME_NONNULL_BEGIN


typedef enum : NSUInteger {
    InterviewVideoQualityLow,
    InterviewVideoQualityMedium,
    InterviewVideoQualityHigh,
} InterviewVideoQuality;

typedef void (^InterviewCompletionBlock)(NSDictionary  * _Nullable task);
typedef void (^InterviewErrorBlock)(id _Nullable error);

@interface Interview : NSObject {
    
}

// Interview controller will never closed if you set this property to YES (default NO)
@property (nonatomic, setter=setIsDemoApp:, getter=isDemoApp) BOOL isDemoApp;

// If you want to hide close button at video controller, set this property to NO (default YES)
@property (nonatomic, setter=setIsCloseButton:, getter=isCloseButton) BOOL isCloseButton;

// Output video quality: InterviewVideoQualityLow, InterviewVideoQualityMedium(default), InterviewVideoQualityHigh
@property (nonatomic, setter=setVideoQuality:, getter=getVideoQuality) InterviewVideoQuality videoQuality;

// When this value "YES", SDK uploads video after interview. Value "NO" will prevent uploading video by SDK. (default YES)
@property (nonatomic, setter=setAutoloadVideo:, getter=isAutoloadVideo) BOOL isAutoloadVideo;

// Back-end API URL address. Default: "https://videointerview.blocknotary.com/"
@property (nonatomic, setter=setEngineURL:, getter=getEngineURL)  NSString * _Nullable engineURL;


+ (instancetype _Nonnull)instance;

- (NSString * _Nonnull)sdkVersion;

- (void)showInterviewControllerWithTaskId:(NSString * _Nullable)taskId animated:(BOOL)isAnimating;
- (void)showInterviewControllerWithTaskId:(NSString *_Nullable)taskId animated:(BOOL)isAnimating withSuccessHandler:(InterviewCompletionBlock _Nullable)successBlock andErrorHandler:(InterviewErrorBlock _Nullable)errorBlock;

- (BOOL)mainApplication:(UIApplication * _Nonnull)application continueUserActivity:(NSUserActivity * _Nullable)userActivity restorationHandler:(void (^ _Nullable)(NSArray * _Nullable))restorationHandler;
- (BOOL)mainApplication:(UIApplication * _Nonnull)application openURL:(NSURL * _Nonnull)url sourceApplication:(NSString * _Nullable)sourceApplication annotation:(id _Nullable)annotation;

@end


//NS_ASSUME_NONNULL_END