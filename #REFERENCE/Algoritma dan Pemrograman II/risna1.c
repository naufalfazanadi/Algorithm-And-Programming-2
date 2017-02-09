#include<stdio.h>

int main(){
	int mat1[100][100];
	int mat2[100][100];
	int hasil1[100][100];
	int hasil2[100][100];
	int i,j;
	
	for(i=0; i<2; i++){
		for(j=0; j<2; j++){
		scanf("%d", &mat1[i][j]);
		}
	}
	
	for(i=0; i<2; i++){
		for(j=0; j<2; j++){
		scanf("%d", &mat2[i][j]);
		}
	}
	
	for(i=0; i<2; i++){
		for(j=0; j<2; j++){
			hasil1[i][j]=mat1[i][j]+mat2[i][j];
			printf("%d\n",hasil1[i][j]);
		}
	}
	
	int k=1,l;
	for(i=0; i<2; i++){
		for(j=0; j<2; j++){
			hasil2[i][j]=mat1[i][j]+mat2[k][j];
			printf("%d",hasil2[i][j]);
		}
		k--;
		
	}
	return 0;
}

