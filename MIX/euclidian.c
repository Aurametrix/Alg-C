#include <stdio.h>  /* printf */
#include <stdlib.h> /* atoi */

/* Euclidian algorithm
 * computing the greatest common divisor of two natural numbers
 * ----------------------------------------------------------------------------
 */

int euclidean_gcd(int a, int b) {
    if (b > a) goto b_larger;
    while (1) {
        a = a % b;
        if (a == 0) return b;
b_larger:
        b = b % a;
        if (b == 0) return a;
    }
}



int main(int argc, char* argv[]) {
    printf("%d\n", euclidean_gcd(atoi(argv[1]), atoi(argv[2])));
    return 0;
}

