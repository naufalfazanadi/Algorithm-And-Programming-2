#include "faisal.h"

void hasil(int langkah[100][100],int p[100],char arah[100][100][100],int m,int x[100],int y[100]){
	int i,j;
	for(i=0;i<m;i++){
		for(j=0;j<p[i];j++){
			if(arah[i][j][0]=='h'){
				x[i]+=langkah[i][j];
			}else if(arah[i][j][0]=='-' && arah[i][j][1]=='h'){
				x[i]-=langkah[i][j];
			}else if(arah[i][j][0]=='v'){
				y[i]+=langkah[i][j];
			}else if(arah[i][j][0]=='-' && arah[i][j][1]=='v'){
				y[i]-=langkah[i][j];
			}else if(arah[i][j][0]=='m'){
				x[i]+=langkah[i][j];
				y[i]+=langkah[i][j];
			}else if(arah[i][j][0]=='-' && arah[i][j][1]=='m'){
				x[i]-=langkah[i][j];
				y[i]-=langkah[i][j];
			}
		}
		printf("%d %d\n",x[i],y[i]);
	}
}