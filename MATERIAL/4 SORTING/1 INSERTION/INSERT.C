#include <stdio.h>

void insertion_sort_inc (int n, int arr[]) {
    int i, j;
    int data;

    for (i = 1; i < n; i++) {
        data = arr[i];
        j = i - 1;

        while ((data < arr[j]) && (j >= 0)) {
            arr[j+1] = arr[j];
            j--;
        }

        arr[j+1] = data;
    }

    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insertion_sort_dec (int n, int arr[]) {
    int i, j;
    int data;

    for (i = 1; i < n; i++) {
        data = arr[i];
        j = i - 1;

        while ((data > arr[j]) && (j >= 0)) {
            arr[j+1] = arr[j];
            j--;
        }

        arr[j+1] = data;
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

    insertion_sort_inc(n, x);
    insertion_sort_dec(n, x);

    return 0;
}
