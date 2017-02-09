#include "head.h"

int main () {
  int i, n;
  scanf("%d", &n); // how many

  pack data[n]; // var untuk data

  char dataCari[8]; // var untuk search

  // input data
  for (i = 0; i < n; i++) {
    scanf("%s %s %d", &data[i].kode, &data[i].nama, &data[i].harga);
  }
  // input search
  scanf("%s", &dataCari);

  // var yang dicari nya antisipasi untuk integer dan string
  char nilaiCari[16];
  int nilaiCariInt;

  // input nilai yg dicari dan mengkonversi untuk lebih mudah
  int method;
  if (strcmp(dataCari, "kode") == 0) {
    method = 1;
    scanf("%s", &nilaiCari);
  } else if (strcmp(dataCari, "nama") == 0) {
    method = 2;
    scanf("%s", &nilaiCari);
  } else if (strcmp(dataCari, "harga") == 0) {
    method = 3;
    scanf("%d", &nilaiCariInt);
  }

  // sort dulu baru search
  selection_sort(n, data, method);
  // jika harga maka masukan integer
  if (method == 3) {
    binary_search(n, data, method, " ", nilaiCariInt);
  } else {
    binary_search(n, data, method, nilaiCari, 0);
  }

  return 0;
}

/*
TEST CASE
3
001 sate 4000
002 gulai 55000
003 soto 34000
kode 002

3
001 sate 4000
002 gulai 55000
003 soto 34000
nama soto

3
001 sate 4000
002 gulai 55000
003 soto 34000
nama sotoy
 */