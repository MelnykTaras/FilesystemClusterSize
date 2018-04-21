//
//  VolumeInfo.c
//  FilesystemClusterSize
//
//  Created by Taras on 4/21/18.
//  Copyright © 2018 Taras Melnyk. All rights reserved.
//

#include "VolumeInfo.h"
#include <stdio.h>
#include <sys/mount.h>

void printVolumeInfo(void)
{
    static unsigned const kFactor = 1024;
    static unsigned const kBytesInKilobyte = kFactor;
    static unsigned const kBytesInMegabyte = kBytesInKilobyte * kFactor;
    static unsigned const kBytesInGigabyte = kBytesInMegabyte * kFactor;
    
    struct statfs *mntbufp = NULL;
    int mountedVolumesCount = getmntinfo(&mntbufp, 0);
    
    for (int i = 0; i < mountedVolumesCount; i++)
    {
        puts("______________________________________\n");
        printf("Directory on which mounted: %s\n", mntbufp[i].f_mntonname);
        printf("Mounted filesystem: %s\n", mntbufp[i].f_mntfromname);
        printf("File system block size: %d kb\n", mntbufp[i].f_bsize / kBytesInKilobyte);
        printf("Optimal transfer block size: %d Mb\n", mntbufp[i].f_iosize / kBytesInMegabyte);
        printf("File system type name: %s\n", mntbufp[i].f_fstypename);
        printf("Total data blocks in file system: %llu\n", mntbufp[i].f_blocks);
        printf("Free blocks in file system: %llu\n", mntbufp[i].f_bfree);
        
        unsigned long long totalSpaceInBytes = mntbufp[i].f_blocks * mntbufp[i].f_bsize;
        printf("Total space: %.2f Gb\n", (double)totalSpaceInBytes / kBytesInGigabyte);
        
        unsigned long long freeSpaceInBytes = mntbufp[i].f_bfree * mntbufp[i].f_bsize;
        float freeSpaceInGigabytes = (double)freeSpaceInBytes / kBytesInGigabyte;
        float freeSpacePercentage = ((double)freeSpaceInBytes / totalSpaceInBytes) * 100;
        printf("Free space: %.2f Gb, %.1f %%\n\n", freeSpaceInGigabytes, freeSpacePercentage);
    }
}
