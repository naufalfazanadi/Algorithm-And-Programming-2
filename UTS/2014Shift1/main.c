#include "head.h"

int main () {
    // Metoda sorting
    char method[16];

    scanf("%s", &method);

    // ------------- INPUT STRING -----------
    // ------------ 1 -------------
    int m, n, o;

    scanf("%d", &m);

    pack arr1[m];

    int i;
    for (i = 0; i < m; i++) {
        scanf("%s", &arr1[i].str);
        arr1[i].konsonan = cek_konso(arr1[i].str);
    }

    // ------------ 2 -------------
    scanf("%d", &n);

    pack arr2[n];

    for (i = 0; i < n; i++) {
        scanf("%s", &arr2[i].str);
        arr2[i].konsonan = cek_konso(arr2[i].str);
    }

    // ------------ 3 -------------
    scanf("%d", &o);

    pack arr3[o];

    for (i = 0; i < o; i++) {
        scanf("%s", &arr3[i].str);
        arr3[i].konsonan = cek_konso(arr3[i].str);
    }

    // ----- END OF INPUT -----

    // -------- SORTING -------
    if (strcmp(method, "insertionsort") == 0) {
        insertion_sort(m, arr1);
        insertion_sort(n, arr2);
        insertion_sort(o, arr3);
    } else if (strcmp(method, "selectionsort") == 0) {
        selection_sort(m, arr1);
        selection_sort(n, arr2);
        selection_sort(o, arr3);
    } else if (strcmp(method, "bubblesort") == 0) {
        bubble_sort(m, arr1);
        bubble_sort(n, arr2);
        bubble_sort(o, arr3);
    } else if (strcmp(method, "quicksort") == 0) {
        quick_sort(0, m-1, arr1);
        quick_sort(0, n-1, arr2);
        quick_sort(0, o-1, arr3);
    }

    // ---------- MERGING ----------
    pack result1[m+n];
    pack result2[m+n+o];

    merge_terurut(m, n, arr1, arr2, result1);
    merge_terurut(m+n, o, result1, arr3, result2);

    for (i = 0; i < m+n+o; i++) {
        printf("%s\n", result2[i].str);
    }
    
    return 0;
}

/*
quicksort
3
cccaa
cc
ccccc
3
vvvaaabbb
vvvb
r
2
lalalalalalala
yeyeyeyyeyeyeyee
 */
