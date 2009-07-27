#import "Three20/TTCalendarDataSource.h"


@implementation TTCalendarDataSource

+ (id<TTTableViewDataSource>)dataSource {
  return [self dataSourceWithItems:[NSArray array]];
}

- (void)loadDate:(NSDate *)date {
}

- (BOOL)hasDetailsForDate:(NSDate *)date {
  return NO;
}

@end
