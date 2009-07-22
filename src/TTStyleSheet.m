#import "Three20/TTStyleSheet.h"
#import "Three20/TTDefaultStyleSheet.h"

///////////////////////////////////////////////////////////////////////////////////////////////////
// global

static TTStyleSheet* gStyleSheet = nil;

///////////////////////////////////////////////////////////////////////////////////////////////////

@implementation TTStyleSheet

///////////////////////////////////////////////////////////////////////////////////////////////////
// class public

+ (TTStyleSheet*)globalStyleSheet {
  if (!gStyleSheet) {
    gStyleSheet = [[TTDefaultStyleSheet alloc] init];
  }
  return gStyleSheet;
}

+ (void)setGlobalStyleSheet:(TTStyleSheet*)styleSheet {
  [gStyleSheet release];
  gStyleSheet = [styleSheet retain];
}

///////////////////////////////////////////////////////////////////////////////////////////////////
// NSObject

- (id)init {
  if (self = [super init]) {
    _styles = nil;
    [[NSNotificationCenter defaultCenter] addObserver:self
                                          selector:@selector(didReceiveMemoryWarning:)
                                          name:UIApplicationDidReceiveMemoryWarningNotification  
                                          object:nil];  
  }
  return self;
}

- (void)dealloc {
  [[NSNotificationCenter defaultCenter] removeObserver:self
                                        name:UIApplicationDidReceiveMemoryWarningNotification  
                                        object:nil];  
  TT_RELEASE_SAFELY(_styles);
  [super dealloc];
}

//////////////////////////////////////////////////////////////////////////////////////////////////
// NSNotifications

- (void)didReceiveMemoryWarning:(void*)object {
  [self freeMemory];
}

///////////////////////////////////////////////////////////////////////////////////////////////////
// private

- (TTStyle *)styleFromAppBundleForSelector:(NSString *)selector
{
  // First, try to find it in the root of the app bundle
  NSString *filename = [NSString stringWithFormat:@"%@.ttstyle", selector];
  TTStyle *style = [NSKeyedUnarchiver unarchiveObjectWithFile:TTPathForBundleResource(filename)];
  if (!style) {
    // Fallback by looking for it in the Three20.bundle resource directory
    filename = [@"Three20.bundle/styles/" stringByAppendingString:filename];
    style = [NSKeyedUnarchiver unarchiveObjectWithFile:TTPathForBundleResource(filename)];
  }
  
  return style;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
// public

- (TTStyle*)styleWithSelector:(NSString*)selector {
  return [self styleWithSelector:selector forState:UIControlStateNormal];
}

- (TTStyle*)styleWithSelector:(NSString*)selector forState:(UIControlState)state {
  NSString* key = state == UIControlStateNormal
    ? selector
    : [NSString stringWithFormat:@"%@%d", selector, state];
  TTStyle* style = [_styles objectForKey:key];
  if (!style) {
    SEL sel = NSSelectorFromString(selector);
    style = [self respondsToSelector:sel]
              ? [self performSelector:sel withObject:(id)state]
              : [self styleFromAppBundleForSelector:selector];
    if (style) {
      if (!_styles) {
        _styles = [[NSMutableDictionary alloc] init];
      }
      [_styles setObject:style forKey:key];
    }
  }
  return style;
}

- (void)freeMemory {
  TT_RELEASE_SAFELY(_styles);
}

@end
