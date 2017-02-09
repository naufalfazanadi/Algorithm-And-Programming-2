/////////////////////////////////////////////////////////
///       [Alpro2] 2nd MEET - MATRIX TYPEDEF         ////
///              Typedef struct x, y                 ////
///                                                  ////
///            code by: naufalfazanadi               ////
/////////////////////////////////////////////////////////
#include <stdio.h>

typedef struct {
    int x;
    int y;
} coordinate;

int main () {
    coordinate matriks[2][2];

    int i, j;

    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            printf("Masukan koordinat x ke [%d][%d] : ", i, j);
            scanf("%d", &matriks[i][j].x);
            printf("Masukan koordinat y ke [%d][%d] : ", i, j);
            scanf("%d", &matriks[i][j].y);
        }
    }

    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            printf("%d, %d\t", matriks[i][j].x, matriks[i][j].y);
        }
        printf("\n");
    }

    return 0;
}
