//
//  JTCalendarAppearance.h
//  JTCalendar
//
//  Created by Jonathan Tribouharet
//

#import <UIKit/UIKit.h>

@class JTCalendar;

@interface JTCalendarAppearance : NSObject

typedef NS_ENUM(NSInteger, JTCalendarWeekDayFormat) {
    JTCalendarWeekDayFormatSingle,
    JTCalendarWeekDayFormatShort,
    JTCalendarWeekDayFormatFull
};

typedef NSString *(^JTCalendarMonthBlock)(NSDate *date, JTCalendar *jt_calendar);

/**
 *	A Boolean value indicating whether the calendar should show a month or a week.
 *
 *	The default value of this property is @c NO.
 */
@property (assign, nonatomic) BOOL isWeekMode;

/**
 *	The default value of this property is @c YES.
 */
@property (assign, nonatomic) BOOL useCacheSystem;

/**
 *	A Boolean value indicating whether to persist the selected day when changing @c weekMode.
 *
 *	The default value of this property is @c NO.
 */
@property (assign, nonatomic) BOOL focusSelectedDayChangeMode;
@property (assign, nonatomic) BOOL readFromRightToLeft; // For language read from right to left

/**
 *	The default value of this property is @c YES.
 */
@property (assign, nonatomic) BOOL selectionAdjustsAppearance;

#pragma mark - Month

/**
 *	The default value of this property is @c blackColor.
 */
@property (nonatomic) UIColor *menuMonthTextColor;

/**
 *	The default value of this property is:
 *	@code [UIFont systemFontOfSize:17.] @endcode
 */
@property (nonatomic) UIFont *menuMonthTextFont;

/**
 *	The default value of this property is @c 2.0.
 */
@property (assign, nonatomic) CGFloat ratioContentMenu;

/**
 *	The default value of this property is @c YES.
 */
@property (assign, nonatomic) BOOL autoChangeMonth;
@property (copy, nonatomic) JTCalendarMonthBlock monthBlock;

#pragma mark - Weekday

/**
 *	The default value of this property is @c JTCalendarWeekDayFormatShort.
 */
@property (assign, nonatomic) JTCalendarWeekDayFormat weekDayFormat;

/**
 *	The default value of this property is this gray nuance:
 *	@code [UIColor colorWithRed:152./256. green:147./256. blue:157./256. alpha:1.] @endcode
 */
@property (nonatomic) UIColor *weekDayTextColor;

/**
 *	The default value of this property is:
 *	@code [UIFont systemFontOfSize:11] @endcode
 */
@property (nonatomic) UIFont *weekDayTextFont;

#pragma mark - Day

/**
 *	The default value of this property is @c redColor.
 */
@property (nonatomic) UIColor *dayCircleColorSelected;

/**
 *	The default value of this property is @c redColor.
 */
@property (nonatomic) UIColor *dayCircleColorSelectedOtherMonth;

/**
 *	The default value of this property is this blue nuance:
 *	@code [UIColor colorWithRed:0x33/256. green:0xB3/256. blue:0xEC/256. alpha:.5] @endcode
 */
@property (nonatomic) UIColor *dayCircleColorToday;

/**
 *	The default value of this property is this blue nuance:
 *	@code [UIColor colorWithRed:0x33/256. green:0xB3/256. blue:0xEC/256. alpha:.5] @endcode
 */
@property (nonatomic) UIColor *dayCircleColorTodayOtherMonth;

/**
 *	The default value of this property is this blue nuance:
 *	@code [UIColor colorWithRed:43./256. green:88./256. blue:1134./256. alpha:1.] @endcode
 */
@property (nonatomic) UIColor *dayCircleColorEvent;

/**
 *	The default value of this property is this blue nuance:
 *	@code [UIColor colorWithRed:43./256. green:88./256. blue:1134./256. alpha:1.] @endcode
 */
@property (nonatomic) UIColor *dayCircleColorEventSelected;

/**
 *	The default value of this property is:
 *	@code [UIColor colorWithRed:43./256. green:88./256. blue:1134./256. alpha:1.] @endcode
 */
