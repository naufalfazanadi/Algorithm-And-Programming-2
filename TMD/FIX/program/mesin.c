#include "head.h"

// hold screen, template dari bu Rosa
void wait(float x) {
  //prosedur wait
  time_t start;
  time_t current;
  time(&start);
  do
    time(&current);
  while(difftime(current,start) < x);
}

// ================== WILL USE AGAIN ==================
// MAIN MENU, notes : parameter just for cls if 0 dont cls if 1 cls
void mainMenu(int clearScreen) {
  if (clearScreen == 1) { // cek param
    system("cls");
  }

  int x; // for choice

  // DESIGN
  printf("--------------------------------\n");
  printf("|           Main Menu          |\n");
  printf("--------------------------------\n");
  printf("| 0. Panjang dan Lebar Papan   |\n");
  printf("| 1. Kelola makanan            |\n");
  printf("| 2. Kelola perjalanan         |\n");
  printf("| 3. A Cari makanan            |\n");
  printf("| 4. Keluar                    |\n");
  printf("--------------------------------\n");
  printf("Masukkan Menu: ");
  scanf("%d", &x); // input choice

  switch (x) { // conditional
    case 0:menu0();break;
    case 1:menu1();break;
    case 2:menu2();break;
    case 3:menu3();break;
    case 4:
      system("cls");
      printf("Have a nice day! :)\n");
      system("exit");
      break;
    default: errorScreen(404); // if wrong input
  }
}

// Error screen for wrong input in menu
void errorScreen(int whatMenu) {
  system("cls");

  int i;

  printf("Sorry nothing to display...\n\n");
  printf("Back to menu, Please Wait");
  for (i = 3; i >= 1; i--) {
    wait(1);
    printf(" .");
  }
  printf("\n");

  switch(whatMenu) {
    case 404: mainMenu(1); break;
    case 0: menu0(); break;
    case 1: menu1(); break;
    case 2: menu2(); break;
  }
}

// ================== MENU SELECTION ==================
// SET BOARD
void menu0() {
  system("cls"); // clrscr

  int i;

  // DESIGN
  printf("---------------------\n");
  printf("\tINPUT\n");
  printf("---------------------\n");
  printf("Panjang papan : ");
  scanf("%d", &x); // input panjang
  printf("Lebar papan   : ");
  scanf("%d", &y); // input lebar

  /*proses*/
  setBoard(); // set panjang dan lebar papan

  printf("Board has been set!\n\n");

  printf("Back to menu, Please Wait");
  for (i = 3; i >= 1; i--) {
    wait(1);
    printf(" .");
  }
  printf("\n");

  mainMenu(1); // Back to main menu
}

// TMAKANAN
void menu1() {
  system("cls"); // clearscreen

  read("../fileData/tmakanan.txt"); // read first
  printBorder(0); // show table makanan

  int x;
  printf("MENU makanan : \n");
  printf("1. Tambah\n");
  printf("2. Hapus\n");
  printf("3. Menu utama\n\n");

  printf("Pilihan Menu: ");
  scanf("%d", &x); // pilih menu

  // perkondisian
  switch(x) {
    case 1: tambah(1); break;
    case 2: hapus(1); break;
    case 3: mainMenu(1); break;
    default : errorScreen(1);
  }
}

// TPERJALANAN
void menu2() {
  system("cls"); // clearscreen

  read("../fileData/tperjalanan.txt"); // read first

  printBorder(1); // show table perjalanan

  int x;
  printf("MENU makanan : \n");
  printf("1. Tambah\n");
  printf("2. Hapus\n");
  printf("3. Menu utama\n\n");

  printf("Pilihan Menu: ");
  scanf("%d", &x); // pilih menu

  // perkondisian
  switch(x) {
    case 1: tambah(2); break;
    case 2: hapus(2); break;
    case 3: mainMenu(1); break;
    default : errorScreen(2);
  }
}

