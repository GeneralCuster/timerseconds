/**
Interface all the things so that I can reference their stuff later
**/

@interface TimerControlsView : UIView {
  UIDatePicker *_timePicker;
}
-(void)setTime:(id)arg1;
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
