//  Picker.h
//  UIPicker
//
//  Created by Matthew on 5/7/17.
//  Copyright © 2017 MatthewCuster, Matthew. All rights reserved.
//

#import <UIKit/UIKit.h>
//#import "headers/TimerControlsView.h"

@interface SecondsPicker : UIPickerView <UIPickerViewDelegate, UIPickerViewDataSource>{

    UIPickerView *pickMe; //The picker view
    UILabel *hourLabel;
    UILabel *minsLabel;
    UILabel *secsLabel;

}

@property(nonatomic, retain) UIPickerView *pickMe;
@property(nonatomic, retain) UILabel *hourLabel, *minsLabel, *secsLabel;

// returns the number of 'columns' to display.
- (NSInteger)numberOfComponentsInPickerView:(UIPickerView *)pickerView;

// returns the # of rows in each component..
- (NSInteger)pickerView:(UIPickerView *)pickerView numberOfRowsInComponent:(NSInteger)component;

- (CGFloat)pickerView:(UIPickerView *)pickerView rowHeightForComponent:(NSInteger)component;

- (UIView *)pickerView:(UIPickerView *)pickerView viewForRow:(NSInteger)row forComponent:(NSInteger)component reusingView:(UIView *)view;
@end
