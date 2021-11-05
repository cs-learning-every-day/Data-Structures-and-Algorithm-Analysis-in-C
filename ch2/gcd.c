#include <stdio.h>

// assure m > n
static unsigned int 
Gcd(unsigned int m, unsigned int n) {
    unsigned int rem;
    while (n > 0) {
        rem = m % n;
        m = n;
        n = rem;
    }
    return m;
}

int main() {
    int M = 50, N = 15;
    printf("GCD(%d,%d) = %u\n", M, N, Gcd(M, N));
    return 0;
}