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

// TODO Hide as much of this as possible in the TTCalendarLogic.m
//      so that we don't visibly export it to client code.
//      Also, I should prefix these method names so that there is
//      less chance of a namespace collision with the client code.
+ (NSDate *)today;
+ (NSDate *)dateForDay:(NSUInteger)day month:(NSUInteger)month year:(NSUInteger)year; // TODO delete me after I'm done with this convenience method. It should only be needed during the initial build-out of the calendar model.

- (BOOL)isToday;
- (NSDate *)dateByMovingToFirstDayOfTheMonth;
- (NSDate *)dateByMovingToFirstDayOfThePreviousMonth;
- (NSDate *)dateByMovingToFirstDayOfTheFollowingMonth;
- (NSDateComponents *)componentsForMonthDayAndYear;
- (NSUInteger)day;
- (NSUInteger)weekday;
- (NSUInteger)numberOfDaysInMonth;


@end