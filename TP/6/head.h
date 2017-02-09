#include <stdio.h>
#include <string.h>

// defining boolean
#define TRUE 1
#define FALSE 0

typedef struct { // untuk inputan
	int hari;
	int masuk;
	int keluar;
} jadwal;

typedef struct { // matriks jadwal
	int hari[5][11];
} day;

typedef struct { // untuk hasil output nya
	int bol;
	int hari[8];
	int masuk[8];
	int keluar[8];
	int count;
} di_searching;

// fungsi untuk update matriks
day cek_jam (day x, int hari, int masuk, int keluar);
// fungsi untuk search irisan pada matriks
di_searching search_irisan(day jam);

/* Saya Muhammad Naufal Fazanadi tidak melakukan kecurangan seperti yang telah dispesifikasikan pada mata kuliah Algoritma dan Pemograman 2 dalam mengerjakan Tugas Praktikum 6, jika saya melakukan kecurangan maka Allah/Tuhan adalah saksi saya, dan saya bersedia menerima hukumanNya. Aamiin. */

/*
5
1 7 18
2 7 10
2 16 18
3 7 12
4 9 12

3
2 7 18
3 10 16
4 7 16

4
1 8 12
1 16 17
3 8 12
4 7 10

Contoh Keluaran

Rabu 16.00 - 18.00
Kamis 16.00 - 18.00
Jumat 7.00 - 18.00

5
1 7 18
2 7 16
3 9 16
4 7 12
4 16 18

4
2 10 18
3 13 18
4 7 10
5 13 18

3
4 16 18
5 7 10
5 13 16
 */