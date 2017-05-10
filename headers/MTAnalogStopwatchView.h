//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "UIView.h"

@class MTAnalogStopwatchHandView, MTTimeView, NSNumberFormatter;

@interface MTAnalogStopwatchView : UIView
{
    double _elapsedTime;
    double _displayAdjustedElapsedTime;
    double _currentLapTime;
    MTAnalogStopwatchHandView *_minutesHand;
    MTAnalogStopwatchHandView *_secondsHand;
    MTAnalogStopwatchHandView *_lapSecondsHand;
    MTTimeView *_timeView;
    NSNumberFormatter *_numberFormatter;
}

- (void).cxx_destruct;
- (struct CGPoint)_minutesCircleCenter:(out double *)arg1;
@property(nonatomic) double currentLapTime; // @synthesize currentLapTime=_currentLapTime;
@property(nonatomic) double displayAdjustedElapsedTime; // @synthesize displayAdjustedElapsedTime=_displayAdjustedElapsedTime;
- (void)drawRect:(struct CGRect)arg1;
@property(nonatomic) double elapsedTime; // @synthesize elapsedTime=_elapsedTime;
- (void)handleLocaleChange;
- (id)initWithFrame:(struct CGRect)arg1;
@property(retain, nonatomic) MTAnalogStopwatchHandView *lapSecondsHand; // @synthesize lapSecondsHand=_lapSecondsHand;
- (void)layoutSubviews;
@property(retain, nonatomic) MTAnalogStopwatchHandView *minutesHand; // @synthesize minutesHand=_minutesHand;
@property(retain, nonatomic) NSNumberFormatter *numberFormatter; // @synthesize numberFormatter=_numberFormatter;
@property(retain, nonatomic) MTAnalogStopwatchHandView *secondsHand; // @synthesize secondsHand=_secondsHand;
@property(retain, nonatomic) MTTimeView *timeView; // @synthesize timeView=_timeView;

@end
