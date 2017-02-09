#include <stdio.h>
#include <string.h>

#define FALSE 0
#define TRUE 1

typedef struct {
	char biner[11];
	int decimal;
} pack; // untuk data nya

typedef struct {
	int beda[32];
	int count;
} diff; // untuk fungsi

// KONVERSI BINER
int convert_to_dec (char biner[]);

// QUICK SORT
void quick_sort (int l, int r, pack arr[]); // dont forget about change data type to pack

// FUNGSI untuk ngecek 3 tabel untuk angka yang sama
diff cek_data_3negara (int m, int n, int o, pack nation1[], pack nation2[], pack nation3[]);

// PROSEDUR MERGING
void merge_terurut (int m, int n, pack arr1[], pack arr2[], pack result[]); // dont forget about change data type to pack

/* Saya Muhammad Naufal Fazanadi tidak melakukan kecurangan seperti yang telah dispesifikasikan
pada mata kuliah Algoritma dan Pemograman 2 dalam mengerjakan Tugas Praktikum 5,
jika saya melakukan kecurangan maka Allah/Tuhan adalah saksi saya, 
dan saya bersedia menerima hukumanNya. Aamiin. */