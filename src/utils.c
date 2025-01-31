#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "utils.h"

bool startsWith(const char *pre, const char *str)   {
    size_t lenpre = strlen(pre),
           lenstr = strlen(str);
    return lenstr < lenpre ? false : memcmp(pre, str, lenpre) == 0;
}
