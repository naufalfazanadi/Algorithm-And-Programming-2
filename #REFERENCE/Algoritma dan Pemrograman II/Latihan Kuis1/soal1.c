#include <stdio.h>
int fibo(int i,int x,int y){
	int temp;
	if(i==0){
		temp=x;
	}else if(i==1){
		temp=y;
	}else{
		temp=fibo(i-1,x,y)+fibo(i-2,x,y);
	}
	return temp;
}
int main(){
	int m,n;
	int x,y;
	scanf("%d",&m);
	scanf("%d",&n);
	scanf("%d",&x);
	scanf("%d",&y);
	int matriks1[m+1][n+1];
	int jumlah=m*n;
	int i,j;
	int deret[100];
	for(i=0;i<jumlah;i++){
		deret[i]=fibo(i,x,y);
	}
	int counter=0;
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			matriks1[i][j]=deret[counter];
			counter++;
			printf("%d",matriks1[i][j]);
			if(j!=n){
				printf(" ");
			}
		}
		printf("\n");
	}
	return 0;
}
