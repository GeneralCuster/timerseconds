//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "UICollectionViewCell.h"

@class MTWorldClockView, UIButton, WorldClockCity;

@interface WorldClockCollectionCell : UICollectionViewCell
{
    _Bool _editing;
    id <WorldClockCollectionCellDelegate> _delegate;
    UIButton *_deleteButton;
    WorldClockCity *_city;
    MTWorldClockView *_worldClockView;
}

- (void).cxx_destruct;
@property(retain, nonatomic) WorldClockCity *city; // @synthesize city=_city;
@property(nonatomic) __weak id <WorldClockCollectionCellDelegate> delegate; // @synthesize delegate=_delegate;
@property(retain, nonatomic) UIButton *deleteButton; // @synthesize deleteButton=_deleteButton;
- (void)deleteTapped:(id)arg1;
- (id)initWithFrame:(struct CGRect)arg1;
@property(nonatomic, getter=isEditing) _Bool editing; // @synthesize editing=_editing;
- (void)setEditing:(_Bool)arg1 animated:(_Bool)arg2;
@property(retain, nonatomic) MTWorldClockView *worldClockView; // @synthesize worldClockView=_worldClockView;
- (void)setupConstraints;
- (void)start;
- (void)stop;

@end