// ANIMASI
void menu3() {
  read("../fileData/tperjalanan.txt"); // read perjalanan

  setMakanan(); // masang makanan di papan

  int i, j, k; // untuk loop
  char temp;
  int energi = 0; // energi A
  int stats; // boolean

  int count = 0; // untuk mengganti warna
  int hold = 0; // hold warna saat looping

  // loop sebanyak perjalanan
  for (i = 0; i < nWay; i++) {
    system("cls"); // clearscreen

    // PENGECEKAN KOORDINAT A DENGAN MAKANAN
    stats = 0;
    j = 0;
    while (j < nFood && stats == 0) { // loop untuk cek koordinat A
      if (tperjalanan[i].x == tmakanan[j].x &&
          tperjalanan[i].y == tmakanan[j].y) { // if same coordinate
        hold++; // iterasi hold color
        // loop sebanyak panjang nama makanan
        for (k = 0; k < strlen(tmakanan[j].nama); k++) {
          if (board[tmakanan[j].y + 1][tmakanan[j].x + 1 + k]
              == tmakanan[j].nama[k]) { // hapus yang srting nya dia sendiri
            board[tmakanan[j].y + 1][tmakanan[j].x + 1 + k] = ' '; // set to ' '
          }
        }
        energi += tmakanan[j].energi; // add the energi
        stats = 1; // true
      }
      j++;
    }
    // --------------------------------------

    if (i != 0) { // jika bukan langkah pertama
      board[tperjalanan[i-1].y + 1][tperjalanan[i-1].x + 1] = temp;
    }

    // temp untuk loop selanjutnya
    temp = board[tperjalanan[i].y + 1][tperjalanan[i].x + 1];

    // set A
    board[tperjalanan[i].y + 1][tperjalanan[i].x + 1] = 'A';

    count = hold % 6; // color
    // PRINT BOARD
    for (j = 0; j < x+3; j++) {
      for (k = 0; k < y+3; k++) {
        if (board[j][k] != ' ' && board[j][k] != '-' && board[j][k] != '|'
            && board[j][k] != 'A') { // if untuk cari makanan

          printColor(count % 6, board[j][k]); // print char berwarna
          if (board[j][k + 1] == ' ') { // penyetop nya spasi
            count++; // ganti warna
          }
        } else { // kalau bukan makanan
          printf("%c", board[j][k]); // print biasa aja (putih)
        }
      }
      printf("\n");
    }
    printf("Energi A : %d\n\n", energi); // print energi yang sudah dimakan

    wait(1);
  }
  // back to main menu
  mainMenu(0);
}

// ============================= OTHER PROCESS ========================
// Setting the board
void setBoard() {
  int i, j;

  // ---------- UNTUK GARIS PALING ATAS ----------
  board[0][0] = '|';
  for (i = 1; i < y+2; i++) {
    board[0][i] = '-';
  }
  board[0][i] = '|';
  board[0][i+1] = '\0';

  // -------------- UNTUK KOTAK NYA --------------
  for (i = 1; i <= x+1; i++) {
    board [i][0] = '|';
    for (j = 1; j < y+2; j++) {
      board[i][j] = ' ';
    }
    board[i][j] = '|'; j++;
    board[i][j] = '\0';
  }

  // ---------- UNTUK GARIS PALING BAWAH ----------
  board[x+2][0] = '|';
  for (i = 1; i < y+2; i++) {
    board[x+2][i] = '-';
  }
  board[x+2][i] = '|';
  board[x+2][i+1] = '\0';
}

