#include <stdio.h>
#include <string.h>

int strip (char command[]);
void print (int field[10][10]);

/* Saya Muhammad Naufal Fazanadi tidak melakukan kecurangan seperti yang telah dispesifikasikan
pada mata kuliah Algoritma dan Pemograman 2 dalam mengerjakan Tugas Praktikum 1,
jika saya melakukan kecurangan maka Allah/Tuhan adalah saksi saya, 
dan saya bersedia menerima hukumanNya. Aamiin. */

/*
Moni merupakan anak yang suka membuat peta. Pada suatu hari Rudi ingin berpetualang ke sebuah tempat. Dalam petualangannya, Rudi ingin mengigat setiap langkah yang telah ia jalani. Bantulah Moni untuk menggambarkan langkah rudi di sebuah peta. Luas tempat yaitu 10 X 10. Rudi dipastikan tidak akan melewati batas tempat tersebut


Format masukan 
x,y koordinat dari tepat awal Rudi(x)
0 < n < 25 , jumlah lankah
0 < i,j <= n, arah langkah, panjang langkah 

Format keluaran
sebuah peta yang mempresentasikan langkah Moni

Contoh Masukan

2 1
5
kanan 5
bawah 5
kiri 3
atas 3
kiri 1


Contoh Keluaran

*x-----***
******|***
**-|**|***
***|**|***
***|**|***
***---|***
**********
**********
**********
**********
 
*x-----***
******|***
**-----|**
*|-----|**
*||-X*||**
*||---||**
*------|**
**********
**********
**********


 */
