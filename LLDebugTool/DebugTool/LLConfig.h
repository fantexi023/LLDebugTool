//
//  LLConfig.h
//
//  Copyright (c) 2018 LLDebugTool Software Foundation (https://github.com/HDB-Li/LLDebugTool)
//
//  Permission is hereby granted, free of charge, to any person obtaining a copy
//  of this software and associated documentation files (the "Software"), to deal
//  in the Software without restriction, including without limitation the rights
//  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//  copies of the Software, and to permit persons to whom the Software is
//  furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in all
//  copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
//  SOFTWARE.

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

// Deprecated macro.
#define LLDebugToolDeprecated(instead) NS_DEPRECATED(2_0, 2_0, 2_0, 2_0, instead)

/**
 Color style enum
 
 - LLConfigColorStyleHack: Green backgroundColor and white textColor.
 - LLConfigColorStyleSimple: White backgroundColor and darkTextColor textColor.
 - LLConfigColorStyleSystem: White backgroundColor and system tint textColor.
 - LLConfigColorStyleCustom: Use custom backgroundColor and textColor.
 */
typedef NS_ENUM(NSUInteger, LLConfigColorStyle) {
    LLConfigColorStyleHack,
    LLConfigColorStyleSimple,
    LLConfigColorStyleSystem,
    LLConfigColorStyleCustom,
};

/**
 Log Level. It can be used for filter.
 
 - LLConfigLogLevelDefault: Use to save message or note.
 - LLConfigLogLevelAlert: Use to save alert message.
 - LLConfigLogLevelWarning: Use to save warning message.
 - LLConfigLogLevelError: Use to save error message.
 */
typedef NS_ENUM(NSUInteger, LLConfigLogLevel) {
    LLConfigLogLevelDefault,
    LLConfigLogLevelAlert,
    LLConfigLogLevelWarning,
    LLConfigLogLevelError,
};

/**
 Window style. Decide how the Window displays.
 
 - LLConfigEntryWindowStyleBall: Show as a ball. Moveable and clickable.
 - LLConfigEntryWindowStyleTitle: Show as a big title. Moveable and clickable.
 - LLConfigEntryWindowStyleLeading: Show as a big title on left. Part moveable and clickable.
 - LLConfigEntryWindowStyleTrailing: Show as a big title on right. Moveable and clickable.
 - LLConfigEntryWindowStyleNetBar: Show at network bar. Unmoveable but clickable.
 - LLConfigEntryWindowStylePowerBar: Show at power bar. Unmoveable but clickable.
 - LLConfigEntryWindowStyleSuspensionBall: Same to LLConfigEntryWindowStyleBall.
 */
typedef NS_ENUM(NSUInteger, LLConfigEntryWindowStyle) {
    LLConfigEntryWindowStyleBall = 0,
    LLConfigEntryWindowStyleTitle = 1,
    LLConfigEntryWindowStyleLeading = 2,
    LLConfigEntryWindowStyleTrailing = 3,
#ifdef __IPHONE_13_0
    LLConfigEntryWindowStyleNetBar NS_ENUM_DEPRECATED_IOS(2_0, 13_0, "Use LLConfigEntryWindowStyleLeading") = 2,
    LLConfigEntryWindowStylePowerBar NS_ENUM_DEPRECATED_IOS(2_0, 13_0, "Use LLConfigEntryWindowStyleTrailing") = 3,
#else
    LLConfigEntryWindowStyleNetBar = 4,
    LLConfigEntryWindowStylePowerBar = 5,
#endif
    LLConfigEntryWindowStyleSuspensionBall NS_ENUM_DEPRECATED_IOS(2_0, 8_0, "Use LLConfigEntryWindowStyleBall") = 0,
};

/**
 Log style for [LLDebugTool logInFile...]. Customize the log you want.
 
 - LLConfigLogDetail: Show all detail info. Contain event, file, line, func, date and desc.
 - LLConfigLogFileFuncDesc : Show with event, file, func and desc.
 - LLConfigLogFileDesc : Show with event, file and desc.
 - LLConfigLogNormal: Show as system NSLog
 - LLConfigLogNone: Don't show anything.
 */
typedef NS_ENUM(NSUInteger, LLConfigLogStyle) {
    LLConfigLogDetail,
    LLConfigLogFileFuncDesc,
    LLConfigLogFileDesc,
    LLConfigLogNormal,
    LLConfigLogNone,
};

/**
 Customize available Features.
 
 - LLConfigAvailableNetwork: Network functions available.
 - LLConfigAvailableLog: Log functions avalable.
 - LLConfigAvailableCrash: Crash functions available.
 - LLConfigAvailableAppInfo: AppInfo functions available.
 - LLConfigAvailableSandbox: Sandbox functions available.
 - LLConfigAvailableScreenshot: Screenshot functions available.
 - LLConfigAvailableAll: All available.
 */
