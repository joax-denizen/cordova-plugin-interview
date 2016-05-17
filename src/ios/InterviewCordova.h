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

- (void)showDemoInterview:(CDVInvokedUrlCommand*)command;

@end
