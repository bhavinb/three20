//
//  TTCalendarGridView.h
//  TTCalendar
//
//  Created by Keith Lazuka on 7/9/09.
//  Copyright 2009 __MyCompanyName__. All rights reserved.
//

#import "Three20/TTView.h"

@class TTCalendarTileView, TTCalendarModel;
@protocol TTCalendarViewDelegate;

//
// Each |cell| is a TTView, and each cell's width is the full width of the TTCalendarGridView.
// In other words, the cell represents a week in the calendar.
// One cell (week) can optionally be kept on-screen by the slide animation.
//
@interface TTCalendarGridView : TTView
{
  id<TTCalendarViewDelegate> delegate;  // Assigned.
  TTCalendarModel *model;
  TTCalendarTileView *selectedTile;
  NSMutableArray *reusableCells;        // The pool of reusable cells. If this runs out, the app will crash instead of dynamically allocating more views. So make this just large enough to meet your app needs, but no larger.
  CGFloat cellHeight;                   // REQUIRED! Subclasses must set this ivar! Currently requires a fixed cell height for all cells.
}

@property (nonatomic, retain) TTCalendarTileView *selectedTile;

- (id)initWithFrame:(CGRect)frame model:(TTCalendarModel *)model delegate:(id<TTCalendarViewDelegate>)delegate;

- (void)refresh;

// These 2 methods should be called *after* the CalendarModel
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