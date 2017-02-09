#include <stdio.h>
#include <string.h>
/*Saya Faisal (1403356) tidak melakukan kecurangan seperti yang telah dispesifikasikan pada mata kuliah Algoritma dan Pemrograman II dalam mengerjakan kuis3,
jika saya melakukan kecurangan maka Allah/Tuhan adalah saksi saya, dan saya bersedia menerima hukumanNya. Aamiin.*/
typedef struct{
	int number;
	int divided;
}bungkus;
//deklarasi global
int calculate(int , int );
void seqsearch(int n,int findit,bungkus* a);
void binary(int n,int findit, bungkus* a);