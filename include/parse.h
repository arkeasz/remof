#ifndef PARSE_H

#define PARSE_H
#include <stdbool.h>
#include "utils.h"

typedef struct {
    int s;
    bool verbose;
    SuccessFile success_files[10];
} Output;

Output initOut();

typedef struct {
    Output otp;
    Tuple vals;
} CLI;

typedef struct {
    char** first;
    char** second;
} Tuple;

void initCLI(int arglen, char *args[])
Tuple initTuple(const char** a, const char** b);
void printTuple(Tuple t);

#endif
