/* This may look like nonsense , but really is -*- mode : C -*- */
#include <stdlib.h>
#include <stdio.h>

/* The main thing that this program does . */
int main (void){

    size_t var = 0;
    --var;
    printf("When we decrement unsigned integer that is equal 0,\nwe get %lu\n", var);
    printf("Because the unsigned integer underflows.\n");

    return EXIT_SUCCESS;
    }
