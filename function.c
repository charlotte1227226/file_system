#include "function.h"

void ls(tFileSystem* FileSystem, tDirectoryNode* target) {
    if (target == NULL) {
        target = FileSystem->root;
    }
    printf("Directories:\n");
    tDirectoryNode* child = target->child;
    while (child) {
        printf("%s\n", child->name);
        child = child->next_sibling;
    }

    printf("Files:\n");
    tFileNode* file = target->file;
    while (file) {
        printf("%s\n", file->name);
        file = file->next;
    }
    printf("ls done\n");
}

tDirectoryNode* cd(tFileSystem* FileSystem, tDirectoryNode* current, const char* name) {
    current = changeDirectory(FileSystem, current, name);
}

void rm(tDirectoryNode* target, const char* name) {
    tFileNode* file = target->file;
    tFileNode* prev = NULL;

    while (file) {
        if (strcmp(file->name, name) == 0) {
            if (prev) {
                prev->next = file->next;
            } else {
                target->file = file->next;
            }
            free(file->name);
            free(file->content);
            free(file);
            printf("rm done\n");
            return;
        }
        prev = file;
        file = file->next;
    }

    printf("No such file\n");
}

void mkdir(tFileSystem* FileSystem, tDirectoryNode* target, const char* name) {
    if (target == NULL) {
        target = FileSystem->root;
    }
    tDirectoryNode* newDir = createDirectory(FileSystem, target, name);
    if (newDir != NULL) {
        printf("mkdir done\n");
    } else {
        printf("mkdir failed\n");
    }
}


void rmdir(tDirectoryNode* target, const char* name) {
    tDirectoryNode* child = target->child;
    tDirectoryNode* prev = NULL;

    while (child != NULL) {
        if (strcmp(child->name, name) == 0) {
            if (prev) {
                prev->next_sibling = child->next_sibling;
            } 
            else {
                target->child = child->next_sibling;
            }
            deleteDirectory(child);
            printf("rmdir done\n");
            return;
        }
        prev = child;
        child = child->next_sibling;
    }

    printf("No such directory\n");
}

void put(tDirectoryNode* target, const char* name) {
     if (target == NULL) {
        printf("Error: No target directory specified.\n");
        return;
    }

    // 打開檔案
    FILE* file = fopen(name, "r");
    if (file == NULL) {
        printf("Error: Failed to open file '%s'.\n", name);
        return;
    }
    char content[2048];
    // 準備讀取檔案內容
    size_t bytesRead = fread(content, sizeof(char), sizeof(content) - 1, file);
    fclose(file); // 關閉檔案

    if (bytesRead == 0) {
        printf("Error: File '%s' is empty or could not be read.\n", name);
        return;
    }

    content[bytesRead] = '\0'; // 確保內容以 '\0' 結尾，成為有效字串

    // 將檔案內容加入虛擬檔案系統
    tFileNode* newFile = createFile(target, name, content);
    if (newFile == NULL) {
        printf("Error: Failed to create file '%s' in the virtual file system.\n", name);
    } 
    else {
        printf("File '%s' added successfully to directory '%s'.\n", name, target->name);
        printf("put done\n");
    }
}

void get(tDirectoryNode* target, const char* name) {
    tFileNode* file = target->file;
    while (file != NULL) {
        if (strcmp(file->name, name) == 0) {
            printf("content: %s\n", file->content);
            printf("get done\n");
            return;
        }
        file = file->next;
    }

    printf("No such file\n");
}

void cat(tDirectoryNode* target, const char* name) {
    tFileNode* file = target->file;
    while (file != NULL) {
        if (strcmp(file->name, name) == 0) {
            printf("%s\n", file->content);
            printf("cat done\n");
            return;
        }
        file = file->next;
    }

    printf("No such file\n");
}

void status(tFileSystem* fileSystem) {
    printf("total inode: %d\n", fileSystem->total_inode);
    printf("used inode: %d\n", fileSystem->used_inode);
    printf("total block: %d\n", fileSystem->total_block);
    printf("used block: %d\n", fileSystem->used_block);
    printf("block size: %d\n", fileSystem->block_size);
    printf("free space: %d\n", fileSystem->free_space);
    printf("status done\n");
}

void help() {
    printf("list of commands\n");
    printf("'ls' list directory\n");
    printf("'cd' change directory\n");
    printf("'rm' remove file\n");
    printf("'mkdir' make directory\n");
    printf("'rmdir' remove directory\n");
    printf("'put' put file into the space\n");
    printf("'get' get file from the space\n");
    printf("'cat' show content\n");
    printf("'status' show status\n");
    printf("'help' show this help message\n");
    printf("'exit' exit program\n");
    printf("help done\n");
}

void exit_and_img(tFileSystem* fileSystem) {
    printf("exit and img done\n");
}
