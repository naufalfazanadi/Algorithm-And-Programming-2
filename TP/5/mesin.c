#include "head.h"

// KONVERSI BINER
int convert_to_dec (char biner[]) {
    int i;
    
    int equal = 512; // untuk biner nya

    int sum = 0; // hasil nya (penjumlahan tiap index nya)
    

    for (i = 0 ; i < strlen(biner) ; i++) {
        if (biner[i] == '1') { // jika angka 1 maka tambahkan ke sum
            sum += equal;
        }
        equal /= 2; // iterasi si penjumlah nya
    }

    return sum;
}

// QUICK
void quick_sort (int l, int r, pack arr[]) { // dont forget about change data type to pack
    int i, j;
    pack temp;

    i = l; j = r;
    // PIVOT TENGAH
    pack pivot = arr[ (l+r) / 2];

    do {

        while((arr[i].decimal < pivot.decimal) && (i<=j)){
            /* mencegah i berjalan terlalu jauh melewati batas j */
            i++;
        }
        while((arr[j].decimal > pivot.decimal) && (i<=j)){
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

// FUNGSI untuk ngecek 3 tabel untuk angka yang sama
diff cek_data_3negara (int m, int n, int o, pack nation1[], pack nation2[], pack nation3[]) {
    int i, j, k;

    int bol; // untuk mencegah jika 12, 12, 12 lalu loop selanjut nya 12, 12, 12 juga
             // maka langsung dibreak menjadi next indeks di array ke satu nya

    diff x; // bungkusan untuk di return berisi counter nya sama isi nya
    x.count = 0;

    i = 0;
    while (i < m) {
        bol = FALSE; // set to FALSE
        j = 0;
        while (j < n && bol == FALSE) {
            k = 0;
            while (k < o && bol == FALSE) {
                if (nation1[i].decimal == nation2[j].decimal &&
                    nation1[i].decimal == nation3[k].decimal &&
                    nation2[j].decimal == nation3[k].decimal) { // kondisi saat sama semua
                    
                    x.beda[x.count] = nation1[i].decimal; // pemindahan
                    x.count++; // penghitungnya
                    
                    bol = TRUE; // saat ketemu set to TRUE
                }
                k++;
            }
            j++;
        }
        i++;
    }

    return x;
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
