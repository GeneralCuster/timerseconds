//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "UITableViewController.h"

@class MTStopwatchLapCell, NSMutableArray;

@interface MTStopwatchLapTableViewController : UITableViewController
{
    _Bool _showsCurrentLap;
    double _currentInterval;
    unsigned long long _cellStyle;
    double _previousLapsTotalInterval;
    NSMutableArray *_lapTimes;
    MTStopwatchLapCell *_currentLapCell;
    CDStruct_d2880215 _lapExtrema;
}

- (void).cxx_destruct;
- (void)_updateCurrentLapCell;
- (void)_updateLapExtrema;
- (void)addLap:(double)arg1;
@property(nonatomic) unsigned long long cellStyle; // @synthesize cellStyle=_cellStyle;
- (void)clearAllLaps;
@property(nonatomic) double currentInterval; // @synthesize currentInterval=_currentInterval;
@property(retain, nonatomic) MTStopwatchLapCell *currentLapCell; // @synthesize currentLapCell=_currentLapCell;
- (id)initWithStyle:(long long)arg1;
- (unsigned long long)lapCount;
@property(nonatomic) CDStruct_d2880215 lapExtrema; // @synthesize lapExtrema=_lapExtrema;
@property(retain, nonatomic) NSMutableArray *lapTimes; // @synthesize lapTimes=_lapTimes;
- (void)loadView;
- (long long)numberOfSectionsInTableView:(id)arg1;
@property(nonatomic) double previousLapsTotalInterval; // @synthesize previousLapsTotalInterval=_previousLapsTotalInterval;
- (double)runningTotalForLap:(long long)arg1;
- (void)setLaps:(id)arg1;
@property(nonatomic) _Bool showsCurrentLap; // @synthesize showsCurrentLap=_showsCurrentLap;
- (id)tableView:(id)arg1 cellForRowAtIndexPath:(id)arg2;
- (long long)tableView:(id)arg1 numberOfRowsInSection:(long long)arg2;

@end
