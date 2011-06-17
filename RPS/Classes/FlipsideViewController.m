//
//  FlipsideViewController.m
//  RPS
//
//  Created by Martin on 3/19/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import "FlipsideViewController.h"
#import "MainViewController.h"


@implementation FlipsideViewController

@synthesize delegate, segmentedControl, mainController;


- (void)viewDidLoad {
    [super viewDidLoad];
    self.view.backgroundColor = [UIColor viewFlipsideBackgroundColor];
}

- (void)viewWillAppear:(BOOL)animated {
    segmentedControl.selectedSegmentIndex = [[NSUserDefaults standardUserDefaults] integerForKey:@"indexPoints"];
    if ([[NSUserDefaults standardUserDefaults] boolForKey:@"gameIsReset"]) segmentedControl.enabled = YES;
    else {
        segmentedControl.enabled = NO;
        UIAlertView * alertView = [[UIAlertView alloc] initWithTitle:@"RPS" message:@"Points cannot be changed during the game" delegate:nil cancelButtonTitle:@"OK" otherButtonTitles:nil];
        [alertView show];
        [alertView release];
    }
    [super viewWillAppear:animated];
}


- (IBAction)done:(id)sender {
	[self.delegate flipsideViewControllerDidFinish:self];
}

- (IBAction)segmentedControlValueChanged:(UIEvent *)event {
    [[NSUserDefaults standardUserDefaults] setInteger:segmentedControl.selectedSegmentIndex forKey:@"indexPoints"];
    if (segmentedControl.selectedSegmentIndex == 0) {
        [[NSUserDefaults standardUserDefaults] setInteger:1 forKey:@"reachablePoints"];
    }
    else if (segmentedControl.selectedSegmentIndex == 1) {
        [[NSUserDefaults standardUserDefaults] setInteger:3 forKey:@"reachablePoints"];
    }
    else {
        [[NSUserDefaults standardUserDefaults] setInteger:5 forKey:@"reachablePoints"];
    }
}

- (void)didReceiveMemoryWarning {
	// Releases the view if it doesn't have a superview.
    [super didReceiveMemoryWarning];
	
	// Release any cached data, images, etc that aren't in use.
}


- (void)viewDidUnload {
	// Release any retained subviews of the main view.
	// e.g. self.myOutlet = nil;
}


/*
// Override to allow orientations other than the default portrait orientation.
- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation {
	// Return YES for supported orientations
	return (interfaceOrientation == UIInterfaceOrientationPortrait);
}
*/


- (void)dealloc {
    [super dealloc];
    
    [mainController release];
    [segmentedControl release];
}


@end
