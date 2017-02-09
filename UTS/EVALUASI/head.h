#include <stdio.h>
#include <string.h>

typedef struct {
    char biner[9];
    int decimal;  
} pack; // bungkusan untuk data

typedef struct {
    int few;
    int lot;
} penghitung; // bungkusan penghitung array 1 dan 2

typedef struct {
    int bol;
    int index;
} cari; // bungkusan untuk searching nya

// --FUNGSI-- untuk konversi
int convert_to_dec (char biner[]);

// --PROSEDUR-- untuk sorting dan merge
void insertion_sort (int n, pack arr[]);
void merge_terurut (int m, int n, pack arr1[], pack arr2[], pack result[]);

// --FUNGSI-- untuk searching nya
cari search(int n, int x_search, pack hasil[]);

/* Saya Muhammad Naufal Fazanadi tidak melakukan kecurangan seperti yang telah dispesifikasikan
pada mata kuliah Algoritma dan Pemograman 2 dalam mengerjakan Evaluasi,
jika saya melakukan kecurangan maka Allah/Tuhan adalah saksi saya, 
dan saya bersedia menerima hukumanNya. Aamiin. */
