#import <substrate.h> //used for MSHookIvar
#import <Foundation/Foundation.h>
#import "Tweak.h"

double numSecs = 0;

/**
Set up my own (instance? Instance-ish) variables to store values in
**/

@implementation pickerDel
- (NSInteger)numberOfComponentsInPickerView:(UIPickerView *)pickerView{
    return 3;
}
// returns the # of rows in each component..
- (NSInteger)pickerView:(UIPickerView *)pickerView numberOfRowsInComponent:(NSInteger)component{
  if(component == 0){
      //For hours
      return 24;
    }else{
  //For the minutes and seconds
  return 60;
  }
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

UIView *timerControlsViewHooked;
UIDatePicker *timePickerHooked;
UIView *timeViewHooked;
NSInteger *seconds[59];
NSInteger *minutes[59];
NSInteger *hours[23];

//Initializing the variables
pickerDel *pDel = [[pickerDel alloc] init];
UIPickerView *pickMe = [[UIPickerView alloc] init];
NSTimer *timerHooked = [[NSTimer alloc] init];
double timeHooked = 0.0;
double timeValueHooked = 0.0;

//Flag telling us if we need to recalculate the end time (timeHooked) 1 = yes, 0 = no
int flag = 0;

/**
And now its time to start hooking!
**/

%hook TimerViewController
-(void)loadView{
  NSLog(@"TimerViewController - loadView");
  //Have to run original code first (presumabley) so that the reference to the _timePicker is actually not null
  %orig;

  //The goal here is to get myself a reference to the UIDatePicker timePicker so I can hide it
    timerControlsViewHooked = MSHookIvar<TimerControlsView *>(self, "_timerControlsView");
    timePickerHooked = MSHookIvar<UIDatePicker *>(timerControlsViewHooked, "_timePicker");
    timeHooked = MSHookIvar<double>(self, "_time");

    //Hiding the original UIDatePicker so we can add our own UIPickerView
    timePickerHooked.hidden = true;

    //Now to add our own UIPickerView

    //Setting size and delegate
    //[pickMe initWithFrame: CGRectMake(0, 100, self.view.frame.size.width, 200)];
    [pickMe setDataSource: pDel];
    [pickMe setDelegate: pDel];

    //creating labels for the picker
    UILabel *hourLabel = [[UILabel alloc] initWithFrame:CGRectMake(42, pickMe.frame.size.height / 3 + 85, 75, 30)];
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
-(void)startTimer:(id)arg1{
  %orig;
  NSLog(@"TimerViewController - startTimer; time: %f", timeHooked);
}
-(void)timerTick:(id)arg1{
  %orig;

  if(flag == 1){
    //On the first urn of timerTick we want to set our own end time.
    timeHooked = CFAbsoluteTimeGetCurrent() + numSecs;
    flag = 0;
  }

  NSLog(@"TimerViewController - timerTick; timeHooked is %f", timeHooked);
  NSLog(@"Current time in seconds: %f", CFAbsoluteTimeGetCurrent());
}
-(void)cancelTimer:(id)arg1{
  NSLog(@"TimerViewController - cancelTimer");
  %orig;
}
-(void)pauseResumeTimer:(id)arg1{
  NSLog(@"TimerViewController - pauseResumeTimer");
  %orig;
}
-(void)startUpdatingTimerUI{
    NSLog(@"TimerViewController - startUpdatingTimerUI");
    %orig;
}
-(void)stopUpdatingTimerUI{
  NSLog(@"TimerViewController - stopUpdatingTimerUI");
  %orig;
}
%end

%hook TimerControlsView
-(void)setTime:(double)arg1{
  %orig;
  NSLog(@"TimerControlsView - setTime.  arg1 is %f, timeHooked is %f", arg1, timeHooked);
}
-(void)setState:(int)arg1 animate:(_Bool)arg2{
  %orig;
  NSLog(@"TimerControlsView - setState, timeHooked is: %f", timeHooked);
}
%end

%hook TimerTimeView
-(void)configureTimeLabel{
  %orig;
  NSLog(@"TimerTimeView - configureTimeLabel");
}
%end

%hook TimeView
-(void)configureTimeLabel{
  %orig;
  timeValueHooked = MSHookIvar<double>(self, "_timeValue");
  NSLog(@"TimeView - configureTimeLabel; _timeValue is: %f", timeValueHooked);
}
-(_Bool)showSubseconds{
  %orig;
  NSLog(@"TimeView - showSubseconds, timeHooked is %f", timeHooked);
  return nil;
}
%end;

%hook MTTimerButtonsController
- (void)_startStopButtonTapped:(id)arg1{
  NSLog(@"MTTimerButtonsController - _startStopButtonTapped");

  UIButton *button = MSHookIvar<UIButton *>(self, "_startStopButton");
  NSString *label = [button titleForState:UIControlStateNormal];
  if([label isEqualToString:@"Start"]){
    timeHooked = CFAbsoluteTimeGetCurrent() + numSecs;
    NSLog(@"tapped Start: %f", timeHooked);
  }

  //If this button is tapped, the end time needs to be recalculated, so set the flag
  flag = 1;
  %orig;
}
%end;
