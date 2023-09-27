#include "file_sort.h"

#include "string.h"
#include "esp_err.h"
#include "esp_log.h"

static const char *TAG = "file_sort";

void file_list_sort(const char *dirpath, file_info_t **file_info_list)
{
    DIR *dir = NULL;
    struct dirent *entry = NULL;
    struct stat entry_stat;

    if ((dir = opendir(dirpath)) == NULL)
    {
        if (!dir)
        {
            ESP_LOGE(TAG, "Failed to stat dir");
        }
        return;
    }
    else
    {
        char entrypath[300];
        // file_info *file_info_list = NULL;
        file_info_t *file_info_new = NULL;
        file_info_t *file_comparison = NULL;
        file_info_t *prev_file = NULL;
        // sdcard 列表
        while ((entry = readdir(dir)) != NULL)
        {
            memset(entrypath, 0, sizeof(entrypath));
            sprintf(entrypath, "%s/%s", dirpath, entry->d_name);
            // 查看文件信息
            if (stat(entrypath, &entry_stat) == -1)
            {
                ESP_LOGE(TAG, "Failed to stat %d : %s", entry->d_type, entry->d_name);
                continue;
            }
            // 只要常规文件
            if (S_ISREG(entry_stat.st_mode))
            {
                // 建立文件信息
                file_info_new = (file_info_t *)malloc(sizeof(file_info_t));
                if (file_info_new != NULL)
                {
                    strncpy(file_info_new->file_name, entry->d_name, strlen(entry->d_name) + 1);
                    file_info_new->file_type = entry->d_type;
                    file_info_new->file_size = entry_stat.st_size;
                    file_info_new->file_msec = entry_stat.st_mtime;
                    file_info_new->next_file = NULL;
                }
                // 开始排序
                if (*file_info_list == NULL)
                {
                    *file_info_list = file_info_new;
                }
                else
                {
                    ESP_LOGI(TAG, "sort: %s", file_info_new->file_name);
                    // 链表第一个
                    file_comparison = *file_info_list;
                    while (1)
                    {
                        double diff = difftime(file_info_new->file_msec, file_comparison->file_msec);
                        ESP_LOGI(TAG, "current: %s , new: %s, diff: %f", file_comparison->file_name, file_info_new->file_name, diff);

                        // 判断时间大的排后
                        if (diff > 0)
                        {
                            // 下一个存在,继续对比
                            if (file_comparison->next_file != NULL)
                            {
                                prev_file = file_comparison;
                                file_comparison = file_comparison->next_file;
                                ESP_LOGI(TAG, "find next...");
                            }
                            else
                            {
                                // 到末尾
                                file_comparison->next_file = file_info_new;
                                file_comparison = NULL;
                                prev_file = NULL;
                                ESP_LOGI(TAG, "pos right end.");
                                break;
                            }
                        }
                        else
                        {
                            // 排前
                            file_info_new->next_file = file_comparison;
                            if (prev_file != NULL)
                            {
                                prev_file->next_file = file_info_new;
                                ESP_LOGI(TAG, "pos left end.");
                            }
                            else
                            {
                                // 更新第一个
                                *file_info_list = file_info_new;
                                ESP_LOGI(TAG, "pos first end.");
                            }
                            file_comparison = NULL;
                            prev_file = NULL;
                            break;
                        }
                    }
                }
            }
        }
        closedir(dir);
    }
}