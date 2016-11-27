//
//  AffTaskObject.h
//  Affidavit
//
//  Created by Eugine Korobovsky on 25.12.15.
//  Copyright © 2015 hintsolutions. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

typedef enum {
    InterviewSubtaskTypeDemo = 0,
    InterviewSubtaskTypeStatementRead,
    InterviewSubtaskTypePassport,
    InterviewSubtaskTypeSMSRead
} InterviewSubtaskType;

typedef enum : NSUInteger {
    InterviewSubtaskOverlayTypeVoid = 0,
    InterviewSubtaskOverlayTypePassport,
    InterviewSubtaskOverlayTypeFace
} InterviewSubtaskOverlayType;

typedef enum : NSUInteger {
    InterviewSubtaskWatermarkMaskNone        = 0,
    InterviewSubtaskWatermarkMaskDatetime    = 1,
    InterviewSubtaskWatermarkMaskGeo         = 1<<1
} InterviewSubtaskWatermarkMask;

typedef enum : NSUInteger {
    InterviewSubtaskPresentationStyleLandscape = 0,           // with left subtask view
    InterviewSubtaskPresentationStyleLandscapeFullscreen,     // for passport types
    InterviewSubtaskPresentationStylePortrait,                // portrait style with bottom subtask view
    InterviewSubtaskPresentationStylePortraitFullscreen       // portrait style for vertical documents
} InterviewSubtaskPresentationStyle;


@interface InterviewSubtaskObject : NSObject {
    
}

// -== Default initialization values ==-
// ______________________________________________________________________________
// |Parameter           |no type| Demo      | Statement | Passport  | SMS       |
// |--------------------|-------|-----------|-----------|-----------|------------
// | min time           | 0     | 0         | 10        | 5         | 5         |
// | max time           | 0     | 0         | 30        | 15        | 15        |
// | overlay            | void  | face      | face      | passport  | face      |
// | watermark          | -     | -         | time+geo  | geo       | time      |
// | camera position    | front | front     | front     | rear      | front     |
// | screenshots        | -     | -         | +         | +         | +         |
// | speech recognize   | -     | -         | en-US     | en-US     | en-US     |
// | presentation       | land  | port      | port      | land-full | land      |
// ------------------------------------------------------------------------------

- (id)init;
- (id)initWithType:(InterviewSubtaskType)type;

@property (nonatomic) InterviewSubtaskType taskType;
@property (nonatomic) InterviewSubtaskOverlayType overlayType;
@property (nonatomic) InterviewSubtaskPresentationStyle presentationStyle;
@property (nonatomic) NSTimeInterval minVideoDuration;
@property (nonatomic) NSTimeInterval maxVideoDuration;
@property (nonatomic, strong) NSString *preface;    // Title before 'Rec' button pressed. If nil => show title&subtitle immediately
@property (nonatomic, strong) NSString *title;
@property (nonatomic, strong) NSString *subtitle;
@property (nonatomic) InterviewSubtaskWatermarkMask watermark;
//@property (nonatomic) BOOL isAntimirror;    // == isRear
@property (nonatomic) BOOL isRear;
@property (nonatomic) BOOL isCatchScreenshots;
@property (nonatomic, strong) NSString *speechRecognizerLanguage;   // recognizer will not work when this property nil
@property (nonatomic) NSInteger order;

@property (nonatomic, strong) NSString *recognizedText;

- (UIImage *)getOverlayWithHighlight:(BOOL)isHighlight;
- (UIImage *)getTaskImage;
- (NSString *)mainButtonTextBeforeMinTime;
- (NSString *)reviewTitleForSubtask;
- (NSString *)reviewSubtitleForSubtask;

@end
