//
//  CalendarTestController.m
//  TTCatalog
//
//  Created by Keith Lazuka on 7/22/09.
//  Copyright 2009 __MyCompanyName__. All rights reserved.
//

#import "CalendarTestController.h"
#import "HolidayCalendarDataSource.h"

@implementation CalendarTestController

// TODO: the client should not have to subclass TTCalendarViewController
//       just to specify the data source. In regular code they can just
//       set the datasource property *after* init, but in TTCatalog,
//       maybe we can pass the dataSource as a parameter via the URL mapping system?
- (id)init
{
  if ((self = [super init])) {
    self.dataSource = [HolidayCalendarDataSource dataSource];
  }
  return self;
}

@end
