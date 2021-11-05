#include <stdio.h>

long int
Pow(long int X, long int N) {
    if (N == 0) {
        return 1;
    } else if (N == 1) {
        return X;
    }

    if (N % 2 == 0) {
        return Pow(X * X, N / 2);
    } else {
        return Pow(X * X, (N - 1) / 2) * X;
    }
}

int main() {
    long int X = 3, N = 69; 
    printf("pow(%ld, %ld) %ld\n", X, N, Pow(X, N));

    X = 2, N = 3;
    printf("pow(%ld, %ld) %ld\n", X, N, Pow(X, N));

    return 0;
}