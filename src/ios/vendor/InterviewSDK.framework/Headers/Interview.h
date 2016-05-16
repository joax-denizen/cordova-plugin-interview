//
//  Interview.h
//  InterviewSDK
//
//  Created by Eugine Korobovsky on 29.03.16.
//  Copyright © 2016 hintsolutions. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

typedef void (^InterviewCompletionBlock)(NSDictionary  * _Nullable task);
typedef void (^InterviewErrorBlock)(id _Nullable error);

@interface Interview : NSObject {
    
}

// If this property equals YES, SDK will show 'goodbye' view controller after success transmission
// otherwise SDK will exit automatically (default YES)
@property (nonatomic, setter=setIsGoodbyeScreen:, getter=isGoodbyeScreen) BOOL isGoodbyeScreen;

// Interview controller will never closed if you set this property to YES (default NO)
@property (nonatomic, setter=setIsDemoApp:, getter=isDemoApp) BOOL isDemoApp;

// If you want to hide close button at video controller, set this property to NO (default YES)
@property (nonatomic, setter=setIsCloseButton:, getter=isCloseButton) BOOL isCloseButton;


+ (instancetype _Nonnull)instance;

- (void)showInterviewControllerWithTaskId:(NSString * _Nullable)taskId animated:(BOOL)isAnimating;
- (void)showInterviewControllerWithTaskId:(NSString *_Nullable)taskId animated:(BOOL)isAnimating withSuccessHandler:(InterviewCompletionBlock _Nullable)successBlock andErrorHandler:(InterviewErrorBlock _Nullable)errorBlock;

- (BOOL)mainApplication:(UIApplication * _Nonnull)application continueUserActivity:(NSUserActivity * _Nullable)userActivity restorationHandler:(void (^ _Nullable)(NSArray * _Nullable))restorationHandler;
- (BOOL)mainApplication:(UIApplication * _Nonnull)application openURL:(NSURL * _Nonnull)url sourceApplication:(NSString * _Nullable)sourceApplication annotation:(id _Nullable)annotation;

@end
