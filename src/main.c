#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include "utils.h"
#include "file.h"
#include "parse.h"
#include "cli.h"
#include <sys/stat.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>

int main(int argc, char *argv[])  {
    int i;
    CLI* cli = cli_init();
    cli_parse(cli, argc, argv);

    Output otp = initOut();

    for (i = 0; i < cli->flag_count; i++) {
        if (cli->flags[i] != NULL) {
            if (strcmp(cli->flags[i], "--help") == 0 || strcmp(cli->flags[i], "-?") == 0) {
                printHelp();
                return 0;
            }
            if (strcmp(cli->flags[i], "--verbose") == 0 || strcmp(cli->flags[i], "-v") == 0) {
                otp.verbose = true;
            }
        }
    }

    for (i = 1; i < cli->values_count; i++)   {
        if (cli->values[i] != NULL)  {
            FileData info = fileInfo(cli->values[i]);
            SuccessFile sf;
            
            if (info.kind == 'd')   {
                removeDir(cli->values[i], &otp);
                sf.filename = cli->values[i];
                sf.status = true;
                otp.success_files[otp.s] = sf;
                otp.s += 1;
            }

            if (info.kind == 'a')   {
                if (remove(cli->values[i]) == 0) {
                    if (otp.verbose) printf("File deleted successfully." ANSI_COLOR_GREEN CHECK_ICON "(%s)\n", cli->values[i]);
                    sf.filename = cli->values[i];
                    sf.status = true;
                    otp.success_files[otp.s] = sf;
                    otp.s += 1;
                } else {
                    if (otp.verbose) printf("Error: Unable to delete the file." ANSI_COLOR_RED ALARM_ICON "(%s)\n", cli->values[i]);
                }
            }
        }
    }

    if (otp.s > 0) {
        printf("File deleted successfully.\n");
        for (i = 0; i < otp.s; i++) {
            if (otp.success_files[i].status) {
                printf(ANSI_COLOR_GREEN CHECK_ICON ANSI_COLOR_RESET "%s\n", otp.success_files[i].filename);
            }
        }
    }

    cli_free(cli);
}
