#import "Three20/TTView.h"

@class TTCalendarTileView, TTCalendarLogic;
@protocol TTCalendarViewDelegate;

/*
 *    TTCalendarGridView
 *    ------------------
 *
 *    Private interface
 *
 *  As a client of the TTCalendar system you should not need to use this class directly
 *  (it is managed by TTCalendarView).
 *
 *  Each |cell| is a TTView, and each cell's width is the full width of the TTCalendarGridView.
 *  In other words, the cell represents a week in the calendar.
 *  One cell (week) can optionally be kept on-screen by the slide animation, depending
 *  on whether the currently selected month has a partial week that belongs to the month
 *  that will be slid into place.
 */
@interface TTCalendarGridView : TTView
{
  id<TTCalendarViewDelegate> delegate;  // Assigned.
  TTCalendarLogic *logic;
  TTCalendarTileView *selectedTile;
  NSMutableArray *reusableCells;        // The pool of reusable cells. If this runs out, the app will crash instead of dynamically allocating more views. So make this just large enough to meet your app needs, but no larger.
  CGFloat cellHeight;                   // This implies that every cell must have the same height.
}

@property (nonatomic, retain) TTCalendarTileView *selectedTile;

- (id)initWithFrame:(CGRect)frame logic:(TTCalendarLogic *)logic delegate:(id<TTCalendarViewDelegate>)delegate;

- (void)refresh;

// These 2 methods should be called *after* the TTCalendarLogic
// has moved to the previous or following month.
- (void)slideUp;
- (void)slideDown;

@end


// --------------------------------

// TODO factor me out into a separate source file.
@interface NSMutableArray (KLQueue)
- (void)enqueue:(id)anObject;
- (id)dequeue;
@end