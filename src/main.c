#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include "utils.h"

#define MAX_OPTIONS 6
#define MAX_VALUES 4

int main(int argc, char *argv[])  {
    int i;
    const char *file[MAX_VALUES] = {NULL};
    char *options[MAX_OPTIONS] = {NULL};
    int option_count = 0;
    int val_count = 0;

    for (i = 0; i < argc; i++)  {
        if (startsWith("--", argv[i]) || startsWith("-", argv[i]))   {
            if (option_count < MAX_OPTIONS) {
                options[option_count++] = argv[i];
            }
        }
    }

    for (i = 0; i < option_count; i++) {
        if (options[i] != NULL) {
            printf("Option %d: %s\n", i, options[i]);
        }
    }

    
    // if (remove(file) == 0) {
    //     printf("File deleted successfully.\n");
    // } else {
    //     printf("Error: Unable to delete the file.\n");
    // }
}
