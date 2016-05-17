//
//  SimpleSDK.m
//  SimpleSDK
//
//  Created by Eugine Korobovsky on 12.05.16.
//  Copyright © 2016 hintsolutions. All rights reserved.
//

#import "InterviewCordova.h"

@implementation InterviewCordova

- (void)showDemoInterview:(CDVInvokedUrlCommand*)command{
    __block CDVPluginResult* pluginResult = nil;
    [[Interview instance] showInterviewControllerWithTaskId:nil animated:YES withSuccessHandler:^(NSDictionary * _Nullable task) {
        pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK];
        [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
    } andErrorHandler:^(id  _Nullable error) {
        if([error isKindOfClass:[NSString class]]){
            pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsString:error];
        }else if([error isKindOfClass:[NSError class]]){
            pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsString:[error localizedDescription]];
        }else{
            pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK];
        };
        [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
    }];
};

@end
