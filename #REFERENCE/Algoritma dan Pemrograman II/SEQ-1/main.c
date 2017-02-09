#include "header.h"

int main(){
	char path[100];
	char newpath[100];
	strcpy(path,"Buka.txt");
	char kata_cari[30];
	printf("Masukkan nim yang dicari :");
	scanf("%s", &kata_cari);
	write(path);
	copy(path,newpath);
	read(path);
	find(path,kata_cari);
	printf("!!!!!!!!!!!!!!!!\n");
	read(newpath);
	
	return 0;
}