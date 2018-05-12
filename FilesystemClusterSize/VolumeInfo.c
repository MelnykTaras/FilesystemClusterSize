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
#include <stdlib.h>
#include <string.h>

char* volumeInfo(void)
{
    struct statfs *mntbufp = NULL;
    int mountedVolumesCount = getmntinfo(&mntbufp, 0);
    char *volumeInfo[mountedVolumesCount];
    unsigned length = 0;
    
    for (int i = 0; i < mountedVolumesCount; i++)
    {
        static unsigned const kFactor = 1024;
        static unsigned const kBytesInKilobyte = kFactor;
        static unsigned const kBytesInMegabyte = kBytesInKilobyte * kFactor;
        static unsigned const kBytesInGigabyte = kBytesInMegabyte * kFactor;
        
        char *mountToName, *mountFromName, *blockSize, *ioSize, *fsTypeName, *totalBlocks, *freeBlocks, *totalSpace, *freeSpace;
        asprintf(&mountToName, "Directory on which mounted: %s\n", mntbufp[i].f_mntonname);
        asprintf(&mountFromName, "Mounted filesystem: %s\n", mntbufp[i].f_mntfromname);

        asprintf(&blockSize, "File system block size: %d kb\n", mntbufp[i].f_bsize / kBytesInKilobyte);
        asprintf(&ioSize, "Optimal transfer block size: %d Mb\n", mntbufp[i].f_iosize / kBytesInMegabyte);
        asprintf(&fsTypeName, "File system type name: %s\n", mntbufp[i].f_fstypename);
        asprintf(&totalBlocks, "Total data blocks in file system: %llu\n", mntbufp[i].f_blocks);
        asprintf(&freeBlocks, "Free blocks in file system: %llu\n", mntbufp[i].f_bfree);
        
        unsigned long long totalSpaceInBytes = mntbufp[i].f_blocks * mntbufp[i].f_bsize;
        asprintf(&totalSpace, "Total space: %.2f Gb\n", (double)totalSpaceInBytes / kBytesInGigabyte);
        
        unsigned long long freeSpaceInBytes = mntbufp[i].f_bfree * mntbufp[i].f_bsize;
        double freeSpaceInGigabytes = (double)freeSpaceInBytes / kBytesInGigabyte;
        double freeSpacePercentage = ((double)freeSpaceInBytes / totalSpaceInBytes) * 100;
        asprintf(&freeSpace, "Free space: %.2lf Gb, %.1lf %%\n\n", freeSpaceInGigabytes, freeSpacePercentage);
        
        char *combinedInfo;
        static char const delimiter[] = "______________________________________\n\n";
        asprintf(&combinedInfo, "%s%s%s%s%s%s%s%s%s%s", delimiter, mountToName, mountFromName, blockSize, ioSize, fsTypeName, totalBlocks, freeBlocks, totalSpace, freeSpace);
        
        free(mountToName);
        free(mountFromName);
        free(blockSize);
        free(ioSize);
        free(fsTypeName);
        free(totalBlocks);
        free(freeBlocks);
        free(totalSpace);
        free(freeSpace);
        
        volumeInfo[i] = combinedInfo;
        length += strlen(combinedInfo);
    }
    
    char *output = malloc(length - mountedVolumesCount + 1);
    memset(output, '\0', sizeof(length + 1));
    
    for (int i = 0; i < mountedVolumesCount; i++) {
        strcat(output, volumeInfo[i]);
        free(volumeInfo[i]);
    }
    
    return output;
}
