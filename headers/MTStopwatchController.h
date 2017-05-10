//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class MTCircleButton;

@interface MTStopwatchController : NSObject
{
    int _mode;
    id <StopWatchControlsTarget> _target;
    MTCircleButton *_startStopButton;
    MTCircleButton *_lapControlButton;
}

- (void).cxx_destruct;
- (void)_lapControlButtonDown:(id)arg1;
- (void)_startStopButtonDown:(id)arg1;
- (id)initWithTarget:(id)arg1;
@property(readonly, nonatomic) MTCircleButton *lapControlButton; // @synthesize lapControlButton=_lapControlButton;
@property(nonatomic) int mode; // @synthesize mode=_mode;
- (void)setMode:(int)arg1 force:(_Bool)arg2;
@property(readonly, nonatomic) MTCircleButton *startStopButton; // @synthesize startStopButton=_startStopButton;
@property(readonly, nonatomic) __weak id <StopWatchControlsTarget> target; // @synthesize target=_target;

@end
