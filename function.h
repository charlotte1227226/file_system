#ifndef __FUNCTION__
#define __FUNCTION__

#include "main.h"
#include "FileSystem.h"

void ls(tFileSystem *FileSystem, tDirectoryNode *target);
tDirectoryNode* cd(tFileSystem* FileSystem, tDirectoryNode *current, const char *name);
void rm(tDirectoryNode *target, const char *name);
void mkdir(tFileSystem* FileSystem, tDirectoryNode *target, const char *name);
void rmdir(tDirectoryNode *target, const char *name);
void put(tDirectoryNode *target, const char *name, const char *content);
void get(tDirectoryNode *target, const char *name);
void cat(tDirectoryNode *target, const char *name);
void status(tFileSystem *fileSystem);
void help();
void exit_and_img(tFileSystem *fileSystem);

#endif
