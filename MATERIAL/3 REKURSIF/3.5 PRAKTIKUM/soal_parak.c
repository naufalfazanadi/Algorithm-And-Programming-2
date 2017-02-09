#include <stdio.h>

int mutiply (int mutiple, int x) {
    int count;

    if (x < mutiple) {
        return 0;
    } else if (){
        count = (x / mutiple)*mutiple;

        return count + mutiply(mutiple, count - mutiple);
    }
}

int main () {
    int mutiple;
    int baris, kolom;

    scanf("%d", &mutiple);
    scanf("%d %d", &baris, &kolom);

    int field[baris][kolom];

    int i, j;

    for (i = 0; i < baris; i++) {
        for (j = 0; j < kolom; j++) {
            scanf("%d", &field[i][j]);
            field[i][j] = mutiply(mutiple, field[i][j]);
        }
    }

    for (i = 0; i < baris; i++) {
        for (j = 0; j < kolom; j++) {
            printf("%d ", field[i][j]);
        }
        printf("\n");
    }

    return 0;
}
