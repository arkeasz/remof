#include <stdio.h>
#include <string.h>
#include "parse.h"
#include "utils.h"
#include <stdlib.h>
#define SIZE 6

Output initOut()    {
    Output o;
    o.verbose = false;
    o.s = 0;
    for (int i = 0; i < 10; i++) {
        o.success_files[i].filename = NULL;
        o.success_files[i].status = false;
    }
    return o;
}

Tuple initTuple(const char** a, const char** b)   {
    Tuple t;
    t.first = malloc(SIZE * sizeof(char*));
    t.second = malloc(SIZE * sizeof(char*));

    if (t.first == NULL || t.second == NULL) {
        printf(ANSI_COLOR_RED ALARM_ICON ANSI_COLOR_RESET "Error allocating memory\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < SIZE; i++) {
        t.first[i] = a[i] ? strdup(a[i]) : NULL;
        t.second[i] = b[i] ? strdup(b[i]) : NULL;
    }
    return t;
}

void printTuple(Tuple t) {
    printf("Tuple:\n\tFirst:  { ");
    for (int i = 0; i < SIZE; i++) {
        if (t.first[i] != NULL) {
            printf("%s, ", t.first[i]);
        }
    }
    printf("}\n\tSecond: { ");
    for (int i = 0; i < SIZE; i++) {
        if (t.second[i] != NULL) {
            printf("%s, ", t.second[i]);
        }
    }
    printf("}\n");
}
