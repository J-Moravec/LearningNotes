#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char* argv[argc + 1]){
    uint16_t number = 1U;

    printf("First, we print the size, minimum, and maximum of uint16 types:\n");
    // UINT16_WIDTH in C23
    printf("size: %lu bytes, %lu bits\n", sizeof(number), 8U*sizeof(number));
    printf("min: %u\n", 0U); // min of unsigned is always 0
    printf("max: %u\n", UINT16_MAX);

    int16_t number2 = 1;
    printf("\nNow we print the size, minimum, and maximum of nt16 types:\n");
    // UINT16_WIDTH in C23
    printf("size: %lu bytes, %lu bits\n", sizeof(number2), 8U*sizeof(number2));
    printf("min: %d\n", INT16_MIN);
    printf("max: %d\n", INT16_MAX);


    printf(
        "\nIt would be cool if we could enforce numeric literals\n"
        "to follow the types of or choice, such as fixed-width types\n"
        "but unfortunatlly, we can't.\n"
        "So we got at least some nice exercise with fixed-width type\n"
        "and also automatic concatenating of character literals.\n\n"
        );

    int16_t hex_s1 = 0x7FFF;
    int16_t hex_s2 = -0x8000;
    uint16_t hex_1 = 0x7FFF;
    uint16_t hex_2 = -0x8000;

    printf("int16_t 0x7FFF is %d\n", hex_s1);
    printf("int16_t -0x8000 is %d\n", hex_s2);
    printf("uint16_t 0x7FFF is %u\n", hex_1);
    printf("uint16_t -0x8000 is %u\n", hex_2);

    printf(
        "\nI am not a bit perplexed on how exactly is this useful.\n"
        "So on compile time, the literals are converted to some type.\n"
        "This can be then converted according to the type of the variable\n"
        "we are using to store the number.\n"
        "Maybe I am not getting something, or it is because while I am using\n"
        "fixed-width type, the conversion mentioned above happens with much wider\n"
        "types (int is 32 bit, and long 64 bit).\n"
        "So unless there is a way to enforce a byte width for ints, I can't\n"
        "finish the exercise as written, because all numbers I got for my\n"
        "fixed width integers (signed and unsigned) are as expected.\n"
        "Or maybe the point was fitting -32768 into unsigned with max 65535?\n"
        );

    return(EXIT_SUCCESS);
    }
