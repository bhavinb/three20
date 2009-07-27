//
//  TTCalendarLogic.h
//  TTCalendar
//
//  Created by Keith Lazuka on 7/15/09.
//  Copyright 2009 __MyCompanyName__. All rights reserved.
//

#import "Three20/TTGlobal.h"

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
