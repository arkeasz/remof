#ifndef UTILS_H

#define UTILS_H
#include <stdbool.h>

#ifndef CONSTANTS
#define CONSTANTS
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"
#define ALARM_ICON "\xF0\x9F\x9A\xA8 "
#define CHECK_ICON "\xE2\x9C\x85 "
#endif

typedef struct {
    char *filename;
    bool status;
} SuccessFile;


bool startsWith(const char *pre, const char *str);
void printHelp();

#endif
