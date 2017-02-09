#include "head.h"

int main () {
	int i;
	int m, n, o;

	// ---------------- NEGARA KE 1 ---------------
	scanf("%d", &m);
	
	pack nation1[m];

	for (i = 0; i < m; i++) {
		scanf("%s", &nation1[i].biner);
		nation1[i].decimal = convert_to_dec(nation1[i].biner); // konversi
	}

	quick_sort(0, m-1, nation1); // SORTING

	// ---------------- NEGARA KE 2 ---------------
	scanf("%d", &n);

	pack nation2[n];

	for (i = 0; i < n; i++) {
		scanf("%s", &nation2[i].biner);
		nation2[i].decimal = convert_to_dec(nation2[i].biner); // konversi
	}

	quick_sort(0, n-1, nation2); // SORTING

	// ---------------- NEGARA KE 3 ---------------
	scanf("%d", &o);

	pack nation3[o];

	for (i = 0; i < o; i++) {
		scanf("%s", &nation3[i].biner);
		nation3[i].decimal = convert_to_dec(nation3[i].biner); // konversi
	}

	quick_sort(0, o-1, nation3); // SORTING

	// ------------- Suspicious data ----------------

	diff suspicious = cek_data_3negara(m, n, o, nation1, nation2, nation3); // cek yang ada di semua tabel

	// --------------- MERGE TABLE ----------------
	pack result1[m+n];
	pack result2[m+n+o];

	merge_terurut(m, n, nation1, nation2, result1); // nation 1 & 2
	merge_terurut(m+n, o, result1, nation3, result2); // (nation 1 & 2 ) & nation 3

	// ----------------- OUTPUT -------------------
	printf("Laporan Data Biner\n");
	printf("====================\n");
	// OUTPUT YANG BINER
	for (i = 0; i < m+n+o; i++) {
		printf("%s\n", result2[i].biner);
	}
	// OUTPUT YANG SAMA NYA
	for (i = 0; i < suspicious.count; i++) {
		printf("%d\n", suspicious.beda[i]);
	}

	return 0;
}

/*
Pada suatu hari tobi,moni dan piyu memiliki tugas mata-mata yang sangat berat. Mereka diminta untuk mengambil data penting di server database musuh yang terdapat di korea selatan,rusia dan AS. 
Data yang harus diambil merupakan sebuah big data yang terdiri dari biner-biner 10 bit. 
Data tersebut harus di gabungkan dan urutkan menjadi satu kemudian carilah data data yang mempunyai nilai yang sama tetapi harus dari ketiga negara yang berbeda (SUSPICIOUS DATA).
Tampilkan dalam sebuah file report yang akan di laporkan ke bos mereka.

Laporan ditulis dengan format : 

Laporan Data Biner 
==================== 
[BIG DATA RESULT] 
[SUSPICIOUS DATA] 

Format Masukan :
n, 0 < n < 50
Big data biner tobi sebanyak n
m, 0 < m < 50 
Big data biner moni sebanyak m 
o, 0 < o < 50 
Big data biner piyu sebanyak o 
Format Keluaran :
Laporan Data Biner 
==================== 
[BIG DATA RESULT] 
[SUSPICIOUS DATA on decimal] 

Contoh Masukan

6
1111111100
0001111011
1111100000
0111111011
0110000000
0000001100
6
0000001100
0110001100
0110010011
0111100011
1111100011
1111111111
5
0000001100
0101100011
1101111011
0000000111
1011111111


Contoh Keluaran

Laporan Data Biner
====================
0000000111
0000001100
0000001100
0000001100
0001111011
0101100011
0110000000
0110001100
0110010011
0111100011
0111111011
1011111111
1101111011
1111100000
1111100011
1111111100
1111111111
12

Contoh Masukan 2

3
0001111011
1111100000
0111111011
5
0001111011
1111100000
0111111011
0111111011
1111100011
2
0001111011
1111100000


Contoh Keluaran 2

Laporan Data Biner
====================
0001111011
0001111011
0001111011
0111111011
0111111011
0111111011
1111100000
1111100000
1111100000
1111100011
123
992

 */