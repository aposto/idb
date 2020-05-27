/*
 * Copyright (c) Facebook, Inc. and its affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#import <Foundation/Foundation.h>

#import <FBControlCore/FBControlCore.h>

NS_ASSUME_NONNULL_BEGIN

@class FBProcessInfo;
@class FBSimulator;

/**
 A Strategy for Terminating the Suprocesses of a Simulator, whether they be Applications or regular spawned processes.
 */
@interface FBSimulatorSubprocessTerminationStrategy : NSObject

#pragma mark Initializers

/**
 Creates and Returns a Strategy for Terminating the Subprocesses of a Simulator's 'launchd_sim'

 @param simulator the Simulator to Terminate Processes.
 */
+ (instancetype)strategyWithSimulator:(FBSimulator *)simulator;

#pragma mark Public Methods

/**
 Terminates a Process for a Simulator.
 Will fail if the Process does not belong to the Simulator.
 Uses the highest-level API available for doing-so.

 @param process the Process to terminate.
 @return A future that resolves successfully when the process is terminated.
 */
- (FBFuture<NSNull *> *)terminateProcess:(FBProcessInfo *)process;

/**
 Terminates an Application Directly.

 @param bundleID the Bundle ID the bundle ID of the Application to terminate.
 @return a future that resolves successfully when the application is terminated.
 */
- (FBFuture<NSNull *> *)terminateApplication:(NSString *)bundleID;

@end

NS_ASSUME_NONNULL_END
