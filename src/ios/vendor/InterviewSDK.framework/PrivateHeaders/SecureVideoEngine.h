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
#import "Interview.h"

typedef void (^ExportAudioCompletionBlock)(id _Nullable error);

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

typedef enum {
    EngineCatchScreenshotStyleNone = 0,
    EngineCatchScreenshotStyleFace,
    EngineCatchScreenshotStyleFacePortrait,
    EngineCatchScreenshotStyleDocument,
    EngineCatchScreenshotStyleFaceIdle,         // only highlight, not catch
    EngineCatchScreenshotStyleFacePortraitIdle, // only highlight, not catch
    EngineCatchScreenshotStyleDocumentIdle      // only highlight, not catch
} EngineCatchScreenshotStyle;

@protocol SecureVideoEngineDelegate <NSObject>
@required
- (void)videoEngineStateWasChanged:(nonnull SecureVideoEngine *)engine;
- (void)startRecording;
- (void)finishRecording;
- (void)failRecording;
- (void)forceProcessingVideoAfterInterrupt;
- (void)diskIsFull;
- (void)faceWasDetectedAtBounds:(CGRect)relativelyBounds onImage:(UIImage * _Nullable)img;
- (void)faceWasUndetected;
@optional
- (void)videoFrameRetrieved:(UIImage * _Nullable)videoFrame;
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

- (BOOL)checkOneTimeFlag:(NSString *)flagName;

@property (nonatomic) EngineCatchScreenshotStyle catchScreenshotsType;

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
@property (nonatomic) InterviewVideoQuality outVideoQuality;
@property (nonatomic) BOOL isAutoloadVideo;
@property (nonatomic, strong, getter = getEngineURL) NSString *engineURL;

// Info-properties
@property (nonatomic, readonly) EngineState engineState;
@property (nonatomic) NSInteger fragmentIndex;
@property (nonatomic, readonly) CLLocationCoordinate2D gpsCoord;


// Service framework routines
- (BOOL)mainApplication:(UIApplication *)application continueUserActivity:(NSUserActivity *)userActivity restorationHandler:(void (^)(NSArray * _Nullable))restorationHandler;
- (BOOL)mainApplication:(UIApplication *)application openURL:(NSURL *)url sourceApplication:(NSString *)sourceApplication annotation:(id)annotation;

@end
