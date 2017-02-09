#include "head.h"

int main () {
  char ribbon[1000]; // var pita

  scanf("%999[^\n]s", &ribbon); // input pita

  int stats = 0; // jumlah kata yang valid
  STARTKATA(ribbon); // start mesin

  stats += checking(); // mengecek kata

  while (EOPKATA(ribbon) == 0) { // loop hingga akhir pita
    INCKATA(ribbon); // next kata
    stats += checking(); // cek lagi
  }

  // OUTPUT
  printf("%d\n", stats);

  return 0;
}