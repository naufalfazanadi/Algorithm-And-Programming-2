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

// ------------------------ SEQUENTIAL FILE HERE ------------------------------
void read () {
  n = 0;

  FILE *seqFile;
  seqFile = fopen("tkursi.txt","r"); // read

  // ------------------- ke arrayin ------------------
  fscanf(seqFile,"%s %s", &record[n].kiri, &record[n].kanan);

  while (strcmp(record[n].kiri, "dummy") != 0 &&
         strcmp(record[n].kanan, "dummy") != 0) {
    n++;
    fscanf(seqFile, "%s %s", &record[n].kiri, &record[n].kanan);
  }

  fclose(seqFile); // dont forget to close
}

void write () {
  FILE *seqFile;

  seqFile = fopen("tkursi.txt","w"); // tipe nya write "w"

  // writing...
  int i;
  for(i = 0; i < n; i++){
    fprintf(seqFile, "%s %s\n", record[i].kiri, record[i].kanan);
  }

  fprintf(seqFile, "%s %s\n", "dummy","dummy"); // dummy data

  fclose(seqFile); // dont forget to close
}

// ------------------------ PROCESS ----------------------------
void turun(char penumpang[]) { // procedure turun
  int i = 0;
  int success = 0;

  // loop
  while (strcmp(record[i].kiri, "dummy") != 0 && success == 0) {
    // jika si orang nya disitu maka kosongin disitu nya
    if (strcmp(penumpang, record[i].kiri) == 0) { // jika di kiri
      strcpy(record[i].kiri, "Kosong");
      success = 1;
    } else if (strcmp(penumpang, record[i].kanan) == 0) { // jika di kanan
      strcpy(record[i].kanan, "Kosong");
      success = 1;
    }
    i++;
  }

  // kalau misal nya gaada nama si penupang
  if (success == 0) {
    printf("Tidak ada penumpang bernama %s\n", penumpang);
  }
}

void sebelahan(char ribbon[], char penumpang1[]) { // procedure yang sebelahan
  int validitas = 0;
  char penumpang2[32];

  // NGECEK VALIDITAS PITA
  INCKATA(ribbon);
  strcpy(penumpang2, ckata); // buat penumpang ke 2

  // cek validitas
  INCKATA(ribbon);

  if (strcmp(ckata, "duduk") == 0) {
    INCKATA(ribbon);
    if (strcmp(ckata, "bersebelahan") == 0) {
      validitas = 1;
    }
  }

  int i = 0;
  int success = 0;

  if (validitas == 1) {
    // loop
    while (strcmp(record[i].kiri, "dummy") != 0 && success == 0) {
      // CEK KEKOSONGAN SEBELAH NYA, PENUMPANG KE 1
      if (strcmp(penumpang1, record[i].kiri) == 0) { // kalau di kiri
        if (strcmp(record[i].kanan, "Kosong") == 0) { // trus kalau kanan kosong
          strcpy(record[i].kanan, penumpang2); // isi
        } else {
          printf("Sebelah %s sudah ada orang. . .\n", penumpang2); // kalau ada
        }
        success = 1;
      } else if (strcmp(penumpang1, record[i].kanan) == 0) { // kalau di kanan
        if (strcmp(record[i].kiri, "Kosong") == 0) { // trus kalau kiri kosong
          strcpy(record[i].kiri, penumpang2); // isi
        } else {
          printf("Sebelah %s sudah ada orang. . .\n", penumpang2); // kalau ada
        }
        success = 1;
      } else
      // CEK KEKOSONGAN SEBELAH NYA, PENUMPANG KE 2
      if (strcmp(penumpang2, record[i].kiri) == 0) { // kalau di kiri
        if (strcmp(record[i].kanan, "Kosong") == 0) { // kalau yang kanan kosong
          strcpy(record[i].kanan, penumpang1); // isi
        } else {
          printf("Sebelah %s sudah ada orang. . .\n", penumpang1); // kalau ada
        }
        success = 1;
      } else if (strcmp(penumpang2, record[i].kanan) == 0) { // kalau di kanan
        if (strcmp(record[i].kiri, "Kosong") == 0) { // kalau yang kiri kosong
          strcpy(record[i].kiri, penumpang1); // isi
        } else {
          printf("Sebelah %s sudah ada orang. . .\n", penumpang1); // kalau ada
        }
        success = 1;
      }
      i++;
    }

    // kalau gaada yang kosong maka tambahkan aja
    if (success == 0 && n < 20) {
      strcpy(record[n].kiri, penumpang1);
      strcpy(record[n].kanan, penumpang2);
      n++;
    } else if (n >= 20) { // kalau udah lebih dari 20,
                          // mau duduk dimana penumpangnya :v
      printf("BUS PENUH\n");
    }
  } else { // kalau ada kata yang salah
    printf("Perintah yang dimasukkan salah. . .\n");
  }
}

