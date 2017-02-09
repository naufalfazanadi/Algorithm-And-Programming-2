#include <stdio.h>
#include <string.h>

// BOOLEAN
#define TRUE 1
#define FALSE 0

// MESIN KATA
int indeks;
int panjangkata;
char ckata[50];

void STARTKATA(char pita[]);
void RESETKATA();
void INCKATA(char pita[]);
char* GETCKATA();
int GETPANJANGKATA();
int EOPKATA(char pita[]);

// My Function
char toUpperCase (char ch); // for capitalize char
int checkSms(char str[256]); // Check validitas

/* Saya Muhammad Naufal Fazanadi tidak melakukan kecurangan seperti yang telah
dispesifikasikan pada mata kuliah Algoritma dan Pemograman 2 dalam mengerjakan
Tugas Praktikum 9, jika saya melakukan kecurangan maka Allah/Tuhan adalah saksi
saya, dan saya bersedia menerima hukumanNya. Aamiin. */
