#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    long double P;
    long double Q;
    long double R;
} PQR;


void print_pqr(PQR x){
    printf("P: %Lf\nQ: %Lf\nR: %Lf\n\n", x.P, x.Q, x.R);
    }


PQR binary_split(long int a, long int b){
    PQR pqr;
    if(b == (a + 1)){
        long double P = -((6 * a - 1) * (2 * a - 1) * (6 * a - 5));
        long double Q = 10939058860032000 * a * a * a;
        long double R = P * (545140134 * a + 13591409);
        pqr = (PQR) {P, Q, R};
        } else {
        long int m = (a + b) / 2;
        PQR pqr_am = binary_split(a, m);
        PQR pqr_mb = binary_split(m, b);

        pqr = (PQR) {
            pqr_am.P * pqr_mb.P,
            pqr_am.Q * pqr_mb.Q,
            pqr_mb.Q * pqr_am.R + pqr_am.P * pqr_mb.R
            };
        }
    return(pqr);
    }


long double chudnovsky(long int n){
    if(n == 1){
        printf("Undefined for n == 1\n");
        return(3);
        }

    PQR pqr = binary_split(1, n);

    long double pi =
        (426880 * sqrtl(10005) * pqr.Q) /
        (13591409 * pqr.Q + pqr.R);

    return(pi);
    }

PQR init_pqr(long int p, long int q, long int r){
    PQR pqr = {p, q, r};
    return(pqr);
    }


int main(int argc, char* argv[argc + 1]){
    long int n;
    if(argc < 2){
        n = 2;
        } else {
        n = strtol(argv[1], 0, 10);
        }

    printf("%.100Lf\n", chudnovsky(n));
    }


