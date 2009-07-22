//
//  TTCalendarModel.m
//  TTCalendar
//
//  Created by Keith Lazuka on 7/15/09.
//  Copyright 2009 __MyCompanyName__. All rights reserved.
//

#import "Three20/TTCalendarModel.h"

@interface TTCalendarModel ()
- (NSUInteger)numberOfDaysInPreviousPartialWeek;
- (NSUInteger)numberOfDaysInFollowingPartialWeek;
@end

@implementation TTCalendarModel

@synthesize baseDate;

+ (NSSet *)keyPathsForValuesAffectingSelectedMonthNameAndYear
{
  return [NSSet setWithObjects:@"baseDate", nil];
}

- (id)init
{
  if ((self = [super init])) {
    self.baseDate = [[NSDate today] dateByMovingToFirstDayOfTheMonth];
    monthAndYearFormatter = [[NSDateFormatter alloc] init];
    [monthAndYearFormatter setDateFormat:@"MMMM yyyy"];
  }
  return self;
}

- (void)retreatToPreviousMonth
{
  self.baseDate = [self.baseDate dateByMovingToFirstDayOfThePreviousMonth];
}

- (void)advanceToFollowingMonth
{
  self.baseDate = [self.baseDate dateByMovingToFirstDayOfTheFollowingMonth];
}

- (NSArray *)daysInFinalWeekOfPreviousMonth
{
  NSMutableArray *days = [NSMutableArray array];
  
  NSDate *beginningOfPreviousMonth = [self.baseDate dateByMovingToFirstDayOfThePreviousMonth];
  int n = [beginningOfPreviousMonth numberOfDaysInMonth];
  int numPartialDays = [self numberOfDaysInPreviousPartialWeek];
  NSDateComponents *c = [beginningOfPreviousMonth componentsForMonthDayAndYear];
  for (int i = n - (numPartialDays - 1); i < n + 1; i++)
    [days addObject:[NSDate dateForDay:i month:c.month year:c.year]];
  
  return days;
}

- (NSArray *)daysInSelectedMonth
{
  NSMutableArray *days = [NSMutableArray array];
  
  NSUInteger numDays = [self.baseDate numberOfDaysInMonth];
  NSDateComponents *c = [self.baseDate componentsForMonthDayAndYear];
  for (int i = 1; i < numDays + 1; i++)
    [days addObject:[NSDate dateForDay:i month:c.month year:c.year]];
  
  return days;
}

- (NSArray *)daysInFirstWeekOfFollowingMonth
{
  NSMutableArray *days = [NSMutableArray array];
  
  NSDateComponents *c = [[self.baseDate dateByMovingToFirstDayOfTheFollowingMonth] componentsForMonthDayAndYear];
  NSUInteger numPartialDays = [self numberOfDaysInFollowingPartialWeek];
  
  for (int i = 1; i < numPartialDays + 1; i++)
    [days addObject:[NSDate dateForDay:i month:c.month year:c.year]];
  
  return days;
}

- (NSString *)selectedMonthNameAndYear;
{
  return [monthAndYearFormatter stringFromDate:self.baseDate];
}

#pragma mark Low-level implementation details

- (NSUInteger)numberOfDaysInPreviousPartialWeek
{
  // weekday(first day of the month) - 1
  return [self.baseDate weekday] - 1;
}

- (NSUInteger)numberOfDaysInFollowingPartialWeek
{
  NSDateComponents *c = [self.baseDate componentsForMonthDayAndYear];
  c.day = [self.baseDate numberOfDaysInMonth];
  NSDate *lastDayOfTheMonth = [[NSCalendar currentCalendar] dateFromComponents:c];
  return 7 - [lastDayOfTheMonth weekday];
}

#pragma mark -

- (void) dealloc
{
  [monthAndYearFormatter release];
  [baseDate release];
  [super dealloc];
}


@end
