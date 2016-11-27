//
//  Interview.h
//  InterviewSDK
//
//  Created by Eugine Korobovsky on 29.03.16.
//  Copyright © 2016 hintsolutions. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "InterviewTaskObject.h"

//NS_ASSUME_NONNULL_BEGIN


typedef enum : NSUInteger {
    InterviewVideoQualityLow,
    InterviewVideoQualityMedium,
    InterviewVideoQualityHigh,
} InterviewVideoQuality;

typedef enum : NSUInteger {
    InterviewInterfaceSchemeOrange = 0,
    InterviewInterfaceSchemeBlue,
    InterviewInterfaceSchemeGreen,
    InterviewInterfaceSchemeBlack
} InterviewInterfaceScheme;


typedef void (^InterviewCompletionBlock)(NSDictionary  * _Nullable task);
typedef void (^InterviewErrorBlock)(id _Nullable error);

@interface Interview : NSObject {
    
}

// Interview controller will never closed if you set this property to YES (default NO)
@property (nonatomic, setter=setIsDemoApp:, getter=isDemoApp) BOOL isDemoApp;

// If you want to hide close button at video controller, set this property to NO (default YES)
@property (nonatomic, setter=setIsCloseButton:, getter=isCloseButton) BOOL isCloseButton;

// When YES, show "back" button on a first screen - it will perform close function (default: NO)
//@property (nonatomic, setter=setIsBackButtonInsteadCloseAtStart:, getter=isBackButtonInsteadCloseAtStart) BOOL isBackButtonInsteadCloseAtStart;


// If you want to hide restart button for every subtask, set this property to NO (default YES)
@property (nonatomic, setter=setIsRestartButton:, getter=isRestartButton) BOOL isRestartButton;

// Does API should display tutorial during loading progress (default YES)
@property (nonatomic, setter=setIsTutorial:, getter=isTutorial) BOOL isTutorial;

// Output video quality: InterviewVideoQualityLow, InterviewVideoQualityMedium(default), InterviewVideoQualityHigh
@property (nonatomic, setter=setVideoQuality:, getter=getVideoQuality) InterviewVideoQuality videoQuality;

// When this value "YES", SDK uploads video after interview. Value "NO" will prevent uploading video by SDK. (default YES)
@property (nonatomic, setter=setAutoloadVideo:, getter=isAutoloadVideo) BOOL isAutoloadVideo;

// When this value "YES", SDK automatically closed after video upload. When "NO" SDK will ask user after uploading for appropriate variant. Available only when isCloseButton is YES (default NO)
@property (nonatomic, setter=setAutoclose:, getter=isAutoclose) BOOL isAutoclose;


// Back-end API URL address. Default: "https://videointerview.blocknotary.com/" DEPRECATED! Use setEngineURL:withUsername:andPassword:demoTaskId: instead
@property (nonatomic, setter=setEngineURL:, getter=getEngineURL)  NSString * _Nullable engineURL;

// Interface scheme
@property (nonatomic, setter=setInterfaceScheme:, getter=getInterfaceScheme)  InterviewInterfaceScheme interfaceScheme;


+ (instancetype _Nonnull)instance;

- (NSString * _Nonnull)sdkVersion;

// When you set API URL, you should specify login information and task id for demo-task (using when uploading demo task)
- (void)setEngineURL:(NSString * _Nonnull)apiURL withUsername:(NSString * _Nonnull)username andPassword:(NSString * _Nonnull)password demoTaskId:(NSString * _Nonnull)taskId;

- (void)setDemoTask:(InterviewTaskObject * _Nonnull)demoTask;

- (void)showInterviewControllerWithTaskId:(NSString * _Nullable)taskId animated:(BOOL)isAnimating;
- (void)showInterviewControllerWithTaskId:(NSString *_Nullable)taskId animated:(BOOL)isAnimating withSuccessHandler:(InterviewCompletionBlock _Nullable)successBlock andErrorHandler:(InterviewErrorBlock _Nullable)errorBlock;
- (void)showInterviewControllerWithTaskId:(NSString *_Nullable)taskId animated:(BOOL)isAnimating withUserMetadata:(NSDictionary * _Nullable)metadata withSuccessHandler:(InterviewCompletionBlock _Nullable)successBlock andErrorHandler:(InterviewErrorBlock _Nullable)errorBlock;

- (BOOL)mainApplication:(UIApplication * _Nonnull)application continueUserActivity:(NSUserActivity * _Nullable)userActivity restorationHandler:(void (^ _Nullable)(NSArray * _Nullable))restorationHandler;
- (BOOL)mainApplication:(UIApplication * _Nonnull)application openURL:(NSURL * _Nonnull)url sourceApplication:(NSString * _Nullable)sourceApplication annotation:(id _Nullable)annotation;

@end


//NS_ASSUME_NONNULL_END
