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

// -----------------------------------------------------------------------------------
#pragma mark TTTableViewController

- (id<TTTableViewDataSource>)createDataSource
{
  return [HolidayCalendarDataSource dataSource];
}

@end
