//
//  TTCalendarView.h
//  TTCalendar
//
//  Created by Keith Lazuka on 7/9/09.
//  Copyright 2009 __MyCompanyName__. All rights reserved.
//

#import "Three20/TTView.h"

@class TTCalendarGridView, TTCalendarModel;
@protocol TTCalendarViewDelegate;

@interface TTCalendarView : TTView
{
  UILabel *headerTitleLabel;    // Displays the currently selected month and year at the top of the calendar.
  TTCalendarGridView *gridView; // The calendar proper (between the calendar header and the day details view)
  UITableView *tableView;       // Bottom section (details for the currently selected day)
  TTView *dropShadow;           // Below the grid and on-top-of tableView.
  id<TTCalendarViewDelegate> delegate;
  TTCalendarModel *model;
}

@property (nonatomic, assign) id<TTCalendarViewDelegate> delegate;
@property (nonatomic, readonly) UITableView *tableView;

- (id)initWithFrame:(CGRect)frame delegate:(id<TTCalendarViewDelegate>)delegate model:(TTCalendarModel *)model;

// these 2 methods are exposed for the delegate
- (void)slideDown;
- (void)slideUp;

@end


@protocol TTCalendarViewDelegate

- (void)showPreviousMonth;
- (void)showFollowingMonth;
- (BOOL)shouldMarkTileForDate:(NSDate *)date;
- (void)didSelectDate:(NSDate *)date;

@end
