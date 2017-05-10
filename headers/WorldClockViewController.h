//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "TableViewController.h"

#import "AddClockViewControllerDelegate.h"
#import "StateManagement.h"

@class NSUserActivity;

@interface WorldClockViewController : TableViewController <StateManagement, AddClockViewControllerDelegate>
{
    NSUserActivity *_userActivity;
}

- (void).cxx_destruct;
- (void)addClockViewController:(id)arg1 addCity:(id)arg2;
- (id)addViewController;
- (id)init;
- (float)itemsTableRowHeight;
- (void)loadView;
- (id)noItemsText;
- (long long)numberOfItems;
- (void)reloadState;
- (void)saveScrollPoint;
- (void)saveState;
- (void)showAddView;
- (id)tableView:(id)arg1 cellForRowAtIndexPath:(id)arg2;
- (void)tableView:(id)arg1 commitEditingStyle:(long long)arg2 forRowAtIndexPath:(id)arg3;
- (void)tableView:(id)arg1 moveRowAtIndexPath:(id)arg2 toIndexPath:(id)arg3;
- (void)viewDidAppear:(_Bool)arg1;
- (void)viewWillAppear:(_Bool)arg1;
- (void)viewWillDisappear:(_Bool)arg1;

@end

