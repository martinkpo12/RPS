//
//  MainViewController.h
//  RPS
//
//  Created by Martin on 3/19/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import "FlipsideViewController.h"

#import <AVFoundation/AVFoundation.h>
#import <AudioToolbox/AudioToolbox.h>

#import "MessageNotificationController.h"
#import "LoginViewController.h"

#import "SHK.h"
#import "SHKFacebook.h"

#import "LocalizedStrings.h"

#define iPad                    ([UIScreen mainScreen].bounds.size.height == 1024)

#define kAnimationDurationShow  2.0
#define kAnimationDurationHide  0.75

#define VIEW_WIDTH              self.view.bounds.size.width
#define VIEW_HEIGHT             self.view.bounds.size.height
#define NOTIFICATION_WIDTH      newNotification.view.frame.size.width
#define NOTIFICATION_HEIGHT     newNotification.view.frame.size.height

@class MessageNotificationController;
@class LoginViewController;

@interface MainViewController : UIViewController <FlipsideViewControllerDelegate> {
	IBOutlet UIImageView            *firstPlayerImageView;
	IBOutlet UIImageView            *COMImageView;
	IBOutlet UISegmentedControl     *segmentControl;
    IBOutlet UILabel                *scoreboard;
    IBOutlet UILabel                *currentResult;
    IBOutlet UILabel                *appTitle;
    IBOutlet UIButton               *buttonThrow;
    
	FlipsideViewController          *optionsController;
    MessageNotificationController   *newNotification;
    LoginViewController             *loginViewController;
    
    NSInteger                       playerPoints;
    NSInteger                       iDevicePoints;
    NSInteger                       reachablePoints;
    BOOL                            gameIsReset;
    BOOL                            userDidWin;
    
    AVAudioPlayer                   *audioPlayer;
}

@property (nonatomic, retain) IBOutlet UIImageView          *firstPlayerImageView;
@property (nonatomic, retain) IBOutlet UIImageView          *COMImageView;
@property (nonatomic, retain) IBOutlet UISegmentedControl   *segmentControl;
@property (nonatomic, retain) IBOutlet UILabel              *scoreboard;
@property (nonatomic, retain) IBOutlet UILabel              *appTitle;
@property (nonatomic, retain) IBOutlet UILabel              *currentResult;
@property (nonatomic, retain) IBOutlet UIButton             *buttonThrow;

@property (nonatomic, retain) FlipsideViewController        *optionsController;
@property (nonatomic, retain, getter = newNotification) MessageNotificationController *newNotification;

@property (nonatomic, retain) AVAudioPlayer *audioPlayer;

- (IBAction)showInfo:(id)sender;
- (IBAction)play:(id)sender;
- (void)share;

- (void)setupUserInterface;
- (void)setupNotifications;
- (void)setupGameSound;
- (void)setupGameLogic;
- (void)setupLogin;


@end
