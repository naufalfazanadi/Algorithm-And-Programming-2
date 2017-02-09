#include "head.h"

int main () {
    int i, j, k; // for loop
    int x, y; // besar matriks

    // input besar matriks
    scanf("%d %d", &x, &y);

    // inisialisasi 4 matriks dengan besar x y
    int matrix[4][x][y];

    for (i = 0; i < 4; i++) { // untuk matriks
        for (j = 0; j < x; j++) { // untuk baris
            for (k = 0; k < y; k++) { // untuk kolom
                scanf("%d", &matrix[i][j][k]); // input
            }
        }
    }

    // inisialisasi var urutan angka yg di matriks 3
    int urutan[x][y];

    for (i = 0; i < x; i++) {
        for (j = 0; j < y; j++) {
            // menggunakan fungsi, kenapa itu dimasukan angka 2?
            // karena kita akan mulai nya langsung ke urutan ketiga saat di fungsi nya
            // e.g. 1, 2, 3 nah di fungsi nya akan langsung menghitung ke angka 3
            // jika urutan 1 atau 2 itu pake basis            
            urutan[i][j] = count_fibo(matrix[0][i][j], matrix[1][i][j], matrix[2][i][j], 2);
            
            // lalu langsung di print dengan format matriks
            // dibandingkannya di procesure ini
            printing(matrix[3][i][j], urutan[i][j], j);
        }
        printf("\n");
    }

    return 0;
}
