#include<stdio.h>
#include<string.h>
/*Saya Faisal (1403356) tidak melakukan kecurangan seperti yang telah dispesifikasikan pada mata kuliah Algoritma dan Pemrograman II dalam mengerjakan TP6,
jika saya melakukan kecurangan maka Allah/Tuhan adalah saksi saya, dan saya bersedia menerima hukumanNya. Aamiin.*/
// bungkusan berisi biner dan desimalnya
typedef struct{
	char biner[100];
	int decimal;
}bungkus;
// deklarasi global
bungkus data[4][50];
bungkus datanew[2][50];
bungkus lasttable[50];
// deklarasi fungsi prosedur
int konversi(int a,int b,char biner[]);
void tambahkan(int a, int b,int indeksnew,int n);
void konversi2(int a,int b,int desimal);
void mergetable(int n,bungkus tabel1[],bungkus tabel2[],bungkus *tabel3);
void sort(int n,bungkus* a);
void binarysearch(int bil_cari,int n,bungkus tabInt[],char replace[]);