//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "UIView.h"

#import "UITableViewDataSource.h"
#import "UITableViewDelegate.h"

@class MTTimerButtonsController, MTTimerPickerCell, NSString, TimerTimeView, UIButton, UIDatePicker, UITableView, UITableViewCell;

@interface TimerControlsView : UIView <UITableViewDataSource, UITableViewDelegate>
{
    TimerTimeView *_timeView;
    UIDatePicker *_timePicker;
    UITableView *_tableView;
    MTTimerPickerCell *_pickerCell;
    UITableViewCell *_toneChooserCell;
    UIButton *_toneButton;
    NSString *_toneName;
    MTTimerButtonsController *_buttonsController;
    int _style;
    id <TimerControlsTarget> _delegate;
    int _state;
    double _topLayoutGuideLength;
    double _bottomLayoutGuideLength;
}

- (void).cxx_destruct;
- (void)_configureAndAddButton:(id)arg1;
@property(nonatomic) double bottomLayoutGuideLength; // @synthesize bottomLayoutGuideLength=_bottomLayoutGuideLength;
@property(nonatomic) double countDownDuration;
- (void)handleLocaleChange;
- (id)initWithDelegate:(id)arg1 style:(int)arg2;
- (void)layoutSubviews;
- (void)setButtonSize:(unsigned long long)arg1;
@property(nonatomic) int state; // @synthesize state=_state;
- (void)setState:(int)arg1 animate:(_Bool)arg2;
@property(nonatomic) int style; // @synthesize style=_style;
- (void)setTime:(double)arg1;
- (void)setTimerToneName:(id)arg1;
@property(nonatomic) double topLayoutGuideLength; // @synthesize topLayoutGuideLength=_topLayoutGuideLength;
- (id)tableView:(id)arg1 cellForRowAtIndexPath:(id)arg2;
- (void)tableView:(id)arg1 didSelectRowAtIndexPath:(id)arg2;
- (double)tableView:(id)arg1 heightForRowAtIndexPath:(id)arg2;
- (long long)tableView:(id)arg1 numberOfRowsInSection:(long long)arg2;
- (_Bool)tableView:(id)arg1 shouldHighlightRowAtIndexPath:(id)arg2;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end
