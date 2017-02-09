#include <stdio.h>
#include <string.h>

// fungsi penghitung urutan
int count_fibo(int x, int y, int n, int urut);
// procedure neprint matriks terakhir
void printing(int cari, int urutan, int n);

/* Saya Muhammad Naufal Fazanadi tidak melakukan kecurangan seperti yang telah dispesifikasikan
pada mata kuliah Algoritma dan Pemograman 2 dalam mengerjakan Tugas Praktikum 2,
jika saya melakukan kecurangan maka Allah/Tuhan adalah saksi saya, 
dan saya bersedia menerima hukumanNya. Aamiin. */

/*
Di hari pertama kuliah, Piyu dan Moni kebingungan karena Dosen yang mengajar Mata Kuliah Matematika mereka berhalangan hadir.Akhirnya Piyu dan Moni memutuskan untuk bermain tebak-tebakan angka fibonacci.

Permainannya cukup sederhana, Piyu akan memberikan sebuah angka dari deret fibonacci dan tugas Moni adalah menyebutkan di urutan berapakah angka tersebut berada, lalu membandingkannya dengan beberapa angka parameter yang diberikan oleh Moni sebelumnya, jika urutan angka fibonacci lebih besar atau sama dengan angka parameter, maka tampilkanlah output O, jika tidak tampilkanlah X. Karena mereka merupakan siswa yang cukup rajin mereka ingin mengaplikasikan bentuk fibonacci tersebut kedalam bentuk matriks.

Bantulah Piyu dan tuliskanlah kode program untuk membuat permainan tersebut lebih seru.

Format Masukan:
X Y, x baris dan y kolom matriks
M1, matriks pertama berisi angka pertama pada deret fibonacci
M2, matriks kedua berisi angka kedua deret fibonacci
M3, matriks ketiga berisi angka-angka yang terdapat pada deret fibonacci
M4, parameter output

Format Keluaran:
M5, berupa O atau X

Penjelasan:

bila x dan y = 2 x 2
matriks1 (setiap elemen akan menjadi basis)
1 1
1 1

matriks2 (setiap elemen akan menjadi basis)
2 2
2 2

matriks3 (angka dalam deret fibonacci)
3 5
8 13

matriks4 (parameter)
5 5
10 10

misal

matriks1[0][0] = 1
matriks2[0][0] = 2
matriks3[0][0] = 3
matriks4[0][0] = 5

maka deret nya akan seperti ini
1 2 3 5

karena matriks3[0][0] adalah 3, angka 3 pada deret tsb terletak pada posisi ke-3
dan 3 < matriks 4[0][0]
maka matriks hasil[0][0] = O
Contoh Masukan

2 2
1 1
1 1
2 2
2 2
3 5
8 13
5 5
10 10


Contoh Keluaran

X X
X X

Contoh Masukan 2

2 2
1 1
1 1
2 2
2 2
3 5
8 13
5 5
5 5


Contoh Keluaran 2

X X
O O
 */
