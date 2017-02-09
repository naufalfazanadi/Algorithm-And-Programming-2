#include <stdio.h>
#include <string.h>

void insertion_sort_inc (char arr[64]) {
    int i, j;
    char data;

    for (i = 1; i < strlen(arr); i++) {
        data = arr[i];
        j = i - 1;

        while ((data < arr[j]) && (j >= 0)) {
            arr[j+1] = arr[j];
            j--;
        }

        arr[j+1] = data;
    }

    printf("%s", arr);
    printf("\n");
}

int main () {
    char str[64];

    scanf("%s", &str);

    insertion_sort_inc(str);

    return 0;
}
