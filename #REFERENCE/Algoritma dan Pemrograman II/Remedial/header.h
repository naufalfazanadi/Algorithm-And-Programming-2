#include<stdio.h>
/*Saya Faisal Syaiful Anwar tidak melakukan kecurangan seperti yang telah dispesifikasikan 
pada mata kuliah Algoritma dan Pemrograman II dalam mengerjakan Remedial Shift 2,
 jika saya melakukan kecurangan maka Allah/Tuhan adalah saksi saya,
 dan saya bersedia menerima hukumanNya. Aamiin.*/
typedef struct{
	char letter;
	int count;
}bungkus;
bungkus record[5];
 //variabel mesin karakter
 int indeks;
char cc;
//deklarasi fungsi prosedur
void start(char pita[]);
void inc(char pita[]);
void adv(char pita[]);
char getcc();
int EOP();
void insertion(int n);