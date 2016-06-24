#import <Cordova/CDV.h>

@interface AlipayPlugin : CDVPlugin

@property(nonatomic,strong)NSString *urlScheme;
@property(nonatomic,strong)NSString *currentCallbackId;

- (void) pay:(CDVInvokedUrlCommand*)command;
@end
