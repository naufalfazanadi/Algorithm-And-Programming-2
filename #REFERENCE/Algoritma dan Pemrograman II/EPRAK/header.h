#include<stdio.h>
#include<string.h>
/*Saya Faisal tidak melakukan kecurangan seperti yang telah dispesifikasikan pada mata kuliah Algoritma dan Pemrograman II dalam mengerjakan EVPRAK(EP142),
jika saya melakukan kecurangan maka Allah/Tuhan adalah saksi saya, dan saya bersedia menerima hukumanNya. Aamiin.*/
//bungkusan berisi krt merah,kuning,nama
typedef struct{
	char nama[100];
	int krt_merah;
	int krt_kng;
}bungkus;
//deklarasi prosedur.
void insertion(bungkus* arr, int n);
void merge(bungkus* tabel_1, bungkus* tabel_2, bungkus* tabel_urut, int n, int m);