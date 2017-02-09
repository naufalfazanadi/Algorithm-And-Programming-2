#include <stdio.h>
#include <string.h>

typedef struct{
	char nim[10];
	char nama[100];
	char nilai[5];
}nilaiMatKul;

int main(){
	int jumlahrek = 0;
	nilaiMatKul temp[100];
	nilaiMatKul rekaman,baru;
	FILE *arsipMatKul;
	arsipMatKul = fopen("Arsipmatkul.txt","r");
	
	printf("mulai proses memasukkan isi file ke array\n");
	fscanf(arsipMatKul, "%s %s %s\n", &rekaman.nim,&rekaman.nama , &rekaman.nilai);
	
	if(strcmp(rekaman.nim, "XXXXXXXX") == 0){
		printf("arsip kosong\n");
	}else{
		do{
			strcpy(temp[jumlahrek].nim,rekaman.nim);
			strcpy(temp[jumlahrek].nama,rekaman.nama);
			strcpy(temp[jumlahrek].nilai,rekaman.nilai);
			jumlahrek++;
			fscanf(arsipMatKul, "%s %s %s\n", &rekaman.nim, &rekaman.nama , &rekaman.nilai);
		}while(strcmp(rekaman.nim, "XXXXXXXX") != 0);		
	}
	fclose(arsipMatKul);
	
	printf("proses memasukkan data baru\n");
	printf("masukkan nim: ");
	scanf("%s", &baru.nim);
	printf("masukkan nama: ");
	scanf("%s", &baru.nama);
	printf("masukkan nim: ");
	scanf("%s", &baru.nilai);
	
	if(strcmp(baru.nim, temp[0].nim) < 0){
		//rekaman baru di paling depan
		//geser semua isi array kebelakang
		int i;
		for(i=(jumlahrek-1); i >= 0; i--){
			strcpy(temp[i+1].nim, temp[i].nim);
			strcpy(temp[i+1].nama, temp[i].nama);
			strcpy(temp[i+1].nilai, temp[i].nilai);
		}
		jumlahrek++;
		strcpy(temp[0].nim, baru.nim);
		strcpy(temp[0].nama, baru.nama);
		strcpy(temp[0].nilai, baru.nilai);
	}else if(strcmp(baru.nim, temp[jumlahrek-1].nim) > 0){
	//rekaman baru di belakang
		strcpy(temp[jumlahrek].nim, baru.nim);
		strcpy(temp[jumlahrek].nama, baru.nama);
		strcpy(temp[jumlahrek].nilai, baru.nilai);
		jumlahrek++;
	}else{
		//rekaman baru memiliki posisi di tengah
		int i = 0;
		int stop = 0;
		//cari posisi
		while((i < jumlahrek) && (stop == 0)){
			if(strcmp(temp[i].nim, baru.nim) > 0){
				stop = 1;
			}else{
				i++;
			}
		}
		int j;
		for(j=(jumlahrek-1); j >= i; j--){
			strcpy(temp[j+1].nim, temp[j].nim);
			strcpy(temp[j+1].nama, temp[j].nama);
			strcpy(temp[j+1].nilai, temp[j].nilai);
		}
		strcpy(temp[i].nim, baru.nim);
		strcpy(temp[i].nama, baru.nama);
		strcpy(temp[i].nilai, baru.nilai);
		jumlahrek++;
	}
	//flush ke file
	arsipMatKul = fopen("ArsipMatKul.dat", "w");
	int i;
	for(i=0; i < jumlahrek; i++){
		fprintf(arsipMatKul, "%s %s %s\n", temp[i].nim, temp[i].nama,
		temp[i].nilai);
	}
	fprintf(arsipMatKul, "XXXXXXXX XXX X");
	fclose(arsipMatKul);
	return 0;
}