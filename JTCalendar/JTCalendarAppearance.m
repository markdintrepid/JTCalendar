//
//  JTCalendarAppearance.m
//  JTCalendar
//
//  Created by Jonathan Tribouharet
//

#import "JTCalendarAppearance.h"

#import "JTCalendar.h"

@implementation JTCalendarAppearance

- (instancetype)init
{
    self = [super init];
    if(!self){
        return nil;
    }
        
    [self setDefaultValues];
    
    return self;
}

- (void)setDefaultValues
{
    self.isWeekMode = NO;
    
    self.weekDayFormat = JTCalendarWeekDayFormatShort;
    self.useCacheSystem = YES;
    self.focusSelectedDayChangeMode = NO;
    self.selectionAdjustsAppearance = YES;
    
    self.ratioContentMenu = 2.;
    self.autoChangeMonth = YES;
    
    self.dayCircleRatio = 1.;
    
    self.menuMonthTextFont = [UIFont systemFontOfSize:17.];
    self.weekDayTextFont = [UIFont systemFontOfSize:11];
    self.dayTextFont = [UIFont systemFontOfSize:[UIFont systemFontSize]];

    self.dayFormat = @"dd";

    // Day Background and Border
    self.dayBackgroundColor = [UIColor clearColor];
    self.dayBorderWidth = 0.0f;
    self.dayBorderColor = [UIColor clearColor];
    
    self.menuMonthTextColor = [UIColor blackColor];
    self.weekDayTextColor = [UIColor colorWithRed:152./256. green:147./256. blue:157./256. alpha:1.];
    
    [self setDayTextColorForAll:[UIColor blackColor]];
    
    self.dayTextColorOtherMonth = [UIColor colorWithRed:152./256. green:147./256. blue:157./256. alpha:1.];

    self.dayCircleColorSelected = [UIColor redColor];
    self.dayTextColorSelected = [UIColor whiteColor];
    
    self.dayCircleColorSelectedOtherMonth = self.dayCircleColorSelected;
    self.dayTextColorSelectedOtherMonth = self.dayTextColorSelected;
    
    self.dayCircleColorToday = [UIColor colorWithRed:0x33/256. green:0xB3/256. blue:0xEC/256. alpha:.5];
    self.dayTextColorToday = [UIColor whiteColor];
    
    self.dayCircleColorTodayOtherMonth = self.dayCircleColorToday;
    self.dayTextColorTodayOtherMonth = self.dayTextColorToday;
    
    self.dayCircleColorEvent = [UIColor colorWithRed:43./256. green:88./256. blue:134./256. alpha:1.];
    self.dayCircleColorEventOtherMonth = self.dayCircleColorEvent;
    
    self.dayCircleColorEventSelected = self.dayCircleColorSelected;
    self.dayCircleColorEventSelectedOtherMonth = self.dayCircleColorEventSelected;
    
    self.dayCircleColorEventToday = self.dayCircleColorToday;
    self.dayCircleColorEventTodayOtherMonth = self.dayCircleColorEventToday;
    
    self.dayTextColorEvent = self.dayTextColor;
    self.dayTextColorEventOtherMonth = self.dayTextColorOtherMonth;
    
    self.dayTextColorEventSelected = self.dayTextColorSelected;
    self.dayTextColorEventSelectedOtherMonth = self.dayTextColorEventSelected;
    
    self.dayTextColorEventToday = self.dayTextColorToday;
    self.dayTextColorEventTodayOtherMonth = self.dayTextColorEventToday;
    
    self.dayCircleBorderColor = [UIColor clearColor];
    self.dayCircleBorderColorToday = [UIColor blackColor];
    self.dayCircleBorderColorOtherMonth = [UIColor clearColor];
    
    self.monthBlock = ^NSString *(NSDate *date, JTCalendar *jt_calendar){
        NSCalendar *calendar = jt_calendar.calendarAppearance.calendar;
        NSDateComponents *comps = [calendar components:NSCalendarUnitYear|NSCalendarUnitMonth fromDate:date];
        NSInteger currentMonthIndex = comps.month;
        
        static NSDateFormatter *dateFormatter;
        if(!dateFormatter){
            dateFormatter = [NSDateFormatter new];
            dateFormatter.timeZone = jt_calendar.calendarAppearance.calendar.timeZone;
        }
        
        while(currentMonthIndex <= 0){
            currentMonthIndex += 12;
        }
        
        return [[dateFormatter standaloneMonthSymbols][currentMonthIndex - 1] capitalizedString];
    };
}

- (NSCalendar *)calendar
{
    static NSCalendar *calendar;
    static dispatch_once_t once;
    
    dispatch_once(&once, ^{
#ifdef __IPHONE_8_0
        calendar = [[NSCalendar alloc] initWithCalendarIdentifier:NSCalendarIdentifierGregorian];
#else
        calendar = [[NSCalendar alloc] initWithCalendarIdentifier:NSGregorianCalendar];
#endif
        calendar.timeZone = [NSTimeZone localTimeZone];
    });
    
    return calendar;
}

- (void)setDayTextColorForAll:(UIColor *)textColor
{
    self.dayTextColor = textColor;
    self.dayTextColorSelected = textColor;
    
    self.dayTextColorOtherMonth = textColor;
    self.dayTextColorSelectedOtherMonth = textColor;
    
    self.dayTextColorToday = textColor;
    self.dayTextColorTodayOtherMonth = textColor;
    
    self.dayTextColorEvent = textColor;
    self.dayTextColorEventOtherMonth = textColor;
}

- (void)setDayTextColorForAllOtherMonth:(UIColor *)textColor {
    self.dayTextColorOtherMonth = textColor;
    self.dayTextColorTodayOtherMonth = textColor;
    self.dayTextColorSelectedOtherMonth = textColor;
    self.dayTextColorEventOtherMonth = textColor;
    self.dayTextColorEventTodayOtherMonth = textColor;
    self.dayTextColorEventSelectedOtherMonth = textColor;
}

- (void)setDayCircleColorForAllOtherMonth:(UIColor *)textColor {
    self.dayCircleColorSelectedOtherMonth = textColor;
    self.dayCircleColorTodayOtherMonth = textColor;
    self.dayCircleColorEventOtherMonth = textColor;
    self.dayCircleColorEventSelectedOtherMonth = textColor;
    self.dayCircleColorEventTodayOtherMonth = textColor;
}

@end
