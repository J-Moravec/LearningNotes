#include <stdlib.h>
#include <stdio.h>

/* lower and upper iteration limits centered around 1.0 */
static double const eps1m01 = 1.0 - 0x1P-01; // this is just 1 - 1 / 2^1 = 0.5
static double const eps1p01 = 1.0 + 0x1P-01; // this is just 1 + 1 / 2^1 = 1.5
static double const eps1m24 = 1.0 - 0x1P-24; // this is 1 - 1 / 2^24 -- close to 1
static double const eps1p24 = 1.0 + 0x1P-24; // this is 1 + 1 / 2^24 -- close to 1

int main(int argc, char* argv[argc+1]){
    for(int i = 1; i < argc; ++i){           // process args
        double const a = strtod(argv[1], 0); // arg -> double
        double x = 1.0;

        printf("Solving for %f, initial value of x=%f\n", a, x);
        for(;;){
            // Step one, get closer before we start mutliplicative inverse
            double prod = a * x;
            if(prod < eps1m01){
                x *= 2.0;
                printf("1 Step: Getting closer x=%f\n", x);
                } else if(eps1p01 < prod){
                x *= 0.5;
                printf("1 Step: Getting closer x=%f\n", x);
                } else {
                break;
                }
            }

        printf("Starting multiplicative inverse for %f, with x=%f\n", a, x);
        size_t i = 1;
        for(;;){
            double prod = a * x;
            if((prod < eps1m24) || (eps1p24 < prod)){
                x *= (2.0 - prod); // Heron' approximation according to the book
                                   // it is multiplicative inverse,
                                   // but Heron's approximation is about square root
                printf("2 Step: iteration %lu, x=%f\n", i++, x);
                } else {
                break;
                }
            }
        printf("heron: a=%.5e,\tx=%.5e,\ta*x=%.12f\n", a, x, a * x);
        }
    return EXIT_SUCCESS;
    }
