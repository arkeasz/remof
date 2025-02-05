#ifndef CLI_H
#define CLI_H

#include <stddef.h> 
#include <wchar.h>
#include <stdbool.h>
#define MAX_FLAGS 16
#define MAX_VALUES 16

typedef struct CLI {
    char **flags;
    int flag_count;
    char **values;
    int values_count;
} CLI;

CLI* cli_init();

// void cli_parse(CLI* cli, int argc, char* argv[]);

// void cli_add_flag(CLI* cli, const char* name, const char* short_name);

// char* cli_get_flag_value(CLI* cli, const char* name);

// bool cli_has_flag(CLI* cli, const char* flag);

// char* cli_get_value(CLI* cli, int index);

void cli_free(CLI* cli);

#endif