// ----------------------- READ / WRITE -------------------
// scanning dari file
void read(char path[50]) {
  FILE *seqFile;
  seqFile = fopen(path,"r"); // read

  // untuk scan int
  char tempA[8];
  char tempB[8];
  char tempC[8];

  max_nama = 0;

  if (strcmp(path, "../fileData/tmakanan.txt") == 0) {
    nFood = 0; // set to 0
    // ------------------- ke arrayin ------------------
    fscanf(seqFile,"%s %s %s %s", &tempA, &tempB, &tmakanan[nFood].nama,&tempC);

    // loop hingga dummy
    while (strcmp(tmakanan[nFood].nama, "##") != 0){
      // Convert
      tmakanan[nFood].x = atoi(tempA);
      tmakanan[nFood].y = atoi(tempB);
      tmakanan[nFood].energi = atoi(tempC);

      nFood++; // iterasi
      fscanf(seqFile,"%s %s %s %s", &tempA,&tempB,&tmakanan[nFood].nama,&tempC);

      // cek terpanjang
      if (strlen(tmakanan[nFood-1].nama) > max_nama) {
        max_nama = strlen(tmakanan[nFood-1].nama);
      }
    }
    sort(0); // di sort setelah di read karena mungkin saja dari file nya acak2
  } else if (strcmp(path, "../fileData/tperjalanan.txt") == 0) {
    nWay = 0; // set to 0
    // ------------------- ke arrayin ------------------
    fscanf(seqFile,"%s %s", &tempA, &tempB);

    // loop hingga dummy
    while (strcmp(tempA, "##") != 0) {
      // convert
      tperjalanan[nWay].x = atoi(tempA);
      tperjalanan[nWay].y = atoi(tempB);

      nWay++; // iterasi
      fscanf(seqFile,"%s %s", &tempA, &tempB);
    }
    sort(1); // di sort setelah di read karena mungkin saja dari file nya acak2
  }
  fclose(seqFile); // dont forget to close
}

// write ke result
void write(char path[50]) {
  FILE *seqFile;

  seqFile = fopen(path,"w"); // tipe nya write "w"
  int i;

  // writing...
  if (strcmp(path,"../fileData/tmakanan.txt") == 0) {
    // print makanan
    for(i = 0; i < nFood; i++){
      fprintf(seqFile, "%d %d %s %d\n", tmakanan[i].x, tmakanan[i].y,
                                        tmakanan[i].nama, tmakanan[i].energi);
    }
    // print dummy
    fprintf(seqFile, "%s %s %s %s\n", "##","##","##","##"); // dummy data

  } else if (strcmp(path,"../fileData/tperjalanan.txt") == 0){
    // print perjalanan
    for(i = 0; i < nWay; i++){
      fprintf(seqFile, "%d %d\n", tperjalanan[i].x, tperjalanan[i].y);
    }
    // print dummy
    fprintf(seqFile, "%s %s\n", "##","##"); // dummy data

  }

  fclose(seqFile); // dont forget to close
}

// sort txt
void sort (int foodOrWay) {
  int i;
  int flip;
  food temp1; // temp untuk makanan
  way temp2; // temp untuk perjalanan

  if (foodOrWay == 0) { // makanan
    do{
        flip = 0;
        for(i = 0; i < (nFood-1); i++){ // loop sebanyak jumlah array
          // sort berdasarkan y lalu x
          if(tmakanan[i].y > tmakanan[i+1].y ||
            (tmakanan[i].y == tmakanan[i+1].y &&
              tmakanan[i].x > tmakanan[i+1].x)) {
              // switching
              temp1 = tmakanan[i];
              tmakanan[i] = tmakanan[i+1];
              tmakanan[i+1] = temp1;
              flip = 1;
          }
        }
    } while(flip == 1); // selama ada data yg berubah

  } else if (foodOrWay == 1) { // perjalanan
    do{
        flip = 0;
        for(i = 0; i < (nWay-1); i++){ // loop sebanyak jumlah array
          // sort berdasarkan y lalu x
          if(tperjalanan[i].y > tperjalanan[i+1].y ||
            (tperjalanan[i].y == tperjalanan[i+1].y &&
              tperjalanan[i].x > tperjalanan[i+1].x)){
              // switching
              temp2 = tperjalanan[i];
              tperjalanan[i] = tperjalanan[i+1];
              tperjalanan[i+1] = temp2;
              flip = 1;
          }
        }
    } while(flip == 1); // selama ada data yg berubah
  }
}

