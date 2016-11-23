//
//  CameraView.h
//  SecureCam
//
//  Created by Mac on 26.05.14.
//  Copyright (c) 2014 hintsolutions. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "SecureVideoEngine.h"
#import "InterviewTaskObject.h"
#import "AffCameraOverlayView.h"

@interface AffCameraController : UIViewController <UIAccelerometerDelegate, SecureVideoEngineDelegate, AffCameraOverlayViewProtocol> {
    
};

@property (nonatomic, strong) IBOutlet UIView *preView;
@property (nonatomic, strong, setter=setCurrentTask:) InterviewTaskObject *currentTask;


#pragma mark Start screen routines

- (void)stopCurrentLoading;
- (void)startNewSession;

#pragma mark Camera screen routines

- (void)restartEntireTask;
- (void)restartLastSubtask;

@end
