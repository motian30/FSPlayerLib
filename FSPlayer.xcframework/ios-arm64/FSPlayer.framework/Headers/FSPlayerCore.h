

#import <Foundation/Foundation.h>
#import <FSPlayer/FSPlayer.h>


typedef enum FSLogLevel {
    FS_LOG_UNKNOWN = 0,
    FS_LOG_DEFAULT = 1,
    FS_LOG_VERBOSE = 2,
    FS_LOG_DEBUG   = 3,
    FS_LOG_INFO    = 4,
    FS_LOG_WARN    = 5,
    FS_LOG_ERROR   = 6,
    FS_LOG_FATAL   = 7,
    FS_LOG_SILENT  = 8,
} FSLogLevel;

typedef enum FSAudioChannel {
    FSAudioChannelStereo = 0,
    FSAudioChannelRight = 1,
    FSAudioChannelLeft = 2
} FSAudioChannel;



NS_ASSUME_NONNULL_BEGIN
@interface FSPlayerCore : NSObject <FSMediaPlayback>

- (id)initWithContentURL:(NSURL *)aUrl
             withOptions:(FSOptions * _Nullable)options;

- (id)initWithMoreContent:(NSURL *)aUrl
              withOptions:(FSOptions * _Nullable)options
               withGLView:(UIView<FSVideoRenderingProtocol> *)glView;

- (void)prepareToPlay;
- (void)play;
- (void)pause;
- (void)stop;
- (BOOL)isPlaying;
- (int64_t)trafficStatistic;
- (float)dropFrameRate;
- (int)dropFrameCount;
- (void)setPauseInBackground:(BOOL)pause;
- (void)setHudValue:(NSString * _Nullable)value forKey:(NSString *)key;

+ (void)setLogReport:(BOOL)preferLogReport;
+ (void)setLogLevel:(FSLogLevel)logLevel;
+ (FSLogLevel)getLogLevel;
+ (void)setLogHandler:(void (^_Nullable)(FSLogLevel level,  NSString * _Nonnull tag,  NSString * _Nonnull msg))handler;

+ (NSDictionary *)supportedDecoders;
+ (BOOL)checkIfFFmpegVersionMatch:(BOOL)showAlert;
+ (BOOL)checkIfPlayerVersionMatch:(BOOL)showAlert
                          version:(NSString *)version;

@property(nonatomic, readonly) CGFloat fpsInMeta;
@property(nonatomic, readonly) CGFloat fpsAtOutput;
@property(nonatomic) BOOL shouldShowHudView;
//when sampleSize is -1,the samples is NULL,means needs reset and refresh ui.
@property(nonatomic, copy) void (^audioSamplesCallback)(int16_t * _Nullable samples, int sampleSize, int sampleRate, int channels);

- (NSDictionary *)allHudItem;

- (void)setOptionValue:(NSString *)value
                forKey:(NSString *)key
            ofCategory:(FSOptionCategory)category;

- (void)setOptionIntValue:(int64_t)value
                   forKey:(NSString *)key
               ofCategory:(FSOptionCategory)category;

- (void)setFormatOptionValue:       (NSString *)value forKey:(NSString *)key;
- (void)setCodecOptionValue:        (NSString *)value forKey:(NSString *)key;
- (void)setSwsOptionValue:          (NSString *)value forKey:(NSString *)key;
- (void)setPlayerOptionValue:       (NSString *)value forKey:(NSString *)key;

- (void)setFormatOptionIntValue:    (int64_t)value forKey:(NSString *)key;
- (void)setCodecOptionIntValue:     (int64_t)value forKey:(NSString *)key;
- (void)setSwsOptionIntValue:       (int64_t)value forKey:(NSString *)key;
- (void)setPlayerOptionIntValue:    (int64_t)value forKey:(NSString *)key;

@property (nonatomic, retain, nullable) id<FSMediaUrlOpenDelegate> segmentOpenDelegate;
@property (nonatomic, retain, nullable) id<FSMediaUrlOpenDelegate> tcpOpenDelegate;
@property (nonatomic, retain, nullable) id<FSMediaUrlOpenDelegate> httpOpenDelegate;
@property (nonatomic, retain, nullable) id<FSMediaUrlOpenDelegate> liveOpenDelegate;
@property (nonatomic, retain, nullable) id<FSMediaNativeInvokeDelegate> nativeInvokeDelegate;

- (void)didShutdown;

#pragma mark KVO properties
@property (nonatomic, readonly) FSMonitor *monitor;

- (void)exchangeSelectedStream:(int)streamIdx;
// FS_VAL_TYPE__VIDEO, FS_VAL_TYPE__AUDIO, FS_VAL_TYPE__SUBTITLE
- (void)closeCurrentStream:(NSString *)streamType;
- (void)enableAccurateSeek:(BOOL)open;
- (void)stepToNextFrame;
- (FSAudioChannel)getAudioChanne;
- (void)setAudioChannel:(FSAudioChannel)config;

@end
NS_ASSUME_NONNULL_END
