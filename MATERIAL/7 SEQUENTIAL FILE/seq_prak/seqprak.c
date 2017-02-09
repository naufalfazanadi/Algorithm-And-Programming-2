#include "head.h"

int main () {
  int i, j;
  int menu; // var pilihan menu
  char ya_no[8]; // var cek ya atau tidak

  pack alpro; // untuk inputan

  do {
    // clearscreen
    system("cls");

    read_file(); // read file dari external
    int max_nama = check_long_nama(); // cek nama terpanjang
    int max_nim = check_long_nim(); // cek nim terpanjang

    // --------------- BORDERING ----------------
    for (i = 0; i < max_nim + max_nama + 12; i++) {
      printf("-");
    }
    printf("\n");

    printf("|NIM");
    for (i = 0; i < max_nim - 2; i++) {
      printf(" ");
    }

    printf("|NAMA");
    for (i = 0; i < max_nama - 3; i++) {
      printf(" ");
    }

    printf("|KELAS |\n");

    for (i = 0; i < max_nim + max_nama + 12; i++) {
      printf("-");
    }
    printf("\n");

    // ----------------- OUTPUT DARI FILE ---------------------

    for (i = 0; i < n; i++) {
      printf("|%s", record[i].nim); // nim

      for (j = 0; j < max_nim - strlen(record[i].nim) + 1; j++) {
        printf(" ");
      }

      printf("|%s", record[i].nama); // nama

      for (j = 0; j < max_nama - strlen(record[i].nama) + 1; j++) {
        printf(" ");
      }

      printf("|%s", record[i].kelas); // kelas

      for (j = 0; j < 6 - strlen(record[i].kelas); j++) {
        printf(" ");
      }

      printf("|\n");
    }


    for (i = 0; i < max_nim + max_nama + 12; i++) {
      printf("-");
    }
    printf("\n");

    // PILIHAN MENU
    printf("\nMasukan pilihan anda!\n");
    printf("\n");
    printf("------------ PILIHAN ------------\n");
    printf("|\t1. Cari Data\t\t|\n");
    printf("|\t2. Tambah Data\t\t|\n");
    printf("|\t3. Update Data\t\t|\n");
    printf("|\t4. Delete Data\t\t|\n");
    printf("|\t5. Exit\t\t\t|\n");
    printf("---------------------------------\n");
    scanf("%d", &menu); // input menu

    if (menu == 1) { // find data
      printf("Masukan NIM : ");
      scanf("%s", &alpro.nim);

      if (search_data(alpro.nim) == 1) {
        printf("Data ditemukan\n");
      } else {
        printf("Data tidak ditemukan\n");
      }
    } else if (menu == 2) { // insert data
      printf("Masukan NIM : ");
      scanf("%s", &alpro.nim);
      printf("Masukan Nama : ");
      scanf("%s", &alpro.nama);
      printf("Masukan Kelas : ");
      scanf("%s", &alpro.kelas);

      insert_data(alpro);
    } else if (menu == 3) { // update data
      printf("Masukan NIM : ");
      scanf("%s", &alpro.nim);

      update_data(alpro.nim);
    } else if (menu == 4) { // delete data
      printf("Masukan NIM : ");
      scanf("%s", &alpro.nim);

      delete_data(alpro.nim);
    }

    if (menu != 5) { // untuk kondisi nomor 5
      printf("Keluar ? (ya / tidak) ");
      scanf("%s", &ya_no);
    }

  } while(strcmp(ya_no, "ya") != 0 && menu != 5); // condition

  system("cls"); // clearscreen
  printf("Exiting the program..\n");

  return 0;
}

/* Saya Muhammad Naufal Fazanadi tidak melakukan kecurangan seperti yang telah
dispesifikasikan pada mata kuliah Algoritma dan Pemograman 2 dalam mengerjakan
Tugas Praktikum 8, jika saya melakukan kecurangan maka Allah/Tuhan adalah saksi
saya, dan saya bersedia menerima hukumanNya. Aamiin. */
