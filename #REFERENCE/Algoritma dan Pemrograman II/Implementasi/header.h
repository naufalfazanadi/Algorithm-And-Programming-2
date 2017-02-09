#include <stdio.h>
#include <string.h>
/*Saya Faisal (1403356) tidak melakukan kecurangan seperti yang telah dispesifikasikan pada mata kuliah Algoritma dan Pemrograman II dalam mengerjakan latihan alpro,
jika saya melakukan kecurangan maka Allah/Tuhan adalah saksi saya, dan saya bersedia menerima hukumanNya. Aamiin.*/
// bungkusan berisi nim nama kelas
typedef struct{
	char nim[15];
	char nama[25];
	char kelas[5];
}mahasiswa;
//var global
mahasiswa data[999];
int n;
int namapjg;
void readFile();
void writeFile();

int findData(char[15]);
void insertData(mahasiswa);
void deleteData(char[15]);
void updateData(char[15]);