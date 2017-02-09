#include "header.h"
//main program
int main(){
	//deklarasi index variabel
	int i, j;
	int n,m;
	//input jumlah data 1
	scanf("%d", &n);
	bungkus Arr1[n]; //variabel array sejumlah data 1
	for(i=0; i<n; i++){
		scanf(" %s %d %d", &Arr1[i].nama, &Arr1[i].krt_merah, &Arr1[i].krt_kng);
	}
	//data 2
	scanf("%d", &m);
	bungkus Arr2[m]; //variabel array sejumlah data 2
	for(i=0; i<m; i++){
		scanf(" %s %d %d", &Arr2[i].nama, &Arr2[i].krt_merah, &Arr2[i].krt_kng);
	}
	//-------------------------------------------------------------------------------------
	insertion(Arr1, n); //urutkan tabel 1 menggunakan prosedur
	insertion(Arr2, m); //urutkan tabel 2 menggunakan prosedur
	
	bungkus mergetable[m+n]; //variabel penggabungan tabel
	merge(Arr1, Arr2, mergetable, n, m); //gabungkan tabel dengan prsedur merge urut
	//---------------------------------------------------------------------------------------
	//print output program
	for(i=0; i<n+m; i++){
		printf("%s %d %d\n", mergetable[i].nama, mergetable[i].krt_merah, mergetable[i].krt_kng); 
	}	
	return 0;
}