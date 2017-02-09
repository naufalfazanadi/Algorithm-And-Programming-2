#include "header.h"

void write(char path[]){
	bungkus rekaman;
	FILE *data;
	data = fopen(path,"w");
	printf("Tuliskan rekaman satu per satu: \n");
	printf("Masukkan NIM : ");
	scanf("%s", &rekaman.nim);
	while(strcmp(rekaman.nim, "XXXXXXXX") != 0){
		printf("Masukkan nama : ");
		scanf("%s", &rekaman.nama);
		printf("masukkan nilai : ");
		scanf("%s", &rekaman.nilai);
		
		fprintf(data, "%s %s %s\n", rekaman.nim,rekaman.nama,rekaman.nilai);
		
		printf("Masukkan NIM : ");
		scanf("%s", &rekaman.nim);
	}
	fprintf(data, "%s %s %s\n", "XXXXXXXX", "XXX", "X");
	fclose(data);
}

void read(char path[100]){
	bungkus rekaman;
	FILE *data;
	data = fopen(path,"r");
	printf("isi arsip beruntun adalah :\n");
	fscanf(data, "%s %s %s\n", &rekaman.nim,&rekaman.nama,&rekaman.nilai);
	
	if(strcmp(rekaman.nim,"XXXXXXXX")==0){
		printf("arsip kosong\n");
	}else{
		do{
			printf("nim: %s\n",rekaman.nim);
			printf("nama: %s\n",rekaman.nama);
			printf("nilai: %s\n",rekaman.nilai);
			printf("--------------------------------\n");
			
			fscanf(data,"%s %s %s\n",&rekaman.nim,&rekaman.nama,&rekaman.nilai);
		}while(strcmp(rekaman.nim,"XXXXXXXX")!= 0);
	}
	fclose(data);
}

void find(char path[],char findit[]){
	bungkus rekaman;
	FILE *data;
	data = fopen(path,"r");
	fscanf(data, "%s %s %s\n",&rekaman.nim, &rekaman.nama, &rekaman.nilai);
	if (strcmp(rekaman.nim, "XXXXXXXX") == 0){
		printf("arsip kosong\n");
	}else{
		if (strcmp(findit, "XXXXXXXX") == 0){
			printf("tidak ditemukan\n");
		}else{
			while((strcmp(rekaman.nim, "XXXXXXXX") != 0) && (strcmp(rekaman.nim, findit) != 0)){
				fscanf(data, "%s %s %s\n",&rekaman.nim, &rekaman.nama,&rekaman.nilai);
			}
		}
		if(strcmp(rekaman.nim,findit)==0){
			printf("hasil\n");
			printf("nim: %s\n",rekaman.nim);
			printf("nama: %s\n",rekaman.nama);
			printf("nilai: %s\n",rekaman.nilai);
			printf("--------------------------------\n");
		}else{
			printf("tidak ditemukan\n");
		}
	}
	fclose(data);

}

void copy(char path[],char newpath[]){
	bungkus rekaman;
	FILE *arsipMatKul1;
	FILE *arsipMatKul2;
	arsipMatKul1 = fopen(path, "r");
	arsipMatKul2 = fopen(newpath, "w");
	printf("Mulai proses menyalin file\n");
	fscanf(arsipMatKul1, "%s %s %s\n",&rekaman.nim, &rekaman.nama,&rekaman.nilai);
	if(strcmp(rekaman.nim, "XXXXXXXX") == 0){
		fprintf(arsipMatKul2, "%s %s %s\n","XXXXXXXX","XXX","X");
	}else{
	while(strcmp(rekaman.nim, "XXXXXXXX") != 0){
		fprintf(arsipMatKul2, "%s %s %s\n",rekaman.nim, rekaman.nama, rekaman.nilai);
		fscanf(arsipMatKul1, "%s %s %s\n",&rekaman.nim, &rekaman.nama,&rekaman.nilai);
	}
	fprintf(arsipMatKul2, "%s %s %s\n",
	"XXXXXXXX","XXX","X");
	}
	printf("proses menyalin file selesai\n");
	fclose(arsipMatKul1);
	fclose(arsipMatKul2);

}