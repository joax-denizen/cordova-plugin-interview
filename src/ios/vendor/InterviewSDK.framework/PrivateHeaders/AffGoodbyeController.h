//
//  AffGoodbyeController.h
//  Affidavit
//
//  Created by Eugine Korobovsky on 24.12.15.
//  Copyright © 2015 hintsolutions. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface AffGoodbyeController : UIViewController{
    
}

@property (nonatomic, strong) IBOutlet UIImageView *backGroundImage;
@property (nonatomic, strong) IBOutlet UILabel *titleLabel;
@property (nonatomic, strong) IBOutlet UIButton *restartButton;
@property (nonatomic, strong) IBOutlet UIButton *reloadBtn;
@property (nonatomic, strong) IBOutlet NSLayoutConstraint *bottomRightBtnConstraint;
@property (nonatomic, strong) IBOutlet NSLayoutConstraint *widthRightBtnConstraint;
@property (nonatomic, strong) IBOutlet NSLayoutConstraint *bottomLeftBtnConstraint;
@property (nonatomic, strong) IBOutlet NSLayoutConstraint *widthLeftBtnConstraint;
@property (nonatomic, strong) IBOutlet NSLayoutConstraint *rightConstraint;

@property (nonatomic, strong) NSDictionary *taskResult;

@end
