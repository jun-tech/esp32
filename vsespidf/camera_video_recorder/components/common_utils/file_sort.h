#ifndef FILE_SORT_H
#define FILE_SORT_H

// sdcard begin
#include <sys/unistd.h>
#include <sys/stat.h>
#include "dirent.h"
#include <fcntl.h>

// 文件结构
typedef struct file_info
{
    char file_name[50];
    int file_type;
    off_t file_size;
    long file_msec;
    struct file_info *next_file;

} file_info_t;

void file_list_sort(const char *dirpath, file_info_t **file_info_list);

#endif