//
//  RootViewController.m
//  TTCalendar
//
//  Created by Keith Lazuka on 7/9/09.
//  Copyright __MyCompanyName__ 2009. All rights reserved.
//

#import "TTCalendarViewController.h"
#import "TTCalendarModel.h"
#import "TTCalendarDataSource.h"

@interface TTCalendarViewController ()
- (TTCalendarView*)calendarView;
@end

@implementation TTCalendarViewController

- (id)init
{
    if ((self = [super init])) {
        self.dataSource = [TTCalendarDataSource dataSource];
    }
    return self;
}

// -----------------------------------------
#pragma mark TTCalendarViewDelegate protocol

- (void)didSelectDate:(NSDate *)date
{
  // Configure the dataSource to display details for |date|.
  [(TTCalendarDataSource*)self.dataSource loadDate:date];

  // Refresh the view to reflect the updated model/dataSource state.
  [self invalidateModel];
}

- (BOOL)shouldMarkTileForDate:(NSDate *)date
{
  return [(TTCalendarDataSource*)self.dataSource hasDetailsForDate:date];
}

- (void)showPreviousMonth
{
  [model retreatToPreviousMonth];
  [[self calendarView] slideDown];
}

- (void)showFollowingMonth
{
  [model advanceToFollowingMonth];
  [[self calendarView] slideUp];
}

// -----------------------------------------------------------------------------------
#pragma mark TTModelDelegate protocol

- (void)modelDidFinishLoad:(id<TTModel>)theModel
{
  [super modelDidFinishLoad:theModel];
  [[self calendarView] refresh];
}

// -----------------------------------------------------------------------------------
#pragma mark UIViewController

- (void)loadView
{
  self.title = @"Calendar";
  model = [[TTCalendarModel alloc] init];
  self.view = [[[TTCalendarView alloc] initWithFrame:TTNavigationFrame() delegate:self model:model] autorelease];
  self.tableView = [[self calendarView] tableView];
}

// make the compiler happy
- (TTCalendarView*)calendarView
{
  return (TTCalendarView*)self.view;
}

#pragma mark -

- (void)dealloc
{
  [model release];
  [super dealloc];
}


@end

