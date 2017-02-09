#include "faisal.h"
void define(char sesuatu[100])
void quickSortPivotPinggir(int l,int r,bungkus* a){
	int i; int j; 
	bungkus temp;
	i = l; j = r;
	do{
		while(((strcmp(a[i].kartu,a[r].kartu)==-1)||((strcmp(a[i].kartu,a[r].kartu)==0) && (strcmp(a[i].nama,a[r].nama)==-1))) && (i<=j)){
			/* mencegah i berjalan terlalu jauh melewati batas j*/
			i = i + 1;
		}
		while(((strcmp(a[j].kartu,a[l].kartu)==1)||((strcmp(a[j].kartu,a[l].kartu)==0) && (strcmp(a[j].nama,a[l].nama)==1))) && (i<=j)){
			/* mencegah i berjalan terlalu jauh melewati batas i */
			j = j - 1;
		}
		if(i<j){
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
			i = i + 1;
			j = j - 1;
		}
	}while(i<j);
	if(l < j){
		quickSortPivotPinggir(l,j,a);
	}
	if(i < r){
		quickSortPivotPinggir(i,r,a);
	}
}
void mergetable(int n,int m){
	int penghitung;
	int penghitung1 = 0;
	int penghitung2 = 0;
	int penghitung3 = 0;
	while((penghitung1 < n) && (penghitung2 < m)){
		if((strcmp(array1[penghitung1].kartu,array2[penghitung2].kartu)==-1)||((strcmp(array1[penghitung1].kartu,array2[penghitung2].kartu)==0) && (strcmp(array1[penghitung1].nama,array2[penghitung2].nama)==-1))){
			array3[penghitung3] = array1[penghitung1];
			penghitung1++;
			penghitung3++;
		}else if((strcmp(array2[penghitung2].kartu,array1[penghitung1].kartu)==-1)||((strcmp(array1[penghitung1].kartu,array2[penghitung2].kartu)==0) && (strcmp(array2[penghitung2].nama,array1[penghitung1].nama)==-1))){
			array3[penghitung3] = array2[penghitung2];
			penghitung2++;
			penghitung3++;
		}else{
			array3[penghitung3] = array1[penghitung1];
			penghitung1++;
			penghitung3++;
			array3[penghitung3] = array2[penghitung2];
			penghitung2++;
			penghitung3++;
		}
	}

	if(penghitung1 < n){
		for(penghitung=penghitung1; penghitung<n; penghitung++){
			array3[penghitung3] = array1[penghitung];
			penghitung3++;
		}
	}
	if(penghitung2 < m){
		for(penghitung=penghitung2; penghitung<m; penghitung++){
			array3[penghitung3] = array2[penghitung];
			penghitung3++;
		}
	}

}
 
