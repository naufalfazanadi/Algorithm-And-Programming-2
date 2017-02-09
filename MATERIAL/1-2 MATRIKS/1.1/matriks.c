/////////////////////////////////////////////////////////
///           [Alpro2] 1st MEET - MATRIX             ////
///                   perkenalan                     ////
///                                                  ////
///            code by: naufalfazanadi               ////
/////////////////////////////////////////////////////////
#include <stdio.h>

int main () {
    int matriks1[4][4];
    int matriks2[4][4];
    int i, j;

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            scanf("%d", &matriks1[i][j]);
        }
    }

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            matriks2[i][j] = matriks1[i][j];
            if (j == 3) {
                printf("%d", matriks2[i][j]);
            } else {   
                printf("%d ", matriks2[i][j]);
            }
        }
        printf("\n");
    }

    return 0;
}
