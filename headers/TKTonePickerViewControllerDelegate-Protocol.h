//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSNumber, NSString, TKTonePickerViewController, TKVibrationPickerViewController;

@protocol TKTonePickerViewControllerDelegate <NSObject>

@optional
- (void)tonePickerViewController:(TKTonePickerViewController *)arg1 didChangeIgnoreMute:(_Bool)arg2;
- (void)tonePickerViewController:(TKTonePickerViewController *)arg1 didDismissVibrationPickerViewController:(TKVibrationPickerViewController *)arg2;
- (void)tonePickerViewController:(TKTonePickerViewController *)arg1 selectedMediaItemWithIdentifier:(NSNumber *)arg2;
- (void)tonePickerViewController:(TKTonePickerViewController *)arg1 selectedToneWithIdentifier:(NSString *)arg2;
- (void)tonePickerViewController:(TKTonePickerViewController *)arg1 willPresentVibrationPickerViewController:(TKVibrationPickerViewController *)arg2;
@end

