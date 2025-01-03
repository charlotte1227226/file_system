#ifndef __FILESYSTEM__
#define __FILESYSTEM__

typedef struct FileNode//當前目錄(檔案夾)的檔案資訊(檔名、內容)
{
    char* name;//檔名
    char* content;//檔案內容
    struct FileNode* prev;
    struct FileNode* next;//下一個檔案
}tFileNode;

typedef struct DirectoryNode//當前目錄(檔案夾)的資訊
{
    int level;//目錄的層級
    char* name;
    struct DirectoryNode* prev;
    struct DirectoryNode* next;
    struct FileNode* file;
}tDirectoryNode;

typedef struct FileSystem//檔案系統(目錄結構)
{
    tDirectoryNode *front;//目錄結構的前端(第一層目錄)
    tDirectoryNode *rear;//目錄結構的後端(最後一層目錄)
    int count;
    int partition_size;
    int total_inode;
    int used_inode;
    int total_block;
    int used_block;
    int file_block;
    int block_size;
    int free_space;
}tFileSystem;


tFileSystem* createFileSystem(int size);
tDirectoryNode* enqueue_directory(tFileSystem *FileSystem, tDirectoryNode *target, char* name);//新增目錄
tFileNode* enqueue_file(tFileSystem *FileSystem, tDirectoryNode *target, char *name, char *content);//新增檔案

tDirectoryNode *find_target_directory(tFileSystem *fileSystem, char *name);//找尋目標目錄
tFileNode *find_target_file(tDirectoryNode *target, char *name);//找尋目標檔案


void dequeue_directory(tFileSystem *fileSystem, tDirectoryNode *target);//刪除目錄
void dequeue_file(tFileSystem *FileSystem, tDirectoryNode *target, tFileNode *target_file);//刪除檔案

#endif