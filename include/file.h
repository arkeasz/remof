#ifndef FILE_H

#define FILE_H
#include "utils.h"
#include "parse.h"

typedef struct {
    char kind; /* d: directory | a: archive | e: error*/
} FileData;

FileData fileInfo(const char *filename);
void removeDir(const char *path, Output *otp);

#endif
