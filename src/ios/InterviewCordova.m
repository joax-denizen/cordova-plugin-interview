//
//  SimpleSDK.m
//  SimpleSDK
//
//  Created by Eugine Korobovsky on 12.05.16.
//  Copyright © 2016 hintsolutions. All rights reserved.
//

#import "InterviewCordova.h"

@interface InterviewCordova () <InterviewDelegate> {
    
}

@property (nonatomic, strong) NSString* callbackId;

@end

@implementation InterviewCordova

- (void)setDelegateMethod:(CDVInvokedUrlCommand*)command {
    self.callbackId = command.callbackId;
};

- (void)setEngine:(CDVInvokedUrlCommand*)command {
    CDVPluginResult* pluginResult = nil;
    
    if(command.arguments.count>=4){
        NSString *engineURL = [command.arguments objectAtIndex:0];
        NSString *username = [command.arguments objectAtIndex:1];
        NSString *password = [command.arguments objectAtIndex:2];
        NSString *demoTaskId = [command.arguments objectAtIndex:3];
        if([engineURL isKindOfClass:[NSString class]] && [username isKindOfClass:[NSString class]] && [password isKindOfClass:[NSString class]] && [demoTaskId isKindOfClass:[NSString class]]){
            [[Interview instance] setEngineURL:engineURL withUsername:username andPassword:password demoTaskId:demoTaskId];
            pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK];
        }else{
            pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:@"Please specify engine URL, username, password and taskId for demo interviews"];
        };
    }else{
        pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:@"Incorrect parameters number (setEngine method)"];
    };
    
    [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
};

- (void)setEngineWithKey:(CDVInvokedUrlCommand*)command {
    CDVPluginResult* pluginResult = nil;
    
    if(command.arguments.count>=3){
        NSString *engineURL = [command.arguments objectAtIndex:0];
        NSString *apiKey = [command.arguments objectAtIndex:1];
        NSString *demoTaskId = [command.arguments objectAtIndex:2];
        if([engineURL isKindOfClass:[NSString class]] && [apiKey isKindOfClass:[NSString class]] && [demoTaskId isKindOfClass:[NSString class]]){
            [[Interview instance] setEngineURL:engineURL withApiKey:apiKey demoTaskId:demoTaskId];
            pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK];
        }else{
            pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:@"Please specify engine URL, API-key and taskId for demo interviews"];
        };
    }else{
        pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:@"Incorrect parameters number (setEngineWithKey method)"];
    };
    
    [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
};

- (void)setS3Storage:(CDVInvokedUrlCommand*)command{
    CDVPluginResult* pluginResult = nil;
    
    if(command.arguments.count>=4){
        NSString *s3Endpoint = [command.arguments objectAtIndex:0];
        NSString *bucketName = [command.arguments objectAtIndex:1];
        NSString *accessKey = [command.arguments objectAtIndex:2];
        NSString *secretKey = [command.arguments objectAtIndex:3];
        if([s3Endpoint isKindOfClass:[NSString class]] && [bucketName isKindOfClass:[NSString class]] && [accessKey isKindOfClass:[NSString class]] && [secretKey isKindOfClass:[NSString class]]){
            [[Interview instance] setS3StorageURL:s3Endpoint withBucketName:bucketName withAccessKey:accessKey andSecretKey:secretKey];
            pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK];
        }else{
            pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:@"Please specify S3 storage URL, bucket name, access key and secret key"];
        };
    }else{
        pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:@"Incorrect parameters number (setS3Storage method)"];
    };
    
    [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
}

- (void)setAuthString:(CDVInvokedUrlCommand*)command {
    CDVPluginResult* pluginResult = nil;
    
    if(command.arguments.count>=1){
        NSString *authString = [command.arguments objectAtIndex:0];
        if([authString isKindOfClass:[NSString class]]){
            if([[Interview instance] setAuthHdr:authString]==YES){
                pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK];
            }else{
                pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:@"Cannot parse Basic auth string: use string like \"<auth_type> <credentials>\" (<auth_type> = Basic|Bearer|BNSession)"];
            };
        }else{
            pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:@"Please specify auth string"];
        };
    }else{
        pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:@"Incorrect parameters number (setAuthString method)"];
    };
    
    [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
}

