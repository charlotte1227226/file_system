#include"function.h"


void ls(tFileSystem *fileSystem, tDirectoryNode *target, tFileNode *target_file)
{
    if(target == NULL)
    {
        target = fileSystem->front;
    }
    printf("directory: \n");
    while(target != NULL)
    {
        printf("%s  ", target->name);
        target = target->next;
    }
    printf("\n");
    printf("file: \n");
    if(target_file == NULL)
    {
        // printf("111111222222");
        // target_file = target->file;
    }
    while(target_file != NULL)
    {
        printf("%s  ", target_file->name);
        target_file = target_file->next;
    }
    printf("\n");
    printf("ls done\n");
}
tDirectoryNode cd(tFileSystem *fileSystem, tDirectoryNode *target, char *name)
{
    if(strcmp(name, "..") == 0)
    {
        if(target->prev == NULL)
        {
            printf("This is the root directory\n");
            return *target;
        }
        else
        {
            return *target->prev;
        }
    }
    else
    {
        tDirectoryNode *temp = find_target_directory(fileSystem, name);
        if(temp == NULL)
        {
            printf("No such directory\n");
            return *target;
        }
        else
        {
            return *temp;
        }
    }
}

void rm(tFileSystem *fileSystem, tDirectoryNode *target, char *name)
{
    tFileNode *temp = find_target_file(target, name);
    if(temp == NULL)
    {
        printf("No such file\n");
    }
    else
    {
        dequeue_file(fileSystem, target, temp);
        printf("rm done\n");
    }
}

void mkdir(tFileSystem *fileSystem, tDirectoryNode *target, char *name)
{
    enqueue_directory(fileSystem, target, name);
    printf("mkdir done\n");
}

void rmdir(tFileSystem *fileSystem, tDirectoryNode *target, char *name)
{
    tDirectoryNode *temp = find_target_directory(fileSystem, name);
    if(temp == NULL)
    {
        printf("No such directory\n");
    }
    else
    {
        dequeue_directory(fileSystem, temp);
        printf("rmdir done\n");
    }
}

void put(tFileSystem *fileSystem, tDirectoryNode *target, char *name)
{
    char *content = (char*)malloc(sizeof(char)*100);
    printf("input content: ");
    scanf("%s", content);
    enqueue_file(fileSystem, target, name, content);
    printf("put done\n");
}

void get(tFileSystem *fileSystem, tDirectoryNode *target, char *name)
{
    tFileNode *temp = find_target_file(target, name);
    if(temp == NULL)
    {
        printf("No such file\n");
    }
    else
    {
        printf("content: %s\n", temp->content);
        printf("get done\n");
    }
}

void cat(tFileSystem *fileSystem, tDirectoryNode *target, char *name)
{
    tFileNode *temp = find_target_file(target, name);
    if(temp == NULL)
    {
        printf("No such file\n");
    }
    else
    {
        printf("content: %s\n", temp->content);
        printf("cat done\n");
    }
}

void status(tFileSystem *fileSystem)
{
    printf("total inode: %d\n", fileSystem->total_inode);
    printf("used inode: %d\n", fileSystem->used_inode);
    printf("total block: %d\n", fileSystem->total_block);
    printf("used block: %d\n", fileSystem->used_block);
    printf("file block: %d\n", fileSystem->file_block);
    printf("block size: %d\n", fileSystem->block_size);
    printf("free space: %d\n", fileSystem->free_space);
    printf("status done\n");
}

void help()
{
    printf("list of commands\n");
    printf("'ls' list directory\n");
    printf("'cd' change directory\n");
    printf("'rm' remove\n");
    printf("'mkdir' make directory\n");
    printf("'rmdir' remove directory\n");
    printf("'put' put file into the space\n");
    printf("'get' get file from the space\n");
    printf("'cat' show content\n");
    printf("'status' show status\n");
    printf("'help'\n");
    printf("'exit and img'\n");
    printf("\n");
    printf("help done\n");
}

void exit_and_img(tFileSystem *fileSystem)
{
    printf("exit and img done\n");
}
