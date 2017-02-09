/////////////////////////////////////////////////////////
///           [Alpro2] 1st MEET - MATRIX             ////
///          penjumlahan, perkalian (MOD)            ////
///                                                  ////
///            code by: naufalfazanadi               ////
/////////////////////////////////////////////////////////
#include <stdio.h>

void jumlah (int m, int n, int o, int p, int m1[m][n], int m2[o][p]) {
    int i, j;
    int m3[m][n];

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            m3[i][j] = m1[i][j] + m2[i][j];
            printf("%d ", m3[i][j]);
        }
        printf("\n");
    }
}

void kali (int m, int n, int o, int p, int m1[m][n], int m2[o][p]) {
    int i, j, k;
    int m3[m][p];

    for (i = 0; i < m; i++) {
        for (j = 0; j < p; j++) {

            // untuk summary di 0 kan dulu
            m3[i][j] = 0;
            
            // pengalian indeksnya
            for (k = 0; k < n; k++) {
                m3[i][j] += m1[i][k] * m2[k][j];
            }
            
            printf("%d ", m3[i][j]);
        }

        printf("\n");
    }

}

int main () {
    int m, n, o, p;
    int i, j;

    printf("Mau berapa kali berapa matriks ke 1 ? (without x)\n");
    scanf("%d %d", &m, &n);

    int m1[m][n];


    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &m1[i][j]);
        }
    }
    
    printf("Mau berapa kali berapa matriks ke 2 ? (without x)\n");
    scanf("%d %d", &o, &p);

    int m2[o][p];

    for (i = 0; i < o; i++) {
        for (j = 0; j < p; j++) {
            scanf("%d", &m2[i][j]);
        }
    }

    printf("\nPenjumlahan...\n");
    if (m == o && n == p) {
        jumlah (m, n, o, p, m1, m2);
    } else {
        printf("Matriks tidak bisa ditambahkan !\n");
    }

    printf("\nPerkalian...\n");
    if (n == o) {
        kali (m, n, o, p, m1, m2);
    } else {
        printf("Matriks tidak bisa dikalikan !\n");
    }

    return 0;
}
