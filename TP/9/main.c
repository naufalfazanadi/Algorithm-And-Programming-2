#include "head.h"

int main () {
  int i, n;

  scanf("%d", &n); // jumlah sms

  char ribbon[256]; // untuk menampung string sms
  int stats[n]; // valid atau tidak

  for (i = 0; i < n; i++) {
    scanf(" %255[^\n]s", ribbon); // input string / pita
    stats[i] = checkSms(ribbon); // cek valid atau tidak
    // printf("%d\n", stats[i]);
  }

  for (i = 0; i < n; i++) { // loop sebanyak sms yg dikirimkan
    if (stats[i] == FALSE) { // jika dari fungsi dapat false
      printf("tidak valid\n");
    } else { // jika dapat true
      printf("valid\n");
    }
  }

  return 0;
}