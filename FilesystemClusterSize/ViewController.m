//
//  ViewController.m
//  FilesystemClusterSize
//
//  Created by Taras on 4/21/18.
//  Copyright © 2018 Taras Melnyk. All rights reserved.
//

#import "ViewController.h"
#include "VolumeInfo.h"

@interface ViewController () {
    __weak IBOutlet UITextView *textView;
}

@end

@implementation ViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    [self printVolumeInfo];
}

- (void)printVolumeInfo
{
    char* output = volumeInfo();
    puts(output);
    textView.text = [NSString stringWithUTF8String:output];
    free(output);
}

@end
