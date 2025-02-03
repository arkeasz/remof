#ifndef PARSE_H

#define PARSE_H

#define SIZE 6

typedef struct {
    char** first[SIZE];
    char** second[SIZE];
} Tuple;

Tuple initTuple(char** a[], char** b[]);
void printTuple(Tuple t);

#endif
