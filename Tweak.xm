#import <substrate.h> //used for MSHookIvar
#import <Foundation/Foundation.h>
#import "picker.m"

/**
Interface all the things so that I can reference their stuff later
**/

@class SecondsPicker;

@interface TimerControlsView : UIView {
  UIDatePicker *_timePicker;
}
- (void)setTime:(double)arg1;
- (void)setTimerToneName:(id)arg1;
- (void)loadView;
@end

@interface TimerViewController : UIViewController {
  TimerControlsView *_timerControlsView;
  NSTimer *_timer;
  double _time;
}
- (void)viewDidAppear:(_Bool)arg1;
- (void)loadView;
@end

/**
Set up my own (instance? Instance-ish) variables to store values in
**/

UIView *timerControlsViewHooked;
UIDatePicker *timePickerHooked;
//Setting flag to mark first time view is loaded in order to not re-assign things over and over


/**
And now its time to start hooking!
**/

%hook TimerViewController
- (void)loadView{

  //Have to run original code first (presumabley) so that the reference to the _timePicker is actually not null
  %orig;

    //First time view is loaded, do stuff
    timerControlsViewHooked = MSHookIvar<TimerControlsView *>(self, "_timerControlsView");
    //The goal here is to get myself a reference to the UIDatePicker timePicker so I can modify it
    timePickerHooked = MSHookIvar<UIDatePicker *>(timerControlsViewHooked, "_timePicker");
    timePickerHooked = nil;

    SecondsPicker *myPicker = [[SecondsPicker alloc]init:(UIView*)timerControlsViewHooked];

  [self.view addSubview:myPicker];

}
%end
