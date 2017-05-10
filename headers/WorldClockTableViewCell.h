//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "UITableViewCell.h"

#import "WorldClockCellViewDelegate.h"

@class NSString, WorldClockCellView, WorldClockCity;

@interface WorldClockTableViewCell : UITableViewCell <WorldClockCellViewDelegate>
{
    WorldClockCity *_city;
    WorldClockCellView *_clockCellView;
}

+ (float)defaultHeight;
- (void).cxx_destruct;
@property(retain, nonatomic) WorldClockCity *city; // @synthesize city=_city;
@property(readonly, nonatomic) WorldClockCellView *clockCellView; // @synthesize clockCellView=_clockCellView;
- (void)dealloc;
- (id)init;
- (id)initWithStyle:(long long)arg1 reuseIdentifier:(id)arg2;
- (void)prepareForReuse;
- (void)setEditing:(_Bool)arg1 animated:(_Bool)arg2;
- (void)setupConstraints;
- (void)timeDidChangeForClockCell:(id)arg1;
- (void)willTransitionToState:(unsigned long long)arg1;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

