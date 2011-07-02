//
//  MessageNotificationController.h
//  iPhoneXMPP
//
//  Created by Martin Goffan on 6/15/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "MainViewController.h"

@class MainViewController;

@interface MessageNotificationController : UIViewController {
    IBOutlet UILabel *lMessage;
    IBOutlet UIImageView *winnerLooserImageView;
    IBOutlet UIButton *shareButton;
    NSString *myMessage;
}

@property (nonatomic, retain) IBOutlet UILabel *lMessage;
@property (nonatomic, retain) IBOutlet UIImageView *winnerLooserImageView;
@property (nonatomic, retain) NSString *myMessage;
@property (nonatomic, retain) IBOutlet UIButton *shareButton;

@property (nonatomic, retain) MainViewController *mainController;

- (void)image:(UIImage *)anImage;
- (IBAction)share:(id)sender;

@end
