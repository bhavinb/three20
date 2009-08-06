
#import "TableTestController.h"

///////////////////////////////////////////////////////////////////////////////////////////////////

@interface TableTestDataSource : TTListDataSource
{
  NSMutableArray *delegates;
  BOOL isLoading;
  BOOL isLoaded;
}
- (void)purge;
- (void)loadForever;
- (void)fill;
- (void)fail;
@end

@implementation TableTestDataSource

- (void)purge
{
  TTLOG(@"purge");
  isLoading = NO;
  isLoaded = YES;
  [self.items removeAllObjects];
}
- (void)loadForever
{
  TTLOG(@"loadForever");
  isLoading = YES;
  isLoaded = NO;
}
- (void)fill
{
  TTLOG(@"fill");
  isLoading = NO;
  isLoaded = YES;
  self.items = [NSMutableArray arrayWithObjects:
                     [TTTableTextItem itemWithText:@"Pomegranate"],
                     [TTTableTextItem itemWithText:@"Kale"],
                     [TTTableTextItem itemWithText:@"Blueberries"],
                     [TTTableTextItem itemWithText:@"Tomato"],
                     [TTTableTextItem itemWithText:@"Tempeh"],
                     [TTTableTextItem itemWithText:@"Grapefruit"],
                     nil];
}
- (void)fail
{
  TTLOG(@"fail");
  isLoading = NO;
  isLoaded = NO;
  [self.items removeAllObjects];
  [delegates perform:@selector(model:didFailLoadWithError:)
          withObject:self
          withObject:[NSError errorWithDomain:@"foo" code:42 userInfo:nil]];
}

///////////////////////////////////////////////////////////////////////////////////////////////////
// TTModel protocol
- (NSMutableArray*)delegates {
  if (!delegates) delegates = [[NSMutableArray alloc] init];
  return delegates;
}
- (BOOL)isLoaded { return isLoaded; }
- (BOOL)isLoading { return isLoading; }

///////////////////////////////////////////////////////////////////////////////////////////////////
// TTTableViewDataSource

- (UIImage*)imageForEmpty {
  return TTIMAGE(@"bundle://Three20.bundle/images/empty.png");
}

- (NSString*)titleForEmpty {
  return NSLocalizedString(@"Empty", @"");
}

- (NSString*)subtitleForEmpty {
  return NSLocalizedString(@"There are no items in the datasource.", @"");
}

- (UIImage*)imageForError:(NSError*)error {
  return TTIMAGE(@"bundle://Three20.bundle/images/error.png");
}

- (NSString*)subtitleForError:(NSError*)error {
  return NSLocalizedString(@"An error occurred while loading the datasource.", @"");
}

- (void)dealloc
{
  [delegates release];
  [super dealloc];
}


@end

///////////////////////////////////////////////////////////////////////////////////////////////////

@implementation TableTestController

///////////////////////////////////////////////////////////////////////////////////////////////////
// private

- (TableTestDataSource *)ds { return (TableTestDataSource*)self.dataSource; }

- (void)cycleModelState {
  static int count = 0;
  
  self.modelError = nil;
  
  count == 0 ?
    [[self ds] loadForever]:
  count == 1 ?
    [[self ds] fill]:
  count == 2 ?
    [[self ds] fail]:
  count == 3 ?
    [[self ds] purge]:
  NULL;
  
  [self invalidateView];
  count = (count + 1) % 4;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
// UIViewController

- (void)loadView {
  [super loadView];
  
  self.navigationItem.rightBarButtonItem = [[[UIBarButtonItem alloc]
    initWithTitle:@"Next" style:UIBarButtonItemStyleBordered target:self
    action:@selector(cycleModelState)] autorelease];
}

///////////////////////////////////////////////////////////////////////////////////////////////////
// TTModelViewController

- (void)createModel {
  self.dataSource = [TableTestDataSource dataSourceWithItems:nil];
}

@end
