#ifndef UTILS_H

#define UTILS_H
#include <stdbool.h>

typedef struct {
    char *filename;
    bool status;
} SuccessFile;

typedef struct {
    int s;
    bool verbose;
    SuccessFile success_files[10];
} Output;

bool startsWith(const char *pre, const char *str);
void printHelp();
Output initOut();

#endif
