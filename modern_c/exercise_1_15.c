#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <limits.h>

#define typename(x) _Generic((x), \
    _Bool: "bool", \
    unsigned char: "unsigned char", \
    unsigned short: "unsigned short", \
    unsigned int: "unsigned int", \
    unsigned long: "unsigned long", \
    unsigned long long: "unsigned long long", \
    char: "char", \
    short: "signed short", \
    int: "int", \
    long int: "long int", \
    long long int: "long long int", \
    float: "float", \
    double: "double", \
    long double: "long double", \
    default: "other")

int main(int argc, char* argv[argc + 1]){
    // Normally, in C you can't inspect a type of a variable.
    // Except for this mad trick!
    printf("Type of -1U is: %s\n", typename(-1U));
    printf("The value of -1U is: %u\n", -1U);
    printf("The maximal value of unsigned is: %u\n", UINT_MAX);
    printf("\n");

    printf("Type of -1UL is: %s\n", typename(-1UL));
    printf("The value of -1UL is: %lu\n", -1UL);
    printf("The maximal value of long unsigned is: %lu\n", ULONG_MAX);
    printf("\n");

    printf("Type of -1ULL is: %s\n", typename(-1ULL));
    printf("The value of -1ULL is: %llu\n", -1ULL);
    printf("The maximal value of long long unsigned is: %llu\n", ULLONG_MAX);

    return(EXIT_SUCCESS);
    }
