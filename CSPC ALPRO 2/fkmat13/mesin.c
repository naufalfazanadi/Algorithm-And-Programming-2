#include "head.h"

long long int faktorial (int n) {
    if (n == 1) {
        return 1;
    } else {
        return (n * faktorial(n - 1));
    }
}

void process (int kolom[], int baris[], int n, int m) {
    int i, j;
    long long int count;
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            count = faktorial(baris[i]) * faktorial(kolom[j]);
            printf("%lld\n", count);
        }
    }
}
