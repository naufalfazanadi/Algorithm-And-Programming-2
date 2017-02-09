#include "header.h"
//Mesin Program

//Prosedur mencari vokal-konso
void vokon(risna* a,int n){
	//deklarasi indeks
	int i,j;
	//pengulangan sebanyak jumlah data di n
	for(i=0;i<n;i++){
		a[i].voko = 0; //pembuat nol
		//menghitung voko di kata pertama
		for(j=0;j<strlen(a[i].string);j++){ //pengulangan sebanyak panjang dari string
			if((a[i].string[j] == 'a') || (a[i].string[j] == 'i') || (a[i].string[j] == 'u') || (a[i].string[j] == 'e') || (a[i].string[j] =='o')){ //jika huruf pertama vokal
				if(j+1!=strlen(a[i].string)){ //cek kondisi dulu apakah j+1 nya ada di akhir kata atau tidak.
					if(a[i].string[j+1] != 'a' && a[i].string[j+1] != 'i' && a[i].string[j+1] != 'u' && a[i].string[j+1] != 'o' && a[i].string[j+1] != 'e'){ //jika huruf selanjutnya konsonan
						a[i].voko++; //penampung vokal-konso bertambah
						j++; //iterasi bertambah 1 disini sehingga mengefesiensi,iterasi akan bertambah lg satu ketika di for
					}
				}
			}
		}
		//menghitung voko di kata kedua
		for(j=0;j<strlen(a[i].string2);j++){ //pengulangan sebanyak panjang dari string
			if(a[i].string2[j] == 'a' || a[i].string2[j] == 'i' || a[i].string2[j] == 'u' || a[i].string2[j] == 'e' || a[i].string2[j] =='o'){ //jika huruf pertama vokal
				if(j+1!=strlen(a[i].string2)){ //cek kondisi apakah j+1 masih berupa huruf / sudah di akhir
					if(a[i].string2[j+1] != 'a' && a[i].string2[j+1] != 'i' && a[i].string2[j+1] != 'u' && a[i].string2[j+1] != 'o' && a[i].string2[j+1] != 'e'){
						a[i].voko++; //voko bertambah
						j++; //iterasi bertambah sehingga akan +2
					}
				}
			}
		}
	}
}
//algoritma selectionsort
void selection(risna* a,int n){
	//deklarasi indeks & variabel
	int i, minIndex, j;
	risna temp;
	for(i=0 ; i<(n-1) ; i++){
		/*inisialisasi indeks elemen minimum*/
		minIndex = i;
		/*perulangan mencari nilai minimum sepanjang indeks i + 1 sampai jumlah elemen array*/

		for(j=(i+1) ; j<n ; j++){
			if(a[minIndex].voko < a[j].voko){
				minIndex = j;
			}
		}
	//menukar posisi elemen bypass
	temp = a[minIndex];
	a[minIndex] = a[i];
	a[i] = temp;	
	}
}
void bubble(risna*a, int n){
	int i; risna temp; int tukar;
	do{
		/*inisialisasi nilai tukar sebelum ada pertukaran diset false */
		tukar = 0;
		/*pengulangan dan memeriksa apakah ada pertukaran */
		for(i=0 ; i<(n-1) ; i++){
			/*jika ada nilai yang dipertukarkan */
			if(a[i].voko < a[i+1].voko){
				//menukar posisi elemen metode bypass
				temp = a[i];
				a[i] = a[i+1];
				a[i+1] = temp;
				//status jika masih ada pertukaran
				tukar=1;
			}
		}
	}while(tukar==1);
}
void insertion(risna* a, int n){
	//deklarasi indeks
	int i; risna data_sisip; int j;
	for(i=1; i<n; i++){
		data_sisip = a[i];
		j=i-1;
		while((data_sisip.voko > a[j].voko) && (j >= 0)){
			/*jika data array lebih kecil dari data sisip maka data array
			digeser ke belakang*/
			a[j+1] = a[j];
			j--;
		}
		/*menempatkan data sisip pada array*/
		a[j+1] = data_sisip;
	}

}
void quickSortPivotPinggir(risna* a,int l,int r){
	//Variabel yg dibutuhkan
	int i; int j; risna temp;
	//Duplikasi Nilai l terhadap i, r terhadap j
	i = l; 
	j = r;
	//Algoritma Quicksort Pivot Pinggir
	do{
		//Kondisi While
		// kondisi i berarti maju dari kiri ke kanan, jika lebih besar maka tukar, & berhenti
		while((a[i].voko > a[r].voko) && (i<=j)){
			/* mencegah i berjalan terlalu jauh melewati batas j*/
			i++;
		}
		// Kondisi j berarti maju dari kanan ke kiri, jika lebih kecil maka tukar& berhenti
		while((a[j].voko < a[l].voko) && (i<=j)){
			/* mencegah j berjalan terlalu jauh melewati batas i */
			j--;
		}
		//jika sudah bertemu maka
		if(i<j){
		//tukar bungkusan metode bypass
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
			i = i + 1;
			j = j - 1;
		}
	}while(i<j);
	//bagi kedalam sub sub menggunakan quicksort rekursif
	if(l < j){
		quickSortPivotPinggir(a,l,j);
	}
	if(i < r){
		quickSortPivotPinggir(a,i,r);
	}
}
//prosedur merge table
void mergetable(risna* array1,risna* array2,risna* array3,int n,int m){
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
		if(array1[index1].voko > array2[index2].voko){
			//memasukan elemen tsb ke array baru
			array3[index3] = array1[index1];
			index1 = index1 + 1;
			index3 = index3 + 1;
		//kondisi ketika lebih kecil
		}else if(array2[index2].voko > array1[index1].voko){
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