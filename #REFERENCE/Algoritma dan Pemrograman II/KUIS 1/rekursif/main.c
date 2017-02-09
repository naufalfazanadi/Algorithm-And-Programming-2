#include "faisal.h"
//Main
int main(){
	//deklarasi variabel
	int m,n;
	int kelipatan;
	//input kelipatan dan ordo
	scanf("%d",&kelipatan);
	scanf("%d",&m);
	scanf("%d",&n);
	int i,j;
	//variabel sesuai dengan ordo
	int matriks[m][n];
	int hasil[m][n];
	//input matriks sebanyak m n
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%d",&matriks[i][j]);
		}
	}
	
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			//hasil matriks sama dengan fungsi
			hasil[i][j]=fibo(kelipatan,matriks[i][j]);
			//print hasil dengan spasi
			printf("%d",hasil[i][j]);
			if(j!=n-1){ //jika j != n-1
				printf(" ");
			}
		}
		//newline
		printf("\n");
	}
	return 0;
}