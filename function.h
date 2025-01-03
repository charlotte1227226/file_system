#ifndef __FUNCTION__
#define __FUNCTION__

#include "main.h"
#include "FileSystem.h"

void ls(tDirectoryNode *target);
tDirectoryNode* cd(tDirectoryNode *current, const char *name);
void rm(tDirectoryNode *target, const char *name);
void mkdir(tDirectoryNode *target, const char *name);
void rmdir(tDirectoryNode *target, const char *name);
void put(tDirectoryNode *target, const char *name, const char *content);
void get(tDirectoryNode *target, const char *name);
void cat(tDirectoryNode *target, const char *name);
void status(tFileSystem *fileSystem);
void help();
void exit_and_img(tFileSystem *fileSystem);

#endif
