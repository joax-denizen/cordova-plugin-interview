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
@property (nonatomic, strong) IBOutlet NSLayoutConstraint *bottomBtnConstraint;

@property (nonatomic, strong) NSDictionary *taskResult;

@end