// ------------------ PRINT TABEL + BORDERING RESPONSIVE --------------
// print table
void printBorder(int x) {
  int i, j;

  if (x == 0) { // jika tmakanan
    // ------------ --- BORDERING ----------------
    // Header
    for (i = 0; i < 11; i++) {
      printf("-");
    }
    for (i = 0; i < max_nama - 4; i++) {
      printf("-");
    }
    for (i = 0; i < 5; i++) {
      printf("-");
    }
    for (i = 0; i < 9; i++) {
      printf("-");
    }
    printf("\n");

    printf("| X  ");
    printf("| Y  ");

    printf("|NAMA ");
    for (i = 0; i < max_nama - 4; i++) {
      printf(" ");
    }

    printf("|ENERGI |\n");

    for (i = 0; i < 11; i++) {
      printf("-");
    }
    for (i = 0; i < max_nama - 4; i++) {
      printf("-");
    }
    for (i = 0; i < 5; i++) {
      printf("-");
    }
    for (i = 0; i < 9; i++) {
      printf("-");
    }
    printf("\n");
    // end of header
    // ----------------- OUTPUT DARI FILE ---------------------
    for (i = 0; i < nFood; i++) {
      printf("|%d", tmakanan[i].x); // x
      // SPACING
      for (j = 0; j < 4 - len(tmakanan[i].x); j++) {
        printf(" ");
      }

      printf("|%d", tmakanan[i].y); // y
      // SPACING
      for (j = 0; j < 4 - len(tmakanan[i].y); j++) {
        printf(" ");
      }

      printf("|%s", tmakanan[i].nama); // nama
      // SPACING
      if (max_nama < 5) {
        for (j = 0; j < 5 - strlen(tmakanan[i].nama); j++) {
          printf(" ");
        }
      } else {
        for (j = 0; j < max_nama - strlen(tmakanan[i].nama) + 1; j++) {
          printf(" ");
        }
      }

      printf("|%d", tmakanan[i].energi);
      // SPACING
      for (j = 0; j < 7 - len(tmakanan[i].energi); j++) {
        printf(" ");
      }

      printf("|\n");
    }

    // LAST BORDER
    for (i = 0; i < 11; i++) {
      printf("-");
    }
    for (i = 0; i < max_nama - 4; i++) {
      printf("-");
    }
    for (i = 0; i < 5; i++) {
      printf("-");
    }
    for (i = 0; i < 9; i++) {
      printf("-");
    }
    printf("\n");

  } else if (x == 1) { // jika tperjalanan
    // Head
    for (i = 0; i < 11; i++) {
      printf("-");
    }
    printf("\n");

    printf("| X  ");
    printf("| Y  |\n");

    for (i = 0; i < 11; i++) {
      printf("-");
    }
    printf("\n");

    // ISI NYA
    for (i = 0; i < nWay; i++) {
      printf("|%d", tperjalanan[i].x);
      for (j = 0; j < 4 - len(tperjalanan[i].x); j++) {
        printf(" ");
      }
      printf("|%d", tperjalanan[i].y);
      for (j = 0; j < 4 - len(tperjalanan[i].y); j++) {
        printf(" ");
      }
      printf("|\n");
    }

    // FOOT
    for (i = 0; i < 11; i++) {
      printf("-");
    }
    printf("\n");
  }
}

// CHECK LONG INT E.G. (1321 = 5)
int len(int x) {
  x /= 10;
  if (x == 0) {
    return 1;
  } else {
    return len(x) + 1;
  }
}

