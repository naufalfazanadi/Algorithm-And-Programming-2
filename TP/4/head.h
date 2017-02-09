#include <stdio.h>
#include <string.h>

// TIPE DATA UNTUK MAHASISWA
typedef struct {
    char nim[16];
    char nama[64];
} data;

// TIPE DATA UNTUK COUNTER
typedef struct {
    in t valid;
    int tidak_valid;
} penghitung;

int cek_nim (char nim[16]); // fungsi untuk mengecek kevalidan nim
void sort_nim (int n,  data roster[n]); // prosedur bubble sort berdasarkan nim
void sort_nama (int l, int r, data roster[]); // prosedur quick sort berdasarkan nama

void output (int nim_or_name_stats, char ya_or_no[], penghitung count, data roster[], data error[]); // prosedur output


/* Saya Muhammad Naufal Fazanadi tidak melakukan kecurangan seperti yang telah dispesifikasikan
pada mata kuliah Algoritma dan Pemograman 2 dalam mengerjakan Tugas Praktikum 4,
jika saya melakukan kecurangan maka Allah/Tuhan adalah saksi saya, 
dan saya bersedia menerima hukumanNya. Aamiin. */
