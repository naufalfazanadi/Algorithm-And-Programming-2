#include "faisal.h"

int main(){
	int n;
	int i;
	char sorting[100];
	scanf("%s",&sorting);
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&array1[i]);
	}
	int m;
	scanf("%d",&m);
	for(i=0;i<m;i++){
		scanf("%d",&array2[i]);
	}
	quickSortPivotPinggir(0,n-1,array1);
	quickSortPivotPinggir(0,m-1,array2);
	mergetable(n,m);
	for(i=0;i<m+n;i++){
		printf("%d\n",array3[i]);
	}
	return 0;
}