//
//  Macros.h
//  Affidavit
//
//  Created by Eugine Korobovsky on 23.12.15.
//  Copyright © 2015 hintsolutions. All rights reserved.
//

#ifndef Macros_h
#define Macros_h

#define PRINT_FRAME(str, frame)                     NSLog(@"%@: %.0f, %.0f, %.0f, %.0f", str, frame.origin.x, frame.origin.y, frame.size.width, frame.size.height)
#define PRINT_SIZE(str, size)                       NSLog(@"%@: %.0fx%.0f", str, size.width, size.height)
#define PRINT_POINT(str, point)                     NSLog(@"%@: (%.0f, %.0f)", str, point.x, point.y)

#define IOS_VER [[[UIDevice currentDevice] systemVersion] floatValue]
//#define IOS7 (IOS_VER>=7.0 ? YES : NO)
//#define IOS6 (IOS_VER>=6.0 ? YES : NO)
//#define IOS5 (IOS_VER>=5.0 ? YES : NO)

#define IS_RETINA_3_5 ([UIScreen mainScreen].bounds.size.height==480.0 ? YES : NO)
#define IS_RETINA_4 ([UIScreen mainScreen].bounds.size.height==568.0 ? YES : NO)
#define IS_RETINA_4_7 ([UIScreen mainScreen].bounds.size.height==667.0 ? YES : NO)
#define IS_RETINA_5_5 ([UIScreen mainScreen].bounds.size.height>700.0 ? YES : NO)

#define LONG_SCREEN_SIDE MAX([UIScreen mainScreen].bounds.size.width, [UIScreen mainScreen].bounds.size.height)
#define SHORT_SCREEN_SIDE MIN([UIScreen mainScreen].bounds.size.width, [UIScreen mainScreen].bounds.size.height)
#define SCREEN_RATIO (SHORT_SCREEN_SIDE/LONG_SCREEN_SIDE)

#define RGBA_COLOR(r, g, b, a) [UIColor colorWithRed:((float)r)/255.0 green:((float)g)/255.0 blue:((float)b)/255.0 alpha:(float)a]

#define degToRad(x) (M_PI * (x) / 180)

#define TRANSFORM_PORTRAIT   CGAffineTransformMakeRotation(0)
#define TRANSFORM_LANDLEFT   CGAffineTransformMakeRotation(M_PI/2)
#define TRANSFORM_LANDRIGHT  CGAffineTransformMakeRotation(-M_PI/2)
#define TRANSFORM_PORTRAITUP CGAffineTransformMakeRotation(M_PI)


#define kVideoEngineFragmentFinishedNotification @"VideoEngineFragmentFinished"
#define kVideoEngineExportSessionDidBeginCryptoNotification @"VideoEngineExportSessionDidBeginCryptoNotification"
#define kVideoEngineExportSessionDidChangeNotification @"VideoEngineExportSessionDidChangeNotification"
#define kVideoEngineExportSessionDidFinishNotification @"VideoEngineExportSessionDidFinishNotification"
#define kVideoEngineExportSessionDidFailNotification   @"VideoEngineExportSessionDidFailNotification"

// Colors
#define SDC_COLOR_BASE_GRAY RGBA_COLOR(49, 52, 58, 1.0)
#define SDC_COLOR_NAVBAR_TRANSLUCENT RGBA_COLOR(49, 52, 58, 0.5)
#define SDC_COLOR_ORANGE RGBA_COLOR(249, 90, 27, 1.0)
#define SDC_COLOR_NAVBAR_TEXT RGBA_COLOR(255, 255, 255, 1.0)

// Fonts
#define SDC_REGULAR_FONT_WITH_SIZE(sz) [UIFont fontWithName:@"HelveticaNeue" size:sz]
#define SDC_BOLD_FONT_WITH_SIZE(sz) [UIFont fontWithName:@"HelveticaNeue-Medium" size:sz]
#define SDC_LIGHT_FONT_WITH_SIZE(sz) [UIFont fontWithName:@"HelveticaNeue-Light" size:sz]
#define SDC_FONT_NAVBAR_TEXT [UIFont fontWithName:@"HelveticaNeue-Medium" size:16.0]

#define INTERVIEW_WAS_FINISHED_NOTIFICATION @"InterviewWasFinished"

#define INTERVIEW_BUNDLE [NSBundle bundleWithIdentifier:@"ru.hintsolutions.InterviewSDK"]
#define INTERVIEW_IMAGE_NAMED(x) [UIImage imageNamed:x inBundle:INTERVIEW_BUNDLE compatibleWithTraitCollection:nil]
#define INTERVIEW_STRING(key) [INTERVIEW_BUNDLE localizedStringForKey:(key) value:@"" table:nil]
//NSLocalizedStringFromTableInBundle(x, @"InterviewLocalizable.strings", INTERVIEW_BUNDLE, @"")

//#define VIDEO_THUMBNAIL_WIDTH 480.0

#define PerformSelectorLeakWarning(Stuff) \
    do { \
    _Pragma("clang diagnostic push") \
    _Pragma("clang diagnostic ignored \"-Warc-performSelector-leaks\"") \
    Stuff; \
    _Pragma("clang diagnostic pop") \
} while (0)


#endif /* Macros_h */
