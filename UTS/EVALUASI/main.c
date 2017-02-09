#include "head.h"

int main () {
    // --------------------- INPUT ---------------------
    pack input; // untuk input saja
    pack few[32]; // untuk yg <= 100
    pack lot[32]; // untuk yg > 100

    penghitung count; // counter
    count.few = 0;
    count.lot = 0;

    do {
        scanf("%s", &input.biner); // input biner

        if (strcmp(input.biner, "Selesai") != 0) {
            // konversi ke desimal
            input.decimal = convert_to_dec(input.biner);

            if (input.decimal > 100) { // perkondisian yg > 100 dan <= 100
                few[count.few] = input;
                count.few++;
            } else {
                lot[count.lot] = input;
                count.lot++;
            }
        }

    } while (strcmp(input.biner, "Selesai") != 0);

    // angka yang dicari
    int x_search;
    scanf("%d", &x_search);

    // --------------------- SORTING ---------------------
    insertion_sort(count.few, few); // sort table <= 100
    insertion_sort(count.lot, lot); // sort table > 100

    // --------------------- MERGE TABLE ---------------------
    pack hasil[count.few + count.lot];
    merge_terurut(count.few, count.lot, few, lot, hasil); // merge semua nya

    // --------------------- SEARCH ---------------------
    
    // isi dari x :
    //      boolean nya (1 / 0)
    //      index nya
    cari x = search(count.few + count.lot, x_search, hasil); // search angka

    // --------------------- OUTPUT ---------------------
    int i;
    // perkondisian jika ketemu atau tidak
    if (x.bol == 1) {
        // output tabel biner hasil
        for (i = 0; i < count.few + count.lot; i++) {
            printf("%s\n", hasil[i].biner);
        }
        printf("index %d\n", x.index);
    
    } else { 
        printf("data not found\n");
    }

    return 0;
}

/*
Buatlah program untuk mencari biner dari nilai desimal biner tersebut. 
Diberikan input biner dengan format 8 bit hingga terdapat input dengan kata Selesai.
Kemudian pisahkan input tersebut dalam 2 buah tabel yang berbeda, tabel dipisahkan berdasarkan nilai desimal < 100 dan nilai desimal > 100.
URUTKAN dan GABUNGKAN 2 tabel tersebut berdasarkan nilai desimalnya, kemudian TEMUKAN letak Biner yang dicari pada Tabel tersebut.
Tampilkanlah hasil penggabungan tabel dan index desimal tabel. Jika tidak ditemukan tampilkan data not found. 

Format Masukan :
Biner 8 bit, hingga kata Selesai
Angka desimal yang dicari

Format Keluaran :
Tabel Akhir (Terurut)
index tabel(jika ditemukan) / data not found

Catatan : 
Gunakan Binary Search,Insertion Sort & Merge Table Terurut 
Urutkan Secara Ascending
Contoh Masukan

11111111
00000011
11111000
01100011
01100100
01111000
Selesai
3


Contoh Keluaran

00000011
01100011
01100100
01111000
11111000
11111111
index 1

Contoh Masukan 2

01011000
11011110
00000001
10111111
Selesai
254


Contoh Keluaran 2

data not found

 */
