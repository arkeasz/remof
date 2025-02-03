#include <stdio.h>
#include "parse.h"

#define SIZE 6

Tuple initTuple(char** a[], char** b[])   {
    Tuple t;
    for (int i = 0; i < SIZE; i++) {
        t.first[i] = a[i];
        t.second[i] = b[i];
    }
    return t;
}

void printTuple(Tuple t) {
    printf("Tuple:\nFirst:  { ");
    for (int i = 0; i < SIZE; i++) {
        printf("%s ", t.first[i]);
    }
    printf("}\nSecond: { ");
    for (int i = 0; i < SIZE; i++) {
        printf("%s ", t.second[i]);
    }
    printf("}\n");
}
