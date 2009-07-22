//
//  HolidayCalendarDataSource.m
//  TTCalendar
//
//  Created by Keith Lazuka on 7/22/09.
//  Copyright 2009 __MyCompanyName__. All rights reserved.
//

#import "HolidayCalendarDataSource.h"

static NSMutableDictionary *holidays;

@implementation HolidayCalendarDataSource

+ (void)initialize
{
  holidays = [[NSMutableDictionary alloc] init];
  [holidays setObject:[TTTableTextItem itemWithText:@"New Years Day"] forKey:[NSDate dateForDay:1 month:1 year:2009]];
  [holidays setObject:[TTTableTextItem itemWithText:@"Martin Luther King Day"] forKey:[NSDate dateForDay:19 month:1 year:2009]];
  [holidays setObject:[TTTableTextItem itemWithText:@"Washington's Birthday"] forKey:[NSDate dateForDay:16 month:2 year:2009]];
  [holidays setObject:[TTTableTextItem itemWithText:@"Memorial Day"] forKey:[NSDate dateForDay:25 month:5 year:2009]];
  [holidays setObject:[TTTableTextItem itemWithText:@"Independence Day"] forKey:[NSDate dateForDay:4 month:7 year:2009]];
  [holidays setObject:[TTTableTextItem itemWithText:@"Labor Day"] forKey:[NSDate dateForDay:7 month:9 year:2009]];
  [holidays setObject:[TTTableTextItem itemWithText:@"Columbus Day"] forKey:[NSDate dateForDay:12 month:10 year:2009]];
  [holidays setObject:[TTTableTextItem itemWithText:@"Veteran's Day"] forKey:[NSDate dateForDay:11 month:11 year:2009]];
  [holidays setObject:[TTTableTextItem itemWithText:@"Thanksgiving Day"] forKey:[NSDate dateForDay:26 month:11 year:2009]];
  [holidays setObject:[TTTableTextItem itemWithText:@"Christmas Day"] forKey:[NSDate dateForDay:25 month:12 year:2009]];
}

- (void)loadDate:(NSDate *)date;
{
  [self.items removeAllObjects];
  TTTableItem *item = [holidays objectForKey:date];
  if (item)
    [self.items addObject:item];
}

- (BOOL)hasDetailsForDate:(NSDate *)date
{
  return [holidays objectForKey:date] != nil;
}

@end
