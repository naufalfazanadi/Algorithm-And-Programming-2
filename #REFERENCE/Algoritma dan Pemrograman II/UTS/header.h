#include<stdio.h>
#include<string.h>
/*Saya Faisal tidak melakukan kecurangan seperti yang telah dispesifikasikan pada mata kuliah Algoritma dan Pemrograman II dalam mengerjakan UTS(GARS215),
jika saya melakukan kecurangan maka Allah/Tuhan adalah saksi saya, dan saya bersedia menerima hukumanNya. Aamiin.*/
//bungkusan yang diminta berupa 2 string dan 1 integer
typedef struct{
	char string[100];
	char string2[100];
	int voko;
}risna;
//deklarasi prosedur
void vokon(risna* a,int n);
void selection(risna* a,int n);
void bubble(risna*a, int n);
void insertion(risna* a, int n);
void mergetable(risna* array1,risna* array2,risna* array3,int n,int m);
void quickSortPivotPinggir(risna* a,int l,int r);