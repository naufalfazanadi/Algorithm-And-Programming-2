#include<stdio.h>
#include<string.h>
typedef struct{
	int stok;
	char nama[100];
	char barang[100];
}bungkus;
bungkus data[100];
void quickSortPivotPinggir(int l,int r,int n){
	int i; int j; 
	bungkus temp;
	i = l; j = r;
	do{
		while((data[i].stok < data[r].stok)&& (i<=j)){
			/* mencegah i berjalan terlalu jauh melewati batas j*/
			i = i + 1;
		}
		while((data[j].stok > data[l].stok)&& (i<=j)){
			/* mencegah i berjalan terlalu jauh melewati batas i */
			j = j - 1;
		}
		if(i<j){
			temp = data[i];
			data[i] = data[j];
			data[j] = temp;
			i = i + 1;
			j = j - 1;
		}
	}while(i<j);
	if(l < j){
		quickSortPivotPinggir(l,j,n);
	}
	if(i<r){
		quickSortPivotPinggir(i,r,n);
	}
}
void tulis(int a){
	int i;
	for(i=0;i<a;i++){
		printf("%d",data[i].stok);
		printf("%s",data[i].barang);
		printf("%s",data[i].nama);
	}
}
int main(){
	int n;
	int i;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&data[i].stok);
		scanf(" %s",&data[i].nama);
		scanf(" %s",&data[i].barang);
	}
	quickSortPivotPinggir(0,n-1,n);
	for(i=0;i<n;i++){
		printf("%d",data[i].stok);
		printf(" %s",data[i].nama);
		printf(" %s",data[i].barang);
	}
	return 0;
}
