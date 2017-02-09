#include "header.h"
//mesin program
//prosedur insersi
void insertion(bungkus* arr, int n){
	//deklarasi indeks
	int i, j;
	bungkus risna;
	
	for(i=1; i<n; i++){
		risna=arr[i];
		j=i-1;
		while(((risna.krt_merah<arr[j].krt_merah) || ((risna.krt_merah == arr[j].krt_merah) && (risna.krt_kng < arr[j].krt_kng))) && (j>=0)){
			/*jika data array lebih kecil dari data sisip maka data array
			digeser ke belakang*/
			arr[j+1]=arr[j];
			j=j-1;
		}
		/*menempatkan data sisip pada array*/
		arr[j+1]=risna;
	}
}
//prosedur mergetable urut
void merge(bungkus* table1, bungkus* table2, bungkus* tabel_urut, int n, int m){
	//deklarasi indeks
	int i;
	int index1=0, index2=0, index3=0;
	while((index1<n) && (index2<m)){
		//jika elemen array 1 lebih kecil dari elemen array2
		if((table1[index1].krt_merah < table2[index2].krt_merah) || ((table1[index1].krt_merah == table2[index2].krt_merah) && (table1[index1].krt_kng < table2[index2].krt_kng))){
			tabel_urut[index3]=table1[index1];
			index1++;
			index3++;
		//jika elemen array 2 lebih kecil dari elemen array 1
		}else if((table1[index1].krt_merah > table2[index2].krt_merah) || ((table1[index1].krt_merah == table2[index2].krt_merah) && (table1[index1].krt_kng > table2[index2].krt_kng))){
			tabel_urut[index3]=table2[index2];
			index2++;
			index3++;
		//jika kedua elemen sama
		}else{
			tabel_urut[index3]=table1[index1];
			index1++;
			index3++;
			
			tabel_urut[index3]=table2[index2];
			index2++;
			index3++;
		}
	}
	//------------------------------------------------------------
	//sisa jika index tsb paling kecil dari index lainnya
	if(index1 < n){	
		for(i=index1; i<n; i++){
			//memasukkan sisa ke array 3
			tabel_urut[index3]=table1[i];
			index3++;
		}
	}
	//sisa jika index2 belum dimasuki semua
	if(index2 < m){	
		for(i=index2; i<m; i++){
			//memasukan sisa ke array 3
			tabel_urut[index3]=table2[i];
			index3++;
		}
	}
}

