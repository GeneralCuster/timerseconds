//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "UIView.h"

@class NSDate, NSDateFormatter, NSMutableDictionary, NSTimer, UIImage, UIImageView, WorldClockMapCityView;

@interface WorldClockMapView : UIView
{
    NSMutableDictionary *_cityViews;
    WorldClockMapCityView *_addedCityView;
    NSDateFormatter *_timeFormatter;
    double _maxTimeStringWidth;
    UIImageView *_mapWithTerminator;
    UIImage *_terminatorImages[1];
    NSDate *_terminatorTimestamp;
    NSTimer *_terminatorTimer;
    struct CGRect _lastTerminatorUpdateBounds;
    _Bool _needsUpdateTerminator;
}

+ (void)updateNewYearsDay;
- (void).cxx_destruct;
- (void)addCity:(id)arg1;
- (void)addCity:(id)arg1 animated:(_Bool)arg2;
- (void)cancelTerminatorUpdate;
- (void)didMoveToWindow;
- (void)handleLocaleChange;
- (void)handleSignificantTimeChange:(id)arg1;
- (id)initWithFrame:(struct CGRect)arg1;
- (void)layoutSubviews;
- (double)maxWidthForDateStringWithFont:(id)arg1;
- (void)removeCity:(id)arg1;
- (void)resizeCityViews;
- (void)scheduleTerminatorUpdate;
- (void)setCities:(id)arg1;
- (struct CGSize)sizeThatFits:(struct CGSize)arg1;
- (void)startUpdatingTime;
- (void)stopUpdatingTime;
- (id)terminatorPathForDayOfYear:(double)arg1 size:(struct CGSize)arg2;
- (double)terminatorUpdateInterval;
- (void)updateTerminator;
- (void)viewWillTransitionToSize:(struct CGSize)arg1 withTransitionCoordinator:(id)arg2;

@end

