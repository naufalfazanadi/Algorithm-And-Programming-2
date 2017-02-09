#include <stdio.h>
#include <string.h>

typedef struct{
	char nim[10];
	char nama[64];
	char nilai[4];
}pack;

int main(){
	pack record;

	FILE *archive_mahasiswa;
	archive_mahasiswa = fopen("archive_mahasiswa.dat", "r"); // "r" itu mode read yg sudah ada
	
	printf("isi arsip beruntun adalah : \n");
	fscanf(archive_mahasiswa, "%s %s %s\n", &record.nim, &record.nama, &record.nilai);
	
	if(strcmp(record.nim, "XXXXXXXX") == 0){
		printf("arsip kosong\n");
	} else {
		do{
			/* proses */
			printf("-----------------\n");
			printf("nim : %s\n", record.nim);
			printf("nama : %s\n", record.nama);
			printf("nilai : %s\n", record.nilai);
			/* iterasi */
			fscanf(archive_mahasiswa, "%s %s %s\n", &record.nim, &record.nama, &record.nilai);
		} while(strcmp(record.nim, "XXXXXXXX") != 0);
	}

	fclose(archive_mahasiswa);
	
	return 0;
}