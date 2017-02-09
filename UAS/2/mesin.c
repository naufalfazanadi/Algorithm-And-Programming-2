#include "head.h"

void STARTKATA(char pita[]){ // mulai mesin kata
  indeks = 0;
  panjangkata = 0;
  while(pita[indeks] == ' '){
    indeks++;
  }
  while((pita[indeks] != ' ') && (pita[indeks] != '.')){
    ckata[panjangkata] = pita[indeks];
    indeks++;
    panjangkata++;
  }
  ckata[panjangkata] = '\0';
}

void RESETKATA(){ // reset kata
  panjangkata = 0;
  ckata[panjangkata] = '\0';
}

void INCKATA(char pita[]){ // next kata
  panjangkata = 0;
  while(pita[indeks] == ' '){
    indeks++;
  }
  while((pita[indeks] != ' ') && (pita[indeks] != '.')){
    ckata[panjangkata] = pita[indeks];
    indeks++;
    panjangkata++;
  }
  ckata[panjangkata] = '\0';
}

char* GETCKATA(){ // untuk mendapatkan kata
  return ckata;
}

int GETPANJANGKATA(){ // untuk mendapatkan panjang kata
  return panjangkata;
}

int EOPKATA(char pita[]){ // End of pita kata
  if(pita[indeks] == '.'){
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

// UNTUK MENGECEK KATA APAKAH ADA KONSO VOKAL ANGKA
int checking () {
  int i;
  int vokal = 0, konsonan = 0, angka = 0; // boolean nya

  i = 0;
  while (i < GETPANJANGKATA() && (vokal == 0 || konsonan == 0 ||
         angka == 0)) { // loop hingga akhir kata dan selama booleannya 0 semua
    // CEK PER CHAR
    if (cekVokal(ckata[i]) == 1) {
      vokal = 1;
    } else if (cekInt(ckata[i]) == 1) {
      angka = 1;
    } else if (cekKonsonan(ckata[i]) == 1) {
      konsonan = 1;
    }
    // iterasi
    i++;
  }

  // jika terdapat konso vokal dan angka
  if (vokal == 1 && konsonan == 1 && angka == 1) {
    return 1; // true
  } else {
    return 0; // false
  }
}