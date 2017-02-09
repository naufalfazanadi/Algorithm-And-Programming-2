#include "head.h"

int main () {
  n = 0; // inisialisasi

  pack record[64]; // array untuk menampung hasil read dari file

  // ngeread dari file
  file_scan(record, "firstlist.txt");
  file_scan(record, "secondlist.txt");

  ip(record); // hitung ip

  quick_sort(0, n-1, record); // sorting berdasarkan ip

  write(record); // write ke result

  return 0;
}
  // int i;
  // for (i = 0; i < n; i++) {
  //   printf("%s %s %.2lf %d\n", record[i].nim, record[i].nama, record[i].mutu,
  //                              record[i].sks);
  //   printf("%s %s %.2f\n", record[i].nim, record[i].nama, record[i].ip);
  // }

/*
inputan

1403407 Lyra 71.60 20
1404551 Atria 83.30 24
1406424 Bellatrix 69.80 20
## ## ## ##

1403703 Sirius 74.80 20
1407055 Aldebaran 72.60 21
1401717 Cygnus 85.80 24
## ## ## ##


1401713 Lyra 71.60 20
1401717 Cygnus 85.80 24
1401717 Cygnus 85.80 24
1401711 Lyra 71.60 20
## ## ## ##

1401717 Cygnus 85.80 24
1401717 Cygnus 85.80 24
1401712 Lyra 71.60 20
1401714 Lyra 71.60 20
## ## ## ##
 */