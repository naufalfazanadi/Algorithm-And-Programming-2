#include<stdio.h>
#include<string.h>
/*Saya Faisal (1403356) tidak melakukan kecurangan seperti yang telah dispesifikasikan pada mata kuliah Algoritma dan Pemrograman II dalam mengerjakan TP5,
jika saya melakukan kecurangan maka Allah/Tuhan adalah saksi saya, dan saya bersedia menerima hukumanNya. Aamiin.*/
//bungkusan berisi inputan ditambah temporary bulan dalam integer
typedef struct{
	char nama[100];
	int hari;
	char bulan[100];
	int tahun;
	int tempbulan;
}bungkus;
//deklarasi prosedur 
void konversi(bungkus* a, int n);
void insertion(bungkus* arr, int n);
void mergetable(bungkus* array1,bungkus* array2,bungkus* array3,int n,int m);