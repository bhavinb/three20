#import "Three20/TTTableViewController.h"
#import "Three20/TTCalendarView.h" // for the TTCalendarViewDelegate protocol

@class TTCalendarLogic;

/*
 *    TTCalendarViewController
 *    ------------------------
 *
 *  As a client of Three20's calendar system, this is your main entry-point
 *  into using the calendar in your app. The TTCalendar system aims to mimic
 *  Apple's mobile calendar app as much as possible. When the user taps a date,
 *  any associated events for that date are displayed in a table view directly
 *  below the calendar. Your only responibility is to provide the events
 *  for each date via TTCalendarDataSource.
 *
 *  TTCalendarViewController automatically creates both the calendar view
 *  and the events table view for you. The only thing you need to provide
 *  is a TTCalendarDataSource so that the calendar system knows which days to
 *  mark with a dot and which events to list under the calendar when a certain
 *  date is selected (just like in Apple's calendar app).
 *
 *  EXAMPLES
 *  --------
 *  Note: All of the following example code assumes that it is being called from
 *  within another UIViewController which is in a UINavigationController hierarchy.
 *
 *  Here is how you would display a very basic calendar (without any events):
 *
 *    TTCalendarViewController *calendar = [[[TTCalendarViewController alloc] init] autorelease];
 *    [self.navigationController pushViewController:calendar animated:YES];
 *
 *  In most cases you will have some custom data that you want to attach
 *  to the dates on the calendar. In this case, all you need to do to display
 *  your annotated calendar is the following:
 *
 *    TTCalendarViewController *calendar = [[[TTCalendarViewController alloc] init] autorelease];
 *    calendar.dataSource = [[[MyTTCalendarDataSourceSubclass alloc] init] autorelease];
 *    [self.navigationController pushViewController:calendar animated:YES];
 *
 *
 */
@interface TTCalendarViewController : TTTableViewController <TTCalendarViewDelegate>
{
  TTCalendarLogic *logic;
}

@end
