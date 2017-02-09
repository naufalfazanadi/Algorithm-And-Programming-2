#include "header.h"
//mesin
//Fungsi ini adalah fungsi mencari deret fiboonaci
int fibo(int i,int a,int b){
	int temp; //variabel temporarry
	
	if(i==0){ //kotak array awal adalah basis (matriks1)
		temp=a;
	}else if(i==1){ //kotak array kedua adalah basis (matriks2)
		temp=b;
	}else{ //kotak selanjutnya adalah, pertambahan a dan b = c
		temp=fibo(i-1,a,b)+fibo(i-2,a,b);
	}
	//Lempar Fungsi
	return temp;
} 
//prosedur ini adalah pembanding matriks hasil dan 4.
int pembanding (int a,int b) {
	// jika deret hasil lebih besar dari matriks 4, maka tampilkan matriks 4
	if(a>=b){
		return b;
	}else{
	//jika lebih kecil, maka tampilkan deret tsb
		return a;
	}
}
void hasil(int m,int n,int matriks5[100][100]){
	int i,j;
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			//tampilkan fibbonaci elemen ke 3, tiap matriks
			printf("%d",matriks5[i][j]);
			//spasi setiap sesudah matriks
			if(j!=n-1){
				printf(" ");
			}
		}
		//newline
		printf("\n");
	}
}
