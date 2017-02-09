#include <stdio.h>
#include <string.h>
/*Saya Faisal tidak melakukan kecurangan seperti yang telah dispesifikasikan pada mata kuliah Algoritma dan Pemrograman II dalam mengerjakan TP4,
jika saya melakukan kecurangan maka Allah/Tuhan adalah saksi saya, dan saya bersedia menerima hukumanNya. Aamiin.*/
// Bungkusan yang berisi nama,barang,Harga toko tersebut
typedef struct{
	char nama[100];
	char barang[100];
	int harga;
}bungkus;

bungkus sell[100];

// deklarasi prosedur
void quickSortPivotPinggir(int l,int r);
void print(int n,bungkus a[n+1]);