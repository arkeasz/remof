#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "utils.h"
#include <sys/stat.h>

void printHelp()    {
    printf("Usage: rm [OPTION]... [FILE]...\n"
           "Remove (unlink) the FILE(s)\n"
           "Options:\n"
           "  --help, -?      Show this help message\n"
           "  --verbose, -v   Enable verbose output\n");
}

bool startsWith(const char *pre, const char *str)   {
    size_t lenpre = strlen(pre),
           lenstr = strlen(str);
    return lenstr < lenpre ? false : memcmp(pre, str, lenpre) == 0;
}
