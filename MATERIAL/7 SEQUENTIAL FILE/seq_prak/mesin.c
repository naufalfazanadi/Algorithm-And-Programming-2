#include "head.h"

// proses membaca file
void read_file() {
  n = 0;          // deklarasi n sama dengan nol
  pack tmp;  // bungkusan penamppung
  FILE *fdata;    // deklarasi nama file
  // membaca file
  fdata = fopen("data/record_mahasiswa.dat", "r");

  // proses membaca file dan ditampung di bungkusan
  do {
    fscanf(fdata, "%s %s %s", tmp.nim, tmp.nama, tmp.kelas);
    if (strcmp(tmp.nim, "##") != 0 && strcmp(tmp.nama, "##") != 0 &&
        strcmp(tmp.kelas, "##") != 0) {
      record[n] = tmp;
      n++;
    }
  } while (strcmp(tmp.nim, "##") != 0 && strcmp(tmp.nama, "##") != 0 &&
           strcmp(tmp.kelas, "##") != 0);
  // menutup file
  fclose(fdata);
}

// proses menulis file
void write_file() {
  int i;  // variabel iterasi

  FILE *fdata;  // deklarasi fdata
  // menulis di file
  fdata = fopen("data/record_mahasiswa.dat", "w");
  // proses penulisan file
  for (i = 0; i < n; i += 1) {
    fprintf(fdata, "%s %s %s\n", record[i].nim, record[i].nama, record[i].kelas);
  }
  // proses penambahan record dummy
  fprintf(fdata, "## ## ##\n");
  // menutupi file
  fclose(fdata);
}

// cek nama yang paling panjang
int check_long_nama () {
  int i;

  int max = 0;

  for (i = 0; i < n; i++) {
    if (strlen(record[i].nama) > max) {
      max = strlen(record[i].nama);
    }
  }

  return max;
}

// cek nim yang paling panjang
int check_long_nim () {
  int i;

  int max = 0;

  for (i = 0; i < n; i++) {
    if (strlen(record[i].nim) > max) {
      max = strlen(record[i].nim);
    }
  }

  return max;
}

// proses mencari data
int search_data(char nim[15]) {
  int status = 0;  // deklarasi status sama dengan nol
  int i = 0;       // variabel iterasi

  // memanggil prosedur baca
  read_file();

  // proses mencari
  while (status == 0 && i < n) {
    if (strcmp(record[i].nim, nim) == 0) {
      // jika nilai yang dicari ada
      status = 1;  // status menjadi 1
    } else {
      i += 1;
    }
  }
  // melempar nilai status
  return status;
}

// proses menambah data
void insert_data(pack masukan) {
  int status = search_data(masukan.nim);  // menerima lemparan dari proses mencari
  // jika nim tidak ganda
  if (status == 0) {
    // data baru dimasukan
    record[n] = masukan;
    n += 1;
    // data ditulis kedalam file
    write_file();
    printf("Data berhasil ditambahkan\n");
  } else {
    // jika nim ganda, tidak bisa memasukan data baru
    printf("NIM sudah terdaftar, data gagal ditambahkan\n");
  }
}

// proses menghapus data
void delete_data(char nim[15]) {
  // pemanggilan prosedur baca
  read_file();
  int i, j;        // variabel iterasi
  int status = 0;  // variabel status
  i = 0;
  char hapus[10];  // variabel hapus

  // proses menghapus data
  while (i < n && status == 0) {
    // jika nim yang akan dihapus ada
    if (strcmp(record[i].nim, nim) == 0) {
      status = 1;  // status menjadi satu
      // mencegah jika salah menghapus data
      printf("Data ditemukan. Yakin hapus data? ");
      printf("ya/tidak\n");
      // input hapus(ya) atau tidak
      scanf("%s", hapus);
      // jika pilihan ya, maka data dihapus
      if (strcmp(hapus, "ya") == 0) {
        for (j = i; j < n; j += 1) {
          record[j] = record[j + 1];
        }
        n -= 1;
        // data ditulis ke dalam file
        write_file();
      }
    } else {
      // jika tidak, data tidak akan dihapus
      i += 1;
    }
  }

  // jika nim tidak ada dalam data
  if (status == 0) {
    printf("Data tidak ditemukan\n");
  }
}

// proses update data
void update_data(char nim[15]) {
  // pemanggilan prosedur baca
  read_file();
  int i, j;        // variabel iterasi
  int status = 0;  // variabel status

  i = 0;
  char nama[25], kelas[15];  // variabel menampung nama dan kelas
  // proses update
  while (i < n && status == 0) {
    // jika nim yang akan diupdate ada di dalam data
    if (strcmp(record[i].nim, nim) == 0) {
      status = 1;
      printf("Data ditemukan\n");
      // tampilan awal sebelum diupdate
      printf("--Data Awal--\n");
      printf("Nama : %s\n", record[i].nama);
      printf("Kelas : %s\n", record[i].kelas);
      printf("-----------\n");
      // input data baru agar data terupdate
      printf("Masukan nama baru : \n");
      scanf("%s", nama);
      printf("Masukan kelas baru : \n");
      scanf("%s", kelas);
      // proses menempatkan ke dalam bungkusan
      strcpy(record[i].nama, nama);
      strcpy(record[i].kelas, kelas);
      printf("Data berhasil diupdate\n");
      // data ditulis kembali ke dalam file
      write_file();
    } else {
      i += 1;
    }
  }
  // jika nim tidak ada di dalam data
  if (status == 0) {
    printf("Data tidak ditemukan\n");
  }
}