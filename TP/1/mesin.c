#include "head.h"

// FUNGSI UNTUK KE INTEGERKAN
int strip (char command[]) {
    if (strcmp(command,"kanan") == 0) {
        return 11;
    } else if (strcmp(command,"kiri") == 0) {
        return 12;
    } else if (strcmp(command,"bawah") == 0) {
        return 21;
    } else if (strcmp(command,"atas") == 0) {
        return 22;
    }
}

// PORSEDUR UNTUK PRINT PETA ASLI (TRANSLATE)
void print (int field[10][10]) {
    int i, j;
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            switch (field[i][j]) {
                case 0 : printf("*");break;
                case 1 : printf("-");break;
                case 2 : printf("|");break;
                case 3 : printf("x");break;
            }
        }
        printf("\n");
    }
}
