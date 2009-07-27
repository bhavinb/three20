#import "Three20/TTView.h"

@class TTCalendarGridView, TTCalendarLogic;
@protocol TTCalendarViewDelegate;

/*
 *    TTCalendarGridView
 *    ------------------
 *
 *    Private interface
 *
 *  As a client of the TTCalendar system you should not need to use this class directly
 *  (it is managed by TTCalendarViewController).
 *
 *  TTCalendarViewController uses TTCalendarView as its view.
 *  TTCalendarView defines a view hierarchy that looks like the following:
 *
 *       +-----------------------------------------+
 *       |                header view              |
 *       +-----------------------------------------+
 *       |                                         |
 *       |                                         |
 *       |                                         |
 *       |                 grid view               |
 *       |             (the calendar grid)         |
 *       |                                         |
 *       |                                         |
 *       +-----------------------------------------+
 *       |                                         |
 *       |           table view (events)           |
 *       |                                         |
 *       +-----------------------------------------+
 *
 */
@interface TTCalendarView : TTView
{
  UILabel *headerTitleLabel;    // Displays the currently selected month and year at the top of the calendar.
  TTCalendarGridView *gridView; // The calendar proper (between the calendar header and the table view)
  UITableView *tableView;       // Bottom section (events for the currently selected day)
  TTView *dropShadow;           // Below the grid and on-top-of tableView.
  id<TTCalendarViewDelegate> delegate;
  TTCalendarLogic *logic;
}

@property (nonatomic, assign) id<TTCalendarViewDelegate> delegate;
@property (nonatomic, readonly) UITableView *tableView;

- (id)initWithFrame:(CGRect)frame delegate:(id<TTCalendarViewDelegate>)delegate logic:(TTCalendarLogic *)logic;

- (void)refresh;  // Requery marked tiles and update the table view of events.

// These 2 methods are exposed for the delegate. They should be called 
// *after* the TTCalendarLogic has moved to the previous or following month.
- (void)slideDown;
- (void)slideUp;

@end

// This protocol is designed to be used by TTCalendarViewController.
@protocol TTCalendarViewDelegate

- (void)showPreviousMonth;
- (void)showFollowingMonth;
- (BOOL)shouldMarkTileForDate:(NSDate *)date;
- (void)didSelectDate:(NSDate *)date;

@end
