#include <stdio.h>
#include <string.h>

// RECORD
typedef struct {
  char kiri[32];
  char kanan[32];
} pack;

// var global
int n;
pack record[21];

// MESIN KATA
// Var global nya
int indeks;
int panjangkata;
char ckata[50];

// Procedure function nya
void STARTKATA(char pita[]);
void RESETKATA();
void INCKATA(char pita[]);
char* GETCKATA();
int GETPANJANGKATA();
int EOPKATA(char pita[]);

// SEQUENTIAL FILE
void read ();
void write ();
// prosedur untuk setiap pola
void turun(char penumpang[]);
void sebelahan(char ribbon[], char penumpang1[]);
void duduk(char ribbon[], char penumpang1[]);

/* Saya Muhammad Naufal Fazanadi tidak melakukan kecurangan seperti yang telah
dispesifikasikan pada mata kuliah Algoritma dan Pemograman 2 dalam mengerjakan
Evaluasi praktikum 2, jika saya melakukan kecurangan maka Allah/Tuhan adalah
saksi saya, dan saya bersedia menerima hukumanNya. Aamiin. */