/* Exercise 0 3 */
/* In this exercise we need to fix the program. */
/* Turns out that the program is quite similar to the one from previous exercise. */
/* Also, copying from the PDF also introduces a lot of formatting error anyway. */

/* This may look like nonsense , but really is -*- mode : C -*- */
/* The main thing that this program does . */
#include <stdlib.h>
#include <stdio.h>

int main(){
    // Declarations
    double A [5] = {
        9.0,
        2.9,
        3.E+25,
        .00007,
        };

    // Doing some work
    for (size_t i = 0; i < 5; ++i){
        printf("element %lu is %g,\tits square is %g\n" ,
        i,
        A[i],
        A[i]*A[i]);
        }
    return EXIT_SUCCESS;
    }