// ------------------- MANAGE FILE -----------------------
// tambah data
void tambah(int menu) {
  int i = 0, j; // loop
  int stats = 0; // boolean

  char nama[32]; // untuk inputan nama
  int x, y, energi; // untuk inputan x y energi

  // INPUTING
  printf("X : ");
  scanf("%d", &x);
  printf("Y : ");
  scanf("%d", &y);

  // Kalau makanan maka input nama dan energi nya
  if (menu == 1)  {
    printf("Nama : ");
    scanf("%s", &nama);
    printf("Energi : ");
    scanf("%d", &energi);

    // UNTUK MAKANAN DULU
    // cek ketersediaan
    while (i < nFood && stats == 0) {
      if (x == tmakanan[i].x && y == tmakanan[i].y) { // kalau udah ada koornya
        stats = 1;
      } else if (strcmp(nama, tmakanan[i].nama) == 0) { // kalau udah ada nama
        stats = 2;
      } else if (x < 0 || y < 0) { // kalau negative
        stats = 3;
      }
      i++;
    }

    if (stats == 1) { // kalau ada koornya
      printf("\nMaaf koordinat %d %d sudah ada makanan\n", x, y);
      printf("Back to menu. . .\n");
    } else if (stats == 2) { // kalau ada nama nya
      printf("\nMaaf makanan %s sudah ada dalam tabel\n", nama);
      printf("Back to menu. . .\n");
    } else if (stats == 3) { // kalau negative
      printf("No negative!. . .\n");
    } else if (stats == 0) { // ADD MAKANAN
      i = 0;

      while (i < nFood && stats == 0) {
        // DISISIPKAN
        if (tmakanan[i].y > y || (tmakanan[i].y == y && tmakanan[i].x >= x)) {
          // geser
          for (j = nFood; j > i; j--) {
            tmakanan[j] = tmakanan[j - 1];
          }
          // nyisip
          tmakanan[j].x = x;
          tmakanan[j].y = y;
          strcpy(tmakanan[j].nama, nama);
          tmakanan[j].energi = energi;

          nFood++; // iterasi
          stats = 1; // true
        }
        i++;
      }
      // nambah diakhir
      if (stats == 0) {
        tmakanan[nFood].x = x;
        tmakanan[nFood].y = y;
        strcpy(tmakanan[nFood].nama, nama);
        tmakanan[nFood].energi = energi;
        nFood++;
      }
      write("../fileData/tmakanan.txt"); // write
      printf("Updating table.");
      for (j = 0; j < 1; j++) {
        wait(1);
        printf(" .");
      }
    }
    wait(2);
    menu1(); // back to menu
  } else if (menu == 2) { // jika tambah perjalanan
    if (x < 0 || y < 0) { // kalau negative
      stats = 3;
    }

    if (stats == 3) { // kalau negatives
      printf("No negative!. . .\n");
    } else {
      // loop
      while (i < nWay && stats == 0) {
        if (tperjalanan[i].y > y || (tperjalanan[i].y == y
            && tperjalanan[i].x >= x)) { // sisip y dulu baru x
          // geser
          for (j = nWay; j > i; j--) {
            tperjalanan[j] = tperjalanan[j - 1];
          }
          // sisip
          tperjalanan[j].x = x;
          tperjalanan[j].y = y;
          nWay++; // iterasi
          stats = 1; // true
        }
        i++;
      }
      // kalau diujung
      if (stats == 0) {
        tperjalanan[nWay].x = x;
        tperjalanan[nWay].y = y;
        nWay++;
      }
      write("../fileData/tperjalanan.txt"); // write ke txt
      printf("Updating table.");
      for (j = 0; j < 1; j++) {
        wait(1);
        printf(" .");
      }
    }
    wait(2);
    menu2(); // back to menu
  }
}

