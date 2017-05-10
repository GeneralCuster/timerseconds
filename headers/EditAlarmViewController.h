//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "UIViewController.h"

#import "UITableViewDataSource.h"
#import "UITableViewDelegate.h"

@class Alarm, EditAlarmView, NSString;

@interface EditAlarmViewController : UIViewController <UITableViewDataSource, UITableViewDelegate>
{
    EditAlarmView *_editAlarmView;
    _Bool _edited;
    _Bool _editingFinished;
    _Bool _newAlarm;
    Alarm *_alarm;
    long long _editingAlarmSetting;
    id <EditAlarmViewControllerDelegate> _delegate;
}

+ (struct CGSize)desiredContentSize;
- (void).cxx_destruct;
- (void)_cancelButtonClicked:(id)arg1;
- (void)_doneButtonClicked:(id)arg1;
- (void)_snoozeControlChanged:(id)arg1;
@property(readonly, nonatomic) Alarm *alarm; // @synthesize alarm=_alarm;
- (void)dealloc;
@property(nonatomic) __weak id <EditAlarmViewControllerDelegate> delegate; // @synthesize delegate=_delegate;
- (void)handlePickerChanged;
- (void)handleSuspend;
- (id)initWithAlarm:(id)arg1;
- (void)loadView;
- (void)markAsEdited;
- (long long)numberOfSectionsInTableView:(id)arg1;
- (void)saveAlarmOnlyIfEdited:(_Bool)arg1;
- (void)startEditingSetting:(long long)arg1;
- (unsigned long long)supportedInterfaceOrientations;
- (id)tableView:(id)arg1 cellForRowAtIndexPath:(id)arg2;
- (void)tableView:(id)arg1 didSelectRowAtIndexPath:(id)arg2;
- (long long)tableView:(id)arg1 numberOfRowsInSection:(long long)arg2;
- (id)tonePickerCellForTableView:(id)arg1;
- (void)viewDidUnload;
- (void)viewWillAppear:(_Bool)arg1;
- (void)willTransitionToTraitCollection:(id)arg1 withTransitionCoordinator:(id)arg2;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end
