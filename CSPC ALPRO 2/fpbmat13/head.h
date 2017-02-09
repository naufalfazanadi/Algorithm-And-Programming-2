#include <stdio.h>
#include <string.h>

int fpb (int x, int y);
void process (int kolom[], int baris[], int n, int m);

/*
Diberikan beberapa masukan yang merupakan header baris dan header kolom dari sebuah matriks perkalian FPB, isi dari matriks adalah hasil nilai persekutuan terbesar dari header kolom dan header baris. Hitung isi matriks hasil dengan menggunakan rekursif untuk menghitung FPB-nya.

 

Format Masukan:

K, tanda header kolom dimulai
n, 0 < n < 100, banyaknya header kolom
n baris angka header kolom
B, tanda header baris dimulai
m, 0 < m < 100, banyaknya header baris
m baris angka header baris

Format Keluaran:

semua angka dalam matriks dimana dimulai dari semua angka di baris ke 1 diteruskan dengan baris 2, dan seterusnya

Contoh Masukan

K
3
3
4
2
B
3
1
3
2


Contoh Keluaran

1
1
1
3
1
1
1
2
2

 */
