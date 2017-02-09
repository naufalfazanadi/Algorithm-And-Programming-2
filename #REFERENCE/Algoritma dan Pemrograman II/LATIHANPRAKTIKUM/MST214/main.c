#include "faisal.h"

int main(){
	int n;
	int i;
	char sorting[100];
	scanf("%s",&sorting);
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf(" %s",&array1[i].nama);
		scanf(" %s",&array1[i].kartu);
	}
	int m;
	scanf("%d",&m);
	for(i=0;i<m;i++){
		scanf(" %s",&array2[i].nama);
		scanf(" %s",&array2[i].kartu);
	}
	quickSortPivotPinggir(0,n-1,array1);
	quickSortPivotPinggir(0,m-1,array2);
	mergetable(n,m);
	printf("n\n");
	for(i=0;i<n;i++){
		printf("%s %s\n",array1[i].nama,array1[i].kartu);
	}
	printf("m\n");
	for(i=0;i<m;i++){
		printf("%s %s\n",array2[i].nama,array2[i].kartu);
	}
	printf("mn\n");
	for(i=0;i<m+n;i++){
		printf("%s %s\n",array3[i].nama,array3[i].kartu);
	}
	return 0;
}