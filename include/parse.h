#ifndef PARSE_H

#define PARSE_H
#include <stdbool.h>
#include "utils.h"

typedef struct {
    char** first;
    char** second;
} Tuple;

typedef struct {
    int s;
    bool verbose;
    SuccessFile success_files[10];
} Output;

Output initOut();

Tuple initTuple(const char** a, const char** b);
void printTuple(Tuple t);

#endif
