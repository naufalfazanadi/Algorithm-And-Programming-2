#include "faisal.h"

void quickSortPivotPinggir(int l,int r,int* a){
	int i; int j; 
	int temp;
	i = l; j = r;
	do{
		while((a[i] < a[r]) && (i<=j)){
			/* mencegah i berjalan terlalu jauh melewati batas j*/
			i = i + 1;
		}
		while((a[j] > a[l])&& (i<=j)){
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
	if(i<r){
		quickSortPivotPinggir(i,r,a);
	}
}
void mergetable(int n,int m){
	int penghitung;
	int penghitung1 = 0;
	int penghitung2 = 0;
	int penghitung3 = 0;
	while((penghitung1 < n) && (penghitung2 < m)){
		if(array1[penghitung1] < array2[penghitung2]){
			array3[penghitung3] = array1[penghitung1];
			penghitung1 = penghitung1 + 1;
			penghitung3 = penghitung3 + 1;
		}else if(array2[penghitung2] < array1[penghitung1]){
			array3[penghitung3] = array2[penghitung2];
			penghitung2 = penghitung2 + 1;
			penghitung3 = penghitung3 + 1;
		}else{
			array3[penghitung3] = array1[penghitung1];
			penghitung1 = penghitung1 + 1;
			penghitung3 = penghitung3 + 1;
			array3[penghitung3] = array2[penghitung2];
			penghitung2 = penghitung2 + 1;
			penghitung3 = penghitung3 + 1;
		}
	}

	if(penghitung1 < n){
		for(penghitung=penghitung1; penghitung<n; penghitung++){
			array3[penghitung3] = array1[penghitung];
			penghitung3 = penghitung3 + 1;
		}
	}
	if(penghitung2 < m){
		for(penghitung=penghitung2; penghitung<m; penghitung++){
			array3[penghitung3] = array2[penghitung];
			penghitung3 = penghitung3 + 1;
		}
	}

}
 
