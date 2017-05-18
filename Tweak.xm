#import <substrate.h> //used for MSHookIvar
#import <Foundation/Foundation.h>
//#import "picker.h"

/**
Interface all the things so that I can reference their stuff later
**/
//@class SecondsPicker;

@interface TimerControlsView : UIView {
  UIDatePicker *_timePicker;
}
@end

@interface TimerViewController : UIViewController {
  TimerControlsView *_timerControlsView;
  NSTimer *_timer;
  double _time;
}
- (void)loadView;
@end

@interface pickerDel : UIViewController <UIPickerViewDataSource, UIPickerViewDelegate>
- (NSInteger)numberOfComponentsInPickerView:(UIPickerView *)pickerView;
- (NSInteger)pickerView:(UIPickerView *)pickerView numberOfRowsInComponent:(NSInteger)component;
- (CGFloat)pickerView:(UIPickerView *)pickerView rowHeightForComponent:(NSInteger)component;
- (UIView *)pickerView:(UIPickerView *)pickerView viewForRow:(NSInteger)row forComponent:(NSInteger)component reusingView:(UIView *)view;

@end

@implementation pickerDel
- (NSInteger)numberOfComponentsInPickerView:(UIPickerView *)pickerView{
    return 3;
}

// returns the # of rows in each component..
- (NSInteger)pickerView:(UIPickerView *)pickerView numberOfRowsInComponent:(NSInteger)component{
  if(component == 0)
      //For hours
      return 24;

  //For the minutes and seconds
  return 60;
}

- (CGFloat)pickerView:(UIPickerView *)pickerView rowHeightForComponent:(NSInteger)component{
    return 30;
}

- (UIView *)pickerView:(UIPickerView *)pickerView viewForRow:(NSInteger)row forComponent:(NSInteger)component reusingView:(UIView *)view{
    UILabel *columnView = [[UILabel alloc] initWithFrame:CGRectMake(35, 0, view.frame.size.width/3 - 35, 30)];
    columnView.text = [NSString stringWithFormat:@"%lu", (long) row];
    columnView.textAlignment = NSTextAlignmentLeft;

    return columnView;
}
@end

/**
Set up my own (instance? Instance-ish) variables to store values in
**/

UIView *timerControlsViewHooked;
UIDatePicker *timePickerHooked;
NSInteger *seconds[59];
NSInteger *minutes[59];
NSInteger *hours[59];

/**
And now its time to start hooking!
**/

%hook TimerViewController
- (void)loadView{

  //Have to run original code first (presumabley) so that the reference to the _timePicker is actually not null
  %orig;

  //The goal here is to get myself a reference to the UIDatePicker timePicker so I can hide it
    timerControlsViewHooked = MSHookIvar<TimerControlsView *>(self, "_timerControlsView");
    timePickerHooked = MSHookIvar<UIDatePicker *>(timerControlsViewHooked, "_timePicker");

    //Hiding the original UIDatePicker so we can add our own UIPickerView
    timePickerHooked.hidden = true;

    //Now to add our own UIPickerView
    //SecondsPicker *myPicker = [[SecondsPicker alloc] init:timerControlsViewHooked];

    pickerDel *pDel = [[pickerDel alloc] init];

    UIPickerView *pickMe = [[UIPickerView alloc] initWithFrame:CGRectMake(0, 100, self.view.frame.size.width, 200)];
    [pickMe setDataSource: pDel];
    [pickMe setDelegate: pDel];

    UILabel *hourLabel = [[UILabel alloc] initWithFrame:CGRectMake(42, pickMe.frame.size.height / 2 - 15, 75, 30)];
    hourLabel.text = @"hour";
    hourLabel.textColor = [UIColor colorWithRed:(188/255.f) green:0 blue:0 alpha:1.0];
    [self.view addSubview:hourLabel];

    UILabel *minsLabel = [[UILabel alloc] initWithFrame:CGRectMake(42 + (pickMe.frame.size.width / 3), pickMe.frame.size.height / 2 - 15, 75, 30)];
    minsLabel.text = @"min";
    minsLabel.textColor = [UIColor colorWithRed:(188/255.f) green:0 blue:0 alpha:1.0];
    [self.view addSubview:minsLabel];

    UILabel *secsLabel = [[UILabel alloc] initWithFrame:CGRectMake(42 + (pickMe.frame.size.width / 3) * 2, pickMe.frame.size.height / 2 - 15, 75, 30)];
    secsLabel.text = @"secs";
    secsLabel.textColor = [UIColor colorWithRed:(188/255.f) green:0 blue:0 alpha:1.0];
    [self.view addSubview:secsLabel];


    [timerControlsViewHooked addSubview:pickMe];

}
%end
