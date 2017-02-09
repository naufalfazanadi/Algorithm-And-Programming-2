#include <stdio.h>
#include <string.h>
#include <time.h>
typedef struct{
	char nama[100];
	char x[2];
	char y[2];
}bungkus;
typedef struct{
	char nama[100];
	char matriks[3][3];
}bungkusnew;
int n;
int namapjg;
bungkus tabel[100];
bungkusnew pola[100];
//mesinkata
int indeks;
char ckata[100];
int panjangkata;
//-----------
void home();
void print();
void add(char nama[100],char x[2],char y[2]);
void read();
void write(FILE *data);
void getpola();
void finddelete(char nama[100]);
void STARTKATA(char pita[]);
void RESETKATA();
void INCKATA(char pita[]);
char* GETCKATA();
int GETPANJANGKATA();
int EOPKATA(char pita[]);
void findpita(char kata[100],int tebal);
void makingmatriks();
void insert(char nama[100],char x[2],char y[2]);