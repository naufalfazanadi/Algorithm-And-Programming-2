#include "faisal.h"
//prosedur sorting

void quickSortPivotPinggir(int l,int r){
	//Variabel yg dibutuhkan
	int i; int j; bungkus temp;
	//Duplikasi Nilai l terhadap i, r terhadap j
	i = l; 
	j = r;
	//Algoritma Quicksort Pivot Pinggir
	do{
		//Kondisi While
		// kondisi i berarti maju dari kiri ke kanan, jika lebih besar maka tukar, & berhenti
		while(((sell[i].harga > sell[r].harga) || ((sell[i].harga == sell[r].harga) && (strcmp(sell[i].barang,sell[r].barang)== 1))) && (i<=j)){
			/* mencegah i berjalan terlalu jauh melewati batas j*/
			i++;
		}
		// Kondisi j berarti maju dari kanan ke kiri, jika lebih kecil maka tukar& berhenti
		while(((sell[j].harga < sell[l].harga)||((sell[j].harga == sell[l].harga) && (strcmp(sell[j].barang,sell[l].barang)== -1))) && (i<=j)){
			/* mencegah j berjalan terlalu jauh melewati batas i */
			j--;
		}
		//jika sudah bertemu maka
		if(i<j){
		//tukar bungkusan
			temp = sell[i];
			sell[i] = sell[j];
			sell[j] = temp;
			i = i + 1;
			j = j - 1;
		}
	}while(i<j);
	//bagi kedalam sub sub menggunakan quicksort rekursif
	if(l < j){
		quickSortPivotPinggir(l,j);
	}
	if(i<r){
		quickSortPivotPinggir(i,r);
	}
}
//prosedur print
void print(int n,bungkus sell[n+1]){
	int i;
	//print hasil
	for(i=0;i<n;i++){
		printf("%s %s %d\n",sell[i].nama,sell[i].barang,sell[i].harga);
	}
}
