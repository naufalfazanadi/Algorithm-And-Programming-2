#include <stdio.h>
#include <string.h>
#include <time.h>
#include <windows.h>

/*Saya Faisal Syaiful Anwar tidak melakukan kecurangan seperti yang telah dispesifikasikan pada mata kuliah Algoritma dan Pemrograman II dalam mengerjakan Tugas Masa Depan Alpro 2,jika saya melakukan kecurangan maka Allah/Tuhan adalah saksi saya, dan saya bersedia menerima hukumanNya. Aamiin.*/
// bungkusan berisi tabel pada file
typedef struct{
	char nama[100];
	int x;
	int y;
}bungkus;
//---------------------
//variabel global
int n;
int namapjg;
bungkus tabel[100];
//mesinkata
int indeks;
char ckata[100];
int panjangkata;
//--
short color;
int temp;
//-----------------------
//deklarasi prosedur ufngsi
void home();
void nu1();
void nu4();
void print();
void read();
void write();
void finddelete(char nama[100]);
void findpita(char kata[100],int tebal);
void insert(char nama[100],int x,int y);
int binarysearch(char kata[100]);
int checksame(char nama[100],int x,int y);

void STARTKATA(char pita[]);
void RESETKATA();
void INCKATA(char pita[]);
char* GETCKATA();
int GETPANJANGKATA();
int EOPKATA(char pita[]);