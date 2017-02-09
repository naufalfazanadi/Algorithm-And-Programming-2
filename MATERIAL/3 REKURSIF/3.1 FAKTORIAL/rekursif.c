/////////////////////////////////////////////////////////
///         [Alpro2] 3rd MEET - RECURSIVE            ////
///          Recursive Procedure Function            ////
///                                                  ////
///            code by: naufalfazanadi               ////
/////////////////////////////////////////////////////////
#include <stdio.h>

int recursive(int n) {
    int count;
    if (n == 1) {
        count = 1;
    } else {
        count = n * recursive(n-1);
    }
    return count;
}

int main () {
    int n;
    printf("Masukan angka yang ingin kalian faktorial kan : ");
    scanf("%d", &n);

    printf("%d\n", recursive(n));

    return 0;
}
