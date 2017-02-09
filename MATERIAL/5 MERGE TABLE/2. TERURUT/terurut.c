#include <stdio.h>

void input (int n, int arr[n]) {
    int i;
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
}

void quick_sort (int l, int r, int arr[]) {
    int i, j;
    int temp;

    i = l; j = r;
    int pivot = arr[ (l+r) / 2];

    do {

        while((arr[i] < pivot) && (i<=j)){
            /* mencegah i berjalan terlalu jauh melewati batas j */
            i++;
        }
        while((arr[j] > pivot) && (i<=j)){
            /* mencegah i berjalan terlalu jauh melewati batas i */
            j--;
        }

        if (i < j) {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;

            i++; j--;
        }
    } while (i < j);

    if ((l < j) && (j < r)) {
        quick_sort(l, j, arr);
    }

    if ((i < r) && (i > l)) {
        quick_sort(i, r, arr);
    }
}

void merge_terurut (int m, int n, int arr1[], int arr2[], int result[]) {
    int i;

    int count1 = 0;
    int count2 = 0;
    int count3 = 0;

    while((count1 < m) && (count2 < n)){
        if(arr1[count1] < arr2[count2]){
            result[count3] = arr1[count1];

            count1++;
            count3++;
        }else if(arr2[count2] < arr1[count1]){
            result[count3] = arr2[count2];

            count2++;
            count3++;
        }else{
            result[count3] = arr1[count1];
            count1++;
            count3++;

            result[count3] = arr2[count2];
            count2++;
            count3++;
        }
    }

    // UNTUK SISA
    if(count1 < m){
        for(i = count1; i < m; i++){
            result[count3] = arr1[i];
            count3++;
        }
    }
    if(count2 < n){
        for(i = count2; i < n; i++){
            result[count3] = arr2[i];
            count3++;
        }
    }
}

int main () {
    // ------- INPUT -------
    int m, n;

    scanf("%d", &m);

    int arr1[m];
    input(m, arr1);

    scanf("%d", &n);

    int arr2[n];
    input(n, arr2);

    // ------- SORT --------- 

    quick_sort(0, m-1, arr1);
    quick_sort(0, n-1, arr2);

    // ------- MERGE --------
    int arr3[m+n];

    merge_terurut(m, n, arr1, arr2, arr3);
    
    // OUTPUT 
    int i;
    for (i = 0; i < m+n; i++) {
        printf("%d\n", arr3[i]);
    }

    return 0;
}
