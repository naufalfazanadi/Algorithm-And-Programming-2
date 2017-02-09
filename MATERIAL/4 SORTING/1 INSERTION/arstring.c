#include <stdio.h>
#include <string.h>

void insertion_sort_inc (int n, char arr[n][64]) {
    int i, j;
    char data[64];

    for (i = 1; i < n; i++) {
        strcpy(data, arr[i]);
        j = i - 1;

        while ((strcmp(data, arr[j]) < 0) && (j >= 0)) {
            strcpy(arr[j+1], arr[j]);
            j--;
        }

        strcpy(arr[j+1], data);
    }

    for (i = 0; i < n; i++) {
        printf("%s\n", arr[i]);
    }
}

int main () {
    int n;
    scanf("%d", &n);

    int i;
    char str[n][64];

    for (i = 0; i < n; i++) {
        scanf("%s", &str[i]);
    }

    printf("\n");
    
    insertion_sort_inc(n, str);

    return 0;
}
