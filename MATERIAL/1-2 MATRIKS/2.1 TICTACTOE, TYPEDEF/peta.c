/////////////////////////////////////////////////////////
///       [Alpro2] 2nd MEET - MATRIX TYPEDEF         ////
///                  MAIN PETA KARTU                 ////
///                                                  ////
///            code by: naufalfazanadi               ////
/////////////////////////////////////////////////////////
#include <stdio.h>

typedef struct {
    char kartu;
    int skor;
} backend;

typedef struct {
    int x;
    int y;
} kordinat;

kordinat move (kordinat coordinate, int playermove) {
    int i, j;
    for (i = 0; i < playermove; i++) {
        if (coordinate.y >= 3) {
            coordinate.x++;
            coordinate.y = 0;
        } else {
            coordinate.y++;
        }
    }
    return coordinate;
}

int main () {

    backend database[3][3];
    // INISIALISASI DATABASE
    database[0][0].kartu = 'A';
    database[0][0].skor = 8;
    database[0][1].kartu = 'D';
    database[0][1].skor = 1;
    database[0][2].kartu = 'I';
    database[0][2].skor = 3;
    database[1][0].kartu = 'P';
    database[1][0].skor = 9;
    database[1][1].kartu = 'W';
    database[1][1].skor = 2;
    database[1][2].kartu = 'Z';
    database[1][2].skor = 4;
    database[2][0].kartu = 'X';
    database[2][0].skor = 5;
    database[2][1].kartu = 'H';
    database[2][1].skor = 10;
    database[2][2].kartu = 'O';
    database[2][2].skor = 6;

    int i, j, k;
    int field[3][3] = {0};
    int playermove;

    kordinat coordinate[2] = {0};

    for (i = 0; i < 6; i++) {
        printf("Player %d move : ", i % 2 + 1);
        scanf("%d", &playermove);
        coordinate[i%2 + 1] = move (coordinate[i%2 + 1], playermove);
        printf("%d %d\n", coordinate[i%2 + 1].x, coordinate[i%2 + 1].y);
    }

    return 0;
}
