#include "main.h"
#include "function.h"
#include "FileSystem.h"

int main() {
    tFileSystem* fileSystem;
    tDirectoryNode* target = NULL;
    int choice;
    char input[50];
    char command[20];
    char params[20];

    printf("1. Load from file\n");
    printf("2. Create new partition in memory\n");
    scanf("%d", &choice);
    getchar(); // 清除緩衝區中的換行符

    if (choice == 1) {
        // TODO: Implement loading from file
        printf("Loading from file not implemented.\n");
    } else if (choice == 2) {
        int size;
        printf("Input size of a new partition (example: 102400, 2048000)\n");
        printf("Partition size = ");
        scanf("%d", &size);
        getchar(); // 清除緩衝區中的換行符

        fileSystem = createFileSystem(size);
        target = fileSystem->root;
        if (fileSystem != NULL) {
            printf("Create new partition in memory successfully\n");
            printf("List of commands:\n");
            printf("'ls' - list directory\n");
            printf("'cd' - change directory\n");
            printf("'rm' - remove file\n");
            printf("'mkdir' - make directory\n");
            printf("'rmdir' - remove directory\n");
            printf("'put' - put file into the space\n");
            printf("'get' - get file from the space\n");
            printf("'cat' - show file content\n");
            printf("'status' - show file system status\n");
            printf("'help' - show help\n");
            printf("'exit' - exit program\n");

            while (1) {
                if (target == NULL) {
                    printf("  $$ ");
                } else {
                    printf("%s $$ ", target->name);
                }

                if (fgets(input, sizeof(input), stdin) == NULL) {
                    printf("\n");
                    continue;
                }

                input[strcspn(input, "\n")] = 0; // 移除換行符
                if (strlen(input) == 0) {
                    printf("\n");
                    continue;
                }
                int matched = sscanf(input, "%s %s", command, params);
                if (matched == 1) {
                    strcpy(params, ""); // 沒有參數，初始化 params
                }

                if (strcmp(command, "ls") == 0) {
                    ls(fileSystem, target);
                } else if (strcmp(command, "cd") == 0) {
                    target = cd(fileSystem, target, params);
                } else if (strcmp(command, "rm") == 0) {
                    rm(target, params);
                } else if (strcmp(command, "mkdir") == 0) {
                    mkdir(fileSystem, target, params);
                } else if (strcmp(command, "rmdir") == 0) {
                    rmdir(target, params);
                } else if (strcmp(command, "put") == 0) {
                    printf("Enter file content: ");
                    char content[100];
                    fgets(content, sizeof(content), stdin);
                    content[strcspn(content, "\n")] = 0; // 移除換行符
                    put(target, params, content);
                } else if (strcmp(command, "get") == 0) {
                    get(target, params);
                } else if (strcmp(command, "cat") == 0) {
                    cat(target, params);
                } else if (strcmp(command, "status") == 0) {
                    status(fileSystem);
                } else if (strcmp(command, "help") == 0) {
                    help();
                } else if (strcmp(command, "exit") == 0) {
                    break;
                } else {
                    printf("Command not found\n");
                }
            }
        } else {
            printf("Create new partition in memory failed\n");
        }
    }

    return 0;
}
