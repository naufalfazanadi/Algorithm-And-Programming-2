/////////////////////////////////////////////////////////
///           [Alpro2] 1st MEET - MATRIX             ////
///             penjumlahan, perkalian               ////
///                                                  ////
///            code by: naufalfazanadi               ////
/////////////////////////////////////////////////////////
#include <stdio.h>

void jumlah (int m1[2][2], int m2[2][2]) {
    int i, j;
    int m3[2][2];

    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            m3[i][j] = m1[i][j] + m2[i][j];
            printf("%d ", m3[i][j]);
        }
        printf("\n");
    }
}

void kali (int m1[2][2], int m2[2][2]) {
    int i, j, k;
    int m3[2][2];

    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {

            // untuk summary di 0 kan dulu
            m3[i][j] = 0;
            
            // pengalian indeksnya
            for (k = 0; k < 2; k++) {
                m3[i][j] += m1[i][k] * m2[k][j];
            }
            
            printf("%d ", m3[i][j]);
        }

        printf("\n");
    }

}

int main () {
    int m1[2][2];
    int m2[2][2];

    int i, j;

    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            scanf("%d", &m1[i][j]);
        }
    }
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            scanf("%d", &m2[i][j]);
        }
    }

    jumlah (m1, m2);
    kali (m1, m2);

    return 0;
}
