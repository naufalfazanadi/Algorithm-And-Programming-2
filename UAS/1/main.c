#include "head.h"

int main () {
  char ribbon[1000]; // var pita

  scanf("%999[^\n]s", &ribbon); // input pita

  char ch1, ch2, ch3; // var menampung kombinasi dari 3 char berurutan

  START(ribbon); // mulai mesin

  // pengisian kombinasi
  ch1 = GETCC();
  INC(ribbon); // next
  ch2 = GETCC();
  INC(ribbon); // next
  ch3 = GETCC();

  int stats = 0; // jumlah kombinasi ang valid

  while (EOP() == 0) { // loop hingga akhir pita
    // cek kombinasi konso - vokal - angka
    if (cekKonsonan(ch1) == 1 && cekVokal(ch2) == 1 && cekInt(ch3) == 1) {
      stats++;
    }
    // menggeser char
    ch1 = ch2;
    ch2 = ch3;
    INC(ribbon);
    ch3 = GETCC();
  }

  // OUTPUT
  printf("%d\n", stats);

  return 0;
}