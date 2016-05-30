//
//  AffTaskObject.h
//  Affidavit
//
//  Created by Mac on 29.12.15.
//  Copyright © 2015 hintsolutions. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import "AffSubtaskObject.h"
//#import <AWSS3/AWSS3.h>

@class AffTaskObject;

typedef enum {
    AffTaskUploadingStageNone = 0,
    AffTaskUploadingStageS3Progress,
    AffTaskUploadingStageParseRequest,
    AffTaskUploadingStageFinished,
    AffTaskUploadingStageError
} AffTaskUploadingStage;

typedef void (^ AffTaskUploadingProgressBlock)(AffTaskUploadingStage curStage, double val);
typedef void (^ AffTaskLoadingCompletionBlock)(AffTaskObject *result, id error);

@interface AffTaskObject : NSObject {
    
};

- (id)init;
- (id)initForDemo;

@property (nonatomic, strong) UIImage *logo;
@property (nonatomic, strong) NSArray *subtasks;
@property (nonatomic, strong) NSMutableDictionary *result;

- (void)loadTaskWithId:(NSString *)taskId withCompletionBlock:(AffTaskLoadingCompletionBlock)completion;

//- (void)uploadTaskResultWithProgressBlock:(AffTaskUploadingProgressBlock)progress completionBlock:(AffTaskLoadingCompletionBlock)completion;
- (void)uploadTaskResultWithProgressBlock2:(AffTaskUploadingProgressBlock)progress completionBlock:(AffTaskLoadingCompletionBlock)completion;

- (BOOL)isDemo;

@end
