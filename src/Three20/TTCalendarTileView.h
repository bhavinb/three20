//
//  TTCalendarTileView.h
//  TTCalendar
//
//  Created by Keith Lazuka on 7/9/09.
//  Copyright 2009 __MyCompanyName__. All rights reserved.
//

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


@interface TTCalendarTileView : UIControl <TTStyleDelegate>
{
  NSDate *date;
  TTCalendarTileState state;
  TTStyle *style;
}

@property (nonatomic, retain) NSDate *date;
@property (nonatomic) BOOL belongsToAdjacentMonth;
@property (nonatomic) BOOL marked;
@property (nonatomic, retain) TTStyle *style;

- (void)prepareForReuse;

@end
