#include <stdio.h>

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
}


int main() {

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

  return 0;
}