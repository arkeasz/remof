#include <stdio.h>
#include <string.h>
#include "file.h"
#include <sys/stat.h>

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
