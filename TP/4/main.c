#include "head.h"

int main () {
    // =============================== INPUT ==================================
    int n;
    char ya_or_no[10];

    scanf("%d", &n); // jumlah data
    scanf("%s", &ya_or_no); // tampilkan error?

    // VAR TEMP INPUT
    data input;
    int check;
    
    // VAR COUNTER
    penghitung count; 
    count.valid = 0;
    count.tidak_valid = 0;

    // ARRAY DATA YG VALID DAN ERROR
    data roster[n], error[n];

    // inputing and processing
    int i;
    for (i = 0; i < n; i++) {
        scanf("%s %s", &input.nim, &input.nama); // input nim dan nama

        // pengecekan nim apakah valid atau tidak 
        check = cek_nim(input.nim);

        if (check == 0) { // jika valid maka masukan ke roster

            roster[count.valid] = input;            
            count.valid++; // untuk jumlah data yg valid
         
        } else { // jika tidak masukan ke error
        
            error[count.tidak_valid] = input;
            count.tidak_valid++; // untuk jumlah data yg tidak valid

        }
    }

    char nim_or_name[8];
    int nim_or_name_stats = 0; // var boolean kalau bukan nim dan nama

    scanf("%s", &nim_or_name); // input mau nim atau nama yg disortir

    // ============================== SORTING ===========================
    if (strcmp(nim_or_name, "nim") == 0) {
        // SORTING NIM (BUBBLE)
        sort_nim(count.valid, roster);
    
    } else if (strcmp(nim_or_name, "nama") == 0) {
        // SORTING NAMA (QUICK)
        sort_nama(0, count.valid-1, roster);
    
    } else {
        nim_or_name_stats = 1;
    }

    // =========================== OUTPUT =================================

    output(nim_or_name_stats, ya_or_no, count, roster, error);

    return 0;
}
/*
Buatlah mesin pengurut daftar mahasiswa dengan data berupa NIM dan mahasiswa dengan ketentuan sebagai berikut :

Input

N (banyaknya data yang akan digunakan)
ya/tidak 
Menampilkan pesan error atau tidak, jika input bukan keduanya, pesan error tidak ditampilkan.
NIM & NAMA sebanyak N
NIM harus semuanya berupa angka dan memiliki 7 karakter.
Jika NIM tidak sesuai, tambahkan ke dalam daftar error.
nim/nama 
Data yang akan diurutkan, nim dengan bubble, nama dengan quick.
Jika bukan keduanya, hentikan program dengan pesan berupa "---Data tidak dapat diproses---".
Output

---Hasil Pengurutan---
[Data yang sudah diurutkan] (Jika ada) / "Tidak ada data valid." (Jika tidak ada data valid)
---Daftar Error--- (Jika ada error & ditampilkan)
[Pesan data yang bermasalah sesuai format] (Jika ada error & ditampilkan)
Contoh Masukan

7
terserah
124j421 EzBugatti
2000001 LienKing
0800322 Artizi
1520036 Yunifers
322322322 Ice3
4429222 Puppan
7732221 EternalEnpi
nim

Contoh Keluaran

---Hasil Pengurutan---
0800322 Artizi
1520036 Yunifers
2000001 LienKing
4429222 Puppan
7732221 EternalEnpi
Contoh Masukan 2

3
ya
124j421 EzBugatti
322322322 Ice3
44292223 Puppan
nama

Contoh Keluaran 2

---Hasil Pengurutan---
Tidak ada data valid.
---Daftar Error---
124j421 - EzBugatti tidak valid.
322322322 - Ice3 tidak valid.
44292223 - Puppan tidak valid.
       
Contoh Masukan 3

7
ya
124j421 SadLife
0241281 Cincong
2332111 Cadas
12894121 Artizi
4429222 Puppan
7732221 EternalEnpi
9321123 Yunifers
mmr

Contoh Keluaran 3

---Data tidak dapat diproses---

*/
