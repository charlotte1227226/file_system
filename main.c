#include"main.h"
#include"function.h"
#include"FileSystem.h"
int main()
{
    tFileSystem *fileSystem;
    tDirectoryNode *target = NULL;
    tFileNode *target_file = NULL;
    int choice;
    char input[50];
    char command[20];
    char params[20];
    printf("1. loads from file\n");
    printf("2. create new partition in memory\n");
    scanf("%d", &choice);
    if(choice == 1)
    {
        //loads from file
    }
    else if(choice == 2)
    {
        int size;   
        printf("Input size of a new partition (example 102400 2048000)\n");
        printf("partition size= ");
        scanf("%d", &size);
        fileSystem = createFileSystem(size);
        if(fileSystem){
        printf("Create new partition in memory successfully\n");
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
        printf("'help'");
        printf("'exit and img'\n");
        printf("\n");
        while(1){
        if(target == NULL)
        {
            printf("  $$ ");
        }
        else
        {
            printf("%s $$ ", target->name);
        }
        scanf("%s", input);
        sscanf(input, "%s %s", command, params);//取得功能和參數
        if(strcmp(command, "ls") == 0){
            ls(fileSystem, target, target_file);
        }
        else if(strcmp(command, "cd") == 0){
            *target = cd(fileSystem, target, params);
        }
        else if(strcmp(command, "rm") == 0){
            rm(fileSystem, target, params);
        }
        else if(strcmp(command, "mkdir") == 0){
            mkdir(fileSystem, target, params);
        }
        else if(strcmp(command, "rmdir") == 0){
            rmdir(fileSystem, target, params);
        }
        else if(strcmp(command, "put") == 0){
            put(fileSystem, target, params);
        }
        else if(strcmp(command, "get") == 0){
            get(fileSystem, target, params);
        }
        else if(strcmp(command, "cat") == 0){
            cat(fileSystem, target, params);
        }
        else if(strcmp(command, "status") == 0){
            status(fileSystem);
        }
        else if(strcmp(command, "help") == 0){
            help();
        }
        else if(strcmp(command, "exit") == 0){
            break;
        }
        else if(strcmp(command, "img") == 0){
            break;        
        }
        else{
            printf("Command not found\n");
        }
        }
        }
        else{
            printf("Create new partition in memory failed\n");
        }
    }

}