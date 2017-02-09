#include<stdio.h>
#include<string.h>
//matriks tipe bungkusan
/*Saya Faisal tidak melakukan kecurangan seperti yang telah dispesifikasikan pada mata kuliah Algoritma dan Pemrograman II dalam mengerjakan TP1, jika saya melakukan kecurangan maka Allah/Tuhan adalah saksi saya, dan saya bersedia menerima hukumanNya. Aamiin.*/
typedef struct{
	int matriks[100][100];
	int matriks2[100][100];
}bungkus; //bungkusan matriks
//deklarasi global
bungkus fung(int k,int b,bungkus data,int n,int koor1[n],int koor2[n],char kata[100][100]);
void resize(int a[100],int n,int b);