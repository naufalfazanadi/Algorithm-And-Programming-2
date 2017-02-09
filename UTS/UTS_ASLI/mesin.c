#include "head.h"

// INSERTION
void insertion_sort (int n, pack arr[]) { // dont forget about change data type to pack
    int i, j;
    pack data;

    for (i = 1; i < n; i++) {
        data = arr[i];
        j = i - 1;

        // penggeseran
        while ((data.komisi > arr[j].komisi) && (j >= 0)) {
            arr[j+1] = arr[j]; // switching
            j--;
        }

        arr[j+1] = data; // switching
    }
}

// SELECTION
void selection_sort (int n, pack arr[]) { // dont forget about change data type to pack
    int i, j;
    int min;
    pack temp;

    for (i = 0; i < n-1; i++) {
        min = i; // indeks yg dalamnya angka minimal
        for (j = i+1; j < n; j++) {
            if(arr[min].komisi < arr[j].komisi) {
                min = j; // ganti kalau ada indeks yg lebih kecil
            }
        }
        //menukar posisi elemen
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

// BUBBLE
void bubble_sort (int n,  pack arr[]) { // dont forget about change data type to pack
    int i;
    pack temp;
    int flip;
    
    do{
        flip = 0;
        for(i = 0; i < (n-1); i++){ // loop sebanyak jumlah array

            if(arr[i].komisi < arr[i+1].komisi){
                // switching
                temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
                flip = 1;
            }

        }
    } while(flip == 1); // selama ada data yg berubah
}

// QUICK
void quick_sort (int l, int r, pack arr[]) { // dont forget about change data type to pack
    int i, j;
    pack temp;

    i = l; j = r;
    // PIVOT TENGAH
    pack pivot = arr[ (l+r) / 2];

    do {

        while((arr[i].komisi > pivot.komisi) && (i<=j)){
            /* mencegah i berjalan terlalu jauh melewati batas j */
            i++;
        }
        while((arr[j].komisi < pivot.komisi) && (i<=j)){
            /* mencegah i berjalan terlalu jauh melewati batas i */
            j--;
        }

        if (i < j) {
            // switching
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;

            i++; j--;
        }
    } while (i < j);

    //  ---------- REKURSIF ---------
    if ((l < j) && (j < r)) {
        quick_sort(l, j, arr);
    }

    if ((i < r) && (i > l)) {
        quick_sort(i, r, arr);
    }
}

// MERGING DATA
void merge_terurut (int m, int n, pack arr1[], pack arr2[], pack result[]) { // dont forget about change data type to pack
    int i;

    int count1 = 0;
    int count2 = 0;
    int count3 = 0;

    // untuk membandingkan
    while((count1 < m) && (count2 < n)){
        if(arr1[count1].komisi > arr2[count2].komisi){
            result[count3] = arr1[count1]; // pemindahan

            count1++;
            count3++;
        }else if(arr2[count2].komisi > arr1[count1].komisi){
            result[count3] = arr2[count2]; // pemindahan

            count2++;
            count3++;
        }else{
            result[count3] = arr1[count1]; // pemindahan
            count1++;
            count3++;

            result[count3] = arr2[count2]; // pemindahan
            count2++;
            count3++;
        }
    }

    // UNTUK SISA
    if(count1 < m){
        for(i = count1; i < m; i++){
            result[count3] = arr1[i]; // pemindahan
            count3++;
        }
    }
    if(count2 < n){
        for(i = count2; i < n; i++){
            result[count3] = arr2[i]; // pemindahan
            count3++;
        }
    }
}
