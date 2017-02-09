#include "head.h"

// SELECTION
void selection_sort (int n, pack arr[], int method) { // dont forget about change data type to pack
    int i, j;
    int min;
    pack temp;

    for (i = 0; i < n-1; i++) {
        min = i; // indeks yg dalamnya angka minimal
        for (j = i+1; j < n; j++) {
            switch (method) {
              case 1 :
                if(strcmp(arr[min].kode, arr[j].kode) > 0) {
                    min = j; // ganti kalau ada indeks yg lebih besar
                }
                break;
              case 2 :
                if(strcmp(arr[min].nama, arr[j].nama) > 0) {
                    min = j; // ganti kalau ada indeks yg lebih besar
                }
                break;
              case 3 :
                if(arr[min].harga > arr[j].harga) {
                    min = j; // ganti kalau ada indeks yg lebih besar
                }
                break;
            }
        }
        //menukar posisi elemen
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

// SEARCH
void binary_search (int n, pack arr[], int method, char x_search[], int x_searchInt) {
  int i, j, k; // untuk loop

  int bol = FALSE; // boolean set to false first
  pack temp; // hasil nya

  i = 0;
  j = n-1;

  while((bol == 0) && (i<=j)){ // loop search
    k = (i + j) / 2; // pembagi
    switch(method) { // pengecekan kode / nama / harga
      case 1 : // kode
        if(strcmp(arr[k].kode, x_search) == 0){ // jika ketemu
          bol = TRUE;
          temp = arr[k];
        }else{ // jika tidak
          if(strcmp(arr[k].kode, x_search) > 0){
            j = k - 1;
          }else{
            i = k + 1;
          }
        }
        break;
      case 2 : // nama
        if(strcmp(arr[k].nama, x_search) == 0){ // jika ketemu
          bol = TRUE;
          temp = arr[k];
        }else{ // jika tidak
          if(strcmp(arr[k].nama, x_search) > 0){
            j = k - 1;
          }else{
            i = k + 1;
          }
        }
        break;
      case 3 : // harga
        if(arr[k].harga == x_searchInt){ // jika ketemu
          bol = TRUE;
          temp = arr[k];
        }else{ // jika tidak
          if(arr[k].harga > x_searchInt){
            j = k - 1;
          }else{
            i = k + 1;
          }
        }
        break;
    }
  }

  // jika ada tampilkan jika tidak ouput tidak ada
  if (bol == TRUE) {
    printf("%s %s %d\n", temp.kode, temp.nama, temp.harga);
  } else {
    printf("tidak ada\n");
  }
}

