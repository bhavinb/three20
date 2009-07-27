#import "Three20/TTListDataSource.h"

/*
 *    TTCalendarDataSource
 *    --------------------
 *
 *  The TTCalendar system uses a very similar data source system
 *  as TTTableViewController. TTCalendarDataSource is actually
 *  a TTListDataSource with a few additional requirements beyond
 *  just providing the event data for each row in the "day details"
 *  table view beneath the calendar.
 *
 *  The first additional responsibility is indicating whether
 *  the calendar should mark a day "tile." Your TTCalendarDataSource
 *  subclass should implement the hasDetailsForDate: method such that
 *  it returns YES if the provided date has 1 or more events
 *  associated with it.
 *
 *  The second additional responsibility is updating the
 *  dataSource's list of table view items whenever the selected
 *  calendar date changes. Your TTCalendarDataSource subclass
 *  should implement the loadDate: method such that every time
 *  it is called, it removes all objects from the dataSource's
 *  list of table items, and adds an item for every event associated
 *  with the given date. The type of item that you add to the list should
 *  either be a TTTableItem or your own custom object (provided that
 *  you also implement tableView:cellClassForObject: and
 *  tableView:cell:willAppearAtIndexPath: just like you would any
 *  other custom cell for a Three20 table view).
 */
@interface TTCalendarDataSource : TTListDataSource {
}

+ (id<TTTableViewDataSource>)dataSource;

// Subclasses should implement these 2 methods
- (BOOL)hasDetailsForDate:(NSDate *)date;   // Return YES if the tile for the given date should be displayed with a mark on it (to indicate that details are available).
- (void)loadDate:(NSDate *)date;            // Reset the list of |items| to include only details for the given date.


@end
