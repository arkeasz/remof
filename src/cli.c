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
    cli->flags = NULL;
    cli->values =  NULL;

    return cli;
}

void cli_free(CLI* cli) {
    if (cli == NULL)    {
        return;
    }

    if (cli->flags) {
        for (int i = 0; i < cli->flag_count; i++) {
            free(cli->flags[i]);
        }
        free(cli->flags);
    }

    if (cli->values)    {
        for (int i = 0; i < cli->values_count; i++) {
            free(cli->values[i]);
        }
        free(cli->values);
    }

    free(cli);
}
