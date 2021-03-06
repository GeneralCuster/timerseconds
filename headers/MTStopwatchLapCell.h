//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "UITableViewCell.h"

@class NSArray, UIColor, UILabel;

@interface MTStopwatchLapCell : UITableViewCell
{
    long long _lap;
    double _time;
    unsigned long long _lapStyle;
    double _runningTotal;
    UIColor *_color;
    UILabel *_lapLabel;
    UILabel *_timeLabel;
    UILabel *_runningTotalLabel;
    NSArray *_layoutConstraints;
}

+ (void)ensureLapFormatter;
+ (void)handleLocaleChange;
+ (id)lapLabelTextForNumber:(long long)arg1;
+ (_Bool)na_supportsAutoLayout;
+ (void)resetLapFormatter;
- (void).cxx_destruct;
- (id)_accessibilityFormatTime:(double)arg1 showHours:(_Bool *)arg2 showSubseconds:(_Bool)arg3;
- (void)_updateForContentSizeChange;
@property(retain, nonatomic) UIColor *color; // @synthesize color=_color;
- (id)initWithStyle:(long long)arg1 reuseIdentifier:(id)arg2;
@property(nonatomic) long long lap; // @synthesize lap=_lap;
@property(retain, nonatomic) UILabel *lapLabel; // @synthesize lapLabel=_lapLabel;
@property(nonatomic) unsigned long long lapStyle; // @synthesize lapStyle=_lapStyle;
@property(retain, nonatomic) NSArray *layoutConstraints; // @synthesize layoutConstraints=_layoutConstraints;
- (void)layoutSubviews;
@property(nonatomic) double runningTotal; // @synthesize runningTotal=_runningTotal;
@property(retain, nonatomic) UILabel *runningTotalLabel; // @synthesize runningTotalLabel=_runningTotalLabel;
@property(nonatomic) double time; // @synthesize time=_time;
@property(retain, nonatomic) UILabel *timeLabel; // @synthesize timeLabel=_timeLabel;
- (void)updateConstraints;

@end

