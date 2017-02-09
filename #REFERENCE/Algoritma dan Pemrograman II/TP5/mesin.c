#include"header.h"
//mesin program
//mesin konversi bulan
void konversi(bungkus* a, int n){
	int i;
	/* Define setiap bulan sesuai dengan patokan universal
	ex:january / 01 
	...
	dececmber / 12 */
	//penggunakan string compare dalam konversi
	for(i=0;i<n;i++){
		if(strcmp(a[i].bulan,"januari")==0){
			a[i].tempbulan = 1;
		}else if(strcmp(a[i].bulan,"februari")==0){
			a[i].tempbulan = 2;
		}else if(strcmp(a[i].bulan,"maret")==0){
			a[i].tempbulan = 3;
		}else if(strcmp(a[i].bulan,"april")==0){
			a[i].tempbulan = 4;
		}else if(strcmp(a[i].bulan,"mei")==0){
			a[i].tempbulan = 5;
		}else if(strcmp(a[i].bulan,"juni")==0){
			a[i].tempbulan = 6;
		}else if(strcmp(a[i].bulan,"juli")==0){
			a[i].tempbulan = 7;
		}else if(strcmp(a[i].bulan,"agustus")==0){
			a[i].tempbulan = 8;
		}else if(strcmp(a[i].bulan,"september")==0){
			a[i].tempbulan = 9;
		}else if(strcmp(a[i].bulan,"oktober")==0){
			a[i].tempbulan = 10;
		}else if(strcmp(a[i].bulan,"november")==0){
			a[i].tempbulan = 11;
		}else if(strcmp(a[i].bulan,"desember")==0){
			a[i].tempbulan = 12;
		}
	}
}
//prosedur insersi sorting
void insertion(bungkus* arr, int n){
	//deklarasi variabel indeks
	int i, j;
	bungkus sisip;
	
	for(i=1; i<n; i++){
		sisip=arr[i];
		j=i-1;
		while(((sisip.tahun>arr[j].tahun) || ((sisip.tahun == arr[j].tahun) && (sisip.tempbulan > arr[j].tempbulan)) || ((sisip.tahun == arr[j].tahun) && (sisip.tempbulan == arr[j].tempbulan) && (sisip.hari > arr[j].hari))) && (j>=0)){
			/*jika data array lebih kecil dari data sisip maka data array
			digeser ke belakang*/
			arr[j+1]=arr[j];
			j=j-1;
		}
		/*menempatkan data sisip pada array*/
		arr[j+1]=sisip;
	}
	
}
//prosedur mergetable urut
void mergetable(bungkus* array1,bungkus* array2,bungkus* array3,int n,int m){
	//deklarasi indeks awal setiap tabel
	int index;
	int index1 = 0;
	int index2 = 0;
	int index3 = 0;
	//index1 berkorelasi dengan n
	//index2 berkorelasi dengan m
	// ketika index1 belum melampaui n dan juga index2
	while((index1 < n) && (index2 < m)){
		//kondisi ketika elemen pada array 1 lebih besar dari array2
		if((array1[index1].tahun > array2[index2].tahun) || ((array1[index1].tahun == array2[index2].tahun) && (array1[index1].tempbulan > array2[index2].tempbulan)) || ((array1[index1].tahun == array2[index2].tahun) && (array1[index1].tempbulan == array2[index2].tempbulan) && (array1[index1].hari > array2[index2].hari))){
			//memasukan elemen tsb ke array baru
			array3[index3] = array1[index1];
			index1 = index1 + 1;
			index3 = index3 + 1;
		//kondisi ketika lebih kecil
		}else if((array2[index2].tahun > array1[index1].tahun) || ((array2[index2].tahun == array1[index1].tahun) && (array2[index2].tempbulan > array1[index1].tempbulan)) || ((array2[index2].tahun == array1[index1].tahun) && (array2[index2].tempbulan == array1[index1].tempbulan) && (array2[index2].hari > array1[index1].hari))){
			//memasukan elemen tsb ke array baru
			array3[index3] = array2[index2];
			index2 = index2 + 1;
			index3 = index3 + 1;
		//kondisi jika sama
		}else{
			//memasukan kedua elemennya ke aarray baru
			array3[index3] = array1[index1];
			index1 = index1 + 1;
			index3 = index3 + 1;
			array3[index3] = array2[index2];
			index2 = index2 + 1;
			index3 = index3 + 1;
		}
	}
	//------------------------------------------------------------
	//sisa jika index tsb paling kecil dari index lainnya
	if(index1 < n){
		for(index=index1; index<n; index++){
			//memasukkan sisa ke array 3
			array3[index3] = array1[index];
			index3 = index3 + 1;
		}
	}
	//sisa jika index2 belum dimasuki semua
	if(index2 < m){
		for(index=index2; index<m; index++){
			//memasukan sisa ke array 3
			array3[index3] = array2[index];
			index3 = index3 + 1;
		}
	}

}