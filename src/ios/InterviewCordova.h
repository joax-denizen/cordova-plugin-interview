//
//  SimpleSDK.h
//  SimpleSDK
//
//  Created by Eugine Korobovsky on 12.05.16.
//  Copyright © 2016 hintsolutions. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <Cordova/CDVPlugin.h>
#import <InterviewSDK/InterviewSDK.h>

@interface InterviewCordova : CDVPlugin

- (void)setDelegateMethod:(CDVInvokedUrlCommand*)command;
- (void)setEngine:(CDVInvokedUrlCommand*)command;
- (void)setEngineWithKey:(CDVInvokedUrlCommand*)command;
- (void)setS3Storage:(CDVInvokedUrlCommand*)command;
- (void)setAuthString:(CDVInvokedUrlCommand*)command;
- (void)showInterview:(CDVInvokedUrlCommand*)command;
- (void)showDemoInterview:(CDVInvokedUrlCommand*)command;;

@end
