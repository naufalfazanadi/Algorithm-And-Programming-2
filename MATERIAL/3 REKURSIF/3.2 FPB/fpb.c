#include <stdio.h>

int fpb (int x, int y) {
    int temp;
    if (y == 0) {
        return x;
    } else {
        temp = x % y;
        return fpb (y, temp);
    }
}

int main () {
    int x, y;

    printf("cari fpb dari (x, y) : ");
    scanf("%d %d", &x, &y);
    
    printf("%d\n", fpb(x,y));

    return 0;
}
