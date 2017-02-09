#include <stdio.h>
#include <string.h>

typedef struct {
  char nim[10];
  char nama[32];
  double mutu;
  int sks;
  float ip;
} pack; // bungkusan untuk array

int n; // global var jumlah data

void file_scan(pack record[], char path[50]); // scanning dari file
void ip(pack record[]); // cari ip
void quick_sort (int l, int r, pack arr[]); // dont forget about change data type to pack
void write(pack record[]); // write ke result

/* Saya Muhammad Naufal Fazanadi tidak melakukan kecurangan seperti yang telah
dispesifikasikan pada mata kuliah Algoritma dan Pemograman 2 dalam mengerjakan
Tugas Praktikum 7, jika saya melakukan kecurangan maka Allah/Tuhan adalah saksi
saya, dan saya bersedia menerima hukumanNya. Aamiin. */
