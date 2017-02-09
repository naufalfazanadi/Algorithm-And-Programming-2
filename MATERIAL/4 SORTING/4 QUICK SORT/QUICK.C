#include <stdio.h>

int tabInt[10] = {34, 67, 23, 28, 98, 15, 89, 67, 28, 18};

void quick_sort (int l, int r) {
    int i, j;
    int temp;

    i = l; j = r;

    do {

        while((tabInt[i] < tabInt[r]) && (i<=j)){
            /* mencegah i berjalan terlalu jauh melewati batas j */
            i++;
        }
        while((tabInt[j] > tabInt[l]) && (i<=j)){
            /* mencegah i berjalan terlalu jauh melewati batas i */
            j--;
        }

        if (i < j) {
            temp = tabInt[i];
            tabInt[i] = tabInt[j];
            tabInt[j] = temp;

            i++; j--;
        }
    } while (i < j);

    if ((l < j) && (j < r)) {
        quick_sort(l, j);
    }

    if ((i < r) && (i > l)) {
        quick_sort(i, r);
    }
}

void quick_sort_centre_pivot (int l, int r) {
    int i, j;
    int temp;

    i = l; j = r;
    int pivot = tabInt[ (l+r) / 2];

    do {

        while((tabInt[i] < pivot) && (i<=j)){
            /* mencegah i berjalan terlalu jauh melewati batas j */
            i++;
        }
        while((tabInt[j] > pivot) && (i<=j)){
            /* mencegah i berjalan terlalu jauh melewati batas i */
            j--;
        }

        if (i < j) {
            temp = tabInt[i];
            tabInt[i] = tabInt[j];
            tabInt[j] = temp;

            i++; j--;
        }
    } while (i < j);

    if ((l < j) && (j < r)) {
        quick_sort_centre_pivot(l, j);
    }

    if ((i < r) && (i > l)) {
        quick_sort_centre_pivot(i, r);
    }
}


int main () {

    quick_sort_centre_pivot(0, 9);
    int i;
    for (i = 0; i < 10; i++) {
        printf("%d ", tabInt[i]);
    }

    return 0;
}
