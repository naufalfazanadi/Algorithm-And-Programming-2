#include "header.h"

int main(){
	int i,j;
	int pilihan;
	mahasiswa alpro;
	//read file sebelum memasuki home
	readFile();
	system("cls"); //clear layar
	
	//isi tabel dengan pola tabel
	printf("Isi tabel saat ini :\n");
	garis();
	printf("|nim");
	for(i=0;i<(9+3)-4;i++){
		printf(" ");
	}
	printf("|nama");
	for(i=0;i<(namapjg+3)-4;i++){
		printf(" ");
	}
	printf("|kelas|\n");
	garis();
	for(i=0; i<n; i++){
		printf("|%s",data[i].nim);
		for(j=0;j<((9+2))-strlen(data[i].nim) ; j++){
			printf(" ");
		}
		printf("|%s",data[i].nama);
		for(j=0;j<(namapjg+3)-strlen(data[i].nama);j++){
			printf(" ");
		}
		printf("|%s",data[i].kelas);
		for(j=0;j<3;j++){
			printf(" ");
		}
		printf("|\n");
	}
	//garis dan tabel semu standar
	garis();
	printf("Menu Pilihan :\n");
	printf("----------------\n");
	printf("1. Cari Data   |\n");
	printf("2. tambah Data |\n");
	printf("3. update Data |\n");
	printf("4. delete Data |\n");
		printf("----------------\n");

	printf("Masukkan Pilihan anda: ");
	scanf("%d", &pilihan);
	
	if(pilihan == 1){
	//prosedur find
		printf("masukan NIM : ");
		scanf("%s", &alpro.nim);
		
		if(findData(alpro.nim) == 1){
			printf("data ditemukan\n");
		}else{
			printf("data tidak ditemukan\n");
		}
	}else if(pilihan ==2){
	//prosedur add
		printf("masukan NIM :");
		scanf("%s", &alpro.nim);
		printf("masukan nama : ");
		scanf("%s", &alpro.nama);
		printf("masukan kelas : ");
		scanf("%s", &alpro.kelas);
		insertData (alpro);
	}else if(pilihan == 3){
	//update
		printf("masukan nim : ");
		scanf("%s", &alpro.nim);
		
		updateData(alpro.nim);
		
	}else if(pilihan == 4){
		printf("masukan NIM : ");
		scanf("%s", &alpro.nim);
		//delete
		deleteData(alpro.nim);
	}
	
	return 0;
}