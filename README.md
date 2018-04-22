Filesystem Cluster Size
=========

Prints to Xcode console information about volumes on iOS device.

Created in order to quickly get actual [cluster size](https://en.wikipedia.org/wiki/Data_cluster) on a particular device.

## Example of output:

```
Directory on which mounted: /
Mounted filesystem: /dev/disk0s1s1
File system block size: 4 kb
Optimal transfer block size: 1 Mb
File system type name: hfs
Total data blocks in file system: 809842
Free blocks in file system: 115510
Total space: 3.09 Gb
Free space: 0.44 Gb, 14.3 %

______________________________________

Directory on which mounted: /dev
Mounted filesystem: devfs
File system block size: 0 kb
Optimal transfer block size: 0 Mb
File system type name: devfs
Total data blocks in file system: 104
Free blocks in file system: 0
Total space: 0.00 Gb
Free space: 0.00 Gb, 0.0 %

______________________________________

Directory on which mounted: /private/var
Mounted filesystem: /dev/disk0s1s2
File system block size: 4 kb
Optimal transfer block size: 1 Mb
File system type name: hfs
Total data blocks in file system: 6931598
Free blocks in file system: 660687
Total space: 26.44 Gb
Free space: 2.52 Gb, 9.5 %

______________________________________

Directory on which mounted: /Developer
Mounted filesystem: /dev/disk4
File system block size: 4 kb
Optimal transfer block size: 64 Mb
File system type name: hfs
Total data blocks in file system: 58802
Free blocks in file system: 41900
Total space: 0.22 Gb
Free space: 0.16 Gb, 71.3 %
```
