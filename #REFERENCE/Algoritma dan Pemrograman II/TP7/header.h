#include <stdio.h>
#include <string.h>
/*Saya Faisal (1403356) tidak melakukan kecurangan seperti yang telah dispesifikasikan pada mata kuliah Algoritma dan Pemrograman II dalam mengerjakan TP7,
jika saya melakukan kecurangan maka Allah/Tuhan adalah saksi saya, dan saya bersedia menerima hukumanNya. Aamiin.*/
// bungkusan berisi tabel pada file
typedef struct{
	char code[10];
	char name[100];
	int cost;
	int multiple;
	int total;
}structure;
//global declare
int n;
void read(structure* data,char path[50]);
void calculate(structure* data);
void sort(structure* a);
void write(structure* data);
