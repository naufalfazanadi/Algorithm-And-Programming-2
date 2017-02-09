#include "header.h"
//prosedur delete
void deleteData(char nim[15]){
	//selalu read sblm memulai
	readFile();
	int i,j;
	int status = 0;
	//jika data ada maka hapus
	i = 0;
	char hapus[10];
	while(i<n && status == 0){
		if(strcmp(data[i].nim,nim)==0){
			status = 1;
			printf("Data ditemukan, yakin hapus data? ya/tidak\n");
			scanf("%s",&hapus);
			if(strcmp(hapus, "ya") == 0){
				for(j=i;j<n;j++){
					data[j]=data[j+1];
				}n--;
				writeFile();
			}
		}else{
			i++;
		}
	}
	//empty set
	if(status == 0){
		printf("Data tidak ditemukan\n");
	}
}

//read seq file
void readFile(){
	n = 0;
	mahasiswa tmp;
	FILE *fdata;
	fdata = fopen("data.txt", "r");
	namapjg = 0;
	//do temporarry :) -ALIFIA SAID
	do{
		fscanf(fdata,"%s %s %s", &tmp.nim, &tmp.nama , &tmp.kelas);
		if( strcmp(tmp.nim, "##") != 0 && strcmp(tmp.nama,"##") != 0 && strcmp(tmp.kelas, "##") != 0){
			data[n] = tmp;
			n++;
			if(strlen(tmp.nama) > namapjg){
				namapjg = strlen(tmp.nama);
			}
		}		
 	}while( strcmp(tmp.nim,"##") != 0 && strcmp(tmp.nama, "##") != 0 && strcmp(tmp.kelas, "##") != 0);
	
	fclose(fdata);
}
//garis to help make tabel
void garis(){
	int i;
	for(i=0;i<(namapjg+3)+20;i++){
		printf("-");
	}
	printf("\n");
}

//flush array ke fike
void writeFile(){
	int i;
	
	FILE *fdata;
	fdata = fopen("data.txt", "w");
	
	for(i=0;i<n;i++){
		fprintf(fdata,"%s %s %s\n",data[i].nim , data[i].nama, data[i].kelas);
	}
	fprintf(fdata, "## ## ##\n");
	
	fclose(fdata);
}

void insertData(mahasiswa masukan){
	int i = 0;
	int status = findData(masukan.nim);
	//kondisi untuk insert di bawah
	//tidak bisa digunakan utk insert ditengAH:)
	if(status == 0){
		data[n] = masukan;
		n++;
		writeFile();
		printf("Data berhasil ditambahkan\n");
	}else{
		printf("NIM sudah terdaftar, data gagal ditambahkan\n");
	}
}

int findData(char nim[15]){

	//find data berupa fungsi true or false
	int status = 0;
	int i =0;
	readFile();
	
	while(status == 0 && i<n ){
		if(strcmp(data[i].nim, nim) == 0){
			status = 1;
		}else{
			i++;
		}
	}
	
	return status;
}
void updateData(char nim[15]){

	//update data menggunakan searching
	readFile();
	int i, j;
	int status = 0;
	i = 0;
	char nama[25],kelas[15];
	while(i<n && status == 0){
		if(strcmp(data[i].nim, nim) == 0){
			status = 1;
			printf("Data ditemukan. \n");
			printf("--Data Awal--\n");
			printf("Nama : %s\n",data[i].nama);
			printf("Kelas : %s\n",data[i].kelas);
			printf("-----------\n");
			printf("Masukan nama baru : ");
			scanf("%s",&nama);
			printf("Masukan kelas baru : ");
			scanf("%s",&kelas);
			//replace same index to new field
			strcpy(data[i].nama,nama);
			strcpy(data[i].kelas,kelas);
			printf("Data berhasil diupdate\n");
			writeFile();
		}else{
			i++;
		}
	}
	//empty set
	if(status == 0){
		printf("Data tidak ditemukan\n");
	}
}