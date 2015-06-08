//
//  DzaTimer.h
//
//  Created by Davide Di Stefano on 25/03/13.
//  Copyright (c) 2013 ReturnService. All rights reserved.
//

#import <Foundation/Foundation.h>

@class DZATimer;

@protocol DZATimerDelegate <NSObject>

// this method is called at each timestep
-(void) timer:(DZATimer *) timer timeStepForElapsedTime:(NSTimeInterval) elapsedTime;

// it must returns how long is a timestep
-(NSTimeInterval) timeStepForCallingEventForTimer:(DZATimer *) timer;

@end

@interface DZATimer : NSObject

-(id) init;
// init with a delegate that will be called at each timestep
-(id) initWithDelegate:(id<DZATimerDelegate>) delegate;

// starts the timer
-(void) startTimer;
// pauses the timer
-(void) pauseTimer;
// stops the timer and resets the elapsedTime
-(NSTimeInterval) stopTimer;

// elapsed time from the start time
@property (nonatomic, readonly) NSTimeInterval elapsedTime;
// delegate object to call at each timestep
@property (nonatomic, weak) id<DZATimerDelegate> delegate;
@property (nonatomic, readonly) BOOL isPlaying;

// returns up-time returned from the function mach_absolute_time. This value is dependent from the clock and can't be used directly to show time
+(uint64_t) getMachAbsoluteTime;
// returns the difference in nanoseconds bewtween 2 machAbsoluteTimes
+(uint64_t) nanoSecondsBetweenStartMachAbsoluteTime:(uint64_t) startTime endMachAbsoluteTime:(uint64_t) endTime;

@end