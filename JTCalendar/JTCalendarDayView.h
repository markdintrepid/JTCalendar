//
//  JTCalendarDayView.h
//  JTCalendar
//
//  Created by Jonathan Tribouharet
//

#import <UIKit/UIKit.h>

#import "JTCalendar.h"

@interface JTCalendarDayView : UIView

@property (weak, nonatomic) JTCalendar *calendarManager;

@property (nonatomic) NSDate *date;
@property (assign, nonatomic) BOOL isOtherMonth;
@property (assign, nonatomic) BOOL hasEvent;

- (void)reloadData;
- (void)reloadAppearance;

@end
