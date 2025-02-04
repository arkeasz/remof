#include <stdio.h>
#include <string.h>
#include "file.h"
#include "parse.h"
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include <stdlib.h>

FileData fileInfo(const char *filename) {
    struct stat file_stat;
    FileData fi;

    if (stat(filename, &file_stat) == -1) {
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

void removeDir(const char *path, Output *otp)  {
    DIR *dir = opendir(path);

    if (dir == NULL) {
        return;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL)  {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char fullPath[1024];
        snprintf(fullPath, sizeof(fullPath), "%s/%s", path, entry->d_name);

        if (entry->d_type == DT_REG) {
            if (remove(fullPath) == 0) {
                if (otp->verbose) printf("File deleted successfully. (%s)\n", entry->d_name);
            } else {
                if (otp->verbose) printf("Error: Unable to delete the file.\n");
            }
        } else if (entry->d_type == DT_DIR) {
            removeDir(fullPath, otp);
        }
    }

    closedir(dir);

    if (rmdir(path) == 0) {
        if (otp->verbose) printf("Directory deleted successfully. (%s)\n", path);
    } else {
        if (otp->verbose) perror("rmdir");
    }
}
