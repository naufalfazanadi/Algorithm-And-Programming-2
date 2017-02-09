#include <stdio.h>
#include <string.h>
/*Saya Faisal Syaiful A tidak melakukan kecurangan seperti yang telah dispesifikasikan 
pada mata kuliah Algoritma dan Pemrograman II dalam mengerjakan Evaluasi Praktikum Akhir,
 jika saya melakukan kecurangan maka Allah/Tuhan adalah saksi saya,
 dan saya bersedia menerima hukumanNya. Aamiin.*/
//----------
//variabel pita
char pita[500];
//------------
//variabel mesinKata
char ckata[50];
int indeks;
int panjangkata;
//------------
//variabel newDelete
char result[50][50];
int row;
//variabel fungsi/prosedur
void read();
void STARTKATA(char pita[]);
void RESETKATA();
void INCKATA(char pita[]);
char* GETCKATA();
int GETPANJANGKATA();
int EOPKATA(char pita[]);
void write();