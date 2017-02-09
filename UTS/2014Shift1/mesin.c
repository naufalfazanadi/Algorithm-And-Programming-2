#include "head.h"

int cek_konso (char str[]) {
    int i;
    int count = 0;

    for (i = 0; i < strlen(str); i++) {
        if (str[i] != 'a' && str[i] != 'i' &&
            str[i] != 'u' && str[i] != 'e' &&
            str[i] != 'o' && str[i] != 'A' &&
            str[i] != 'I' && str[i] != 'U' &&
            str[i] != 'E' && str[i] != 'O') {
            count++;
        }
    }

    return count;
}

void insertion_sort (int n, pack arr[]) {
    int i, j;
    pack data;

    for (i = 1; i < n; i++) {
        data = arr[i];
        j = i - 1;

        while ((data.konsonan > arr[j].konsonan) && (j >= 0)) {
            arr[j+1] = arr[j];
            j--;
        }

        arr[j+1] = data;
    }
}

void selection_sort (int n, pack arr[]) {
    int i, j;
    int min;
    pack temp;

    for (i = 0; i < n-1; i++) {
        min = i; // indeks yg dalamnya angka minimal
        for (j = i+1; j < n; j++) {
            if(arr[min].konsonan < arr[j].konsonan) {
                min = j; // ganti kalau ada indeks yg lebih kecil
            }
        }
        //menukar posisi elemen
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

void bubble_sort (int n,  pack arr[]) {
    int i;
    pack temp;
    int flip;
    
    do{
        flip = 0;
        for(i = 0; i < (n-1); i++){

            if(arr[i].konsonan < arr[i+1].konsonan){
                temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
                flip = 1;
            }

        }
    } while(flip == 1);
}

void quick_sort (int l, int r, pack arr[]) {
    int i, j;
    pack temp;

    i = l; j = r;
    pack pivot = arr[ (l+r) / 2];

    do {

        while((arr[i].konsonan > pivot.konsonan) && (i<=j)){
            /* mencegah i berjalan terlalu jauh melewati batas j */
            i++;
        }
        while((arr[j].konsonan < pivot.konsonan) && (i<=j)){
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

void merge_terurut (int m, int n, pack arr1[], pack arr2[], pack result[]) {
    int i;

    int count1 = 0;
    int count2 = 0;
    int count3 = 0;

    while((count1 < m) && (count2 < n)){
        if(arr1[count1].konsonan > arr2[count2].konsonan){
            result[count3] = arr1[count1];

            count1++;
            count3++;
        }else if(arr2[count2].konsonan > arr1[count1].konsonan){
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
