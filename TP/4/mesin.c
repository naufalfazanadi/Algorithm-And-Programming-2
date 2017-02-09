#include "head.h"

// fungsi untuk mengecek kevalidan nim
int cek_nim (char nim[16]) {
    int i = 0;
    int status = 0;

    if (strlen(nim) > 7) {
        status = 1;
    }

    while ((i < strlen(nim)) && (status == 0)) {
        if (nim[i] < '0' || nim[i] > '9') {
            status = 1;
        }
        i++;
    }

    return status;
}

// prosedur bubble sort berdasarkan nim
void sort_nim (int n,  data roster[]) {
    int i;
    data temp;
    int flip;
    
    do{
        flip = 0;
        for(i = 0; i < (n-1); i++){

            if(strcmp(roster[i].nim, roster[i+1].nim) > 0){
                temp = roster[i];
                roster[i] = roster[i+1];
                roster[i+1] = temp;
                flip = 1;
            }

        }
    } while(flip == 1);
}

// prosedur quick sort berdasarkan nama
void sort_nama (int l, int r, data roster[]) {
    int i, j;
    data temp;
    data pivot = roster[ (l+r) / 2];

    i = l; j = r;

    do {

        while((strcmp(roster[i].nama, pivot.nama) < 0) && (i<=j)){
            /* mencegah i berjalan terlalu jauh melewati batas j */
            i++;
        }
        while((strcmp(roster[j].nama, pivot.nama) > 0) && (i<=j)){
            /* mencegah i berjalan terlalu jauh melewati batas i */
            j--;
        }

        if (i < j) {
            temp = roster[i];
            roster[i] = roster[j];
            roster[j] = temp;

            i++; j--;
        }
    } while (i < j);

    if ((l < j) && (j < r)) {
        sort_nama(l, j, roster);
    }

    if ((i < r) && (i > l)) {
        sort_nama(i, r, roster);
    }
}

// PROSEDUR OUTPUT
void output (int nim_or_name_stats, char ya_or_no[], penghitung count, data roster[], data error[]) {
    int i;

    if (nim_or_name_stats == 1) { // jika bukan nim dan nama
    
        printf("---Data tidak dapat diproses---\n");
    
    } else {
        printf("---Hasil Pengurutan---\n");

        if (count.valid == 0) { // jika data nya tidak ada atau jumlah nya 0
            printf("Tidak ada data valid.\n");
        } else {
            for (i = 0; i < count.valid; i++) {
                printf("%s %s\n", roster[i].nim, roster[i].nama);
            }
        }
        
        // jika ya maka tampilkan yg error nya selama si datanya itu ada atau != 0
        if (strcmp(ya_or_no, "ya") == 0 && count.tidak_valid != 0) {
            printf("---Daftar Error---\n");
            
            for (i = 0; i < count.tidak_valid; i++) {
                printf("%s - %s tidak valid.\n", error[i].nim, error[i].nama);
            }
        }
    }
}
