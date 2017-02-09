//tugas praktikum matriks
#include "header.h"

int main(){
	// deklarasi
	int k,b;
	bungkus data;
	// input ordo matriks
	scanf("%d",&b);
	scanf("%d",&k);
	int i,j,l,m;
	// input matriks
	for(i=0;i<b;i++){
		for(j=0;j<k;j++){
			scanf("%d",&data.matriks[i][j]);
		}
	}
	// duplikat matriks
	for(i=0;i<b;i++){
		for(j=0;j<k;j++){
			data.matriks2[i][j]=data.matriks[i][j];
		}
	}
	// deklarasi kasus
	int n;
	//input jumlah n kasus
	scanf("%d",&n);
	int x[n];
	int y[n];
	char tuker[n][100];
	//input kasus sebanyak n
	for(i=0;i<n;i++){
		scanf(" %s",&tuker[i]);
		scanf("%d",&x[i]);
		scanf("%d",&y[i]);
	}
	//pemanggilan fungsi
	bungkus hasil;
	hasil=fung(k,b,data,n,x,y,tuker);
	//output
	for(i=0;i<b;i++){
		for(j=0;j<k;j++){
			//print angka satu per satu.
			printf("%d",hasil.matriks[i][j]);
			//spasi sesudah angka, kecuali angka akhir
			if(j!=k-1){
				printf(" ");
			}
		}
		printf("\n");
	}	
	return 0;
}
