#include "head.h"

int main () {
    int field[3][3] = {0};

    int i, j, k;
    
    char control[3], tandas;
    int a, b;
    
    pemain play[2];
    strcpy(play[0].controller, "P1");
    strcpy(play[1].controller, "P2");
    play[0].tanda = '-';
    play[1].tanda = '-';

    for (i = 0; i < 6; i++) {
        scanf("%s %c %d %d", &control, &tandas, &a, &b);

        if (strcmp(control, play[0].controller) == 0) {
            play[0].tanda = tandas;
        } else if (strcmp(control, play[1].controller) == 0) {
            play[1].tanda = tandas;
        }

        if (tandas == play[0].tanda) {
            field[a][b] = 1;
        } else if (tandas == play[1].tanda) {
            field[a][b] = 2;
        }
        
    }

    int stats = win_lose (field);

    switch (stats) {
        case 0 : printf("tidak ada\n"); break;
        default : printf("%s\n", play[stats-1].controller); break;
    }

    return 0;
}
