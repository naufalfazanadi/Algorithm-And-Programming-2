#include "head.h"

int main () {
    // Metoda sorting
    char method[16];

    scanf("%s", &method);

    // ------------- INPUT ------------
    int m, n, o; // jumlah untuk 2014, 2015, 2016 : m, n, o
    
    int i; // untuk loop
    // ------------ 1 -------------

    scanf("%d", &m); // banyak data

    pack d2014[m]; // tipe nya array of bungkusan

    for (i = 0; i < m; i++) {
        scanf("%s %s %d %lf", &d2014[i].nama, &d2014[i].no_telp, &d2014[i].jam_terbang, &d2014[i].komisi);
    }

    // ------------ 2 -------------
    scanf("%d", &n); // banyak data

    pack d2015[n]; // tipe nya array of bungkusan

    for (i = 0; i < n; i++) {
        scanf("%s %s %d %lf", &d2015[i].nama, &d2015[i].no_telp, &d2015[i].jam_terbang, &d2015[i].komisi);
    }

    // ------------ 3 -------------
    scanf("%d", &o); // banyak data

    pack d2016[o]; // tipe nya array of bungkusan

    for (i = 0; i < o; i++) {
        scanf("%s %s %d %lf", &d2016[i].nama, &d2016[i].no_telp, &d2016[i].jam_terbang, &d2016[i].komisi);
    }

    // ----- END OF INPUT -----

    // -------- SORTING -------
    if (strcmp(method, "insert") == 0) { // insertion sort
        insertion_sort(m, d2014);
        insertion_sort(n, d2015);
        insertion_sort(o, d2016);
    } else if (strcmp(method, "select") == 0) { // selection sort
        selection_sort(m, d2014);
        selection_sort(n, d2015);
        selection_sort(o, d2016);
    } else if (strcmp(method, "bubble") == 0) { // bubble sort
        bubble_sort(m, d2014);
        bubble_sort(n, d2015);
        bubble_sort(o, d2016);
    } else if (strcmp(method, "quick") == 0) { // quick sort
        quick_sort(0, m-1, d2014);
        quick_sort(0, n-1, d2015);
        quick_sort(0, o-1, d2016);
    }

    // ---------- MERGING ----------
    pack result1[m+n]; // hasil dari 2014 dan 2015
    pack result2[m+n+o]; // hasil dari (2014 + 2015) + 2016

    merge_terurut(m, n, d2014, d2015, result1); // merge 2014 & 2015
    merge_terurut(m+n, o, result1, d2016, result2); // merge (2014 2015) & 2016

    // ---------- OUTPUT -----------
    for (i = 0; i < m+n+o; i++) {
        printf("%s %s %d %.0lf\n", result2[i].nama, result2[i].no_telp, result2[i].jam_terbang, result2[i].komisi);
    }

    return 0;
}

/*
Kemampuan yang dievaluasi: Penggabungan tabel dengan terurut sesuai konsep yang diberikan pada materi kuliah. Diberikan 3 buah array dari tipe terstruktur. Tipe terstruktur terdiri dari nama_driver (string), nomor_telepon (string), jam_terbang (int), komisi (double). Array pertama berisi tipe terstruktur driver pada tahun 2014, array kedua pada tahun 2015, array ketiga pada tahun 2016. Gabungkan ketiga array dengan terurut dari besar ke kecil berdasarkan nilai komisi. Gunakan konsep yang baik dan benar untuk nilai sempurna.

Format Masukan:

metode pengurutan array pertama (insert, select, bubble, quick)
n, 0 < n <= 100, banyaknya elemen array pertama
n baris elemen array pertama yang terdiri dari nama nomor jam komisi
m, 0 < m <= 100, banyaknya elemen array pertama
m baris elemen array pertama yang terdiri dari nama nomor jam komisi
p, 0 < p <= 100, banyaknya elemen array pertama
p baris elemen array pertama yang terdiri dari nama nomor jam komisi

Format Keluaran:

hasil pengurutan n + m + p baris yang terdiri dari nama nomor jam komisi (komisi ditampilkan tanpa angka di belakang koma, silakan googling)

Contoh Masukan

insert
3
driver_1 08123451 34 1000000
driver_2 08123452 31 900000
driver_3 08123453 30 800000
2
driver_4 08123454 50 2000000
driver_5 08123455 29 700000
1
driver_6 08123456 1 15000


Contoh Keluaran

driver_4 08123454 50 2000000
driver_1 08123451 34 1000000
driver_2 08123452 31 900000
driver_3 08123453 30 800000
driver_5 08123455 29 700000
driver_6 08123456 1 15000


 */

/*
quick
3
naufal 08123451 7823 9000000
achmad 08123452 342 300000
iki 08123453 123 890000
2
fadhil 08123454 1 2300000
arin 08123455 98 700000
1
tasya 08123456 423 10000000

insert
3
driver_1 08123451 34 1000000
driver_2 08123452 31 900000
driver_3 08123453 30 800000
2
driver_4 08123454 50 2000000
driver_5 08123455 29 700000
1
driver_6 08123456 1 15000
 */
