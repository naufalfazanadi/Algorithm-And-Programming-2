#include "head.h"

// MESIN KATA (TEMPLATE BU ROSA)
void STARTKATA(char pita[]){
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

void RESETKATA(){
  panjangkata = 0;
  ckata[panjangkata] = '\0';
}

void INCKATA(char pita[]){
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

char* GETCKATA(){
  return ckata;
}

int GETPANJANGKATA(){
  return panjangkata;
}

int EOPKATA(char pita[]){
  if(pita[indeks] == '.'){
    return 1;
  }else{
    return 0;
  }
}

// MY FUNCTION

// Untuk kapitalisasi char
char toUpperCase (char ch) {
  if ((int)ch >= 65 && (int)ch <= 90) { // kalau sudah caps
    return ch;
  } else {
    return (char)((int)ch - 32); // kapitalisasi
  }
}

// Untuk cek sms, true atau false
// NOTE : If there is a wrong then the process stop and directly return FALSE
int checkSms(char str[256]) {
  STARTKATA(str); // START
  // printf("%s", ckata);

  // REG
  if (ckata[0] != 'R' && ckata[1] != 'E' && ckata[2] != 'G') {
    return FALSE;
  } else {
    INCKATA(str); // next
  }
  // printf("%s", ckata);

  // SBMPTN
  if (strcmp(ckata, "SBMPTN") != 0) {
    return FALSE;
  } else {
    INCKATA(str); // next
  }
  // printf("%s", ckata);

  // NAMA
  // Tanda nama 3 kata adalah _ nya ada 2
  int i, j;
  int word = 0;
  for (i = 0; i < GETPANJANGKATA(); i++) {
    if (ckata[i] == '_') { // cek '_'
      word++;
    }
  }

  if (word < 2) { // jika _ nya 1 berarti hanya 2 kata, dst
    return FALSE;
  } else {
    INCKATA(str); // next
  }
  // printf("%s", ckata);

  // LOKASI KOTA
  char location[32]; // untuk menampung lokasi kota utk dibandingkan dgn sekolah
  for (i = 0; i < GETPANJANGKATA(); i++) {
    if (ckata[i] >= 48 && ckata[i] <= 57) { // cek capslock
      return FALSE;
    } else { // jika sudah caps maka pindahkan
      location[i] = ckata[i];
    }
  }
  location[i] = '\0';

  INCKATA(str); // next
  // printf("%s", ckata);

  // SEKOLAH
  word = 0; // reset hitung kata
  for (i = 0; i < GETPANJANGKATA(); i++) {
    if (word == 2) { // e.g. SMAN_11_BANDUNG <- cek jika sudah di _B
      i--; // dec dulu agar enak loop j nya
      for (j = 0; j < strlen(location); j++) {
        i++; // iterasi supaya hingga akhir
        // printf("%d %c %c ", j, ckata[i], toUpperCase(location[j]));
        if (ckata[i] != toUpperCase(location[j])) { // cek kesamaan kota
          return FALSE;
        }
      }
    }

    if (ckata[i] == '_') { // cek jumlah kata dan sedang ada di kata ke brp
      word++;
    } else if (ckata[i] < 48 || (ckata[i] > 57 && ckata[i] < 65) ||
               ckata[i] > 90) { // cek caps atau angka
      return FALSE;
    }
  }

  if (word < 2) { // jika kurang dari 3 kata
    return FALSE;
  }

  INCKATA(str); // next
  // printf("%s", ckata);

  // KODE
  int star = 0;
  if (panjangkata != 6) { // jika panjang kode nya bukan 6 digit / char
    return FALSE;
  }

  i = 0;
  while (i < GETPANJANGKATA() && star == 0) {
    if (ckata[i] == '*') { // jika ada * maka kode valid
      star = 1;
    }
    i++;
  }

  if (star == 1) {
    return TRUE; // FINALLY RETURNING THE TRUE
  } else {
    return FALSE;
  }
}