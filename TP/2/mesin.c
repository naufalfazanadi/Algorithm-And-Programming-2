#include "head.h"

// UNTUK MENGHITUNG URUTAN KEBERAPA
int count_fibo(int x, int y, int n, int urut) {
    int sum; // untuk dapat urutan selanjutnya
    sum = x + y; // e.g. 3, 5, 3+5 = 8, berarti 8 adalah urutan selanjutnya
    urut++; // var penghitungan urutan

    if (n == x) { // jika sama seperti urutan pertama
        return 1;
    } else if (n == y) { // jika sama seperti urutan kedua
        return 2;
    } else if (sum == n) { // jika sum nya sudah sama seperti matriks 3
        return urut; // maka var penghitungnya dilempar kan
    } else { // jika belum sama rekursifkan
        count_fibo(y, sum, n, urut); // dengan mengubah si masukan parameternya
    }

}

// UNTUK OUTPUT MATRIKS
void printing(int cari, int urutan, int n) {
    if (n != 0) { // spasi
        printf(" ");
    }

    // jika urutan angka di matriks 3 lebih besar dari matriks paramter
    if (urutan >= cari) {
        printf("O"); // print O
    } else {
        printf("X"); // jika tidak print X
    }

}

// 1, 2, 3, 5, 8, 13, 21, 34, 55, 89
// x, y, sum,
      X  Y  SUM
        X   Y  SUM
