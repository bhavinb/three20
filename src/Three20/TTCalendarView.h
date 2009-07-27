//
//  TTCalendarView.h
//  TTCalendar
//
//  Created by Keith Lazuka on 7/9/09.
//  Copyright 2009 __MyCompanyName__. All rights reserved.
//

#import "Three20/TTView.h"

@class TTCalendarGridView, TTCalendarLogic;
@protocol TTCalendarViewDelegate;

@interface TTCalendarView : TTView
{
  UILabel *headerTitleLabel;    // Displays the currently selected month and year at the top of the calendar.
  TTCalendarGridView *gridView; // The calendar proper (between the calendar header and the day details view)
  UITableView *tableView;       // Bottom section (details for the currently selected day)
  TTView *dropShadow;           // Below the grid and on-top-of tableView.
  id<TTCalendarViewDelegate> delegate;
  TTCalendarLogic *logic;
}

@property (nonatomic, assign) id<TTCalendarViewDelegate> delegate;
@property (nonatomic, readonly) UITableView *tableView;

- (id)initWithFrame:(CGRect)frame delegate:(id<TTCalendarViewDelegate>)delegate logic:(TTCalendarLogic *)logic;

- (void)refresh;  // Requery marked tables and update the day details view (the area below the calendar grid).

// These 2 methods are exposed for the delegate. They should be called 
// *after* the CalendarModel has moved to the previous or following month.
- (void)slideDown;
- (void)slideUp;

@end


@protocol TTCalendarViewDelegate

- (void)showPreviousMonth;
- (void)showFollowingMonth;
- (BOOL)shouldMarkTileForDate:(NSDate *)date;
- (void)didSelectDate:(NSDate *)date;

@end
