#include <stdio.h> // lib

// fungsi
int recursive(int n, int count);

//JANJI
/* Saya Muhammad Naufal Fazanadi tidak melakukan kecurangan seperti yang telah dispesifikasikan
pada mata kuliah Algoritma dan Pemograman 2 dalam mengerjakan Kuis 1,
jika saya melakukan kecurangan maka Allah/Tuhan adalah saksi saya, 
dan saya bersedia menerima hukumanNya. Aamiin. */

/*
Diberikan sebuah matriks dimana semua sel-nya diberikan sebuah angka integer. Carilah berapa kali angka itu bisa terbagi 2 (membelah) sampai hasil baginya dibawah angka 1 (nol koma), nol koma dihitung sebagai hasil bagi terakhir. Lalu tampilkan ke layar angka integer awal dan berapa kali angka itu bisa membelah. Proses membelah menggunakan rekursif.
Misalkan besar integer adalah 8 maka banyaknya proses membelah adalah:
level 1 membelah menjadi 4.
level 2 membelah menjadi 2.
level 3 membelah menjadi 1.
level 4 membelah menjadi 0.5.
Maka level pembelahan yang dilakukan adalah 4.
Format Masukan:

b, 0 < b < 100, banyaknya baris pada matriks.
k, 0 < k < 100, banyaknya kolom pada matriks.
b x k baris angka isi matriks, 0 <= angka <= 1.000.000
Format Keluaran:

isi hasil matriks dengan format per sel adalah (angka_awal, banyaknya_membelah).
Contoh Masukan

2
3
2
0
9
4
16
32


Contoh Keluaran

(2, 2) (0, 0) (9, 4)
(4, 3) (16, 5) (32, 6)


 */
