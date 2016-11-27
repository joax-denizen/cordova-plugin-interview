//
//  AffTaskObject.h
//  Affidavit
//
//  Created by Mac on 29.12.15.
//  Copyright © 2015 hintsolutions. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import "InterviewSubtaskObject.h"
//#import <AWSS3/AWSS3.h>

@class InterviewTaskObject;

typedef enum {
    InterviewTaskUploadingStageNone = 0,
    InterviewTaskUploadingStageS3Progress,
    InterviewTaskUploadingStageParseRequest,
    InterviewTaskUploadingStageFinished,
    InterviewTaskUploadingStageError
} InterviewTaskUploadingStage;

typedef void (^ InterviewTaskUploadingProgressBlock)(InterviewTaskUploadingStage curStage, double val);
typedef void (^ InterviewTaskLoadingCompletionBlock)(InterviewTaskObject *result, id error);

@interface InterviewTaskObject : NSObject {
    
};

- (id)init;
- (id)initForDemo;

@property (nonatomic, strong) UIImage *logo;
@property (nonatomic, strong) NSArray *subtasks;
@property (nonatomic, strong) NSMutableDictionary *result;

- (void)loadTaskWithId:(NSString *)taskId withCompletionBlock:(InterviewTaskLoadingCompletionBlock)completion;
- (void)uploadTaskResultWithProgressBlock:(InterviewTaskUploadingProgressBlock)progress completionBlock:(InterviewTaskLoadingCompletionBlock)completion;

- (BOOL)isDemo;

@end
