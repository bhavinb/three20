//
//  TTCalendarDataSource.h
//  TTCalendar
//
//  Created by Keith Lazuka on 7/20/09.
//  Copyright 2009 __MyCompanyName__. All rights reserved.
//

#import "Three20/TTTableViewDataSource.h"


@interface TTCalendarDataSource : TTListDataSource {
}

+ (id<TTTableViewDataSource>)dataSource;

// Subclasses should implement these 2 methods
- (void)loadDate:(NSDate *)date;             // Reset the list of |items| to include only details for the given date.
- (BOOL)hasDetailsForDate:(NSDate *)date;   // Return YES if the tile for the given date should be displayed with a mark on it (to indicate that details are available).

@end
