//
//  AffCameraOverlayView.h
//  Affidavit
//
//  Created by Eugine Korobovsky on 25.12.15.
//  Copyright © 2015 hintsolutions. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "AffSubtaskObject.h"

typedef enum : NSUInteger {
    AffCameraOverlayViewStateUnknown = 0,
    AffCameraOverlayViewStateTaskShowed,
    AffCameraOverlayViewStateTaskProcess,
    AffCameraOverlayViewStateTaskInterrupted,
    AffCameraOverlayViewStateTaskCompleted
} AffCameraOverlayViewState;

@protocol AffCameraOverlayViewProtocol <NSObject>

- (void)didPressNavbarBackButton;
- (void)didPressExitButton;
- (void)didPressTaskButton;
- (BOOL)isTaskButtonShouldBeResponsed;

@end

@interface AffCameraOverlayView : UIView {
    
};

@property (nonatomic, assign) id <AffCameraOverlayViewProtocol> delegate;

@property (nonatomic) AffCameraOverlayViewState taskState;

@property (nonatomic, strong) UIImageView *cameraMaskImageView;
@property (nonatomic, strong) UIScrollView *taskDescrScrollView;
@property (nonatomic, strong) UILabel *taskTitle;
//@property (nonatomic, strong) UILabel *stepLabel;
@property (nonatomic, strong) UILabel *infoLabel;


@property (nonatomic) BOOL isFullscreenMode;

- (void)setIsRecordingIcon:(BOOL)isRec;
- (void)updateRecordTime:(NSTimeInterval)seconds;
- (void)setTitle:(NSString *)titleStr andSubtitle:(NSString *)subtitleStr;
//- (void)showBackButton:(BOOL)isShow;
//- (void)setTaskButtonTitle:(NSString *)btnTitle andEnable:(BOOL)btnEnabled;
- (void)setInfo:(NSString *)infoTitle;
- (void)setRecButtonRecordered:(BOOL)isRec andEnable:(BOOL)btnEnabled;
- (void)pushSubtask:(AffSubtaskObject *)subtask withIndex:(NSInteger)subtaskIndex fromTotal:(NSInteger)totalSubtasks;

- (void)showProgressHUDWithText:(NSString *)hudText;
- (void)changeHUDProgress:(float)progress;
- (void)showWaitHUDWithText:(NSString *)hudText;
- (void)hideHUD;


@end
