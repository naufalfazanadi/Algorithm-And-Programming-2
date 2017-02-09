#include<Stdio.h>

int main(){
	int n;
	int n1;
	int m;
	int m1;
	int i,j;
	scanf("%d %d",&n,&m);
	scanf("%d %d",&n1,&m1);
	int mat1[n][m];
	int mat2[n1][m1];
	int mat3[n][m1];
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			scanf("%d",&mat1[i][j]);
		}
	}
	for(i=0;i<n1;i++){
		for(j=0;j<m1;j++){
			scanf("%d",&mat2[i][j]);
		}
	}

	return 0;
}