#include <stdio.h>

int pangkat (int x, int n) {
    if (n == 0) {
        return 1;
    } else {
        return x * pangkat(x, n-1); 
    }
}

int main () {
    int x, n;

    printf("Masukan bilangan yang akan dipangkatkan : ");
    scanf("%d", &x);
    printf("Mau berapa pangkat : ");
    scanf("%d", &n);

    printf("%d\n", pangkat(x, n));

    return 0;
}
