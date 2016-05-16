//
//  SecureVideoEngine.h
//  SecureCam
//
//  Created by Mac on 26.05.14.
//  Copyright (c) 2014 hintsolutions. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>
#import <CoreLocation/CoreLocation.h>
#import "AffTaskObject.h"
#import "AffSubtaskObject.h"


//@class SDC;
@class SecureVideoEngine;

typedef enum {
    EngineStateNotPrepared = 0,
	EngineStatePreparing,
    EngineStateSessionNotStarted,
	EngineStateReady,
    EngineStateRecording,
    EngineStateProcessing,
    EngineStateError,
    EngineStateFatalError,
    EngineStateInterrupted
} EngineState;

@protocol SecureVideoEngineDelegate <NSObject>
@required
- (void)videoEngineStateWasChanged:(nonnull SecureVideoEngine *)engine;
- (void)startRecording;
- (void)finishRecording;
- (void)failRecording;
- (void)forceProcessingVideoAfterInterrupt;
- (void)diskIsFull;
- (void)faceWasDetectedAtBounds:(CGRect)relativelyBounds;
- (void)faceWasUndetected;
@optional
- (void)videoFrameRetrieved:(UIImage *)videoFrame;
@end


@interface SecureVideoEngine : NSObject <AVCaptureFileOutputRecordingDelegate, AVCaptureVideoDataOutputSampleBufferDelegate, CLLocationManagerDelegate> {
    
}

+ (instancetype)instance;

@property (nonatomic, assign) id<SecureVideoEngineDelegate> delegate;
//@property (nonatomic, assign) SDC *sdc;

//- (id)initWithSDC:(SDC *)sdc;
- (id)init;

- (BOOL)createCaptureSession;
- (void)setCapturePreView:(UIView *)preView;
- (void)setCaptureQuality;
- (void)startCaptureSession;
- (void)stopCaptureSession;
- (void)startMovieCapturing;
- (void)stopMovieCapturing;
- (void)stopMovieCapturingWithoutCompose;
- (void)updatePreviewLayerFrame:(CGRect)newFrame;

- (void)startFaceDetection;
- (void)stopFaceDetection;


- (void)startComposingReadyMovieForTask:(AffTaskObject *)task;

//- (BOOL)signRecordWithRecordInfo:(NSMutableDictionary *)recordDictionary;

- (void)setTorchEnabled:(BOOL)isTorch;

- (BOOL)isRecordRunning;
- (BOOL)isCaptureSessionRunning;

@property (nonatomic, strong) NSString *taskId;
//@property (nonatomic, strong) id userInfo;

@property (nonatomic) BOOL isGoodbyeScreen;
@property (nonatomic) BOOL isDemoApp;
@property (nonatomic) BOOL isCloseButton;

@property (nonatomic, setter = setOrientation:) UIInterfaceOrientation currentOrientation;
@property (nonatomic, setter = setCameraPosition:) AVCaptureDevicePosition cameraPosition;
@property (nonatomic, setter = setMirroring:) BOOL isMirroring;
@property (nonatomic) BOOL isDateTimeOverlay;
@property (nonatomic, setter = setIsGeolocationOverlay:) BOOL isGeolocationOverlay;

// Info-properties
@property (nonatomic, readonly) EngineState engineState;

@property (nonatomic) NSInteger fragmentIndex;

@property (nonatomic, readonly) CLLocationCoordinate2D gpsCoord;
/*@property (nonatomic, readonly) double gpsVelocity;
@property (nonatomic, readonly) double gpsAzimuth;
@property (nonatomic, readonly) double accelX;
@property (nonatomic, readonly) double accelY;
@property (nonatomic, readonly) double accelZ;*/

// Service framework routines
- (BOOL)mainApplication:(UIApplication *)application continueUserActivity:(NSUserActivity *)userActivity restorationHandler:(void (^)(NSArray * _Nullable))restorationHandler;
- (BOOL)mainApplication:(UIApplication *)application openURL:(NSURL *)url sourceApplication:(NSString *)sourceApplication annotation:(id)annotation;

@end
