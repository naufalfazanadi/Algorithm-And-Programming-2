#include "head.h"

int main () {
    // inisialisasi peta
    int field[10][10] = {0};

    // koordinat awal
    int x, y;

    scanf("%d %d", &x, &y);
    field[y-1][x-1] = 3; // 3 UNTUK KODE TRANSLATE

    // jumlah langkah
    int n;

    scanf("%d", &n);

    int i, j; // UNTUK LOOP

    char command[6];
    int move;
    int intcom;

    // PROSES DAN INPUTAN LANGKAH
    for (i = 0; i < n; i++) {
        // input langkah
        scanf("%s %d", &command, &move);
        // ubah jadi integer
        intcom = strip(command);
        // pengubah peta menjadi - atau | dgn kode
        for (j = 0; j < move; j++) {
            switch (intcom) {
                case 11 : {
                    x++;
                    field[y-1][x-1] = 1;
                } break;
                case 12 : {
                    x--;
                    field[y-1][x-1] = 1;
                } break;
                case 21 : {
                    y++;
                    field[y-1][x-1] = 2;
                } break;
                case 22 : {
                    y--;
                    field[y-1][x-1] = 2;
                } break;
            }
        }
    }
    // OUTPUT dengan PROSEDUR
    print (field);

    return 0;
}
