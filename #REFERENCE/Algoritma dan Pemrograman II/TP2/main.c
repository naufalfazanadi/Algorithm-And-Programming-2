#include "header.h"
//Main 
int main(){
	//Variabel ordo
	int m,n;
	//Variabel counter
	int i,j,k; 
	scanf("%d",&m);
	scanf("%d",&n);
	//Deklarasi matriks sebanyak ordo
	int matriks1[m+1][n+1];
	int matriks2[m+1][n+1];
	int matriks3[m+1][n+1];
	int matriks4[m+1][n+1];
	int matriks5[100][100];
	//Deret untuk sementara
	int deret[100];
	//Input matriks 1 & 2 Sebagai Basis
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%d",&matriks1[i][j]);
		}
	}
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%d",&matriks2[i][j]);
		}
	}
	//Input Matriks 3 Sebagai Elemen tampil ke-
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%d",&matriks3[i][j]);
		}
	}
	//Input matriks 4 sebagai pembanding akhir
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%d",&matriks4[i][j]);
		}
	}
	//Proses Pembuatan deret
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			//perulangan k sebanyak elemen matriks ke-3, sehingga membuat deret sebanyak matriks 3.
			for(k=0;k<matriks3[i][j];k++){
				//deret ke k, fungsi fibbonaci
				deret[k]=fibo(k,matriks1[i][j],matriks2[i][j]);
			}
			matriks5[i][j]=pembanding(deret[matriks3[i][j]-1],matriks4[i][j]);
		}
	}
	
	//Output!!
	hasil(m,n,matriks5);
	return 0;
}


