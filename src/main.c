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
#define MAX_VALUES 10
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

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

    Output otp = initOut();

    for (i = 0; i < option_count; i++) {
        if (options[i] != NULL) {
            if (strcmp(options[i], "--help") == 0 || strcmp(options[i], "-?") == 0) {
                printHelp();
                return 0;
            }
            if (strcmp(options[i], "--verbose") == 0 || strcmp(options[i], "-v") == 0) {
                otp.verbose = true;
            }
        }
    }

    for (i = 0; i < value_count; i++)   {
        if (values[i] != NULL)  {
            FileData info = fileInfo(values[i]);
            SuccessFile sf;
            if (info.kind == 'd')   {
                removeDir(values[i], &otp);
                sf.filename = values[i];
                sf.status = true;
                otp.success_files[otp.s] = sf;
                otp.s += 1;
            }

            if (info.kind == 'a')   {
                if (remove(values[i]) == 0) {
                    if (otp.verbose) printf("File deleted successfully. (%s)\n", values[i]);
                    sf.filename = values[i];
                    sf.status = true;
                    otp.success_files[otp.s] = sf;
                    otp.s += 1;
                } else {
                    if (otp.verbose) printf("Error: Unable to delete the file. (%s)\n", values[i]);
                }
            }
        }
    }

    if (otp.s > 0) {
        printf("File deleted successfully.\n");
        for (i = 0; i < otp.s; i++) {
            if (otp.success_files[i].status) {
                printf(ANSI_COLOR_GREEN "\xE2\x9C\x85" ANSI_COLOR_RESET " %s\n", otp.success_files[i].filename);
            }
        }
    }

}
