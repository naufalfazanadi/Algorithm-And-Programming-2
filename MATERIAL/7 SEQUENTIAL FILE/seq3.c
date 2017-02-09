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

	archive_mahasiswa = fopen("archive_mahasiswa.dat", "r");

	char kata_cari[10];

	printf("masukkan nim yang dicari : ");
	scanf("%s", &kata_cari);

	fscanf(archive_mahasiswa, "%s %s %s\n", &record.nim, &record.nama, &record.nilai);

	if(strcmp(record.nim, "XXXXXXXX") == 0){
		printf("arsip kosong\n");
	}else{
		if(strcmp(kata_cari, "XXXXXXXX") == 0){
			printf("tidak ditemukan\n");
		}else{
			while((strcmp(record.nim, "XXXXXXXX") != 0)&&(strcmp(record.nim, kata_cari) != 0)){
				/* iterasi */
				fscanf(archive_mahasiswa, "%s %s %s\n", &record.nim, &record.nama, &record.nilai);
			}

			if(strcmp(record.nim, kata_cari)== 0){
				printf("hasil pencarian : \n");
				printf("nim : %s\n", record.nim);
				printf("nama : %s\n", record.nama);
				printf("nilai : %s\n", record.nilai);
				printf("------------\n");
			}else{
				printf("tidak ditemukan\n");
			} 
		} 
	}
	fclose(archive_mahasiswa);
	return 0;
}