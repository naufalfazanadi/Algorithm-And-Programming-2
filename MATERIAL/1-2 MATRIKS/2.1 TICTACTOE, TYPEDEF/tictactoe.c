/////////////////////////////////////////////////////////
///       [Alpro2] 2nd MEET - MATRIX TYPEDEF         ////
///                   TIC TAC TOE                    ////
///                                                  ////
///            code by: naufalfazanadi               ////
/////////////////////////////////////////////////////////
#include <stdio.h>

void print (int field[3][3]) {
    int i, j;
    for (i = 0; i < 3; i++) {
        printf("----------\n");
        
        for (j = 0; j < 3; j++) {
            printf("| ");

            if (field[i][j] == 0) {
                printf(" ");
            } else if (field[i][j] == 1) {
                printf("O");
            } else if (field[i][j] == 2) {
                printf("X");
            }
        }

        printf("|\n");
    }
    
    printf("----------\n");
}

int winner (int field[3][3]) {
    
}

int main () {

    int field[3][3] = {0};

    int i, j;

    int player[2];

    int win = 0;
    i=0;
    while (i < 9 && win == 0) {
        system ("cls");
        
        print(field);
        
        printf("Command Player %d (x, y) : ", i%2 + 1);
        scanf("%d %d", &player[0], &player[1]);

        if (i%2+1 == 1) {
            field[player[0]][player[1]] = 1;
        } else {
            field[player[0]][player[1]] = 2;
        }

        win = winner(field);

        i++;
    }

    return 0;
}
