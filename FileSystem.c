#include"FileSystem.h"
#include"function.h"

tFileSystem* createFileSystem(int size)
{
    tFileSystem *fileSystem;
    fileSystem = (tFileSystem *)malloc(sizeof(tFileSystem));
    if (fileSystem)
    {
        fileSystem->front = NULL;
        fileSystem->rear = NULL;
        fileSystem->count = 0;
        fileSystem->partition_size = size;
        fileSystem->total_inode = size / 1024;
        fileSystem->used_inode = 0;
        fileSystem->total_block = size / 1024;
        fileSystem->used_block = 0;
        fileSystem->file_block = 0;
        fileSystem->block_size = 1024;
        fileSystem->free_space = size;
    }
    return fileSystem;
}

tDirectoryNode* enqueue_directory(tFileSystem *FileSystem, tDirectoryNode *target, char* name)
{
    tDirectoryNode *newptr = NULL;
    printf("    Enqueue directory\n");
    newptr = (tDirectoryNode *)malloc(sizeof(tDirectoryNode));
    if (newptr == NULL)
    {
        printf("    Enqueue directory False!!! \n");
        return NULL;
    }
    printf("    Enqueue directory malloc done\n");
    newptr->name = (char *)malloc(strlen(name) + 1);
    printf("newptr->name = (char *)malloc(strlen(name) + 1)\n");
    for(int i = 0; i < strlen(name); i++)
    {
        newptr->name[i] = name[i];
    }
    printf("newptr->name = %s\n", newptr->name);
    newptr->level = target->level + 1;
    printf("newptr->level = target->level + 1\n");
    newptr->prev = target->prev;
    printf("newptr->prev = target->prev\n");
    newptr->next = target;
    printf("newptr->next = target\n");
    newptr->file = NULL;
    printf("newptr->file = NULL\n");
    target->prev = newptr;
    printf("    Enqueue directory done\n");
    if (newptr->prev == NULL)
    {
        if(FileSystem->front == target)
        {
            FileSystem->front = newptr;
            printf("FileSystem->front = newptr\n");
        }
        return newptr;
    }
    else
    {
        newptr->prev->next = newptr;
        printf("newptr->prev->next = newptr\n");
        return newptr;
    }
}

tFileNode* enqueue_file(tFileSystem *FileSystem,tDirectoryNode *target, char *name, char *content)
{
    tFileNode *newptr = NULL;
    newptr = (tFileNode *)malloc(sizeof(tFileNode));
    if (newptr == NULL)
    {
        printf("    Enqueue file False!!! \n");
        return NULL;
    }
    newptr->name = (char *)malloc(strlen(name) + 1);
    strcpy(newptr->name, name);
    newptr->content = (char *)malloc(strlen(content) + 1);
    strcpy(newptr->content, content);
    newptr->prev = target->file->prev;
    newptr->next = target->file;
    target->file->prev = newptr;
    if (newptr->prev == NULL)
    {
        return newptr;
    }
    else
    {
        newptr->prev->next = newptr;
        return newptr;
    }
}

tDirectoryNode *find_target_directory(tFileSystem *fileSystem, char *name)
{
    tDirectoryNode *target = fileSystem->front;
    while(target != NULL)
    {
        if(strcmp(target->name, name) == 0)
        {
            return target;
        }
        target = target->next;
    }
    return NULL;
}

tFileNode *find_target_file(tDirectoryNode *target, char *name)
{
    tFileNode *target_file = target->file;
    while(target_file != NULL)
    {
        if(strcmp(target_file->name, name) == 0)
        {
            return target_file;
        }
        target_file = target_file->next;
    }
    return NULL;
}

void dequeue_directory(tFileSystem *fileSystem, tDirectoryNode *target)
{
    if(target->prev == NULL)
    {
        fileSystem->front = target->next;
    }
    else
    {
        target->prev->next = target->next;
    }
    if(target->next == NULL)
    {
        fileSystem->rear = target->prev;
    }
    else
    {
        target->next->prev = target->prev;
    }
    free(target->name);
    free(target);
}

void dequeue_file(tFileSystem *FileSystem, tDirectoryNode *target, tFileNode *target_file)
{
    if(target_file->prev == NULL)
    {
        target->file = target_file->next;
    }
    else
    {
        target_file->prev->next = target_file->next;
    }
    if(target_file->next == NULL)
    {
        target->file->prev = target_file->prev;
    }
    else
    {
        target_file->next->prev = target_file->prev;
    }
    free(target_file->name);
    free(target_file->content);
    free(target_file);
}