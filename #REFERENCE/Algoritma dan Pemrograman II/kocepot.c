#include <stdio.h>
#include <string.h>

int main(){
	
	int m,x[100],y[100];
	scanf("%d",&m);
	int i,j,k;
	int p[100];
	char arah[100][100][100];
	int langkah[100][100];
	for(i=0;i<m;i++){
		scanf("%d",&x[i]);
		scanf("%d",&y[i]);
		scanf("%d",&p[i]);
		for(j=0;j<p[i];j++){
			scanf(" %s",&arah[i][j]);
			scanf("%d",&langkah[i][j]);
		}
	}
	int matriks[100][100];
	for(i=0;i<m;i++){
		for(j=0;j<p[i];j++){
			if(arah[i][j][0]=='h'){
				x[i]+=langkah[i][j];
			}else if(arah[i][j][0]=='-' && arah[1][i][j]=='h'){
				x[i]-=langkah[i][j];
			}else if(arah[i][j][0]=='v'){
				y[i]+=langkah[i][j];
			}else if(arah[i][j][0]=='-' && arah[1][i][j]=='v'){
				y[i]-=langkah[i][j];
			}else if(arah[i][j][0]=='m'){
				x[i]+=langkah[i][j];
				y[i]+=langkah[i][j];
			}else if(arah[i][j][0]=='-' && arah[1][i][j]=='m'){
				x[i]-=langkah[i][j];
				y[i]-=langkah[i][j];
			}
		}
		printf("%d %d\n",x[i],y[i]);
	}

	return 0;
}