//
//  DZAViewController.m
//  DZATimer
//
//  Created by Davide Di Stefano on 06/08/2015.
//  Copyright (c) 2014 Davide Di Stefano. All rights reserved.
//

#import "DZAViewController.h"

@interface DZAViewController ()
@property (weak, nonatomic) IBOutlet UIButton *playButton;
@property (weak, nonatomic) IBOutlet UILabel *timerLabel;
@property (strong, nonatomic) DZATimer * timer;
@end

@implementation DZAViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    _timer = [[DZATimer alloc] initWithDelegate:self];
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (IBAction)playPauseTouchUpInside:(id)sender
{
    if (!_timer.isPlaying)
    {
        [_timer startTimer];
    } else
    {
        [_timer pauseTimer];
    }
    [self updateUI];
}

- (IBAction)stopTouchUpInside:(id)sender
{
    [_timer stopTimer];
    [self updateUI];
}

-(void) updateUI
{
    if (_timer.isPlaying)
    {
        [_playButton setTitle:@"Pause" forState:UIControlStateNormal];
    } else
    {
        [_playButton setTitle:@"Play" forState:UIControlStateNormal];
    }
}

// this method is called at each timestep
-(void) timer:(DZATimer *) timer timeStepForElapsedTime:(NSTimeInterval) elapsedTime;
{
    _timerLabel.text = [NSString stringWithFormat:@"%0.2f sec", _timer.elapsedTime];
}

// it must returns how long is a timestep
-(NSTimeInterval) timeStepForCallingEventForTimer:(DZATimer *) timer;
{
    return 0.01;
}

@end
