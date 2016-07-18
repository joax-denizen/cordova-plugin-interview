//
//  ViewController.h
//  Affidavit
//
//  Created by Eugine Korobovsky on 22.12.15.
//  Copyright © 2015 hintsolutions. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface AffStartController : UIViewController {
    
}

//@property (nonatomic, strong) IBOutlet UIActivityIndicatorView *actInd;
@property (nonatomic, strong) IBOutlet UIImageView *backgroundImage;
@property (nonatomic, strong) IBOutlet UILabel *titleLabel;
@property (nonatomic, strong) IBOutlet UIButton *reloadTaskButton;
@property (nonatomic, strong) IBOutlet NSLayoutConstraint *rightConstraint;

- (void)stopCurrentLoading;
- (void)startNewSession;


@end

