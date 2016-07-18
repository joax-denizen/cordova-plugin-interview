//
//  CameraView.h
//  SecureCam
//
//  Created by Mac on 26.05.14.
//  Copyright (c) 2014 hintsolutions. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "SecureVideoEngine.h"
#import "AffTaskObject.h"
#import "AffCameraOverlayView.h"

@interface AffCameraController : UIViewController <UIAccelerometerDelegate, SecureVideoEngineDelegate, AffCameraOverlayViewProtocol> {
    
};


//@property (nonatomic, strong) SecureVideoEngine *engine;
@property (nonatomic, strong) IBOutlet UIView *preView;

@property (nonatomic, strong) IBOutlet UIView *needRotateView;
@property (nonatomic, strong) IBOutlet UIImageView *needRotateImage;
@property (nonatomic, strong) IBOutlet UILabel *needRotateLabel;

@property (nonatomic, strong, setter=setCurrentTask:) AffTaskObject *currentTask;

- (void)restartEntireTask;

@end
