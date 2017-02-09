/////////////////////////////////////////////////////////
///        [Alpro2] 1st MEET PRAK - MATRIX           ////
///              MODUL PRAKTIKUM 1st                 ////
///                                                  ////
///            code by: naufalfazanadi               ////
/////////////////////////////////////////////////////////
#include <stdio.h>
#include <string.h>

// int tukarb (int m, int n, int matriks[m][n], int x, int y) {

// }

// int tukark (int m, int n, int matriks[m][n], int x, int y) {

// }

int main () {
    int m, n;

    scanf("%d %d", &m, &n);

    int i, j;
    int matriks[m][n];

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &matriks[i][j]);
        }
    }

    int sum_cmd;
    char command[7];
    int x,y;
    int temp;

    scanf("%d", &sum_cmd);

    for (i = 0; i < sum_cmd; i++) {
        scanf("%s %d %d", &command, &x, &y);

        x--; y--;

        if (strcmp(command, "TukarB") == 0) {
            for (j = 0; j < n; j++) {
                temp = matriks[y][j];
                matriks[y][j] = matriks[x][j];
                matriks[x][j] = temp;
            }
            // matriks[x] = tukarb(m, n, matriks, x, y);
            // matriks[y] = tukarb(m, n, matriks, x, y);
        } else if (strcmp(command, "TukarK") == 0) {
            for (j = 0; j < m; j++) {
                temp = matriks[j][y];
                matriks[j][y] = matriks[j][x];
                matriks[j][x] = temp;
            }

            // matriks[][x] = tukark(m, n, matriks, x, y);
            // matriks[][y] = tukark(m, n, matriks, x, y);
        }
    }

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", matriks[i][j]);
        }
        printf("\n");
    }

    return 0;
}
