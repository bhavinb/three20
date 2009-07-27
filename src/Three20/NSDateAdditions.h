#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface NSDate (TTCategory)

/**
 * Returns the current date with the time set to midnight.
 */
+ (NSDate*)dateWithToday;

/**
 * Returns a copy of the date with the time set to midnight on the same day.
 */
- (NSDate*)dateAtMidnight;

/**
 * Formats the date with 'h:mm a' or the localized equivalent.
 */
- (NSString*)formatTime;

/**
 * Formats the date with 'EEEE, LLLL d, YYYY' or the localized equivalent.
 */
- (NSString*)formatDate;

/**
 * Formats the date according to how old it is.
 *
 * For dates less than a day old, the format is 'h:mm a', for less than a week old the
 * format is 'EEEE', and for anything older the format is 'M/d/yy'.
 */
- (NSString*)formatShortTime;

/**
 * Formats the date according to how old it is.
 *
 * For dates less than a day old, the format is 'h:mm a', for less than a week old the
 * format is 'EEE h:mm a', and for anything older the format is 'MMM d h:mm a'.
 */
- (NSString*)formatDateTime;

/**
 * Formats dates within 24 hours like '5 minutes ago', or calls formatDateTime if older.
 */
- (NSString*)formatRelativeTime;

/**
 * Formats the date with 'MMMM d", "Today", or "Yesterday".
 *
 * You must supply date components for today and yesterday because they are relatively expensive
 * to create, so it is best to avoid creating them every time you call this method if you
 * are going to be calling it multiple times in a loop.
 */
- (NSString*)formatDay:(NSDateComponents*)today yesterday:(NSDateComponents*)yesterday;

@end

@interface NSDate (TTCalendarAdditions)

// All of the following methods use [NSCalendar currentCalendar] to perform
// their calculations. These methods are not documented because, as of right now,
// they are only here for the TTCalendar subsystem.
+ (NSDate *)cc_today;
+ (NSDate *)cc_dateForDay:(NSUInteger)day month:(NSUInteger)month year:(NSUInteger)year; // TODO delete me after I'm done with this convenience method. It should only be needed during the initial build-out of the calendar model.

- (BOOL)cc_isToday;
- (NSDate *)cc_dateByMovingToFirstDayOfTheMonth;
- (NSDate *)cc_dateByMovingToFirstDayOfThePreviousMonth;
- (NSDate *)cc_dateByMovingToFirstDayOfTheFollowingMonth;
- (NSDateComponents *)cc_componentsForMonthDayAndYear;
- (NSUInteger)cc_day;
- (NSUInteger)cc_weekday;
- (NSUInteger)cc_numberOfDaysInMonth;


@end