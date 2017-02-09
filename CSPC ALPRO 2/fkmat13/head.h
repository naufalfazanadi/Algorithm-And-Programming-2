#include <stdio.h>
#include <string.h>

long long int faktorial (int n);
void process (int kolom[], int baris[], int n, int m);

/*
Diberikan beberapa masukan yang merupakan header baris dan header kolom dari sebuah matriks perkalian faktorial, isi dari matriks adalah hasil perkalian faktorial dari header kolom dan header baris. Hitung isi matriks hasil dengan menggunakan rekursif untuk menghitung faktorialnya.

 

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
5


Contoh Keluaran

6
24
2
36
144
12
720
2880
240



 */
