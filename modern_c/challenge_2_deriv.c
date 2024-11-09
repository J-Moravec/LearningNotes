#include <stdlib.h>
#include <stdio.h>
#include <float.h> // for DBL_EPSILON
#include <math.h> // for sqrt and pow
#include <assert.h>

double derivation(double f(double), double x){
    // best h value
    double h = sqrt(DBL_EPSILON);

    // symmetric difference quotient
    return( (f(x + h) - f(x - h)) / (2 * h) );
    }


// some functions with known derivative:
// Function factories are hard :(
double polynom1(double x){
    // f'(x) = 2
    return(2 * x - 1);
    }

double polynom2(double x){
    // f(x) = x^2 - x + 2
    // f'(x) = 2x - 1 
    return(pow(x, (double) 2) - 1 * x + 3);
    }

double polynom3(double x){
    // f(x) = 1/3 x^3 - (1/2) x^2 + 3x - 4
    // f'(x) = x^2 - x + 3
    return((1.0/3.0) * pow(x, (double) 3) - (1.0/2.0) * pow(x, (double) 2) + 3 * x - 4);
    }


int equal(double x, double y){
    return(fabs(x - y) < 1e-8);
    }


int main(){
    assert(equal(derivation(polynom1, 1), 2));
    assert(equal(derivation(polynom1, 5), 2));
    assert(equal(derivation(polynom1, 200), 2));

    assert(equal(derivation(polynom2, 1), polynom1(1)));
    assert(equal(derivation(polynom2, 5), polynom1(5)));
    assert(equal(derivation(polynom2, 200), polynom1(200)));

    assert(equal(derivation(polynom3, 1), polynom2(1)));
    assert(equal(derivation(polynom3, 5), polynom2(5)));
    assert(equal(derivation(polynom3, 200), polynom2(200)));

    assert(equal(derivation(sin, 1), cos(1.0)));
    assert(equal(derivation(sin, 5), cos(5.0)));
    assert(equal(derivation(sin, 200), cos(200.0)));
    }
