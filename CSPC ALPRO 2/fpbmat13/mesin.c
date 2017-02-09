#include "head.h"

int fpb (int x, int y) {
    int temp;
    if (y == 0) {
        return x;
    } else {
        temp = x % y;
        return fpb (y, temp);
    }
}

void process (int kolom[], int baris[], int n, int m) {
    int i, j;
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("%d\n", fpb(baris[i], kolom[j]));
        }
    }
}
