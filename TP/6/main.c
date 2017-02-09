#include "head.h"

int main () {
  // ------------------ INPUT ----------------------
  day jam = {FALSE}; // untuk mengisi irisan

  int i, j, n; // FOR LOOP

  jadwal x; // var untuk penampung inputan

  // input, loop i untuk orang nya (untuk jadwal 3 orang)
  for (i = 0; i < 3; i++) {
    scanf("%d", &n); // jumlah jadwal

    for (j = 0; j < n; j++) {
      scanf("%d %d %d", &x.hari, &x.masuk, &x.keluar);

      // update jadwal kuliah
      jam = cek_jam(jam, x.hari, x.masuk, x.keluar);
    }
  }

  // ------------- SEARCH YG IRISAN (FALSE) -------------
  di_searching hasil = search_irisan(jam);

  // ------------------ OUTPUT ------------------
  if (hasil.bol == FALSE) { // jika tidak ada yg irisan

    printf("Tidak ada irisan jadwal.\n");

  } else { // jika ada irisannya

    for (i = 0; i < hasil.count; i++) {
      // convert dulu dari angka ke string
      char hari_char[8];
      switch (hasil.hari[i]) {
        case 0 : strcpy(hari_char, "Senin"); break;
        case 1 : strcpy(hari_char, "Selasa"); break;
        case 2 : strcpy(hari_char, "Rabu"); break;
        case 3 : strcpy(hari_char, "Kamis"); break;
        case 4 : strcpy(hari_char, "Jumat"); break;
      }
      // output
      printf("%s %d.00 - %d.00\n", hari_char, hasil.masuk[i], hasil.keluar[i]);
    }
  }

  // CEK OUTPUT

  printf("\t\t1 \t2 \t3 \t4 \t5\n");
  printf("------------------------------------------------------------------\n");
  for (i = 0; i < 11; i++) {
   printf("jam %d - %d \t%d ", i+7, i+8, jam.hari[0][i]);
   printf("\t%d ", jam.hari[1][i]);
   printf("\t%d ", jam.hari[2][i]);
   printf("\t%d ", jam.hari[3][i]);
   printf("\t%d ", jam.hari[4][i]);
   printf("\n");
  }
  return 0;
}


/*
Tobi, Moni dan Piyu berada di kelas yang berbeda. Mereka merupakan anggota dari salah satu Departemen BEM KEMAKOM. Saat ini mereka sedang menentukan waktu rapat rutin. Agar semua anggota dapat menghadiri rapat, yang dipilih adalah waktu dimana semua anggota tidak memiliki jadwal kuliah (irisan jadwal kosong). Buatlah program untuk mencari irisan jadwal kosong mereka, jika waktu beraktivitas ketiganya tidak kurang dari pukul 7 dan tidak lebih dari pukul 18. Gunakan algoritma searching sequential maupun binary search untuk menyelesaikan permasalahan ini!

Format masukan (diulang sebanyak 3 kali, untuk Tobi, Moni, kemudian Piyu) :
n (jumlah daftar jam yang dipakai untuk kuliah, mulai hari Senin-Jumat)
daftar jadwal, terdiri dari : [nomor_hari] [jam_mulai] [jam_selesai]

Format keluaran :
[nama_hari] [batas_awal_jam_kosong - batas_akhir]
Contoh Masukan

5
1 7 18 (maksudnya hari Senin, mulai dari jam 7 hingga jam 18)
2 7 10 (hari Selasa mulai jam 7 hingga jam 10, kemudian...
2 16 18 ...dilanjutkan jam 16 hingga jam 18. Berarti di hari selasa, Tobi punya jadwal kosong dari pukul 10 s.d. pukul 16)
3 7 12  (dst.)
4 9 12

3
2 7 18
3 10 16
4 7 16

4
1 8 12
1 16 17
3 8 12
4 7 10

Contoh Keluaran

Rabu 16.00 - 18.00
Kamis 16.00 - 18.00
Jumat 7.00 - 18.00
Contoh Masukan 2


5
1 7 18
2 7 16
3 9 16
4 7 12
4 16 18

4
2 10 18
3 7 10
4 7 16
5 10 18

3
3 16 18
5 7 10
5 13 16

Contoh Keluaran 2

Tidak ada irisan jadwal.

*/