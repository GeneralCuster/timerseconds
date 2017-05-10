//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "UINavigationController.h"

#import "MTSleepAlarmOnboardingDelegate.h"
#import "UIAdaptivePresentationControllerDelegate.h"

@class AddSheetNavigationController, NSString;

@interface MTSleepAlarmNavigationController : UINavigationController <MTSleepAlarmOnboardingDelegate, UIAdaptivePresentationControllerDelegate>
{
    AddSheetNavigationController *_presentedNavigationController;
}

- (void).cxx_destruct;
- (id)init;
- (void)presentSleepAlarmOnboarding;
- (void)presentationController:(id)arg1 willPresentWithAdaptiveStyle:(long long)arg2 transitionCoordinator:(id)arg3;
@property(retain, nonatomic) AddSheetNavigationController *presentedNavigationController; // @synthesize presentedNavigationController=_presentedNavigationController;
- (void)sleepAlarmOnboardingDidCancel;
- (void)sleepAlarmOnboardingDidCompleteWithSleepAlarm:(id)arg1;
- (void)updateNavigationBarForTraitCollection:(id)arg1;
- (void)viewDidLoad;
- (void)willTransitionToTraitCollection:(id)arg1 withTransitionCoordinator:(id)arg2;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

