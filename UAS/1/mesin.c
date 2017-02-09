#include "head.h"

void START(char pita[]){ // mulai mesin
  indeks = 0;
  cc = pita[indeks];
}

void INC(char pita[]){ // next char
  indeks++;
  cc = pita[indeks];
}

void ADV(char pita[]){ // next char mengabaikan ' '
  indeks++;
  cc = pita[indeks];

  while((cc == ' ') && (EOP() == 0)){
    indeks++;
    cc = pita[indeks];
  }
}

char GETCC(){ // untuk mendapatkan char
  return cc;
}

int EOP(){ // END OF PITA
  if(cc == '.'){
    return 1;
  }else{
    return 0;
  }
}

// CEK CHAR VOKAL
int cekVokal (char ch) {
  if (ch == 'a' || ch == 'i' || ch == 'u' || ch == 'e' || ch == 'o' ||
      ch == 'A' || ch == 'I' || ch == 'U' || ch == 'E' || ch == 'O') {
    return 1;
  } else {
    return 0;
  }
}

// CEK CHAR KONSONAN
int cekKonsonan (char ch) {
  if (ch != 'a' && ch != 'i' && ch != 'u' && ch != 'e' && ch != 'o' &&
      ch != 'A' && ch != 'I' && ch != 'U' && ch != 'E' && ch != 'O') {
    return 1;
  } else {
    return 0;
  }
}

// CEK CHAR ANGKA
int cekInt (char ch) {
  if (ch >= '0' && ch <= '9') {
    return 1;
  } else {
    return 0;
  }
}