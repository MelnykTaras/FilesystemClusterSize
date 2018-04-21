//
//  AppDelegate.m
//  FilesystemClusterSize
//
//  Created by Taras on 4/21/18.
//  Copyright © 2018 Taras Melnyk. All rights reserved.
//

#import "AppDelegate.h"
#include "VolumeInfo.h"

@implementation AppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    printVolumeInfo();
    return YES;
}

@end
