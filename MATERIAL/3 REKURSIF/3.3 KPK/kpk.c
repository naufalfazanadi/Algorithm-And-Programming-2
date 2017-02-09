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

int kpk (int x, int y) {
    return x * y / fpb(x, y);
}

int main () {
    int x, y;

    printf("cari kpk dari (x, y) : ");
    scanf("%d %d", &x, &y);

    printf("%d\n", kpk(x, y));

    return 0;
}
