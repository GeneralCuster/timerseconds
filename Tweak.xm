#import <substrate.h> //used for MSHookIvar
#import <Foundation/Foundation.h>
//#import "picker.h"

/**
Interface all the things so that I can reference their stuff later
**/

int numSecs = 0;

@interface TimerControlsView : UIView {
  UIDatePicker *_timePicker;
}
@end

@interface TimerViewController : UIViewController {
  TimerControlsView *_timerControlsView;
  NSTimer *_timer;
  double _time;
}
  -(void)startTimer:(id)arg1;
  -(void)loadView;
  -(void)startUpdatingTimerUI;
@end

@interface pickerDel : UIViewController <UIPickerViewDataSource, UIPickerViewDelegate>
- (NSInteger)numberOfComponentsInPickerView:(UIPickerView *)pickerView;
- (NSInteger)pickerView:(UIPickerView *)pickerView numberOfRowsInComponent:(NSInteger)component;
- (CGFloat)pickerView:(UIPickerView *)pickerView rowHeightForComponent:(NSInteger)component;
- (UIView *)pickerView:(UIPickerView *)pickerView viewForRow:(NSInteger)row forComponent:(NSInteger)component reusingView:(UIView *)view;
- (void)pickerView:(UIPickerView *)pickerView didSelectRow:(NSInteger)row inComponent:(NSInteger)component;
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

- (void)pickerView:(UIPickerView *)pickerView didSelectRow:(NSInteger)row inComponent:(NSInteger)component {

  NSInteger hours = [pickerView selectedRowInComponent:0];
  NSInteger mins = [pickerView selectedRowInComponent:1];
  NSInteger secs = [pickerView selectedRowInComponent:2];

  numSecs = (hours * 3600) + (mins * 60) + secs;
}

- (UIView *)pickerView:(UIPickerView *)pickerView viewForRow:(NSInteger)row forComponent:(NSInteger)component reusingView:(UIView *)view{
    UILabel *columnText = [[UILabel alloc] initWithFrame:CGRectMake(35, 0, view.frame.size.width/3 -35, 30)];
    columnText.text = [NSString stringWithFormat:@"%lu", (long) row];
    columnText.textColor = [UIColor whiteColor];
    columnText.font = [UIFont fontWithName:@"HelveticaNeue-Bold" size:23];
    columnText.textAlignment = NSTextAlignmentLeft;

    return columnText;
}
@end

/**
Set up my own (instance? Instance-ish) variables to store values in
**/

UIView *timerControlsViewHooked;
UIDatePicker *timePickerHooked;
NSInteger *seconds[59];
NSInteger *minutes[59];
NSInteger *hours[23];

//Initializing the picker
pickerDel *pDel = [[pickerDel alloc] init];
UIPickerView *pickMe = [[UIPickerView alloc] init];
NSTimer *timerHooked = [[NSTimer alloc] init];

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

    //Setting size and delegate
    //[pickMe initWithFrame: CGRectMake(0, 100, self.view.frame.size.width, 200)];
    [pickMe setDataSource: pDel];
    [pickMe setDelegate: pDel];

    //creating labels for the picker
    UILabel *hourLabel = [[UILabel alloc] initWithFrame:CGRectMake(42, pickMe.frame.size.height / 2 + 85, 75, 30)];
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

- (void)startTimer:(id)arg1{
//If the user has picked a value when starting the timer, then numSecs will be updated, otherwise it will be 0.
//Now we need to create a timer lasting for the number of seconds specified by numSecs
double doubleTimeHooked = MSHookIvar<double>(self, "_time");
timerHooked = MSHookIvar<NSTimer *>(self, "_timer");




}

%end
