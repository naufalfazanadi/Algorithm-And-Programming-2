#include <stdio.h>
#include <string.h>

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

// CEK HURUF VOKAL KONSO DAN ANGKA
int cekVokal (char ch);
int cekKonsonan (char ch);
int cekInt (char ch);

// UNTUK CHECK KATA
int checking ();

/* Saya Muhammad Naufal Fazanadi tidak melakukan kecurangan seperti yang telah
dispesifikasikan pada mata kuliah Algoritma dan Pemograman 2 dalam mengerjakan
Ujian Akhir Semester (UAS), jika saya melakukan kecurangan maka Allah/Tuhan
adalah saksi saya, dan saya bersedia menerima hukumanNya. Aamiin. */