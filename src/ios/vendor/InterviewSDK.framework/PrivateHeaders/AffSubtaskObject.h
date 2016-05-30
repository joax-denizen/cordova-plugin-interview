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
    AffSubtaskTypeDemo = 0,
    AffSubtaskTypeSMSRead,
    AffSubtaskTypeStatementRead,
    AffSubtaskTypePassport
} AffSubtaskType;

typedef enum : NSUInteger {
    AffSubtaskOverlayTypeVoid = 0,
    AffSubtaskOverlayTypePassport,
    AffSubtaskOverlayTypeFace
} AffSubtaskOverlayType;

typedef enum : NSUInteger {
    AffSubtaskWatermarkMaskNone        = 0,
    AffSubtaskWatermarkMaskDatetime    = 1,
    AffSubtaskWatermarkMaskGeo         = 1<<1
} AffSubtaskWatermarkMask;


@interface AffSubtaskObject : NSObject {
    
}

- (id)init;
- (id)initWithType:(AffSubtaskType)type;

@property (nonatomic) AffSubtaskType taskType;
@property (nonatomic) AffSubtaskOverlayType overlayType;
@property (nonatomic) NSTimeInterval minVideoDuration;
@property (nonatomic) NSTimeInterval maxVideoDuration;
@property (nonatomic, strong) NSString *title;
@property (nonatomic, strong) NSString *subtitle;
@property (nonatomic) AffSubtaskWatermarkMask watermark;
@property (nonatomic) BOOL isAntimirror;
@property (nonatomic) BOOL isRear;
@property (nonatomic) BOOL isCatchScreenshots;
@property (nonatomic) NSInteger order;

- (UIImage *)getOverlay;
- (UIImage *)getTaskImage;
- (NSString *)mainButtonTextBeforeMinTime;

@end
