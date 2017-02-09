#include "head.h"

// CONVERSION
int convert_to_dec (char biner[]) {
    int decimal[8]; // inisialisasi nilai biner di index nya
        decimal[0] = 128;
        decimal[1] = 64;
        decimal[2] = 32;
        decimal[3] = 16;
        decimal[4] = 8;
        decimal[5] = 4;
        decimal[6] = 2;
        decimal[7] = 1;

    int sum = 0; // hasil nya (penjumlahan tiap index nya)
    int count = 0; // untuk berjalan di biner nya
    
    int i;

    for (i = 0 ; i < strlen(biner) ; i++) {
        if (biner[i] == '1') { // jika angka 1 maka tambahkan ke sum
            sum += decimal[count];
        }
        count++; // iterasi index biner
    }

    return sum;
}

// INSERTION
void insertion_sort (int n, pack arr[]) { // dont forget about change data type to pack
    int i, j;
    pack data;

    for (i = 1; i < n; i++) {
        data = arr[i];
        j = i - 1;

        // penggeseran
        while ((data.decimal < arr[j].decimal) && (j >= 0)) {
            arr[j+1] = arr[j]; // switching
            j--;
        }

        arr[j+1] = data; // switching
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
        if(arr1[count1].decimal < arr2[count2].decimal){
            result[count3] = arr1[count1]; // pemindahan

            count1++;
            count3++;
        }else if(arr2[count2].decimal < arr1[count1].decimal){
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

// SEARCHING
cari search(int n, int x_search, pack hasil[]) {
    cari x;
    x.bol = 0; // set to false    

    int i = 0;
    while (i < n && x.bol == 0) {
        if (hasil[i].decimal == x_search) { // jika ketemu maka
            x.bol = 1; // TRUE
            x.index = i+1; // set index
        }
        i++; // iterasi
    }

    return x;
}
