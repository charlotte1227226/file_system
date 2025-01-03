#ifndef __FUNCTION__
#define __FUNCTION__

#include "main.h"
#include "FileSystem.h"


void our_malloc(int mem_location, int data_type, int size);
void our_free(int mem_location);

void ls(tFileSystem *fileSystem, tDirectoryNode *target, tFileNode *target_file);
tDirectoryNode cd(tFileSystem *fileSystem, tDirectoryNode *target, char *name);
void rm(tFileSystem *fileSystem, tDirectoryNode *target, char *name);
void mkdir(tFileSystem *fileSystem, tDirectoryNode *target, char *name);
void rmdir(tFileSystem *fileSystem, tDirectoryNode *target, char *name);
void put(tFileSystem *fileSystem, tDirectoryNode *target, char *name);
void get(tFileSystem *fileSystem, tDirectoryNode *target, char *name);
void cat(tFileSystem *fileSystem, tDirectoryNode *target, char *name);
void status(tFileSystem *fileSystem);
void help();
void exit_and_img(tFileSystem *fileSystem);


#endif