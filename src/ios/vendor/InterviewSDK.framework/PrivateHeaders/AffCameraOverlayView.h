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
@property (nonatomic, strong) UIView *landscapeStatusView;
@property (nonatomic, strong) UILabel *recTimeLabel;
@property (nonatomic, strong) UIView *taskView;
@property (nonatomic, strong) UIButton *oversizeTaskButton;
@property (nonatomic, strong) UIButton *taskButton;
@property (nonatomic, strong) UIScrollView *taskDescrScrollView;
@property (nonatomic, strong) UILabel *taskTitle;
@property (nonatomic, strong) UIImageView *taskImageView;

- (void)setIsRecordingIcon:(BOOL)isRec;
- (void)updateRecordTime:(NSTimeInterval)seconds;
- (void)setTitle:(NSString *)titleStr andSubtitle:(NSString *)subtitleStr;
- (void)showBackButton:(BOOL)isShow;
- (void)setTaskButtonTitle:(NSString *)btnTitle andEnable:(BOOL)btnEnabled;
- (void)pushSubtask:(AffSubtaskObject *)subtask withBackButton:(BOOL)isBackBtn;


@end
