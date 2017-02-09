#include "faisal.h"

int main(){
	//variabel
	int m,n;
	int i,j;
	//input ordo
	scanf("%d",&m);
	scanf("%d",&n);
	//deklarasi bungkusan namanya matriks sesuai ordo
	bungkus matriks[m][n];
	int hasil[m+1][n+1];
	//input x y z dari setiap kotak (bungkus)
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%d",&matriks[i][j].x);
			scanf("%d",&matriks[i][j].y);
			scanf("%d",&matriks[i][j].z);
		}
	}
	//hasil adalah masuk ke fungsi
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			hasil[i][j]=fungsi(matriks[i][j].x,matriks[i][j].y,matriks[i][j].z);
		}
	}
	//output
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			//print hasil menggunakan spasi,kecuali akhir
			printf("%d",hasil[i][j]);
			if(j!=n-1){ //jika j tidak sama dengan n-1
				printf(" ");
			}
		}
		//newline
		printf("\n");
	}
	return 0;
}