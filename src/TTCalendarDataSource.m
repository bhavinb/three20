//
//  TTCalendarDataSource.m
//  TTCalendar
//
//  Created by Keith Lazuka on 7/20/09.
//  Copyright 2009 __MyCompanyName__. All rights reserved.
//

#import "Three20/TTCalendarDataSource.h"


@implementation TTCalendarDataSource

+ (id<TTTableViewDataSource>)dataSource {
  return [self dataSourceWithItems:[NSArray array]];
}

- (void)loadDate:(NSDate *)date {
}

- (BOOL)hasDetailsForDate:(NSDate *)date {
  return NO;
}

@end
