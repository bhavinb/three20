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

// -----------------------------------------
#pragma mark TTCalendarViewDelegate protocol

- (void)didSelectDate:(NSDate *)date
{
  [(TTCalendarDataSource*)self.dataSource loadDate:date];
  self.viewState = TTViewDataLoaded;
}

- (BOOL)shouldMarkTileForDate:(NSDate *)date
{
  // Lazy load hack. hopefully the new TTTableViewController implementation
  // will make this unnecessary.
  if (!self.dataSource) 
    self.dataSource = [self createDataSource];

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
#pragma mark TTTableViewController

- (id<TTTableViewDataSource>)createDataSource
{
  return [TTCalendarDataSource dataSource];
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

