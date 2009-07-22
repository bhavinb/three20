//
//  RootViewController.h
//  TTCalendar
//
//  Created by Keith Lazuka on 7/9/09.
//  Copyright __MyCompanyName__ 2009. All rights reserved.
//

#import "Three20/TTTableViewController.h"
#import "Three20/TTCalendarView.h" // for the TTCalendarViewDelegate protocol

@class TTCalendarModel;

@interface TTCalendarViewController : TTTableViewController <TTCalendarViewDelegate>
{
  TTCalendarModel *model;
}

@end
