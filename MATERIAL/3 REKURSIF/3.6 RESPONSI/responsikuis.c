#include <stdio.h>

typedef struct {
    int x;
    int y;
    int z;
}bungkus;

int mid(int x, int y, int z) {

    if ((x > y && x < z) || (x > z && x < y)) {
        return x;
    } else if ((y > x && y < z) || (y > z && y < x)) {
        return y;
    } else if ((z > x && z < y) || (z > y && z < x)) {
        return z;
    }
}

int main () {
    int m, n;
    scanf("%d %d", &m, &n);

    bungkus matriks[m * n];

    int tengah[m*n];

    int i, j;
    for (i = 0; i < m * n; i++) {
        scanf("%d", &matriks[i].x);
        scanf("%d", &matriks[i].y);
        scanf("%d", &matriks[i].z);

        tengah[i] = mid(matriks[i].x, matriks[i].y, matriks[i].z);
    }

    int count = 0;
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", tengah[count]);
            count++;
        }
        printf("\n");
    }

    return 0;
}
