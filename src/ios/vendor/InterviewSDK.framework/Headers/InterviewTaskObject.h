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
    InterviewTaskUploadingStageConfirmProgress,
    InterviewTaskUploadingStageConfirmWaiting,
    InterviewTaskUploadingStageS3Progress,
    InterviewTaskUploadingStageParseRequest,
    InterviewTaskUploadingStageFinished,
    InterviewTaskUploadingStageError
} InterviewTaskUploadingStage;

typedef enum {  // confirm.io requests
    InterviewTaskConfirmTypeNone = 0,       // NO   CONFIRMATION:       do not sending any requests to the confirm.io service
    InterviewTaskConfirmTypeDocument,       // DOC  CONFIRMATION:       send 2 document photos (front&back sides) and confirm them
    InterviewTaskConfirmTypeFace,           // FACE CONFIRMATION:       send front document photo and selie to confirm user face
    InterviewTaskConfirmTypeComposite,      // COMPOSITE CONFIRMATION:  make document and face confirmation
    InterviewTaskConfirmTypeDocumentLazy,   // doc confirmation with request only (send request guid to the server)
    InterviewTaskConfirmTypeCompositeLazy   // composite confirmation with request only
} InterviewTaskConfirmType;

typedef void (^ InterviewTaskUploadingProgressBlock)(InterviewTaskUploadingStage curStage, double val);
typedef void (^ InterviewTaskLoadingCompletionBlock)(InterviewTaskObject *result, id error);

@interface InterviewTaskObject : NSObject <NSCoding> {
    
};

- (id)init;
- (id)initForDemo;

@property (nonatomic, strong) NSArray *subtasks;
@property (nonatomic, strong) UIImage *logo;
@property (nonatomic)         InterviewTaskConfirmType confirmType;

// Output dictionary
@property (nonatomic, strong) NSMutableDictionary *result;

// Set subtask's numbers for the confirm photos (id front side, id back side, user selfie)
// Any NSNumber contains subtask number of source photo
// When front and back point to the same subtask, front grabbed from the video beginning and back from the video end
// If yo want only doc or face confirmation pass nil for unaffected parameters
// If you set any confirm option but doesn't use this method, SDK will try automatically detect appropriate subtasks for confirm (not recommended)
// Method returns YES if sources set corrected:
//    - you should set front and back side to subtask with InterviewSubtaskTypePassport type
//    - you should set selfie to subtask with InterviewSubtaskTypeStatementRead or InterviewSubtaskTypeSMSRead type
//    - any subtasks must exists (subtasks property should be filled completely)
// Method returns NO if error occured. In this case SDK will try select subtasks automatically.
- (BOOL)setConfirmSourceFrontDocument:(NSNumber *)front backDocument:(NSNumber *)back selfie:(NSNumber *)selfie;

// Returns (-1) if not set
- (NSInteger)getConfirmSourceForDocumentFront;
- (NSInteger)getConfirmSourceForDocumentBack;
- (NSInteger)getConfirmSourceForDocumentSelfie;


// Internal routines (used within SDK)
- (void)loadTaskWithId:(NSString *)taskId withCompletionBlock:(InterviewTaskLoadingCompletionBlock)completion;
- (void)uploadTaskResultWithProgressBlock:(InterviewTaskUploadingProgressBlock)progress completionBlock:(InterviewTaskLoadingCompletionBlock)completion;

- (BOOL)isDemo;

@end
