/////////////////////////////////////////////////////////
///        [Alpro2] 1st MEET PRAK - MATRIX           ////
///              MODUL PRAKTIKUM 2nd                 ////
///                                                  ////
///            code by: naufalfazanadi               ////
/////////////////////////////////////////////////////////
#include <stdio.h>
#include <string.h>

int main () {
    int m, n;

    scanf("%d %d", &m, &n);

    int i, j, k;
    int matriks[m][n];

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &matriks[i][j]);
        }
    }

    int sum_cmd;
    char command[8];
    int search, x, y;
    int temp;
    int bol;

    scanf("%d", &sum_cmd);


    for (i = 0; i < sum_cmd; i++) {
        bol = 0;
        
        scanf("%s %d %d %d", &command, &search, &x, &y);

        x--; y--;

        if (strcmp(command, "Replace") == 0) {

            matriks[x][y] = search;

        } else if (strcmp(command, "Swap") == 0) {

            j = 0; 
            while (j < m && bol == 0) {
                k = 0;
                while (k < n && bol == 0) {
                    if (matriks[j][k] == search) {
                        temp = search;
                        matriks[j][k] = matriks[x][y];
                        matriks[x][y] = temp;

                        bol = 1;
                    } else {
                        k++;
                    }
                }
                j++;
            }

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
