#include<stdio.h>

int main(){
	int matriks1[100][100];
	int matriks2[100][100];
	int i,j;
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			scanf("%d",&matriks1[i][j]);
		}
	}
	
	int c1;
	int c2=0;
	for(i=0;i<3;i++){
		c1=2;
		for(j=0;j<3;j++){
			matriks2[i][j]=matriks1[c1][j];
			c1--;
			printf("%d",matriks2[i][j]);
		}
		c2++;
	}
	return 0;
}