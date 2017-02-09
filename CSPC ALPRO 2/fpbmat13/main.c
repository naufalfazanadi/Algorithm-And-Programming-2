#include "head.h"

int main () {

    char huruf;
    int n, m;
    int i, j;
    int kolom[32], baris[32];

    scanf(" %c", &huruf);

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &kolom[i]);
    }

    scanf(" %c", &huruf);

    scanf("%d", &m);

    for (i = 0; i < m; i++) {
        scanf("%d", &baris[i]);
    }

    process (kolom, baris, n, m);

    return 0;
}
