#import "Three20/TTStyle.h"

// these values can be used with the TTCalendarTileStateMode mask
#define kTTCalendarTileTypeRegular  (0 << 16)
#define kTTCalendarTileTypeAdjacent (1 << 16)
#define kTTCalendarTileTypeToday    (2 << 16)

// The reason that I encode some of the TTCalendarTileViewState as UIControlState
// is that it makes it much easier to integrate with the existing TTStyleSheet
// interface.
enum {
  TTCalendarTileStateMode       = 0x03 << 16,  // bits 0 and 1 encode the tile mode (regular, adjacent, today)
  TTCalendarTileStateMarked     = 0x04 << 16   // bit 2 is true when there is data attached to this tile's date.
};
typedef UIControlState TTCalendarTileState;

/*
 *    TTCalendarTileView
 *    ------------------
 *
 *    Private interface
 *
 *  As a client of the TTCalendar system you should not need to use this class directly
 *  (it is managed by TTCalendarGridView).
 *
 *  A TTCalendarTileView represents a single square tile for an individual date
 *  on the calendar.
 */
@interface TTCalendarTileView : UIControl <TTStyleDelegate>
{
  NSDate *date;
  TTCalendarTileState state;
  TTStyle *style;
}

@property (nonatomic, retain) NSDate *date;         // The date that this tile represents.
@property (nonatomic) BOOL belongsToAdjacentMonth;  // YES if the tile is part of a partial week from an adjacent month (such tiles are grayed out, just like in Apple's mobile calendar app)
@property (nonatomic) BOOL marked;                  // YES if the tile should draw a marker underneath the day number. (the mark indicates to the user that the tile's date has one or more associated events)
@property (nonatomic, retain) TTStyle *style;       // The head of the TTStyle rendering pipeline that will draw this tile.

- (void)prepareForReuse;                            // TTCalendarGridView manages a pool of reusable TTCalendarTileViews. This method behaves like the prepareForReuse method on the UITableViewCell class.

@end
