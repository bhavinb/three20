#import "YouTubeTestController.h"

@implementation YouTubeTestController

- (void)dealloc {
  [youTubeView release];
  [super dealloc];
}

- (void)loadView {
  self.view = [[[UIView alloc] initWithFrame:[UIScreen mainScreen].applicationFrame] autorelease];
  self.view.backgroundColor = [UIColor redColor];
    
  youTubeView = [[T3YouTubeView alloc] initWithURL:@"http://www.youtube.com/watch?v=g8thp78oXsg"];
  youTubeView.center = self.view.center;
  [self.view addSubview:youTubeView];
}

///////////////////////////////////////////////////////////////////////////////////////////////////

@end