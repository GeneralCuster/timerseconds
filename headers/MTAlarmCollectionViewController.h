//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "UICollectionViewController.h"

#import "AlarmDelegate.h"
#import "AlarmManagerObserver.h"
#import "EditAlarmViewControllerDelegate.h"
#import "MTAlarmCollectionCellDelegate.h"
#import "StateManagement.h"
#import "UICollectionViewDelegateFlowLayout.h"
#import "UIPopoverPresentationControllerDelegate.h"

@class EditAlarmViewController, MTAlarmCollectionCell, NSString, NSUserActivity, _UIContentUnavailableView;

@interface MTAlarmCollectionViewController : UICollectionViewController <AlarmDelegate, AlarmManagerObserver, EditAlarmViewControllerDelegate, MTAlarmCollectionCellDelegate, UICollectionViewDelegateFlowLayout, UIPopoverPresentationControllerDelegate, StateManagement>
{
    double _cellHeight;
    EditAlarmViewController *_addEditAlarmController;
    MTAlarmCollectionCell *_sizingCell;
    _UIContentUnavailableView *_noItemsView;
    NSUserActivity *_userActivity;
}

- (void).cxx_destruct;
- (void)_addOrEditControllerDidDismissCommitChanges:(_Bool)arg1;
- (void)_handleNumberOfItemsDidChange;
- (void)_layoutNoItemsLabel;
- (void)addAlarm:(id)arg1;
@property(retain, nonatomic) EditAlarmViewController *addEditAlarmController; // @synthesize addEditAlarmController=_addEditAlarmController;
- (void)alarmDidUpdate:(id)arg1;
- (void)alarmManagerDidUpdateAlarms:(id)arg1;
@property(readonly, nonatomic) double cellHeight; // @synthesize cellHeight=_cellHeight;
- (id)collectionView:(id)arg1 cellForItemAtIndexPath:(id)arg2;
- (void)collectionView:(id)arg1 didEndDisplayingCell:(id)arg2 forItemAtIndexPath:(id)arg3;
- (void)collectionView:(id)arg1 didSelectItemAtIndexPath:(id)arg2;
- (struct UIEdgeInsets)collectionView:(id)arg1 layout:(id)arg2 insetForSectionAtIndex:(long long)arg3;
- (double)collectionView:(id)arg1 layout:(id)arg2 minimumInteritemSpacingForSectionAtIndex:(long long)arg3;
- (double)collectionView:(id)arg1 layout:(id)arg2 minimumLineSpacingForSectionAtIndex:(long long)arg3;
- (struct CGSize)collectionView:(id)arg1 layout:(id)arg2 sizeForItemAtIndexPath:(id)arg3;
- (long long)collectionView:(id)arg1 numberOfItemsInSection:(long long)arg2;
- (_Bool)collectionView:(id)arg1 shouldSelectItemAtIndexPath:(id)arg2;
- (void)collectionView:(id)arg1 willDisplayCell:(id)arg2 forItemAtIndexPath:(id)arg3;
- (void)deleteCell:(id)arg1;
- (void)didDeleteAlarm:(id)arg1;
- (void)didEditAlarm:(id)arg1;
- (void)dismissAddViewController:(id)arg1;
- (void)handleContentSizeChange:(id)arg1;
- (id)init;
@property(retain, nonatomic) _UIContentUnavailableView *noItemsView; // @synthesize noItemsView=_noItemsView;
- (void)popoverPresentationControllerDidDismissPopover:(id)arg1;
- (void)reloadState;
- (void)removeAlarmAtIndexPath:(id)arg1;
- (void)saveState;
- (void)setAlarmEnabled:(_Bool)arg1 forCell:(id)arg2;
- (void)setEditing:(_Bool)arg1 animated:(_Bool)arg2;
@property(retain, nonatomic) MTAlarmCollectionCell *sizingCell; // @synthesize sizingCell=_sizingCell;
@property(retain, nonatomic) NSUserActivity *userActivity; // @synthesize userActivity=_userActivity;
- (void)viewDidAppear:(_Bool)arg1;
- (void)viewDidLayoutSubviews;
- (void)viewDidLoad;
- (void)viewWillAppear:(_Bool)arg1;
- (void)viewWillTransitionToSize:(struct CGSize)arg1 withTransitionCoordinator:(id)arg2;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end
