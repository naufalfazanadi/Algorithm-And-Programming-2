#include "head.h"

int main () {
    int x, y; // besarnya matriks

    scanf("%d %d", &x, &y); // input besarnya matriks

    int matrix[x][y]; // matriks inputan
    int hasill[x][y]; // matriks hasil

    int i, j; // untuk loop

    for (i = 0; i < x; i++) {
        for (j = 0; j < y; j++) {
            // inputan
            scanf("%d", &matrix[i][j]);

            // proses
            hasill[i][j] = recursive(matrix[i][j], -1);
        }
    }   

    // output
    for (i = 0; i < x; i++) {
        for (j = 0; j < y; j++) {
            if (j != y-1) {
                printf("(%d, %d) ", matrix[i][j], hasill[i][j]); // spasi
            } else {
                printf("(%d, %d)", matrix[i][j], hasill[i][j]); // untuk yg ujung
            }

        }
        printf("\n");
    }    

    return 0;
}
