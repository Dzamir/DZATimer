//
//  RSTimerUtils.h
//  ReturnUtils
//
//  Created by Davide Di Stefano on 25/03/13.
//  Copyright (c) 2013 ReturnService. All rights reserved.
//

#import <Foundation/Foundation.h>

@class RSTimer;

@protocol RSTimerDelegate <NSObject>

-(void) timer:(RSTimer *) timer timeStepForElapsedTime:(NSTimeInterval) elapsedTime;
-(NSTimeInterval) timeStepForCallingEventForTimer:(RSTimer *) timer;

@end

@interface RSTimer : NSObject

-(id) init;
-(id) initWithDelegate:(id<RSTimerDelegate>) delegate;

-(void) startTimer;
-(void) pauseTimer;
-(void) stopTimer;

@property (nonatomic, readonly) NSTimeInterval elapsedTime;
@property (nonatomic, weak) id<RSTimerDelegate> delegate;

// returns up-time returned from the function mach_absolute_time. This value is dependent from the clock and can't be used directly  to show time
+(uint64_t) getMachAbsoluteTime;
// returns the difference in nanoseconds bewtween 2 machAbsoluteTimes
+(uint64_t) nanoSecondsBetweenStartMachAbsoluteTime:(uint64_t) startTime endMachAbsoluteTime:(uint64_t) endTime;

@end