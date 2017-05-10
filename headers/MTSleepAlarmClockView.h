//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "UIControl.h"

#import "UIGestureRecognizerDelegate.h"

@class CADisplayLink, NSDateComponents, NSLayoutConstraint, NSNumberFormatter, NSString, UILabel, UILongPressGestureRecognizer;

@interface MTSleepAlarmClockView : UIControl <UIGestureRecognizerDelegate>
{
    _Bool _draggingSleep;
    _Bool _draggingWake;
    _Bool _draggingArc;
    UILongPressGestureRecognizer *_dragRecognizer;
    unsigned long long _style;
    NSDateComponents *_sleepTime;
    NSDateComponents *_wakeTime;
    double _zoomedHourSize;
    UILabel *_sleepHoursLabel;
    long long _zoomedHour;
    double _zoomStartAngle;
    unsigned long long _dragAndHoldCounter;
    double _lastDragAngle;
    double _dragSleepAngleOffset;
    double _dragWakeAngleOffset;
    CADisplayLink *_displayLink;
    NSNumberFormatter *_hourNumberFormatter;
    NSLayoutConstraint *_sleepLabelLeadingConstraint;
    NSLayoutConstraint *_sleepLabelTrailingConstraint;
}

- (void).cxx_destruct;
- (struct CGPoint)_centerPointAtAngle:(double)arg1;
- (CDStruct_d83abbfb)_currentDrawingProperties;
- (_Bool)_endCircleContainsPoint:(struct CGPoint)arg1;
- (void)_endDragging;
- (id)_newTimeForAngle:(double)arg1 isWake:(_Bool)arg2;
- (_Bool)_sleepArcContainsPoint:(struct CGPoint)arg1;
- (_Bool)_startCircleContainsPoint:(struct CGPoint)arg1;
- (double)angleForHour:(long long)arg1 minute:(long long)arg2;
- (_Bool)angleIsDuringSleep:(double)arg1;
- (id)clampTimeToZoomedHour:(id)arg1;
@property(retain, nonatomic) CADisplayLink *displayLink; // @synthesize displayLink=_displayLink;
- (void)displayLinkTick:(id)arg1;
@property(nonatomic) unsigned long long dragAndHoldCounter; // @synthesize dragAndHoldCounter=_dragAndHoldCounter;
- (void)dragCancelled:(id)arg1;
- (void)dragEnded:(id)arg1;
- (void)dragMoved:(id)arg1;
@property(retain, nonatomic) UILongPressGestureRecognizer *dragRecognizer; // @synthesize dragRecognizer=_dragRecognizer;
- (void)dragRecognizerChanged:(id)arg1;
@property(nonatomic) double dragSleepAngleOffset; // @synthesize dragSleepAngleOffset=_dragSleepAngleOffset;
- (void)dragStarted:(id)arg1;
@property(nonatomic) double dragWakeAngleOffset; // @synthesize dragWakeAngleOffset=_dragWakeAngleOffset;
- (void)drawRect:(struct CGRect)arg1;
- (_Bool)gestureRecognizer:(id)arg1 shouldReceiveTouch:(id)arg2;
- (void)handleLocaleChange;
@property(retain, nonatomic) NSNumberFormatter *hourNumberFormatter; // @synthesize hourNumberFormatter=_hourNumberFormatter;
- (id)initWithFrame:(struct CGRect)arg1;
@property(nonatomic, getter=isDraggingArc) _Bool draggingArc; // @synthesize draggingArc=_draggingArc;
@property(nonatomic, getter=isDraggingSleep) _Bool draggingSleep; // @synthesize draggingSleep=_draggingSleep;
@property(nonatomic, getter=isDraggingWake) _Bool draggingWake; // @synthesize draggingWake=_draggingWake;
@property(nonatomic) double lastDragAngle; // @synthesize lastDragAngle=_lastDragAngle;
@property(readonly, nonatomic) double nonzoomedHourSize;
- (double)ringWidth;
- (void)setEnabled:(_Bool)arg1;
@property(retain, nonatomic) UILabel *sleepHoursLabel; // @synthesize sleepHoursLabel=_sleepHoursLabel;
@property(retain, nonatomic) NSLayoutConstraint *sleepLabelLeadingConstraint; // @synthesize sleepLabelLeadingConstraint=_sleepLabelLeadingConstraint;
@property(retain, nonatomic) NSLayoutConstraint *sleepLabelTrailingConstraint; // @synthesize sleepLabelTrailingConstraint=_sleepLabelTrailingConstraint;
@property(copy, nonatomic) NSDateComponents *sleepTime; // @synthesize sleepTime=_sleepTime;
@property(nonatomic) unsigned long long style; // @synthesize style=_style;
@property(copy, nonatomic) NSDateComponents *wakeTime; // @synthesize wakeTime=_wakeTime;
@property(nonatomic) double zoomStartAngle; // @synthesize zoomStartAngle=_zoomStartAngle;
@property(nonatomic) long long zoomedHour; // @synthesize zoomedHour=_zoomedHour;
@property(nonatomic) double zoomedHourSize; // @synthesize zoomedHourSize=_zoomedHourSize;
- (void)setupConstraints;
@property(readonly, nonatomic) double sleepAngle;
- (struct CGPoint)sleepCenter;
- (double)sleepLength;
- (double)standardAngleForHour:(long long)arg1 minute:(long long)arg2;
- (id)standardTimeForAngle:(double)arg1;
- (id)timeForAngle:(double)arg1;
- (void)updateCenterLabels;
- (void)updateConstraints;
@property(readonly, nonatomic) double wakeAngle;
- (struct CGPoint)wakeCenter;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

