#include <stdio.h>
#include <string.h>
#include "file.h"
#include "parse.h"
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

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
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) continue;

        char fullPath[PATH_MAX];
        snprintf(fullPath, sizeof(fullPath), "%s/%s", path, entry->d_name);

        struct stat statbuf;
        if (lstat(fullPath, &statbuf) == -1) {
            if (otp->verbose) {
                perror("lstat");
                printf("Error stating %s\n", fullPath);
            }
            continue;
        }

        if (S_ISREG(statbuf.st_mode) || S_ISLNK(statbuf.st_mode)) {
            if (unlink(fullPath) == 0) {
                if (otp->verbose) printf("Deleted: %s\n", fullPath);
            } else {
                if (otp->verbose) {
                    perror("unlink");
                    printf("Failed to delete: %s\n", fullPath);
                }
            }
        } else if (S_ISDIR(statbuf.st_mode)) {
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
