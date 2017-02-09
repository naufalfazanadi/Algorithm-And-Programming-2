#include "faisal.h"

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
	hasil(langkah,p,arah,m,x,y);
	

	return 0;
}
