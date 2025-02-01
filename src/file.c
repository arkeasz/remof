#include <stdio.h>
#include <string.h>
#include "file.h"
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>

FileData fileInfo(const char *filename) {
    struct stat file_stat;
    FileData fi;

    if (stat(filename, &file_stat) == -1) {
        perror("Error to get metadata\n");
        fi.kind = 'e';
        return fi;
    }

    if (S_ISDIR(file_stat.st_mode)) {
        fi.kind = 'd';
    } else {
        fi.kind = 'a';
    }

    return fi;
}

void removeDir(const char *path)  {
    DIR *dir = opendir(path);

    if (dir == NULL) {
        perror("opendir");
        return;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL)  {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char fullPath[1024];
        snprintf(fullPath, sizeof(fullPath), "%s/%s", path, entry->d_name);

        FileData info = fileInfo(fullPath);
        if (info.kind == 'd')   {
            removeDir(fullPath);
        }

        if (info.kind == 'a')   {
            if (remove(fullPath) == 0) {
                printf("File deleted successfully. (%s)\n", entry->d_name);
            } else {
                printf("Error: Unable to delete the file.\n");
            }
        }
        printf("%s\n", entry->d_name);
    }

    closedir(dir);

    if (rmdir(path) == 0) {
        printf("Directory deleted successfully. (%s)\n", path);
    } else {
        perror("rmdir");
    }
}