typedef NS_OPTIONS(NSUInteger, LLConfigAvailableFeature) {
    LLConfigAvailableNetwork    = 1 << 0,
    LLConfigAvailableLog        = 1 << 1,
    LLConfigAvailableCrash      = 1 << 2,
    LLConfigAvailableAppInfo    = 1 << 3,
    LLConfigAvailableSandbox    = 1 << 4,
    LLConfigAvailableScreenshot = 1 << 5,
    LLConfigAvailableHierarchy  = 1 << 6,
    LLConfigAvailableAll        = 0xFF,
    
    // Quick options
    LLConfigAvailableNoneNetwork    = 0xFF - (1 << 0),
    LLConfigAvailableNoneLog        = 0xFF - (1 << 1),
    LLConfigAvailableNoneCrash      = 0xFF - (1 << 2),
    LLConfigAvailableNoneAppInfo    = 0xFF - (1 << 3),
    LLConfigAvailableNoneSandbox    = 0xFF - (1 << 4),
    LLConfigAvailableNoneScreenshot = 0xFF - (1 << 5),
    LLConfigAvailableNoneHierarchy  = 0xFF - (1 << 6),
};

/**
 Action enums.
 
 - LLDebugToolActionFunction: Show function window.
 - LLDebugToolActionSetting: Show setting function.
 - LLDebugToolActionNetwork: Network function.
 - LLDebugToolActionLog: Log function.
 - LLDebugToolActionCrash: Crash function.
 - LLDebugToolActionAppInfo: App info function.
 - LLDebugToolActionSandbox: Sandbox function.
 - LLDebugToolActionConvenientScreenshot: Convenient screenshot function.
 - LLDebugToolActionScreenshot: Screenshot function.
 - LLDebugToolActionHierarchy: Hierarchy function.
 - LLDebugToolActionMagnifier: Magnifier function.
 - LLDebugToolActionRuler: Ruler function.
 - LLDebugToolActionWidgetBorder: Widget border function.
 */
typedef NS_ENUM(NSUInteger, LLDebugToolAction) {
    LLDebugToolActionFunction,
    LLDebugToolActionSetting,
    LLDebugToolActionNetwork,
    LLDebugToolActionLog,
    LLDebugToolActionCrash,
    LLDebugToolActionAppInfo,
    LLDebugToolActionSandbox,
    LLDebugToolActionScreenshot,
    LLDebugToolActionConvenientScreenshot,
    LLDebugToolActionHierarchy,
    LLDebugToolActionMagnifier,
    LLDebugToolActionRuler,
    LLDebugToolActionWidgetBorder,
    LLDebugToolActionHtml
};

FOUNDATION_EXPORT NSNotificationName _Nonnull const LLConfigDidUpdateWindowStyleNotificationName;

NS_ASSUME_NONNULL_BEGIN
/**
 Config file. Must config properties before [LLDebugTool enable].
 */
@interface LLConfig : NSObject

/**
 Singleton to get/save config.
 
 @return Singleton
 */
+ (instancetype)shared;

#pragma mark - Entry Window Config
/**
 Entry window style. Decide how the Window displays. Default is LLConfigEntryWindowStyleSuspensionBall.
 */
@property (nonatomic, assign) LLConfigEntryWindowStyle entryWindowStyle;

/**
 Entry window ball width, default is kLLEntryWindowBallWidth, must greater than kLLEntryWindowMinBallWidth.
 */
@property (nonatomic, assign) CGFloat entryWindowBallWidth;

/**
 Entry window display percent, 0.1 .. 1.0, default is kLLEntryWindowDisplayPercent.
 */
@property (nonatomic, assign) CGFloat entryWindowDisplayPercent;

/**
 Entry window first display position, default is {kLLEntryWindowFirstDisplayPositionX, kLLEntryWindowFirstDisplayPositionY}.
 */
@property (nonatomic, assign) CGPoint entryWindowFirstDisplayPosition;

/**
 Entry window alpha(not active), default is kLLInactiveAlpha.
 */
@property (nonatomic, assign) CGFloat inactiveAlpha;

/**
 Entry window alpha(active), default is kLLActiveAlpha.
 */
@property (nonatomic, assign) CGFloat activeAlpha;

/**
 Automatic adjust entry window's frame to side, default is YES.
 */
@property (nonatomic, assign, getter=isShrinkToEdgeWhenInactive) BOOL shrinkToEdgeWhenInactive;

/**
 Automatic hide when shake, default is YES.
 */
@property (nonatomic, assign, getter=isShakeToHide) BOOL shakeToHide;

#pragma mark - Theme Color.
/**
 Use preset the color configuration. For details, please see LLConfigColorStyle.
 */
@property (nonatomic, assign) LLConfigColorStyle colorStyle;

/**
 Customizing the custom color configuration, will auto set colorStyle to LLConfigColorStyleCustom.
 */
- (void)configBackgroundColor:(UIColor *)backgroundColor primaryColor:(UIColor *)primaryColor statusBarStyle:(UIStatusBarStyle)statusBarStyle;

/**
 Window's statusBarStyle when show.
 */
- (void)configStatusBarStyle:(UIStatusBarStyle)statusBarStyle;

#pragma mark - Log
/**
 Customize the log style. Default is LLConfigLogDetail.
 */
