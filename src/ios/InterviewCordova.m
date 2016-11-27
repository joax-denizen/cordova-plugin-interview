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
    
    [[Interview instance] setIsCloseButton:YES];
    [[Interview instance] setIsRestartButton:NO];
    [[Interview instance] setIsTutorial:NO];
    [[Interview instance] setVideoQuality:InterviewVideoQualityMedium];
    [[Interview instance] setAutoclose:YES];
    
    [[Interview instance] setInterfaceScheme:InterviewInterfaceSchemeBlack];
    
    InterviewSubtaskObject *subtask0 = [[InterviewSubtaskObject alloc] initWithType:InterviewSubtaskTypeDemo];
    subtask0.title = @"DEMO MODE";
    subtask0.subtitle = @"Use the link in your mailbox to go through a personalized interview process";
    subtask0.presentationStyle = InterviewSubtaskPresentationStylePortrait;
    
    
    InterviewSubtaskObject *subtask1 = [[InterviewSubtaskObject alloc] initWithType:InterviewSubtaskTypeSMSRead];
    subtask1.presentationStyle = InterviewSubtaskPresentationStylePortrait;
    subtask1.preface = @"Face the camera and press 'Record'";
    subtask1.title = @"Read the numbers outloud facing the camera";
    subtask1.subtitle = @"16854654";
    subtask1.minVideoDuration = (DEBUG?0:5);
    subtask1.maxVideoDuration = 15;
    subtask1.speechRecognizerLanguage = @"en-US";
    
    InterviewSubtaskObject *subtask2 = [[InterviewSubtaskObject alloc] initWithType:InterviewSubtaskTypePassport];
    subtask2.preface = @"Center the passport here and then press 'Record'";
    subtask2.title = @"Document recording";
    subtask2.subtitle = @"Please wait until recording continues";
    subtask2.minVideoDuration = (DEBUG?0:5);
    subtask2.maxVideoDuration = 5;
    
    InterviewTaskObject *demoTask = [InterviewTaskObject new];
    demoTask.subtasks = @[subtask0, subtask1, subtask2];
    [[Interview instance] setDemoTask:demoTask];
    
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
