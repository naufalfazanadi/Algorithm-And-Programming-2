#include <stdio.h>

void input (int n, int arr[n]) {
    int i;
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
}

int merge (int count, int n, int gabung[], int arr[n]) {
    int i;
    for (i = 0; i < n; i++) {
        gabung[count] = arr[i];
        count++;
    }
    return count;
}

int main () {
    int m, n;

    scanf("%d", &m);

    int arr1[m];
    input(m, arr1);

    scanf("%d", &n);

    int arr2[n];
    input(n, arr2);

    int arr3[m+n];
    int count = 0;
    
    count = merge(count, m, arr3, arr1);
    count = merge(count, n, arr3, arr2);

    printf("======================= \n");
    int i;
    for (i = 0; i < m+n; i++) {
        printf("%d\n", arr3[i]);
    }

    return 0;
}
