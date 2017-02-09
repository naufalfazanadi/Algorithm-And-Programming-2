#include "header.h"

int main(){
	int k,b;
	bungkus data;
	scanf("%d",&b);
	scanf("%d",&k);
	int data.matriks[b][k];
	int data.matriks2[b][k];
	int i,j,l,m;
	for(i=0;i<b;i++){
		for(j=0;j<k;j++){
			scanf("%d",&data.matriks[i][j]);
			data.matriks2[i][j]=data.matriks[i][j];
		}
	}
	int n;
	int x[n];
	int y[n];
	char tuker[100][100];
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%s",&tuker[i]);
		scanf("%d",&x[i]);
		scanf("%d",&y[i]);
	}
	bungkus hasil=fung(k,b,data.matriks,data.matriks2,n,x,y,tuker);
	for(i=0;i<b;i++){
		for(j=0;j<k;j++){
			printf("%d",hasil.matriks[i][j]);
			if(j!=k-1){
				printf(" ");
			}
		}
		printf("\n");
	}
	
	return 0;
}