@property (nonatomic) UIColor *dayCircleColorEventOtherMonth;

/**
 *	The default value of this property is this blue nuance:
 *	@code [UIColor colorWithRed:43./256. green:88./256. blue:1134./256. alpha:1.] @endcode
 */
@property (nonatomic) UIColor *dayCircleColorEventSelectedOtherMonth;

/**
 *	The default value of this property is @c whiteColor.
 */
@property (nonatomic) UIColor *dayCircleColorEventToday;

/**
 *	The default value of this property is @c whiteColor.
 */
@property (nonatomic) UIColor *dayCircleColorEventTodayOtherMonth;

/**
 *	The default value of this property is @c blackColor.
 */
@property (nonatomic) UIColor *dayTextColor;

/**
 *	The default value of this property is @c whiteColor.
 */
@property (nonatomic) UIColor *dayTextColorSelected;

/**
 *	The default value of this property is gray nuance:
 *	@code [UIColor colorWithRed:152./256. green:147./256. blue:157./256. alpha:1.] @endcode
 */
@property (nonatomic) UIColor *dayTextColorOtherMonth;

/**
 *	The default value of this property is @c whiteColor.
 */
@property (nonatomic) UIColor *dayTextColorSelectedOtherMonth;

/**
 *	The default value of this property is @c whiteColor.
 */
@property (nonatomic) UIColor *dayTextColorToday;

/**
 *	The default value of this property is @c whiteColor.
 */
@property (nonatomic) UIColor *dayTextColorTodayOtherMonth;

/**
 *	The default value of this property is @c whiteColor.
 */
@property (nonatomic) UIColor *dayTextColorEvent;

/**
 *	The default value of this property is @c whiteColor.
 */
@property (nonatomic) UIColor *dayTextColorEventOtherMonth;

/**
 *	The default value of this property is @c whiteColor.
 */
@property (nonatomic) UIColor *dayTextColorEventSelected;

/**
 *	The default value of this property is @c whiteColor.
 */
@property (nonatomic) UIColor *dayTextColorEventSelectedOtherMonth;

/**
 *	The default value of this property is @c whiteColor.
 */
@property (nonatomic) UIColor *dayTextColorEventToday;

/**
 *	The default value of this property is @c whiteColor.
 */
@property (nonatomic) UIColor *dayTextColorEventTodayOtherMonth;

/**
 *	The default value of this property is @c clearColor.
 */
@property (nonatomic) UIColor *dayCircleBorderColor;

/**
 *	The default value of this property is @c blackColor.
 */
@property (nonatomic) UIColor *dayCircleBorderColorToday;

/**
 *	The default value of this property is @c clearColor.
 */
@property (nonatomic) UIColor *dayCircleBorderColorOtherMonth;

/**
 *	The default value of this property is:
 *	@code [UIFont systemFontOfSize:[UIFont systemFontSize]] @endcode
 */
@property (nonatomic) UIFont *dayTextFont;

/**
 *	The default value of this property is @c dd.
 */
@property (nonatomic) NSString *dayFormat;

#pragma mark - Day Background and Border

/**
 *	The default value of this property is @c clearColor.
 */
@property (nonatomic) UIColor *dayBackgroundColor;

/**
 *	The default value of this property is @c 0.0.
 */
@property (assign, nonatomic) CGFloat dayBorderWidth;

/**
 *	The default value of this property is @c clearColor.
 */
@property (nonatomic) UIColor *dayBorderColor;

/**
 *	The default value of this property is @c 1.0.
 */
@property (assign, nonatomic) CGFloat dayCircleRatio;

/**
 *	The default value of this property is a @c Gregorian calendar.
 */
- (NSCalendar *)calendar;

/**
 *	Sets the specified color to all the color properties of the day text.
 *
 *	@param textColor The color to use.
 */
- (void)setDayTextColorForAll:(UIColor *)textColor;
- (void)setDayTextColorForAllOtherMonth:(UIColor *)textColor;
- (void)setDayCircleColorForAllOtherMonth:(UIColor *)textColor;

@end
