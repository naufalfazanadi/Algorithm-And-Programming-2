#include "head.h"

int main () {
  read(); // read from file

  char ribbon[256];

  scanf("%255[^\n]s", &ribbon); // input pita

  // CHECK THE RIBBON
  STARTKATA(ribbon); // start

  char penumpang1[32]; // untuk kata pertama
  strcpy(penumpang1, GETCKATA());

  INCKATA(ribbon); // cek kata selanjut nya

  // kalau kata kedua nya memenuhi pola 1 2 3 maka panggil prosedur
  if (strcmp(GETCKATA(), "turun") == 0) {
    turun(penumpang1);
  } else if (strcmp(GETCKATA(), "duduk") == 0) {
    duduk(ribbon, penumpang1);
  } else if (strcmp(GETCKATA(), "dan") == 0) {
    sebelahan(ribbon, penumpang1);
  } else {
    // kalau salah
    printf("Input yang dimasukkan salah. . .\n");
  }

  // WRITE TO FILE
  write();

  // cek txt
  // int i;
  // for (i = 0; i < n; i++) {
  //   printf("%s %s\n", record[i].kiri, record[i].kanan);
  // }

  return 0;
}

/*
Asumsinya bus damri tersebut mempunyai 2 banjar kursi ke samping dan 20 baris ke belakang.

Format kalimat masukan dibatasi :
1. [namapenumpang] turun.
2. [namapenumpang1] duduk di sebelah kiri/kanan/depan/belakang [namapenumpang2].
3. [namapenumpang1] dan [namapenumpang2] duduk bersebelahan.

Tidak ada kemungkinan supir damri menginput kalimat selain dari ketiga itu.

Bonus :
Validasi jika input nama di barisan kursi yang sudah penuh,
misalnya Dina duduk di sebelah kanan Teti, maka ada warning seperti ini :

Barisan kursi sudah penuh. Silahkan input ulang :
[masukan baru dengan format kalimat 1, 2 atau 3]

Contoh Masukan

Dudu duduk di sebelah kanan Dida.

Contoh Keluaran

Pada file tkursi.txt akan terekam :
Dida Dudu
dummy dummy

Contoh Masukan 2

Dida turun.

Contoh Keluaran 2

Rekaman tkursi.txt :
Kosong Dudu
dummy dummy

Contoh Masukan 3

Tata dan Teti duduk bersebelahan.

Contoh Keluaran 3

Rekaman tkursi.txt :
Kosong Dudu
Tata Teti
dummy dummy
 */