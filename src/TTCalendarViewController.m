#import "TTCalendarViewController.h"
#import "TTCalendarLogic.h"
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
  [logic retreatToPreviousMonth];
  [[self calendarView] slideDown];
}

- (void)showFollowingMonth
{
  [logic advanceToFollowingMonth];
  [[self calendarView] slideUp];
}

// -----------------------------------------------------------------------------------
#pragma mark TTModelViewController

// TODO: this still doesn't work right (it doesn't update until the user actually
//       touches somewhere on the calendar--strange).
- (void)didLoadModel
{
  [super didLoadModel];
  [[self calendarView] refresh];
}

// -----------------------------------------------------------------------------------
#pragma mark UIViewController

- (void)loadView
{
  self.title = @"Calendar";
  logic = [[TTCalendarLogic alloc] init];
  self.view = [[[TTCalendarView alloc] initWithFrame:TTNavigationFrame() delegate:self logic:logic] autorelease];
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
  [logic release];
  [super dealloc];
}


@end

