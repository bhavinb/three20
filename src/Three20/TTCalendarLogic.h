#import "Three20/TTGlobal.h"

/*
 *    TTCalendarLogic
 *    ------------------
 *
 *    Private interface
 *
 *  As a client of the TTCalendar system you should not need to use this class directly
 *  (it is managed by the internal TTCalendar subsystem).
 *
 *  The TTCalendarLogic represents the current state of the displayed calendar month
 *  and provides the logic for switching between months and determining which days
 *  are in a month as well as which days are in partial weeks adjacent to the selected
 *  month.
 */
@interface TTCalendarLogic : NSObject
{
  NSDate *baseDate; // The first day of the currently selected month
  NSDateFormatter *monthAndYearFormatter;
}

@property (nonatomic, retain) NSDate *baseDate;

- (void)retreatToPreviousMonth;
- (void)advanceToFollowingMonth;

// Each of the daysIn* methords return an array of NSDates in increasing chronological order
- (NSArray *)daysInFinalWeekOfPreviousMonth;
- (NSArray *)daysInSelectedMonth;
- (NSArray *)daysInFirstWeekOfFollowingMonth;

- (NSString *)selectedMonthNameAndYear;

@end
