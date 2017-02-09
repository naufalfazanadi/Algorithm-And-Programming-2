#include <stdio.h>
#include <string.h>

// boolean
#define FALSE 0
#define TRUE 1

// bungkusan
typedef struct {
  char kode[10];
  char nama[16];
  int harga;
} pack;

// sort
void selection_sort (int n, pack arr[], int method); // dont forget about change data type to pack
// search
void binary_search (int n, pack arr[], int mehod, char x_search[], int x_searchInt);

/* Saya Muhammad Naufal Fazanadi tidak melakukan kecurangan seperti yang telah
dispesifikasikan pada mata kuliah Algoritma dan Pemograman 2 dalam mengerjakan
KUIS 2, jika saya melakukan kecurangan maka Allah/Tuhan adalah saksi
saya, dan saya bersedia menerima hukumanNya. Aamiin. */
