#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
  char nim[15];
  char nama[50];
  char kelas[5];
} pack; // bungkusan

pack record[128]; // var global untuk record

int n; // jumlah record nya

// PRO FUNC
void read_file(); // ngeread dari file
void write_file(); // ngewrite ke file

int check_long_nama (); // cek nama paling panjang
int check_long_nim (); // cek nim paling panjang

int search_data(char[15]); // cari nim
void insert_data(pack); // insert data
void delete_data(char[15]); // delete data
void update_data(char[15]); // update data
