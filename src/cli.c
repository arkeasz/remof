#include <stdio.h>
#include <string.h>
#include "parse.h"
#include "utils.h"
#include <stdlib.h>
#include "cli.h"

CLI* cli_init() {
    CLI* cli = (CLI*)malloc(sizeof(CLI));
    if (cli == NULL)    {
        return NULL;
    }

    cli->flag_count = 0;
    cli->values_count = 0;
    cli->flags = (char**)malloc(MAX_FLAGS * sizeof(char*));
    cli->values =  (char**)malloc(MAX_VALUES * sizeof(char*));

    if (cli->flags == NULL || cli->values == NULL) {
        free(cli->flags);
        free(cli->values);
        free(cli);
        return NULL;
    }

    return cli;
}

void cli_free(CLI* cli) {
    if (cli == NULL)    {
        return;
    }

    for (size_t i = 0; i < cli->flag_count; i++) {
        free(cli->flags[i]);
    }
    free(cli->flags);

    for (size_t i = 0; i < cli->values_count; i++) {
        free(cli->values[i]);
    }
    free(cli->values);

    free(cli);
}

void cli_parse(CLI* cli, int argc, char* argv[]) {
    if (cli == NULL) return;

    for (size_t i = 0; i < argc; i++)   {
        if (startsWith("--", argv[i]) || startsWith("-", argv[i]))   {
            if (cli->flag_count < MAX_FLAGS)    {
                cli->flags[cli->flag_count] = strdup(argv[i]);
                ++cli->flag_count;
            }
        } else {
            if (cli->values_count < MAX_VALUES) {
                cli->values[cli->values_count] = strdup(argv[i]);
                ++cli->values_count;
            }
        }
    }
};

void print_cli_data(CLI* cli) {
    if (cli == NULL) return;
    printf("%d\n", cli->flag_count);
    printf("%d\n", cli->values_count);
    for (size_t i = 0; i < cli->flag_count; i++) {
        printf("flags: %s\n", cli->flags[i]);
    }

    for (size_t i = 0; i < cli->values_count; i++) {
        printf("values: %s\n", cli->values[i]);
    }
}
