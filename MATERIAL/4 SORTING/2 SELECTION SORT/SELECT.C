#include <stdio.h>

void selection_sort (int n, int arr[]) {
    int i, j;
    int min;
    int temp;

    for (i = 0; i < n-1; i++) {
        min = i; // indeks yg dalamnya angka minimal
        for (j = i+1; j < n; j++) {
            if(arr[min] > arr[j]) {
                min = j; // ganti kalau ada indeks yg lebih kecil
            }
        }
        //menukar posisi elemen
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }

    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main () {
    int n;

    scanf("%d", &n);

    int x[n];

    int i;
    for (i = 0; i < n; i++) {
        scanf("%d", &x[i]);
    }

    selection_sort(n, x);

    return 0;
}

// 34 67 23 28 98 15 89 67 28 18
