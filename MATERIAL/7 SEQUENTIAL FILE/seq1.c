#include <stdio.h>
#include <string.h>

typedef struct{
	char nim[10];
	char nama[64];
	char nilai[4];
}pack;

int main(){

	pack record;

	// membuat sebuah file
	FILE *archive_mahasiswa;
	archive_mahasiswa = fopen("archive_mahasiswa.dat", "w"); // "w" itu mode write

	printf("Tuliskan record satu per satu: \n");

	// untuk pengecekan awal
	printf("masukkan nim : ");
	scanf("%s", &record.nim);

	while(strcmp(record.nim, "XXXXXXXX") != 0){
		/* proses */
		printf("masukkan nama : ");
		scanf("%s", &record.nama);

		printf("masukkan nilai : ");
		scanf("%s", &record.nilai);

		// memasukkan data inputan ke sebuah file baru
		fprintf(archive_mahasiswa, "%s %s %s\n", record.nim, record.nama, record.nilai);

		/* iterasi */
		printf("masukkan nim : ");
		scanf("%s",&record.nim);
	}

	// masukan data xxxxxxx sebagai batas berakhir nya data
	fprintf(archive_mahasiswa, "%s %s %s\n", "XXXXXXXX","XXX","X");
	fclose(archive_mahasiswa); // tutup untuk ke file baru nya

	return 0;
}