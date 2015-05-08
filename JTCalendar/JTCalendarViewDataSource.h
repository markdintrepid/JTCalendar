//
//  JTCalendarDataSource.h
//  JTCalendar
//
//  Created by Jonathan Tribouharet
//

#import <Foundation/Foundation.h>

@class JTCalendar;

@protocol JTCalendarDataSource <NSObject>

- (BOOL)calendar:(JTCalendar *)calendar hasEventForDate:(NSDate *)date;
- (void)calendar:(JTCalendar *)calendar didSelectDate:(NSDate *)date;

@optional

- (BOOL)calendar:(JTCalendar *)calendar canSelectDate:(NSDate *)date;

- (void)calendarDidLoadPreviousPage;
- (void)calendarDidLoadNextPage;

@end
