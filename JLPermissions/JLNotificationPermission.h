#import "JLPermissionsCore.h"
#import <UserNotifications/UserNotifications.h>

NS_ASSUME_NONNULL_BEGIN

@interface JLNotificationPermission : JLPermissionsCore

+ (instancetype)sharedInstance;

/**
 * For iOS 10 and later, set this for the notification authorization options you want to register.  If not set, it uses
 * Alert, Badge, and Sound and ProvidesAppNotificationSettings(iOS 12) authorization options.
 */
@property(nonatomic) UNAuthorizationOptions authorizationOptions;

/**
 *  Uses the default dialog which is identical to the system permission dialog
 *
 *  @param completion the block that will be executed on the main thread
 *when access is granted or denied.  May be called immediately if access was
 *previously established
 */
- (void)authorize:(NotificationAuthorizationHandler)completion;

/**
 *  This is identical to the call other call, however it allows you to specify
 *your own custom text for the dialog window rather than using the standard
 *system dialog
 *
 *  @param messageTitle      custom alert message title
 *  @param message           custom alert message
 *  @param cancelTitle       custom cancel button message
 *  @param grantTitle        custom grant button message
 *  @param completion the block that will be executed on the main thread
 *when access is granted or denied.  May be called immediately if access was
 *previously established
 */
- (void)authorizeWithTitle:(NSString *)messageTitle
                   message:(NSString *__nullable)message
               cancelTitle:(NSString *)cancelTitle
                grantTitle:(NSString *)grantTitle
                completion:(NotificationAuthorizationHandler)completion;

/**
 *  Removes the apps push notification authorization at the system level and
 * clears the cached deviceID.
 */
- (void)unauthorize;

/**
 *  This callback must be called in the AppDelegate or else your push
 *notification handler may not be called
 *
 *- (void)application:(UIApplication *)application
 *didRegisterForRemoteNotificationsWithDeviceToken:(NSData *)deviceToken {
 *   [[JLPermissions sharedInstance] notificationResult:deviceToken error:nil];
 *}
 *
 *- (void)application:(UIApplication *)application
 *didFailToRegisterForRemoteNotificationsWithError:(NSError *)error {
 *   [[JLPermissions sharedInstance] notificationResult:nil error:error];
 *}
 *
 *  @param deviceToken the deviceToken from
 *didRegisterForRemoteNotificationsWithDeviceToken
 *  @param error       the error from
 *didFailToRegisterForRemoteNotificationsWithError
 */
- (void)notificationResult:(NSData *__nullable)deviceToken error:(NSError *__nullable)error;

/**
 *  The device ID that was previously obtained during an authorizeNotifications
 *call
 *
 *  @return the deviceID with <,>, and spaces removed
 */
- (NSString *__nullable)deviceID;

@end
NS_ASSUME_NONNULL_END
