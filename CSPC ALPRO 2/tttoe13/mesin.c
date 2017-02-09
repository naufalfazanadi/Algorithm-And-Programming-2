#include "head.h"

int win_lose (int field[3][3]) {
    int count = 0;

    if (field[0][0] == 1 && field[0][1] == 1 && field[0][2] == 1) {
        count = 1;
    } else if (field[1][0] == 1 && field[1][1] == 1 && field[1][2] == 1) {
        count = 1;
    } else if (field[2][0] == 1 && field[2][1] == 1 && field[2][2] == 1) {
        count = 1;
    } else if (field[0][0] == 1 && field[1][1] == 1 && field[2][2] == 1) {
        count = 1;
    } else if (field[0][2] == 1 && field[1][1] == 1 && field[2][0] == 1) {
        count = 1;
    } else if (field[0][0] == 1 && field[1][0] == 1 && field[2][0] == 1) {
        count = 1;
    } else if (field[0][1] == 1 && field[1][1] == 1 && field[2][1] == 1) {
        count = 1;
    } else if (field[0][2] == 1 && field[1][2] == 1 && field[2][2] == 1) {
        count = 1;
    }

    if (field[0][0] == 2 && field[0][1] == 2 && field[0][2] == 2) {
        count = 2;
    } else if (field[1][0] == 2 && field[1][1] == 2 && field[1][2] == 2) {
        count = 2;
    } else if (field[2][0] == 2 && field[2][1] == 2 && field[2][2] == 2) {
        count = 2;
    } else if (field[0][0] == 2 && field[1][1] == 2 && field[2][2] == 2) {
        count = 2;
    } else if (field[0][2] == 2 && field[1][1] == 2 && field[2][0] == 2) {
        count = 2;
    } else if (field[0][0] == 2 && field[1][0] == 2 && field[2][0] == 2) {
        count = 2;
    } else if (field[0][1] == 2 && field[1][1] == 2 && field[2][1] == 2) {
        count = 2;
    } else if (field[0][2] == 2 && field[1][2] == 2 && field[2][2] == 2) {
        count = 2;
    }

    return count;
}

/*
P1 A 0 1
P2 R 0 2
P1 A 1 0
P2 R 1 1
P2 R 2 0
P1 A 2 2
 */