// hapus data
void hapus(int menu) {
  int i = 0, j; // var loop
  int stats = 0; // boolean

  char nama[32]; // var nama
  int x, y; // var untuk x dan y

  char yaOrNo; // y / n

  if (menu == 2) { // untuk perjalanan
    // input koor nya
    printf("X : ");
    scanf("%d", &x);
    printf("Y : ");
    scanf("%d", &y);

    while (i < nWay && stats == 0) {
      // kalau ketemu
      if (x == tperjalanan[i].x && y == tperjalanan[i].y) {
        // cek konfirmasi
        printf("Koordinat %d %d ditemukan, Hapus ? (y / n) ", x, y);
        scanf(" %c", &yaOrNo);

        // kalau ya
        if (yaOrNo == 'y' || yaOrNo == 'Y') {
          if (i == nWay - 1) { // kalau di ujung
            nWay--;
          } else { // kalau di tengah
            // geser
            for (j = i; j < nWay - 1; j++) {
              tperjalanan[j] = tperjalanan[j + 1];
            }
            nWay--; // --
          }
          stats = 1;
        } else { // kalau tidak
          stats = 2;
        }
      }
      i++; // iterasi
    }

    // kalau tidak ada
    if (stats == 0) {
      printf("Koordinat %d %d tidak ada pada tabel...\n", x, y);
    } else if (stats == 1) { // kalau true
      write("../fileData/tperjalanan.txt"); // write
      printf("\nUpdating table.");
      for (j = 0; j < 1; j++) {
        wait(1);
        printf(" .");
      }
    } else { // kalau dicancel
      printf("\nBack to menu.");
      for (j = 0; j < 1; j++) {
        wait(1);
        printf(" .");
      }
    }
    wait(2);
    menu2(); // back to menu
  } else if (menu == 1)  { // kalau tmakanan
    // input nama
    printf("Nama : ");
    scanf("%s", &nama);

    // loop
    while (i < nFood && stats == 0) {
      // kalau ada
      if (strcmp(tmakanan[i].nama, nama) == 0) {
        // konfirmasi
        printf("Data %s ditemukan, hapus ? (y/n) ", nama);
        scanf(" %c", &yaOrNo);

        // kalau y
        if (yaOrNo == 'y' || yaOrNo == 'Y') {
          // kalau diujung
          if (i == nFood - 1) {
            nFood--;
          } else { // kalau ditengah
            // geser
            for (j = i; j < nFood - 1; j++) {
              tmakanan[j] = tmakanan[j + 1];
            }
            nFood--;
          }
          stats = 1;
        } else { // kalau n
          stats = 2;
        }
      }
      i++;
    }
    // kalau gaada
    if (stats == 0) {
      printf("\nMakanan %s tidak ada dalam tabel...\n", nama);
    } else if (stats == 1) { // kalau ada
      write("../fileData/tmakanan.txt"); // write
      printf("\nUpdating table.");
      for (j = 0; j < 1; j++) {
        wait(1);
        printf(" .");
      }
    } else { // kalau dicancel
      printf("\nBack to menu.");
      for (j = 0; j < 1; j++) {
        wait(1);
        printf(" .");
      }
    }
    wait(2);
    menu1(); // back to menu
  }
}

// ------------------ UNTUK ANIMASI --------------------
// Pasang makanan di papan
void setMakanan() {
  read("../fileData/tmakanan.txt"); // read makanan dulu

  setBoard(); // set the board

  int i, j; // loop

  for (i = 0; i < nFood; i++) { // loop sebanyak makanan
    for (j = 0; j < strlen(tmakanan[i].nama); j++) { // loop hingga panjang nama
      // pasang huruf makanan pada papan
      board[tmakanan[i].y + 1][tmakanan[i].x + 1 + j] = tmakanan[i].nama[j];
    }
  }
}

// ngeprint berwarna
void printColor(int num, char ch) {
  switch(num) {
    case 0: printf( COLOR_RED "%c" COLOR_RESET, ch); break;
    case 1: printf( COLOR_YELLOW "%c" COLOR_RESET, ch); break;
    case 2: printf( COLOR_GREEN "%c" COLOR_RESET, ch); break;
    case 3: printf( COLOR_BLUE "%c" COLOR_RESET, ch); break;
    case 4: printf( COLOR_MAGENTA "%c" COLOR_RESET, ch); break;
    case 5: printf( COLOR_CYAN "%c" COLOR_RESET, ch); break;
  }
}