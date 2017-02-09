#include"header.h"

int convert(char inputan[]){
	int i, j, k;
	int nilai;
	int total=0;
	nilai=128;
		for(i=0; i<strlen(inputan); i++){
			if(inputan[i]=='1'){
				total=total+nilai;
			}
			nilai=nilai/2;
		}
	return total;
}

int tambah(int a, int b){
	int jumlah;
		jumlah=a+b;
	
	return jumlah;
}

void convert_lagi(int a, data* sesuatu, int desimal){
	int i;
	char biner2[100];
	strcpy(sesuatu[a].biner, "00000000");
	int nilai;
	nilai=128;
	if(desimal > 256){
		desimal=desimal-256;
	}
	for(i=0; i<8; i++){
		if(desimal >= nilai){
			desimal=desimal-nilai;
			sesuatu[a].biner[i]='1';
		}
		nilai=nilai/2;
	}
		
	// for(i=0; i<n+2; i++){
		// printf("%s", sesuatu[a].biner[i]);
	// }
}


void bubble(data a[], int n){
	int i, tukar;

	data temp;
	
	do{
	/* inisialisasi nilai tukar sebelum ada pertukaran, di set 0 karena belum ada proses tukar antara array */
		tukar=0;
		/* pengulangan dan memeriksa apakah ada pertukaran */
		for(i=0; i<(n-1); i++){
		/* jika ada nilai yang dipertukarkan */
			if(a[i].desimal > a[i+1].desimal){
			/* menukar posisi elemen */
				temp = a[i];//tabInt di indeks itu dimasukkan ke 
				a[i]=a[i+1];
				a[i+1]=temp;
				tukar=1;
			}
		}
	}while(tukar == 1);
	
	
	for(i=0; i<n; i++){
		// printf("%d \n", a[i].desimal);
	// printf("%s %d\n", arr[i].kata, arr[i].jumlah);
	}
}

void binarysearch(int n,  data a[]){
	int i=0;
	// int j=n-1;
	int ketemu=0;
	int k;
	
	while(ketemu == 0 && i<=n){
		cari = a[i].desimal;
		if(cari==a[i].desimal){
			ketemu=1;
		}
		else{
			i++;
		}
	}
	
	if(ketemu==1){
		// convert_lagi(a[i].desimal);
		printf("-----data ditemukan-----\n");
		printf("%d\n", k+1);
		// printf("nama : %s\n", ilkom[k].nama);
		// printf("nilai : %.2f\n", ilkom[k].nilai);
	}
	else{
		printf("data not found");
	}
}

void merge(data* tampung1, data* tampung2, data* tabel3, int n){

	bubble(tampung1, n);
	bubble(tampung2, n);
	
	int index1=0, index2=0, index3=0;
	
	while((index1<n) && (index2<n)){
		if(tampung1[index1].desimal<tampung2[index2].desimal){
			tabel3[index3]=tampung1[index1];
			index1++;
			index3++;
		}else if(tampung1[index1].desimal > tampung2[index2].desimal){
			tabel3[index3]=tampung2[index2];
			index2++;
			index3++;
		}else{
			tabel3[index3]=tampung1[index1];
			index1++;
			index3++;
			
			tabel3[index3]=tampung2[index2];
			index2++;
			index3++;
		}
	}
	
	int i=0;
	if(index1 < n){	
		for(i=index1; i<n; i++){
			tabel3[index3]=tampung1[i];
			index3++;
		}
	}
	if(index2 < n){
		for(i=index2; i<n; i++){
			tabel3[index3]=tampung2[i];
			index3++;
		}
	}
	
	binarysearch(n+n, tabel3);
	
	/*for(i=0; i<n+n; i++){
		printf("%d ", tabel3[i].desimal);
	 }*/
}