void duduk(char ribbon[], char penumpang1[]) { // procedure yang posisi
  char penumpang2[32];
  char posisi[10];
  int validitas = 0;

  // cek validasi kata
  INCKATA(ribbon);
  if (strcmp(ckata, "di") == 0) {
    INCKATA(ribbon);
    if (strcmp(ckata, "sebelah") == 0) {
      INCKATA(ribbon);
      strcpy(posisi, ckata);

      if (strcmp(posisi, "kiri") == 0 || strcmp(posisi, "kanan") == 0 ||
          strcmp(posisi, "depan") == 0 || strcmp(posisi, "belakang") == 0)
      validitas = 1;
    }
  }

  int i = 0, j; // untuk loop
  int success = 0;

  if (validitas == 1) {
    INCKATA(ribbon); // incremen untuk dapat data penumpang kedua
    strcpy(penumpang2, ckata);

    // kondisi posisi
    if (strcmp(posisi, "kiri") == 0) { // kiri
      while (strcmp(record[i].kiri, "dummy") != 0 && success == 0) {
        if(strcmp(penumpang2, record[i].kiri) == 0) { // kalau si orang nya
          printf("Udah mentok!\n");                   // pengen dikiri yang di
          success = 1;                                // kiri
        } else if (strcmp(penumpang2, record[i].kanan) == 0){
          if (strcmp(record[i].kiri, "Kosong") == 0) { // kalau kanannya kosong
            strcpy(record[i].kiri, penumpang1); // isi
          } else { // kalau adaan
            printf("Kursi penuh!\n");
          }
          success = 1;
        }
        i++;
      }

      // nambah data
      if (success == 0 && n < 20) {
        strcpy(record[n].kiri, penumpang1);
        strcpy(record[n].kanan, penumpang2);
        n++;
      } else if (n >= 20) { // kalau bus nya udah penuh penumpang nya kemana :v
        printf("BUS PENUH\n");
      }
    } else if (strcmp(posisi, "kanan") == 0) { // kanan
      while (strcmp(record[i].kiri, "dummy") != 0 && success == 0) {
        if(strcmp(penumpang2, record[i].kanan) == 0) {
          printf("Udah mentok!\n");
          success = 1;
        } else if (strcmp(penumpang2, record[i].kiri) == 0){
          if (strcmp(record[i].kanan, "Kosong") == 0) {
            strcpy(record[i].kanan, penumpang1);
          } else {
            printf("Kursi penuh!\n");
          }
          success = 1;
        }
        i++;
      }

      if (success == 0 && n < 20) {
        strcpy(record[n].kiri, penumpang2);
        strcpy(record[n].kanan, penumpang1);
        n++;
      } else if (n >= 20) {
        printf("BUS PENUH\n");
      }
    } else if (strcmp(posisi, "depan") == 0) { // depan
      while (strcmp(record[i].kiri, "dummy") != 0 && success == 0) {
        if(strcmp(penumpang2, record[i].kanan) == 0) {
          if (strcmp(record[i - 1].kanan, "Kosong") == 0) {
            strcpy(record[i - 1].kanan, penumpang1);
          } else if(strcmp(record[i - 1].kanan, "Kosong") != 0){
            // geser
            for (j = n; j > i; j--) {
              record[j] = record[j-1];
            }
            strcpy(record[j].kanan, penumpang1);
            strcpy(record[j].kiri, "Kosong");
            n++;
          }
          success = 1;
        } else if (strcmp(penumpang2, record[i].kiri) == 0){
          if (strcmp(record[i - 1].kiri, "Kosong") == 0) {
            strcpy(record[i - 1].kiri, penumpang1);
          } else if(strcmp(record[i - 1].kiri, "Kosong") != 0){
            // geser
            for (j = n; j > i; j--) {
              record[j] = record[j-1];
            }
            strcpy(record[j].kiri, penumpang1);
            strcpy(record[j].kanan, "Kosong");
            n++;
          }
          success = 1;
        }
        i++;
      }
    } else if (strcmp(posisi, "belakang") == 0) { // belakang
      while (strcmp(record[i].kiri, "dummy") != 0 && success == 0) {
        if(strcmp(penumpang2, record[i].kanan) == 0) {
          if (strcmp(record[i + 1].kanan, "Kosong") == 0) {
            strcpy(record[i + 1].kanan, penumpang1);
          } else if(strcmp(record[i + 1].kanan, "Kosong") != 0){
            i++;
            // geser
            for (j = n; j > i; j--) {
              record[j] = record[j-1];
            }
            strcpy(record[j].kanan, penumpang1);
            strcpy(record[j].kiri, "Kosong");
            n++;
          }
          success = 1;
        } else if (strcmp(penumpang2, record[i].kiri) == 0){
          if (strcmp(record[i + 1].kiri, "Kosong") == 0) {
            strcpy(record[i + 1].kiri, penumpang1);
          } else if(strcmp(record[i + 1].kiri, "Kosong") != 0){
            i++;
            // geser
            for (j = n; j > i; j--) {
              record[j] = record[j-1];
            }
            strcpy(record[j].kiri, penumpang1);
            strcpy(record[j].kanan, "Kosong");
            n++;
          }
          success = 1;
        }
        i++;
      }
    }
  } else {
    printf("Perintah yang dimasukkan salah. . .\n");
  }
}