- (void)showInterview:(CDVInvokedUrlCommand*)command{
    __block CDVPluginResult* pluginResult = nil;
    
    if(command.arguments.count>=2){
        NSString *taskId = [command.arguments objectAtIndex:0];
        if([taskId isKindOfClass:[NSString class]]==NO){
            taskId = nil;
        };
        
        InterviewVideoQuality videoQuality = InterviewVideoQualityMedium;
        NSString *videoQualityStr = [command.arguments objectAtIndex:1];
        if([videoQualityStr isKindOfClass:[NSString class]]){
            videoQualityStr = [videoQualityStr lowercaseString];
            if([videoQualityStr isEqualToString:@"interviewvideoqualitylow"] || [videoQualityStr isEqualToString:@"low"]){
                videoQuality = InterviewVideoQualityLow;
            };
            if([videoQualityStr isEqualToString:@"interviewvideoqualitymedium"] || [videoQualityStr isEqualToString:@"medium"]){
                videoQuality = InterviewVideoQualityMedium;
            };
            if([videoQualityStr isEqualToString:@"interviewvideoqualityhigh"] || [videoQualityStr isEqualToString:@"high"]){
                videoQuality = InterviewVideoQualityHigh;
            };
        };
        
        [[Interview instance] setIsCloseButton:YES];
        [[Interview instance] setIsRestartButton:NO];
        [[Interview instance] setIsTutorial:NO];
        [[Interview instance] setVideoQuality:videoQuality];
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
        subtask1.minVideoDuration = 5;
        subtask1.maxVideoDuration = 15;
        subtask1.speechRecognizerLanguage = @"en-US";
        InterviewSubtaskObject *subtask2 = [[InterviewSubtaskObject alloc] initWithType:InterviewSubtaskTypePassport];
        subtask2.preface = @"Center the passport here and then press 'Record'";
        subtask2.title = @"Document recording";
        subtask2.subtitle = @"Please wait until recording continues";
        subtask2.minVideoDuration = 5;
        subtask2.maxVideoDuration = 5;
        InterviewTaskObject *demoTask = [InterviewTaskObject new];
        demoTask.subtasks = @[subtask0, subtask1, subtask2];
        [[Interview instance] setDemoTask:demoTask];
        
        [[Interview instance] setDelegate:self];
        
        [[Interview instance] showInterviewControllerWithTaskId:taskId animated:YES withSuccessHandler:^(NSDictionary * _Nullable task) {
            pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK];
            [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
        } andErrorHandler:^(id  _Nullable error) {
            if([error isKindOfClass:[NSString class]]){
                pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:error];
            }else if([error isKindOfClass:[NSError class]]){
                pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:[error localizedDescription]];
            }else{
                pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR];
            };
            [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
        }];
    }else{
        pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:@"Incorrect parameters number (showInterview method)"];
        [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
    };
};

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
    subtask1.minVideoDuration = 5;
    subtask1.maxVideoDuration = 15;
    subtask1.speechRecognizerLanguage = @"en-US";
    InterviewSubtaskObject *subtask2 = [[InterviewSubtaskObject alloc] initWithType:InterviewSubtaskTypePassport];
    subtask2.preface = @"Center the passport here and then press 'Record'";
    subtask2.title = @"Document recording";
    subtask2.subtitle = @"Please wait until recording continues";
    subtask2.minVideoDuration = 5;
    subtask2.maxVideoDuration = 5;
    InterviewTaskObject *demoTask = [InterviewTaskObject new];
    demoTask.subtasks = @[subtask0, subtask1, subtask2];
    [[Interview instance] setDemoTask:demoTask];
    
    [[Interview instance] setDelegate:self];
    
    [[Interview instance] showInterviewControllerWithTaskId:nil animated:YES withSuccessHandler:^(NSDictionary * _Nullable task) {
        pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsDictionary:task];
        [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
    } andErrorHandler:^(id  _Nullable error) {
        if([error isKindOfClass:[NSString class]]){
            pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:error];
        }else if([error isKindOfClass:[NSError class]]){
            pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:[error localizedDescription]];
        }else{
            pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR];
        };
        [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
    }];
};

# pragma mark - InterviewDelagate's routines

- (void)interviewWillAppear:(Interview *)interview{
    NSLog(@"Will appear INTERVIEW 0x%08lX", (unsigned long)interview);
    
    CDVPluginResult* result = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsString:@"willAppear"];
    [self.commandDelegate sendPluginResult:result callbackId:self.callbackId];
};

- (void)interviewDidAppear:(Interview *)interview{
    NSLog(@"Did appear INTERVIEW 0x%08lX", (unsigned long)interview);
    
    CDVPluginResult* result = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsString:@"didAppear"];
    [self.commandDelegate sendPluginResult:result callbackId:self.callbackId];
};

- (void)interviewWillDisappear:(Interview *)interview{
    NSLog(@"Will disappear INTERVIEW 0x%08lX", (unsigned long)interview);
    
    CDVPluginResult* result = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsString:@"willDisappear"];
    [self.commandDelegate sendPluginResult:result callbackId:self.callbackId];
};

- (void)interviewDidDisappear:(Interview *)interview{
    NSLog(@"Did disappear INTERVIEW 0x%08lX", (unsigned long)interview);
    
    CDVPluginResult* result = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsString:@"didDisappear"];
    [self.commandDelegate sendPluginResult:result callbackId:self.callbackId];
};

@end
