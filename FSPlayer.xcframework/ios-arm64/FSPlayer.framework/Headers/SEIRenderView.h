

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

#import <FSPlayer/FSVideoRenderingProtocol.h>


@class SEIDataModel;

NS_ASSUME_NONNULL_BEGIN
@interface SEIRenderView : UIView <FSVideoRenderingProtocol>

@property (nonatomic, strong) NSDictionary<NSString *, UIView<FSVideoRenderingProtocol> *> *renderSubview;
@property (nonatomic, copy) void (^userInfoDidchange)(void);
@property (nonatomic, copy) void (^userInfoDataDidchange)(void);
@property (nonatomic, copy) void (^cutomInfoDidchange)(void);
@property (nonatomic, copy) void (^globalInfoDidchange)(void);
@property (nonatomic, strong) SEIDataModel *currentSEI;


@end


@interface SEIDataObject : NSObject

@property (nonatomic, strong) SEIDataModel *data;


- (void)initWithBytes:(uint8_t *)bytes length:(NSUInteger)length;

@end
NS_ASSUME_NONNULL_END
