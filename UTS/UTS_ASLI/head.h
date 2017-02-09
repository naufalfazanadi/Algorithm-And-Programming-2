#include <stdio.h>
#include <string.h>

// ----- TIPE DATA BUNGKUSAN -----
typedef struct {
    char nama[64];
    char no_telp[12];
    int jam_terbang;
    double komisi;
} pack;

// PROSEDUR SORTING
void insertion_sort (int n, pack arr[]);
void selection_sort (int n, pack arr[]);
void bubble_sort (int n,  pack arr[]);
void quick_sort (int l, int r, pack arr[]);

// PROSEDUR UNTUK MERGING
void merge_terurut (int m, int n, pack arr1[], pack arr2[], pack result[]);

/* Saya Muhammad Naufal Fazanadi tidak melakukan kecurangan seperti yang telah dispesifikasikan
pada mata kuliah Algoritma dan Pemograman 2 dalam mengerjakan UTS,
jika saya melakukan kecurangan maka Allah/Tuhan adalah saksi saya, 
dan saya bersedia menerima hukumanNya. Aamiin. */
