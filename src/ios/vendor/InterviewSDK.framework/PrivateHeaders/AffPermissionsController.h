//
//  AffPermissionsController.h
//  Affidavit
//
//  Created by Eugine Korobovsky on 22.12.15.
//  Copyright © 2015 hintsolutions. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <CoreLocation/CoreLocation.h>

typedef enum : NSUInteger {
    AffPermissionTypeNone         = 0,
    AffPermissionTypeVideo        = 1,
    AffPermissionTypeAudio        = 1<<1,
    AffPermissionTypeLocation     = 1<<2,
    AffPermissionTypeNotification = 1<<3
} AffPermissionType;

@interface AffPermissionsController : UIViewController <CLLocationManagerDelegate> {
    
}

@property (nonatomic, strong) IBOutlet UIImageView *backGroundImage;
@property (nonatomic, strong) IBOutlet UILabel *titleLabel;
@property (nonatomic, strong) IBOutlet UIButton *centerButton;

//@property (nonatomic) AffPermissionType requestedPermissions;

@end
