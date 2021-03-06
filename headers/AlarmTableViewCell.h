//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "UITableViewCell.h"

@class AlarmView, UISwitch;

@interface AlarmTableViewCell : UITableViewCell
{
    id <AlarmActiveDelegate> _alarmActiveDelegate;
    AlarmView *_alarmView;
    _Bool _enabled;
    UISwitch *_enabledSwitch;
}

- (void).cxx_destruct;
- (void)_alarmActiveChanged:(id)arg1;
@property(retain, nonatomic) UISwitch *enabledSwitch; // @synthesize enabledSwitch=_enabledSwitch;
- (id)init;
- (id)initWithStyle:(long long)arg1 reuseIdentifier:(id)arg2;
- (void)internalSetBackgroundColor:(id)arg1;
- (void)refreshUI:(id)arg1 animated:(_Bool)arg2;
- (void)setAlarmActiveDelegate:(id)arg1;
- (void)setBackgroundColor:(id)arg1;
- (void)setEditing:(_Bool)arg1 animated:(_Bool)arg2;
- (void)setHighlighted:(_Bool)arg1 animated:(_Bool)arg2;
- (void)setSelected:(_Bool)arg1 animated:(_Bool)arg2;
- (void)setupAsTemplateLayoutCell:(_Bool)arg1;
- (void)willTransitionToState:(unsigned long long)arg1;

@end

