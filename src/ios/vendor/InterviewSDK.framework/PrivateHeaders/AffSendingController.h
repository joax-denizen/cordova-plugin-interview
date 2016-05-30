//
//  AffSendingController.h
//  Affidavit
//
//  Created by Eugine Korobovsky on 30.12.15.
//  Copyright © 2015 hintsolutions. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "AffTaskObject.h"

@interface AffSendingController : UIViewController {
    
}

@property (nonatomic, strong) AffTaskObject *task;

@property (nonatomic, strong) IBOutlet UIImageView *backgroundImage;
@property (nonatomic, strong) IBOutlet UILabel *sendingLabel;

@end
