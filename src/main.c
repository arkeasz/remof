#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include "utils.h"
#include "file.h"
#include <sys/stat.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>

#define MAX_OPTIONS 6
#define MAX_VALUES 4

int main(int argc, char *argv[])  {
    int i;
    const char *values[MAX_VALUES] = {NULL};
    char *options[MAX_OPTIONS] = {NULL};
    int option_count = 0;
    int value_count = 0;

    for (i = 1; i < argc; i++)  {
        if (startsWith("--", argv[i]) || startsWith("-", argv[i]))   {
            if (option_count < MAX_OPTIONS) {
                options[option_count++] = argv[i];
            }
        } else {
            if (value_count < MAX_VALUES)   {
                values[value_count++] = argv[i];
            }
        }

    }

    for (i = 0; i < option_count; i++) {
        if (options[i] != NULL) {
            printf("Option %d: %s\n", i, options[i]);
        }
    }

    for (i = 0; i < value_count; i++)   {
        if (values[i] != NULL)  {
            FileData info = fileInfo(values[i]);
            if (info.kind == 'd')   {
                removeDir(values[i]);
            }

            if (info.kind == 'a')   {
                if (remove(values[i]) == 0) {
                    printf("File deleted successfully. (%s)\n", values[i]);
                } else {
                    printf("Error: Unable to delete the file.\n");
                }
            }
        }
    }
}