@property (nonatomic, assign) LLConfigLogStyle logStyle;

#pragma mark - Date Formatter
/**
 Date Format Style. Use to recording time when create model. Default is "yyyy-MM-dd HH:mm:ss".
 If this value is modified, the old data is not compatible.
 */
@property (nonatomic, copy) NSString *dateFormatter;

#pragma mark - Magnifier Window
/**
 Magnifier window zoom level, number of pixels per color, default is kLLMagnifierWindowZoomLevel.
 */
@property (nonatomic, assign) NSInteger magnifierZoomLevel;

/**
 Number of rows per magnifier window, default is kLLMagnifierWindowSize.
 */
@property (nonatomic, assign) NSInteger magnifierSize;

#pragma mark - User Identity
/**
 Tag user name is used to create the crash/network/log model.
 */
@property (nonatomic, copy, nullable) NSString *userIdentity;

#pragma mark - Network
/**
 Observer network in hosts, ignore others.
 */
@property (nonatomic, strong, nullable) NSArray <NSString *>*observerdHosts;

/**
 Ignored hosts, low level than observerdHosts.
 */
@property (nonatomic, strong, nullable) NSArray <NSString *>*ignoredHosts;

/**
 Whether observer webView request.
 */
@property (nonatomic, assign) BOOL observerWebView;

#pragma mark - Hierarchy

/**
 Hierarchy function ignore private class or not.
 */
@property (nonatomic, assign, getter=isHierarchyIgnorePrivateClass) BOOL hierarchyIgnorePrivateClass;

#pragma mark - Widget Border

/**
Whether show widget border. Default is NO.
*/
@property (nonatomic, assign, getter=isShowWidgetBorder) BOOL showWidgetBorder;

#pragma mark - Html5

/**
 Default html5 url string used in Html function. must has prefix with http:// or https://
 */
@property (nonatomic, copy, nullable) NSString *defaultHtmlUrl;

/**
 Custom view controller used in html function. you can use your custom viewController to dynamic debug your web view. must comply with `LLComponentDelegate`. ViewController must set background color.
 */
@property (nonatomic, copy, nullable) UIViewController *(^htmlViewControllerProvider)(void);

#pragma mark - LLDebugTool
/**
 Whether to print LLDebugTool's log event. Default is YES.
 */
@property (nonatomic, assign, getter=isShowDebugToolLog) BOOL showDebugToolLog;

/**
 Whether check LLDebugTool has new version.
 */
@property (nonatomic, assign) BOOL autoCheckDebugToolVersion;

/**
 Whether show entry window when first install, default is NO, if set YES, entry window won't show when first initial, you can shake to show the entry window.
 */
@property (nonatomic, assign) BOOL hideWhenInstall;

#pragma mark - Click Event

/**
 Click action. Default is LLDebugToolActionFunction.
*/
@property (nonatomic, assign, readonly) LLDebugToolAction clickAction;

/**
 Double click action. Default is LLDebugToolActionConvenientScreenshot.
 */
@property (nonatomic, assign) LLDebugToolAction doubleClickAction;

#pragma mark - Function
/**
 Available features. Default is LLConfigAvailableAll.
 It can affect tabbar's display and features on or off. If this value is modified at run time, will automatic called [LLDebugTool stopWorking] and [LLDebugTool startWorking] again to start or close the features, also the tabbar will be updated automatically the next time it appears.
 */
@property (nonatomic, assign) LLConfigAvailableFeature availables;

#pragma mark - Folder Path
/**
 The folder path for LLDebugTool. The database is created and read in this directory.
 Default path is ../Documents/LLDebugTool/.
 */
@property (nonatomic, copy) NSString *folderPath;

#pragma mark - Extension
/**
 Image resource bundle.
 */
@property (nonatomic, strong, readonly, nullable) NSBundle *imageBundle;

/**
 XIB resource bundle.
 */
@property (nonatomic, strong, readonly, nullable) NSBundle *XIBBundle;

#pragma mark - DEPRECATED

@property (nonatomic, assign) CGFloat suspensionBallWidth LLDebugToolDeprecated("Use `entryWindowBallWidth`.");
@property (nonatomic, assign) CGFloat suspensionWindowHideWidth LLDebugToolDeprecated("Use `entryWindowDisplayPercent` to set display percent.");
@property (nonatomic, assign) CGFloat suspensionWindowTop LLDebugToolDeprecated("Use `entryWindowFirstDisplayPosition` to set first display position.");
@property (nonatomic, assign) CGFloat normalAlpha LLDebugToolDeprecated("Use `inactiveAlpha`.");
@property (nonatomic, assign) BOOL suspensionBallMoveable LLDebugToolDeprecated("Deprecated");
@property (nonatomic, assign, getter=isAutoAdjustSuspensionWindow) BOOL autoAdjustSuspensionWindow LLDebugToolDeprecated("Use `shrinkToEdgeWhenInactive`.");
@property (nonatomic, strong, nullable) NSArray <NSString *>*hosts LLDebugToolDeprecated("Use `observerdHosts`");

@end

NS_ASSUME_NONNULL_END

