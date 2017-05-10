c#import <picker.h>
@implementation SecondsPicker

@synthesize pickMe;
@synthesize hourLabel, minsLabel, secsLabel;

UIView *myParent;

-(id) init:(UIView*)parent{
  self = [super init];

    myParent = parent;

    pickMe = [[UIPickerView alloc] initWithFrame:CGRectMake(0, 100, parent.frame.size.width, 200)];
    pickMe.dataSource = self;
    pickMe.delegate = self;

    hourLabel = [[UILabel alloc] initWithFrame:CGRectMake(42, parent.frame.size.height / 2 - 15, 75, 30)];
    hourLabel.text = @"hour";
    [pickMe addSubview:hourLabel];

    minsLabel = [[UILabel alloc] initWithFrame:CGRectMake(42 + (parent.frame.size.width / 3), parent.frame.size.height / 2 - 15, 75, 30)];
    minsLabel.text = @"min";
    [pickMe addSubview:minsLabel];

    secsLabel = [[UILabel alloc] initWithFrame:CGRectMake(42 + ((parent.frame.size.width / 3) * 2), parent.frame.size.height / 2 - 15, 75, 30)];
    secsLabel.text = @"sec";
    [pickMe addSubview:secsLabel];

return self;
}

// returns the number of 'columns' (componenets) to display.
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
    UILabel *columnView = [[UILabel alloc] initWithFrame:CGRectMake(35, 0, myParent.frame.size.width/3 - 35, 30)];
    columnView.text = [NSString stringWithFormat:@"%lu", (long) row];
    columnView.textAlignment = NSTextAlignmentLeft;

    return columnView;
}

@end
