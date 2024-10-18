#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[argc + 1]){
    if(argc < 4){
        printf("Not enough arguments\n\n");
        printf("I perform operations with hours in 24 hour format.\n");
        printf("Give me one number, an operation (before or after), and another number\n");
        printf("and I will perform the operation of your liking.\n");
        exit(EXIT_FAILURE);
        }

    size_t first = strtoul(argv[1], 0, 10);
    size_t second = strtoul(argv[3], 0, 10);
    char* operation = argv[2];
    size_t res;

    if(strcmp(operation, "after") == 0){
        res = (second % 24 + first % 24) % 24;
        } else if(strcmp(operation, "before") == 0){
        res = (second % 24 + 24 - first % 24) % 24; // this will prevent underflow and overflow
        } else {
        printf("Unknown operation, must be either \"before\" or \"after\".\n");
        exit(EXIT_FAILURE);
        }

    printf("%zu %s %zu is %zu\n", first, operation, second, res);

    return(EXIT_SUCCESS);
    }
