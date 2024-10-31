#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc, char* argv[argc + 1]){
    int int_num = 1;
    long int long_num = 1;
    long long int long_long_num = 1;


    printf("First, we print sizes, minimum, and maximum of signed types:\n");
    printf("Size of:\n");
    printf("              int: %lu min: %d max: %d\n", sizeof(int_num), INT_MIN, INT_MAX);
    printf("         long int: %lu min: %ld max: %ld\n", sizeof(long_num), LONG_MIN, LONG_MAX);
    printf("    long long int: %lu min: %lld max: %lld\n", sizeof(long_long_num), LLONG_MIN, LLONG_MAX);
    // Turns out that on my platform, long long has the same size as long,
    // so we cannot fulfill the exercise about promoting LONG_MAX -1 to long long

    printf("INT_MAX = 2^31 - 1 = %ld\n", 2147483648 - 1); // promoted to long
    printf("INT_MIN = -2^32 = %ld\n", -2147483648); // promoted to long
    // printf("LONG_MAX = 2^63 - 1 = %ld\n", -(LONG_MAX + 1)); would overflow so won't compile

    return(EXIT_SUCCESS);
    }
